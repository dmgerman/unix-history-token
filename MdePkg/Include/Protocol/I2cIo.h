begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   I2C I/O Protocol as defined in the PI 1.3 specification.    The EFI I2C I/O protocol enables the user to manipulate a single    I2C device independent of the host controller and I2C design.    Copyright (c) 2013 - 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   This protocol is from PI Version 1.3.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__I2C_IO_H__
end_ifndef

begin_define
define|#
directive|define
name|__I2C_IO_H__
end_define

begin_include
include|#
directive|include
file|<Pi/PiI2c.h>
end_include

begin_define
define|#
directive|define
name|EFI_I2C_IO_PROTOCOL_GUID
value|{ 0xb60a3e6b, 0x18c4, 0x46e5, { 0xa2, 0x9a, 0xc9, 0xa1, 0x06, 0x65, 0xa2, 0x8e }}
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// I2C I/O protocol
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The I2C IO protocol enables access to a specific device on the I2C
end_comment

begin_comment
comment|/// bus.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Each I2C device is identified uniquely in the system by the tuple
end_comment

begin_comment
comment|/// DeviceGuid:DeviceIndex.  The DeviceGuid represents the manufacture
end_comment

begin_comment
comment|/// and part number and is provided by the silicon vendor or the third
end_comment

begin_comment
comment|/// party I2C device driver writer.  The DeviceIndex identifies the part
end_comment

begin_comment
comment|/// within the system by using a unique number and is created by the
end_comment

begin_comment
comment|/// board designer or the writer of the EFI_I2C_ENUMERATE_PROTOCOL.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// I2C slave addressing is abstracted to validate addresses and limit
end_comment

begin_comment
comment|/// operation to the specified I2C device.  The third party providing
end_comment

begin_comment
comment|/// the I2C device support provides an ordered list of slave addresses
end_comment

begin_comment
comment|/// for the I2C device required to implement the EFI_I2C_ENUMERATE_PROTOCOL.
end_comment

begin_comment
comment|/// The order of the list must be preserved.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|struct
name|_EFI_I2C_IO_PROTOCOL
name|EFI_I2C_IO_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Queue an I2C transaction for execution on the I2C device.    This routine must be called at or below TPL_NOTIFY.  For synchronous   requests this routine must be called at or below TPL_CALLBACK.    This routine queues an I2C transaction to the I2C controller for   execution on the I2C bus.    When Event is NULL, QueueRequest() operates synchronously and returns   the I2C completion status as its return value.    When Event is not NULL, QueueRequest() synchronously returns EFI_SUCCESS   indicating that the asynchronous I2C transaction was queued.  The values   above are returned in the buffer pointed to by I2cStatus upon the   completion of the I2C transaction when I2cStatus is not NULL.    The upper layer driver writer provides the following to the platform   vendor:      1.  Vendor specific GUID for the I2C part   2.  Guidance on proper construction of the slave address array when the       I2C device uses more than one slave address.  The I2C bus protocol       uses the SlaveAddressIndex to perform relative to physical address       translation to access the blocks of hardware within the I2C device.    @param[in] This               Pointer to an EFI_I2C_IO_PROTOCOL structure.   @param[in] SlaveAddressIndex  Index value into an array of slave addresses                                 for the I2C device.  The values in the array                                 are specified by the board designer, with the                                 third party I2C device driver writer providing                                 the slave address order.                                  For devices that have a single slave address,                                 this value must be zero.  If the I2C device                                 uses more than one slave address then the                                 third party (upper level) I2C driver writer                                 needs to specify the order of entries in the                                 slave address array.                                  \ref ThirdPartyI2cDrivers "Third Party I2C                                 Drivers" section in I2cMaster.h.   @param[in] Event              Event to signal for asynchronous transactions,                                 NULL for synchronous transactions   @param[in] RequestPacket      Pointer to an EFI_I2C_REQUEST_PACKET structure                                 describing the I2C transaction   @param[out] I2cStatus         Optional buffer to receive the I2C transaction                                 completion status    @retval EFI_SUCCESS           The asynchronous transaction was successfully                                 queued when Event is not NULL.   @retval EFI_SUCCESS           The transaction completed successfully when                                 Event is NULL.   @retval EFI_BAD_BUFFER_SIZE   The RequestPacket->LengthInBytes value is too                                 large.   @retval EFI_DEVICE_ERROR      There was an I2C error (NACK) during the                                 transaction.   @retval EFI_INVALID_PARAMETER RequestPacket is NULL.   @retval EFI_NO_MAPPING        The EFI_I2C_HOST_PROTOCOL could not set the                                 bus configuration required to access this I2C                                 device.   @retval EFI_NO_RESPONSE       The I2C device is not responding to the slave                                 address selected by SlaveAddressIndex.                                 EFI_DEVICE_ERROR will be returned if the                                 controller cannot distinguish when the NACK                                 occurred.   @retval EFI_OUT_OF_RESOURCES  Insufficient memory for I2C transaction   @retval EFI_UNSUPPORTED       The controller does not support the requested                                 transaction.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_I2C_IO_PROTOCOL_QUEUE_REQUEST
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_I2C_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINTN
name|SlaveAddressIndex
parameter_list|,
name|IN
name|EFI_EVENT
name|Event
name|OPTIONAL
parameter_list|,
name|IN
name|EFI_I2C_REQUEST_PACKET
modifier|*
name|RequestPacket
parameter_list|,
name|OUT
name|EFI_STATUS
modifier|*
name|I2cStatus
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// I2C I/O protocol
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_I2C_IO_PROTOCOL
block|{
comment|///
comment|/// Queue an I2C transaction for execution on the I2C device.
comment|///
name|EFI_I2C_IO_PROTOCOL_QUEUE_REQUEST
name|QueueRequest
decl_stmt|;
comment|///
comment|/// Unique value assigned by the silicon manufacture or the third
comment|/// party I2C driver writer for the I2C part.  This value logically
comment|/// combines both the manufacture name and the I2C part number into
comment|/// a single value specified as a GUID.
comment|///
name|CONST
name|EFI_GUID
modifier|*
name|DeviceGuid
decl_stmt|;
comment|///
comment|/// Unique ID of the I2C part within the system
comment|///
name|UINT32
name|DeviceIndex
decl_stmt|;
comment|///
comment|/// Hardware revision - ACPI _HRV value.  See the Advanced Configuration
comment|/// and Power Interface Specification, Revision 5.0  for the field format
comment|/// and the Plug and play support for I2C web-page for restriction on values.
comment|///
name|UINT32
name|HardwareRevision
decl_stmt|;
comment|///
comment|/// Pointer to an EFI_I2C_CONTROLLER_CAPABILITIES data structure containing
comment|/// the capabilities of the I2C host controller.
comment|///
name|CONST
name|EFI_I2C_CONTROLLER_CAPABILITIES
modifier|*
name|I2cControllerCapabilities
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|///
end_comment

begin_comment
comment|/// Reference to variable defined in the .DEC file
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiI2cIoProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//  __I2C_IO_H__
end_comment

end_unit

