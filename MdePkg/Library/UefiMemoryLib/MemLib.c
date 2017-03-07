begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Base Memory Library functions implementation bases on Uefi Boot Service.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|"MemLibInternals.h"
end_include

begin_comment
comment|/**   Copies a source buffer to a destination buffer, and returns the destination buffer.    This function wraps the gBS->CopyMem().    @param  DestinationBuffer   The pointer to the destination buffer of the memory copy.   @param  SourceBuffer        The pointer to the source buffer of the memory copy.   @param  Length              The number of bytes to copy from SourceBuffer to DestinationBuffer.    @return DestinationBuffer.  **/
end_comment

begin_function
name|VOID
modifier|*
name|EFIAPI
name|InternalMemCopyMem
parameter_list|(
name|OUT
name|VOID
modifier|*
name|Destination
parameter_list|,
name|IN
name|CONST
name|VOID
modifier|*
name|Source
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|)
block|{
name|gBS
operator|->
name|CopyMem
argument_list|(
name|Destination
argument_list|,
operator|(
name|VOID
operator|*
operator|)
name|Source
argument_list|,
name|Length
argument_list|)
expr_stmt|;
return|return
name|Destination
return|;
block|}
end_function

begin_comment
comment|/**   Fills a target buffer with a byte value, and returns the target buffer.    This function wraps the gBS->SetMem().    @param  Buffer    Memory to set.   @param  Size      The number of bytes to set.   @param  Value     Value of the set operation.    @return Buffer.  **/
end_comment

begin_function
name|VOID
modifier|*
name|EFIAPI
name|InternalMemSetMem
parameter_list|(
name|OUT
name|VOID
modifier|*
name|Buffer
parameter_list|,
name|IN
name|UINTN
name|Size
parameter_list|,
name|IN
name|UINT8
name|Value
parameter_list|)
block|{
name|gBS
operator|->
name|SetMem
argument_list|(
name|Buffer
argument_list|,
name|Size
argument_list|,
name|Value
argument_list|)
expr_stmt|;
return|return
name|Buffer
return|;
block|}
end_function

end_unit

