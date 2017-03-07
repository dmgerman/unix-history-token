begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   I2C Device Enumerate Protocol as defined in the PI 1.3 specification.    This protocol supports the enumerations of device on the I2C bus.    Copyright (c) 2013, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   This protocol is from PI Version 1.3.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__I2C_ENUMERATE_H__
end_ifndef

begin_define
define|#
directive|define
name|__I2C_ENUMERATE_H__
end_define

begin_include
include|#
directive|include
file|<Pi/PiI2c.h>
end_include

begin_define
define|#
directive|define
name|EFI_I2C_ENUMERATE_PROTOCOL_GUID
value|{ 0xda8cd7c4, 0x1c00, 0x49e2, { 0x80, 0x3e, 0x52, 0x14, 0xe7, 0x01, 0x89, 0x4c }}
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_I2C_ENUMERATE_PROTOCOL
name|EFI_I2C_ENUMERATE_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Enumerate the I2C devices    This function enables the caller to traverse the set of I2C devices   on an I2C bus.    @param[in]  This              The platform data for the next device on                                 the I2C bus was returned successfully.   @param[in, out] Device        Pointer to a buffer containing an                                 EFI_I2C_DEVICE structure.  Enumeration is                                 started by setting the initial EFI_I2C_DEVICE                                 structure pointer to NULL.  The buffer                                 receives an EFI_I2C_DEVICE structure pointer                                 to the next I2C device.    @retval EFI_SUCCESS           The platform data for the next device on                                 the I2C bus was returned successfully.   @retval EFI_INVALID_PARAMETER Device is NULL   @retval EFI_NO_MAPPING        *Device does not point to a valid                                 EFI_I2C_DEVICE structure returned in a                                 previous call Enumerate().  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_I2C_ENUMERATE_PROTOCOL_ENUMERATE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_I2C_ENUMERATE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|CONST
name|EFI_I2C_DEVICE
modifier|*
modifier|*
name|Device
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Get the requested I2C bus frequency for a specified bus configuration.    This function returns the requested I2C bus clock frequency for the   I2cBusConfiguration.  This routine is provided for diagnostic purposes   and is meant to be called after calling Enumerate to get the   I2cBusConfiguration value.    @param[in] This                 Pointer to an EFI_I2C_ENUMERATE_PROTOCOL                                   structure.   @param[in] I2cBusConfiguration  I2C bus configuration to access the I2C                                   device   @param[out] *BusClockHertz      Pointer to a buffer to receive the I2C                                   bus clock frequency in Hertz    @retval EFI_SUCCESS           The I2C bus frequency was returned                                 successfully.   @retval EFI_INVALID_PARAMETER BusClockHertz was NULL   @retval EFI_NO_MAPPING        Invalid I2cBusConfiguration value  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_I2C_ENUMERATE_PROTOCOL_GET_BUS_FREQUENCY
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_I2C_ENUMERATE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINTN
name|I2cBusConfiguration
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|BusClockHertz
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// I2C Enumerate protocol
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_I2C_ENUMERATE_PROTOCOL
block|{
comment|///
comment|/// Traverse the set of I2C devices on an I2C bus.  This routine
comment|/// returns the next I2C device on an I2C bus.
comment|///
name|EFI_I2C_ENUMERATE_PROTOCOL_ENUMERATE
name|Enumerate
decl_stmt|;
comment|///
comment|/// Get the requested I2C bus frequency for a specified bus
comment|/// configuration.
comment|///
name|EFI_I2C_ENUMERATE_PROTOCOL_GET_BUS_FREQUENCY
name|GetBusFrequency
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
name|gEfiI2cEnumerateProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//  __I2C_ENUMERATE_H__
end_comment

end_unit

