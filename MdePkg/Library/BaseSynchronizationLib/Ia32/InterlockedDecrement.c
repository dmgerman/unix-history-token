begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   InterlockedDecrement function    Copyright (c) 2006 - 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_comment
comment|/**   Performs an atomic decrement of an 32-bit unsigned integer.    Performs an atomic decrement of the 32-bit unsigned integer specified by   Value and returns the decrement value. The decrement operation must be   performed using MP safe mechanisms. The state of the return value is not   guaranteed to be MP safe.    @param  Value A pointer to the 32-bit value to decrement.    @return The decrement value.  **/
end_comment

begin_function
name|UINT32
name|EFIAPI
name|InternalSyncDecrement
parameter_list|(
name|IN
specifier|volatile
name|UINT32
modifier|*
name|Value
parameter_list|)
block|{
name|_asm
block|{
name|mov
name|eax
decl_stmt|,
name|Value
name|lock
name|dec
name|dword
name|ptr
index|[
name|eax
index|]
name|mov
name|eax
decl_stmt|, [
name|eax
decl|]
block|}
block|}
end_function

end_unit

