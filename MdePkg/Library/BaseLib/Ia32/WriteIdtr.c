begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   AsmWriteIdtr function    Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|"BaseLibInternals.h"
end_include

begin_comment
comment|/**   Writes the current Interrupt Descriptor Table Register(GDTR) descriptor.    Writes the current IDTR descriptor and returns it in Idtr. This function is   only available on IA-32 and x64.    @param  Idtr  The pointer to a IDTR descriptor.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|InternalX86WriteIdtr
parameter_list|(
name|IN
name|CONST
name|IA32_DESCRIPTOR
modifier|*
name|Idtr
parameter_list|)
block|{
name|_asm
block|{
name|mov
name|eax
decl_stmt|,
name|Idtr
name|pushfd
name|cli
name|lidt
name|fword
name|ptr
index|[
name|eax
index|]
name|popfd
block|}
block|}
end_function

end_unit

