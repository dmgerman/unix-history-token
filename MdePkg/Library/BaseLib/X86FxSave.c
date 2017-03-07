begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   IA-32/x64 AsmFxSave()    Copyright (c) 2006 - 2012, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|"BaseLibInternals.h"
end_include

begin_comment
comment|/**   Save the current floating point/SSE/SSE2 context to a buffer.    Saves the current floating point/SSE/SSE2 state to the buffer specified by   Buffer. Buffer must be aligned on a 16-byte boundary. This function is only   available on IA-32 and x64.    If Buffer is NULL, then ASSERT().   If Buffer is not aligned on a 16-byte boundary, then ASSERT().    @param  Buffer  A pointer to a buffer to save the floating point/SSE/SSE2 context.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|AsmFxSave
parameter_list|(
name|OUT
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
name|InternalX86FxSave
argument_list|(
name|Buffer
argument_list|)
expr_stmt|;
comment|//
comment|// Mark one flag at end of Buffer, it will be check by AsmFxRestor()
comment|//
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
operator|=
literal|0xAA5555AA
expr_stmt|;
block|}
end_function

end_unit

