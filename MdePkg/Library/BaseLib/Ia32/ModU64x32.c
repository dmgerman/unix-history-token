begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Calculate the remainder of a 64-bit integer by a 32-bit integer    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_comment
comment|/**   Divides a 64-bit unsigned integer by a 32-bit unsigned integer and   generates a 32-bit unsigned remainder.    This function divides the 64-bit unsigned value Dividend by the 32-bit   unsigned value Divisor and generates a 32-bit remainder. This function   returns the 32-bit unsigned remainder.    @param  Dividend  A 64-bit unsigned value.   @param  Divisor   A 32-bit unsigned value.    @return Dividend % Divisor  **/
end_comment

begin_function
name|UINT32
name|EFIAPI
name|InternalMathModU64x32
parameter_list|(
name|IN
name|UINT64
name|Dividend
parameter_list|,
name|IN
name|UINT32
name|Divisor
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
name|Dividend
operator|+
literal|4
index|]
name|mov
name|ecx
decl_stmt|,
name|Divisor
name|xor
name|edx
decl_stmt|,
name|edx
name|div
name|ecx
name|mov
name|eax
decl_stmt|,
name|dword
name|ptr
index|[
name|Dividend
operator|+
literal|0
index|]
name|div
name|ecx
name|mov
name|eax
decl_stmt|,
name|edx
block|}
block|}
end_function

end_unit

