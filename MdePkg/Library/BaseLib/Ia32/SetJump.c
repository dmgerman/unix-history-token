begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Implementation of SetJump() on IA-32.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|"BaseLibInternals.h"
end_include

begin_comment
comment|/**   Worker function that checks ASSERT condition for JumpBuffer    Checks ASSERT condition for JumpBuffer.    If JumpBuffer is NULL, then ASSERT().   For IPF CPUs, if JumpBuffer is not aligned on a 16-byte boundary, then ASSERT().    @param  JumpBuffer    A pointer to CPU context buffer.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|InternalAssertJumpBuffer
parameter_list|(
name|IN
name|BASE_LIBRARY_JUMP_BUFFER
modifier|*
name|JumpBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Saves the current CPU context that can be restored with a call to LongJump()   and returns 0.    Saves the current CPU context in the buffer specified by JumpBuffer and   returns 0. The initial call to SetJump() must always return 0. Subsequent   calls to LongJump() cause a non-zero value to be returned by SetJump().    If JumpBuffer is NULL, then ASSERT().   For IPF CPUs, if JumpBuffer is not aligned on a 16-byte boundary, then ASSERT().    @param  JumpBuffer  A pointer to CPU context buffer.    @retval 0 Indicates a return from SetJump().  **/
end_comment

begin_macro
name|_declspec
argument_list|(
argument|naked
argument_list|)
end_macro

begin_function
name|UINTN
name|EFIAPI
name|SetJump
parameter_list|(
name|OUT
name|BASE_LIBRARY_JUMP_BUFFER
modifier|*
name|JumpBuffer
parameter_list|)
block|{
name|_asm
block|{
name|push
index|[
name|esp
operator|+
literal|4
index|]
name|call
name|InternalAssertJumpBuffer
name|pop
name|ecx
name|pop
name|ecx
name|mov
name|edx
decl_stmt|, [
name|esp
decl|]
name|mov
index|[
name|edx
index|]
decl_stmt|,
name|ebx
name|mov
index|[
name|edx
operator|+
literal|4
index|]
decl_stmt|,
name|esi
name|mov
index|[
name|edx
operator|+
literal|8
index|]
decl_stmt|,
name|edi
name|mov
index|[
name|edx
operator|+
literal|12
index|]
decl_stmt|,
name|ebp
name|mov
index|[
name|edx
operator|+
literal|16
index|]
decl_stmt|,
name|esp
name|mov
index|[
name|edx
operator|+
literal|20
index|]
decl_stmt|,
name|ecx
name|xor
name|eax
decl_stmt|,
name|eax
name|jmp
name|ecx
block|}
block|}
end_function

end_unit

