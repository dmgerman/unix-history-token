begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provide services to access I/O Ports and MMIO registers.  Copyright (c) 2006 - 2012, Intel Corporation. All rights reserved.<BR> Copyright (c) 2017, AMD Incorporated. All rights reserved.<BR>  This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IO_LIB_H__
end_ifndef

begin_define
define|#
directive|define
name|__IO_LIB_H__
end_define

begin_comment
comment|/**   Macro that converts PCI Segment and I/O Port to an address that can be   passed to the I/O Library functions.      Computes an address that is compatible with the I/O Library functions.     The unused upper bits of Segment, and Port are stripped prior to the    generation of the address.      @param  Segment   PCI Segment number.  Range 0..65535.   @param  Port      I/O Port number.  Range 0..65535.      @return An address that the I/o Library functions need.  **/
end_comment

begin_define
define|#
directive|define
name|IO_LIB_ADDRESS
parameter_list|(
name|Segment
parameter_list|,
name|Port
parameter_list|)
define|\
value|( ((Port)& 0xffff) | (((Segment)& 0xffff)<< 16) )
end_define

begin_comment
comment|/**   Reads an 8-bit I/O port.    Reads the 8-bit I/O port specified by Port. The 8-bit read value is returned.   This function must guarantee that all I/O read and write operations are   serialized.    If 8-bit I/O port operations are not supported, then ASSERT().    @param  Port  The I/O port to read.    @return The value read.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|IoRead8
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes an 8-bit I/O port.    Writes the 8-bit I/O port specified by Port with the value specified by Value   and returns Value. This function must guarantee that all I/O read and write   operations are serialized.    If 8-bit I/O port operations are not supported, then ASSERT().    @param  Port  The I/O port to write.   @param  Value The value to write to the I/O port.    @return The value written the I/O port.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|IoWrite8
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
comment|/**   Reads an 8-bit I/O port fifo into a block of memory.    Reads the 8-bit I/O fifo port specified by Port.   The port is read Count times, and the read data is   stored in the provided Buffer.    This function must guarantee that all I/O read and write operations are   serialized.    If 8-bit I/O port operations are not supported, then ASSERT().    @param  Port    The I/O port to read.   @param  Count   The number of times to read I/O port.   @param  Buffer  The buffer to store the read data into.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|IoReadFifo8
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINTN
name|Count
parameter_list|,
name|OUT
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a block of memory into an 8-bit I/O port fifo.    Writes the 8-bit I/O fifo port specified by Port.   The port is written Count times, and the write data is   retrieved from the provided Buffer.    This function must guarantee that all I/O write and write operations are   serialized.    If 8-bit I/O port operations are not supported, then ASSERT().    @param  Port    The I/O port to write.   @param  Count   The number of times to write I/O port.   @param  Buffer  The buffer to retrieve the write data from.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|IoWriteFifo8
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINTN
name|Count
parameter_list|,
name|IN
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads an 8-bit I/O port, performs a bitwise OR, and writes the   result back to the 8-bit I/O port.    Reads the 8-bit I/O port specified by Port, performs a bitwise OR   between the read result and the value specified by OrData, and writes the   result to the 8-bit I/O port specified by Port. The value written to the I/O   port is returned. This function must guarantee that all I/O read and write   operations are serialized.    If 8-bit I/O port operations are not supported, then ASSERT().    @param  Port    The I/O port to write.   @param  OrData  The value to OR with the read value from the I/O port.    @return The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|IoOr8
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
comment|/**   Reads an 8-bit I/O port, performs a bitwise AND, and writes the result back   to the 8-bit I/O port.    Reads the 8-bit I/O port specified by Port, performs a bitwise AND between   the read result and the value specified by AndData, and writes the result to   the 8-bit I/O port specified by Port. The value written to the I/O port is   returned. This function must guarantee that all I/O read and write operations   are serialized.    If 8-bit I/O port operations are not supported, then ASSERT().    @param  Port    The I/O port to write.   @param  AndData The value to AND with the read value from the I/O port.    @return The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|IoAnd8
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
comment|/**   Reads an 8-bit I/O port, performs a bitwise AND followed by a bitwise    OR, and writes the result back to the 8-bit I/O port.    Reads the 8-bit I/O port specified by Port, performs a bitwise AND between   the read result and the value specified by AndData, performs a bitwise OR   between the result of the AND operation and the value specified by OrData,   and writes the result to the 8-bit I/O port specified by Port. The value   written to the I/O port is returned. This function must guarantee that all   I/O read and write operations are serialized.    If 8-bit I/O port operations are not supported, then ASSERT().    @param  Port    The I/O port to write.   @param  AndData The value to AND with the read value from the I/O port.   @param  OrData  The value to OR with the result of the AND operation.    @return The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|IoAndThenOr8
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
comment|/**   Reads a bit field of an I/O register.    Reads the bit field in an 8-bit I/O register. The bit field is specified by   the StartBit and the EndBit. The value of the bit field is returned.    If 8-bit I/O port operations are not supported, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().    @param  Port      The I/O port to read.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..7.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..7.    @return The value read.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|IoBitFieldRead8
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
comment|/**   Writes a bit field to an I/O register.    Writes Value to the bit field of the I/O register. The bit field is specified   by the StartBit and the EndBit. All other bits in the destination I/O   register are preserved. The value written to the I/O port is returned.     If 8-bit I/O port operations are not supported, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If Value is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Port      The I/O port to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..7.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..7.   @param  Value     New value of the bit field.    @return The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|IoBitFieldWrite8
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
comment|/**   Reads a bit field in an 8-bit port, performs a bitwise OR, and writes the   result back to the bit field in the 8-bit port.    Reads the 8-bit I/O port specified by Port, performs a bitwise OR   between the read result and the value specified by OrData, and writes the   result to the 8-bit I/O port specified by Port. The value written to the I/O   port is returned. This function must guarantee that all I/O read and write   operations are serialized. Extra left bits in OrData are stripped.    If 8-bit I/O port operations are not supported, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Port      The I/O port to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..7.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..7.   @param  OrData    The value to OR with the read value from the I/O port.    @return The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|IoBitFieldOr8
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
comment|/**   Reads a bit field in an 8-bit port, performs a bitwise AND, and writes the   result back to the bit field in the 8-bit port.    Reads the 8-bit I/O port specified by Port, performs a bitwise AND between   the read result and the value specified by AndData, and writes the result to   the 8-bit I/O port specified by Port. The value written to the I/O port is   returned. This function must guarantee that all I/O read and write operations   are serialized. Extra left bits in AndData are stripped.    If 8-bit I/O port operations are not supported, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Port      The I/O port to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..7.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..7.   @param  AndData   The value to AND with the read value from the I/O port.    @return The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|IoBitFieldAnd8
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
comment|/**   Reads a bit field in an 8-bit port, performs a bitwise AND followed by a   bitwise OR, and writes the result back to the bit field in the   8-bit port.    Reads the 8-bit I/O port specified by Port, performs a bitwise AND followed   by a bitwise OR between the read result and the value specified by   AndData, and writes the result to the 8-bit I/O port specified by Port. The   value written to the I/O port is returned. This function must guarantee that   all I/O read and write operations are serialized. Extra left bits in both   AndData and OrData are stripped.    If 8-bit I/O port operations are not supported, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Port      The I/O port to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..7.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..7.   @param  AndData   The value to AND with the read value from the I/O port.   @param  OrData    The value to OR with the result of the AND operation.    @return The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|IoBitFieldAndThenOr8
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
comment|/**   Reads a 16-bit I/O port.    Reads the 16-bit I/O port specified by Port. The 16-bit read value is returned.   This function must guarantee that all I/O read and write operations are   serialized.    If 16-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 16-bit boundary, then ASSERT().    @param  Port  The I/O port to read.    @return The value read.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|IoRead16
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a 16-bit I/O port.    Writes the 16-bit I/O port specified by Port with the value specified by Value   and returns Value. This function must guarantee that all I/O read and write   operations are serialized.    If 16-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 16-bit boundary, then ASSERT().      @param  Port  The I/O port to write.   @param  Value The value to write to the I/O port.    @return The value written the I/O port.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|IoWrite16
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
comment|/**   Reads a 16-bit I/O port fifo into a block of memory.    Reads the 16-bit I/O fifo port specified by Port.   The port is read Count times, and the read data is   stored in the provided Buffer.    This function must guarantee that all I/O read and write operations are   serialized.    If 16-bit I/O port operations are not supported, then ASSERT().    @param  Port    The I/O port to read.   @param  Count   The number of times to read I/O port.   @param  Buffer  The buffer to store the read data into.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|IoReadFifo16
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINTN
name|Count
parameter_list|,
name|OUT
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a block of memory into a 16-bit I/O port fifo.    Writes the 16-bit I/O fifo port specified by Port.   The port is written Count times, and the write data is   retrieved from the provided Buffer.    This function must guarantee that all I/O write and write operations are   serialized.    If 16-bit I/O port operations are not supported, then ASSERT().    @param  Port    The I/O port to write.   @param  Count   The number of times to write I/O port.   @param  Buffer  The buffer to retrieve the write data from.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|IoWriteFifo16
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINTN
name|Count
parameter_list|,
name|IN
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 16-bit I/O port, performs a bitwise OR, and writes the   result back to the 16-bit I/O port.    Reads the 16-bit I/O port specified by Port, performs a bitwise OR   between the read result and the value specified by OrData, and writes the   result to the 16-bit I/O port specified by Port. The value written to the I/O   port is returned. This function must guarantee that all I/O read and write   operations are serialized.    If 16-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 16-bit boundary, then ASSERT().    @param  Port    The I/O port to write.   @param  OrData  The value to OR with the read value from the I/O port.    @return The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|IoOr16
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
comment|/**   Reads a 16-bit I/O port, performs a bitwise AND, and writes the result back   to the 16-bit I/O port.    Reads the 16-bit I/O port specified by Port, performs a bitwise AND between   the read result and the value specified by AndData, and writes the result to   the 16-bit I/O port specified by Port. The value written to the I/O port is   returned. This function must guarantee that all I/O read and write operations   are serialized.    If 16-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 16-bit boundary, then ASSERT().      @param  Port    The I/O port to write.   @param  AndData The value to AND with the read value from the I/O port.    @return The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|IoAnd16
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
comment|/**   Reads a 16-bit I/O port, performs a bitwise AND followed by a bitwise    OR, and writes the result back to the 16-bit I/O port.    Reads the 16-bit I/O port specified by Port, performs a bitwise AND between   the read result and the value specified by AndData, performs a bitwise OR   between the result of the AND operation and the value specified by OrData,   and writes the result to the 16-bit I/O port specified by Port. The value   written to the I/O port is returned. This function must guarantee that all   I/O read and write operations are serialized.    If 16-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 16-bit boundary, then ASSERT().      @param  Port    The I/O port to write.   @param  AndData The value to AND with the read value from the I/O port.   @param  OrData  The value to OR with the result of the AND operation.    @return The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|IoAndThenOr16
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
comment|/**   Reads a bit field of an I/O register.    Reads the bit field in a 16-bit I/O register. The bit field is specified by   the StartBit and the EndBit. The value of the bit field is returned.    If 16-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 16-bit boundary, then ASSERT().   If StartBit is greater than 15, then ASSERT().   If EndBit is greater than 15, then ASSERT().   If EndBit is less than StartBit, then ASSERT().    @param  Port      The I/O port to read.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..15.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..15.    @return The value read.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|IoBitFieldRead16
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
comment|/**   Writes a bit field to an I/O register.    Writes Value to the bit field of the I/O register. The bit field is specified   by the StartBit and the EndBit. All other bits in the destination I/O   register are preserved. The value written to the I/O port is returned. Extra   left bits in Value are stripped.    If 16-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 16-bit boundary, then ASSERT().   If StartBit is greater than 15, then ASSERT().   If EndBit is greater than 15, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If Value is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Port      The I/O port to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..15.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..15.   @param  Value     New value of the bit field.    @return The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|IoBitFieldWrite16
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
comment|/**   Reads a bit field in a 16-bit port, performs a bitwise OR, and writes the   result back to the bit field in the 16-bit port.    Reads the 16-bit I/O port specified by Port, performs a bitwise OR   between the read result and the value specified by OrData, and writes the   result to the 16-bit I/O port specified by Port. The value written to the I/O   port is returned. This function must guarantee that all I/O read and write   operations are serialized. Extra left bits in OrData are stripped.    If 16-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 16-bit boundary, then ASSERT().   If StartBit is greater than 15, then ASSERT().   If EndBit is greater than 15, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Port      The I/O port to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..15.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..15.   @param  OrData    The value to OR with the read value from the I/O port.    @return The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|IoBitFieldOr16
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
comment|/**   Reads a bit field in a 16-bit port, performs a bitwise AND, and writes the   result back to the bit field in the 16-bit port.    Reads the 16-bit I/O port specified by Port, performs a bitwise AND between   the read result and the value specified by AndData, and writes the result to   the 16-bit I/O port specified by Port. The value written to the I/O port is   returned. This function must guarantee that all I/O read and write operations   are serialized. Extra left bits in AndData are stripped.    If 16-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 16-bit boundary, then ASSERT().   If StartBit is greater than 15, then ASSERT().   If EndBit is greater than 15, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Port      The I/O port to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..15.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..15.   @param  AndData   The value to AND with the read value from the I/O port.    @return The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|IoBitFieldAnd16
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
comment|/**   Reads a bit field in a 16-bit port, performs a bitwise AND followed by a   bitwise OR, and writes the result back to the bit field in the   16-bit port.    Reads the 16-bit I/O port specified by Port, performs a bitwise AND followed   by a bitwise OR between the read result and the value specified by   AndData, and writes the result to the 16-bit I/O port specified by Port. The   value written to the I/O port is returned. This function must guarantee that   all I/O read and write operations are serialized. Extra left bits in both   AndData and OrData are stripped.    If 16-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 16-bit boundary, then ASSERT().   If StartBit is greater than 15, then ASSERT().   If EndBit is greater than 15, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Port      The I/O port to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..15.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..15.   @param  AndData   The value to AND with the read value from the I/O port.   @param  OrData    The value to OR with the result of the AND operation.    @return The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|IoBitFieldAndThenOr16
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
comment|/**   Reads a 32-bit I/O port.    Reads the 32-bit I/O port specified by Port. The 32-bit read value is returned.   This function must guarantee that all I/O read and write operations are   serialized.    If 32-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 32-bit boundary, then ASSERT().      @param  Port  The I/O port to read.    @return The value read.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|IoRead32
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a 32-bit I/O port.    Writes the 32-bit I/O port specified by Port with the value specified by Value   and returns Value. This function must guarantee that all I/O read and write   operations are serialized.    If 32-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 32-bit boundary, then ASSERT().      @param  Port  The I/O port to write.   @param  Value The value to write to the I/O port.    @return The value written the I/O port.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|IoWrite32
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
comment|/**   Reads a 32-bit I/O port fifo into a block of memory.    Reads the 32-bit I/O fifo port specified by Port.   The port is read Count times, and the read data is   stored in the provided Buffer.    This function must guarantee that all I/O read and write operations are   serialized.    If 32-bit I/O port operations are not supported, then ASSERT().    @param  Port    The I/O port to read.   @param  Count   The number of times to read I/O port.   @param  Buffer  The buffer to store the read data into.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|IoReadFifo32
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINTN
name|Count
parameter_list|,
name|OUT
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a block of memory into a 32-bit I/O port fifo.    Writes the 32-bit I/O fifo port specified by Port.   The port is written Count times, and the write data is   retrieved from the provided Buffer.    This function must guarantee that all I/O write and write operations are   serialized.    If 32-bit I/O port operations are not supported, then ASSERT().    @param  Port    The I/O port to write.   @param  Count   The number of times to write I/O port.   @param  Buffer  The buffer to retrieve the write data from.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|IoWriteFifo32
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|UINTN
name|Count
parameter_list|,
name|IN
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 32-bit I/O port, performs a bitwise OR, and writes the   result back to the 32-bit I/O port.    Reads the 32-bit I/O port specified by Port, performs a bitwise OR   between the read result and the value specified by OrData, and writes the   result to the 32-bit I/O port specified by Port. The value written to the I/O   port is returned. This function must guarantee that all I/O read and write   operations are serialized.    If 32-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 32-bit boundary, then ASSERT().    @param  Port    The I/O port to write.   @param  OrData  The value to OR with the read value from the I/O port.    @return The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|IoOr32
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
comment|/**   Reads a 32-bit I/O port, performs a bitwise AND, and writes the result back   to the 32-bit I/O port.    Reads the 32-bit I/O port specified by Port, performs a bitwise AND between   the read result and the value specified by AndData, and writes the result to   the 32-bit I/O port specified by Port. The value written to the I/O port is   returned. This function must guarantee that all I/O read and write operations   are serialized.    If 32-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 32-bit boundary, then ASSERT().    @param  Port    The I/O port to write.   @param  AndData The value to AND with the read value from the I/O port.    @return The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|IoAnd32
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
comment|/**   Reads a 32-bit I/O port, performs a bitwise AND followed by a bitwise    OR, and writes the result back to the 32-bit I/O port.    Reads the 32-bit I/O port specified by Port, performs a bitwise AND between   the read result and the value specified by AndData, performs a bitwise OR   between the result of the AND operation and the value specified by OrData,   and writes the result to the 32-bit I/O port specified by Port. The value   written to the I/O port is returned. This function must guarantee that all   I/O read and write operations are serialized.    If 32-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 32-bit boundary, then ASSERT().    @param  Port    The I/O port to write.   @param  AndData The value to AND with the read value from the I/O port.   @param  OrData  The value to OR with the result of the AND operation.    @return The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|IoAndThenOr32
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
comment|/**   Reads a bit field of an I/O register.    Reads the bit field in a 32-bit I/O register. The bit field is specified by   the StartBit and the EndBit. The value of the bit field is returned.    If 32-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 32-bit boundary, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().    @param  Port      The I/O port to read.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..31.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..31.    @return The value read.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|IoBitFieldRead32
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
comment|/**   Writes a bit field to an I/O register.    Writes Value to the bit field of the I/O register. The bit field is specified   by the StartBit and the EndBit. All other bits in the destination I/O   register are preserved. The value written to the I/O port is returned. Extra   left bits in Value are stripped.    If 32-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 32-bit boundary, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If Value is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Port      The I/O port to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..31.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..31.   @param  Value     New value of the bit field.    @return The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|IoBitFieldWrite32
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
comment|/**   Reads a bit field in a 32-bit port, performs a bitwise OR, and writes the   result back to the bit field in the 32-bit port.    Reads the 32-bit I/O port specified by Port, performs a bitwise OR   between the read result and the value specified by OrData, and writes the   result to the 32-bit I/O port specified by Port. The value written to the I/O   port is returned. This function must guarantee that all I/O read and write   operations are serialized. Extra left bits in OrData are stripped.    If 32-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 32-bit boundary, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Port      The I/O port to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..31.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..31.   @param  OrData    The value to OR with the read value from the I/O port.    @return The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|IoBitFieldOr32
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
comment|/**   Reads a bit field in a 32-bit port, performs a bitwise AND, and writes the   result back to the bit field in the 32-bit port.    Reads the 32-bit I/O port specified by Port, performs a bitwise AND between   the read result and the value specified by AndData, and writes the result to   the 32-bit I/O port specified by Port. The value written to the I/O port is   returned. This function must guarantee that all I/O read and write operations   are serialized. Extra left bits in AndData are stripped.    If 32-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 32-bit boundary, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Port      The I/O port to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..31.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..31.   @param  AndData   The value to AND with the read value from the I/O port.    @return The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|IoBitFieldAnd32
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
comment|/**   Reads a bit field in a 32-bit port, performs a bitwise AND followed by a   bitwise OR, and writes the result back to the bit field in the   32-bit port.    Reads the 32-bit I/O port specified by Port, performs a bitwise AND followed   by a bitwise OR between the read result and the value specified by   AndData, and writes the result to the 32-bit I/O port specified by Port. The   value written to the I/O port is returned. This function must guarantee that   all I/O read and write operations are serialized. Extra left bits in both   AndData and OrData are stripped.    If 32-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 32-bit boundary, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Port      The I/O port to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..31.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..31.   @param  AndData   The value to AND with the read value from the I/O port.   @param  OrData    The value to OR with the result of the AND operation.    @return The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|IoBitFieldAndThenOr32
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
comment|/**   Reads a 64-bit I/O port.    Reads the 64-bit I/O port specified by Port. The 64-bit read value is returned.   This function must guarantee that all I/O read and write operations are   serialized.    If 64-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 64-bit boundary, then ASSERT().    @param  Port  The I/O port to read.    @return The value read.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|IoRead64
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a 64-bit I/O port.    Writes the 64-bit I/O port specified by Port with the value specified by Value   and returns Value. This function must guarantee that all I/O read and write   operations are serialized.    If 64-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 64-bit boundary, then ASSERT().    @param  Port  The I/O port to write.   @param  Value The value to write to the I/O port.    @return The value written the I/O port.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|IoWrite64
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
comment|/**   Reads a 64-bit I/O port, performs a bitwise OR, and writes the   result back to the 64-bit I/O port.    Reads the 64-bit I/O port specified by Port, performs a bitwise OR   between the read result and the value specified by OrData, and writes the   result to the 64-bit I/O port specified by Port. The value written to the I/O   port is returned. This function must guarantee that all I/O read and write   operations are serialized.    If 64-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 64-bit boundary, then ASSERT().    @param  Port    The I/O port to write.   @param  OrData  The value to OR with the read value from the I/O port.    @return The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|IoOr64
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
comment|/**   Reads a 64-bit I/O port, performs a bitwise AND, and writes the result back   to the 64-bit I/O port.    Reads the 64-bit I/O port specified by Port, performs a bitwise AND between   the read result and the value specified by AndData, and writes the result to   the 64-bit I/O port specified by Port. The value written to the I/O port is   returned. This function must guarantee that all I/O read and write operations   are serialized.    If 64-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 64-bit boundary, then ASSERT().    @param  Port    The I/O port to write.   @param  AndData The value to AND with the read value from the I/O port.    @return The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|IoAnd64
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
comment|/**   Reads a 64-bit I/O port, performs a bitwise AND followed by a bitwise    OR, and writes the result back to the 64-bit I/O port.    Reads the 64-bit I/O port specified by Port, performs a bitwise AND between   the read result and the value specified by AndData, performs a bitwise OR   between the result of the AND operation and the value specified by OrData,   and writes the result to the 64-bit I/O port specified by Port. The value   written to the I/O port is returned. This function must guarantee that all   I/O read and write operations are serialized.    If 64-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 64-bit boundary, then ASSERT().    @param  Port    The I/O port to write.   @param  AndData The value to AND with the read value from the I/O port.   @param  OrData  The value to OR with the result of the AND operation.    @return The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|IoAndThenOr64
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
comment|/**   Reads a bit field of an I/O register.    Reads the bit field in a 64-bit I/O register. The bit field is specified by   the StartBit and the EndBit. The value of the bit field is returned.    If 64-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 64-bit boundary, then ASSERT().   If StartBit is greater than 63, then ASSERT().   If EndBit is greater than 63, then ASSERT().   If EndBit is less than StartBit, then ASSERT().    @param  Port      The I/O port to read.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..63.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..63.    @return The value read.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|IoBitFieldRead64
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
comment|/**   Writes a bit field to an I/O register.    Writes Value to the bit field of the I/O register. The bit field is specified   by the StartBit and the EndBit. All other bits in the destination I/O   register are preserved. The value written to the I/O port is returned. Extra   left bits in Value are stripped.    If 64-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 64-bit boundary, then ASSERT().   If StartBit is greater than 63, then ASSERT().   If EndBit is greater than 63, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If Value is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Port      The I/O port to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..63.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..63.   @param  Value     New value of the bit field.    @return The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|IoBitFieldWrite64
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
comment|/**   Reads a bit field in a 64-bit port, performs a bitwise OR, and writes the   result back to the bit field in the 64-bit port.    Reads the 64-bit I/O port specified by Port, performs a bitwise OR   between the read result and the value specified by OrData, and writes the   result to the 64-bit I/O port specified by Port. The value written to the I/O   port is returned. This function must guarantee that all I/O read and write   operations are serialized. Extra left bits in OrData are stripped.    If 64-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 64-bit boundary, then ASSERT().   If StartBit is greater than 63, then ASSERT().   If EndBit is greater than 63, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Port      The I/O port to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..63.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..63.   @param  OrData    The value to OR with the read value from the I/O port.    @return The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|IoBitFieldOr64
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
comment|/**   Reads a bit field in a 64-bit port, performs a bitwise AND, and writes the   result back to the bit field in the 64-bit port.    Reads the 64-bit I/O port specified by Port, performs a bitwise AND between   the read result and the value specified by AndData, and writes the result to   the 64-bit I/O port specified by Port. The value written to the I/O port is   returned. This function must guarantee that all I/O read and write operations   are serialized. Extra left bits in AndData are stripped.    If 64-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 64-bit boundary, then ASSERT().   If StartBit is greater than 63, then ASSERT().   If EndBit is greater than 63, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Port      The I/O port to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..63.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..63.   @param  AndData   The value to AND with the read value from the I/O port.    @return The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|IoBitFieldAnd64
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
comment|/**   Reads a bit field in a 64-bit port, performs a bitwise AND followed by a   bitwise OR, and writes the result back to the bit field in the   64-bit port.    Reads the 64-bit I/O port specified by Port, performs a bitwise AND followed   by a bitwise OR between the read result and the value specified by   AndData, and writes the result to the 64-bit I/O port specified by Port. The   value written to the I/O port is returned. This function must guarantee that   all I/O read and write operations are serialized. Extra left bits in both   AndData and OrData are stripped.    If 64-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 64-bit boundary, then ASSERT().   If StartBit is greater than 63, then ASSERT().   If EndBit is greater than 63, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Port      The I/O port to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..63.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..63.   @param  AndData   The value to AND with the read value from the I/O port.   @param  OrData    The value to OR with the result of the AND operation.    @return The value written back to the I/O port.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|IoBitFieldAndThenOr64
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
comment|/**   Reads an 8-bit MMIO register.    Reads the 8-bit MMIO register specified by Address. The 8-bit read value is   returned. This function must guarantee that all MMIO read and write   operations are serialized.    If 8-bit MMIO register operations are not supported, then ASSERT().    @param  Address The MMIO register to read.    @return The value read.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|MmioRead8
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes an 8-bit MMIO register.    Writes the 8-bit MMIO register specified by Address with the value specified   by Value and returns Value. This function must guarantee that all MMIO read   and write operations are serialized.    If 8-bit MMIO register operations are not supported, then ASSERT().    @param  Address The MMIO register to write.   @param  Value   The value to write to the MMIO register.      @return Value.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|MmioWrite8
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
comment|/**   Reads an 8-bit MMIO register, performs a bitwise OR, and writes the   result back to the 8-bit MMIO register.    Reads the 8-bit MMIO register specified by Address, performs a bitwise    OR between the read result and the value specified by OrData, and   writes the result to the 8-bit MMIO register specified by Address. The value   written to the MMIO register is returned. This function must guarantee that   all MMIO read and write operations are serialized.    If 8-bit MMIO register operations are not supported, then ASSERT().    @param  Address The MMIO register to write.   @param  OrData  The value to OR with the read value from the MMIO register.    @return The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|MmioOr8
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
comment|/**   Reads an 8-bit MMIO register, performs a bitwise AND, and writes the result   back to the 8-bit MMIO register.    Reads the 8-bit MMIO register specified by Address, performs a bitwise AND   between the read result and the value specified by AndData, and writes the   result to the 8-bit MMIO register specified by Address. The value written to   the MMIO register is returned. This function must guarantee that all MMIO   read and write operations are serialized.    If 8-bit MMIO register operations are not supported, then ASSERT().    @param  Address The MMIO register to write.   @param  AndData The value to AND with the read value from the MMIO register.    @return The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|MmioAnd8
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
comment|/**   Reads an 8-bit MMIO register, performs a bitwise AND followed by a bitwise    OR, and writes the result back to the 8-bit MMIO register.    Reads the 8-bit MMIO register specified by Address, performs a bitwise AND   between the read result and the value specified by AndData, performs a   bitwise OR between the result of the AND operation and the value specified by   OrData, and writes the result to the 8-bit MMIO register specified by   Address. The value written to the MMIO register is returned. This function   must guarantee that all MMIO read and write operations are serialized.    If 8-bit MMIO register operations are not supported, then ASSERT().     @param  Address The MMIO register to write.   @param  AndData The value to AND with the read value from the MMIO register.   @param  OrData  The value to OR with the result of the AND operation.    @return The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|MmioAndThenOr8
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
comment|/**   Reads a bit field of a MMIO register.    Reads the bit field in an 8-bit MMIO register. The bit field is specified by   the StartBit and the EndBit. The value of the bit field is returned.    If 8-bit MMIO register operations are not supported, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().    @param  Address   MMIO register to read.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..7.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..7.    @return The value read.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|MmioBitFieldRead8
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
comment|/**   Writes a bit field to a MMIO register.    Writes Value to the bit field of the MMIO register. The bit field is   specified by the StartBit and the EndBit. All other bits in the destination   MMIO register are preserved. The new value of the 8-bit register is returned.    If 8-bit MMIO register operations are not supported, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If Value is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Address   MMIO register to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..7.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..7.   @param  Value     New value of the bit field.    @return The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|MmioBitFieldWrite8
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
comment|/**   Reads a bit field in an 8-bit MMIO register, performs a bitwise OR, and   writes the result back to the bit field in the 8-bit MMIO register.    Reads the 8-bit MMIO register specified by Address, performs a bitwise    OR between the read result and the value specified by OrData, and   writes the result to the 8-bit MMIO register specified by Address. The value   written to the MMIO register is returned. This function must guarantee that   all MMIO read and write operations are serialized. Extra left bits in OrData   are stripped.    If 8-bit MMIO register operations are not supported, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Address   MMIO register to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..7.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..7.   @param  OrData    The value to OR with read value from the MMIO register.    @return The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|MmioBitFieldOr8
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
comment|/**   Reads a bit field in an 8-bit MMIO register, performs a bitwise AND, and   writes the result back to the bit field in the 8-bit MMIO register.    Reads the 8-bit MMIO register specified by Address, performs a bitwise AND   between the read result and the value specified by AndData, and writes the   result to the 8-bit MMIO register specified by Address. The value written to   the MMIO register is returned. This function must guarantee that all MMIO   read and write operations are serialized. Extra left bits in AndData are   stripped.    If 8-bit MMIO register operations are not supported, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Address   MMIO register to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..7.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..7.   @param  AndData   The value to AND with read value from the MMIO register.    @return The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|MmioBitFieldAnd8
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
comment|/**   Reads a bit field in an 8-bit MMIO register, performs a bitwise AND followed   by a bitwise OR, and writes the result back to the bit field in the   8-bit MMIO register.    Reads the 8-bit MMIO register specified by Address, performs a bitwise AND   followed by a bitwise OR between the read result and the value   specified by AndData, and writes the result to the 8-bit MMIO register   specified by Address. The value written to the MMIO register is returned.   This function must guarantee that all MMIO read and write operations are   serialized. Extra left bits in both AndData and OrData are stripped.    If 8-bit MMIO register operations are not supported, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Address   MMIO register to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..7.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..7.   @param  AndData   The value to AND with read value from the MMIO register.   @param  OrData    The value to OR with the result of the AND operation.    @return The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|MmioBitFieldAndThenOr8
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
comment|/**   Reads a 16-bit MMIO register.    Reads the 16-bit MMIO register specified by Address. The 16-bit read value is   returned. This function must guarantee that all MMIO read and write   operations are serialized.    If 16-bit MMIO register operations are not supported, then ASSERT().   If Address is not aligned on a 16-bit boundary, then ASSERT().    @param  Address The MMIO register to read.    @return The value read.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|MmioRead16
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a 16-bit MMIO register.    Writes the 16-bit MMIO register specified by Address with the value specified   by Value and returns Value. This function must guarantee that all MMIO read   and write operations are serialized.    If 16-bit MMIO register operations are not supported, then ASSERT().   If Address is not aligned on a 16-bit boundary, then ASSERT().    @param  Address The MMIO register to write.   @param  Value   The value to write to the MMIO register.      @return Value.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|MmioWrite16
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
comment|/**   Reads a 16-bit MMIO register, performs a bitwise OR, and writes the   result back to the 16-bit MMIO register.    Reads the 16-bit MMIO register specified by Address, performs a bitwise    OR between the read result and the value specified by OrData, and   writes the result to the 16-bit MMIO register specified by Address. The value   written to the MMIO register is returned. This function must guarantee that   all MMIO read and write operations are serialized.    If 16-bit MMIO register operations are not supported, then ASSERT().   If Address is not aligned on a 16-bit boundary, then ASSERT().    @param  Address The MMIO register to write.   @param  OrData  The value to OR with the read value from the MMIO register.    @return The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|MmioOr16
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
comment|/**   Reads a 16-bit MMIO register, performs a bitwise AND, and writes the result   back to the 16-bit MMIO register.    Reads the 16-bit MMIO register specified by Address, performs a bitwise AND   between the read result and the value specified by AndData, and writes the   result to the 16-bit MMIO register specified by Address. The value written to   the MMIO register is returned. This function must guarantee that all MMIO   read and write operations are serialized.    If 16-bit MMIO register operations are not supported, then ASSERT().   If Address is not aligned on a 16-bit boundary, then ASSERT().    @param  Address The MMIO register to write.   @param  AndData The value to AND with the read value from the MMIO register.    @return The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|MmioAnd16
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
comment|/**   Reads a 16-bit MMIO register, performs a bitwise AND followed by a bitwise    OR, and writes the result back to the 16-bit MMIO register.    Reads the 16-bit MMIO register specified by Address, performs a bitwise AND   between the read result and the value specified by AndData, performs a   bitwise OR between the result of the AND operation and the value specified by   OrData, and writes the result to the 16-bit MMIO register specified by   Address. The value written to the MMIO register is returned. This function   must guarantee that all MMIO read and write operations are serialized.    If 16-bit MMIO register operations are not supported, then ASSERT().   If Address is not aligned on a 16-bit boundary, then ASSERT().    @param  Address The MMIO register to write.   @param  AndData The value to AND with the read value from the MMIO register.   @param  OrData  The value to OR with the result of the AND operation.    @return The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|MmioAndThenOr16
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
comment|/**   Reads a bit field of a MMIO register.    Reads the bit field in a 16-bit MMIO register. The bit field is specified by   the StartBit and the EndBit. The value of the bit field is returned.    If 16-bit MMIO register operations are not supported, then ASSERT().   If Address is not aligned on a 16-bit boundary, then ASSERT().   If StartBit is greater than 15, then ASSERT().   If EndBit is greater than 15, then ASSERT().   If EndBit is less than StartBit, then ASSERT().    @param  Address   MMIO register to read.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..15.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..15.    @return The value read.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|MmioBitFieldRead16
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
comment|/**   Writes a bit field to a MMIO register.    Writes Value to the bit field of the MMIO register. The bit field is   specified by the StartBit and the EndBit. All other bits in the destination   MMIO register are preserved. The new value of the 16-bit register is returned.    If 16-bit MMIO register operations are not supported, then ASSERT().   If Address is not aligned on a 16-bit boundary, then ASSERT().   If StartBit is greater than 15, then ASSERT().   If EndBit is greater than 15, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If Value is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Address   MMIO register to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..15.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..15.   @param  Value     New value of the bit field.    @return The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|MmioBitFieldWrite16
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
comment|/**   Reads a bit field in a 16-bit MMIO register, performs a bitwise OR, and   writes the result back to the bit field in the 16-bit MMIO register.    Reads the 16-bit MMIO register specified by Address, performs a bitwise    OR between the read result and the value specified by OrData, and   writes the result to the 16-bit MMIO register specified by Address. The value   written to the MMIO register is returned. This function must guarantee that   all MMIO read and write operations are serialized. Extra left bits in OrData   are stripped.    If 16-bit MMIO register operations are not supported, then ASSERT().   If Address is not aligned on a 16-bit boundary, then ASSERT().   If StartBit is greater than 15, then ASSERT().   If EndBit is greater than 15, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Address   MMIO register to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..15.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..15.   @param  OrData    The value to OR with read value from the MMIO register.    @return The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|MmioBitFieldOr16
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
comment|/**   Reads a bit field in a 16-bit MMIO register, performs a bitwise AND, and   writes the result back to the bit field in the 16-bit MMIO register.    Reads the 16-bit MMIO register specified by Address, performs a bitwise AND   between the read result and the value specified by AndData, and writes the   result to the 16-bit MMIO register specified by Address. The value written to   the MMIO register is returned. This function must guarantee that all MMIO   read and write operations are serialized. Extra left bits in AndData are   stripped.    If 16-bit MMIO register operations are not supported, then ASSERT().   If Address is not aligned on a 16-bit boundary, then ASSERT().   If StartBit is greater than 15, then ASSERT().   If EndBit is greater than 15, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Address   MMIO register to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..15.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..15.   @param  AndData   The value to AND with read value from the MMIO register.    @return The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|MmioBitFieldAnd16
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
comment|/**   Reads a bit field in a 16-bit MMIO register, performs a bitwise AND followed   by a bitwise OR, and writes the result back to the bit field in the   16-bit MMIO register.    Reads the 16-bit MMIO register specified by Address, performs a bitwise AND   followed by a bitwise OR between the read result and the value   specified by AndData, and writes the result to the 16-bit MMIO register   specified by Address. The value written to the MMIO register is returned.   This function must guarantee that all MMIO read and write operations are   serialized. Extra left bits in both AndData and OrData are stripped.    If 16-bit MMIO register operations are not supported, then ASSERT().   If Address is not aligned on a 16-bit boundary, then ASSERT().   If StartBit is greater than 15, then ASSERT().   If EndBit is greater than 15, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Address   MMIO register to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..15.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..15.   @param  AndData   The value to AND with read value from the MMIO register.   @param  OrData    The value to OR with the result of the AND operation.    @return The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|MmioBitFieldAndThenOr16
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
comment|/**   Reads a 32-bit MMIO register.    Reads the 32-bit MMIO register specified by Address. The 32-bit read value is   returned. This function must guarantee that all MMIO read and write   operations are serialized.    If 32-bit MMIO register operations are not supported, then ASSERT().   If Address is not aligned on a 32-bit boundary, then ASSERT().    @param  Address The MMIO register to read.    @return The value read.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|MmioRead32
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a 32-bit MMIO register.    Writes the 32-bit MMIO register specified by Address with the value specified   by Value and returns Value. This function must guarantee that all MMIO read   and write operations are serialized.    If 32-bit MMIO register operations are not supported, then ASSERT().   If Address is not aligned on a 32-bit boundary, then ASSERT().    @param  Address The MMIO register to write.   @param  Value   The value to write to the MMIO register.      @return Value.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|MmioWrite32
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
comment|/**   Reads a 32-bit MMIO register, performs a bitwise OR, and writes the   result back to the 32-bit MMIO register.    Reads the 32-bit MMIO register specified by Address, performs a bitwise    OR between the read result and the value specified by OrData, and   writes the result to the 32-bit MMIO register specified by Address. The value   written to the MMIO register is returned. This function must guarantee that   all MMIO read and write operations are serialized.    If 32-bit MMIO register operations are not supported, then ASSERT().   If Address is not aligned on a 32-bit boundary, then ASSERT().    @param  Address The MMIO register to write.   @param  OrData  The value to OR with the read value from the MMIO register.    @return The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|MmioOr32
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
comment|/**   Reads a 32-bit MMIO register, performs a bitwise AND, and writes the result   back to the 32-bit MMIO register.    Reads the 32-bit MMIO register specified by Address, performs a bitwise AND   between the read result and the value specified by AndData, and writes the   result to the 32-bit MMIO register specified by Address. The value written to   the MMIO register is returned. This function must guarantee that all MMIO   read and write operations are serialized.    If 32-bit MMIO register operations are not supported, then ASSERT().   If Address is not aligned on a 32-bit boundary, then ASSERT().    @param  Address The MMIO register to write.   @param  AndData The value to AND with the read value from the MMIO register.    @return The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|MmioAnd32
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
comment|/**   Reads a 32-bit MMIO register, performs a bitwise AND followed by a bitwise    OR, and writes the result back to the 32-bit MMIO register.    Reads the 32-bit MMIO register specified by Address, performs a bitwise AND   between the read result and the value specified by AndData, performs a   bitwise OR between the result of the AND operation and the value specified by   OrData, and writes the result to the 32-bit MMIO register specified by   Address. The value written to the MMIO register is returned. This function   must guarantee that all MMIO read and write operations are serialized.    If 32-bit MMIO register operations are not supported, then ASSERT().   If Address is not aligned on a 32-bit boundary, then ASSERT().    @param  Address The MMIO register to write.   @param  AndData The value to AND with the read value from the MMIO register.   @param  OrData  The value to OR with the result of the AND operation.    @return The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|MmioAndThenOr32
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
comment|/**   Reads a bit field of a MMIO register.    Reads the bit field in a 32-bit MMIO register. The bit field is specified by   the StartBit and the EndBit. The value of the bit field is returned.    If 32-bit MMIO register operations are not supported, then ASSERT().   If Address is not aligned on a 32-bit boundary, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().    @param  Address   MMIO register to read.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..31.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..31.    @return The value read.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|MmioBitFieldRead32
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
comment|/**   Writes a bit field to a MMIO register.    Writes Value to the bit field of the MMIO register. The bit field is   specified by the StartBit and the EndBit. All other bits in the destination   MMIO register are preserved. The new value of the 32-bit register is returned.    If 32-bit MMIO register operations are not supported, then ASSERT().   If Address is not aligned on a 32-bit boundary, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If Value is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Address   MMIO register to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..31.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..31.   @param  Value     New value of the bit field.    @return The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|MmioBitFieldWrite32
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
comment|/**   Reads a bit field in a 32-bit MMIO register, performs a bitwise OR, and   writes the result back to the bit field in the 32-bit MMIO register.    Reads the 32-bit MMIO register specified by Address, performs a bitwise    OR between the read result and the value specified by OrData, and   writes the result to the 32-bit MMIO register specified by Address. The value   written to the MMIO register is returned. This function must guarantee that   all MMIO read and write operations are serialized. Extra left bits in OrData   are stripped.    If 32-bit MMIO register operations are not supported, then ASSERT().   If Address is not aligned on a 32-bit boundary, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Address   MMIO register to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..31.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..31.   @param  OrData    The value to OR with read value from the MMIO register.    @return The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|MmioBitFieldOr32
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
comment|/**   Reads a bit field in a 32-bit MMIO register, performs a bitwise AND, and   writes the result back to the bit field in the 32-bit MMIO register.    Reads the 32-bit MMIO register specified by Address, performs a bitwise AND   between the read result and the value specified by AndData, and writes the   result to the 32-bit MMIO register specified by Address. The value written to   the MMIO register is returned. This function must guarantee that all MMIO   read and write operations are serialized. Extra left bits in AndData are   stripped.    If 32-bit MMIO register operations are not supported, then ASSERT().   If Address is not aligned on a 32-bit boundary, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Address   MMIO register to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..31.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..31.   @param  AndData   The value to AND with read value from the MMIO register.    @return The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|MmioBitFieldAnd32
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
comment|/**   Reads a bit field in a 32-bit MMIO register, performs a bitwise AND followed   by a bitwise OR, and writes the result back to the bit field in the   32-bit MMIO register.    Reads the 32-bit MMIO register specified by Address, performs a bitwise AND   followed by a bitwise OR between the read result and the value   specified by AndData, and writes the result to the 32-bit MMIO register   specified by Address. The value written to the MMIO register is returned.   This function must guarantee that all MMIO read and write operations are   serialized. Extra left bits in both AndData and OrData are stripped.    If 32-bit MMIO register operations are not supported, then ASSERT().   If Address is not aligned on a 32-bit boundary, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Address   MMIO register to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..31.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..31.   @param  AndData   The value to AND with read value from the MMIO register.   @param  OrData    The value to OR with the result of the AND operation.    @return The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|MmioBitFieldAndThenOr32
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
comment|/**   Reads a 64-bit MMIO register.    Reads the 64-bit MMIO register specified by Address. The 64-bit read value is   returned. This function must guarantee that all MMIO read and write   operations are serialized.    If 64-bit MMIO register operations are not supported, then ASSERT().   If Address is not aligned on a 64-bit boundary, then ASSERT().    @param  Address The MMIO register to read.    @return The value read.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|MmioRead64
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a 64-bit MMIO register.    Writes the 64-bit MMIO register specified by Address with the value specified   by Value and returns Value. This function must guarantee that all MMIO read   and write operations are serialized.    If 64-bit MMIO register operations are not supported, then ASSERT().   If Address is not aligned on a 64-bit boundary, then ASSERT().    @param  Address The MMIO register to write.   @param  Value   The value to write to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|MmioWrite64
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
comment|/**   Reads a 64-bit MMIO register, performs a bitwise OR, and writes the   result back to the 64-bit MMIO register.    Reads the 64-bit MMIO register specified by Address, performs a bitwise    OR between the read result and the value specified by OrData, and   writes the result to the 64-bit MMIO register specified by Address. The value   written to the MMIO register is returned. This function must guarantee that   all MMIO read and write operations are serialized.    If 64-bit MMIO register operations are not supported, then ASSERT().   If Address is not aligned on a 64-bit boundary, then ASSERT().    @param  Address The MMIO register to write.   @param  OrData  The value to OR with the read value from the MMIO register.    @return The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|MmioOr64
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
comment|/**   Reads a 64-bit MMIO register, performs a bitwise AND, and writes the result   back to the 64-bit MMIO register.    Reads the 64-bit MMIO register specified by Address, performs a bitwise AND   between the read result and the value specified by AndData, and writes the   result to the 64-bit MMIO register specified by Address. The value written to   the MMIO register is returned. This function must guarantee that all MMIO   read and write operations are serialized.    If 64-bit MMIO register operations are not supported, then ASSERT().   If Address is not aligned on a 64-bit boundary, then ASSERT().    @param  Address The MMIO register to write.   @param  AndData The value to AND with the read value from the MMIO register.    @return The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|MmioAnd64
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
comment|/**   Reads a 64-bit MMIO register, performs a bitwise AND followed by a bitwise    OR, and writes the result back to the 64-bit MMIO register.    Reads the 64-bit MMIO register specified by Address, performs a bitwise AND   between the read result and the value specified by AndData, performs a   bitwise OR between the result of the AND operation and the value specified by   OrData, and writes the result to the 64-bit MMIO register specified by   Address. The value written to the MMIO register is returned. This function   must guarantee that all MMIO read and write operations are serialized.    If 64-bit MMIO register operations are not supported, then ASSERT().   If Address is not aligned on a 64-bit boundary, then ASSERT().    @param  Address The MMIO register to write.   @param  AndData The value to AND with the read value from the MMIO register.   @param  OrData  The value to OR with the result of the AND operation.    @return The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|MmioAndThenOr64
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
comment|/**   Reads a bit field of a MMIO register.    Reads the bit field in a 64-bit MMIO register. The bit field is specified by   the StartBit and the EndBit. The value of the bit field is returned.    If 64-bit MMIO register operations are not supported, then ASSERT().   If Address is not aligned on a 64-bit boundary, then ASSERT().   If StartBit is greater than 63, then ASSERT().   If EndBit is greater than 63, then ASSERT().   If EndBit is less than StartBit, then ASSERT().    @param  Address   MMIO register to read.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..63.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..63.    @return The value read.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|MmioBitFieldRead64
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
comment|/**   Writes a bit field to a MMIO register.    Writes Value to the bit field of the MMIO register. The bit field is   specified by the StartBit and the EndBit. All other bits in the destination   MMIO register are preserved. The new value of the 64-bit register is returned.    If 64-bit MMIO register operations are not supported, then ASSERT().   If Address is not aligned on a 64-bit boundary, then ASSERT().   If StartBit is greater than 63, then ASSERT().   If EndBit is greater than 63, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If Value is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Address   MMIO register to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..63.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..63.   @param  Value     New value of the bit field.    @return The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|MmioBitFieldWrite64
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
comment|/**   Reads a bit field in a 64-bit MMIO register, performs a bitwise OR, and   writes the result back to the bit field in the 64-bit MMIO register.    Reads the 64-bit MMIO register specified by Address, performs a bitwise    OR between the read result and the value specified by OrData, and   writes the result to the 64-bit MMIO register specified by Address. The value   written to the MMIO register is returned. This function must guarantee that   all MMIO read and write operations are serialized. Extra left bits in OrData   are stripped.    If 64-bit MMIO register operations are not supported, then ASSERT().   If Address is not aligned on a 64-bit boundary, then ASSERT().   If StartBit is greater than 63, then ASSERT().   If EndBit is greater than 63, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Address   MMIO register to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..63.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..63.   @param  OrData    The value to OR with read value from the MMIO register.    @return The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|MmioBitFieldOr64
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
comment|/**   Reads a bit field in a 64-bit MMIO register, performs a bitwise AND, and   writes the result back to the bit field in the 64-bit MMIO register.    Reads the 64-bit MMIO register specified by Address, performs a bitwise AND   between the read result and the value specified by AndData, and writes the   result to the 64-bit MMIO register specified by Address. The value written to   the MMIO register is returned. This function must guarantee that all MMIO   read and write operations are serialized. Extra left bits in AndData are   stripped.    If 64-bit MMIO register operations are not supported, then ASSERT().   If Address is not aligned on a 64-bit boundary, then ASSERT().   If StartBit is greater than 63, then ASSERT().   If EndBit is greater than 63, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Address   MMIO register to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..63.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..63.   @param  AndData   The value to AND with read value from the MMIO register.    @return The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|MmioBitFieldAnd64
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
comment|/**   Reads a bit field in a 64-bit MMIO register, performs a bitwise AND followed   by a bitwise OR, and writes the result back to the bit field in the   64-bit MMIO register.    Reads the 64-bit MMIO register specified by Address, performs a bitwise AND   followed by a bitwise OR between the read result and the value   specified by AndData, and writes the result to the 64-bit MMIO register   specified by Address. The value written to the MMIO register is returned.   This function must guarantee that all MMIO read and write operations are   serialized. Extra left bits in both AndData and OrData are stripped.    If 64-bit MMIO register operations are not supported, then ASSERT().   If Address is not aligned on a 64-bit boundary, then ASSERT().   If StartBit is greater than 63, then ASSERT().   If EndBit is greater than 63, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Address   MMIO register to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..63.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..63.   @param  AndData   The value to AND with read value from the MMIO register.   @param  OrData    The value to OR with the result of the AND operation.    @return The value written back to the MMIO register.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|MmioBitFieldAndThenOr64
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
comment|/**   Copy data from MMIO region to system memory by using 8-bit access.    Copy data from MMIO region specified by starting address StartAddress    to system memory specified by Buffer by using 8-bit access. The total    number of byte to be copied is specified by Length. Buffer is returned.      If Length is greater than (MAX_ADDRESS - StartAddress + 1), then ASSERT().    If Length is greater than (MAX_ADDRESS - Buffer + 1), then ASSERT().     @param  StartAddress    Starting address for the MMIO region to be copied from.   @param  Length          The size, in bytes, of Buffer.   @param  Buffer          Pointer to a system memory buffer receiving the data read.    @return Buffer  **/
end_comment

begin_function_decl
name|UINT8
modifier|*
name|EFIAPI
name|MmioReadBuffer8
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
comment|/**   Copy data from MMIO region to system memory by using 16-bit access.    Copy data from MMIO region specified by starting address StartAddress    to system memory specified by Buffer by using 16-bit access. The total    number of byte to be copied is specified by Length. Buffer is returned.      If StartAddress is not aligned on a 16-bit boundary, then ASSERT().    If Length is greater than (MAX_ADDRESS - StartAddress + 1), then ASSERT().    If Length is greater than (MAX_ADDRESS - Buffer + 1), then ASSERT().    If Length is not aligned on a 16-bit boundary, then ASSERT().   If Buffer is not aligned on a 16-bit boundary, then ASSERT().    @param  StartAddress    Starting address for the MMIO region to be copied from.   @param  Length          The size, in bytes, of Buffer.   @param  Buffer          Pointer to a system memory buffer receiving the data read.    @return Buffer  **/
end_comment

begin_function_decl
name|UINT16
modifier|*
name|EFIAPI
name|MmioReadBuffer16
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
comment|/**   Copy data from MMIO region to system memory by using 32-bit access.    Copy data from MMIO region specified by starting address StartAddress    to system memory specified by Buffer by using 32-bit access. The total    number of byte to be copied is specified by Length. Buffer is returned.      If StartAddress is not aligned on a 32-bit boundary, then ASSERT().    If Length is greater than (MAX_ADDRESS - StartAddress + 1), then ASSERT().    If Length is greater than (MAX_ADDRESS - Buffer + 1), then ASSERT().    If Length is not aligned on a 32-bit boundary, then ASSERT().   If Buffer is not aligned on a 32-bit boundary, then ASSERT().    @param  StartAddress    Starting address for the MMIO region to be copied from.   @param  Length          The size, in bytes, of Buffer.   @param  Buffer          Pointer to a system memory buffer receiving the data read.    @return Buffer  **/
end_comment

begin_function_decl
name|UINT32
modifier|*
name|EFIAPI
name|MmioReadBuffer32
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
comment|/**   Copy data from MMIO region to system memory by using 64-bit access.    Copy data from MMIO region specified by starting address StartAddress    to system memory specified by Buffer by using 64-bit access. The total    number of byte to be copied is specified by Length. Buffer is returned.      If StartAddress is not aligned on a 64-bit boundary, then ASSERT().    If Length is greater than (MAX_ADDRESS - StartAddress + 1), then ASSERT().    If Length is greater than (MAX_ADDRESS - Buffer + 1), then ASSERT().    If Length is not aligned on a 64-bit boundary, then ASSERT().   If Buffer is not aligned on a 64-bit boundary, then ASSERT().    @param  StartAddress    Starting address for the MMIO region to be copied from.   @param  Length          The size, in bytes, of Buffer.   @param  Buffer          Pointer to a system memory buffer receiving the data read.    @return Buffer  **/
end_comment

begin_function_decl
name|UINT64
modifier|*
name|EFIAPI
name|MmioReadBuffer64
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
comment|/**   Copy data from system memory to MMIO region by using 8-bit access.    Copy data from system memory specified by Buffer to MMIO region specified    by starting address StartAddress by using 8-bit access. The total number    of byte to be copied is specified by Length. Buffer is returned.      If Length is greater than (MAX_ADDRESS - StartAddress + 1), then ASSERT().    If Length is greater than (MAX_ADDRESS -Buffer + 1), then ASSERT().     @param  StartAddress    Starting address for the MMIO region to be copied to.   @param  Length          The size, in bytes, of Buffer.   @param  Buffer          Pointer to a system memory buffer containing the data to write.    @return Buffer  **/
end_comment

begin_function_decl
name|UINT8
modifier|*
name|EFIAPI
name|MmioWriteBuffer8
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
comment|/**   Copy data from system memory to MMIO region by using 16-bit access.    Copy data from system memory specified by Buffer to MMIO region specified    by starting address StartAddress by using 16-bit access. The total number    of byte to be copied is specified by Length. Buffer is returned.      If StartAddress is not aligned on a 16-bit boundary, then ASSERT().    If Length is greater than (MAX_ADDRESS - StartAddress + 1), then ASSERT().    If Length is greater than (MAX_ADDRESS -Buffer + 1), then ASSERT().    If Length is not aligned on a 16-bit boundary, then ASSERT().    If Buffer is not aligned on a 16-bit boundary, then ASSERT().    @param  StartAddress    Starting address for the MMIO region to be copied to.   @param  Length          The size, in bytes, of Buffer.   @param  Buffer          Pointer to a system memory buffer containing the data to write.    @return Buffer  **/
end_comment

begin_function_decl
name|UINT16
modifier|*
name|EFIAPI
name|MmioWriteBuffer16
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
comment|/**   Copy data from system memory to MMIO region by using 32-bit access.    Copy data from system memory specified by Buffer to MMIO region specified    by starting address StartAddress by using 32-bit access. The total number    of byte to be copied is specified by Length. Buffer is returned.      If StartAddress is not aligned on a 32-bit boundary, then ASSERT().    If Length is greater than (MAX_ADDRESS - StartAddress + 1), then ASSERT().    If Length is greater than (MAX_ADDRESS -Buffer + 1), then ASSERT().    If Length is not aligned on a 32-bit boundary, then ASSERT().    If Buffer is not aligned on a 32-bit boundary, then ASSERT().    @param  StartAddress    Starting address for the MMIO region to be copied to.   @param  Length          The size, in bytes, of Buffer.   @param  Buffer          Pointer to a system memory buffer containing the data to write.    @return Buffer  **/
end_comment

begin_function_decl
name|UINT32
modifier|*
name|EFIAPI
name|MmioWriteBuffer32
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
comment|/**   Copy data from system memory to MMIO region by using 64-bit access.    Copy data from system memory specified by Buffer to MMIO region specified    by starting address StartAddress by using 64-bit access. The total number    of byte to be copied is specified by Length. Buffer is returned.      If StartAddress is not aligned on a 64-bit boundary, then ASSERT().    If Length is greater than (MAX_ADDRESS - StartAddress + 1), then ASSERT().    If Length is greater than (MAX_ADDRESS -Buffer + 1), then ASSERT().    If Length is not aligned on a 64-bit boundary, then ASSERT().    If Buffer is not aligned on a 64-bit boundary, then ASSERT().    @param  StartAddress    Starting address for the MMIO region to be copied to.   @param  Length          The size, in bytes, of Buffer.   @param  Buffer          Pointer to a system memory buffer containing the data to write.    @return Buffer  **/
end_comment

begin_function_decl
name|UINT64
modifier|*
name|EFIAPI
name|MmioWriteBuffer64
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

