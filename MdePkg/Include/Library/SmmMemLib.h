begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provides services for SMM Memory Operation.    The SMM Mem Library provides function for checking if buffer is outside SMRAM and valid.   It also provides functions for copy data from SMRAM to non-SMRAM, from non-SMRAM to SMRAM,   from non-SMRAM to non-SMRAM, or set data in non-SMRAM.      Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SMM_MEM_LIB_H_
end_ifndef

begin_define
define|#
directive|define
name|_SMM_MEM_LIB_H_
end_define

begin_comment
comment|/**   This function check if the buffer is valid per processor architecture and not overlap with SMRAM.    @param Buffer  The buffer start address to be checked.   @param Length  The buffer length to be checked.    @retval TRUE  This buffer is valid per processor architecture and not overlap with SMRAM.   @retval FALSE This buffer is not valid per processor architecture or overlap with SMRAM. **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|SmmIsBufferOutsideSmmValid
parameter_list|(
name|IN
name|EFI_PHYSICAL_ADDRESS
name|Buffer
parameter_list|,
name|IN
name|UINT64
name|Length
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Copies a source buffer (non-SMRAM) to a destination buffer (SMRAM).    This function copies a source buffer (non-SMRAM) to a destination buffer (SMRAM).   It checks if source buffer is valid per processor architecture and not overlap with SMRAM.   If the check passes, it copies memory and returns EFI_SUCCESS.   If the check fails, it return EFI_SECURITY_VIOLATION.   The implementation must be reentrant.    @param  DestinationBuffer   The pointer to the destination buffer of the memory copy.   @param  SourceBuffer        The pointer to the source buffer of the memory copy.   @param  Length              The number of bytes to copy from SourceBuffer to DestinationBuffer.    @retval EFI_SECURITY_VIOLATION The SourceBuffer is invalid per processor architecture or overlap with SMRAM.   @retval EFI_SUCCESS            Memory is copied.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|SmmCopyMemToSmram
parameter_list|(
name|OUT
name|VOID
modifier|*
name|DestinationBuffer
parameter_list|,
name|IN
name|CONST
name|VOID
modifier|*
name|SourceBuffer
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Copies a source buffer (SMRAM) to a destination buffer (NON-SMRAM).    This function copies a source buffer (non-SMRAM) to a destination buffer (SMRAM).   It checks if destination buffer is valid per processor architecture and not overlap with SMRAM.   If the check passes, it copies memory and returns EFI_SUCCESS.   If the check fails, it returns EFI_SECURITY_VIOLATION.   The implementation must be reentrant.      @param  DestinationBuffer   The pointer to the destination buffer of the memory copy.   @param  SourceBuffer        The pointer to the source buffer of the memory copy.   @param  Length              The number of bytes to copy from SourceBuffer to DestinationBuffer.    @retval EFI_SECURITY_VIOLATION The DesinationBuffer is invalid per processor architecture or overlap with SMRAM.   @retval EFI_SUCCESS            Memory is copied.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|SmmCopyMemFromSmram
parameter_list|(
name|OUT
name|VOID
modifier|*
name|DestinationBuffer
parameter_list|,
name|IN
name|CONST
name|VOID
modifier|*
name|SourceBuffer
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Copies a source buffer (NON-SMRAM) to a destination buffer (NON-SMRAM).    This function copies a source buffer (non-SMRAM) to a destination buffer (SMRAM).   It checks if source buffer and destination buffer are valid per processor architecture and not overlap with SMRAM.   If the check passes, it copies memory and returns EFI_SUCCESS.   If the check fails, it returns EFI_SECURITY_VIOLATION.   The implementation must be reentrant, and it must handle the case where source buffer overlaps destination buffer.      @param  DestinationBuffer   The pointer to the destination buffer of the memory copy.   @param  SourceBuffer        The pointer to the source buffer of the memory copy.   @param  Length              The number of bytes to copy from SourceBuffer to DestinationBuffer.    @retval EFI_SECURITY_VIOLATION The DesinationBuffer is invalid per processor architecture or overlap with SMRAM.   @retval EFI_SECURITY_VIOLATION The SourceBuffer is invalid per processor architecture or overlap with SMRAM.   @retval EFI_SUCCESS            Memory is copied.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|SmmCopyMem
parameter_list|(
name|OUT
name|VOID
modifier|*
name|DestinationBuffer
parameter_list|,
name|IN
name|CONST
name|VOID
modifier|*
name|SourceBuffer
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Fills a target buffer (NON-SMRAM) with a byte value.    This function fills a target buffer (non-SMRAM) with a byte value.   It checks if target buffer is valid per processor architecture and not overlap with SMRAM.   If the check passes, it fills memory and returns EFI_SUCCESS.   If the check fails, it returns EFI_SECURITY_VIOLATION.      @param  Buffer    The memory to set.   @param  Length    The number of bytes to set.   @param  Value     The value with which to fill Length bytes of Buffer.      @retval EFI_SECURITY_VIOLATION The Buffer is invalid per processor architecture or overlap with SMRAM.   @retval EFI_SUCCESS            Memory is set.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|SmmSetMem
parameter_list|(
name|OUT
name|VOID
modifier|*
name|Buffer
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|,
name|IN
name|UINT8
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

