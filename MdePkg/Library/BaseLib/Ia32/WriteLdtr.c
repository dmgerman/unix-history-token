begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   AsmWriteLdtr function    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_comment
comment|/**   Writes the current Local Descriptor Table Register (GDTR) selector.    Writes and the current LDTR descriptor specified by Ldtr. This function is   only available on IA-32 and x64.    @param  Ldtr  16-bit LDTR selector value.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|AsmWriteLdtr
parameter_list|(
name|IN
name|UINT16
name|Ldtr
parameter_list|)
block|{
name|_asm
block|{
name|xor
name|eax
decl_stmt|,
name|eax
name|mov
name|ax
decl_stmt|,
name|Ldtr
name|lldt
name|ax
block|}
block|}
end_function

end_unit

