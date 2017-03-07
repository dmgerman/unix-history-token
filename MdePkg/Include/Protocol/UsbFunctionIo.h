begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   The USB Function Protocol provides an I/O abstraction for a USB Controller   operating in Function mode (also commonly referred to as Device, Peripheral,   or Target mode) and the mechanisms by which the USB Function can communicate   with the USB Host. It is used by other UEFI drivers or applications to   perform data transactions and basic USB controller management over a USB   Function port.    This simple protocol only supports USB 2.0 bulk transfers on systems with a   single configuration and a single interface. It does not support isochronous   or interrupt transfers, alternate interfaces, or USB 3.0 functionality.   Future revisions of this protocol may support these or additional features.    Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__USB_FUNCTION_IO_H__
end_ifndef

begin_define
define|#
directive|define
name|__USB_FUNCTION_IO_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/UsbIo.h>
end_include

begin_define
define|#
directive|define
name|EFI_USBFN_IO_PROTOCOL_GUID
define|\
value|{ \       0x32d2963a, 0xfe5d, 0x4f30, {0xb6, 0x33, 0x6e, 0x5d, 0xc5, 0x58, 0x3, 0xcc} \     }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_USBFN_IO_PROTOCOL
name|EFI_USBFN_IO_PROTOCOL
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_USBFN_IO_PROTOCOL_REVISION
value|0x00010001
end_define

begin_typedef
typedef|typedef
enum|enum
name|_EFI_USBFN_PORT_TYPE
block|{
name|EfiUsbUnknownPort
init|=
literal|0
block|,
name|EfiUsbStandardDownstreamPort
block|,
name|EfiUsbChargingDownstreamPort
block|,
name|EfiUsbDedicatedChargingPort
block|,
name|EfiUsbInvalidDedicatedChargingPort
block|}
name|EFI_USBFN_PORT_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_USB_INTERFACE_DESCRIPTOR
modifier|*
name|InterfaceDescriptor
decl_stmt|;
name|EFI_USB_ENDPOINT_DESCRIPTOR
modifier|*
modifier|*
name|EndpointDescriptorTable
decl_stmt|;
block|}
name|EFI_USB_INTERFACE_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_USB_CONFIG_DESCRIPTOR
modifier|*
name|ConfigDescriptor
decl_stmt|;
name|EFI_USB_INTERFACE_INFO
modifier|*
modifier|*
name|InterfaceInfoTable
decl_stmt|;
block|}
name|EFI_USB_CONFIG_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_USB_DEVICE_DESCRIPTOR
modifier|*
name|DeviceDescriptor
decl_stmt|;
name|EFI_USB_CONFIG_INFO
modifier|*
modifier|*
name|ConfigInfoTable
decl_stmt|;
block|}
name|EFI_USB_DEVICE_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|_EFI_USB_ENDPOINT_TYPE
block|{
name|UsbEndpointControl
init|=
literal|0x00
block|,
comment|//UsbEndpointIsochronous = 0x01,
name|UsbEndpointBulk
init|=
literal|0x02
block|,
comment|//UsbEndpointInterrupt = 0x03
block|}
name|EFI_USB_ENDPOINT_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|_EFI_USBFN_DEVICE_INFO_ID
block|{
name|EfiUsbDeviceInfoUnknown
init|=
literal|0
block|,
name|EfiUsbDeviceInfoSerialNumber
block|,
name|EfiUsbDeviceInfoManufacturerName
block|,
name|EfiUsbDeviceInfoProductName
block|}
name|EFI_USBFN_DEVICE_INFO_ID
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|_EFI_USBFN_ENDPOINT_DIRECTION
block|{
name|EfiUsbEndpointDirectionHostOut
init|=
literal|0
block|,
name|EfiUsbEndpointDirectionHostIn
block|,
name|EfiUsbEndpointDirectionDeviceTx
init|=
name|EfiUsbEndpointDirectionHostIn
block|,
name|EfiUsbEndpointDirectionDeviceRx
init|=
name|EfiUsbEndpointDirectionHostOut
block|}
name|EFI_USBFN_ENDPOINT_DIRECTION
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|_EFI_USBFN_MESSAGE
block|{
comment|//
comment|// Nothing
comment|//
name|EfiUsbMsgNone
init|=
literal|0
block|,
comment|//
comment|// SETUP packet is received, returned Buffer contains
comment|// EFI_USB_DEVICE_REQUEST struct
comment|//
name|EfiUsbMsgSetupPacket
block|,
comment|//
comment|// Indicates that some of the requested data has been received from the
comment|// host. It is the responsibility of the class driver to determine if it
comment|// needs to wait for any remaining data. Returned Buffer contains
comment|// EFI_USBFN_TRANSFER_RESULT struct containing endpoint number, transfer
comment|// status and count of bytes received.
comment|//
name|EfiUsbMsgEndpointStatusChangedRx
block|,
comment|//
comment|// Indicates that some of the requested data has been transmitted to the
comment|// host. It is the responsibility of the class driver to determine if any
comment|// remaining data needs to be resent. Returned Buffer contains
comment|// EFI_USBFN_TRANSFER_RESULT struct containing endpoint number, transfer
comment|// status and count of bytes sent.
comment|//
name|EfiUsbMsgEndpointStatusChangedTx
block|,
comment|//
comment|// DETACH bus event signaled
comment|//
name|EfiUsbMsgBusEventDetach
block|,
comment|//
comment|// ATTACH bus event signaled
comment|//
name|EfiUsbMsgBusEventAttach
block|,
comment|//
comment|// RESET bus event signaled
comment|//
name|EfiUsbMsgBusEventReset
block|,
comment|//
comment|// SUSPEND bus event signaled
comment|//
name|EfiUsbMsgBusEventSuspend
block|,
comment|//
comment|// RESUME bus event signaled
comment|//
name|EfiUsbMsgBusEventResume
block|,
comment|//
comment|// Bus speed updated, returned buffer indicated bus speed using
comment|// following enumeration named EFI_USB_BUS_SPEED
comment|//
name|EfiUsbMsgBusEventSpeed
block|}
name|EFI_USBFN_MESSAGE
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|_EFI_USBFN_TRANSFER_STATUS
block|{
name|UsbTransferStatusUnknown
init|=
literal|0
block|,
name|UsbTransferStatusComplete
block|,
name|UsbTransferStatusAborted
block|,
name|UsbTransferStatusActive
block|,
name|UsbTransferStatusNone
block|}
name|EFI_USBFN_TRANSFER_STATUS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_USBFN_TRANSFER_RESULT
block|{
name|UINTN
name|BytesTransferred
decl_stmt|;
name|EFI_USBFN_TRANSFER_STATUS
name|TransferStatus
decl_stmt|;
name|UINT8
name|EndpointIndex
decl_stmt|;
name|EFI_USBFN_ENDPOINT_DIRECTION
name|Direction
decl_stmt|;
name|VOID
modifier|*
name|Buffer
decl_stmt|;
block|}
name|EFI_USBFN_TRANSFER_RESULT
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|_EFI_USB_BUS_SPEED
block|{
name|UsbBusSpeedUnknown
init|=
literal|0
block|,
name|UsbBusSpeedLow
block|,
name|UsbBusSpeedFull
block|,
name|UsbBusSpeedHigh
block|,
name|UsbBusSpeedSuper
block|,
name|UsbBusSpeedMaximum
init|=
name|UsbBusSpeedSuper
block|}
name|EFI_USB_BUS_SPEED
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|_EFI_USBFN_MESSAGE_PAYLOAD
block|{
name|EFI_USB_DEVICE_REQUEST
name|udr
decl_stmt|;
name|EFI_USBFN_TRANSFER_RESULT
name|utr
decl_stmt|;
name|EFI_USB_BUS_SPEED
name|ubs
decl_stmt|;
block|}
name|EFI_USBFN_MESSAGE_PAYLOAD
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|_EFI_USBFN_POLICY_TYPE
block|{
name|EfiUsbPolicyUndefined
init|=
literal|0
block|,
name|EfiUsbPolicyMaxTransactionSize
block|,
name|EfiUsbPolicyZeroLengthTerminationSupport
block|,
name|EfiUsbPolicyZeroLengthTermination
block|}
name|EFI_USBFN_POLICY_TYPE
typedef|;
end_typedef

begin_comment
comment|/**   Returns information about what USB port type was attached.    @param[in]  This              A pointer to the EFI_USBFN_IO_PROTOCOL instance.   @param[out] PortType          Returns the USB port type.    @retval EFI_SUCCESS           The function returned successfully.   @retval EFI_INVALID_PARAMETER A parameter is invalid.   @retval EFI_DEVICE_ERROR      The physical device reported an error.   @retval EFI_NOT_READY         The physical device is busy or not ready to                                 process this request or there is no USB port                                 attached to the device.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USBFN_IO_DETECT_PORT
function_decl|)
parameter_list|(
name|IN
name|EFI_USBFN_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_USBFN_PORT_TYPE
modifier|*
name|PortType
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Configures endpoints based on supplied device and configuration descriptors.    Assuming that the hardware has already been initialized, this function configures   the endpoints using the device information supplied by DeviceInfo, activates the   port, and starts receiving USB events.    This function must ignore the bMaxPacketSize0field of the Standard Device Descriptor   and the wMaxPacketSize field of the Standard Endpoint Descriptor that are made   available through DeviceInfo.    @param[in]  This              A pointer to the EFI_USBFN_IO_PROTOCOL instance.   @param[out] DeviceInfo        A pointer to EFI_USBFN_DEVICE_INFO instance.    @retval EFI_SUCCESS           The function returned successfully.   @retval EFI_INVALID_PARAMETER A parameter is invalid.   @retval EFI_DEVICE_ERROR      The physical device reported an error.   @retval EFI_NOT_READY         The physical device is busy or not ready to process                                 this request.   @retval EFI_OUT_OF_RESOURCES  The request could not be completed due to lack of                                 resources.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USBFN_IO_CONFIGURE_ENABLE_ENDPOINTS
function_decl|)
parameter_list|(
name|IN
name|EFI_USBFN_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_USB_DEVICE_INFO
modifier|*
name|DeviceInfo
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Returns the maximum packet size of the specified endpoint type for the supplied   bus speed.    If the BusSpeed is UsbBusSpeedUnknown, the maximum speed the underlying controller   supports is assumed.    This protocol currently does not support isochronous or interrupt transfers. Future   revisions of this protocol may eventually support it.    @param[in]  This              A pointer to the EFI_USBFN_IO_PROTOCOLinstance.   @param[in]  EndpointType      Endpoint type as defined as EFI_USB_ENDPOINT_TYPE.   @param[in]  BusSpeed          Bus speed as defined as EFI_USB_BUS_SPEED.   @param[out] MaxPacketSize     The maximum packet size, in bytes, of the specified                                 endpoint type.    @retval EFI_SUCCESS           The function returned successfully.   @retval EFI_INVALID_PARAMETER A parameter is invalid.   @retval EFI_DEVICE_ERROR      The physical device reported an error.   @retval EFI_NOT_READY         The physical device is busy or not ready to process                                 this request.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USBFN_IO_GET_ENDPOINT_MAXPACKET_SIZE
function_decl|)
parameter_list|(
name|IN
name|EFI_USBFN_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_USB_ENDPOINT_TYPE
name|EndpointType
parameter_list|,
name|IN
name|EFI_USB_BUS_SPEED
name|BusSpeed
parameter_list|,
name|OUT
name|UINT16
modifier|*
name|MaxPacketSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Returns device specific information based on the supplied identifier as a Unicode string.    If the supplied Buffer isn't large enough, or is NULL, the method fails with   EFI_BUFFER_TOO_SMALL and the required size is returned through BufferSize. All returned   strings are in Unicode format.    An Id of EfiUsbDeviceInfoUnknown is treated as an invalid parameter.    @param[in]  This              A pointer to the EFI_USBFN_IO_PROTOCOLinstance.   @param[in]  Id                The requested information id.     @param[in]  BufferSize        On input, the size of the Buffer in bytes. On output, the                                 amount of data returned in Buffer in bytes.   @param[out] Buffer            A pointer to a buffer to returnthe requested information                                 as a Unicode string.    @retval EFI_SUCCESS           The function returned successfully.   @retval EFI_INVALID_PARAMETER A parameter is invalid.   @retval EFI_DEVICE_ERROR      The physical device reported an error.   @retval EFI_BUFFER_TOO_SMALL  Supplied buffer isn't large enough to hold the request string.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USBFN_IO_GET_DEVICE_INFO
function_decl|)
parameter_list|(
name|IN
name|EFI_USBFN_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_USBFN_DEVICE_INFO_ID
name|Id
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
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Returns the vendor-id and product-id of the device.    @param[in]  This              A pointer to the EFI_USBFN_IO_PROTOCOL instance.   @param[out] Vid               Returned vendor-id of the device.   @param[out] Pid               Returned product-id of the device.    @retval EFI_SUCCESS           The function returned successfully.   @retval EFI_INVALID_PARAMETER A parameter is invalid.   @retval EFI_NOT_FOUND         Unable to return the vendor-id or the product-id.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USBFN_IO_GET_VENDOR_ID_PRODUCT_ID
function_decl|)
parameter_list|(
name|IN
name|EFI_USBFN_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|UINT16
modifier|*
name|Vid
parameter_list|,
name|OUT
name|UINT16
modifier|*
name|Pid
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Aborts the transfer on the specified endpoint.    This function should fail with EFI_INVALID_PARAMETER if the specified direction   is incorrect for the endpoint.    @param[in]  This              A pointer to the EFI_USBFN_IO_PROTOCOL instance.   @param[in]  EndpointIndex     Indicates the endpoint on which the ongoing transfer                                 needs to be canceled.   @param[in]  Direction         Direction of the endpoint.    @retval EFI_SUCCESS           The function returned successfully.   @retval EFI_INVALID_PARAMETER A parameter is invalid.   @retval EFI_DEVICE_ERROR      The physical device reported an error.   @retval EFI_NOT_READY         The physical device is busy or not ready to process                                 this request.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USBFN_IO_ABORT_TRANSFER
function_decl|)
parameter_list|(
name|IN
name|EFI_USBFN_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT8
name|EndpointIndex
parameter_list|,
name|IN
name|EFI_USBFN_ENDPOINT_DIRECTION
name|Direction
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Returns the stall state on the specified endpoint.    This function should fail with EFI_INVALID_PARAMETER if the specified direction   is incorrect for the endpoint.    @param[in]      This          A pointer to the EFI_USBFN_IO_PROTOCOL instance.   @param[in]      EndpointIndex Indicates the endpoint.   @param[in]      Direction     Direction of the endpoint.   @param[in, out] State         Boolean, true value indicates that the endpoint                                 is in a stalled state, false otherwise.    @retval EFI_SUCCESS           The function returned successfully.   @retval EFI_INVALID_PARAMETER A parameter is invalid.   @retval EFI_DEVICE_ERROR      The physical device reported an error.   @retval EFI_NOT_READY         The physical device is busy or not ready to process                                 this request.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USBFN_IO_GET_ENDPOINT_STALL_STATE
function_decl|)
parameter_list|(
name|IN
name|EFI_USBFN_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT8
name|EndpointIndex
parameter_list|,
name|IN
name|EFI_USBFN_ENDPOINT_DIRECTION
name|Direction
parameter_list|,
name|IN
name|OUT
name|BOOLEAN
modifier|*
name|State
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Sets or clears the stall state on the specified endpoint.    This function should fail with EFI_INVALID_PARAMETER if the specified direction   is incorrect for the endpoint.    @param[in]  This              A pointer to the EFI_USBFN_IO_PROTOCOL instance.   @param[in]  EndpointIndex     Indicates the endpoint.   @param[in]  Direction         Direction of the endpoint.   @param[in]  State             Requested stall state on the specified endpoint.                                 True value causes the endpoint to stall; false                                 value clears an existing stall.    @retval EFI_SUCCESS           The function returned successfully.   @retval EFI_INVALID_PARAMETER A parameter is invalid.   @retval EFI_DEVICE_ERROR      The physical device reported an error.   @retval EFI_NOT_READY         The physical device is busy or not ready to process                                 this request.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USBFN_IO_SET_ENDPOINT_STALL_STATE
function_decl|)
parameter_list|(
name|IN
name|EFI_USBFN_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT8
name|EndpointIndex
parameter_list|,
name|IN
name|EFI_USBFN_ENDPOINT_DIRECTION
name|Direction
parameter_list|,
name|IN
name|OUT
name|BOOLEAN
modifier|*
name|State
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function is called repeatedly to get information on USB bus states,   receive-completion and transmit-completion events on the endpoints, and   notification on setup packet on endpoint 0.    A class driver must call EFI_USBFN_IO_PROTOCOL.EventHandler()repeatedly   to receive updates on the transfer status and number of bytes transferred   on various endpoints.    @param[in]      This          A pointer to the EFI_USBFN_IO_PROTOCOL instance.   @param[out]     Message       Indicates the event that initiated this notification.   @param[in, out] PayloadSize   On input, the size of the memory pointed by                                 Payload. On output, the amount ofdata returned                                 in Payload.   @param[out]     Payload       A pointer to EFI_USBFN_MESSAGE_PAYLOAD instance                                 to return additional payload for current message.    @retval EFI_SUCCESS           The function returned successfully.   @retval EFI_INVALID_PARAMETER A parameter is invalid.   @retval EFI_DEVICE_ERROR      The physical device reported an error.   @retval EFI_NOT_READY         The physical device is busy or not ready to process                                 this request.   @retval EFI_BUFFER_TOO_SMALL  The Supplied buffer is not large enough to hold                                 the message payload.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USBFN_IO_EVENTHANDLER
function_decl|)
parameter_list|(
name|IN
name|EFI_USBFN_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_USBFN_MESSAGE
modifier|*
name|Message
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|PayloadSize
parameter_list|,
name|OUT
name|EFI_USBFN_MESSAGE_PAYLOAD
modifier|*
name|Payload
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function handles transferring data to or from the host on the specified   endpoint, depending on the direction specified.    A class driver must call EFI_USBFN_IO_PROTOCOL.EventHandler() repeatedly to   receive updates on the transfer status and the number of bytes transferred on   various endpoints. Upon an update of the transfer status, the Buffer field of   the EFI_USBFN_TRANSFER_RESULT structure (as described in the function description   for EFI_USBFN_IO_PROTOCOL.EventHandler()) must be initialized with the Buffer   pointer that was supplied to this method.    The overview of the call sequence is illustrated in the Figure 54.    This function should fail with EFI_INVALID_PARAMETER if the specified direction   is incorrect for the endpoint.    @param[in]      This          A pointer to the EFI_USBFN_IO_PROTOCOL instance.   @param[in]      EndpointIndex Indicates the endpoint on which TX or RX transfer                                 needs to take place.   @param[in]      Direction     Direction of the endpoint.   @param[in, out] BufferSize    If Direction is EfiUsbEndpointDirectionDeviceRx:                                   On input, the size of the Bufferin bytes.                                   On output, the amount of data returned in Buffer                                   in bytes.                                 If Direction is EfiUsbEndpointDirectionDeviceTx:                                   On input, the size of the Bufferin bytes.                                   On output, the amount of data transmitted in bytes.   @param[in, out] Buffer        If Direction is EfiUsbEndpointDirectionDeviceRx:                                   The Buffer to return the received data.                                 If Directionis EfiUsbEndpointDirectionDeviceTx:                                   The Buffer that contains the data to be transmitted.    @retval EFI_SUCCESS           The function returned successfully.   @retval EFI_INVALID_PARAMETER A parameter is invalid.   @retval EFI_DEVICE_ERROR      The physical device reported an error.   @retval EFI_NOT_READY         The physical device is busy or not ready to process                                 this request.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USBFN_IO_TRANSFER
function_decl|)
parameter_list|(
name|IN
name|EFI_USBFN_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT8
name|EndpointIndex
parameter_list|,
name|IN
name|EFI_USBFN_ENDPOINT_DIRECTION
name|Direction
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|BufferSize
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Returns the maximum supported transfer size.    Returns the maximum number of bytes that the underlying controller can accommodate   in a single transfer.    @param[in]  This              A pointer to the EFI_USBFN_IO_PROTOCOL instance.   @param[out] MaxTransferSize   The maximum supported transfer size, in bytes.    @retval EFI_SUCCESS           The function returned successfully.   @retval EFI_INVALID_PARAMETER A parameter is invalid.   @retval EFI_DEVICE_ERROR      The physical device reported an error.   @retval EFI_NOT_READY         The physical device is busy or not ready to process                                 this request.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USBFN_IO_GET_MAXTRANSFER_SIZE
function_decl|)
parameter_list|(
name|IN
name|EFI_USBFN_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|MaxTransferSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Allocates a transfer buffer of the specified sizethat satisfies the controller   requirements.    The AllocateTransferBuffer() function allocates a memory region of Size bytes and   returns the address of the allocated memory that satisfies the underlying controller   requirements in the location referenced by Buffer.    The allocated transfer buffer must be freed using a matching call to   EFI_USBFN_IO_PROTOCOL.FreeTransferBuffer()function.    @param[in]  This              A pointer to the EFI_USBFN_IO_PROTOCOL instance.   @param[in]  Size              The number of bytes to allocate for the transfer buffer.   @param[out] Buffer            A pointer to a pointer to the allocated buffer if the                                 call succeeds; undefined otherwise.    @retval EFI_SUCCESS           The function returned successfully.   @retval EFI_INVALID_PARAMETER A parameter is invalid.   @retval EFI_OUT_OF_RESOURCES  The requested transfer buffer could not be allocated.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USBFN_IO_ALLOCATE_TRANSFER_BUFFER
function_decl|)
parameter_list|(
name|IN
name|EFI_USBFN_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINTN
name|Size
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Deallocates the memory allocated for the transfer buffer by the   EFI_USBFN_IO_PROTOCOL.AllocateTransferBuffer() function.    The EFI_USBFN_IO_PROTOCOL.FreeTransferBuffer() function deallocates the   memory specified by Buffer. The Buffer that is freed must have been allocated   by EFI_USBFN_IO_PROTOCOL.AllocateTransferBuffer().    @param[in]  This              A pointer to the EFI_USBFN_IO_PROTOCOL instance.   @param[in]  Buffer            A pointer to the transfer buffer to deallocate.    @retval EFI_SUCCESS           The function returned successfully.   @retval EFI_INVALID_PARAMETER A parameter is invalid.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USBFN_IO_FREE_TRANSFER_BUFFER
function_decl|)
parameter_list|(
name|IN
name|EFI_USBFN_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function supplies power to the USB controller if needed and initializes   the hardware and the internal data structures. The port must not be activated   by this function.    @param[in]  This              A pointer to the EFI_USBFN_IO_PROTOCOL instance.    @retval EFI_SUCCESS           The function returned successfully.   @retval EFI_INVALID_PARAMETER A parameter is invalid.   @retval EFI_DEVICE_ERROR      The physical device reported an error.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USBFN_IO_START_CONTROLLER
function_decl|)
parameter_list|(
name|IN
name|EFI_USBFN_IO_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function stops the USB hardware device.    @param[in]  This              A pointer to the EFI_USBFN_IO_PROTOCOL instance.    @retval EFI_SUCCESS           The function returned successfully.   @retval EFI_INVALID_PARAMETER A parameter is invalid.   @retval EFI_DEVICE_ERROR      The physical device reported an error.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USBFN_IO_STOP_CONTROLLER
function_decl|)
parameter_list|(
name|IN
name|EFI_USBFN_IO_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function sets the configuration policy for the specified non-control   endpoint.    This function can only be called before EFI_USBFN_IO_PROTOCOL.StartController()   or after EFI_USBFN_IO_PROTOCOL.StopController() has been called.    @param[in]  This              A pointer to the EFI_USBFN_IO_PROTOCOL instance.   @param[in]  EndpointIndex     Indicates the non-control endpoint for which the                                 policy needs to be set.   @param[in]  Direction         Direction of the endpoint.   @param[in]  PolicyType        Policy type the user is trying to set for the                                 specified non-control endpoint.   @param[in]  BufferSize        The size of the Bufferin bytes.   @param[in]  Buffer            The new value for the policy parameter that                                 PolicyType specifies.    @retval EFI_SUCCESS           The function returned successfully.   @retval EFI_INVALID_PARAMETER A parameter is invalid.   @retval EFI_DEVICE_ERROR      The physical device reported an error.   @retval EFI_UNSUPPORTED       Changing this policy value is not supported.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USBFN_IO_SET_ENDPOINT_POLICY
function_decl|)
parameter_list|(
name|IN
name|EFI_USBFN_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT8
name|EndpointIndex
parameter_list|,
name|IN
name|EFI_USBFN_ENDPOINT_DIRECTION
name|Direction
parameter_list|,
name|IN
name|EFI_USBFN_POLICY_TYPE
name|PolicyType
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

begin_comment
comment|/**   This function sets the configuration policy for the specified non-control   endpoint.    This function can only be called before EFI_USBFN_IO_PROTOCOL.StartController()   or after EFI_USBFN_IO_PROTOCOL.StopController() has been called.    @param[in]      This          A pointer to the EFI_USBFN_IO_PROTOCOL instance.   @param[in]      EndpointIndex Indicates the non-control endpoint for which the                                 policy needs to be set.   @param[in]      Direction     Direction of the endpoint.   @param[in]      PolicyType    Policy type the user is trying to retrieve for                                 the specified non-control endpoint.   @param[in, out] BufferSize    On input, the size of Bufferin bytes. On output,                                 the amount of data returned in Bufferin bytes.   @param[in, out] Buffer        A pointer to a buffer to return requested endpoint                                 policy value.    @retval EFI_SUCCESS           The function returned successfully.   @retval EFI_INVALID_PARAMETER A parameter is invalid.   @retval EFI_DEVICE_ERROR      The specified policy value is not supported.   @retval EFI_BUFFER_TOO_SMALL  Supplied buffer is not large enough to hold requested                                 policy value.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USBFN_IO_GET_ENDPOINT_POLICY
function_decl|)
parameter_list|(
name|IN
name|EFI_USBFN_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT8
name|EndpointIndex
parameter_list|,
name|IN
name|EFI_USBFN_ENDPOINT_DIRECTION
name|Direction
parameter_list|,
name|IN
name|EFI_USBFN_POLICY_TYPE
name|PolicyType
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|BufferSize
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_USBFN_IO_PROTOCOL provides basic data transactions and basic USB
end_comment

begin_comment
comment|/// controller management for a USB Function port.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_USBFN_IO_PROTOCOL
block|{
name|UINT32
name|Revision
decl_stmt|;
name|EFI_USBFN_IO_DETECT_PORT
name|DetectPort
decl_stmt|;
name|EFI_USBFN_IO_CONFIGURE_ENABLE_ENDPOINTS
name|ConfigureEnableEndpoints
decl_stmt|;
name|EFI_USBFN_IO_GET_ENDPOINT_MAXPACKET_SIZE
name|GetEndpointMaxPacketSize
decl_stmt|;
name|EFI_USBFN_IO_GET_DEVICE_INFO
name|GetDeviceInfo
decl_stmt|;
name|EFI_USBFN_IO_GET_VENDOR_ID_PRODUCT_ID
name|GetVendorIdProductId
decl_stmt|;
name|EFI_USBFN_IO_ABORT_TRANSFER
name|AbortTransfer
decl_stmt|;
name|EFI_USBFN_IO_GET_ENDPOINT_STALL_STATE
name|GetEndpointStallState
decl_stmt|;
name|EFI_USBFN_IO_SET_ENDPOINT_STALL_STATE
name|SetEndpointStallState
decl_stmt|;
name|EFI_USBFN_IO_EVENTHANDLER
name|EventHandler
decl_stmt|;
name|EFI_USBFN_IO_TRANSFER
name|Transfer
decl_stmt|;
name|EFI_USBFN_IO_GET_MAXTRANSFER_SIZE
name|GetMaxTransferSize
decl_stmt|;
name|EFI_USBFN_IO_ALLOCATE_TRANSFER_BUFFER
name|AllocateTransferBuffer
decl_stmt|;
name|EFI_USBFN_IO_FREE_TRANSFER_BUFFER
name|FreeTransferBuffer
decl_stmt|;
name|EFI_USBFN_IO_START_CONTROLLER
name|StartController
decl_stmt|;
name|EFI_USBFN_IO_STOP_CONTROLLER
name|StopController
decl_stmt|;
name|EFI_USBFN_IO_SET_ENDPOINT_POLICY
name|SetEndpointPolicy
decl_stmt|;
name|EFI_USBFN_IO_GET_ENDPOINT_POLICY
name|GetEndpointPolicy
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiUsbFunctionIoProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

