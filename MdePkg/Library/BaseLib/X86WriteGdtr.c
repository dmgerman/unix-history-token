begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   IA-32/x64 AsmWriteGdtr()    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|"BaseLibInternals.h"
end_include

begin_comment
comment|/**   Writes the current Global Descriptor Table Register (GDTR) descriptor.    Writes and the current GDTR descriptor specified by Gdtr. This function is   only available on IA-32 and x64.    If Gdtr is NULL, then ASSERT().    @param  Gdtr  The pointer to a GDTR descriptor.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|AsmWriteGdtr
parameter_list|(
name|IN
name|CONST
name|IA32_DESCRIPTOR
modifier|*
name|Gdtr
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|Gdtr
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|InternalX86WriteGdtr
argument_list|(
name|Gdtr
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

