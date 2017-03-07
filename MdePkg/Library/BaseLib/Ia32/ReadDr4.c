begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   AsmReadDr4 function    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_comment
comment|/**   Reads the current value of Debug Register 4 (DR4).    Reads and returns the current value of DR4. This function is only available   on IA-32 and x64. This returns a 32-bit value on IA-32 and a 64-bit value on   x64.    @return The value of Debug Register 4 (DR4).  **/
end_comment

begin_function
name|UINTN
name|EFIAPI
name|AsmReadDr4
parameter_list|(
name|VOID
parameter_list|)
block|{
asm|__asm {
asm|_emit  0x0f
asm|_emit  0x21
asm|_emit  0xe0
asm|}
block|}
end_function

end_unit

