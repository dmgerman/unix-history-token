begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Include file matches things in PI.  Copyright (c) 2013, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                              THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   PI Version 1.3  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PI_I2C_H__
end_ifndef

begin_define
define|#
directive|define
name|__PI_I2C_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// A 10-bit slave address is or'ed with the following value enabling the
end_comment

begin_comment
comment|/// I2C protocol stack to address the duplicated address space between 0
end_comment

begin_comment
comment|//  and 127 in 10-bit mode.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|I2C_ADDRESSING_10_BIT
value|0x80000000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// I2C controller capabilities
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_I2C_CONTROLLER_CAPABILITIES specifies the capabilities of the
end_comment

begin_comment
comment|/// I2C host controller.  The StructureSizeInBytes enables variations of
end_comment

begin_comment
comment|/// this structure to be identified if there is need to extend this
end_comment

begin_comment
comment|/// structure in the future.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Length of this data structure in bytes
comment|///
name|UINT32
name|StructureSizeInBytes
decl_stmt|;
comment|///
comment|/// The maximum number of bytes the I2C host controller is able to
comment|/// receive from the I2C bus.
comment|///
name|UINT32
name|MaximumReceiveBytes
decl_stmt|;
comment|///
comment|/// The maximum number of bytes the I2C host controller is able to send
comment|/// on the I2C  bus.
comment|///
name|UINT32
name|MaximumTransmitBytes
decl_stmt|;
comment|///
comment|/// The maximum number of bytes in the I2C bus transaction.
comment|///
name|UINT32
name|MaximumTotalBytes
decl_stmt|;
block|}
name|EFI_I2C_CONTROLLER_CAPABILITIES
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// I2C device description
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_I2C_ENUMERATE_PROTOCOL uses the EFI_I2C_DEVICE to describe
end_comment

begin_comment
comment|/// the platform specific details associated with an I2C device.  This
end_comment

begin_comment
comment|/// description is passed to the I2C bus driver during enumeration where
end_comment

begin_comment
comment|/// it is made available to the third party I2C device driver via the
end_comment

begin_comment
comment|/// EFI_I2C_IO_PROTOCOL.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
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
comment|/// Hardware revision - ACPI _HRV value.  See the Advanced
comment|/// Configuration and Power Interface Specification, Revision 5.0
comment|/// for the field format and the Plug and play support for I2C
comment|/// web-page for restriction on values.
comment|///
comment|/// http://www.acpi.info/spec.htm
comment|/// http://msdn.microsoft.com/en-us/library/windows/hardware/jj131711(v=vs.85).aspx
comment|///
name|UINT32
name|HardwareRevision
decl_stmt|;
comment|///
comment|/// I2C bus configuration for the I2C device
comment|///
name|UINT32
name|I2cBusConfiguration
decl_stmt|;
comment|///
comment|/// Number of slave addresses for the I2C device.
comment|///
name|UINT32
name|SlaveAddressCount
decl_stmt|;
comment|///
comment|/// Pointer to the array of slave addresses for the I2C device.
comment|///
name|CONST
name|UINT32
modifier|*
name|SlaveAddressArray
decl_stmt|;
block|}
name|EFI_I2C_DEVICE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Define the I2C flags
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// I2C read operation when set
end_comment

begin_define
define|#
directive|define
name|I2C_FLAG_READ
value|0x00000001
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Define the flags for SMBus operation
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The following flags are also present in only the first I2C operation
end_comment

begin_comment
comment|/// and are ignored when present in other operations.  These flags
end_comment

begin_comment
comment|/// describe a particular SMB transaction as shown in the following table.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// SMBus operation
end_comment

begin_define
define|#
directive|define
name|I2C_FLAG_SMBUS_OPERATION
value|0x00010000
end_define

begin_comment
comment|/// SMBus block operation
end_comment

begin_comment
comment|///   The flag I2C_FLAG_SMBUS_BLOCK causes the I2C master protocol to update
end_comment

begin_comment
comment|///   the LengthInBytes field of the operation in the request packet with
end_comment

begin_comment
comment|///   the actual number of bytes read or written.  These values are only
end_comment

begin_comment
comment|///   valid when the entire I2C transaction is successful.
end_comment

begin_comment
comment|///   This flag also changes the LengthInBytes meaning to be: A maximum
end_comment

begin_comment
comment|///   of LengthInBytes is to be read from the device.  The first byte
end_comment

begin_comment
comment|///   read contains the number of bytes remaining to be read, plus an
end_comment

begin_comment
comment|///   optional PEC value.
end_comment

begin_define
define|#
directive|define
name|I2C_FLAG_SMBUS_BLOCK
value|0x00020000
end_define

begin_comment
comment|/// SMBus process call operation
end_comment

begin_define
define|#
directive|define
name|I2C_FLAG_SMBUS_PROCESS_CALL
value|0x00040000
end_define

begin_comment
comment|/// SMBus use packet error code (PEC)
end_comment

begin_comment
comment|///   Note that the I2C master protocol may clear the I2C_FLAG_SMBUS_PEC bit
end_comment

begin_comment
comment|///   to indicate that the PEC value was checked by the hardware and is
end_comment

begin_comment
comment|///   not appended to the returned read data.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|I2C_FLAG_SMBUS_PEC
value|0x00080000
end_define

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// QuickRead:          OperationCount=1,
end_comment

begin_comment
comment|///                     LengthInBytes=0,   Flags=I2C_FLAG_READ
end_comment

begin_comment
comment|/// QuickWrite:         OperationCount=1,
end_comment

begin_comment
comment|///                     LengthInBytes=0,   Flags=0
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// ReceiveByte:        OperationCount=1,
end_comment

begin_comment
comment|///                     LengthInBytes=1,   Flags=I2C_FLAG_SMBUS_OPERATION
end_comment

begin_comment
comment|///                                            | I2C_FLAG_READ
end_comment

begin_comment
comment|/// ReceiveByte+PEC:    OperationCount=1,
end_comment

begin_comment
comment|///                     LengthInBytes=2,   Flags=I2C_FLAG_SMBUS_OPERATION
end_comment

begin_comment
comment|///                                            | I2C_FLAG_READ
end_comment

begin_comment
comment|///                                            | I2C_FLAG_SMBUS_PEC
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// SendByte:           OperationCount=1,
end_comment

begin_comment
comment|///                     LengthInBytes=1,   Flags=I2C_FLAG_SMBUS_OPERATION
end_comment

begin_comment
comment|/// SendByte+PEC:       OperationCount=1,
end_comment

begin_comment
comment|///                     LengthInBytes=2,   Flags=I2C_FLAG_SMBUS_OPERATION
end_comment

begin_comment
comment|///                                            | I2C_FLAG_SMBUS_PEC
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// ReadDataByte:       OperationCount=2,
end_comment

begin_comment
comment|///                     LengthInBytes=1,   Flags=I2C_FLAG_SMBUS_OPERATION
end_comment

begin_comment
comment|///                     LengthInBytes=1,   Flags=I2C_FLAG_READ
end_comment

begin_comment
comment|/// ReadDataByte+PEC:   OperationCount=2,
end_comment

begin_comment
comment|///                     LengthInBytes=1,   Flags=I2C_FLAG_SMBUS_OPERATION
end_comment

begin_comment
comment|///                                            | I2C_FLAG_SMBUS_PEC
end_comment

begin_comment
comment|///                     LengthInBytes=2,   Flags=I2C_FLAG_READ
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// WriteDataByte:      OperationCount=1,
end_comment

begin_comment
comment|///                     LengthInBytes=2,   Flags=I2C_FLAG_SMBUS_OPERATION
end_comment

begin_comment
comment|/// WriteDataByte+PEC:  OperationCount=1,
end_comment

begin_comment
comment|///                     LengthInBytes=3,   Flags=I2C_FLAG_SMBUS_OPERATION
end_comment

begin_comment
comment|///                                            | I2C_FLAG_SMBUS_PEC
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// ReadDataWord:       OperationCount=2,
end_comment

begin_comment
comment|///                     LengthInBytes=1,   Flags=I2C_FLAG_SMBUS_OPERATION
end_comment

begin_comment
comment|///                     LengthInBytes=2,   Flags=I2C_FLAG_READ
end_comment

begin_comment
comment|/// ReadDataWord+PEC:   OperationCount=2,
end_comment

begin_comment
comment|///                     LengthInBytes=1,   Flags=I2C_FLAG_SMBUS_OPERATION
end_comment

begin_comment
comment|///                                            | I2C_FLAG_SMBUS_PEC
end_comment

begin_comment
comment|///                     LengthInBytes=3,   Flags=I2C_FLAG_READ
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// WriteDataWord:      OperationCount=1,
end_comment

begin_comment
comment|///                     LengthInBytes=3,   Flags=I2C_FLAG_SMBUS_OPERATION
end_comment

begin_comment
comment|/// WriteDataWord+PEC:  OperationCount=1,
end_comment

begin_comment
comment|///                     LengthInBytes=4,   Flags=I2C_FLAG_SMBUS_OPERATION
end_comment

begin_comment
comment|///                                            | I2C_FLAG_SMBUS_PEC
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// ReadBlock:          OperationCount=2,
end_comment

begin_comment
comment|///                     LengthInBytes=1,   Flags=I2C_FLAG_SMBUS_OPERATION
end_comment

begin_comment
comment|///                                            | I2C_FLAG_SMBUS_BLOCK
end_comment

begin_comment
comment|///                     LengthInBytes=33,  Flags=I2C_FLAG_READ
end_comment

begin_comment
comment|/// ReadBlock+PEC:      OperationCount=2,
end_comment

begin_comment
comment|///                     LengthInBytes=1,   Flags=I2C_FLAG_SMBUS_OPERATION
end_comment

begin_comment
comment|///                                            | I2C_FLAG_SMBUS_BLOCK
end_comment

begin_comment
comment|///                                            | I2C_FLAG_SMBUS_PEC
end_comment

begin_comment
comment|///                     LengthInBytes=34,  Flags=I2C_FLAG_READ
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// WriteBlock:         OperationCount=1,
end_comment

begin_comment
comment|///                     LengthInBytes=N+2, Flags=I2C_FLAG_SMBUS_OPERATION
end_comment

begin_comment
comment|///                                            | I2C_FLAG_SMBUS_BLOCK
end_comment

begin_comment
comment|/// WriteBlock+PEC:     OperationCount=1,
end_comment

begin_comment
comment|///                     LengthInBytes=N+3, Flags=I2C_FLAG_SMBUS_OPERATION
end_comment

begin_comment
comment|///                                            | I2C_FLAG_SMBUS_BLOCK
end_comment

begin_comment
comment|///                                            | I2C_FLAG_SMBUS_PEC
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// ProcessCall:        OperationCount=2,
end_comment

begin_comment
comment|///                     LengthInBytes=3,   Flags=I2C_FLAG_SMBUS_OPERATION
end_comment

begin_comment
comment|///                                            | I2C_FLAG_SMBUS_PROCESS_CALL
end_comment

begin_comment
comment|///                     LengthInBytes=2,   Flags=I2C_FLAG_READ
end_comment

begin_comment
comment|/// ProcessCall+PEC:    OperationCount=2,
end_comment

begin_comment
comment|///                     LengthInBytes=3,   Flags=I2C_FLAG_SMBUS_OPERATION
end_comment

begin_comment
comment|///                                            | I2C_FLAG_SMBUS_PROCESS_CALL
end_comment

begin_comment
comment|///                                            | I2C_FLAG_SMBUS_PEC
end_comment

begin_comment
comment|///                     LengthInBytes=3,   Flags=I2C_FLAG_READ
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// BlkProcessCall:     OperationCount=2,
end_comment

begin_comment
comment|///                     LengthInBytes=N+2, Flags=I2C_FLAG_SMBUS_OPERATION
end_comment

begin_comment
comment|///                                            | I2C_FLAG_SMBUS_PROCESS_CALL
end_comment

begin_comment
comment|///                                            | I2C_FLAG_SMBUS_BLOCK
end_comment

begin_comment
comment|///                     LengthInBytes=33,  Flags=I2C_FLAG_READ
end_comment

begin_comment
comment|/// BlkProcessCall+PEC: OperationCount=2,
end_comment

begin_comment
comment|///                     LengthInBytes=N+2, Flags=I2C_FLAG_SMBUS_OPERATION
end_comment

begin_comment
comment|///                                            | I2C_FLAG_SMBUS_PROCESS_CALL
end_comment

begin_comment
comment|///                                            | I2C_FLAG_SMBUS_BLOCK
end_comment

begin_comment
comment|///                                            | I2C_FLAG_SMBUS_PEC
end_comment

begin_comment
comment|///                     LengthInBytes=34,  Flags=I2C_FLAG_READ
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// I2C device operation
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_I2C_OPERATION describes a subset of an I2C transaction in which
end_comment

begin_comment
comment|/// the I2C controller is either sending or receiving bytes from the bus.
end_comment

begin_comment
comment|/// Some transactions will consist of a single operation while others will
end_comment

begin_comment
comment|/// be two or more.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note: Some I2C controllers do not support read or write ping (address
end_comment

begin_comment
comment|/// only) operation and will return EFI_UNSUPPORTED status when these
end_comment

begin_comment
comment|/// operations are requested.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note: I2C controllers which do not support complex transactions requiring
end_comment

begin_comment
comment|/// multiple repeated start bits return EFI_UNSUPPORTED without processing
end_comment

begin_comment
comment|/// any of the transaction.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Flags to qualify the I2C operation.
comment|///
name|UINT32
name|Flags
decl_stmt|;
comment|///
comment|/// Number of bytes to send to or receive from the I2C device.  A ping
comment|/// (address only byte/bytes)  is indicated by setting the LengthInBytes
comment|/// to zero.
comment|///
name|UINT32
name|LengthInBytes
decl_stmt|;
comment|///
comment|/// Pointer to a buffer containing the data to send or to receive from
comment|/// the I2C device.  The Buffer must be at least LengthInBytes in size.
comment|///
name|UINT8
modifier|*
name|Buffer
decl_stmt|;
block|}
name|EFI_I2C_OPERATION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// I2C device request
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_I2C_REQUEST_PACKET describes a single I2C transaction.  The
end_comment

begin_comment
comment|/// transaction starts with a start bit followed by the first operation
end_comment

begin_comment
comment|/// in the operation array.  Subsequent operations are separated with
end_comment

begin_comment
comment|/// repeated start bits and the last operation is followed by a stop bit
end_comment

begin_comment
comment|/// which concludes the transaction.  Each operation is described by one
end_comment

begin_comment
comment|/// of the elements in the Operation array.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Number of elements in the operation array
comment|///
name|UINTN
name|OperationCount
decl_stmt|;
comment|///
comment|/// Description of the I2C operation
comment|///
name|EFI_I2C_OPERATION
name|Operation
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_I2C_REQUEST_PACKET
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//  __PI_I2C_H__
end_comment

end_unit

