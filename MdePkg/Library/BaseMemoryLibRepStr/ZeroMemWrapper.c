begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   ZeroMem() implementation.    The following BaseMemoryLib instances contain the same copy of this file:      BaseMemoryLib     BaseMemoryLibMmx     BaseMemoryLibSse2     BaseMemoryLibRepStr     BaseMemoryLibOptDxe     BaseMemoryLibOptPei     PeiMemoryLib     UefiMemoryLib        Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|"MemLibInternals.h"
end_include

begin_comment
comment|/**   Fills a target buffer with zeros, and returns the target buffer.    This function fills Length bytes of Buffer with zeros, and returns Buffer.      If Length> 0 and Buffer is NULL, then ASSERT().   If Length is greater than (MAX_ADDRESS - Buffer + 1), then ASSERT().    @param  Buffer      The pointer to the target buffer to fill with zeros.   @param  Length      The number of bytes in Buffer to fill with zeros.    @return Buffer.  **/
end_comment

begin_function
name|VOID
modifier|*
name|EFIAPI
name|ZeroMem
parameter_list|(
name|OUT
name|VOID
modifier|*
name|Buffer
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|)
block|{
if|if
condition|(
name|Length
operator|==
literal|0
condition|)
block|{
return|return
name|Buffer
return|;
block|}
name|ASSERT
argument_list|(
name|Buffer
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|Length
operator|<=
operator|(
name|MAX_ADDRESS
operator|-
operator|(
name|UINTN
operator|)
name|Buffer
operator|+
literal|1
operator|)
argument_list|)
expr_stmt|;
return|return
name|InternalMemZeroMem
argument_list|(
name|Buffer
argument_list|,
name|Length
argument_list|)
return|;
block|}
end_function

end_unit

