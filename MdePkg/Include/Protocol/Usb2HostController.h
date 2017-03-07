begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI_USB2_HC_PROTOCOL as defined in UEFI 2.0.   The USB Host Controller Protocol is used by code, typically USB bus drivers,    running in the EFI boot services environment, to perform data transactions over    a USB bus. In addition, it provides an abstraction for the root hub of the USB bus.    Copyright (c) 2006 - 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USB2_HOSTCONTROLLER_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB2_HOSTCONTROLLER_H_
end_define

begin_include
include|#
directive|include
file|<Protocol/UsbIo.h>
end_include

begin_define
define|#
directive|define
name|EFI_USB2_HC_PROTOCOL_GUID
define|\
value|{ \     0x3e745226, 0x9818, 0x45b6, {0xa2, 0xac, 0xd7, 0xcd, 0xe, 0x8b, 0xa2, 0xbc } \   }
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
name|_EFI_USB2_HC_PROTOCOL
name|EFI_USB2_HC_PROTOCOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|PortStatus
decl_stmt|;
comment|///< Contains current port status bitmap.
name|UINT16
name|PortChangeStatus
decl_stmt|;
comment|///< Contains current port status change bitmap.
block|}
name|EFI_USB_PORT_STATUS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_USB_PORT_STATUS.PortStatus bit definition
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|USB_PORT_STAT_CONNECTION
value|0x0001
end_define

begin_define
define|#
directive|define
name|USB_PORT_STAT_ENABLE
value|0x0002
end_define

begin_define
define|#
directive|define
name|USB_PORT_STAT_SUSPEND
value|0x0004
end_define

begin_define
define|#
directive|define
name|USB_PORT_STAT_OVERCURRENT
value|0x0008
end_define

begin_define
define|#
directive|define
name|USB_PORT_STAT_RESET
value|0x0010
end_define

begin_define
define|#
directive|define
name|USB_PORT_STAT_POWER
value|0x0100
end_define

begin_define
define|#
directive|define
name|USB_PORT_STAT_LOW_SPEED
value|0x0200
end_define

begin_define
define|#
directive|define
name|USB_PORT_STAT_HIGH_SPEED
value|0x0400
end_define

begin_define
define|#
directive|define
name|USB_PORT_STAT_SUPER_SPEED
value|0x0800
end_define

begin_define
define|#
directive|define
name|USB_PORT_STAT_OWNER
value|0x2000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_USB_PORT_STATUS.PortChangeStatus bit definition
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|USB_PORT_STAT_C_CONNECTION
value|0x0001
end_define

begin_define
define|#
directive|define
name|USB_PORT_STAT_C_ENABLE
value|0x0002
end_define

begin_define
define|#
directive|define
name|USB_PORT_STAT_C_SUSPEND
value|0x0004
end_define

begin_define
define|#
directive|define
name|USB_PORT_STAT_C_OVERCURRENT
value|0x0008
end_define

begin_define
define|#
directive|define
name|USB_PORT_STAT_C_RESET
value|0x0010
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Usb port features value
end_comment

begin_comment
comment|/// Each value indicates its bit index in the port status and status change bitmaps,
end_comment

begin_comment
comment|/// if combines these two bitmaps into a 32-bit bitmap.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|EfiUsbPortEnable
init|=
literal|1
block|,
name|EfiUsbPortSuspend
init|=
literal|2
block|,
name|EfiUsbPortReset
init|=
literal|4
block|,
name|EfiUsbPortPower
init|=
literal|8
block|,
name|EfiUsbPortOwner
init|=
literal|13
block|,
name|EfiUsbPortConnectChange
init|=
literal|16
block|,
name|EfiUsbPortEnableChange
init|=
literal|17
block|,
name|EfiUsbPortSuspendChange
init|=
literal|18
block|,
name|EfiUsbPortOverCurrentChange
init|=
literal|19
block|,
name|EfiUsbPortResetChange
init|=
literal|20
block|}
name|EFI_USB_PORT_FEATURE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_USB_SPEED_FULL
value|0x0000
end_define

begin_comment
comment|///< 12 Mb/s, USB 1.1 OHCI and UHCI HC.
end_comment

begin_define
define|#
directive|define
name|EFI_USB_SPEED_LOW
value|0x0001
end_define

begin_comment
comment|///< 1 Mb/s, USB 1.1 OHCI and UHCI HC.
end_comment

begin_define
define|#
directive|define
name|EFI_USB_SPEED_HIGH
value|0x0002
end_define

begin_comment
comment|///< 480 Mb/s, USB 2.0 EHCI HC.
end_comment

begin_define
define|#
directive|define
name|EFI_USB_SPEED_SUPER
value|0x0003
end_define

begin_comment
comment|///< 4.8 Gb/s, USB 3.0 XHCI HC.
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|TranslatorHubAddress
decl_stmt|;
comment|///< device address
name|UINT8
name|TranslatorPortNumber
decl_stmt|;
comment|///< the port number of the hub that device is connected to.
block|}
name|EFI_USB2_HC_TRANSACTION_TRANSLATOR
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
comment|/**   Retrieves the Host Controller capabilities.    @param  This           A pointer to the EFI_USB2_HC_PROTOCOL instance.   @param  MaxSpeed       Host controller data transfer speed.   @param  PortNumber     Number of the root hub ports.   @param  Is64BitCapable TRUE if controller supports 64-bit memory addressing,                          FALSE otherwise.    @retval EFI_SUCCESS           The host controller capabilities were retrieved successfully.   @retval EFI_INVALID_PARAMETER One of the input args was NULL.   @retval EFI_DEVICE_ERROR      An error was encountered while attempting to                                 retrieve the capabilities.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USB2_HC_PROTOCOL_GET_CAPABILITY
function_decl|)
parameter_list|(
name|IN
name|EFI_USB2_HC_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|UINT8
modifier|*
name|MaxSpeed
parameter_list|,
name|OUT
name|UINT8
modifier|*
name|PortNumber
parameter_list|,
name|OUT
name|UINT8
modifier|*
name|Is64BitCapable
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|EFI_USB_HC_RESET_GLOBAL
value|0x0001
end_define

begin_define
define|#
directive|define
name|EFI_USB_HC_RESET_HOST_CONTROLLER
value|0x0002
end_define

begin_define
define|#
directive|define
name|EFI_USB_HC_RESET_GLOBAL_WITH_DEBUG
value|0x0004
end_define

begin_define
define|#
directive|define
name|EFI_USB_HC_RESET_HOST_WITH_DEBUG
value|0x0008
end_define

begin_comment
comment|/**   Provides software reset for the USB host controller.    @param  This       A pointer to the EFI_USB2_HC_PROTOCOL instance.   @param  Attributes A bit mask of the reset operation to perform.    @retval EFI_SUCCESS           The reset operation succeeded.   @retval EFI_INVALID_PARAMETER Attributes is not valid.   @retval EFI_UNSUPPORTED       The type of reset specified by Attributes is not currently                                 supported by the host controller hardware.   @retval EFI_ACCESS_DENIED     Reset operation is rejected due to the debug port being configured                                 and active; only EFI_USB_HC_RESET_GLOBAL_WITH_DEBUG or                                 EFI_USB_HC_RESET_HOST_WITH_DEBUG reset Attributes can be used to                                 perform reset operation for this host controller.   @retval EFI_DEVICE_ERROR      An error was encountered while attempting to                                 retrieve the capabilities.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USB2_HC_PROTOCOL_RESET
function_decl|)
parameter_list|(
name|IN
name|EFI_USB2_HC_PROTOCOL
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
comment|/**   Enumration value for status of USB HC. **/
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|EfiUsbHcStateHalt
block|,
comment|///< The host controller is in halt
comment|///< state. No USB transactions can occur
comment|///< while in this state. The host
comment|///< controller can enter this state for
comment|///< three reasons: 1) After host
comment|///< controller hardware reset. 2)
comment|///< Explicitly set by software. 3)
comment|///< Triggered by a fatal error such as
comment|///< consistency check failure.
name|EfiUsbHcStateOperational
block|,
comment|///< The host controller is in an
comment|///< operational state. When in
comment|///< this state, the host
comment|///< controller can execute bus
comment|///< traffic. This state must be
comment|///< explicitly set to enable the
comment|///< USB bus traffic.
name|EfiUsbHcStateSuspend
block|,
comment|///< The host controller is in the
comment|///< suspend state. No USB
comment|///< transactions can occur while in
comment|///< this state. The host controller
comment|///< enters this state for the
comment|///< following reasons: 1) Explicitly
comment|///< set by software. 2) Triggered
comment|///< when there is no bus traffic for
comment|///< 3 microseconds.
name|EfiUsbHcStateMaximum
comment|///< Maximum value for enumration value of HC status.
block|}
name|EFI_USB_HC_STATE
typedef|;
end_typedef

begin_comment
comment|/**   Retrieves current state of the USB host controller.    @param  This  A pointer to the EFI_USB2_HC_PROTOCOL instance.   @param  State A pointer to the EFI_USB_HC_STATE data structure that                 indicates current state of the USB host controller.    @retval EFI_SUCCESS           The state information of the host controller was returned in State.   @retval EFI_INVALID_PARAMETER State is NULL.   @retval EFI_DEVICE_ERROR      An error was encountered while attempting to retrieve the                                 host controller's current state.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USB2_HC_PROTOCOL_GET_STATE
function_decl|)
parameter_list|(
name|IN
name|EFI_USB2_HC_PROTOCOL
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
comment|/**   Sets the USB host controller to a specific state.    @param  This  A pointer to the EFI_USB2_HC_PROTOCOL instance.   @param  State Indicates the state of the host controller that will be set.    @retval EFI_SUCCESS           The USB host controller was successfully placed in the state                                 specified by State.   @retval EFI_INVALID_PARAMETER State is not valid.   @retval EFI_DEVICE_ERROR      Failed to set the state specified by State due to device error.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USB2_HC_PROTOCOL_SET_STATE
function_decl|)
parameter_list|(
name|IN
name|EFI_USB2_HC_PROTOCOL
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
comment|/**   Submits control transfer to a target USB device.    @param  This                A pointer to the EFI_USB2_HC_PROTOCOL instance.   @param  DeviceAddress       Represents the address of the target device on the USB.   @param  DeviceSpeed         Indicates device speed.   @param  MaximumPacketLength Indicates the maximum packet size that the default control transfer                               endpoint is capable of sending or receiving.   @param  Request             A pointer to the USB device request that will be sent to the USB device.   @param  TransferDirection   Specifies the data direction for the transfer. There are three values                               available, EfiUsbDataIn, EfiUsbDataOut and EfiUsbNoData.   @param  Data                A pointer to the buffer of data that will be transmitted to USB device or                               received from USB device.   @param  DataLength          On input, indicates the size, in bytes, of the data buffer specified by Data.                               On output, indicates the amount of data actually transferred.   @param  TimeOut             Indicates the maximum time, in milliseconds, which the transfer is                               allowed to complete.   @param  Translator          A pointer to the transaction translator data.   @param  TransferResult      A pointer to the detailed result information generated by this control                               transfer.    @retval EFI_SUCCESS           The control transfer was completed successfully.   @retval EFI_INVALID_PARAMETER Some parameters are invalid.   @retval EFI_OUT_OF_RESOURCES  The control transfer could not be completed due to a lack of resources.   @retval EFI_TIMEOUT           The control transfer failed due to timeout.   @retval EFI_DEVICE_ERROR      The control transfer failed due to host controller or device error.                                 Caller should check TransferResult for detailed error information.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USB2_HC_PROTOCOL_CONTROL_TRANSFER
function_decl|)
parameter_list|(
name|IN
name|EFI_USB2_HC_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT8
name|DeviceAddress
parameter_list|,
name|IN
name|UINT8
name|DeviceSpeed
parameter_list|,
name|IN
name|UINTN
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
name|IN
name|EFI_USB2_HC_TRANSACTION_TRANSLATOR
modifier|*
name|Translator
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|TransferResult
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|EFI_USB_MAX_BULK_BUFFER_NUM
value|10
end_define

begin_comment
comment|/**   Submits bulk transfer to a bulk endpoint of a USB device.    @param  This                A pointer to the EFI_USB2_HC_PROTOCOL instance.   @param  DeviceAddress       Represents the address of the target device on the USB.   @param  EndPointAddress     The combination of an endpoint number and an endpoint direction of the                               target USB device.   @param  DeviceSpeed         Indicates device speed.   @param  MaximumPacketLength Indicates the maximum packet size the target endpoint is capable of                               sending or receiving.   @param  DataBuffersNumber   Number of data buffers prepared for the transfer.   @param  Data                Array of pointers to the buffers of data that will be transmitted to USB                               device or received from USB device.   @param  DataLength          When input, indicates the size, in bytes, of the data buffers specified by                               Data. When output, indicates the actually transferred data size.   @param  DataToggle          A pointer to the data toggle value.   @param  TimeOut             Indicates the maximum time, in milliseconds, which the transfer is                               allowed to complete.   @param  Translator          A pointer to the transaction translator data.   @param  TransferResult      A pointer to the detailed result information of the bulk transfer.    @retval EFI_SUCCESS           The bulk transfer was completed successfully.   @retval EFI_INVALID_PARAMETER Some parameters are invalid.   @retval EFI_OUT_OF_RESOURCES  The bulk transfer could not be submitted due to a lack of resources.   @retval EFI_TIMEOUT           The bulk transfer failed due to timeout.   @retval EFI_DEVICE_ERROR      The bulk transfer failed due to host controller or device error.                                 Caller should check TransferResult for detailed error information.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USB2_HC_PROTOCOL_BULK_TRANSFER
function_decl|)
parameter_list|(
name|IN
name|EFI_USB2_HC_PROTOCOL
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
name|DeviceSpeed
parameter_list|,
name|IN
name|UINTN
name|MaximumPacketLength
parameter_list|,
name|IN
name|UINT8
name|DataBuffersNumber
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|Data
index|[
name|EFI_USB_MAX_BULK_BUFFER_NUM
index|]
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
name|IN
name|EFI_USB2_HC_TRANSACTION_TRANSLATOR
modifier|*
name|Translator
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|TransferResult
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Submits an asynchronous interrupt transfer to an interrupt endpoint of a USB device.   Translator parameter doesn't exist in UEFI2.0 spec, but it will be updated in the following specification version.    @param  This                A pointer to the EFI_USB2_HC_PROTOCOL instance.   @param  DeviceAddress       Represents the address of the target device on the USB.   @param  EndPointAddress     The combination of an endpoint number and an endpoint direction of the                               target USB device.   @param  DeviceSpeed         Indicates device speed.   @param  MaximumPacketLength Indicates the maximum packet size the target endpoint is capable of                               sending or receiving.   @param  IsNewTransfer       If TRUE, an asynchronous interrupt pipe is built between the host and the                               target interrupt endpoint. If FALSE, the specified asynchronous interrupt                               pipe is canceled. If TRUE, and an interrupt transfer exists for the target                               end point, then EFI_INVALID_PARAMETER is returned.   @param  DataToggle          A pointer to the data toggle value.   @param  PollingInterval     Indicates the interval, in milliseconds, that the asynchronous interrupt                               transfer is polled.   @param  DataLength          Indicates the length of data to be received at the rate specified by                               PollingInterval from the target asynchronous interrupt endpoint.   @param  Translator          A pointr to the transaction translator data.   @param  CallBackFunction    The Callback function. This function is called at the rate specified by                               PollingInterval.   @param  Context             The context that is passed to the CallBackFunction. This is an                               optional parameter and may be NULL.    @retval EFI_SUCCESS           The asynchronous interrupt transfer request has been successfully                                 submitted or canceled.   @retval EFI_INVALID_PARAMETER Some parameters are invalid.   @retval EFI_OUT_OF_RESOURCES  The request could not be completed due to a lack of resources.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USB2_HC_PROTOCOL_ASYNC_INTERRUPT_TRANSFER
function_decl|)
parameter_list|(
name|IN
name|EFI_USB2_HC_PROTOCOL
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
name|DeviceSpeed
parameter_list|,
name|IN
name|UINTN
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
name|EFI_USB2_HC_TRANSACTION_TRANSLATOR
modifier|*
name|Translator
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
comment|/**   Submits synchronous interrupt transfer to an interrupt endpoint of a USB device.   Translator parameter doesn't exist in UEFI2.0 spec, but it will be updated in the following specification version.    @param  This                  A pointer to the EFI_USB2_HC_PROTOCOL instance.   @param  DeviceAddress         Represents the address of the target device on the USB.   @param  EndPointAddress       The combination of an endpoint number and an endpoint direction of the                                 target USB device.   @param  DeviceSpeed           Indicates device speed.   @param  MaximumPacketLength   Indicates the maximum packet size the target endpoint is capable of                                 sending or receiving.   @param  Data                  A pointer to the buffer of data that will be transmitted to USB device or                                 received from USB device.   @param  DataLength            On input, the size, in bytes, of the data buffer specified by Data. On                                 output, the number of bytes transferred.   @param  DataToggle            A pointer to the data toggle value.   @param  TimeOut               Indicates the maximum time, in milliseconds, which the transfer is                                 allowed to complete.   @param  Translator            A pointr to the transaction translator data.   @param  TransferResult        A pointer to the detailed result information from the synchronous                                 interrupt transfer.    @retval EFI_SUCCESS           The synchronous interrupt transfer was completed successfully.   @retval EFI_INVALID_PARAMETER Some parameters are invalid.   @retval EFI_OUT_OF_RESOURCES  The synchronous interrupt transfer could not be submitted due to a lack of resources.   @retval EFI_TIMEOUT           The synchronous interrupt transfer failed due to timeout.   @retval EFI_DEVICE_ERROR      The synchronous interrupt transfer failed due to host controller or device error.                                 Caller should check TransferResult for detailed error information.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USB2_HC_PROTOCOL_SYNC_INTERRUPT_TRANSFER
function_decl|)
parameter_list|(
name|IN
name|EFI_USB2_HC_PROTOCOL
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
name|DeviceSpeed
parameter_list|,
name|IN
name|UINTN
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
name|IN
name|EFI_USB2_HC_TRANSACTION_TRANSLATOR
modifier|*
name|Translator
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|TransferResult
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|EFI_USB_MAX_ISO_BUFFER_NUM
value|7
end_define

begin_define
define|#
directive|define
name|EFI_USB_MAX_ISO_BUFFER_NUM1
value|2
end_define

begin_comment
comment|/**   Submits isochronous transfer to an isochronous endpoint of a USB device.    This function is used to submit isochronous transfer to a target endpoint of a USB device.    The target endpoint is specified by DeviceAddressand EndpointAddress. Isochronous transfers are    used when working with isochronous date. It provides periodic, continuous communication between    the host and a device. Isochronous transfers can beused only by full-speed, high-speed, and    super-speed devices.    High-speed isochronous transfers can be performed using multiple data buffers. The number of    buffers that are actually prepared for the transfer is specified by DataBuffersNumber. For   full-speed isochronous transfers this value is ignored.    Data represents a list of pointers to the data buffers. For full-speed isochronous transfers   only the data pointed by Data[0]shall be used. For high-speed isochronous transfers and for   the split transactions depending on DataLengththere several data buffers canbe used. For the   high-speed isochronous transfers the total number of buffers must not exceed EFI_USB_MAX_ISO_BUFFER_NUM.     For split transactions performed on full-speed device by high-speed host controller the total   number of buffers is limited to EFI_USB_MAX_ISO_BUFFER_NUM1.   If the isochronous transfer is successful, then EFI_SUCCESSis returned. The isochronous transfer    is designed to be completed within one USB frame time, if it cannot be completed, EFI_TIMEOUT   is returned. If an error other than timeout occurs during the USB transfer, then EFI_DEVICE_ERROR   is returned and the detailed status code will be returned in TransferResult.    EFI_INVALID_PARAMETERis returned if one of the following conditionsis satisfied:     - Data is NULL.      - DataLength is 0.     - DeviceSpeed is not one of the supported values listed above.     - MaximumPacketLength is invalid. MaximumPacketLength must be 1023 or less for full-speed devices,       and 1024 or less for high-speed and super-speed devices.     - TransferResult is NULL.    @param  This                  A pointer to the EFI_USB2_HC_PROTOCOL instance.   @param  DeviceAddress         Represents the address of the target device on the USB.   @param  EndPointAddress       The combination of an endpoint number and an endpoint direction of the                                 target USB device.   @param  DeviceSpeed           Indicates device speed. The supported values are EFI_USB_SPEED_FULL,                                  EFI_USB_SPEED_HIGH, or EFI_USB_SPEED_SUPER.   @param  MaximumPacketLength   Indicates the maximum packet size the target endpoint is capable of                                 sending or receiving.   @param  DataBuffersNumber     Number of data buffers prepared for the transfer.   @param  Data                  Array of pointers to the buffers of data that will be transmitted to USB                                 device or received from USB device.   @param  DataLength            Specifies the length, in bytes, of the data to be sent to or received from                                 the USB device.   @param  Translator            A pointer to the transaction translator data.   @param  TransferResult        A pointer to the detailed result information of the isochronous transfer.    @retval EFI_SUCCESS           The isochronous transfer was completed successfully.   @retval EFI_INVALID_PARAMETER Some parameters are invalid.   @retval EFI_OUT_OF_RESOURCES  The isochronous transfer could not be submitted due to a lack of resources.   @retval EFI_TIMEOUT           The isochronous transfer cannot be completed within the one USB frame time.   @retval EFI_DEVICE_ERROR      The isochronous transfer failed due to host controller or device error.                                 Caller should check TransferResult for detailed error information.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USB2_HC_PROTOCOL_ISOCHRONOUS_TRANSFER
function_decl|)
parameter_list|(
name|IN
name|EFI_USB2_HC_PROTOCOL
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
name|DeviceSpeed
parameter_list|,
name|IN
name|UINTN
name|MaximumPacketLength
parameter_list|,
name|IN
name|UINT8
name|DataBuffersNumber
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|Data
index|[
name|EFI_USB_MAX_ISO_BUFFER_NUM
index|]
parameter_list|,
name|IN
name|UINTN
name|DataLength
parameter_list|,
name|IN
name|EFI_USB2_HC_TRANSACTION_TRANSLATOR
modifier|*
name|Translator
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|TransferResult
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Submits nonblocking isochronous transfer to an isochronous endpoint of a USB device.    This is an asynchronous type of USB isochronous transfer. If the caller submits a USB   isochronous transfer request through this function, this function will return immediately.    When the isochronous transfer completes, the IsochronousCallbackfunction will be triggered,   the caller can know the transfer results. If the transfer is successful, the caller can get   the data received or sent in this callback function.    The target endpoint is specified by DeviceAddressand EndpointAddress. Isochronous transfers   are used when working with isochronous date. It provides periodic, continuous communication   between the host and a device. Isochronous transfers can be used only by full-speed, high-speed,   and super-speed devices.    High-speed isochronous transfers can be performed using multiple data buffers. The number of    buffers that are actually prepared for the transfer is specified by DataBuffersNumber. For   full-speed isochronous transfers this value is ignored.    Data represents a list of pointers to the data buffers. For full-speed isochronous transfers   only the data pointed by Data[0] shall be used. For high-speed isochronous transfers and for   the split transactions depending on DataLength there several data buffers can be used. For   the high-speed isochronous transfers the total number of buffers must not exceed EFI_USB_MAX_ISO_BUFFER_NUM.    For split transactions performed on full-speed device by high-speed host controller the total   number of buffers is limited to EFI_USB_MAX_ISO_BUFFER_NUM1.    EFI_INVALID_PARAMETER is returned if one of the following conditionsis satisfied:     - Data is NULL.      - DataLength is 0.     - DeviceSpeed is not one of the supported values listed above.     - MaximumPacketLength is invalid. MaximumPacketLength must be 1023 or less for full-speed        devices and 1024 or less for high-speed and super-speed devices.    @param  This                  A pointer to the EFI_USB2_HC_PROTOCOL instance.   @param  DeviceAddress         Represents the address of the target device on the USB.   @param  EndPointAddress       The combination of an endpoint number and an endpoint direction of the                                 target USB device.   @param  DeviceSpeed           Indicates device speed. The supported values are EFI_USB_SPEED_FULL,                                  EFI_USB_SPEED_HIGH, or EFI_USB_SPEED_SUPER.   @param  MaximumPacketLength   Indicates the maximum packet size the target endpoint is capable of                                 sending or receiving.   @param  DataBuffersNumber     Number of data buffers prepared for the transfer.   @param  Data                  Array of pointers to the buffers of data that will be transmitted to USB                                 device or received from USB device.   @param  DataLength            Specifies the length, in bytes, of the data to be sent to or received from                                 the USB device.   @param  Translator            A pointer to the transaction translator data.   @param  IsochronousCallback   The Callback function. This function is called if the requested                                 isochronous transfer is completed.   @param  Context               Data passed to the IsochronousCallback function. This is an                                 optional parameter and may be NULL.    @retval EFI_SUCCESS           The asynchronous isochronous transfer request has been successfully                                 submitted or canceled.   @retval EFI_INVALID_PARAMETER Some parameters are invalid.   @retval EFI_OUT_OF_RESOURCES  The asynchronous isochronous transfer could not be submitted due to                                 a lack of resources.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USB2_HC_PROTOCOL_ASYNC_ISOCHRONOUS_TRANSFER
function_decl|)
parameter_list|(
name|IN
name|EFI_USB2_HC_PROTOCOL
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
name|DeviceSpeed
parameter_list|,
name|IN
name|UINTN
name|MaximumPacketLength
parameter_list|,
name|IN
name|UINT8
name|DataBuffersNumber
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|Data
index|[
name|EFI_USB_MAX_ISO_BUFFER_NUM
index|]
parameter_list|,
name|IN
name|UINTN
name|DataLength
parameter_list|,
name|IN
name|EFI_USB2_HC_TRANSACTION_TRANSLATOR
modifier|*
name|Translator
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
comment|/**   Retrieves the current status of a USB root hub port.    @param  This       A pointer to the EFI_USB2_HC_PROTOCOL instance.   @param  PortNumber Specifies the root hub port from which the status is to be retrieved.                      This value is zero based.   @param  PortStatus A pointer to the current port status bits and port status change bits.    @retval EFI_SUCCESS           The status of the USB root hub port specified by PortNumber                                 was returned in PortStatus.   @retval EFI_INVALID_PARAMETER PortNumber is invalid.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USB2_HC_PROTOCOL_GET_ROOTHUB_PORT_STATUS
function_decl|)
parameter_list|(
name|IN
name|EFI_USB2_HC_PROTOCOL
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
comment|/**   Sets a feature for the specified root hub port.    @param  This        A pointer to the EFI_USB2_HC_PROTOCOL instance.   @param  PortNumber  Specifies the root hub port whose feature is requested to be set. This                       value is zero based.   @param  PortFeature Indicates the feature selector associated with the feature set request.    @retval EFI_SUCCESS           The feature specified by PortFeature was set for the USB                                 root hub port specified by PortNumber.   @retval EFI_INVALID_PARAMETER PortNumber is invalid or PortFeature is invalid for this function.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USB2_HC_PROTOCOL_SET_ROOTHUB_PORT_FEATURE
function_decl|)
parameter_list|(
name|IN
name|EFI_USB2_HC_PROTOCOL
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
comment|/**   Clears a feature for the specified root hub port.    @param  This        A pointer to the EFI_USB2_HC_PROTOCOL instance.   @param  PortNumber  Specifies the root hub port whose feature is requested to be cleared. This                       value is zero based.   @param  PortFeature Indicates the feature selector associated with the feature clear request.    @retval EFI_SUCCESS           The feature specified by PortFeature was cleared for the USB                                 root hub port specified by PortNumber.   @retval EFI_INVALID_PARAMETER PortNumber is invalid or PortFeature is invalid for this function.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USB2_HC_PROTOCOL_CLEAR_ROOTHUB_PORT_FEATURE
function_decl|)
parameter_list|(
name|IN
name|EFI_USB2_HC_PROTOCOL
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
comment|/// The EFI_USB2_HC_PROTOCOL provides USB host controller management, basic
end_comment

begin_comment
comment|/// data transactions over a USB bus, and USB root hub access. A device driver
end_comment

begin_comment
comment|/// that wishes to manage a USB bus in a system retrieves the EFI_USB2_HC_PROTOCOL
end_comment

begin_comment
comment|/// instance that is associated with the USB bus to be managed. A device handle
end_comment

begin_comment
comment|/// for a USB host controller will minimally contain an EFI_DEVICE_PATH_PROTOCOL
end_comment

begin_comment
comment|/// instance, and an EFI_USB2_HC_PROTOCOL instance.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_USB2_HC_PROTOCOL
block|{
name|EFI_USB2_HC_PROTOCOL_GET_CAPABILITY
name|GetCapability
decl_stmt|;
name|EFI_USB2_HC_PROTOCOL_RESET
name|Reset
decl_stmt|;
name|EFI_USB2_HC_PROTOCOL_GET_STATE
name|GetState
decl_stmt|;
name|EFI_USB2_HC_PROTOCOL_SET_STATE
name|SetState
decl_stmt|;
name|EFI_USB2_HC_PROTOCOL_CONTROL_TRANSFER
name|ControlTransfer
decl_stmt|;
name|EFI_USB2_HC_PROTOCOL_BULK_TRANSFER
name|BulkTransfer
decl_stmt|;
name|EFI_USB2_HC_PROTOCOL_ASYNC_INTERRUPT_TRANSFER
name|AsyncInterruptTransfer
decl_stmt|;
name|EFI_USB2_HC_PROTOCOL_SYNC_INTERRUPT_TRANSFER
name|SyncInterruptTransfer
decl_stmt|;
name|EFI_USB2_HC_PROTOCOL_ISOCHRONOUS_TRANSFER
name|IsochronousTransfer
decl_stmt|;
name|EFI_USB2_HC_PROTOCOL_ASYNC_ISOCHRONOUS_TRANSFER
name|AsyncIsochronousTransfer
decl_stmt|;
name|EFI_USB2_HC_PROTOCOL_GET_ROOTHUB_PORT_STATUS
name|GetRootHubPortStatus
decl_stmt|;
name|EFI_USB2_HC_PROTOCOL_SET_ROOTHUB_PORT_FEATURE
name|SetRootHubPortFeature
decl_stmt|;
name|EFI_USB2_HC_PROTOCOL_CLEAR_ROOTHUB_PORT_FEATURE
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
name|gEfiUsb2HcProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

