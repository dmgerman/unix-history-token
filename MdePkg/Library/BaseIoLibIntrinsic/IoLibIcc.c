begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   I/O Library. This file has compiler specifics for ICC as there   is no ANSI C standard for doing IO.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials are   licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
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
name|UINT8
name|Data
decl_stmt|;
asm|__asm {
asm|mov dx, word ptr [Port]
asm|in  al, dx
asm|mov Data, al
asm|}
return|return
name|Data
return|;
block|}
end_function

begin_comment
comment|/**   Writes an 8-bit I/O port.    Writes the 8-bit I/O port specified by Port with the value specified by Value   and returns Value. This function must guarantee that all I/O read and write   operations are serialized.    If 8-bit I/O port operations are not supported, then ASSERT().    @param  Port  The I/O port to write.   @param  Value The value to write to the I/O port.    @return The value written the I/O port.  **/
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
asm|__asm {
asm|mov al, byte ptr [Value]
asm|mov dx, word ptr [Port]
asm|out dx, al
asm|}
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
name|Data
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
asm|__asm {
asm|mov dx, word ptr [Port]
asm|in  ax, dx
asm|mov word ptr [Data], ax
asm|}
return|return
name|Data
return|;
block|}
end_function

begin_comment
comment|/**   Writes a 16-bit I/O port.    Writes the 16-bit I/O port specified by Port with the value specified by Value   and returns Value. This function must guarantee that all I/O read and write   operations are serialized.    If 16-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 16-bit boundary, then ASSERT().      @param  Port  The I/O port to write.   @param  Value The value to write to the I/O port.    @return The value written the I/O port.  **/
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
asm|__asm {
asm|mov ax, word ptr [Value]
asm|mov dx, word ptr [Port]
asm|out dx, ax
asm|}
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
name|Data
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
asm|__asm {
asm|mov dx, word ptr [Port]
asm|in  eax, dx
asm|mov dword ptr [Data], eax
asm|}
return|return
name|Data
return|;
block|}
end_function

begin_comment
comment|/**   Writes a 32-bit I/O port.    Writes the 32-bit I/O port specified by Port with the value specified by Value   and returns Value. This function must guarantee that all I/O read and write   operations are serialized.    If 32-bit I/O port operations are not supported, then ASSERT().   If Port is not aligned on a 32-bit boundary, then ASSERT().      @param  Port  The I/O port to write.   @param  Value The value to write to the I/O port.    @return The value written the I/O port.  **/
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
asm|__asm {
asm|mov eax, dword ptr [Value]
asm|mov dx, word ptr [Port]
asm|out dx, eax
asm|}
return|return
name|Value
return|;
block|}
end_function

end_unit

