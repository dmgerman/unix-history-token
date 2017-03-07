begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   I/O and MMIO Library Services that do I/O and also enable the I/O operation   to be replayed during an S3 resume. This library class maps directly on top   of the IoLib class.     Copyright (c) 2006 - 2012, Intel Corporation. All rights reserved.<BR>    This program and the accompanying materials   are licensed and made available under the terms and conditions   of the BSD License which accompanies this distribution.  The   full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__S3_IO_LIB_H__
end_ifndef

begin_define
define|#
directive|define
name|__S3_IO_LIB_H__
end_define

begin_comment
comment|/**   Reads an 8-bit I/O port and saves the value in the S3 script to be replayed   on S3 resume.    Reads the 8-bit I/O port specified by Port. The 8-bit read value is returned.   This function must guarantee that all I/O read and write operations are   serialized.    If 8-bit I/O port operations are not supported, then ASSERT().    @param[in]  Port   The I/O port to read.    @return   The value read.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|S3IoRead8
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes an 8-bit I/O port, and saves the value in the S3 script to be replayed   on S3 resume.    Writes the 8-bit I/O port specified by Port with the value specified by Value   and returns Value. This function must guarantee that all I/O read and write   operations are serialized.    If 8-bit I/O port operations are not supported, then ASSERT().    @param[in]  Port    The I/O port to write.   @param[in]  Value   The value to write to the I/O port.    @return   The value written the I/O port.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|S3IoWrite8
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINT8
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads an 8-bit I/O port, performs a bitwise OR, writes the   result back to the 8-bit I/O port, and saves the value in the S3 script to be   replayed on S3 resume.    Reads the 8-bit I/O port specified by Port, performs a bitwise OR   between the read result and the value specified by OrData, and writes the   result to the 8-bit I/O port specified by Port. The value written to the I/O   port is returned. This function must guarantee that all I/O read and write   operations are serialized.    If 8-bit I/O port operations are not supported, then ASSERT().    @param[in]  Port     The I/O port to write.   @param[in]  OrData   The value to OR with the read value from the I/O port.    @return   The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|S3IoOr8
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINT8
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads an 8-bit I/O port, performs a bitwise AND, writes the result back   to the 8-bit I/O port, and saves the value in the S3 script to be replayed   on S3 resume.    Reads the 8-bit I/O port specified by Port, performs a bitwise AND between   the read result and the value specified by AndData, and writes the result to   the 8-bit I/O port specified by Port. The value written to the I/O port is   returned. This function must guarantee that all I/O read and write operations   are serialized.    If 8-bit I/O port operations are not supported, then ASSERT().    @param[in]  Port      The I/O port to write.   @param[in]  AndData   The value to AND with the read value from the I/O port.    @return   The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|S3IoAnd8
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINT8
name|AndData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads an 8-bit I/O port, performs a bitwise AND followed by a bitwise   inclusive OR, writes the result back to the 8-bit I/O port, and saves    the value in the S3 script to be replayed on S3 resume.    Reads the 8-bit I/O port specified by Port, performs a bitwise AND between   the read result and the value specified by AndData, performs a bitwise OR   between the result of the AND operation and the value specified by OrData,   and writes the result to the 8-bit I/O port specified by Port. The value   written to the I/O port is returned. This function must guarantee that all   I/O read and write operations are serialized.    If 8-bit I/O port operations are not supported, then ASSERT().    @param[in]  Port      The I/O port to write.   @param[in]  AndData   The value to AND with the read value from the I/O port.   @param[in]  OrData    The value to OR with the result of the AND operation.    @return   The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|S3IoAndThenOr8
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINT8
name|AndData
parameter_list|,
name|IN
name|UINT8
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field of an I/O register, and saves the value in the S3 script to   be replayed on S3 resume.    Reads the bit field in an 8-bit I/O register. The bit field is specified by   the StartBit and the EndBit. The value of the bit field is returned.    If 8-bit I/O port operations are not supported, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().    @param[in]  Port       The I/O port to read.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..7.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..7.    @return   The value read.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|S3IoBitFieldRead8
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a bit field to an I/O register and saves the value in the S3 script to   be replayed on S3 resume.    Writes Value to the bit field of the I/O register. The bit field is specified   by the StartBit and the EndBit. All other bits in the destination I/O   register are preserved. The value written to the I/O port is returned.    Remaining bits in Value are stripped.    If 8-bit I/O port operations are not supported, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If Value is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in]  Port       The I/O port to write.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..7.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..7.   @param[in]  Value      New value of the bit field.    @return   The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|S3IoBitFieldWrite8
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT8
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in an 8-bit port, performs a bitwise OR, writes the   result back to the bit field in the 8-bit port, and saves the value in the    S3 script to be replayed on S3 resume.    Reads the 8-bit I/O port specified by Port, performs a bitwise OR   between the read result and the value specified by OrData, and writes the   result to the 8-bit I/O port specified by Port. The value written to the I/O   port is returned. This function must guarantee that all I/O read and write   operations are serialized. Extra left bits in OrData are stripped.    If 8-bit I/O port operations are not supported, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in]  Port       The I/O port to write.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..7.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..7.   @param[in]  OrData     The value to OR with the read value from the I/O port.    @return   The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|S3IoBitFieldOr8
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT8
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in an 8-bit port, performs a bitwise AND, writes the   result back to the bit field in the 8-bit port, and saves the value in the    S3 script to be replayed on S3 resume.    Reads the 8-bit I/O port specified by Port, performs a bitwise AND between   the read result and the value specified by AndData, and writes the result to   the 8-bit I/O port specified by Port. The value written to the I/O port is   returned. This function must guarantee that all I/O read and write operations   are serialized. Extra left bits in AndData are stripped.    If 8-bit I/O port operations are not supported, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in]  Port       The I/O port to write.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..7.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..7.   @param[in]  AndData    The value to AND with the read value from the I/O port.    @return   The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|S3IoBitFieldAnd8
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT8
name|AndData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in an 8-bit port, performs a bitwise AND followed by a   bitwise OR, writes the result back to the bit field in the   8-bit port, and saves the value in the S3 script to be replayed on S3 resume.    Reads the 8-bit I/O port specified by Port, performs a bitwise AND followed   by a bitwise OR between the read result and the value specified by   AndData, and writes the result to the 8-bit I/O port specified by Port. The   value written to the I/O port is returned. This function must guarantee that   all I/O read and write operations are serialized. Extra left bits in both   AndData and OrData are stripped.    If 8-bit I/O port operations are not supported, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in]  Port       The I/O port to write.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..7.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..7.   @param[in]  AndData    The value to AND with the read value from the I/O port.   @param[in]  OrData     The value to OR with the result of the AND operation.    @return   The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|S3IoBitFieldAndThenOr8
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT8
name|AndData
parameter_list|,
name|IN
name|UINT8
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 16-bit I/O port, and saves the value in the S3 script to be replayed   on S3 resume.    Reads the 16-bit I/O port specified by Port. The 16-bit read value is returned.   This function must guarantee that all I/O read and write operations are   serialized.    If 16-bit I/O port operations are not supported, then ASSERT().    @param[in]  Port   The I/O port to read.    @return   The value read.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|S3IoRead16
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a 16-bit I/O port, and saves the value in the S3 script to be replayed   on S3 resume.    Writes the 16-bit I/O port specified by Port with the value specified by Value   and returns Value. This function must guarantee that all I/O read and write   operations are serialized.    If 16-bit I/O port operations are not supported, then ASSERT().    @param[in]  Port    The I/O port to write.   @param[in]  Value   The value to write to the I/O port.    @return   The value written the I/O port.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|S3IoWrite16
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINT16
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 16-bit I/O port, performs a bitwise OR, writes the   result back to the 16-bit I/O port, and saves the value in the S3 script to    be replayed on S3 resume.    Reads the 16-bit I/O port specified by Port, performs a bitwise OR   between the read result and the value specified by OrData, and writes the   result to the 16-bit I/O port specified by Port. The value written to the I/O   port is returned. This function must guarantee that all I/O read and write   operations are serialized.    If 16-bit I/O port operations are not supported, then ASSERT().    @param[in]  Port     The I/O port to write.   @param[in]  OrData   The value to OR with the read value from the I/O port.    @return   The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|S3IoOr16
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINT16
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 16-bit I/O port, performs a bitwise AND, writes the result back   to the 16-bit I/O port , and saves the value in the S3 script to be replayed   on S3 resume.    Reads the 16-bit I/O port specified by Port, performs a bitwise AND between   the read result and the value specified by AndData, and writes the result to   the 16-bit I/O port specified by Port. The value written to the I/O port is   returned. This function must guarantee that all I/O read and write operations   are serialized.    If 16-bit I/O port operations are not supported, then ASSERT().    @param[in]  Port      The I/O port to write.   @param[in]  AndData   The value to AND with the read value from the I/O port.    @return   The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|S3IoAnd16
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINT16
name|AndData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 16-bit I/O port, performs a bitwise AND followed by a bitwise   inclusive OR, writes the result back to the 16-bit I/O port, and saves   the value in the S3 script to be replayed on S3 resume.    Reads the 16-bit I/O port specified by Port, performs a bitwise AND between   the read result and the value specified by AndData, performs a bitwise OR   between the result of the AND operation and the value specified by OrData,   and writes the result to the 16-bit I/O port specified by Port. The value   written to the I/O port is returned. This function must guarantee that all   I/O read and write operations are serialized.    If 16-bit I/O port operations are not supported, then ASSERT().    @param[in]  Port      The I/O port to write.   @param[in]  AndData   The value to AND with the read value from the I/O port.   @param[in]  OrData    The value to OR with the result of the AND operation.    @return   The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|S3IoAndThenOr16
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINT16
name|AndData
parameter_list|,
name|IN
name|UINT16
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field of an I/O register saves the value in the S3 script to be   replayed on S3 resume.    Reads the bit field in a 16-bit I/O register. The bit field is specified by   the StartBit and the EndBit. The value of the bit field is returned.    If 16-bit I/O port operations are not supported, then ASSERT().   If StartBit is greater than 15, then ASSERT().   If EndBit is greater than 15, then ASSERT().   If EndBit is less than StartBit, then ASSERT().    @param[in]  Port       The I/O port to read.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..15.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..15.    @return   The value read.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|S3IoBitFieldRead16
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a bit field to an I/O register, and saves the value in the S3 script    to be replayed on S3 resume.    Writes Value to the bit field of the I/O register. The bit field is specified   by the StartBit and the EndBit. All other bits in the destination I/O   register are preserved. The value written to the I/O port is returned. Extra   left bits in Value are stripped.    If 16-bit I/O port operations are not supported, then ASSERT().   If StartBit is greater than 15, then ASSERT().   If EndBit is greater than 15, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If Value is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in]  Port       The I/O port to write.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..15.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..15.   @param[in]  Value      New value of the bit field.    @return   The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|S3IoBitFieldWrite16
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT16
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in a 16-bit port, performs a bitwise OR, writes the   result back to the bit field in the 16-bit port, and saves the value in the    S3 script to be replayed on S3 resume.    Reads the 16-bit I/O port specified by Port, performs a bitwise OR   between the read result and the value specified by OrData, and writes the   result to the 16-bit I/O port specified by Port. The value written to the I/O   port is returned. This function must guarantee that all I/O read and write   operations are serialized. Extra left bits in OrData are stripped.    If 16-bit I/O port operations are not supported, then ASSERT().   If StartBit is greater than 15, then ASSERT().   If EndBit is greater than 15, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in]  Port       The I/O port to write.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..15.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..15.   @param[in]  OrData     The value to OR with the read value from the I/O port.    @return   The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|S3IoBitFieldOr16
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT16
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in a 16-bit port, performs a bitwise AND, writes the   result back to the bit field in the 16-bit port, and saves the value in the    S3 script to be replayed on S3 resume.    Reads the 16-bit I/O port specified by Port, performs a bitwise AND between   the read result and the value specified by AndData, and writes the result to   the 16-bit I/O port specified by Port. The value written to the I/O port is   returned. This function must guarantee that all I/O read and write operations   are serialized. Extra left bits in AndData are stripped.    If 16-bit I/O port operations are not supported, then ASSERT().   If StartBit is greater than 15, then ASSERT().   If EndBit is greater than 15, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in]  Port       The I/O port to write.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..15.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..15.   @param[in]  AndData    The value to AND with the read value from the I/O port.    @return   The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|S3IoBitFieldAnd16
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT16
name|AndData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in a 16-bit port, performs a bitwise AND followed by a   bitwise OR, writes the result back to the bit field in the   16-bit port, and saves the value in the S3 script to be replayed on S3    resume.    Reads the 16-bit I/O port specified by Port, performs a bitwise AND followed   by a bitwise OR between the read result and the value specified by   AndData, and writes the result to the 16-bit I/O port specified by Port. The   value written to the I/O port is returned. This function must guarantee that   all I/O read and write operations are serialized. Extra left bits in both   AndData and OrData are stripped.    If 16-bit I/O port operations are not supported, then ASSERT().   If StartBit is greater than 15, then ASSERT().   If EndBit is greater than 15, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in]  Port       The I/O port to write.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..15.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..15.   @param[in]  AndData    The value to AND with the read value from the I/O port.   @param[in]  OrData     The value to OR with the result of the AND operation.    @return   The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|S3IoBitFieldAndThenOr16
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT16
name|AndData
parameter_list|,
name|IN
name|UINT16
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 32-bit I/O port, and saves the value in the S3 script to be replayed   on S3 resume.    Reads the 32-bit I/O port specified by Port. The 32-bit read value is returned.   This function must guarantee that all I/O read and write operations are   serialized.    If 32-bit I/O port operations are not supported, then ASSERT().    @param[in]  Port   The I/O port to read.    @return   The value read.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|S3IoRead32
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a 32-bit I/O port, and saves the value in the S3 script to be replayed   on S3 resume.    Writes the 32-bit I/O port specified by Port with the value specified by Value   and returns Value. This function must guarantee that all I/O read and write   operations are serialized.    If 32-bit I/O port operations are not supported, then ASSERT().    @param[in]  Port    The I/O port to write.   @param[in]  Value   The value to write to the I/O port.    @return   The value written the I/O port.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|S3IoWrite32
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINT32
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 32-bit I/O port, performs a bitwise OR, writes the   result back to the 32-bit I/O port, and saves the value in the S3 script to    be replayed on S3 resume.    Reads the 32-bit I/O port specified by Port, performs a bitwise OR   between the read result and the value specified by OrData, and writes the   result to the 32-bit I/O port specified by Port. The value written to the I/O   port is returned. This function must guarantee that all I/O read and write   operations are serialized.    If 32-bit I/O port operations are not supported, then ASSERT().    @param[in]  Port     The I/O port to write.   @param[in]  OrData   The value to OR with the read value from the I/O port.    @return   The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|S3IoOr32
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINT32
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 32-bit I/O port, performs a bitwise AND, writes the result back   to the 32-bit I/O port, and saves the value in the S3 script to be replayed   on S3 resume.    Reads the 32-bit I/O port specified by Port, performs a bitwise AND between   the read result and the value specified by AndData, and writes the result to   the 32-bit I/O port specified by Port. The value written to the I/O port is   returned. This function must guarantee that all I/O read and write operations   are serialized.    If 32-bit I/O port operations are not supported, then ASSERT().    @param[in]  Port      The I/O port to write.   @param[in]  AndData   The value to AND with the read value from the I/O port.    @return   The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|S3IoAnd32
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINT32
name|AndData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 32-bit I/O port, performs a bitwise AND followed by a bitwise   inclusive OR, writes the result back to the 32-bit I/O port, and saves    the value in the S3 script to be replayed on S3 resume.    Reads the 32-bit I/O port specified by Port, performs a bitwise AND between   the read result and the value specified by AndData, performs a bitwise OR   between the result of the AND operation and the value specified by OrData,   and writes the result to the 32-bit I/O port specified by Port. The value   written to the I/O port is returned. This function must guarantee that all   I/O read and write operations are serialized.    If 32-bit I/O port operations are not supported, then ASSERT().    @param[in]  Port      The I/O port to write.   @param[in]  AndData   The value to AND with the read value from the I/O port.   @param[in]  OrData    The value to OR with the result of the AND operation.    @return   The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|S3IoAndThenOr32
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINT32
name|AndData
parameter_list|,
name|IN
name|UINT32
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field of an I/O register, and saves the value in the S3 script to   be replayed on S3 resume.    Reads the bit field in a 32-bit I/O register. The bit field is specified by   the StartBit and the EndBit. The value of the bit field is returned.    If 32-bit I/O port operations are not supported, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().    @param[in]  Port       The I/O port to read.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..31.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..31.    @return   The value read.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|S3IoBitFieldRead32
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a bit field to an I/O register, and saves the value in the S3 script to   be replayed on S3 resume.    Writes Value to the bit field of the I/O register. The bit field is specified   by the StartBit and the EndBit. All other bits in the destination I/O   register are preserved. The value written to the I/O port is returned. Extra   left bits in Value are stripped.    If 32-bit I/O port operations are not supported, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If Value is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in]  Port       The I/O port to write.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..31.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..31.   @param[in]  Value      New value of the bit field.    @return   The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|S3IoBitFieldWrite32
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT32
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in a 32-bit port, performs a bitwise OR, writes the   result back to the bit field in the 32-bit port, and saves the value in the    S3 script to be replayed on S3 resume.    Reads the 32-bit I/O port specified by Port, performs a bitwise OR   between the read result and the value specified by OrData, and writes the   result to the 32-bit I/O port specified by Port. The value written to the I/O   port is returned. This function must guarantee that all I/O read and write   operations are serialized. Extra left bits in OrData are stripped.    If 32-bit I/O port operations are not supported, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in]  Port       The I/O port to write.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..31.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..31.   @param[in]  OrData     The value to OR with the read value from the I/O port.    @return   The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|S3IoBitFieldOr32
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT32
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in a 32-bit port, performs a bitwise AND, writes the   result back to the bit field in the 32-bit port, and saves the value in the    S3 script to be replayed on S3 resume.    Reads the 32-bit I/O port specified by Port, performs a bitwise AND between   the read result and the value specified by AndData, and writes the result to   the 32-bit I/O port specified by Port. The value written to the I/O port is   returned. This function must guarantee that all I/O read and write operations   are serialized. Extra left bits in AndData are stripped.    If 32-bit I/O port operations are not supported, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in]  Port       The I/O port to write.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..31.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..31.   @param[in]  AndData    The value to AND with the read value from the I/O port.    @return   The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|S3IoBitFieldAnd32
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT32
name|AndData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in a 32-bit port, performs a bitwise AND followed by a   bitwise OR, writes the result back to the bit field in the   32-bit port, and saves the value in the S3 script to be replayed on S3    resume.    Reads the 32-bit I/O port specified by Port, performs a bitwise AND followed   by a bitwise OR between the read result and the value specified by   AndData, and writes the result to the 32-bit I/O port specified by Port. The   value written to the I/O port is returned. This function must guarantee that   all I/O read and write operations are serialized. Extra left bits in both   AndData and OrData are stripped.    If 32-bit I/O port operations are not supported, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in]  Port       The I/O port to write.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..31.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..31.   @param[in]  AndData    The value to AND with the read value from the I/O port.   @param[in]  OrData     The value to OR with the result of the AND operation.    @return   The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|S3IoBitFieldAndThenOr32
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT32
name|AndData
parameter_list|,
name|IN
name|UINT32
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 64-bit I/O port, and saves the value in the S3 script to be replayed   on S3 resume.    Reads the 64-bit I/O port specified by Port. The 64-bit read value is returned.   This function must guarantee that all I/O read and write operations are   serialized.    If 64-bit I/O port operations are not supported, then ASSERT().    @param[in]  Port   The I/O port to read.    @return   The value read.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|S3IoRead64
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a 64-bit I/O port, and saves the value in the S3 script to be replayed   on S3 resume.    Writes the 64-bit I/O port specified by Port with the value specified by Value   and returns Value. This function must guarantee that all I/O read and write   operations are serialized.    If 64-bit I/O port operations are not supported, then ASSERT().    @param[in]  Port    The I/O port to write.   @param[in]  Value   The value to write to the I/O port.    @return   The value written to the I/O port.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|S3IoWrite64
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 64-bit I/O port, performs a bitwise OR, writes the   result back to the 64-bit I/O port, and saves the value in the S3 script to    be replayed on S3 resume.    Reads the 64-bit I/O port specified by Port, performs a bitwise OR   between the read result and the value specified by OrData, and writes the   result to the 64-bit I/O port specified by Port. The value written to the I/O   port is returned. This function must guarantee that all I/O read and write   operations are serialized.    If 64-bit I/O port operations are not supported, then ASSERT().    @param[in]  Port     The I/O port to write.   @param[in]  OrData   The value to OR with the read value from the I/O port.    @return   The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|S3IoOr64
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINT64
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 64-bit I/O port, performs a bitwise AND, writes the result back   to the 64-bit I/O port, and saves the value in the S3 script to be replayed   on S3 resume.    Reads the 64-bit I/O port specified by Port, performs a bitwise AND between   the read result and the value specified by AndData, and writes the result to   the 64-bit I/O port specified by Port. The value written to the I/O port is   returned. This function must guarantee that all I/O read and write operations   are serialized.    If 64-bit I/O port operations are not supported, then ASSERT().    @param[in]  Port      The I/O port to write.   @param[in]  AndData   The value to AND with the read value from the I/O port.    @return   The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|S3IoAnd64
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINT64
name|AndData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 64-bit I/O port, performs a bitwise AND followed by a bitwise   inclusive OR, writes the result back to the 64-bit I/O port, and saves   the value in the S3 script to be replayed on S3 resume.    Reads the 64-bit I/O port specified by Port, performs a bitwise AND between   the read result and the value specified by AndData, performs a bitwise OR   between the result of the AND operation and the value specified by OrData,   and writes the result to the 64-bit I/O port specified by Port. The value   written to the I/O port is returned. This function must guarantee that all   I/O read and write operations are serialized.    If 64-bit I/O port operations are not supported, then ASSERT().    @param[in]  Port      The I/O port to write.   @param[in]  AndData   The value to AND with the read value from the I/O port.   @param[in]  OrData    The value to OR with the result of the AND operation.    @return   The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|S3IoAndThenOr64
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINT64
name|AndData
parameter_list|,
name|IN
name|UINT64
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field of an I/O register, and saves the value in the S3 script to   be replayed on S3 resume.    Reads the bit field in a 64-bit I/O register. The bit field is specified by   the StartBit and the EndBit. The value of the bit field is returned.    If 64-bit I/O port operations are not supported, then ASSERT().   If StartBit is greater than 63, then ASSERT().   If EndBit is greater than 63, then ASSERT().   If EndBit is less than StartBit, then ASSERT().    @param[in]  Port       The I/O port to read.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..63.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..63.    @return   The value read.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|S3IoBitFieldRead64
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a bit field to an I/O register, and saves the value in the S3 script to   be replayed on S3 resume.    Writes Value to the bit field of the I/O register. The bit field is specified   by the StartBit and the EndBit. All other bits in the destination I/O   register are preserved. The value written to the I/O port is returned. Extra   left bits in Value are stripped.    If 64-bit I/O port operations are not supported, then ASSERT().   If StartBit is greater than 63, then ASSERT().   If EndBit is greater than 63, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If Value is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in]  Port       The I/O port to write.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..63.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..63.   @param[in]  Value      New value of the bit field.    @return   The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|S3IoBitFieldWrite64
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in a 64-bit port, performs a bitwise OR, writes the   result back to the bit field in the 64-bit port, and saves the value in the    S3 script to be replayed on S3 resume.    Reads the 64-bit I/O port specified by Port, performs a bitwise OR   between the read result and the value specified by OrData, and writes the   result to the 64-bit I/O port specified by Port. The value written to the I/O   port is returned. This function must guarantee that all I/O read and write   operations are serialized. Extra left bits in OrData are stripped.    If 64-bit I/O port operations are not supported, then ASSERT().   If StartBit is greater than 63, then ASSERT().   If EndBit is greater than 63, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in]  Port       The I/O port to write.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..63.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..63.   @param[in]  OrData     The value to OR with the read value from the I/O port.    @return   The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|S3IoBitFieldOr64
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT64
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in a 64-bit port, performs a bitwise AND, writes the   result back to the bit field in the 64-bit port, and saves the value in the    S3 script to be replayed on S3 resume.    Reads the 64-bit I/O port specified by Port, performs a bitwise AND between   the read result and the value specified by AndData, and writes the result to   the 64-bit I/O port specified by Port. The value written to the I/O port is   returned. This function must guarantee that all I/O read and write operations   are serialized. Extra left bits in AndData are stripped.    If 64-bit I/O port operations are not supported, then ASSERT().   If StartBit is greater than 63, then ASSERT().   If EndBit is greater than 63, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in]  Port       The I/O port to write.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..63.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..63.   @param[in]  AndData    The value to AND with the read value from the I/O port.    @return   The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|S3IoBitFieldAnd64
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT64
name|AndData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in a 64-bit port, performs a bitwise AND followed by a   bitwise OR, writes the result back to the bit field in the   64-bit port, and saves the value in the S3 script to be replayed on S3    resume.    Reads the 64-bit I/O port specified by Port, performs a bitwise AND followed   by a bitwise OR between the read result and the value specified by   AndData, and writes the result to the 64-bit I/O port specified by Port. The   value written to the I/O port is returned. This function must guarantee that   all I/O read and write operations are serialized. Extra left bits in both   AndData and OrData are stripped.    If 64-bit I/O port operations are not supported, then ASSERT().   If StartBit is greater than 63, then ASSERT().   If EndBit is greater than 63, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in]  Port       The I/O port to write.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..63.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..63.   @param[in]  AndData    The value to AND with the read value from the I/O port.   @param[in]  OrData     The value to OR with the result of the AND operation.    @return   The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|S3IoBitFieldAndThenOr64
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT64
name|AndData
parameter_list|,
name|IN
name|UINT64
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads an 8-bit MMIO register, and saves the value in the S3 script to be    replayed on S3 resume.    Reads the 8-bit MMIO register specified by Address. The 8-bit read value is   returned. This function must guarantee that all MMIO read and write   operations are serialized.    If 8-bit MMIO register operations are not supported, then ASSERT().    @param[in]  Address   The MMIO register to read.    @return   The value read.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|S3MmioRead8
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes an 8-bit MMIO register, and saves the value in the S3 script to be    replayed on S3 resume.    Writes the 8-bit MMIO register specified by Address with the value specified   by Value and returns Value. This function must guarantee that all MMIO read   and write operations are serialized.    If 8-bit MMIO register operations are not supported, then ASSERT().    @param[in]  Address   The MMIO register to write.   @param[in]  Value     The value to write to the MMIO register.    @return   The value written the MMIO register.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|S3MmioWrite8
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINT8
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads an 8-bit MMIO register, performs a bitwise OR, writes the   result back to the 8-bit MMIO register, and saves the value in the S3 script    to be replayed on S3 resume.    Reads the 8-bit MMIO register specified by Address, performs a bitwise   inclusive OR between the read result and the value specified by OrData, and   writes the result to the 8-bit MMIO register specified by Address. The value   written to the MMIO register is returned. This function must guarantee that   all MMIO read and write operations are serialized.    If 8-bit MMIO register operations are not supported, then ASSERT().    @param[in]  Address   The MMIO register to write.   @param[in]  OrData    The value to OR with the read value from the MMIO register.    @return   The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|S3MmioOr8
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINT8
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads an 8-bit MMIO register, performs a bitwise AND, writes the result   back to the 8-bit MMIO register, and saves the value in the S3 script to be    replayed on S3 resume.    Reads the 8-bit MMIO register specified by Address, performs a bitwise AND   between the read result and the value specified by AndData, and writes the   result to the 8-bit MMIO register specified by Address. The value written to   the MMIO register is returned. This function must guarantee that all MMIO   read and write operations are serialized.    If 8-bit MMIO register operations are not supported, then ASSERT().    @param[in]  Address   The MMIO register to write.   @param[in]  AndData   The value to AND with the read value from the MMIO register.    @return   The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|S3MmioAnd8
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINT8
name|AndData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads an 8-bit MMIO register, performs a bitwise AND followed by a bitwise   inclusive OR, writes the result back to the 8-bit MMIO register, and saves    the value in the S3 script to be replayed on S3 resume.    Reads the 8-bit MMIO register specified by Address, performs a bitwise AND   between the read result and the value specified by AndData, performs a   bitwise OR between the result of the AND operation and the value specified by   OrData, and writes the result to the 8-bit MMIO register specified by   Address. The value written to the MMIO register is returned. This function   must guarantee that all MMIO read and write operations are serialized.    If 8-bit MMIO register operations are not supported, then ASSERT().    @param[in]  Address   The MMIO register to write.   @param[in]  AndData   The value to AND with the read value from the MMIO register.   @param[in]  OrData    The value to OR with the result of the AND operation.    @return   The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|S3MmioAndThenOr8
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINT8
name|AndData
parameter_list|,
name|IN
name|UINT8
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field of a MMIO register, and saves the value in the S3 script to   be replayed on S3 resume.    Reads the bit field in an 8-bit MMIO register. The bit field is specified by   the StartBit and the EndBit. The value of the bit field is returned.    If 8-bit MMIO register operations are not supported, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().    @param[in]  Address    MMIO register to read.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..7.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..7.    @return   The value read.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|S3MmioBitFieldRead8
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a bit field to an MMIO register, and saves the value in the S3 script to   be replayed on S3 resume.    Writes Value to the bit field of the MMIO register. The bit field is   specified by the StartBit and the EndBit. All other bits in the destination   MMIO register are preserved. The new value of the 8-bit register is returned.    If 8-bit MMIO register operations are not supported, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If Value is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in]  Address    The MMIO register to write.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..7.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..7.   @param[in]  Value      New value of the bit field.    @return   The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|S3MmioBitFieldWrite8
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT8
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in an 8-bit MMIO register, performs a bitwise OR,    writes the result back to the bit field in the 8-bit MMIO register, and saves   the value in the S3 script to be replayed on S3 resume.    Reads the 8-bit MMIO register specified by Address, performs a bitwise   inclusive OR between the read result and the value specified by OrData, and   writes the result to the 8-bit MMIO register specified by Address. The value   written to the MMIO register is returned. This function must guarantee that   all MMIO read and write operations are serialized. Extra left bits in OrData   are stripped.    If 8-bit MMIO register operations are not supported, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in]  Address    The MMIO register to write.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..7.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..7.   @param[in]  OrData     The value to OR with the read value from the MMIO register.    @return   The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|S3MmioBitFieldOr8
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT8
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in an 8-bit MMIO register, performs a bitwise AND, and   writes the result back to the bit field in the 8-bit MMIO register, and saves   the value in the S3 script to be replayed on S3 resume.    Reads the 8-bit MMIO register specified by Address, performs a bitwise AND   between the read result and the value specified by AndData, and writes the   result to the 8-bit MMIO register specified by Address. The value written to   the MMIO register is returned. This function must guarantee that all MMIO   read and write operations are serialized. Extra left bits in AndData are   stripped.    If 8-bit MMIO register operations are not supported, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in]  Address    The MMIO register to write.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..7.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..7.   @param[in]  AndData    The value to AND with the read value from the MMIO register.    @return   The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|S3MmioBitFieldAnd8
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT8
name|AndData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in an 8-bit MMIO register, performs a bitwise AND followed   by a bitwise OR, writes the result back to the bit field in the   8-bit MMIO register, and saves the value in the S3 script to be replayed   on S3 resume.    Reads the 8-bit MMIO register specified by Address, performs a bitwise AND   followed by a bitwise OR between the read result and the value   specified by AndData, and writes the result to the 8-bit MMIO register   specified by Address. The value written to the MMIO register is returned.   This function must guarantee that all MMIO read and write operations are   serialized. Extra left bits in both AndData and OrData are stripped.    If 8-bit MMIO register operations are not supported, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in]  Address    The MMIO register to write.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..7.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..7.   @param[in]  AndData    The value to AND with the read value from the MMIO register.   @param[in]  OrData     The value to OR with the result of the AND operation.    @return   The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|S3MmioBitFieldAndThenOr8
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT8
name|AndData
parameter_list|,
name|IN
name|UINT8
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 16-bit MMIO register, and saves the value in the S3 script to be replayed   on S3 resume.    Reads the 16-bit MMIO register specified by Address. The 16-bit read value is   returned. This function must guarantee that all MMIO read and write   operations are serialized.    If 16-bit MMIO register operations are not supported, then ASSERT().    @param[in]  Address   The MMIO register to read.    @return   The value read.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|S3MmioRead16
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a 16-bit MMIO register, and saves the value in the S3 script to be replayed   on S3 resume.    Writes the 16-bit MMIO register specified by Address with the value specified   by Value and returns Value. This function must guarantee that all MMIO read   and write operations are serialized, and saves the value in the S3 script to be   replayed on S3 resume.    If 16-bit MMIO register operations are not supported, then ASSERT().    @param[in]  Address   The MMIO register to write.   @param[in]  Value     The value to write to the MMIO register.    @return   The value written the MMIO register.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|S3MmioWrite16
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINT16
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 16-bit MMIO register, performs a bitwise OR, writes the   result back to the 16-bit MMIO register, and saves the value in the S3 script    to be replayed on S3 resume.    Reads the 16-bit MMIO register specified by Address, performs a bitwise   inclusive OR between the read result and the value specified by OrData, and   writes the result to the 16-bit MMIO register specified by Address. The value   written to the MMIO register is returned. This function must guarantee that   all MMIO read and write operations are serialized.    If 16-bit MMIO register operations are not supported, then ASSERT().    @param[in]  Address   The MMIO register to write.   @param[in]  OrData    The value to OR with the read value from the MMIO register.    @return   The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|S3MmioOr16
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINT16
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 16-bit MMIO register, performs a bitwise AND, writes the result   back to the 16-bit MMIO register, and saves the value in the S3 script to be    replayed on S3 resume.    Reads the 16-bit MMIO register specified by Address, performs a bitwise AND   between the read result and the value specified by AndData, and writes the   result to the 16-bit MMIO register specified by Address. The value written to   the MMIO register is returned. This function must guarantee that all MMIO   read and write operations are serialized.    If 16-bit MMIO register operations are not supported, then ASSERT().    @param[in]  Address   The MMIO register to write.   @param[in]  AndData   The value to AND with the read value from the MMIO register.    @return   The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|S3MmioAnd16
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINT16
name|AndData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 16-bit MMIO register, performs a bitwise AND followed by a bitwise   inclusive OR, writes the result back to the 16-bit MMIO register, and    saves the value in the S3 script to be replayed on S3 resume.    Reads the 16-bit MMIO register specified by Address, performs a bitwise AND   between the read result and the value specified by AndData, performs a   bitwise OR between the result of the AND operation and the value specified by   OrData, and writes the result to the 16-bit MMIO register specified by   Address. The value written to the MMIO register is returned. This function   must guarantee that all MMIO read and write operations are serialized.    If 16-bit MMIO register operations are not supported, then ASSERT().    @param[in]  Address   The MMIO register to write.   @param[in]  AndData   The value to AND with the read value from the MMIO register.   @param[in]  OrData    The value to OR with the result of the AND operation.    @return   The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|S3MmioAndThenOr16
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINT16
name|AndData
parameter_list|,
name|IN
name|UINT16
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field of a MMIO register, and saves the value in the S3 script to   be replayed on S3 resume.    Reads the bit field in a 16-bit MMIO register. The bit field is specified by   the StartBit and the EndBit. The value of the bit field is returned.    If 16-bit MMIO register operations are not supported, then ASSERT().   If StartBit is greater than 15, then ASSERT().   If EndBit is greater than 15, then ASSERT().   If EndBit is less than StartBit, then ASSERT().    @param[in]  Address    MMIO register to read.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..15.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..15.    @return   The value read.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|S3MmioBitFieldRead16
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a bit field to a MMIO register, and saves the value in the S3 script to   be replayed on S3 resume.    Writes Value to the bit field of the MMIO register. The bit field is   specified by the StartBit and the EndBit. All other bits in the destination   MMIO register are preserved. The new value of the 16-bit register is returned.    If 16-bit MMIO register operations are not supported, then ASSERT().   If StartBit is greater than 15, then ASSERT().   If EndBit is greater than 15, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If Value is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in]  Address    The MMIO register to write.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..15.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..15.   @param[in]  Value      New value of the bit field.    @return   The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|S3MmioBitFieldWrite16
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT16
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in a 16-bit MMIO register, performs a bitwise OR,    writes the result back to the bit field in the 16-bit MMIO register, and    saves the value in the S3 script to be replayed on S3 resume.    Reads the 16-bit MMIO register specified by Address, performs a bitwise   inclusive OR between the read result and the value specified by OrData, and   writes the result to the 16-bit MMIO register specified by Address. The value   written to the MMIO register is returned. This function must guarantee that   all MMIO read and write operations are serialized. Extra left bits in OrData   are stripped.    If 16-bit MMIO register operations are not supported, then ASSERT().   If StartBit is greater than 15, then ASSERT().   If EndBit is greater than 15, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in]  Address    The MMIO register to write.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..15.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..15.   @param[in]  OrData     The value to OR with the read value from the MMIO register.    @return   The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|S3MmioBitFieldOr16
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT16
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in a 16-bit MMIO register, performs a bitwise AND, and   writes the result back to the bit field in the 16-bit MMIO register and    saves the value in the S3 script to be replayed on S3 resume.    Reads the 16-bit MMIO register specified by Address, performs a bitwise AND   between the read result and the value specified by AndData, and writes the   result to the 16-bit MMIO register specified by Address. The value written to   the MMIO register is returned. This function must guarantee that all MMIO   read and write operations are serialized. Extra left bits in AndData are   stripped.    If 16-bit MMIO register operations are not supported, then ASSERT().   If StartBit is greater than 15, then ASSERT().   If EndBit is greater than 15, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in]  Address    The MMIO register to write.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..15.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..15.   @param[in]  AndData    The value to AND with the read value from the MMIO register.    @return   The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|S3MmioBitFieldAnd16
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT16
name|AndData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in a 16-bit MMIO register, performs a bitwise AND followed   by a bitwise OR, writes the result back to the bit field in the   16-bit MMIO register, and saves the value in the S3 script to be replayed   on S3 resume.    Reads the 16-bit MMIO register specified by Address, performs a bitwise AND   followed by a bitwise OR between the read result and the value   specified by AndData, and writes the result to the 16-bit MMIO register   specified by Address. The value written to the MMIO register is returned.   This function must guarantee that all MMIO read and write operations are   serialized. Extra left bits in both AndData and OrData are stripped.    If 16-bit MMIO register operations are not supported, then ASSERT().   If StartBit is greater than 15, then ASSERT().   If EndBit is greater than 15, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in]  Address    The MMIO register to write.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..15.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..15.   @param[in]  AndData    The value to AND with the read value from the MMIO register.   @param[in]  OrData     The value to OR with the result of the AND operation.    @return   The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|S3MmioBitFieldAndThenOr16
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT16
name|AndData
parameter_list|,
name|IN
name|UINT16
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 32-bit MMIO register saves the value in the S3 script to be    replayed on S3 resume.    Reads the 32-bit MMIO register specified by Address. The 32-bit read value is   returned. This function must guarantee that all MMIO read and write   operations are serialized.    If 32-bit MMIO register operations are not supported, then ASSERT().    @param[in]  Address   The MMIO register to read.    @return   The value read.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|S3MmioRead32
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a 32-bit MMIO register, and saves the value in the S3 script to be    replayed on S3 resume.    Writes the 32-bit MMIO register specified by Address with the value specified   by Value and returns Value. This function must guarantee that all MMIO read   and write operations are serialized.    If 32-bit MMIO register operations are not supported, then ASSERT().    @param[in]  Address   The MMIO register to write.   @param[in]  Value     The value to write to the MMIO register.    @return   The value written the MMIO register.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|S3MmioWrite32
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINT32
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 32-bit MMIO register, performs a bitwise OR, writes the   result back to the 32-bit MMIO register, and saves the value in the S3 script    to be replayed on S3 resume.    Reads the 32-bit MMIO register specified by Address, performs a bitwise   inclusive OR between the read result and the value specified by OrData, and   writes the result to the 32-bit MMIO register specified by Address. The value   written to the MMIO register is returned. This function must guarantee that   all MMIO read and write operations are serialized.    If 32-bit MMIO register operations are not supported, then ASSERT().    @param[in]  Address   The MMIO register to write.   @param[in]  OrData    The value to OR with the read value from the MMIO register.    @return   The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|S3MmioOr32
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINT32
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 32-bit MMIO register, performs a bitwise AND, writes the result   back to the 32-bit MMIO register, and saves the value in the S3 script to be    replayed on S3 resume.    Reads the 32-bit MMIO register specified by Address, performs a bitwise AND   between the read result and the value specified by AndData, and writes the   result to the 32-bit MMIO register specified by Address. The value written to   the MMIO register is returned. This function must guarantee that all MMIO   read and write operations are serialized.    If 32-bit MMIO register operations are not supported, then ASSERT().    @param[in]  Address   The MMIO register to write.   @param[in]  AndData   The value to AND with the read value from the MMIO register.    @return   The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|S3MmioAnd32
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINT32
name|AndData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 32-bit MMIO register, performs a bitwise AND followed by a bitwise   inclusive OR, writes the result back to the 32-bit MMIO register, and    saves the value in the S3 script to be replayed on S3 resume.    Reads the 32-bit MMIO register specified by Address, performs a bitwise AND   between the read result and the value specified by AndData, performs a   bitwise OR between the result of the AND operation and the value specified by   OrData, and writes the result to the 32-bit MMIO register specified by   Address. The value written to the MMIO register is returned. This function   must guarantee that all MMIO read and write operations are serialized.    If 32-bit MMIO register operations are not supported, then ASSERT().    @param[in]  Address   The MMIO register to write.   @param[in]  AndData   The value to AND with the read value from the MMIO register.   @param[in]  OrData    The value to OR with the result of the AND operation.    @return   The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|S3MmioAndThenOr32
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINT32
name|AndData
parameter_list|,
name|IN
name|UINT32
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field of a MMIO register, and saves the value in the S3 script    to be replayed on S3 resume.    Reads the bit field in a 32-bit MMIO register. The bit field is specified by   the StartBit and the EndBit. The value of the bit field is returned.    If 32-bit MMIO register operations are not supported, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().    @param[in]  Address    MMIO register to read.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..31.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..31.    @return   The value read.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|S3MmioBitFieldRead32
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a bit field to a MMIO register, and saves the value in the S3 script    to be replayed on S3 resume.    Writes Value to the bit field of the MMIO register. The bit field is   specified by the StartBit and the EndBit. All other bits in the destination   MMIO register are preserved. The new value of the 32-bit register is returned.    If 32-bit MMIO register operations are not supported, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If Value is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in]  Address    The MMIO register to write.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..31.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..31.   @param[in]  Value      New value of the bit field.    @return   The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|S3MmioBitFieldWrite32
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT32
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in a 32-bit MMIO register, performs a bitwise OR,    writes the result back to the bit field in the 32-bit MMIO register, and    saves the value in the S3 script to be replayed on S3 resume.    Reads the 32-bit MMIO register specified by Address, performs a bitwise   inclusive OR between the read result and the value specified by OrData, and   writes the result to the 32-bit MMIO register specified by Address. The value   written to the MMIO register is returned. This function must guarantee that   all MMIO read and write operations are serialized. Extra left bits in OrData   are stripped.    If 32-bit MMIO register operations are not supported, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in]  Address    The MMIO register to write.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..31.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..31.   @param[in]  OrData     The value to OR with the read value from the MMIO register.    @return   The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|S3MmioBitFieldOr32
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT32
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in a 32-bit MMIO register, performs a bitwise AND, and   writes the result back to the bit field in the 32-bit MMIO register and    saves the value in the S3 script to be replayed on S3 resume.    Reads the 32-bit MMIO register specified by Address, performs a bitwise AND   between the read result and the value specified by AndData, and writes the   result to the 32-bit MMIO register specified by Address. The value written to   the MMIO register is returned. This function must guarantee that all MMIO   read and write operations are serialized. Extra left bits in AndData are   stripped.    If 32-bit MMIO register operations are not supported, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in]  Address    The MMIO register to write.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..31.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..31.   @param[in]  AndData    The value to AND with the read value from the MMIO register.    @return   The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|S3MmioBitFieldAnd32
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT32
name|AndData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in a 32-bit MMIO register, performs a bitwise AND followed   by a bitwise OR, writes the result back to the bit field in the   32-bit MMIO register, and saves the value in the S3 script to be replayed   on S3 resume.    Reads the 32-bit MMIO register specified by Address, performs a bitwise AND   followed by a bitwise OR between the read result and the value   specified by AndData, and writes the result to the 32-bit MMIO register   specified by Address. The value written to the MMIO register is returned.   This function must guarantee that all MMIO read and write operations are   serialized. Extra left bits in both AndData and OrData are stripped.    If 32-bit MMIO register operations are not supported, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in]  Address    The MMIO register to write.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..31.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..31.   @param[in]  AndData    The value to AND with the read value from the MMIO register.   @param[in]  OrData     The value to OR with the result of the AND operation.    @return   The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|S3MmioBitFieldAndThenOr32
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT32
name|AndData
parameter_list|,
name|IN
name|UINT32
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 64-bit MMIO register, and saves the value in the S3 script to be    replayed on S3 resume.    Reads the 64-bit MMIO register specified by Address. The 64-bit read value is   returned. This function must guarantee that all MMIO read and write   operations are serialized.    If 64-bit MMIO register operations are not supported, then ASSERT().    @param[in]  Address   The MMIO register to read.    @return   The value read.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|S3MmioRead64
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a 64-bit MMIO register, and saves the value in the S3 script to be    replayed on S3 resume.    Writes the 64-bit MMIO register specified by Address with the value specified   by Value and returns Value. This function must guarantee that all MMIO read   and write operations are serialized.    If 64-bit MMIO register operations are not supported, then ASSERT().    @param[in]  Address   The MMIO register to write.   @param[in]  Value     The value to write to the MMIO register.    @return   The value written the MMIO register.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|S3MmioWrite64
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 64-bit MMIO register, performs a bitwise OR, writes the   result back to the 64-bit MMIO register, and saves the value in the S3 script    to be replayed on S3 resume.    Reads the 64-bit MMIO register specified by Address, performs a bitwise   inclusive OR between the read result and the value specified by OrData, and   writes the result to the 64-bit MMIO register specified by Address. The value   written to the MMIO register is returned. This function must guarantee that   all MMIO read and write operations are serialized.    If 64-bit MMIO register operations are not supported, then ASSERT().    @param[in]  Address   The MMIO register to write.   @param[in]  OrData    The value to OR with the read value from the MMIO register.    @return   The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|S3MmioOr64
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINT64
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 64-bit MMIO register, performs a bitwise AND, writes the result   back to the 64-bit MMIO register, and saves the value in the S3 script to be    replayed on S3 resume.    Reads the 64-bit MMIO register specified by Address, performs a bitwise AND   between the read result and the value specified by AndData, and writes the   result to the 64-bit MMIO register specified by Address. The value written to   the MMIO register is returned. This function must guarantee that all MMIO   read and write operations are serialized.    If 64-bit MMIO register operations are not supported, then ASSERT().    @param[in]  Address   The MMIO register to write.   @param[in]  AndData   The value to AND with the read value from the MMIO register.    @return   The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|S3MmioAnd64
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINT64
name|AndData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 64-bit MMIO register, performs a bitwise AND followed by a bitwise   inclusive OR, writes the result back to the 64-bit MMIO register, and    saves the value in the S3 script to be replayed on S3 resume.    Reads the 64-bit MMIO register specified by Address, performs a bitwise AND   between the read result and the value specified by AndData, performs a   bitwise OR between the result of the AND operation and the value specified by   OrData, and writes the result to the 64-bit MMIO register specified by   Address. The value written to the MMIO register is returned. This function   must guarantee that all MMIO read and write operations are serialized.    If 64-bit MMIO register operations are not supported, then ASSERT().    @param[in]  Address   The MMIO register to write.   @param[in]  AndData   The value to AND with the read value from the MMIO register.   @param[in]  OrData    The value to OR with the result of the AND operation.    @return   The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|S3MmioAndThenOr64
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINT64
name|AndData
parameter_list|,
name|IN
name|UINT64
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field of a MMIO register saves the value in the S3 script to   be replayed on S3 resume.    Reads the bit field in a 64-bit MMIO register. The bit field is specified by   the StartBit and the EndBit. The value of the bit field is returned.    If 64-bit MMIO register operations are not supported, then ASSERT().   If StartBit is greater than 63, then ASSERT().   If EndBit is greater than 63, then ASSERT().   If EndBit is less than StartBit, then ASSERT().    @param[in]  Address    MMIO register to read.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..63.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..63.    @return   The value read.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|S3MmioBitFieldRead64
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a bit field to a MMIO register, and saves the value in the S3 script to   be replayed on S3 resume.    Writes Value to the bit field of the MMIO register. The bit field is   specified by the StartBit and the EndBit. All other bits in the destination   MMIO register are preserved. The new value of the 64-bit register is returned.    If 64-bit MMIO register operations are not supported, then ASSERT().   If StartBit is greater than 63, then ASSERT().   If EndBit is greater than 63, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If Value is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in]  Address    The MMIO register to write.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..63.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..63.   @param[in]  Value      New value of the bit field.    @return   The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|S3MmioBitFieldWrite64
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in a 64-bit MMIO register, performs a bitwise OR,    writes the result back to the bit field in the 64-bit MMIO register, and    saves the value in the S3 script to be replayed on S3 resume.    Reads the 64-bit MMIO register specified by Address, performs a bitwise   inclusive OR between the read result and the value specified by OrData, and   writes the result to the 64-bit MMIO register specified by Address. The value   written to the MMIO register is returned. This function must guarantee that   all MMIO read and write operations are serialized. Extra left bits in OrData   are stripped.    If 64-bit MMIO register operations are not supported, then ASSERT().   If StartBit is greater than 63, then ASSERT().   If EndBit is greater than 63, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in]  Address    The MMIO register to write.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..63.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..63.   @param[in]  OrData     The value to OR with the read value from the MMIO register.    @return   The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|S3MmioBitFieldOr64
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT64
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in a 64-bit MMIO register, performs a bitwise AND, and   writes the result back to the bit field in the 64-bit MMIO register, and saves   the value in the S3 script to be replayed on S3 resume.    Reads the 64-bit MMIO register specified by Address, performs a bitwise AND   between the read result and the value specified by AndData, and writes the   result to the 64-bit MMIO register specified by Address. The value written to   the MMIO register is returned. This function must guarantee that all MMIO   read and write operations are serialized. Extra left bits in AndData are   stripped.    If 64-bit MMIO register operations are not supported, then ASSERT().   If StartBit is greater than 63, then ASSERT().   If EndBit is greater than 63, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in]  Address    The MMIO register to write.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..63.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..63.   @param[in]  AndData    The value to AND with the read value from the MMIO register.    @return   The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|S3MmioBitFieldAnd64
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT64
name|AndData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in a 64-bit MMIO register, performs a bitwise AND followed   by a bitwise OR, writes the result back to the bit field in the   64-bit MMIO register, and saves the value in the S3 script to be replayed   on S3 resume.    Reads the 64-bit MMIO register specified by Address, performs a bitwise AND   followed by a bitwise OR between the read result and the value   specified by AndData, and writes the result to the 64-bit MMIO register   specified by Address. The value written to the MMIO register is returned.   This function must guarantee that all MMIO read and write operations are   serialized. Extra left bits in both AndData and OrData are stripped.    If 64-bit MMIO register operations are not supported, then ASSERT().   If StartBit is greater than 63, then ASSERT().   If EndBit is greater than 63, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in]  Address    The MMIO register to write.   @param[in]  StartBit   The ordinal of the least significant bit in the bit field.                          Range 0..63.   @param[in]  EndBit     The ordinal of the most significant bit in the bit field.                          Range 0..63.   @param[in]  AndData    The value to AND with the read value from the MMIO register.   @param[in]  OrData     The value to OR with the result of the AND operation.    @return   The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|S3MmioBitFieldAndThenOr64
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT64
name|AndData
parameter_list|,
name|IN
name|UINT64
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Copies data from MMIO region to system memory by using 8-bit access,   and saves the value in the S3 script to be replayed on S3 resume.    Copy data from MMIO region specified by starting address StartAddress    to system memory specified by Buffer by using 8-bit access. The total    number of bytes to be copied is specified by Length. Buffer is returned.      If Length is greater than (MAX_ADDRESS - StartAddress + 1), then ASSERT().    If Length is greater than (MAX_ADDRESS - Buffer + 1), then ASSERT().     @param[in]  StartAddress   Starting address for the MMIO region to be copied from.   @param[in]  Length         Size in bytes of the copy.   @param[out] Buffer         Pointer to a system memory buffer receiving the data read.    @return   Buffer.  **/
end_comment

begin_function_decl
name|UINT8
modifier|*
name|EFIAPI
name|S3MmioReadBuffer8
parameter_list|(
name|IN
name|UINTN
name|StartAddress
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|,
name|OUT
name|UINT8
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Copies data from MMIO region to system memory by using 16-bit access,   and saves the value in the S3 script to be replayed on S3 resume.    Copy data from MMIO region specified by starting address StartAddress    to system memory specified by Buffer by using 16-bit access. The total    number of bytes to be copied is specified by Length. Buffer is returned.      If StartAddress is not aligned on a 16-bit boundary, then ASSERT().    If Length is greater than (MAX_ADDRESS - StartAddress + 1), then ASSERT().    If Length is greater than (MAX_ADDRESS - Buffer + 1), then ASSERT().    If Length is not aligned on a 16-bit boundary, then ASSERT().   If Buffer is not aligned on a 16-bit boundary, then ASSERT().    @param[in]  StartAddress   Starting address for the MMIO region to be copied from.   @param[in]  Length         Size in bytes of the copy.   @param[out] Buffer         Pointer to a system memory buffer receiving the data read.    @return   Buffer.  **/
end_comment

begin_function_decl
name|UINT16
modifier|*
name|EFIAPI
name|S3MmioReadBuffer16
parameter_list|(
name|IN
name|UINTN
name|StartAddress
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|,
name|OUT
name|UINT16
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Copies data from MMIO region to system memory by using 32-bit access,   and saves the value in the S3 script to be replayed on S3 resume.    Copy data from MMIO region specified by starting address StartAddress    to system memory specified by Buffer by using 32-bit access. The total    number of byte to be copied is specified by Length. Buffer is returned.      If StartAddress is not aligned on a 32-bit boundary, then ASSERT().    If Length is greater than (MAX_ADDRESS - StartAddress + 1), then ASSERT().    If Length is greater than (MAX_ADDRESS - Buffer + 1), then ASSERT().    If Length is not aligned on a 32-bit boundary, then ASSERT().   If Buffer is not aligned on a 32-bit boundary, then ASSERT().    @param[in]  StartAddress   Starting address for the MMIO region to be copied from.   @param[in]  Length         Size in bytes of the copy.   @param[out] Buffer         Pointer to a system memory buffer receiving the data read.    @return   Buffer.  **/
end_comment

begin_function_decl
name|UINT32
modifier|*
name|EFIAPI
name|S3MmioReadBuffer32
parameter_list|(
name|IN
name|UINTN
name|StartAddress
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Copies data from MMIO region to system memory by using 64-bit access,   and saves the value in the S3 script to be replayed on S3 resume.    Copy data from MMIO region specified by starting address StartAddress    to system memory specified by Buffer by using 64-bit access. The total    number of byte to be copied is specified by Length. Buffer is returned.      If StartAddress is not aligned on a 64-bit boundary, then ASSERT().    If Length is greater than (MAX_ADDRESS - StartAddress + 1), then ASSERT().    If Length is greater than (MAX_ADDRESS - Buffer + 1), then ASSERT().    If Length is not aligned on a 64-bit boundary, then ASSERT().   If Buffer is not aligned on a 64-bit boundary, then ASSERT().    @param[in]  StartAddress   Starting address for the MMIO region to be copied from.   @param[in]  Length         Size in bytes of the copy.   @param[out] Buffer         Pointer to a system memory buffer receiving the data read.    @return   Buffer.  **/
end_comment

begin_function_decl
name|UINT64
modifier|*
name|EFIAPI
name|S3MmioReadBuffer64
parameter_list|(
name|IN
name|UINTN
name|StartAddress
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|,
name|OUT
name|UINT64
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Copies data from system memory to MMIO region by using 8-bit access,   and saves the value in the S3 script to be replayed on S3 resume.    Copy data from system memory specified by Buffer to MMIO region specified    by starting address StartAddress by using 8-bit access. The total number    of byte to be copied is specified by Length. Buffer is returned.      If Length is greater than (MAX_ADDRESS - StartAddress + 1), then ASSERT().    If Length is greater than (MAX_ADDRESS -Buffer + 1), then ASSERT().     @param[in]  StartAddress   Starting address for the MMIO region to be copied to.   @param[in]  Length         Size in bytes of the copy.   @param[in]  Buffer         Pointer to a system memory buffer containing the data to write.    @return   Buffer.  **/
end_comment

begin_function_decl
name|UINT8
modifier|*
name|EFIAPI
name|S3MmioWriteBuffer8
parameter_list|(
name|IN
name|UINTN
name|StartAddress
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|,
name|IN
name|CONST
name|UINT8
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Copies data from system memory to MMIO region by using 16-bit access,   and saves the value in the S3 script to be replayed on S3 resume.    Copy data from system memory specified by Buffer to MMIO region specified    by starting address StartAddress by using 16-bit access. The total number    of bytes to be copied is specified by Length. Buffer is returned.      If StartAddress is not aligned on a 16-bit boundary, then ASSERT().    If Length is greater than (MAX_ADDRESS - StartAddress + 1), then ASSERT().    If Length is greater than (MAX_ADDRESS -Buffer + 1), then ASSERT().    If Length is not aligned on a 16-bit boundary, then ASSERT().    If Buffer is not aligned on a 16-bit boundary, then ASSERT().    @param[in]  StartAddress   Starting address for the MMIO region to be copied to.   @param[in]  Length         Size in bytes of the copy.   @param[in]  Buffer         Pointer to a system memory buffer containing the data to write.    @return   Buffer.  **/
end_comment

begin_function_decl
name|UINT16
modifier|*
name|EFIAPI
name|S3MmioWriteBuffer16
parameter_list|(
name|IN
name|UINTN
name|StartAddress
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|,
name|IN
name|CONST
name|UINT16
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Copies data from system memory to MMIO region by using 32-bit access,   and saves the value in the S3 script to be replayed on S3 resume.    Copy data from system memory specified by Buffer to MMIO region specified    by starting address StartAddress by using 32-bit access. The total number    of bytes to be copied is specified by Length. Buffer is returned.      If StartAddress is not aligned on a 32-bit boundary, then ASSERT().    If Length is greater than (MAX_ADDRESS - StartAddress + 1), then ASSERT().    If Length is greater than (MAX_ADDRESS -Buffer + 1), then ASSERT().    If Length is not aligned on a 32-bit boundary, then ASSERT().    If Buffer is not aligned on a 32-bit boundary, then ASSERT().    @param[in]  StartAddress   Starting address for the MMIO region to be copied to.   @param[in]  Length         Size in bytes of the copy.   @param[in]  Buffer         Pointer to a system memory buffer containing the data to write.    @return   Buffer.  **/
end_comment

begin_function_decl
name|UINT32
modifier|*
name|EFIAPI
name|S3MmioWriteBuffer32
parameter_list|(
name|IN
name|UINTN
name|StartAddress
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|,
name|IN
name|CONST
name|UINT32
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Copies data from system memory to MMIO region by using 64-bit access,    and saves the value in the S3 script to be replayed on S3 resume.    Copy data from system memory specified by Buffer to MMIO region specified    by starting address StartAddress by using 64-bit access. The total number    of bytes to be copied is specified by Length. Buffer is returned.      If StartAddress is not aligned on a 64-bit boundary, then ASSERT().    If Length is greater than (MAX_ADDRESS - StartAddress + 1), then ASSERT().    If Length is greater than (MAX_ADDRESS -Buffer + 1), then ASSERT().    If Length is not aligned on a 64-bit boundary, then ASSERT().    If Buffer is not aligned on a 64-bit boundary, then ASSERT().    @param[in]  StartAddress   Starting address for the MMIO region to be copied to.   @param[in]  Length         Size in bytes of the copy.   @param[in]  Buffer         Pointer to a system memory buffer containing the data to write.    @return   Buffer.  **/
end_comment

begin_function_decl
name|UINT64
modifier|*
name|EFIAPI
name|S3MmioWriteBuffer64
parameter_list|(
name|IN
name|UINTN
name|StartAddress
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|,
name|IN
name|CONST
name|UINT64
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

