begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   I/O Library. This file has compiler specifics for Microsft C as there is no   ANSI C standard for doing IO.    MSC - uses intrinsic functions and the optimize will remove the function call   overhead.    We don't advocate putting compiler specifics in libraries or drivers but there   is no other way to make this work.    Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|"BaseIoLibIntrinsicInternal.h"
end_include

begin_comment
comment|//
end_comment

begin_comment
comment|// Microsoft Visual Studio 7.1 Function Prototypes for I/O Intrinsics.
end_comment

begin_comment
comment|//
end_comment

begin_function_decl
name|int
name|_inp
parameter_list|(
name|unsigned
name|short
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|short
name|_inpw
parameter_list|(
name|unsigned
name|short
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|_inpd
parameter_list|(
name|unsigned
name|short
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_outp
parameter_list|(
name|unsigned
name|short
name|port
parameter_list|,
name|int
name|databyte
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|short
name|_outpw
parameter_list|(
name|unsigned
name|short
name|port
parameter_list|,
name|unsigned
name|short
name|dataword
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|_outpd
parameter_list|(
name|unsigned
name|short
name|port
parameter_list|,
name|unsigned
name|long
name|dataword
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_ReadWriteBarrier
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_pragma
pragma|#
directive|pragma
name|intrinsic
name|(
name|_inp
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|intrinsic
name|(
name|_inpw
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|intrinsic
name|(
name|_inpd
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|intrinsic
name|(
name|_outp
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|intrinsic
name|(
name|_outpw
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|intrinsic
name|(
name|_outpd
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|intrinsic
name|(
name|_ReadWriteBarrier
name|)
end_pragma

begin_comment
comment|//
end_comment

begin_comment
comment|// _ReadWriteBarrier() forces memory reads and writes to complete at the point
end_comment

begin_comment
comment|// in the call. This is only a hint to the compiler and does emit code.
end_comment

begin_comment
comment|// In past versions of the compiler, _ReadWriteBarrier was enforced only
end_comment

begin_comment
comment|// locally and did not affect functions up the call tree. In Visual C++
end_comment

begin_comment
comment|// 2005, _ReadWriteBarrier is enforced all the way up the call tree.
end_comment

begin_comment
comment|//
end_comment

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
name|UINT8
name|Value
decl_stmt|;
name|_ReadWriteBarrier
argument_list|()
expr_stmt|;
name|Value
operator|=
operator|(
name|UINT8
operator|)
name|_inp
argument_list|(
operator|(
name|UINT16
operator|)
name|Port
argument_list|)
expr_stmt|;
name|_ReadWriteBarrier
argument_list|()
expr_stmt|;
return|return
name|Value
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
name|_ReadWriteBarrier
argument_list|()
expr_stmt|;
operator|(
name|UINT8
operator|)
name|_outp
argument_list|(
operator|(
name|UINT16
operator|)
name|Port
argument_list|,
name|Value
argument_list|)
expr_stmt|;
name|_ReadWriteBarrier
argument_list|()
expr_stmt|;
return|return
name|Value
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
name|UINT16
name|Value
decl_stmt|;
name|ASSERT
argument_list|(
operator|(
name|Port
operator|&
literal|1
operator|)
operator|==
literal|0
argument_list|)
expr_stmt|;
name|_ReadWriteBarrier
argument_list|()
expr_stmt|;
name|Value
operator|=
name|_inpw
argument_list|(
operator|(
name|UINT16
operator|)
name|Port
argument_list|)
expr_stmt|;
name|_ReadWriteBarrier
argument_list|()
expr_stmt|;
return|return
name|Value
return|;
block|}
end_function

begin_comment
comment|/**   Writes a 16-bit I/O port.    Writes the 16-bit I/O port specified by Port with the value specified by Value   and returns Value. This function must guarantee that all I/O read and write   operations are serialized.    If 16-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 16-bit boundary, then ASSERT().      @param  Port  The I/O port to write.   @param  Value The value to write to the I/O port.    @return The value written to the I/O port.  **/
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
operator|(
name|Port
operator|&
literal|1
operator|)
operator|==
literal|0
argument_list|)
expr_stmt|;
name|_ReadWriteBarrier
argument_list|()
expr_stmt|;
name|_outpw
argument_list|(
operator|(
name|UINT16
operator|)
name|Port
argument_list|,
name|Value
argument_list|)
expr_stmt|;
name|_ReadWriteBarrier
argument_list|()
expr_stmt|;
return|return
name|Value
return|;
block|}
end_function

begin_comment
comment|/**   Reads a 32-bit I/O port.    Reads the 32-bit I/O port specified by Port. The 32-bit read value is returned.   This function must guarantee that all I/O read and write operations are   serialized.    If 32-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 32-bit boundary, then ASSERT().      @param  Port  The I/O port to read.    @return The value read.  **/
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
name|UINT32
name|Value
decl_stmt|;
name|ASSERT
argument_list|(
operator|(
name|Port
operator|&
literal|3
operator|)
operator|==
literal|0
argument_list|)
expr_stmt|;
name|_ReadWriteBarrier
argument_list|()
expr_stmt|;
name|Value
operator|=
name|_inpd
argument_list|(
operator|(
name|UINT16
operator|)
name|Port
argument_list|)
expr_stmt|;
name|_ReadWriteBarrier
argument_list|()
expr_stmt|;
return|return
name|Value
return|;
block|}
end_function

begin_comment
comment|/**   Writes a 32-bit I/O port.    Writes the 32-bit I/O port specified by Port with the value specified by Value   and returns Value. This function must guarantee that all I/O read and write   operations are serialized.    If 32-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 32-bit boundary, then ASSERT().      @param  Port  The I/O port to write.   @param  Value The value to write to the I/O port.    @return The value written to the I/O port.  **/
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
operator|(
name|Port
operator|&
literal|3
operator|)
operator|==
literal|0
argument_list|)
expr_stmt|;
name|_ReadWriteBarrier
argument_list|()
expr_stmt|;
name|_outpd
argument_list|(
operator|(
name|UINT16
operator|)
name|Port
argument_list|,
name|Value
argument_list|)
expr_stmt|;
name|_ReadWriteBarrier
argument_list|()
expr_stmt|;
return|return
name|Value
return|;
block|}
end_function

end_unit

