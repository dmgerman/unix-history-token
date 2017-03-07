begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   AsmWriteMm4 function    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_comment
comment|/**   Writes the current value of 64-bit MMX Register #4 (MM4).    Writes the current value of MM4. This function is only available on IA32 and   x64.    @param  Value The 64-bit value to write to MM4.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|AsmWriteMm4
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
block|{
name|_asm
block|{
name|movq
name|mm4
decl_stmt|,
name|qword
name|ptr
index|[
name|Value
index|]
name|emms
block|}
block|}
end_function

end_unit

