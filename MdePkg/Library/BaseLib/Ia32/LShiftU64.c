begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   64-bit left shift function for IA-32.    Copyright (c) 2006 - 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_comment
comment|/**   Shifts a 64-bit integer left between 0 and 63 bits. The low bits   are filled with zeros. The shifted value is returned.    This function shifts the 64-bit value Operand to the left by Count bits. The   low Count bits are set to zero. The shifted value is returned.    @param  Operand The 64-bit operand to shift left.   @param  Count   The number of bits to shift left.    @return Operand<< Count  **/
end_comment

begin_function
name|UINT64
name|EFIAPI
name|InternalMathLShiftU64
parameter_list|(
name|IN
name|UINT64
name|Operand
parameter_list|,
name|IN
name|UINTN
name|Count
parameter_list|)
block|{
name|_asm
block|{
name|mov
name|cl
decl_stmt|,
name|byte
name|ptr
index|[
name|Count
index|]
name|xor
name|eax
decl_stmt|,
name|eax
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
name|test
name|cl
decl_stmt|, 32
comment|// Count>= 32?
name|jnz
name|L0
name|mov
name|eax
decl_stmt|,
name|edx
name|mov
name|edx
decl_stmt|,
name|dword
name|ptr
index|[
name|Operand
operator|+
literal|4
index|]
name|L0
range|:
name|shld
name|edx
decl_stmt|,
name|eax
decl_stmt|,
name|cl
name|shl
name|eax
decl_stmt|,
name|cl
block|}
block|}
end_function

end_unit

