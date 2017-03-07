begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This library class provides common serial I/O port functions.  Copyright (c) 2006 - 2015, Intel Corporation. All rights reserved.<BR> Copyright (c) 2012 - 2014, ARM Ltd. All rights reserved. This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SERIAL_PORT_LIB__
end_ifndef

begin_define
define|#
directive|define
name|__SERIAL_PORT_LIB__
end_define

begin_include
include|#
directive|include
file|<Uefi/UefiBaseType.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/SerialIo.h>
end_include

begin_comment
comment|/**   Initialize the serial device hardware.      If no initialization is required, then return RETURN_SUCCESS.   If the serial device was successfully initialized, then return RETURN_SUCCESS.   If the serial device could not be initialized, then return RETURN_DEVICE_ERROR.      @retval RETURN_SUCCESS        The serial device was initialized.   @retval RETURN_DEVICE_ERROR   The serial device could not be initialized.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|SerialPortInitialize
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Write data from buffer to serial device.      Writes NumberOfBytes data bytes from Buffer to the serial device.     The number of bytes actually written to the serial device is returned.   If the return value is less than NumberOfBytes, then the write operation failed.   If Buffer is NULL, then ASSERT().    If NumberOfBytes is zero, then return 0.    @param  Buffer           Pointer to the data buffer to be written.   @param  NumberOfBytes    Number of bytes to written to the serial device.    @retval 0                NumberOfBytes is 0.   @retval>0               The number of bytes written to the serial device.                              If this value is less than NumberOfBytes, then the write operation failed.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|SerialPortWrite
parameter_list|(
name|IN
name|UINT8
modifier|*
name|Buffer
parameter_list|,
name|IN
name|UINTN
name|NumberOfBytes
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Read data from serial device and save the datas in buffer.     Reads NumberOfBytes data bytes from a serial device into the buffer   specified by Buffer. The number of bytes actually read is returned.    If the return value is less than NumberOfBytes, then the rest operation failed.   If Buffer is NULL, then ASSERT().    If NumberOfBytes is zero, then return 0.    @param  Buffer           Pointer to the data buffer to store the data read from the serial device.   @param  NumberOfBytes    Number of bytes which will be read.    @retval 0                Read data failed, no data is to be read.   @retval>0               Actual number of bytes read from serial device.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|SerialPortRead
parameter_list|(
name|OUT
name|UINT8
modifier|*
name|Buffer
parameter_list|,
name|IN
name|UINTN
name|NumberOfBytes
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Polls a serial device to see if there is any data waiting to be read.    Polls a serial device to see if there is any data waiting to be read.   If there is data waiting to be read from the serial device, then TRUE is returned.   If there is no data waiting to be read from the serial device, then FALSE is returned.    @retval TRUE             Data is waiting to be read from the serial device.   @retval FALSE            There is no data waiting to be read from the serial device.  **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|SerialPortPoll
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Sets the control bits on a serial device.    @param Control                Sets the bits of Control that are settable.    @retval RETURN_SUCCESS        The new control bits were set on the serial device.   @retval RETURN_UNSUPPORTED    The serial device does not support this operation.   @retval RETURN_DEVICE_ERROR   The serial device is not functioning correctly.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|SerialPortSetControl
parameter_list|(
name|IN
name|UINT32
name|Control
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Retrieve the status of the control bits on a serial device.    @param Control                A pointer to return the current control signals from the serial device.    @retval RETURN_SUCCESS        The control bits were read from the serial device.   @retval RETURN_UNSUPPORTED    The serial device does not support this operation.   @retval RETURN_DEVICE_ERROR   The serial device is not functioning correctly.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|SerialPortGetControl
parameter_list|(
name|OUT
name|UINT32
modifier|*
name|Control
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Sets the baud rate, receive FIFO depth, transmit/receice time out, parity,   data bits, and stop bits on a serial device.    @param BaudRate           The requested baud rate. A BaudRate value of 0 will use the                             device's default interface speed.                             On output, the value actually set.   @param ReveiveFifoDepth   The requested depth of the FIFO on the receive side of the                             serial interface. A ReceiveFifoDepth value of 0 will use                             the device's default FIFO depth.                             On output, the value actually set.   @param Timeout            The requested time out for a single character in microseconds.                             This timeout applies to both the transmit and receive side of the                             interface. A Timeout value of 0 will use the device's default time                             out value.                             On output, the value actually set.   @param Parity             The type of parity to use on this serial device. A Parity value of                             DefaultParity will use the device's default parity value.                             On output, the value actually set.   @param DataBits           The number of data bits to use on the serial device. A DataBits                             vaule of 0 will use the device's default data bit setting.                             On output, the value actually set.   @param StopBits           The number of stop bits to use on this serial device. A StopBits                             value of DefaultStopBits will use the device's default number of                             stop bits.                             On output, the value actually set.    @retval RETURN_SUCCESS            The new attributes were set on the serial device.   @retval RETURN_UNSUPPORTED        The serial device does not support this operation.   @retval RETURN_INVALID_PARAMETER  One or more of the attributes has an unsupported value.   @retval RETURN_DEVICE_ERROR       The serial device is not functioning correctly.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|SerialPortSetAttributes
parameter_list|(
name|IN
name|OUT
name|UINT64
modifier|*
name|BaudRate
parameter_list|,
name|IN
name|OUT
name|UINT32
modifier|*
name|ReceiveFifoDepth
parameter_list|,
name|IN
name|OUT
name|UINT32
modifier|*
name|Timeout
parameter_list|,
name|IN
name|OUT
name|EFI_PARITY_TYPE
modifier|*
name|Parity
parameter_list|,
name|IN
name|OUT
name|UINT8
modifier|*
name|DataBits
parameter_list|,
name|IN
name|OUT
name|EFI_STOP_BITS_TYPE
modifier|*
name|StopBits
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

