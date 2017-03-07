begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file declares Smbus2 PPI.   This PPI provides the basic I/O interfaces that a PEIM uses to access its    SMBus controller and the slave devices attached to it.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   This PPI is introduced in PI Version 1.0.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PEI_SMBUS2_PPI_H__
end_ifndef

begin_define
define|#
directive|define
name|__PEI_SMBUS2_PPI_H__
end_define

begin_include
include|#
directive|include
file|<IndustryStandard/SmBus.h>
end_include

begin_define
define|#
directive|define
name|EFI_PEI_SMBUS2_PPI_GUID
define|\
value|{ 0x9ca93627, 0xb65b, 0x4324, { 0xa2, 0x2, 0xc0, 0xb4, 0x61, 0x76, 0x45, 0x43 } }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_PEI_SMBUS2_PPI
name|EFI_PEI_SMBUS2_PPI
typedef|;
end_typedef

begin_comment
comment|/**   Executes an SMBus operation to an SMBus controller. Returns when either    the command has been executed or an error is encountered in doing the operation.    @param  This            A pointer to the EFI_PEI_SMBUS2_PPI instance.   @param  SlaveAddress    The SMBUS hardware address to which the SMBUS device is preassigned or                           allocated.   @param  Command         This command is transmitted by the SMBus host controller to the SMBus slave                            device and the interpretation is SMBus slave device specific.                            It can mean the offset to a list of functions inside                            an SMBus slave device. Not all operations or slave devices support                           this command's registers.   @param  Operation       Signifies which particular SMBus hardware protocol instance that it                            will use to execute the SMBus transactions.                            This SMBus hardware protocol is defined by the System Management Bus (SMBus)                            Specification and is not related to UEFI.   @param  PecCheck        Defines if Packet Error Code (PEC) checking is required for this operation.   @param  Length          Signifies the number of bytes that this operation will do.                            The maximum number of bytes can be revision specific and operation specific.                           This parameter will contain the actual number of bytes that are executed                           for this operation. Not all operations require this argument.   @param  Buffer          Contains the value of data to execute to the SMBus slave device.                            Not all operations require this argument.                            The length of this buffer is identified by Length.     @retval EFI_SUCCESS           The last data that was returned from the access                                 matched the poll exit criteria.   @retval EFI_CRC_ERROR         The checksum is not correct (PEC is incorrect)   @retval EFI_TIMEOUT           Timeout expired before the operation was completed.                                 Timeout is determined by the SMBus host controller device.   @retval EFI_OUT_OF_RESOURCES  The request could not be completed                                 due to a lack of resources.   @retval EFI_DEVICE_ERROR      The request was not completed because                                 a failure reflected in the Host Status Register bit.   @retval EFI_INVALID_PARAMETER Operation is not defined in EFI_SMBUS_OPERATION.                                 Or Length/Buffer is NULL for operations except for EfiSmbusQuickRead and                                 EfiSmbusQuickWrite. Or Length is outside the range of valid values.   @retval EFI_UNSUPPORTED       The SMBus operation or PEC is not supported.   @retval EFI_BUFFER_TOO_SMALL  Buffer is not sufficient for this operation.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_SMBUS2_PPI_EXECUTE_OPERATION
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_SMBUS2_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_SMBUS_DEVICE_ADDRESS
name|SlaveAddress
parameter_list|,
name|IN
name|EFI_SMBUS_DEVICE_COMMAND
name|Command
parameter_list|,
name|IN
name|EFI_SMBUS_OPERATION
name|Operation
parameter_list|,
name|IN
name|BOOLEAN
name|PecCheck
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|Length
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
comment|/**   The ArpDevice() function enumerates the entire bus or enumerates a specific    device that is identified by SmbusUdid.     @param  This           A pointer to the EFI_PEI_SMBUS2_PPI instance.   @param  ArpAll         A Boolean expression that indicates if the host drivers need                          to enumerate all the devices or enumerate only the device that is identified                          by SmbusUdid. If ArpAll is TRUE, SmbusUdid and SlaveAddress are optional.                          If ArpAll is FALSE, ArpDevice will enumerate SmbusUdid and the address                          will be at SlaveAddress.   @param  SmbusUdid      The targeted SMBus Unique Device Identifier (UDID).                          The UDID may not exist for SMBus devices with fixed addresses.   @param  SlaveAddress   The new SMBus address for the slave device for                          which the operation is targeted.    @retval EFI_SUCCESS           The SMBus slave device address was set.   @retval EFI_INVALID_PARAMETER SlaveAddress is NULL.   @retval EFI_OUT_OF_RESOURCES  The request could not be completed                                 due to a lack of resources.   @retval EFI_TIMEOUT           The SMBus slave device did not respond.   @retval EFI_DEVICE_ERROR      The request was not completed because the transaction failed.   @retval EFI_UNSUPPORTED       ArpDevice, GetArpMap, and Notify are not implemented by this PEIM.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_SMBUS2_PPI_ARP_DEVICE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_SMBUS2_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|ArpAll
parameter_list|,
name|IN
name|EFI_SMBUS_UDID
modifier|*
name|SmbusUdid
parameter_list|,
name|OPTIONAL
name|IN
name|OUT
name|EFI_SMBUS_DEVICE_ADDRESS
modifier|*
name|SlaveAddress
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   The GetArpMap() function returns the mapping of all the SMBus devices    that are enumerated by the SMBus host driver.     @param  This           A pointer to the EFI_PEI_SMBUS2_PPI instance.   @param  Length         Size of the buffer that contains the SMBus device map.   @param  SmbusDeviceMap The pointer to the device map as enumerated                          by the SMBus controller driver.    @retval EFI_SUCCESS           The device map was returned correctly in the buffer.   @retval EFI_UNSUPPORTED       ArpDevice, GetArpMap, and Notify are not implemented by this PEIM.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_SMBUS2_PPI_GET_ARP_MAP
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_SMBUS2_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|Length
parameter_list|,
name|IN
name|OUT
name|EFI_SMBUS_DEVICE_MAP
modifier|*
modifier|*
name|SmbusDeviceMap
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   CallBack function can be registered in EFI_PEI_SMBUS2_PPI_NOTIFY.    @param  This           A pointer to the EFI_PEI_SMBUS2_PPI instance.   @param  SlaveAddress   The SMBUS hardware address to which the SMBUS                          device is preassigned or allocated.   @param  Data           Data of the SMBus host notify command that                          the caller wants to be called.    @retval EFI_SUCCESS           NotifyFunction has been registered.   @retval EFI_UNSUPPORTED       ArpDevice, GetArpMap, and Notify are not                                 implemented by this PEIM.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_SMBUS_NOTIFY2_FUNCTION
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_SMBUS2_PPI
modifier|*
name|SmbusPpi
parameter_list|,
name|IN
name|EFI_SMBUS_DEVICE_ADDRESS
name|SlaveAddress
parameter_list|,
name|IN
name|UINTN
name|Data
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   The Notify() function registers all the callback functions to allow the    bus driver to call these functions when the SlaveAddress/Data pair happens.    @param  This           A pointer to the EFI_PEI_SMBUS2_PPI instance.   @param  SlaveAddress   Address that the host controller detects as                          sending a message and calls all the registered functions.   @param  Data           Data that the host controller detects as sending a message                          and calls all the registered functions.   @param  NotifyFunction The function to call when the bus driver                          detects the SlaveAddress and Data pair.    @retval EFI_SUCCESS     NotifyFunction has been registered.   @retval EFI_UNSUPPORTED ArpDevice, GetArpMap, and Notify are not                           implemented by this PEIM. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_SMBUS2_PPI_NOTIFY
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_SMBUS2_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_SMBUS_DEVICE_ADDRESS
name|SlaveAddress
parameter_list|,
name|IN
name|UINTN
name|Data
parameter_list|,
name|IN
name|EFI_PEI_SMBUS_NOTIFY2_FUNCTION
name|NotifyFunction
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|///  Provides the basic I/O interfaces that a PEIM uses to access
end_comment

begin_comment
comment|///  its SMBus controller and the slave devices attached to it.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_PEI_SMBUS2_PPI
block|{
name|EFI_PEI_SMBUS2_PPI_EXECUTE_OPERATION
name|Execute
decl_stmt|;
name|EFI_PEI_SMBUS2_PPI_ARP_DEVICE
name|ArpDevice
decl_stmt|;
name|EFI_PEI_SMBUS2_PPI_GET_ARP_MAP
name|GetArpMap
decl_stmt|;
name|EFI_PEI_SMBUS2_PPI_NOTIFY
name|Notify
decl_stmt|;
comment|///
comment|/// Identifier which uniquely identifies this SMBus controller in a system.
comment|///
name|EFI_GUID
name|Identifier
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPeiSmbus2PpiGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

