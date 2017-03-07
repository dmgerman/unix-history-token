begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Serial IO protocol as defined in the UEFI 2.0 specification.    Abstraction of a basic serial device. Targeted at 16550 UART, but   could be much more generic.    Copyright (c) 2006 - 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SERIAL_IO_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__SERIAL_IO_PROTOCOL_H__
end_define

begin_define
define|#
directive|define
name|EFI_SERIAL_IO_PROTOCOL_GUID
define|\
value|{ \     0xBB25CF6F, 0xF1D4, 0x11D2, {0x9A, 0x0C, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0xFD } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Protocol GUID defined in EFI1.1.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|SERIAL_IO_PROTOCOL
value|EFI_SERIAL_IO_PROTOCOL_GUID
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_SERIAL_IO_PROTOCOL
name|EFI_SERIAL_IO_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Backward-compatible with EFI1.1.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|EFI_SERIAL_IO_PROTOCOL
name|SERIAL_IO_INTERFACE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Parity type that is computed or checked as each character is transmitted or received. If the
end_comment

begin_comment
comment|/// device does not support parity, the value is the default parity value.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|DefaultParity
block|,
name|NoParity
block|,
name|EvenParity
block|,
name|OddParity
block|,
name|MarkParity
block|,
name|SpaceParity
block|}
name|EFI_PARITY_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Stop bits type
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|DefaultStopBits
block|,
name|OneStopBit
block|,
name|OneFiveStopBits
block|,
name|TwoStopBits
block|}
name|EFI_STOP_BITS_TYPE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// define for Control bits, grouped by read only, write only, and read write
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Read Only
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SERIAL_CLEAR_TO_SEND
value|0x00000010
end_define

begin_define
define|#
directive|define
name|EFI_SERIAL_DATA_SET_READY
value|0x00000020
end_define

begin_define
define|#
directive|define
name|EFI_SERIAL_RING_INDICATE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|EFI_SERIAL_CARRIER_DETECT
value|0x00000080
end_define

begin_define
define|#
directive|define
name|EFI_SERIAL_INPUT_BUFFER_EMPTY
value|0x00000100
end_define

begin_define
define|#
directive|define
name|EFI_SERIAL_OUTPUT_BUFFER_EMPTY
value|0x00000200
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Write Only
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SERIAL_REQUEST_TO_SEND
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EFI_SERIAL_DATA_TERMINAL_READY
value|0x00000001
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Read Write
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SERIAL_HARDWARE_LOOPBACK_ENABLE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|EFI_SERIAL_SOFTWARE_LOOPBACK_ENABLE
value|0x00002000
end_define

begin_define
define|#
directive|define
name|EFI_SERIAL_HARDWARE_FLOW_CONTROL_ENABLE
value|0x00004000
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Serial IO Member Functions
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/**   Reset the serial device.    @param  This              Protocol instance pointer.                                @retval EFI_SUCCESS       The device was reset.   @retval EFI_DEVICE_ERROR  The serial device could not be reset.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SERIAL_RESET
function_decl|)
parameter_list|(
name|IN
name|EFI_SERIAL_IO_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Sets the baud rate, receive FIFO depth, transmit/receice time out, parity,    data bits, and stop bits on a serial device.    @param  This             Protocol instance pointer.   @param  BaudRate         The requested baud rate. A BaudRate value of 0 will use the                            device's default interface speed.   @param  ReveiveFifoDepth The requested depth of the FIFO on the receive side of the                            serial interface. A ReceiveFifoDepth value of 0 will use                            the device's default FIFO depth.   @param  Timeout          The requested time out for a single character in microseconds.                            This timeout applies to both the transmit and receive side of the                            interface. A Timeout value of 0 will use the device's default time                            out value.   @param  Parity           The type of parity to use on this serial device. A Parity value of                            DefaultParity will use the device's default parity value.   @param  DataBits         The number of data bits to use on the serial device. A DataBits                            vaule of 0 will use the device's default data bit setting.   @param  StopBits         The number of stop bits to use on this serial device. A StopBits                            value of DefaultStopBits will use the device's default number of                            stop bits.    @retval EFI_SUCCESS      The device was reset.   @retval EFI_DEVICE_ERROR The serial device could not be reset.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SERIAL_SET_ATTRIBUTES
function_decl|)
parameter_list|(
name|IN
name|EFI_SERIAL_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT64
name|BaudRate
parameter_list|,
name|IN
name|UINT32
name|ReceiveFifoDepth
parameter_list|,
name|IN
name|UINT32
name|Timeout
parameter_list|,
name|IN
name|EFI_PARITY_TYPE
name|Parity
parameter_list|,
name|IN
name|UINT8
name|DataBits
parameter_list|,
name|IN
name|EFI_STOP_BITS_TYPE
name|StopBits
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Set the control bits on a serial device    @param  This             Protocol instance pointer.   @param  Control          Set the bits of Control that are settable.    @retval EFI_SUCCESS      The new control bits were set on the serial device.   @retval EFI_UNSUPPORTED  The serial device does not support this operation.   @retval EFI_DEVICE_ERROR The serial device is not functioning correctly.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SERIAL_SET_CONTROL_BITS
function_decl|)
parameter_list|(
name|IN
name|EFI_SERIAL_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|Control
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Retrieves the status of thecontrol bits on a serial device    @param  This              Protocol instance pointer.   @param  Control           A pointer to return the current Control signals from the serial device.                                @retval EFI_SUCCESS       The control bits were read from the serial device.   @retval EFI_DEVICE_ERROR  The serial device is not functioning correctly.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SERIAL_GET_CONTROL_BITS
function_decl|)
parameter_list|(
name|IN
name|EFI_SERIAL_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|Control
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Writes data to a serial device.    @param  This              Protocol instance pointer.   @param  BufferSize        On input, the size of the Buffer. On output, the amount of                             data actually written.   @param  Buffer            The buffer of data to write    @retval EFI_SUCCESS       The data was written.   @retval EFI_DEVICE_ERROR  The device reported an error.   @retval EFI_TIMEOUT       The data write was stopped due to a timeout.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SERIAL_WRITE
function_decl|)
parameter_list|(
name|IN
name|EFI_SERIAL_IO_PROTOCOL
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
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Writes data to a serial device.    @param  This              Protocol instance pointer.   @param  BufferSize        On input, the size of the Buffer. On output, the amount of                             data returned in Buffer.   @param  Buffer            The buffer to return the data into.    @retval EFI_SUCCESS       The data was read.   @retval EFI_DEVICE_ERROR  The device reported an error.   @retval EFI_TIMEOUT       The data write was stopped due to a timeout.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SERIAL_READ
function_decl|)
parameter_list|(
name|IN
name|EFI_SERIAL_IO_PROTOCOL
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
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   @par Data Structure Description:   The data values in SERIAL_IO_MODE are read-only and are updated by the code    that produces the SERIAL_IO_PROTOCOL member functions.    @param ControlMask   A mask for the Control bits that the device supports. The device   must always support the Input Buffer Empty control bit.      @param TimeOut   If applicable, the number of microseconds to wait before timing out   a Read or Write operation.      @param BaudRate   If applicable, the current baud rate setting of the device; otherwise,   baud rate has the value of zero to indicate that device runs at the   device's designed speed.      @param ReceiveFifoDepth   The number of characters the device will buffer on input      @param DataBits   The number of characters the device will buffer on input      @param Parity   If applicable, this is the EFI_PARITY_TYPE that is computed or    checked as each character is transmitted or reveived. If the device   does not support parity the value is the default parity value.      @param StopBits   If applicable, the EFI_STOP_BITS_TYPE number of stop bits per   character. If the device does not support stop bits the value is   the default stop bit values.  **/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|ControlMask
decl_stmt|;
comment|//
comment|// current Attributes
comment|//
name|UINT32
name|Timeout
decl_stmt|;
name|UINT64
name|BaudRate
decl_stmt|;
name|UINT32
name|ReceiveFifoDepth
decl_stmt|;
name|UINT32
name|DataBits
decl_stmt|;
name|UINT32
name|Parity
decl_stmt|;
name|UINT32
name|StopBits
decl_stmt|;
block|}
name|EFI_SERIAL_IO_MODE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_SERIAL_IO_PROTOCOL_REVISION
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SERIAL_IO_INTERFACE_REVISION
value|EFI_SERIAL_IO_PROTOCOL_REVISION
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The Serial I/O protocol is used to communicate with UART-style serial devices.
end_comment

begin_comment
comment|/// These can be standard UART serial ports in PC-AT systems, serial ports attached
end_comment

begin_comment
comment|/// to a USB interface, or potentially any character-based I/O device.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_SERIAL_IO_PROTOCOL
block|{
comment|///
comment|/// The revision to which the EFI_SERIAL_IO_PROTOCOL adheres. All future revisions
comment|/// must be backwards compatible. If a future version is not backwards compatible,
comment|/// it is not the same GUID.
comment|///
name|UINT32
name|Revision
decl_stmt|;
name|EFI_SERIAL_RESET
name|Reset
decl_stmt|;
name|EFI_SERIAL_SET_ATTRIBUTES
name|SetAttributes
decl_stmt|;
name|EFI_SERIAL_SET_CONTROL_BITS
name|SetControl
decl_stmt|;
name|EFI_SERIAL_GET_CONTROL_BITS
name|GetControl
decl_stmt|;
name|EFI_SERIAL_WRITE
name|Write
decl_stmt|;
name|EFI_SERIAL_READ
name|Read
decl_stmt|;
comment|///
comment|/// Pointer to SERIAL_IO_MODE data.
comment|///
name|EFI_SERIAL_IO_MODE
modifier|*
name|Mode
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSerialIoProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

