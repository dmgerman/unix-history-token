begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Resource Publication Library that uses PEI Core Services to publish system memory.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_include
include|#
directive|include
file|<PiPei.h>
end_include

begin_include
include|#
directive|include
file|<Library/ResourcePublicationLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/PeiServicesLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/DebugLib.h>
end_include

begin_comment
comment|/**   Declares the presence of permanent system memory in the platform.    Declares that the system memory buffer specified by MemoryBegin and MemoryLength   as permanent memory that may be used for general purpose use by software.   The amount of memory available to software may be less than MemoryLength   if published memory has alignment restrictions.    If MemoryLength is 0, then ASSERT().   If MemoryLength is greater than (MAX_ADDRESS - MemoryBegin + 1), then ASSERT().     @param  MemoryBegin               The start address of the memory being declared.   @param  MemoryLength              The number of bytes of memory being declared.    @retval  RETURN_SUCCESS           The memory buffer was published.   @retval  RETURN_OUT_OF_RESOURCES  There are not enough resources to publish the memory buffer  **/
end_comment

begin_function
name|RETURN_STATUS
name|EFIAPI
name|PublishSystemMemory
parameter_list|(
name|IN
name|PHYSICAL_ADDRESS
name|MemoryBegin
parameter_list|,
name|IN
name|UINT64
name|MemoryLength
parameter_list|)
block|{
name|EFI_STATUS
name|Status
decl_stmt|;
name|ASSERT
argument_list|(
name|MemoryLength
operator|>
literal|0
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|MemoryLength
operator|<=
operator|(
name|MAX_ADDRESS
operator|-
name|MemoryBegin
operator|+
literal|1
operator|)
argument_list|)
expr_stmt|;
name|Status
operator|=
name|PeiServicesInstallPeiMemory
argument_list|(
name|MemoryBegin
argument_list|,
name|MemoryLength
argument_list|)
expr_stmt|;
return|return
operator|(
name|RETURN_STATUS
operator|)
name|Status
return|;
block|}
end_function

end_unit

