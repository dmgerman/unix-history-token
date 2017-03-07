begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Internal ASSERT () functions for SetJump.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|"BaseLibInternals.h"
end_include

begin_comment
comment|/**   Worker function that checks ASSERT condition for JumpBuffer    Checks ASSERT condition for JumpBuffer.    If JumpBuffer is NULL, then ASSERT().   For IPF CPUs, if JumpBuffer is not aligned on a 16-byte boundary, then ASSERT().    @param  JumpBuffer    A pointer to CPU context buffer.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|InternalAssertJumpBuffer
parameter_list|(
name|IN
name|BASE_LIBRARY_JUMP_BUFFER
modifier|*
name|JumpBuffer
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|JumpBuffer
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
operator|(
operator|(
name|UINTN
operator|)
name|JumpBuffer
operator|&
operator|(
name|BASE_LIBRARY_JUMP_BUFFER_ALIGNMENT
operator|-
literal|1
operator|)
operator|)
operator|==
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

