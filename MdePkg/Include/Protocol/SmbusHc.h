begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   The file provides basic SMBus host controller management    and basic data transactions over the SMBus.    Copyright (c) 2006 - 2011, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference: PI   Version 1.00.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SMBUS_HC_H__
end_ifndef

begin_define
define|#
directive|define
name|__SMBUS_HC_H__
end_define

begin_include
include|#
directive|include
file|<IndustryStandard/SmBus.h>
end_include

begin_define
define|#
directive|define
name|EFI_SMBUS_HC_PROTOCOL_GUID
define|\
value|{0xe49d33ed, 0x513d, 0x4634, { 0xb6, 0x98, 0x6f, 0x55, 0xaa, 0x75, 0x1c, 0x1b} }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_SMBUS_HC_PROTOCOL
name|EFI_SMBUS_HC_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**         The Execute() function provides a standard way to execute an   operation as defined in the System Management Bus (SMBus)   Specification. The resulting transaction will be either that   the SMBus slave devices accept this transaction or that this   function returns with error.       @param This     A pointer to the EFI_SMBUS_HC_PROTOCOL instance.                   SlaveAddress The SMBus slave address of the device                   with which to communicate. Type                   EFI_SMBUS_DEVICE_ADDRESS is defined in                   EFI_PEI_SMBUS_PPI.Execute() in the Platform                   Initialization SMBus PPI Specification.    @param Command  This command is transmitted by the SMBus host                   controller to the SMBus slave device and the                   interpretation is SMBus slave device specific.                   It can mean the offset to a list of functions                   inside an SMBus slave device. Not all                   operations or slave devices support this                   command's registers. Type                   EFI_SMBUS_DEVICE_COMMAND is defined in                   EFI_PEI_SMBUS_PPI.Execute() in the Platform                   Initialization SMBus PPI Specification.   @param Operation Signifies the particular SMBus                   hardware protocol instance it will use to                   execute the SMBus transactions. This SMBus                   hardware protocol is defined by the SMBus                   Specification and is not related to PI                   Architecture. Type EFI_SMBUS_OPERATION is                   defined in EFI_PEI_SMBUS_PPI.Execute() in the                   Platform Initialization SMBus PPI                   Specification.    @param PecCheck Defines if Packet Error Code (PEC) checking                   is required for this operation. SMBus Host                   Controller Code Definitions Version 1.0                   August 21, 2006 13                      @param Length    Signifies the number of bytes that this operation will do.                   The maximum number of bytes can be revision                   specific and operation specific. This field                   will contain the actual number of bytes that                   are executed for this operation. Not all                   operations require this argument.    @param Buffer   Contains the value of data to execute to the                   SMBus slave device. Not all operations require                   this argument. The length of this buffer is                   identified by Length.         @retval EFI_SUCCESS           The last data that was returned from the                                 access matched the poll exit criteria.    @retval EFI_CRC_ERROR         Checksum is not correct (PEC is incorrect).    @retval EFI_TIMEOUT           Timeout expired before the operation was                                 completed. Timeout is determined by the                                 SMBus host controller device.    @retval EFI_OUT_OF_RESOURCES  The request could not be                                 completed due to a lack of                                 resources.    @retval EFI_DEVICE_ERROR      The request was not completed                                 because a failure that was reflected                                 in the Host Status Register bit.                                 Device errors are a result of a                                 transaction collision, illegal                                 command field, unclaimed cycle (host                                 initiated), or bus errors                                 (collisions).    @retval EFI_INVALID_PARAMETER Operation is not defined in                                 EFI_SMBUS_OPERATION.    @retval EFI_INVALID_PARAMETER Length/Buffer is NULL for                                 operations except for                                 EfiSmbusQuickRead and                                 EfiSmbusQuickWrite. Length is                                 outside the range of valid                                 values.    @retval EFI_UNSUPPORTED       The SMBus operation or PEC is not                                 supported.     @retval EFI_BUFFER_TOO_SMALL  Buffer is not sufficient for                                 this operation.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMBUS_HC_EXECUTE_OPERATION
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_SMBUS_HC_PROTOCOL
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
comment|/**       The ArpDevice() function provides a standard way for a device driver to    enumerate the entire SMBus or specific devices on the bus.      @param This           A pointer to the EFI_SMBUS_HC_PROTOCOL instance.    @param ArpAll         A Boolean expression that indicates if the                         host drivers need to enumerate all the devices                         or enumerate only the device that is                         identified by SmbusUdid. If ArpAll is TRUE,                         SmbusUdid and SlaveAddress are optional. If                         ArpAll is FALSE, ArpDevice will enumerate                         SmbusUdid and the address will be at                         SlaveAddress.    @param SmbusUdid      The Unique Device Identifier (UDID) that is                         associated with this device. Type                         EFI_SMBUS_UDID is defined in                         EFI_PEI_SMBUS_PPI.ArpDevice() in the                         Platform Initialization SMBus PPI                         Specification.    @param SlaveAddress   The SMBus slave address that is                         associated with an SMBus UDID.    @retval EFI_SUCCESS           The last data that was returned from the                                 access matched the poll exit criteria.    @retval EFI_CRC_ERROR         Checksum is not correct (PEC is                                 incorrect).    @retval EFI_TIMEOUT           Timeout expired before the operation was                                 completed. Timeout is determined by the                                 SMBus host controller device.    @retval EFI_OUT_OF_RESOURCES  The request could not be                                 completed due to a lack of                                 resources.    @retval EFI_DEVICE_ERROR      The request was not completed                                 because a failure was reflected in                                 the Host Status Register bit. Device                                 Errors are a result of a transaction                                 collision, illegal command field,                                 unclaimed cycle (host initiated), or                                 bus errors (collisions).    @retval EFI_UNSUPPORTED       ArpDevice, GetArpMap, and Notify are                                 not implemented by this driver.     **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMBUS_HC_PROTOCOL_ARP_DEVICE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_SMBUS_HC_PROTOCOL
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
comment|/**   The GetArpMap() function returns the mapping of all the SMBus devices    that were enumerated by the SMBus host driver.      @param This           A pointer to the EFI_SMBUS_HC_PROTOCOL instance.      @param Length         Size of the buffer that contains the SMBus                         device map.      @param SmbusDeviceMap The pointer to the device map as                         enumerated by the SMBus controller                         driver.      @retval EFI_SUCCESS       The SMBus returned the current device map.      @retval EFI_UNSUPPORTED   ArpDevice, GetArpMap, and Notify are                             not implemented by this driver.    **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMBUS_HC_PROTOCOL_GET_ARP_MAP
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_SMBUS_HC_PROTOCOL
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
comment|/**   The notify function does some actions.      @param SlaveAddress   The SMBUS hardware address to which the SMBUS device is preassigned or allocated.    @param Data   Data of the SMBus host notify command that the caller wants to be called.      @return EFI_STATUS **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMBUS_NOTIFY_FUNCTION
function_decl|)
parameter_list|(
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
comment|/**       The Notify() function registers all the callback functions to   allow the bus driver to call these functions when the    SlaveAddress/Data pair happens.      @param  This            A pointer to the EFI_SMBUS_HC_PROTOCOL instance.      @param  SlaveAddress    Address that the host controller detects                           as sending a message and calls all the registered function.    @param  Data            Data that the host controller detects as sending                           message and calls all the registered function.     @param  NotifyFunction  The function to call when the bus                           driver detects the SlaveAddress and                           Data pair.    @retval EFI_SUCCESS       NotifyFunction was registered.      @retval EFI_UNSUPPORTED   ArpDevice, GetArpMap, and Notify are                             not implemented by this driver.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMBUS_HC_PROTOCOL_NOTIFY
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_SMBUS_HC_PROTOCOL
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
name|EFI_SMBUS_NOTIFY_FUNCTION
name|NotifyFunction
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_SMBUS_HC_PROTOCOL provides SMBus host controller management and basic data
end_comment

begin_comment
comment|/// transactions over SMBus. There is one EFI_SMBUS_HC_PROTOCOL instance for each SMBus
end_comment

begin_comment
comment|/// host controller.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_SMBUS_HC_PROTOCOL
block|{
name|EFI_SMBUS_HC_EXECUTE_OPERATION
name|Execute
decl_stmt|;
name|EFI_SMBUS_HC_PROTOCOL_ARP_DEVICE
name|ArpDevice
decl_stmt|;
name|EFI_SMBUS_HC_PROTOCOL_GET_ARP_MAP
name|GetArpMap
decl_stmt|;
name|EFI_SMBUS_HC_PROTOCOL_NOTIFY
name|Notify
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSmbusHcProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

