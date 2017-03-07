begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Implementation of IsZeroBuffer function.    The following BaseMemoryLib instances contain the same copy of this file:      BaseMemoryLib     BaseMemoryLibMmx     BaseMemoryLibSse2     BaseMemoryLibRepStr     BaseMemoryLibOptDxe     BaseMemoryLibOptPei     PeiMemoryLib     UefiMemoryLib    Copyright (c) 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|"MemLibInternals.h"
end_include

begin_comment
comment|/**   Checks if the contents of a buffer are all zeros.    This function checks whether the contents of a buffer are all zeros. If the   contents are all zeros, return TRUE. Otherwise, return FALSE.    If Length> 0 and Buffer is NULL, then ASSERT().   If Length is greater than (MAX_ADDRESS - Buffer + 1), then ASSERT().    @param  Buffer      The pointer to the buffer to be checked.   @param  Length      The size of the buffer (in bytes) to be checked.    @retval TRUE        Contents of the buffer are all zeros.   @retval FALSE       Contents of the buffer are not all zeros.  **/
end_comment

begin_function
name|BOOLEAN
name|EFIAPI
name|IsZeroBuffer
parameter_list|(
name|IN
name|CONST
name|VOID
modifier|*
name|Buffer
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|)
block|{
name|ASSERT
argument_list|(
operator|!
operator|(
name|Buffer
operator|==
name|NULL
operator|&&
name|Length
operator|>
literal|0
operator|)
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
operator|(
name|Length
operator|-
literal|1
operator|)
operator|<=
operator|(
name|MAX_ADDRESS
operator|-
operator|(
name|UINTN
operator|)
name|Buffer
operator|)
argument_list|)
expr_stmt|;
return|return
name|InternalMemIsZeroBuffer
argument_list|(
name|Buffer
argument_list|,
name|Length
argument_list|)
return|;
block|}
end_function

end_unit

