begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provides most USB APIs to support the Hid requests defined in USB Hid 1.1 spec   and the standard requests defined in USB 1.1 spec.  Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__USB_DXE_LIB_H__
end_ifndef

begin_define
define|#
directive|define
name|__USB_DXE_LIB_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/UsbIo.h>
end_include

begin_comment
comment|/**   Get the descriptor of the specified USB HID interface.    Submit a UsbGetHidDescriptor() request for the USB device specified by UsbIo   and Interface, and return the HID descriptor in HidDescriptor.   If UsbIo is NULL, then ASSERT().   If HidDescriptor is NULL, then ASSERT().    @param  UsbIo          A pointer to the USB I/O Protocol instance for the specific USB target.   @param  Interface      The index of the HID interface on the USB target.   @param  HidDescriptor  Pointer to the USB HID descriptor that was retrieved from                          the specified USB target and interface. Type EFI_USB_HID_DESCRIPTOR                          is defined in the MDE Package Industry Standard include file Usb.h.    @retval EFI_SUCCESS       The request executed successfully.   @retval EFI_TIMEOUT       A timeout occurred executing the request.   @retval EFI_DEVICE_ERROR  The request failed due to a device error.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|UsbGetHidDescriptor
parameter_list|(
name|IN
name|EFI_USB_IO_PROTOCOL
modifier|*
name|UsbIo
parameter_list|,
name|IN
name|UINT8
name|Interface
parameter_list|,
name|OUT
name|EFI_USB_HID_DESCRIPTOR
modifier|*
name|HidDescriptor
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Get the report descriptor of the specified USB HID interface.    Submit a USB get HID report descriptor request for the USB device specified by   UsbIo and Interface, and return the report descriptor in DescriptorBuffer.   If UsbIo is NULL, then ASSERT().   If DescriptorBuffer is NULL, then ASSERT().    @param  UsbIo             A pointer to the USB I/O Protocol instance for the specific USB target.   @param  Interface         The index of the report interface on the USB target.   @param  DescriptorLength  The size, in bytes, of DescriptorBuffer.   @param  DescriptorBuffer  A pointer to the buffer to store the report class descriptor.    @retval  EFI_SUCCESS           The request executed successfully.   @retval  EFI_OUT_OF_RESOURCES  The request could not be completed because the                                  buffer specified by DescriptorLength and DescriptorBuffer                                  is not large enough to hold the result of the request.   @retval  EFI_TIMEOUT           A timeout occurred executing the request.   @retval  EFI_DEVICE_ERROR      The request failed due to a device error.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|UsbGetReportDescriptor
parameter_list|(
name|IN
name|EFI_USB_IO_PROTOCOL
modifier|*
name|UsbIo
parameter_list|,
name|IN
name|UINT8
name|Interface
parameter_list|,
name|IN
name|UINT16
name|DescriptorLength
parameter_list|,
name|OUT
name|UINT8
modifier|*
name|DescriptorBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Get the HID protocol of the specified USB HID interface.    Submit a USB get HID protocol request for the USB device specified by UsbIo   and Interface, and return the protocol retrieved in Protocol.   If UsbIo is NULL, then ASSERT().   If Protocol is NULL, then ASSERT().    @param  UsbIo      A pointer to the USB I/O Protocol instance for the specific USB target.   @param  Interface  The index of the report interface on the USB target.   @param  Protocol   A pointer to the protocol for the specified USB target.    @retval  EFI_SUCCESS       The request executed successfully.   @retval  EFI_TIMEOUT       A timeout occurred executing the request.   @retval  EFI_DEVICE_ERROR  The request failed due to a device error.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|UsbGetProtocolRequest
parameter_list|(
name|IN
name|EFI_USB_IO_PROTOCOL
modifier|*
name|UsbIo
parameter_list|,
name|IN
name|UINT8
name|Interface
parameter_list|,
name|OUT
name|UINT8
modifier|*
name|Protocol
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Set the HID protocol of the specified USB HID interface.    Submit a USB set HID protocol request for the USB device specified by UsbIo   and Interface, and set the protocol to the value specified by Protocol.   If UsbIo is NULL, then ASSERT().    @param  UsbIo      A pointer to the USB I/O Protocol instance for the specific USB target.   @param  Interface  The index of the report interface on the USB target.   @param  Protocol   The protocol value to set for the specified USB target.    @retval  EFI_SUCCESS       The request executed successfully.   @retval  EFI_TIMEOUT       A timeout occurred executing the request.   @retval  EFI_DEVICE_ERROR  The request failed due to a device error.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|UsbSetProtocolRequest
parameter_list|(
name|IN
name|EFI_USB_IO_PROTOCOL
modifier|*
name|UsbIo
parameter_list|,
name|IN
name|UINT8
name|Interface
parameter_list|,
name|IN
name|UINT8
name|Protocol
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Set the idle rate of the specified USB HID report.    Submit a USB set HID report idle request for the USB device specified by UsbIo,   Interface, and ReportId, and set the idle rate to the value specified by Duration.   If UsbIo is NULL, then ASSERT().    @param  UsbIo      A pointer to the USB I/O Protocol instance for the specific USB target.   @param  Interface  The index of the report interface on the USB target.   @param  ReportId   The identifier of the report to retrieve.   @param  Duration   The idle rate to set for the specified USB target.    @retval  EFI_SUCCESS       The request executed successfully.   @retval  EFI_TIMEOUT       A timeout occurred executing the request.   @retval  EFI_DEVICE_ERROR  The request failed due to a device error.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|UsbSetIdleRequest
parameter_list|(
name|IN
name|EFI_USB_IO_PROTOCOL
modifier|*
name|UsbIo
parameter_list|,
name|IN
name|UINT8
name|Interface
parameter_list|,
name|IN
name|UINT8
name|ReportId
parameter_list|,
name|IN
name|UINT8
name|Duration
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Get the idle rate of the specified USB HID report.    Submit a USB get HID report idle request for the USB device specified by UsbIo,   Interface, and ReportId, and return the ide rate in Duration.   If UsbIo is NULL, then ASSERT().   If Duration is NULL, then ASSERT().    @param  UsbIo      A pointer to the USB I/O Protocol instance for the specific USB target.   @param  Interface  The index of the report interface on the USB target.   @param  ReportId   The identifier of the report to retrieve.   @param  Duration   A pointer to the idle rate retrieved from the specified USB target.    @retval  EFI_SUCCESS       The request executed successfully.   @retval  EFI_TIMEOUT       A timeout occurred executing the request.   @retval  EFI_DEVICE_ERROR  The request failed due to a device error.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|UsbGetIdleRequest
parameter_list|(
name|IN
name|EFI_USB_IO_PROTOCOL
modifier|*
name|UsbIo
parameter_list|,
name|IN
name|UINT8
name|Interface
parameter_list|,
name|IN
name|UINT8
name|ReportId
parameter_list|,
name|OUT
name|UINT8
modifier|*
name|Duration
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Set the report descriptor of the specified USB HID interface.    Submit a USB set HID report request for the USB device specified by UsbIo,   Interface, ReportId, and ReportType, and set the report descriptor using the   buffer specified by ReportLength and Report.   If UsbIo is NULL, then ASSERT().   If Report is NULL, then ASSERT().    @param  UsbIo         A pointer to the USB I/O Protocol instance for the specific USB target.   @param  Interface     The index of the report interface on the USB target.   @param  ReportId      The identifier of the report to retrieve.   @param  ReportType    The type of report to retrieve.   @param  ReportLength  The size, in bytes, of Report.   @param  Report        A pointer to the report descriptor buffer to set.    @retval  EFI_SUCCESS       The request executed successfully.   @retval  EFI_TIMEOUT       A timeout occurred executing the request.   @retval  EFI_DEVICE_ERROR  The request failed due to a device error.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|UsbSetReportRequest
parameter_list|(
name|IN
name|EFI_USB_IO_PROTOCOL
modifier|*
name|UsbIo
parameter_list|,
name|IN
name|UINT8
name|Interface
parameter_list|,
name|IN
name|UINT8
name|ReportId
parameter_list|,
name|IN
name|UINT8
name|ReportType
parameter_list|,
name|IN
name|UINT16
name|ReportLen
parameter_list|,
name|IN
name|UINT8
modifier|*
name|Report
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Get the report descriptor of the specified USB HID interface.    Submit a USB get HID report request for the USB device specified by UsbIo,   Interface, ReportId, and ReportType, and return the report in the buffer   specified by Report.   If UsbIo is NULL, then ASSERT().   If Report is NULL, then ASSERT().    @param  UsbIo         A pointer to the USB I/O Protocol instance for the specific USB target.   @param  Interface     The index of the report interface on the USB target.   @param  ReportId      The identifier of the report to retrieve.   @param  ReportType    The type of report to retrieve.   @param  ReportLength  The size, in bytes, of Report.   @param  Report        A pointer to the buffer to store the report descriptor.    @retval  EFI_SUCCESS           The request executed successfully.   @retval  EFI_OUT_OF_RESOURCES  The request could not be completed because the                                  buffer specified by ReportLength and Report is not                                  large enough to hold the result of the request.   @retval  EFI_TIMEOUT           A timeout occurred executing the request.   @retval  EFI_DEVICE_ERROR      The request failed due to a device error.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|UsbGetReportRequest
parameter_list|(
name|IN
name|EFI_USB_IO_PROTOCOL
modifier|*
name|UsbIo
parameter_list|,
name|IN
name|UINT8
name|Interface
parameter_list|,
name|IN
name|UINT8
name|ReportId
parameter_list|,
name|IN
name|UINT8
name|ReportType
parameter_list|,
name|IN
name|UINT16
name|ReportLen
parameter_list|,
name|OUT
name|UINT8
modifier|*
name|Report
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Get the descriptor of the specified USB device.    Submit a USB get descriptor request for the USB device specified by UsbIo, Value,   and Index, and return the descriptor in the buffer specified by Descriptor.   The status of the transfer is returned in Status.   If UsbIo is NULL, then ASSERT().   If Descriptor is NULL, then ASSERT().   If Status is NULL, then ASSERT().    @param  UsbIo             A pointer to the USB I/O Protocol instance for the specific USB target.   @param  Value             The device request value.   @param  Index             The device request index.   @param  DescriptorLength  The size, in bytes, of Descriptor.   @param  Descriptor        A pointer to the descriptor buffer to get.   @param  Status            A pointer to the status of the transfer.    @retval EFI_SUCCESS           The request executed successfully.   @retval EFI_OUT_OF_RESOURCES  The request could not be completed because the                                 buffer specified by DescriptorLength and Descriptor                                 is not large enough to hold the result of the request.   @retval EFI_TIMEOUT           A timeout occurred executing the request.   @retval EFI_DEVICE_ERROR      The request failed due to a device error. The transfer                                 status is returned in Status.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|UsbGetDescriptor
parameter_list|(
name|IN
name|EFI_USB_IO_PROTOCOL
modifier|*
name|UsbIo
parameter_list|,
name|IN
name|UINT16
name|Value
parameter_list|,
name|IN
name|UINT16
name|Index
parameter_list|,
name|IN
name|UINT16
name|DescriptorLength
parameter_list|,
name|OUT
name|VOID
modifier|*
name|Descriptor
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|Status
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Set the descriptor of the specified USB device.    Submit a USB set descriptor request for the USB device specified by UsbIo,   Value, and Index, and set the descriptor using the buffer specified by DesriptorLength   and Descriptor.  The status of the transfer is returned in Status.   If UsbIo is NULL, then ASSERT().   If Descriptor is NULL, then ASSERT().   If Status is NULL, then ASSERT().    @param  UsbIo             A pointer to the USB I/O Protocol instance for the specific USB target.   @param  Value             The device request value.   @param  Index             The device request index.   @param  DescriptorLength  The size, in bytes, of Descriptor.   @param  Descriptor        A pointer to the descriptor buffer to set.   @param  Status            A pointer to the status of the transfer.    @retval  EFI_SUCCESS       The request executed successfully.   @retval  EFI_TIMEOUT       A timeout occurred executing the request.   @retval  EFI_DEVICE_ERROR  The request failed due to a device error.                              The transfer status is returned in Status.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|UsbSetDescriptor
parameter_list|(
name|IN
name|EFI_USB_IO_PROTOCOL
modifier|*
name|UsbIo
parameter_list|,
name|IN
name|UINT16
name|Value
parameter_list|,
name|IN
name|UINT16
name|Index
parameter_list|,
name|IN
name|UINT16
name|DescriptorLength
parameter_list|,
name|IN
name|VOID
modifier|*
name|Descriptor
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|Status
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Get the interface setting of the specified USB device.    Submit a USB get interface request for the USB device specified by UsbIo,   and Interface, and place the result in the buffer specified by AlternateSetting.   The status of the transfer is returned in Status.   If UsbIo is NULL, then ASSERT().   If AlternateSetting is NULL, then ASSERT().   If Status is NULL, then ASSERT().    @param  UsbIo             A pointer to the USB I/O Protocol instance for the specific USB target.   @param  Interface         The interface index value.   @param  AlternateSetting  A pointer to the alternate setting to be retrieved.   @param  Status            A pointer to the status of the transfer.    @retval EFI_SUCCESS       The request executed successfully.   @retval EFI_TIMEOUT       A timeout occurred executing the request.   @retval EFI_DEVICE_ERROR  The request failed due to a device error.                             The transfer status is returned in Status.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|UsbGetInterface
parameter_list|(
name|IN
name|EFI_USB_IO_PROTOCOL
modifier|*
name|UsbIo
parameter_list|,
name|IN
name|UINT16
name|Interface
parameter_list|,
name|OUT
name|UINT16
modifier|*
name|AlternateSetting
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|Status
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Set the interface setting of the specified USB device.    Submit a USB set interface request for the USB device specified by UsbIo, and   Interface, and set the alternate setting to the value specified by AlternateSetting.   The status of the transfer is returned in Status.   If UsbIo is NULL, then ASSERT().   If Status is NULL, then ASSERT().    @param  UsbIo             A pointer to the USB I/O Protocol instance for the specific USB target.   @param  Interface         The interface index value.   @param  AlternateSetting  The alternate setting to be set.   @param  Status            A pointer to the status of the transfer.    @retval EFI_SUCCESS  The request executed successfully.   @retval EFI_TIMEOUT  A timeout occurred executing the request.   @retval EFI_SUCCESS  The request failed due to a device error.                        The transfer status is returned in Status.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|UsbSetInterface
parameter_list|(
name|IN
name|EFI_USB_IO_PROTOCOL
modifier|*
name|UsbIo
parameter_list|,
name|IN
name|UINT16
name|Interface
parameter_list|,
name|IN
name|UINT16
name|AlternateSetting
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|Status
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Get the device configuration.    Submit a USB get configuration request for the USB device specified by UsbIo   and place the result in the buffer specified by ConfigurationValue. The status   of the transfer is returned in Status.   If UsbIo is NULL, then ASSERT().   If ConfigurationValue is NULL, then ASSERT().   If Status is NULL, then ASSERT().    @param  UsbIo               A pointer to the USB I/O Protocol instance for the specific USB target.   @param  ConfigurationValue  A pointer to the device configuration to be retrieved.   @param  Status              A pointer to the status of the transfer.    @retval EFI_SUCCESS        The request executed successfully.   @retval EFI_TIMEOUT        A timeout occurred executing the request.   @retval EFI_DEVICE_ERROR   The request failed due to a device error.                              The transfer status is returned in Status.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|UsbGetConfiguration
parameter_list|(
name|IN
name|EFI_USB_IO_PROTOCOL
modifier|*
name|UsbIo
parameter_list|,
name|OUT
name|UINT16
modifier|*
name|ConfigurationValue
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|Status
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Set the device configuration.    Submit a USB set configuration request for the USB device specified by UsbIo   and set the device configuration to the value specified by ConfigurationValue.   The status of the transfer is returned in Status.   If UsbIo is NULL, then ASSERT().   If Status is NULL, then ASSERT().    @param  UsbIo               A pointer to the USB I/O Protocol instance for the specific USB target.   @param  ConfigurationValue  The device configuration value to be set.   @param  Status              A pointer to the status of the transfer.    @retval EFI_SUCCESS       The request executed successfully.   @retval EFI_TIMEOUT       A timeout occurred executing the request.   @retval EFI_DEVICE_ERROR  The request failed due to a device error.                             The transfer status is returned in Status.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|UsbSetConfiguration
parameter_list|(
name|IN
name|EFI_USB_IO_PROTOCOL
modifier|*
name|UsbIo
parameter_list|,
name|IN
name|UINT16
name|ConfigurationValue
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|Status
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Set the specified feature of the specified device.    Submit a USB set device feature request for the USB device specified by UsbIo,   Recipient, and Target to the value specified by Value.  The status of the   transfer is returned in Status.   If UsbIo is NULL, then ASSERT().   If Status is NULL, then ASSERT().    @param  UsbIo      A pointer to the USB I/O Protocol instance for the specific USB target.   @param  Recipient  The USB data recipient type (i.e. Device, Interface, Endpoint).                      Type USB_TYPES_DEFINITION is defined in the MDE Package Industry                      Standard include file Usb.h.   @param  Value      The value of the feature to be set.   @param  Target     The index of the device to be set.   @param  Status     A pointer to the status of the transfer.    @retval EFI_SUCCESS       The request executed successfully.   @retval EFI_TIMEOUT       A timeout occurred executing the request.   @retval EFI_DEVICE_ERROR  The request failed due to a device error.                             The transfer status is returned in Status.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|UsbSetFeature
parameter_list|(
name|IN
name|EFI_USB_IO_PROTOCOL
modifier|*
name|UsbIo
parameter_list|,
name|IN
name|USB_TYPES_DEFINITION
name|Recipient
parameter_list|,
name|IN
name|UINT16
name|Value
parameter_list|,
name|IN
name|UINT16
name|Target
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|Status
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Clear the specified feature of the specified device.    Submit a USB clear device feature request for the USB device specified by UsbIo,   Recipient, and Target to the value specified by Value.  The status of the transfer   is returned in Status.   If UsbIo is NULL, then ASSERT().   If Status is NULL, then ASSERT().    @param  UsbIo      A pointer to the USB I/O Protocol instance for the specific USB target.   @param  Recipient  The USB data recipient type (i.e. Device, Interface, Endpoint).                      Type USB_TYPES_DEFINITION is defined in the MDE Package Industry Standard                      include file Usb.h.   @param  Value      The value of the feature to be cleared.   @param  Target     The index of the device to be cleared.   @param  Status     A pointer to the status of the transfer.    @retval EFI_SUCCESS       The request executed successfully.   @retval EFI_TIMEOUT       A timeout occurred executing the request.   @retval EFI_DEVICE_ERROR  The request failed due to a device error.                             The transfer status is returned in Status.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|UsbClearFeature
parameter_list|(
name|IN
name|EFI_USB_IO_PROTOCOL
modifier|*
name|UsbIo
parameter_list|,
name|IN
name|USB_TYPES_DEFINITION
name|Recipient
parameter_list|,
name|IN
name|UINT16
name|Value
parameter_list|,
name|IN
name|UINT16
name|Target
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|Status
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Get the status of the specified device.    Submit a USB device get status request for the USB device specified by UsbIo,   Recipient, and Target, and place the result in the buffer specified by DeviceStatus.   The status of the transfer is returned in Status.   If UsbIo is NULL, then ASSERT().   If DeviceStatus is NULL, then ASSERT().   If Status is NULL, then ASSERT().    @param  UsbIo         A pointer to the USB I/O Protocol instance for the specific USB target.   @param  Recipient     The USB data recipient type (i.e. Device, Interface, Endpoint).                         Type USB_TYPES_DEFINITION is defined in the MDE Package Industry Standard                         include file Usb.h.   @param  Target        The index of the device to be get the status of.   @param  DeviceStatus  A pointer to the device status to be retrieved.   @param  Status        A pointer to the status of the transfer.    @retval EFI_SUCCESS       The request executed successfully.   @retval EFI_TIMEOUT       A timeout occurred executing the request.   @retval EFI_DEVICE_ERROR  The request failed due to a device error.                             The transfer status is returned in Status.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|UsbGetStatus
parameter_list|(
name|IN
name|EFI_USB_IO_PROTOCOL
modifier|*
name|UsbIo
parameter_list|,
name|IN
name|USB_TYPES_DEFINITION
name|Recipient
parameter_list|,
name|IN
name|UINT16
name|Target
parameter_list|,
name|OUT
name|UINT16
modifier|*
name|DeviceStatus
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|Status
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Clear halt feature of the specified usb endpoint.    Retrieve the USB endpoint descriptor specified by UsbIo and EndPoint.   If the USB endpoint descriptor can not be retrieved, then return EFI_NOT_FOUND.   If the endpoint descriptor is found, then clear the halt feature of this USB endpoint.   The status of the transfer is returned in Status.   If UsbIo is NULL, then ASSERT().   If Status is NULL, then ASSERT().    @param  UsbIo     A pointer to the USB I/O Protocol instance for the specific USB target.   @param  Endpoint  The endpoint address.   @param  Status    A pointer to the status of the transfer.    @retval EFI_SUCCESS       The request executed successfully.   @retval EFI_TIMEOUT       A timeout occurred executing the request.   @retval EFI_DEVICE_ERROR  The request failed due to a device error.                             The transfer status is returned in Status.   @retval EFI_NOT_FOUND     The specified USB endpoint descriptor can not be found  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|UsbClearEndpointHalt
parameter_list|(
name|IN
name|EFI_USB_IO_PROTOCOL
modifier|*
name|UsbIo
parameter_list|,
name|IN
name|UINT8
name|Endpoint
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|Status
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

