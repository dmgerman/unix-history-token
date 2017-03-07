begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provides a service to publish discovered system resources.  Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__RESOURCE_PUBLICATION_LIB__
end_ifndef

begin_define
define|#
directive|define
name|__RESOURCE_PUBLICATION_LIB__
end_define

begin_comment
comment|/**   Declares the presence of permanent system memory in the platform.    Declares that the system memory buffer specified by MemoryBegin and MemoryLength   as permanent memory that may be used for general purpose use by software.   The amount of memory available to software may be less than MemoryLength   if published memory has alignment restrictions.    If MemoryLength is 0, then ASSERT().   If MemoryLength is greater than (MAX_ADDRESS - MemoryBegin + 1), then ASSERT().     @param  MemoryBegin               The start address of the memory being declared.   @param  MemoryLength              The number of bytes of memory being declared.    @retval  RETURN_SUCCESS           The memory buffer was published.   @retval  RETURN_OUT_OF_RESOURCES  There are not enough resources to publish the memory buffer  **/
end_comment

begin_function_decl
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
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

