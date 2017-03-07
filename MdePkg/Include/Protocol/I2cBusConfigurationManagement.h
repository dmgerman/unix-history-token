begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   I2C Bus Configuration Management Protocol as defined in the PI 1.3 specification.    The EFI I2C bus configuration management protocol provides platform specific    services that allow the I2C host protocol to reconfigure the switches and multiplexers    and set the clock frequency for the I2C bus. This protocol also enables the I2C host protocol    to reset an I2C device which may be locking up the I2C bus by holding the clock or data line low.    Copyright (c) 2013, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   This protocol is from PI Version 1.3.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__I2C_BUS_CONFIGURATION_MANAGEMENT_H__
end_ifndef

begin_define
define|#
directive|define
name|__I2C_BUS_CONFIGURATION_MANAGEMENT_H__
end_define

begin_define
define|#
directive|define
name|EFI_I2C_BUS_CONFIGURATION_MANAGEMENT_PROTOCOL_GUID
define|\
value|{ 0x55b71fb5, 0x17c6, 0x410e, { 0xb5, 0xbd, 0x5f, 0xa2, 0xe3, 0xd4, 0x46, 0x6b }}
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// I2C bus configuration management protocol
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI I2C bus configuration management protocol provides platform
end_comment

begin_comment
comment|/// specific services that allow the I2C host protocol to reconfigure the
end_comment

begin_comment
comment|/// switches and multiplexers and set the clock frequency for the I2C bus.
end_comment

begin_comment
comment|/// This protocol also enables the I2C host protocol to reset an I2C device
end_comment

begin_comment
comment|/// which may be locking up the I2C bus by holding the clock or data line
end_comment

begin_comment
comment|/// low.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The I2C protocol stack uses the concept of an I2C bus configuration as
end_comment

begin_comment
comment|/// a way to describe a particular state of the switches and multiplexers
end_comment

begin_comment
comment|/// in the I2C bus.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A simple I2C bus does not have any multiplexers or switches is described
end_comment

begin_comment
comment|/// to the I2C protocol stack with a single I2C bus configuration which
end_comment

begin_comment
comment|/// specifies the I2C bus frequency.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// An I2C bus with switches and multiplexers use an I2C bus configuration
end_comment

begin_comment
comment|/// to describe each of the unique settings for the switches and multiplexers
end_comment

begin_comment
comment|/// and the I2C bus frequency.  However the I2C bus configuration management
end_comment

begin_comment
comment|/// protocol only needs to define the I2C bus configurations that the software
end_comment

begin_comment
comment|/// uses, which may be a subset of the total.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The I2C bus configuration description includes a list of I2C devices
end_comment

begin_comment
comment|/// which may be accessed when this I2C bus configuration is enabled.  I2C
end_comment

begin_comment
comment|/// devices before a switch or multiplexer must be included in one I2C bus
end_comment

begin_comment
comment|/// configuration while I2C devices after a switch or multiplexer are on
end_comment

begin_comment
comment|/// another I2C bus configuration.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The I2C bus configuration management protocol is an optional protocol.
end_comment

begin_comment
comment|/// When the I2C bus configuration protocol is not defined the I2C host
end_comment

begin_comment
comment|/// protocol does not start and the I2C master protocol may be used for
end_comment

begin_comment
comment|/// other purposes such as SMBus traffic.  When the I2C bus configuration
end_comment

begin_comment
comment|/// protocol is available, the I2C host protocol uses the I2C bus
end_comment

begin_comment
comment|/// configuration protocol to call into the platform specific code to set
end_comment

begin_comment
comment|/// the switches and multiplexers and set the maximum I2C bus frequency.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The platform designers determine the maximum I2C bus frequency by
end_comment

begin_comment
comment|/// selecting a frequency which supports all of the I2C devices on the
end_comment

begin_comment
comment|/// I2C bus for the setting of switches and multiplexers.  The platform
end_comment

begin_comment
comment|/// designers must validate this against the I2C device data sheets and
end_comment

begin_comment
comment|/// any limits of the I2C controller or bus length.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// During I2C device enumeration, the I2C bus driver retrieves the I2C
end_comment

begin_comment
comment|/// bus configuration that must be used to perform I2C transactions to
end_comment

begin_comment
comment|/// each I2C device.  This I2C bus configuration value is passed into
end_comment

begin_comment
comment|/// the I2C host protocol to identify the I2C bus configuration required
end_comment

begin_comment
comment|/// to access a specific I2C device.  The I2C host protocol calls
end_comment

begin_comment
comment|/// EnableBusConfiguration() to set the switches and multiplexers in the
end_comment

begin_comment
comment|/// I2C bus and the I2C clock frequency.  The I2C host protocol may
end_comment

begin_comment
comment|/// optimize calls to EnableBusConfiguration() by only making the call
end_comment

begin_comment
comment|/// when the I2C bus configuration value changes between I2C requests.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// When I2C transactions are required on the same I2C bus to change the
end_comment

begin_comment
comment|/// state of multiplexers or switches, the I2C master protocol must be
end_comment

begin_comment
comment|/// used to perform the necessary I2C transactions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// It is up to the platform specific code to choose the proper I2C bus
end_comment

begin_comment
comment|/// configuration when ExitBootServices() is called. Some operating systems
end_comment

begin_comment
comment|/// are not able to manage the I2C bus configurations and must use the I2C
end_comment

begin_comment
comment|/// bus configuration that is established by the platform firmware before
end_comment

begin_comment
comment|/// ExitBootServices() returns.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|struct
name|_EFI_I2C_BUS_CONFIGURATION_MANAGEMENT_PROTOCOL
name|EFI_I2C_BUS_CONFIGURATION_MANAGEMENT_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Enable access to an I2C bus configuration.    This routine must be called at or below TPL_NOTIFY.  For synchronous   requests this routine must be called at or below TPL_CALLBACK.    Reconfigure the switches and multiplexers in the I2C bus to enable   access to a specific I2C bus configuration.  Also select the maximum   clock frequency for this I2C bus configuration.    This routine uses the I2C Master protocol to perform I2C transactions   on the local bus.  This eliminates any recursion in the I2C stack for   configuration transactions on the same I2C bus.  This works because the   local I2C bus is idle while the I2C bus configuration is being enabled.    If I2C transactions must be performed on other I2C busses, then the   EFI_I2C_HOST_PROTOCOL, the EFI_I2C_IO_PROTCOL, or a third party I2C   driver interface for a specific device must be used.  This requirement   is because the I2C host protocol controls the flow of requests to the   I2C controller.  Use the EFI_I2C_HOST_PROTOCOL when the I2C device is   not enumerated by the EFI_I2C_ENUMERATE_PROTOCOL.  Use a protocol   produced by a third party driver when it is available or the   EFI_I2C_IO_PROTOCOL when the third party driver is not available but   the device is enumerated with the EFI_I2C_ENUMERATE_PROTOCOL.    When Event is NULL, EnableI2cBusConfiguration operates synchronously   and returns the I2C completion status as its return value.    @param[in]  This            Pointer to an EFI_I2C_BUS_CONFIGURATION_MANAGEMENT_PROTOCOL                               structure.   @param[in]  I2cBusConfiguration Index of an I2C bus configuration.  All                                   values in the range of zero to N-1 are                                   valid where N is the total number of I2C                                   bus configurations for an I2C bus.   @param[in]  Event           Event to signal when the transaction is complete   @param[out] I2cStatus       Buffer to receive the transaction status.    @return  When Event is NULL, EnableI2cBusConfiguration operates synchrouously   and returns the I2C completion status as its return value.  In this case it is   recommended to use NULL for I2cStatus.  The values returned from   EnableI2cBusConfiguration are:    @retval EFI_SUCCESS           The asynchronous bus configuration request                                 was successfully started when Event is not                                 NULL.   @retval EFI_SUCCESS           The bus configuration request completed                                 successfully when Event is NULL.   @retval EFI_DEVICE_ERROR      The bus configuration failed.   @retval EFI_NO_MAPPING        Invalid I2cBusConfiguration value  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_I2C_BUS_CONFIGURATION_MANAGEMENT_PROTOCOL_ENABLE_I2C_BUS_CONFIGURATION
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_I2C_BUS_CONFIGURATION_MANAGEMENT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINTN
name|I2cBusConfiguration
parameter_list|,
name|IN
name|EFI_EVENT
name|Event
name|OPTIONAL
parameter_list|,
name|IN
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
comment|/// I2C bus configuration management protocol
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_I2C_BUS_CONFIGURATION_MANAGEMENT_PROTOCOL
block|{
comment|///
comment|/// Enable an I2C bus configuration for use.
comment|///
name|EFI_I2C_BUS_CONFIGURATION_MANAGEMENT_PROTOCOL_ENABLE_I2C_BUS_CONFIGURATION
name|EnableI2cBusConfiguration
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
name|gEfiI2cBusConfigurationManagementProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//  __I2C_BUS_CONFIGURATION_MANAGEMENT_H__
end_comment

end_unit

