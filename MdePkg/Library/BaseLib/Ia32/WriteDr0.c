begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   AsmWriteDr0 function    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_comment
comment|/**   Writes a value to Debug Register 0 (DR0).    Writes and returns a new value to DR0. This function is only available on   IA-32 and x64. This writes a 32-bit value on IA-32 and a 64-bit value on x64.    @param  Value The value to write to Dr0.    @return The value written to Debug Register 0 (DR0).  **/
end_comment

begin_function
name|UINTN
name|EFIAPI
name|AsmWriteDr0
parameter_list|(
name|IN
name|UINTN
name|Value
parameter_list|)
block|{
name|_asm
block|{
name|mov
name|eax
decl_stmt|,
name|Value
name|mov
name|dr0
decl_stmt|,
name|eax
block|}
block|}
end_function

end_unit

