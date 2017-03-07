begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   I/O Library for EBC.    EBC does not support port I/O.  All APIs in this file ASSERT().    Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>   Copyright (c) 2017, AMD Incorporated. All rights reserved.<BR>    This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|"BaseIoLibIntrinsicInternal.h"
end_include

begin_comment
comment|/**   Reads an 8-bit I/O port.    Reads the 8-bit I/O port specified by Port. The 8-bit read value is returned.   This function must guarantee that all I/O read and write operations are   serialized.    If 8-bit I/O port operations are not supported, then ASSERT().    @param  Port  The I/O port to read.    @return The value read.  **/
end_comment

begin_function
name|UINT8
name|EFIAPI
name|IoRead8
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/**   Writes an 8-bit I/O port.    Writes the 8-bit I/O port specified by Port with the value specified by Value   and returns Value. This function must guarantee that all I/O read and write   operations are serialized.    If 8-bit I/O port operations are not supported, then ASSERT().    @param  Port  The I/O port to write.   @param  Value The value to write to the I/O port.    @return The value written to the I/O port.  **/
end_comment

begin_function
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
block|{
name|ASSERT
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/**   Reads a 16-bit I/O port.    Reads the 16-bit I/O port specified by Port. The 16-bit read value is returned.   This function must guarantee that all I/O read and write operations are   serialized.    If 16-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 16-bit boundary, then ASSERT().    @param  Port  The I/O port to read.    @return The value read.  **/
end_comment

begin_function
name|UINT16
name|EFIAPI
name|IoRead16
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/**   Writes a 16-bit I/O port.    Writes the 16-bit I/O port specified by Port with the value specified by Value   and returns Value. This function must guarantee that all I/O read and write   operations are serialized.    If 16-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 16-bit boundary, then ASSERT().    @param  Port  The I/O port to write.   @param  Value The value to write to the I/O port.    @return The value written to the I/O port.  **/
end_comment

begin_function
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
block|{
name|ASSERT
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/**   Reads a 32-bit I/O port.    Reads the 32-bit I/O port specified by Port. The 32-bit read value is returned.   This function must guarantee that all I/O read and write operations are   serialized.    If 32-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 32-bit boundary, then ASSERT().    @param  Port  The I/O port to read.    @return The value read.  **/
end_comment

begin_function
name|UINT32
name|EFIAPI
name|IoRead32
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/**   Writes a 32-bit I/O port.    Writes the 32-bit I/O port specified by Port with the value specified by Value   and returns Value. This function must guarantee that all I/O read and write   operations are serialized.    If 32-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 32-bit boundary, then ASSERT().    @param  Port  The I/O port to write.   @param  Value The value to write to the I/O port.    @return The value written to the I/O port.  **/
end_comment

begin_function
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
block|{
name|ASSERT
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/**   Reads an 8-bit I/O port fifo into a block of memory.    Reads the 8-bit I/O fifo port specified by Port.   The port is read Count times, and the read data is   stored in the provided Buffer.    This function must guarantee that all I/O read and write operations are   serialized.    If 8-bit I/O port operations are not supported, then ASSERT().    @param  Port    The I/O port to read.   @param  Count   The number of times to read I/O port.   @param  Buffer  The buffer to store the read data into.  **/
end_comment

begin_function
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
block|{
name|ASSERT
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**   Writes a block of memory into an 8-bit I/O port fifo.    Writes the 8-bit I/O fifo port specified by Port.   The port is written Count times, and the write data is   retrieved from the provided Buffer.    This function must guarantee that all I/O write and write operations are   serialized.    If 8-bit I/O port operations are not supported, then ASSERT().    @param  Port    The I/O port to write.   @param  Count   The number of times to write I/O port.   @param  Buffer  The buffer to retrieve the write data from.  **/
end_comment

begin_function
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
block|{
name|ASSERT
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**   Reads a 16-bit I/O port fifo into a block of memory.    Reads the 16-bit I/O fifo port specified by Port.   The port is read Count times, and the read data is   stored in the provided Buffer.    This function must guarantee that all I/O read and write operations are   serialized.    If 16-bit I/O port operations are not supported, then ASSERT().    @param  Port    The I/O port to read.   @param  Count   The number of times to read I/O port.   @param  Buffer  The buffer to store the read data into.  **/
end_comment

begin_function
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
block|{
name|ASSERT
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**   Writes a block of memory into a 16-bit I/O port fifo.    Writes the 16-bit I/O fifo port specified by Port.   The port is written Count times, and the write data is   retrieved from the provided Buffer.    This function must guarantee that all I/O write and write operations are   serialized.    If 16-bit I/O port operations are not supported, then ASSERT().    @param  Port    The I/O port to write.   @param  Count   The number of times to write I/O port.   @param  Buffer  The buffer to retrieve the write data from.  **/
end_comment

begin_function
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
block|{
name|ASSERT
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**   Reads a 32-bit I/O port fifo into a block of memory.    Reads the 32-bit I/O fifo port specified by Port.   The port is read Count times, and the read data is   stored in the provided Buffer.    This function must guarantee that all I/O read and write operations are   serialized.    If 32-bit I/O port operations are not supported, then ASSERT().    @param  Port    The I/O port to read.   @param  Count   The number of times to read I/O port.   @param  Buffer  The buffer to store the read data into.  **/
end_comment

begin_function
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
block|{
name|ASSERT
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**   Writes a block of memory into a 32-bit I/O port fifo.    Writes the 32-bit I/O fifo port specified by Port.   The port is written Count times, and the write data is   retrieved from the provided Buffer.    This function must guarantee that all I/O write and write operations are   serialized.    If 32-bit I/O port operations are not supported, then ASSERT().    @param  Port    The I/O port to write.   @param  Count   The number of times to write I/O port.   @param  Buffer  The buffer to retrieve the write data from.  **/
end_comment

begin_function
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
block|{
name|ASSERT
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

