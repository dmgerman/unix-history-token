begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Long Jump functions.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|"BaseLibInternals.h"
end_include

begin_comment
comment|/**   Restores the CPU context that was saved with SetJump().    Restores the CPU context from the buffer specified by JumpBuffer. This   function never returns to the caller. Instead is resumes execution based on   the state of JumpBuffer.    If JumpBuffer is NULL, then ASSERT().   For IPF CPUs, if JumpBuffer is not aligned on a 16-byte boundary, then ASSERT().   If Value is 0, then ASSERT().    @param  JumpBuffer  A pointer to CPU context buffer.   @param  Value       The value to return when the SetJump() context is                       restored and must be non-zero.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|LongJump
parameter_list|(
name|IN
name|BASE_LIBRARY_JUMP_BUFFER
modifier|*
name|JumpBuffer
parameter_list|,
name|IN
name|UINTN
name|Value
parameter_list|)
block|{
name|InternalAssertJumpBuffer
argument_list|(
name|JumpBuffer
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|Value
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|InternalLongJump
argument_list|(
name|JumpBuffer
argument_list|,
name|Value
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

