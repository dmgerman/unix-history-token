begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This PPI manipulates the I2C host controller to perform transactions as a master    on the I2C bus using the current state of any switches or multiplexers in the I2C bus.    Copyright (c) 2013, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   This PPI is introduced in PI Version 1.3.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__I2C_MASTER_PPI_H__
end_ifndef

begin_define
define|#
directive|define
name|__I2C_MASTER_PPI_H__
end_define

begin_include
include|#
directive|include
file|<Pi/PiI2c.h>
end_include

begin_define
define|#
directive|define
name|EFI_PEI_I2C_MASTER_PPI_GUID
define|\
value|{ 0xb3bfab9b, 0x9f9c, 0x4e8b, { 0xad, 0x37, 0x7f, 0x8c, 0x51, 0xfc, 0x62, 0x80 }}
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_PEI_I2C_MASTER_PPI
name|EFI_PEI_I2C_MASTER_PPI
typedef|;
end_typedef

begin_comment
comment|/**   Set the frequency for the I2C clock line.      @param This                   Pointer to an EFI_PEI_I2C_MASTER_PPI structure.   @param BusClockHertz          Pointer to the requested I2C bus clock frequency in Hertz.                                 Upon return this value contains the actual frequency                                  in use by the I2C controller.    @retval EFI_SUCCESS           The bus frequency was set successfully.   @retval EFI_INVALID_PARAMETER BusClockHertz is NULL   @retval EFI_UNSUPPORTED       The controller does not support this frequency.     **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_I2C_MASTER_PPI_SET_BUS_FREQUENCY
function_decl|)
parameter_list|(
name|IN
name|EFI_PEI_I2C_MASTER_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|UINTN
modifier|*
name|BusClockHertz
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Reset the I2C controller and configure it for use.      @param  This                  Pointer to an EFI_PEI_I2C_MASTER_PPI structure.    @retval EFI_SUCCESS           The reset completed successfully.   @retval EFI_DEVICE_ERROR      The reset operation failed.     **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_I2C_MASTER_PPI_RESET
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_I2C_MASTER_PPI
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Start an I2C transaction on the host controller.      @param  This                   Pointer to an EFI_PEI_I2C_MASTER_PPI structure.   @param  SlaveAddress           Address of the device on the I2C bus.                                  Set the I2C_ADDRESSING_10_BIT when using 10-bit addresses,                                   clear this bit for 7-bit addressing.                                  Bits 0-6 are used for 7-bit I2C slave addresses and                                   bits 0-9 are used for 10-bit I2C slave addresses.   @param  RequestPacket          Pointer to an EFI_I2C_REQUEST_PACKET structure describing the I2C transaction.    @retval EFI_SUCCESS	           The transaction completed successfully.   @retval EFI_BAD_BUFFER_SIZE	   The RequestPacket->LengthInBytes value is too large.   @retval EFI_DEVICE_ERROR	     There was an I2C error (NACK) during the transaction.   @retval EFI_INVALID_PARAMETER	 RequestPacket is NULL   @retval EFI_NO_RESPONSE	       The I2C device is not responding to the slave address.                                  EFI_DEVICE_ERROR will be returned if the controller cannot distinguish when the NACK occurred.   @retval EFI_NOT_FOUND	         Reserved bit set in the SlaveAddress parameter   @retval EFI_OUT_OF_RESOURCES	 Insufficient memory for I2C transaction   @retval EFI_UNSUPPORTED	       The controller does not support the requested transaction.     **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_I2C_MASTER_PPI_START_REQUEST
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_I2C_MASTER_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|UINTN
name|SlaveAddress
parameter_list|,
name|IN
name|EFI_I2C_REQUEST_PACKET
modifier|*
name|RequestPacket
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This PPI manipulates the I2C host controller to perform transactions as a master on the I2C bus
end_comment

begin_comment
comment|/// using the current state of any switches or multiplexers in the I2C bus.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_PEI_I2C_MASTER_PPI
block|{
name|EFI_PEI_I2C_MASTER_PPI_SET_BUS_FREQUENCY
name|SetBusFrequency
decl_stmt|;
name|EFI_PEI_I2C_MASTER_PPI_RESET
name|Reset
decl_stmt|;
name|EFI_PEI_I2C_MASTER_PPI_START_REQUEST
name|StartRequest
decl_stmt|;
name|CONST
name|EFI_I2C_CONTROLLER_CAPABILITIES
modifier|*
name|I2cControllerCapabilities
decl_stmt|;
name|EFI_GUID
name|Identifier
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPeiI2cMasterPpiGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

