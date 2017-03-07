begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   AsmReadMm5 function    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_comment
comment|/**   Reads the current value of 64-bit MMX Register #5 (MM5).    Reads and returns the current value of MM5. This function is only available   on IA-32 and x64.    @return The current value of MM5.  **/
end_comment

begin_function
name|UINT64
name|EFIAPI
name|AsmReadMm5
parameter_list|(
name|VOID
parameter_list|)
block|{
name|_asm
block|{
name|push
name|eax
name|push
name|eax
name|movq
index|[
name|esp
index|]
decl_stmt|,
name|mm5
name|pop
name|eax
name|pop
name|edx
name|emms
block|}
block|}
end_function

end_unit

