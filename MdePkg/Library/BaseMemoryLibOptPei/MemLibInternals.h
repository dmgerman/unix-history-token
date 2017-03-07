begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Declaration of internal functions for Base Memory Library.    The following BaseMemoryLib instances contain the same copy of this file:     BaseMemoryLib     BaseMemoryLibMmx     BaseMemoryLibSse2     BaseMemoryLibRepStr     BaseMemoryLibOptDxe     BaseMemoryLibOptPei    Copyright (c) 2006 - 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MEM_LIB_INTERNALS__
end_ifndef

begin_define
define|#
directive|define
name|__MEM_LIB_INTERNALS__
end_define

begin_include
include|#
directive|include
file|<Base.h>
end_include

begin_include
include|#
directive|include
file|<Library/BaseMemoryLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/BaseLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/DebugLib.h>
end_include

begin_comment
comment|/**   Copy Length bytes from Source to Destination.    @param  DestinationBuffer The target of the copy request.   @param  SourceBuffer      The place to copy from.   @param  Length            The number of bytes to copy.    @return Destination  **/
end_comment

begin_function_decl
name|VOID
modifier|*
name|EFIAPI
name|InternalMemCopyMem
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
comment|/**   Set Buffer to Value for Size bytes.    @param  Buffer   The memory to set.   @param  Length   The number of bytes to set.   @param  Value    The value of the set operation.    @return Buffer  **/
end_comment

begin_function_decl
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
name|Length
parameter_list|,
name|IN
name|UINT8
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Fills a target buffer with a 16-bit value, and returns the target buffer.    @param  Buffer  The pointer to the target buffer to fill.   @param  Length  The count of 16-bit value to fill.   @param  Value   The value with which to fill Length bytes of Buffer.    @return Buffer  **/
end_comment

begin_function_decl
name|VOID
modifier|*
name|EFIAPI
name|InternalMemSetMem16
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
name|UINT16
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Fills a target buffer with a 32-bit value, and returns the target buffer.    @param  Buffer  The pointer to the target buffer to fill.   @param  Length  The count of 32-bit value to fill.   @param  Value   The value with which to fill Length bytes of Buffer.    @return Buffer  **/
end_comment

begin_function_decl
name|VOID
modifier|*
name|EFIAPI
name|InternalMemSetMem32
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
name|UINT32
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Fills a target buffer with a 64-bit value, and returns the target buffer.    @param  Buffer  The pointer to the target buffer to fill.   @param  Length  The count of 64-bit value to fill.   @param  Value   The value with which to fill Length bytes of Buffer.    @return Buffer  **/
end_comment

begin_function_decl
name|VOID
modifier|*
name|EFIAPI
name|InternalMemSetMem64
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
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Set Buffer to 0 for Size bytes.    @param  Buffer The memory to set.   @param  Length The number of bytes to set    @return Buffer  **/
end_comment

begin_function_decl
name|VOID
modifier|*
name|EFIAPI
name|InternalMemZeroMem
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
function_decl|;
end_function_decl

begin_comment
comment|/**   Compares two memory buffers of a given length.    @param  DestinationBuffer The first memory buffer.   @param  SourceBuffer      The second memory buffer.   @param  Length            The length of DestinationBuffer and SourceBuffer memory                             regions to compare. Must be non-zero.    @return 0                 All Length bytes of the two buffers are identical.   @retval Non-zero          The first mismatched byte in SourceBuffer subtracted from the first                             mismatched byte in DestinationBuffer.  **/
end_comment

begin_function_decl
name|INTN
name|EFIAPI
name|InternalMemCompareMem
parameter_list|(
name|IN
name|CONST
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
comment|/**   Scans a target buffer for an 8-bit value, and returns a pointer to the   matching 8-bit value in the target buffer.    @param  Buffer  The pointer to the target buffer to scan.   @param  Length  The count of 8-bit value to scan. Must be non-zero.   @param  Value   The value to search for in the target buffer.    @return The pointer to the first occurrence or NULL if not found.  **/
end_comment

begin_function_decl
name|CONST
name|VOID
modifier|*
name|EFIAPI
name|InternalMemScanMem8
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
parameter_list|,
name|IN
name|UINT8
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Scans a target buffer for a 16-bit value, and returns a pointer to the   matching 16-bit value in the target buffer.    @param  Buffer  The pointer to the target buffer to scan.   @param  Length  The count of 16-bit value to scan. Must be non-zero.   @param  Value   The value to search for in the target buffer.    @return The pointer to the first occurrence or NULL if not found.  **/
end_comment

begin_function_decl
name|CONST
name|VOID
modifier|*
name|EFIAPI
name|InternalMemScanMem16
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
parameter_list|,
name|IN
name|UINT16
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Scans a target buffer for a 32-bit value, and returns a pointer to the   matching 32-bit value in the target buffer.    @param  Buffer  The pointer to the target buffer to scan.   @param  Length  The count of 32-bit value to scan. Must be non-zero.   @param  Value   The value to search for in the target buffer.    @return The pointer to the first occurrence or NULL if not found.  **/
end_comment

begin_function_decl
name|CONST
name|VOID
modifier|*
name|EFIAPI
name|InternalMemScanMem32
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
parameter_list|,
name|IN
name|UINT32
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Scans a target buffer for a 64-bit value, and returns a pointer to the   matching 64-bit value in the target buffer.    @param  Buffer  The pointer to the target buffer to scan.   @param  Length  The count of 64-bit value to scan. Must be non-zero.   @param  Value   The value to search for in the target buffer.    @return The pointer to the first occurrence or NULL if not found.  **/
end_comment

begin_function_decl
name|CONST
name|VOID
modifier|*
name|EFIAPI
name|InternalMemScanMem64
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
parameter_list|,
name|IN
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Checks whether the contents of a buffer are all zeros.    @param  Buffer  The pointer to the buffer to be checked.   @param  Length  The size of the buffer (in bytes) to be checked.    @retval TRUE    Contents of the buffer are all zeros.   @retval FALSE   Contents of the buffer are not all zeros.  **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|InternalMemIsZeroBuffer
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
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

