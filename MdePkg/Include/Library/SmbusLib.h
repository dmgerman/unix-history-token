begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provides library functions to access SMBUS devices. Libraries of this class   must be ported to a specific SMBUS controller.  Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SMBUS_LIB__
end_ifndef

begin_define
define|#
directive|define
name|__SMBUS_LIB__
end_define

begin_comment
comment|/**   Macro that converts SMBUS slave address, SMBUS command, SMBUS data length,   and PEC to a value that can be passed to the SMBUS Library functions.    Computes an address that is compatible with the SMBUS Library functions.   The unused upper bits of SlaveAddress, Command, and Length are stripped   prior to the generation of the address.      @param  SlaveAddress    SMBUS Slave Address.  Range 0..127.   @param  Command         SMBUS Command.  Range 0..255.   @param  Length          SMBUS Data Length.  Range 0..32.   @param  Pec             TRUE if Packet Error Checking is enabled.  Otherwise FALSE.  **/
end_comment

begin_define
define|#
directive|define
name|SMBUS_LIB_ADDRESS
parameter_list|(
name|SlaveAddress
parameter_list|,
name|Command
parameter_list|,
name|Length
parameter_list|,
name|Pec
parameter_list|)
define|\
value|( ((Pec) ? BIT22: 0)                  | \     (((SlaveAddress)& 0x7f)<< 1)      | \     (((Command)& 0xff)<< 8)      | \     (((Length)& 0x3f)<< 16)       \   )
end_define

begin_comment
comment|/**   Macro that returns the SMBUS Slave Address value from an SmBusAddress Parameter value.      @param SmBusAddress   Address that encodes the SMBUS Slave Address, SMBUS Command, SMBUS Data Length, and PEC  **/
end_comment

begin_define
define|#
directive|define
name|SMBUS_LIB_SLAVE_ADDRESS
parameter_list|(
name|SmBusAddress
parameter_list|)
value|(((SmBusAddress)>> 1)& 0x7f)
end_define

begin_comment
comment|/**   Macro that returns the SMBUS Command value from an SmBusAddress Parameter value.      @param SmBusAddress   Address that encodes the SMBUS Slave Address, SMBUS Command, SMBUS Data Length, and PEC **/
end_comment

begin_define
define|#
directive|define
name|SMBUS_LIB_COMMAND
parameter_list|(
name|SmBusAddress
parameter_list|)
value|(((SmBusAddress)>> 8)& 0xff)
end_define

begin_comment
comment|/**   Macro that returns the SMBUS Data Length value from an SmBusAddress Parameter value.      @param SmBusAddress Address that encodes the SMBUS Slave Address, SMBUS Command, SMBUS Data Length, and PEC  **/
end_comment

begin_define
define|#
directive|define
name|SMBUS_LIB_LENGTH
parameter_list|(
name|SmBusAddress
parameter_list|)
value|(((SmBusAddress)>> 16)& 0x3f)
end_define

begin_comment
comment|/**   Macro that returns the SMBUS PEC value from an SmBusAddress Parameter value.      @param SmBusAddress Address that encodes the SMBUS Slave Address, SMBUS Command, SMBUS Data Length, and PEC    **/
end_comment

begin_define
define|#
directive|define
name|SMBUS_LIB_PEC
parameter_list|(
name|SmBusAddress
parameter_list|)
value|((BOOLEAN) (((SmBusAddress)& BIT22) != 0))
end_define

begin_comment
comment|/**   Macro that returns the set of reserved bits from an SmBusAddress Parameter value.      @param SmBusAddress Address that encodes the SMBUS Slave Address, SMBUS Command, SMBUS Data Length, and PEC    **/
end_comment

begin_define
define|#
directive|define
name|SMBUS_LIB_RESERVED
parameter_list|(
name|SmBusAddress
parameter_list|)
value|((SmBusAddress)& ~(BIT23 - 2))
end_define

begin_comment
comment|/**   Executes an SMBUS quick read command.    Executes an SMBUS quick read command on the SMBUS device specified by SmBusAddress.   Only the SMBUS slave address field of SmBusAddress is required.   If Status is not NULL, then the status of the executed command is returned in Status.   If PEC is set in SmBusAddress, then ASSERT().   If Command in SmBusAddress is not zero, then ASSERT().   If Length in SmBusAddress is not zero, then ASSERT().   If any reserved bits of SmBusAddress are set, then ASSERT().    @param  SmBusAddress  Address that encodes the SMBUS Slave Address,                         SMBUS Command, SMBUS Data Length, and PEC.   @param  Status        Return status for the executed command.                         This is an optional parameter and may be NULL.                         RETURN_SUCCESS  The SMBUS command was executed.                         RETURN_TIMEOUT  A timeout occurred while executing the SMBUS command.                         RETURN_DEVICE_ERROR The request was not completed because a failure                         reflected in the Host Status Register bit.  Device errors are a result                         of a transaction collision, illegal command field, unclaimed cycle                         (host initiated), or bus errors (collisions).                         RETURN_UNSUPPORTED  The SMBus operation is not supported.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|SmBusQuickRead
parameter_list|(
name|IN
name|UINTN
name|SmBusAddress
parameter_list|,
name|OUT
name|RETURN_STATUS
modifier|*
name|Status
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Executes an SMBUS quick write command.    Executes an SMBUS quick write command on the SMBUS device specified by SmBusAddress.   Only the SMBUS slave address field of SmBusAddress is required.   If Status is not NULL, then the status of the executed command is returned in Status.   If PEC is set in SmBusAddress, then ASSERT().   If Command in SmBusAddress is not zero, then ASSERT().   If Length in SmBusAddress is not zero, then ASSERT().   If any reserved bits of SmBusAddress are set, then ASSERT().    @param  SmBusAddress  Address that encodes the SMBUS Slave Address,                         SMBUS Command, SMBUS Data Length, and PEC.   @param  Status        Return status for the executed command.                         This is an optional parameter and may be NULL.                         RETURN_SUCCESS The SMBUS command was executed.                         RETURN_TIMEOUT A timeout occurred while executing the SMBUS command.                         RETURN_DEVICE_ERROR  The request was not completed because a failure                         reflected in the Host Status Register bit.  Device errors are a result                         of a transaction collision, illegal command field, unclaimed cycle                         (host initiated), or bus errors (collisions).                         RETURN_UNSUPPORTED  The SMBus operation is not supported.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|SmBusQuickWrite
parameter_list|(
name|IN
name|UINTN
name|SmBusAddress
parameter_list|,
name|OUT
name|RETURN_STATUS
modifier|*
name|Status
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Executes an SMBUS receive byte command.    Executes an SMBUS receive byte command on the SMBUS device specified by SmBusAddress.   Only the SMBUS slave address field of SmBusAddress is required.   The byte received from the SMBUS is returned.   If Status is not NULL, then the status of the executed command is returned in Status.   If Command in SmBusAddress is not zero, then ASSERT().   If Length in SmBusAddress is not zero, then ASSERT().   If any reserved bits of SmBusAddress are set, then ASSERT().    @param  SmBusAddress  Address that encodes the SMBUS Slave Address,                         SMBUS Command, SMBUS Data Length, and PEC.   @param  Status        Return status for the executed command.                         This is an optional parameter and may be NULL.                         RETURN_SUCCESS The SMBUS command was executed.                         RETURN_TIMEOUT A timeout occurred while executing the SMBUS command.                         RETURN_DEVICE_ERROR  The request was not completed because a failure                         reflected in the Host Status Register bit.  Device errors are a result                         of a transaction collision, illegal command field, unclaimed cycle                         (host initiated), or bus errors (collisions).                         RETURN_CRC_ERROR  The checksum is not correct (PEC is incorrect)                         RETURN_UNSUPPORTED  The SMBus operation is not supported.    @return The byte received from the SMBUS.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|SmBusReceiveByte
parameter_list|(
name|IN
name|UINTN
name|SmBusAddress
parameter_list|,
name|OUT
name|RETURN_STATUS
modifier|*
name|Status
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Executes an SMBUS send byte command.    Executes an SMBUS send byte command on the SMBUS device specified by SmBusAddress.   The byte specified by Value is sent.   Only the SMBUS slave address field of SmBusAddress is required.  Value is returned.   If Status is not NULL, then the status of the executed command is returned in Status.   If Command in SmBusAddress is not zero, then ASSERT().   If Length in SmBusAddress is not zero, then ASSERT().   If any reserved bits of SmBusAddress are set, then ASSERT().    @param  SmBusAddress  Address that encodes the SMBUS Slave Address,                         SMBUS Command, SMBUS Data Length, and PEC.   @param  Value         The 8-bit value to send.   @param  Status        Return status for the executed command.                         This is an optional parameter and may be NULL.                         RETURN_SUCCESS The SMBUS command was executed.                         RETURN_TIMEOUT A timeout occurred while executing the SMBUS command.                         RETURN_DEVICE_ERROR  The request was not completed because a failure                         reflected in the Host Status Register bit.  Device errors are a result                         of a transaction collision, illegal command field, unclaimed cycle                         (host initiated), or bus errors (collisions).                         RETURN_CRC_ERROR  The checksum is not correct (PEC is incorrect)                         RETURN_UNSUPPORTED  The SMBus operation is not supported.    @return The parameter of Value.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|SmBusSendByte
parameter_list|(
name|IN
name|UINTN
name|SmBusAddress
parameter_list|,
name|IN
name|UINT8
name|Value
parameter_list|,
name|OUT
name|RETURN_STATUS
modifier|*
name|Status
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Executes an SMBUS read data byte command.    Executes an SMBUS read data byte command on the SMBUS device specified by SmBusAddress.   Only the SMBUS slave address and SMBUS command fields of SmBusAddress are required.   The 8-bit value read from the SMBUS is returned.   If Status is not NULL, then the status of the executed command is returned in Status.   If Length in SmBusAddress is not zero, then ASSERT().   If any reserved bits of SmBusAddress are set, then ASSERT().    @param  SmBusAddress    Address that encodes the SMBUS Slave Address,                           SMBUS Command, SMBUS Data Length, and PEC.   @param  Status        Return status for the executed command.                         This is an optional parameter and may be NULL.                         RETURN_SUCCESS The SMBUS command was executed.                         RETURN_TIMEOUT A timeout occurred while executing the SMBUS command.                         RETURN_DEVICE_ERROR  The request was not completed because a failure                         reflected in the Host Status Register bit.  Device errors are a result                         of a transaction collision, illegal command field, unclaimed cycle                         (host initiated), or bus errors (collisions).                         RETURN_CRC_ERROR  The checksum is not correct (PEC is incorrect)                         RETURN_UNSUPPORTED  The SMBus operation is not supported.    @return The byte read from the SMBUS.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|SmBusReadDataByte
parameter_list|(
name|IN
name|UINTN
name|SmBusAddress
parameter_list|,
name|OUT
name|RETURN_STATUS
modifier|*
name|Status
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Executes an SMBUS write data byte command.    Executes an SMBUS write data byte command on the SMBUS device specified by SmBusAddress.   The 8-bit value specified by Value is written.   Only the SMBUS slave address and SMBUS command fields of SmBusAddress are required.   Value is returned.   If Status is not NULL, then the status of the executed command is returned in Status.   If Length in SmBusAddress is not zero, then ASSERT().   If any reserved bits of SmBusAddress are set, then ASSERT().    @param  SmBusAddress  Address that encodes the SMBUS Slave Address,                         SMBUS Command, SMBUS Data Length, and PEC.   @param  Value         The 8-bit value to write.   @param  Status        Return status for the executed command.                         This is an optional parameter and may be NULL.                         RETURN_SUCCESS The SMBUS command was executed.                         RETURN_TIMEOUT A timeout occurred while executing the SMBUS command.                         RETURN_DEVICE_ERROR  The request was not completed because a failure                         reflected in the Host Status Register bit.  Device errors are a result                         of a transaction collision, illegal command field, unclaimed cycle                         (host initiated), or bus errors (collisions).                         RETURN_CRC_ERROR  The checksum is not correct (PEC is incorrect)                         RETURN_UNSUPPORTED  The SMBus operation is not supported.    @return The parameter of Value.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|SmBusWriteDataByte
parameter_list|(
name|IN
name|UINTN
name|SmBusAddress
parameter_list|,
name|IN
name|UINT8
name|Value
parameter_list|,
name|OUT
name|RETURN_STATUS
modifier|*
name|Status
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Executes an SMBUS read data word command.    Executes an SMBUS read data word command on the SMBUS device specified by SmBusAddress.   Only the SMBUS slave address and SMBUS command fields of SmBusAddress are required.   The 16-bit value read from the SMBUS is returned.   If Status is not NULL, then the status of the executed command is returned in Status.   If Length in SmBusAddress is not zero, then ASSERT().   If any reserved bits of SmBusAddress are set, then ASSERT().      @param  SmBusAddress  Address that encodes the SMBUS Slave Address,                         SMBUS Command, SMBUS Data Length, and PEC.   @param  Status        Return status for the executed command.                         This is an optional parameter and may be NULL.                         RETURN_SUCCESS The SMBUS command was executed.                         RETURN_TIMEOUT A timeout occurred while executing the SMBUS command.                         RETURN_DEVICE_ERROR  The request was not completed because a failure                         reflected in the Host Status Register bit.  Device errors are a result                         of a transaction collision, illegal command field, unclaimed cycle                         (host initiated), or bus errors (collisions).                         RETURN_CRC_ERROR  The checksum is not correct (PEC is incorrect)                         RETURN_UNSUPPORTED  The SMBus operation is not supported.    @return The byte read from the SMBUS.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|SmBusReadDataWord
parameter_list|(
name|IN
name|UINTN
name|SmBusAddress
parameter_list|,
name|OUT
name|RETURN_STATUS
modifier|*
name|Status
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Executes an SMBUS write data word command.    Executes an SMBUS write data word command on the SMBUS device specified by SmBusAddress.   The 16-bit value specified by Value is written.   Only the SMBUS slave address and SMBUS command fields of SmBusAddress are required.   Value is returned.   If Status is not NULL, then the status of the executed command is returned in Status.   If Length in SmBusAddress is not zero, then ASSERT().   If any reserved bits of SmBusAddress are set, then ASSERT().    @param  SmBusAddress  Address that encodes the SMBUS Slave Address,                         SMBUS Command, SMBUS Data Length, and PEC.   @param  Value         The 16-bit value to write.   @param  Status        Return status for the executed command.                         This is an optional parameter and may be NULL.                         RETURN_SUCCESS The SMBUS command was executed.                         RETURN_TIMEOUT A timeout occurred while executing the SMBUS command.                         RETURN_DEVICE_ERROR  The request was not completed because a failure                         reflected in the Host Status Register bit.  Device errors are a result                         of a transaction collision, illegal command field, unclaimed cycle                         (host initiated), or bus errors (collisions).                         RETURN_CRC_ERROR  The checksum is not correct (PEC is incorrect)                         RETURN_UNSUPPORTED  The SMBus operation is not supported.    @return The parameter of Value.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|SmBusWriteDataWord
parameter_list|(
name|IN
name|UINTN
name|SmBusAddress
parameter_list|,
name|IN
name|UINT16
name|Value
parameter_list|,
name|OUT
name|RETURN_STATUS
modifier|*
name|Status
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Executes an SMBUS process call command.    Executes an SMBUS process call command on the SMBUS device specified by SmBusAddress.   The 16-bit value specified by Value is written.   Only the SMBUS slave address and SMBUS command fields of SmBusAddress are required.   The 16-bit value returned by the process call command is returned.   If Status is not NULL, then the status of the executed command is returned in Status.   If Length in SmBusAddress is not zero, then ASSERT().   If any reserved bits of SmBusAddress are set, then ASSERT().    @param  SmBusAddress  Address that encodes the SMBUS Slave Address,                         SMBUS Command, SMBUS Data Length, and PEC.   @param  Value         The 16-bit value to write.   @param  Status        Return status for the executed command.                         This is an optional parameter and may be NULL.                         RETURN_SUCCESS The SMBUS command was executed.                         RETURN_TIMEOUT A timeout occurred while executing the SMBUS command.                         RETURN_DEVICE_ERROR  The request was not completed because a failure                         reflected in the Host Status Register bit.  Device errors are a result                         of a transaction collision, illegal command field, unclaimed cycle                         (host initiated), or bus errors (collisions).                         RETURN_CRC_ERROR  The checksum is not correct (PEC is incorrect)                         RETURN_UNSUPPORTED  The SMBus operation is not supported.    @return The 16-bit value returned by the process call command.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|SmBusProcessCall
parameter_list|(
name|IN
name|UINTN
name|SmBusAddress
parameter_list|,
name|IN
name|UINT16
name|Value
parameter_list|,
name|OUT
name|RETURN_STATUS
modifier|*
name|Status
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Executes an SMBUS read block command.    Executes an SMBUS read block command on the SMBUS device specified by SmBusAddress.   Only the SMBUS slave address and SMBUS command fields of SmBusAddress are required.   Bytes are read from the SMBUS and stored in Buffer.   The number of bytes read is returned, and will never return a value larger than 32-bytes.   If Status is not NULL, then the status of the executed command is returned in Status.   It is the caller's responsibility to make sure Buffer is large enough for the total number of bytes read.   SMBUS supports a maximum transfer size of 32 bytes, so Buffer does not need to be any larger than 32 bytes.   If Length in SmBusAddress is not zero, then ASSERT().   If Buffer is NULL, then ASSERT().   If any reserved bits of SmBusAddress are set, then ASSERT().    @param  SmBusAddress  Address that encodes the SMBUS Slave Address,                         SMBUS Command, SMBUS Data Length, and PEC.   @param  Buffer        Pointer to the buffer to store the bytes read from the SMBUS.   @param  Status        Return status for the executed command.                         This is an optional parameter and may be NULL.                         RETURN_SUCCESS The SMBUS command was executed.                         RETURN_TIMEOUT A timeout occurred while executing the SMBUS command.                         RETURN_DEVICE_ERROR  The request was not completed because a failure                         reflected in the Host Status Register bit.  Device errors are a result                         of a transaction collision, illegal command field, unclaimed cycle                         (host initiated), or bus errors (collisions).                         RETURN_CRC_ERROR  The checksum is not correct (PEC is incorrect)                         RETURN_UNSUPPORTED  The SMBus operation is not supported.    @return The number of bytes read.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|SmBusReadBlock
parameter_list|(
name|IN
name|UINTN
name|SmBusAddress
parameter_list|,
name|OUT
name|VOID
modifier|*
name|Buffer
parameter_list|,
name|OUT
name|RETURN_STATUS
modifier|*
name|Status
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Executes an SMBUS write block command.    Executes an SMBUS write block command on the SMBUS device specified by SmBusAddress.   The SMBUS slave address, SMBUS command, and SMBUS length fields of SmBusAddress are required.   Bytes are written to the SMBUS from Buffer.   The number of bytes written is returned, and will never return a value larger than 32-bytes.   If Status is not NULL, then the status of the executed command is returned in Status.     If Length in SmBusAddress is zero or greater than 32, then ASSERT().   If Buffer is NULL, then ASSERT().   If any reserved bits of SmBusAddress are set, then ASSERT().    @param  SmBusAddress  Address that encodes the SMBUS Slave Address,                         SMBUS Command, SMBUS Data Length, and PEC.   @param  Buffer        Pointer to the buffer to store the bytes read from the SMBUS.   @param  Status        Return status for the executed command.                         This is an optional parameter and may be NULL.                         RETURN_TIMEOUT A timeout occurred while executing the SMBUS command.                         RETURN_DEVICE_ERROR  The request was not completed because a failure                         reflected in the Host Status Register bit.  Device errors are a result                         of a transaction collision, illegal command field, unclaimed cycle                         (host initiated), or bus errors (collisions).                         RETURN_CRC_ERROR  The checksum is not correct (PEC is incorrect)                         RETURN_UNSUPPORTED  The SMBus operation is not supported.    @return The number of bytes written.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|SmBusWriteBlock
parameter_list|(
name|IN
name|UINTN
name|SmBusAddress
parameter_list|,
name|OUT
name|VOID
modifier|*
name|Buffer
parameter_list|,
name|OUT
name|RETURN_STATUS
modifier|*
name|Status
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Executes an SMBUS block process call command.    Executes an SMBUS block process call command on the SMBUS device specified by SmBusAddress.   The SMBUS slave address, SMBUS command, and SMBUS length fields of SmBusAddress are required.   Bytes are written to the SMBUS from WriteBuffer.  Bytes are then read from the SMBUS into ReadBuffer.   If Status is not NULL, then the status of the executed command is returned in Status.   It is the caller's responsibility to make sure ReadBuffer is large enough for the total number of bytes read.   SMBUS supports a maximum transfer size of 32 bytes, so Buffer does not need to be any larger than 32 bytes.   If Length in SmBusAddress is zero or greater than 32, then ASSERT().   If WriteBuffer is NULL, then ASSERT().   If ReadBuffer is NULL, then ASSERT().   If any reserved bits of SmBusAddress are set, then ASSERT().    @param  SmBusAddress  Address that encodes the SMBUS Slave Address,                         SMBUS Command, SMBUS Data Length, and PEC.   @param  WriteBuffer   Pointer to the buffer of bytes to write to the SMBUS.   @param  ReadBuffer    Pointer to the buffer of bytes to read from the SMBUS.   @param  Status        Return status for the executed command.                         This is an optional parameter and may be NULL.                         RETURN_TIMEOUT A timeout occurred while executing the SMBUS command.                         RETURN_DEVICE_ERROR  The request was not completed because a failure                         reflected in the Host Status Register bit.  Device errors are a result                         of a transaction collision, illegal command field, unclaimed cycle                         (host initiated), or bus errors (collisions).                         RETURN_CRC_ERROR  The checksum is not correct (PEC is incorrect)                         RETURN_UNSUPPORTED  The SMBus operation is not supported.    @return The number of bytes written.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|SmBusBlockProcessCall
parameter_list|(
name|IN
name|UINTN
name|SmBusAddress
parameter_list|,
name|IN
name|VOID
modifier|*
name|WriteBuffer
parameter_list|,
name|OUT
name|VOID
modifier|*
name|ReadBuffer
parameter_list|,
name|OUT
name|RETURN_STATUS
modifier|*
name|Status
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

