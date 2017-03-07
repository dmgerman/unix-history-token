begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Implementation of 64-bit swap bytes    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_comment
comment|/**   Switches the endianess of a 64-bit integer.    This function swaps the bytes in a 64-bit unsigned value to switch the value   from little endian to big endian or vice versa. The byte swapped value is   returned.    @param  Operand A 64-bit unsigned value.    @return The byte swaped Operand.  **/
end_comment

begin_function
name|UINT64
name|EFIAPI
name|InternalMathSwapBytes64
parameter_list|(
name|IN
name|UINT64
name|Operand
parameter_list|)
block|{
name|_asm
block|{
name|mov
name|eax
decl_stmt|,
name|dword
name|ptr
index|[
name|Operand
operator|+
literal|4
index|]
name|mov
name|edx
decl_stmt|,
name|dword
name|ptr
index|[
name|Operand
operator|+
literal|0
index|]
name|bswap
name|eax
name|bswap
name|edx
block|}
block|}
end_function

end_unit

