begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   IA-32/x64 AsmFxRestore()    Copyright (c) 2006 - 2012, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|"BaseLibInternals.h"
end_include

begin_comment
comment|/**   Restores the current floating point/SSE/SSE2 context from a buffer.    Restores the current floating point/SSE/SSE2 state from the buffer specified   by Buffer. Buffer must be aligned on a 16-byte boundary. This function is   only available on IA-32 and x64.    If Buffer is NULL, then ASSERT().   If Buffer is not aligned on a 16-byte boundary, then ASSERT().   If Buffer was not saved with AsmFxSave(), then ASSERT().    @param  Buffer  A pointer to a buffer to save the floating point/SSE/SSE2 context.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|AsmFxRestore
parameter_list|(
name|IN
name|CONST
name|IA32_FX_BUFFER
modifier|*
name|Buffer
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|Buffer
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
literal|0
operator|==
operator|(
operator|(
name|UINTN
operator|)
name|Buffer
operator|&
literal|0xf
operator|)
argument_list|)
expr_stmt|;
comment|//
comment|// Check the flag recorded by AsmFxSave()
comment|//
name|ASSERT
argument_list|(
literal|0xAA5555AA
operator|==
operator|*
operator|(
name|UINT32
operator|*
operator|)
operator|(
operator|&
name|Buffer
operator|->
name|Buffer
index|[
sizeof|sizeof
argument_list|(
name|Buffer
operator|->
name|Buffer
argument_list|)
operator|-
literal|4
index|]
operator|)
argument_list|)
expr_stmt|;
name|InternalX86FxRestore
argument_list|(
name|Buffer
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

