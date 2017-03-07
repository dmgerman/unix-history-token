begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Smbus Library Services that conduct SMBus transactions and enable the operatation   to be replayed during an S3 resume. This library class maps directly on top   of the SmbusLib class.    Copyright (c) 2007 - 2010, Intel Corporation. All rights reserved.<BR>    This program and the accompanying materials   are licensed and made available under the terms and conditions   of the BSD License which accompanies this distribution.  The   full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__S3_SMBUS_LIB_H__
end_ifndef

begin_define
define|#
directive|define
name|__S3_SMBUS_LIB_H__
end_define

begin_comment
comment|/**   Executes an SMBUS quick read command, and saves the value in the S3 script to be replayed   on S3 resume.    Executes an SMBUS quick read command on the SMBUS device specified by SmBusAddress.   Only the SMBUS slave address field of SmBusAddress is required.   If Status is not NULL, then the status of the executed command is returned in Status.   If PEC is set in SmBusAddress, then ASSERT().   If Command in SmBusAddress is not zero, then ASSERT().   If Length in SmBusAddress is not zero, then ASSERT().   If any reserved bits of SmBusAddress are set, then ASSERT().    @param[in]  SmBusAddress   The address that encodes the SMBUS Slave Address,                              SMBUS Command, SMBUS Data Length, and PEC.   @param[out] Status         The return status for the executed command.                              This is an optional parameter and may be NULL.                              RETURN_SUCCESS  		 The SMBUS command was executed.                              RETURN_TIMEOUT  		 A timeout occurred while executing the SMBUS command.                              RETURN_DEVICE_ERROR The request was not completed because a failure                               was recorded in the Host Status Register bit.  Device errors are a result                               of a transaction collision, illegal command field, unclaimed cycle                               (host initiated), or bus error (collision).                              RETURN_UNSUPPORTED  	The SMBus operation is not supported.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|S3SmBusQuickRead
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
comment|/**   Executes an SMBUS quick write command, and saves the value in the S3 script to be replayed   on S3 resume.    Executes an SMBUS quick write command on the SMBUS device specified by SmBusAddress.   Only the SMBUS slave address field of SmBusAddress is required.   If Status is not NULL, then the status of the executed command is returned in Status.   If PEC is set in SmBusAddress, then ASSERT().   If Command in SmBusAddress is not zero, then ASSERT().   If Length in SmBusAddress is not zero, then ASSERT().   If any reserved bits of SmBusAddress are set, then ASSERT().    @param[in]  SmBusAddress   The address that encodes the SMBUS Slave Address,                              SMBUS Command, SMBUS Data Length, and PEC.   @param[out] Status         The return status for the executed command.                              This is an optional parameter and may be NULL.                              RETURN_SUCCESS  		The SMBUS command was executed.                              RETURN_TIMEOUT  		A timeout occurred while executing the SMBUS command.                              RETURN_DEVICE_ERROR The request was not completed because a failure                              was recorded in the Host Status Register bit.  Device errors are a result                              of a transaction collision, illegal command field, unclaimed cycle                              (host initiated), or bus error (collision).                              RETURN_UNSUPPORTED  	The SMBus operation is not supported.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|S3SmBusQuickWrite
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
comment|/**   Executes an SMBUS receive byte command, and saves the value in the S3 script to be replayed   on S3 resume.    Executes an SMBUS receive byte command on the SMBUS device specified by SmBusAddress.   Only the SMBUS slave address field of SmBusAddress is required.   The byte received from the SMBUS is returned.   If Status is not NULL, then the status of the executed command is returned in Status.   If Command in SmBusAddress is not zero, then ASSERT().   If Length in SmBusAddress is not zero, then ASSERT().   If any reserved bits of SmBusAddress are set, then ASSERT().    @param[in]  SmBusAddress   The address that encodes the SMBUS Slave Address,                              SMBUS Command, SMBUS Data Length, and PEC.   @param[out] Status         The return status for the executed command.                              This is an optional parameter and may be NULL.                              RETURN_SUCCESS  		The SMBUS command was executed.                              RETURN_TIMEOUT  		A timeout occurred while executing the SMBUS command.                              RETURN_DEVICE_ERROR The request was not completed because a failure                              was recorded in the Host Status Register bit.  Device errors are a result                              of a transaction collision, illegal command field, unclaimed cycle                              (host initiated), or bus error (collision).                              RETURN_CRC_ERROR  The checksum is not correct (PEC is incorrect).                              RETURN_UNSUPPORTED  	The SMBus operation is not supported.    @return   The byte received from the SMBUS.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|S3SmBusReceiveByte
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
comment|/**   Executes an SMBUS send byte command, and saves the value in the S3 script to be replayed   on S3 resume.    Executes an SMBUS send byte command on the SMBUS device specified by SmBusAddress.   The byte specified by Value is sent.   Only the SMBUS slave address field of SmBusAddress is required.  Value is returned.   If Status is not NULL, then the status of the executed command is returned in Status.   If Command in SmBusAddress is not zero, then ASSERT().   If Length in SmBusAddress is not zero, then ASSERT().   If any reserved bits of SmBusAddress are set, then ASSERT().    @param[in]  SmBusAddress   The address that encodes the SMBUS Slave Address,                              SMBUS Command, SMBUS Data Length, and PEC.   @param[in]  Value          The 8-bit value to send.   @param[out] Status         The return status for the executed command.                              This is an optional parameter and may be NULL.                              RETURN_SUCCESS The SMBUS command was executed.                              RETURN_TIMEOUT A timeout occurred while executing the SMBUS command.                              RETURN_DEVICE_ERROR  The request was not completed because a failure                              was recorded in the Host Status Register bit.  Device errors are a result                              of a transaction collision, illegal command field, unclaimed cycle                              (host initiated), or bus errors (collisions).                              RETURN_CRC_ERROR  The checksum is not correct (PEC is incorrect).                              RETURN_UNSUPPORTED  The SMBus operation is not supported.    @return   The parameter of Value.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|S3SmBusSendByte
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
comment|/**   Executes an SMBUS read data byte command, and saves the value in the S3 script to be replayed   on S3 resume.    Executes an SMBUS read data byte command on the SMBUS device specified by SmBusAddress.   Only the SMBUS slave address and SMBUS command fields of SmBusAddress are required.   The 8-bit value read from the SMBUS is returned.   If Status is not NULL, then the status of the executed command is returned in Status.   If Length in SmBusAddress is not zero, then ASSERT().   If any reserved bits of SmBusAddress are set, then ASSERT().    @param[in]  SmBusAddress   The address that encodes the SMBUS Slave Address,                              SMBUS Command, SMBUS Data Length, and PEC.   @param[out] Status         The return status for the executed command.                              This is an optional parameter and may be NULL.                              RETURN_SUCCESS The SMBUS command was executed.                              RETURN_TIMEOUT A timeout occurred while executing the SMBUS command.                              RETURN_DEVICE_ERROR  The request was not completed because a failure                              was recorded in the Host Status Register bit.  Device errors are a result                              of a transaction collision, illegal command field, unclaimed cycle                              (host initiated), or bus error (collision).                              RETURN_CRC_ERROR  The checksum is not correct (PEC is incorrect).                              RETURN_UNSUPPORTED  The SMBus operation is not supported.    @return   The byte read from the SMBUS.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|S3SmBusReadDataByte
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
comment|/**   Executes an SMBUS write data byte command, and saves the value in the S3 script to be replayed   on S3 resume.    Executes an SMBUS write data byte command on the SMBUS device specified by SmBusAddress.   The 8-bit value specified by Value is written.   Only the SMBUS slave address and SMBUS command fields of SmBusAddress are required.   Value is returned.   If Status is not NULL, then the status of the executed command is returned in Status.   If Length in SmBusAddress is not zero, then ASSERT().   If any reserved bits of SmBusAddress are set, then ASSERT().    @param[in]  SmBusAddress   The address that encodes the SMBUS Slave Address,                              SMBUS Command, SMBUS Data Length, and PEC.   @param[in]  Value          The 8-bit value to write.   @param[out] Status         The return status for the executed command.                              This is an optional parameter and may be NULL.                              RETURN_SUCCESS The SMBUS command was executed.                              RETURN_TIMEOUT A timeout occurred while executing the SMBUS command.                              RETURN_DEVICE_ERROR  The request was not completed because a failure                              was recorded in the Host Status Register bit.  Device errors are a result                              of a transaction collision, illegal command field, unclaimed cycle                              (host initiated), or bus error (collision).                              RETURN_CRC_ERROR  The checksum is not correct (PEC is incorrect).                              RETURN_UNSUPPORTED  The SMBus operation is not supported.    @return   The parameter of Value.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|S3SmBusWriteDataByte
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
comment|/**   Executes an SMBUS read data word command, and saves the value in the S3 script to be replayed   on S3 resume.    Executes an SMBUS read data word command on the SMBUS device specified by SmBusAddress.   Only the SMBUS slave address and SMBUS command fields of SmBusAddress are required.   The 16-bit value read from the SMBUS is returned.   If Status is not NULL, then the status of the executed command is returned in Status.   If Length in SmBusAddress is not zero, then ASSERT().   If any reserved bits of SmBusAddress are set, then ASSERT().    @param[in]  SmBusAddress   The address that encodes the SMBUS Slave Address,                              SMBUS Command, SMBUS Data Length, and PEC.   @param[out] Status         The return status for the executed command.                              This is an optional parameter and may be NULL.                              RETURN_SUCCESS The SMBUS command was executed.                              RETURN_TIMEOUT A timeout occurred while executing the SMBUS command.                              RETURN_DEVICE_ERROR  The request was not completed because a failure                              was recorded in the Host Status Register bit.  Device errors are a result                              of a transaction collision, illegal command field, unclaimed cycle                              (host initiated), or bus error (collision).                              RETURN_CRC_ERROR  The checksum is not correct (PEC is incorrect).                              RETURN_UNSUPPORTED  The SMBus operation is not supported.    @return   The byte read from the SMBUS.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|S3SmBusReadDataWord
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
comment|/**   Executes an SMBUS write data word command, and saves the value in the S3 script to be replayed   on S3 resume.    Executes an SMBUS write data word command on the SMBUS device specified by SmBusAddress.   The 16-bit value specified by Value is written.   Only the SMBUS slave address and SMBUS command fields of SmBusAddress are required.   Value is returned.   If Status is not NULL, then the status of the executed command is returned in Status.   If Length in SmBusAddress is not zero, then ASSERT().   If any reserved bits of SmBusAddress are set, then ASSERT().    @param[in]  SmBusAddress   The address that encodes the SMBUS Slave Address,                              SMBUS Command, SMBUS Data Length, and PEC.   @param[in]  Value          The 16-bit value to write.   @param[out] Status         The return status for the executed command.                              This is an optional parameter and may be NULL.                              RETURN_SUCCESS The SMBUS command was executed.                              RETURN_TIMEOUT A timeout occurred while executing the SMBUS command.                              RETURN_DEVICE_ERROR  The request was not completed because a failure                              was recorded in the Host Status Register bit.  Device errors are a result                              of a transaction collision, illegal command field, unclaimed cycle                              (host initiated), or bus error (collision).                              RETURN_CRC_ERROR  The checksum is not correct (PEC is incorrect).                              RETURN_UNSUPPORTED  The SMBus operation is not supported.    @return   The parameter of Value.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|S3SmBusWriteDataWord
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
comment|/**   Executes an SMBUS process call command, and saves the value in the S3 script to be replayed   on S3 resume.    Executes an SMBUS process call command on the SMBUS device specified by SmBusAddress.   The 16-bit value specified by Value is written.   Only the SMBUS slave address and SMBUS command fields of SmBusAddress are required.   The 16-bit value returned by the process call command is returned.   If Status is not NULL, then the status of the executed command is returned in Status.   If Length in SmBusAddress is not zero, then ASSERT().   If any reserved bits of SmBusAddress are set, then ASSERT().    @param[in]  SmBusAddress   The address that encodes the SMBUS Slave Address,                              SMBUS Command, SMBUS Data Length, and PEC.   @param[in]  Value          The 16-bit value to write.   @param[out] Status         The return status for the executed command.                              This is an optional parameter and may be NULL.                              RETURN_SUCCESS The SMBUS command was executed.                              RETURN_TIMEOUT A timeout occurred while executing the SMBUS command.                              RETURN_DEVICE_ERROR  The request was not completed because a failure                              was recorded in the Host Status Register bit.  Device errors are a result                              of a transaction collision, illegal command field, unclaimed cycle                              (host initiated), or bus error (collision).                              RETURN_CRC_ERROR  The checksum is not correct (PEC is incorrect).                              RETURN_UNSUPPORTED  The SMBus operation is not supported.    @return   The 16-bit value returned by the process call command.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|S3SmBusProcessCall
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
comment|/**   Executes an SMBUS read block command, and saves the value in the S3 script to be replayed   on S3 resume.    Executes an SMBUS read block command on the SMBUS device specified by SmBusAddress.   Only the SMBUS slave address and SMBUS command fields of SmBusAddress are required.   Bytes are read from the SMBUS and stored in Buffer.   The number of bytes read is returned, and will never return a value larger than 32-bytes.   If Status is not NULL, then the status of the executed command is returned in Status.   It is the caller's responsibility to make sure Buffer is large enough for the total number of bytes read.   SMBUS supports a maximum transfer size of 32 bytes, so Buffer does not need to be any larger than 32 bytes.   If Length in SmBusAddress is not zero, then ASSERT().   If Buffer is NULL, then ASSERT().   If any reserved bits of SmBusAddress are set, then ASSERT().    @param[in]  SmBusAddress   The address that encodes the SMBUS Slave Address,                              SMBUS Command, SMBUS Data Length, and PEC.   @param[out] Buffer         The pointer to the buffer to store the bytes read from the SMBUS.   @param[out] Status         The return status for the executed command.                              This is an optional parameter and may be NULL.                              RETURN_SUCCESS The SMBUS command was executed.                              RETURN_TIMEOUT A timeout occurred while executing the SMBUS command.                              RETURN_DEVICE_ERROR  The request was not completed because a failure                              was recorded in the Host Status Register bit.  Device errors are a result                              of a transaction collision, illegal command field, unclaimed cycle                              (host initiated), or bus error (collision).                              RETURN_CRC_ERROR  The checksum is not correct (PEC is incorrect).                              RETURN_UNSUPPORTED  The SMBus operation is not supported.    @return   The number of bytes read.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|S3SmBusReadBlock
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
comment|/**   Executes an SMBUS write block command, and saves the value in the S3 script to be replayed   on S3 resume.    Executes an SMBUS write block command on the SMBUS device specified by SmBusAddress.   The SMBUS slave address, SMBUS command, and SMBUS length fields of SmBusAddress are required.   Bytes are written to the SMBUS from Buffer.   The number of bytes written is returned, and will never return a value larger than 32-bytes.   If Status is not NULL, then the status of the executed command is returned in Status.   If Length in SmBusAddress is zero or greater than 32, then ASSERT().   If Buffer is NULL, then ASSERT().   If any reserved bits of SmBusAddress are set, then ASSERT().    @param[in]  SmBusAddress   The address that encodes the SMBUS Slave Address,                              SMBUS Command, SMBUS Data Length, and PEC.   @param[out] Buffer         The pointer to the buffer to store the bytes read from the SMBUS.   @param[out] Status         The return status for the executed command.                              This is an optional parameter and may be NULL.                              RETURN_TIMEOUT A timeout occurred while executing the SMBUS command.                              RETURN_DEVICE_ERROR  The request was not completed because a failure                              was recorded in the Host Status Register bit.  Device errors are a result                              of a transaction collision, illegal command field, unclaimed cycle                              (host initiated), or bus error (collision).                              RETURN_CRC_ERROR  The checksum is not correct (PEC is incorrect).                              RETURN_UNSUPPORTED  The SMBus operation is not supported.    @return   The number of bytes written.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|S3SmBusWriteBlock
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
comment|/**   Executes an SMBUS block process call command, and saves the value in the S3 script to be replayed   on S3 resume.    Executes an SMBUS block process call command on the SMBUS device specified by SmBusAddress.   The SMBUS slave address, SMBUS command, and SMBUS length fields of SmBusAddress are required.   Bytes are written to the SMBUS from WriteBuffer.  Bytes are then read from the SMBUS into ReadBuffer.   If Status is not NULL, then the status of the executed command is returned in Status.   It is the caller's responsibility to make sure ReadBuffer is large enough for the total number of bytes read.   SMBUS supports a maximum transfer size of 32 bytes, so Buffer does not need to be any larger than 32 bytes.   If Length in SmBusAddress is zero or greater than 32, then ASSERT().   If WriteBuffer is NULL, then ASSERT().   If ReadBuffer is NULL, then ASSERT().   If any reserved bits of SmBusAddress are set, then ASSERT().    @param[in]  SmBusAddress   The address that encodes the SMBUS Slave Address,                              SMBUS Command, SMBUS Data Length, and PEC.   @param[in]  WriteBuffer    The pointer to the buffer of bytes to write to the SMBUS.   @param[out] ReadBuffer     The pointer to the buffer of bytes to read from the SMBUS.   @param[out] Status         The return status for the executed command.                              This is an optional parameter and may be NULL.                              RETURN_TIMEOUT A timeout occurred while executing the SMBUS command.                              RETURN_DEVICE_ERROR  The request was not completed because a failure                              was recorded in the Host Status Register bit.  Device errors are a result                              of a transaction collision, illegal command field, unclaimed cycle                              (host initiated), or bus error (collision).                              RETURN_CRC_ERROR  The checksum is not correct (PEC is incorrect).                              RETURN_UNSUPPORTED  The SMBus operation is not supported.    @return   The number of bytes written.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|S3SmBusBlockProcessCall
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

