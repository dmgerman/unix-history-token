begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provides services to allocate and free memory buffers of various memory types and alignments.      The Memory Allocation Library abstracts various common memory allocation operations. This library    allows code to be written in a phase-independent manner because the allocation of memory in PEI, DXE,    and SMM (for example) is done via a different mechanism. Using a common library interface makes it    much easier to port algorithms from phase to phase.     Copyright (c) 2006 - 2013, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MEMORY_ALLOCATION_LIB_H__
end_ifndef

begin_define
define|#
directive|define
name|__MEMORY_ALLOCATION_LIB_H__
end_define

begin_comment
comment|/**   Allocates one or more 4KB pages of type EfiBootServicesData.    Allocates the number of 4KB pages of type EfiBootServicesData and returns a pointer to the   allocated buffer.  The buffer returned is aligned on a 4KB boundary.  If Pages is 0, then NULL   is returned.  If there is not enough memory remaining to satisfy the request, then NULL is   returned.    @param  Pages                 The number of 4 KB pages to allocate.    @return A pointer to the allocated buffer or NULL if allocation fails.  **/
end_comment

begin_function_decl
name|VOID
modifier|*
name|EFIAPI
name|AllocatePages
parameter_list|(
name|IN
name|UINTN
name|Pages
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Allocates one or more 4KB pages of type EfiRuntimeServicesData.    Allocates the number of 4KB pages of type EfiRuntimeServicesData and returns a pointer to the   allocated buffer.  The buffer returned is aligned on a 4KB boundary.  If Pages is 0, then NULL   is returned.  If there is not enough memory remaining to satisfy the request, then NULL is   returned.    @param  Pages                 The number of 4 KB pages to allocate.    @return A pointer to the allocated buffer or NULL if allocation fails.  **/
end_comment

begin_function_decl
name|VOID
modifier|*
name|EFIAPI
name|AllocateRuntimePages
parameter_list|(
name|IN
name|UINTN
name|Pages
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Allocates one or more 4KB pages of type EfiReservedMemoryType.    Allocates the number of 4KB pages of type EfiReservedMemoryType and returns a pointer to the   allocated buffer.  The buffer returned is aligned on a 4KB boundary.  If Pages is 0, then NULL   is returned.  If there is not enough memory remaining to satisfy the request, then NULL is   returned.    @param  Pages                 The number of 4 KB pages to allocate.    @return A pointer to the allocated buffer or NULL if allocation fails.  **/
end_comment

begin_function_decl
name|VOID
modifier|*
name|EFIAPI
name|AllocateReservedPages
parameter_list|(
name|IN
name|UINTN
name|Pages
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Frees one or more 4KB pages that were previously allocated with one of the page allocation   functions in the Memory Allocation Library.    Frees the number of 4KB pages specified by Pages from the buffer specified by Buffer.  Buffer   must have been allocated on a previous call to the page allocation services of the Memory   Allocation Library.  If it is not possible to free allocated pages, then this function will   perform no actions.      If Buffer was not allocated with a page allocation function in the Memory Allocation Library,   then ASSERT().   If Pages is zero, then ASSERT().     @param  Buffer                Pointer to the buffer of pages to free.   @param  Pages                 The number of 4 KB pages to free.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|FreePages
parameter_list|(
name|IN
name|VOID
modifier|*
name|Buffer
parameter_list|,
name|IN
name|UINTN
name|Pages
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Allocates one or more 4KB pages of type EfiBootServicesData at a specified alignment.    Allocates the number of 4KB pages specified by Pages of type EfiBootServicesData with an   alignment specified by Alignment.  The allocated buffer is returned.  If Pages is 0, then NULL is   returned.  If there is not enough memory at the specified alignment remaining to satisfy the   request, then NULL is returned.      If Alignment is not a power of two and Alignment is not zero, then ASSERT().   If Pages plus EFI_SIZE_TO_PAGES (Alignment) overflows, then ASSERT().    @param  Pages                 The number of 4 KB pages to allocate.   @param  Alignment             The requested alignment of the allocation.  Must be a power of two.                                 If Alignment is zero, then byte alignment is used.    @return A pointer to the allocated buffer or NULL if allocation fails.  **/
end_comment

begin_function_decl
name|VOID
modifier|*
name|EFIAPI
name|AllocateAlignedPages
parameter_list|(
name|IN
name|UINTN
name|Pages
parameter_list|,
name|IN
name|UINTN
name|Alignment
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Allocates one or more 4KB pages of type EfiRuntimeServicesData at a specified alignment.    Allocates the number of 4KB pages specified by Pages of type EfiRuntimeServicesData with an   alignment specified by Alignment.  The allocated buffer is returned.  If Pages is 0, then NULL is   returned.  If there is not enough memory at the specified alignment remaining to satisfy the   request, then NULL is returned.      If Alignment is not a power of two and Alignment is not zero, then ASSERT().   If Pages plus EFI_SIZE_TO_PAGES (Alignment) overflows, then ASSERT().    @param  Pages                 The number of 4 KB pages to allocate.   @param  Alignment             The requested alignment of the allocation.  Must be a power of two.                                 If Alignment is zero, then byte alignment is used.    @return A pointer to the allocated buffer or NULL if allocation fails.  **/
end_comment

begin_function_decl
name|VOID
modifier|*
name|EFIAPI
name|AllocateAlignedRuntimePages
parameter_list|(
name|IN
name|UINTN
name|Pages
parameter_list|,
name|IN
name|UINTN
name|Alignment
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Allocates one or more 4KB pages of type EfiReservedMemoryType at a specified alignment.    Allocates the number of 4KB pages specified by Pages of type EfiReservedMemoryType with an   alignment specified by Alignment.  The allocated buffer is returned.  If Pages is 0, then NULL is   returned.  If there is not enough memory at the specified alignment remaining to satisfy the   request, then NULL is returned.      If Alignment is not a power of two and Alignment is not zero, then ASSERT().   If Pages plus EFI_SIZE_TO_PAGES (Alignment) overflows, then ASSERT().    @param  Pages                 The number of 4 KB pages to allocate.   @param  Alignment             The requested alignment of the allocation.  Must be a power of two.                                 If Alignment is zero, then byte alignment is used.    @return A pointer to the allocated buffer or NULL if allocation fails.  **/
end_comment

begin_function_decl
name|VOID
modifier|*
name|EFIAPI
name|AllocateAlignedReservedPages
parameter_list|(
name|IN
name|UINTN
name|Pages
parameter_list|,
name|IN
name|UINTN
name|Alignment
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Frees one or more 4KB pages that were previously allocated with one of the aligned page   allocation functions in the Memory Allocation Library.    Frees the number of 4KB pages specified by Pages from the buffer specified by Buffer.  Buffer   must have been allocated on a previous call to the aligned page allocation services of the Memory   Allocation Library.  If it is not possible to free allocated pages, then this function will    perform no actions.      If Buffer was not allocated with an aligned page allocation function in the Memory Allocation   Library, then ASSERT().   If Pages is zero, then ASSERT().      @param  Buffer                Pointer to the buffer of pages to free.   @param  Pages                 The number of 4 KB pages to free.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|FreeAlignedPages
parameter_list|(
name|IN
name|VOID
modifier|*
name|Buffer
parameter_list|,
name|IN
name|UINTN
name|Pages
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Allocates a buffer of type EfiBootServicesData.    Allocates the number bytes specified by AllocationSize of type EfiBootServicesData and returns a   pointer to the allocated buffer.  If AllocationSize is 0, then a valid buffer of 0 size is   returned.  If there is not enough memory remaining to satisfy the request, then NULL is returned.    @param  AllocationSize        The number of bytes to allocate.    @return A pointer to the allocated buffer or NULL if allocation fails.  **/
end_comment

begin_function_decl
name|VOID
modifier|*
name|EFIAPI
name|AllocatePool
parameter_list|(
name|IN
name|UINTN
name|AllocationSize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Allocates a buffer of type EfiRuntimeServicesData.    Allocates the number bytes specified by AllocationSize of type EfiRuntimeServicesData and returns   a pointer to the allocated buffer.  If AllocationSize is 0, then a valid buffer of 0 size is   returned.  If there is not enough memory remaining to satisfy the request, then NULL is returned.    @param  AllocationSize        The number of bytes to allocate.    @return A pointer to the allocated buffer or NULL if allocation fails.  **/
end_comment

begin_function_decl
name|VOID
modifier|*
name|EFIAPI
name|AllocateRuntimePool
parameter_list|(
name|IN
name|UINTN
name|AllocationSize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Allocates a buffer of type EfiReservedMemoryType.    Allocates the number bytes specified by AllocationSize of type EfiReservedMemoryType and returns   a pointer to the allocated buffer.  If AllocationSize is 0, then a valid buffer of 0 size is   returned.  If there is not enough memory remaining to satisfy the request, then NULL is returned.    @param  AllocationSize        The number of bytes to allocate.    @return A pointer to the allocated buffer or NULL if allocation fails.  **/
end_comment

begin_function_decl
name|VOID
modifier|*
name|EFIAPI
name|AllocateReservedPool
parameter_list|(
name|IN
name|UINTN
name|AllocationSize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Allocates and zeros a buffer of type EfiBootServicesData.    Allocates the number bytes specified by AllocationSize of type EfiBootServicesData, clears the   buffer with zeros, and returns a pointer to the allocated buffer.  If AllocationSize is 0, then a   valid buffer of 0 size is returned.  If there is not enough memory remaining to satisfy the   request, then NULL is returned.    @param  AllocationSize        The number of bytes to allocate and zero.    @return A pointer to the allocated buffer or NULL if allocation fails.  **/
end_comment

begin_function_decl
name|VOID
modifier|*
name|EFIAPI
name|AllocateZeroPool
parameter_list|(
name|IN
name|UINTN
name|AllocationSize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Allocates and zeros a buffer of type EfiRuntimeServicesData.    Allocates the number bytes specified by AllocationSize of type EfiRuntimeServicesData, clears the   buffer with zeros, and returns a pointer to the allocated buffer.  If AllocationSize is 0, then a   valid buffer of 0 size is returned.  If there is not enough memory remaining to satisfy the   request, then NULL is returned.    @param  AllocationSize        The number of bytes to allocate and zero.    @return A pointer to the allocated buffer or NULL if allocation fails.  **/
end_comment

begin_function_decl
name|VOID
modifier|*
name|EFIAPI
name|AllocateRuntimeZeroPool
parameter_list|(
name|IN
name|UINTN
name|AllocationSize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Allocates and zeros a buffer of type EfiReservedMemoryType.    Allocates the number bytes specified by AllocationSize of type EfiReservedMemoryType, clears the   buffer with zeros, and returns a pointer to the allocated buffer.  If AllocationSize is 0, then a   valid buffer of 0 size is returned.  If there is not enough memory remaining to satisfy the   request, then NULL is returned.    @param  AllocationSize        The number of bytes to allocate and zero.    @return A pointer to the allocated buffer or NULL if allocation fails.  **/
end_comment

begin_function_decl
name|VOID
modifier|*
name|EFIAPI
name|AllocateReservedZeroPool
parameter_list|(
name|IN
name|UINTN
name|AllocationSize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Copies a buffer to an allocated buffer of type EfiBootServicesData.    Allocates the number bytes specified by AllocationSize of type EfiBootServicesData, copies   AllocationSize bytes from Buffer to the newly allocated buffer, and returns a pointer to the   allocated buffer.  If AllocationSize is 0, then a valid buffer of 0 size is returned.  If there   is not enough memory remaining to satisfy the request, then NULL is returned.      If Buffer is NULL, then ASSERT().   If AllocationSize is greater than (MAX_ADDRESS - Buffer + 1), then ASSERT().     @param  AllocationSize        The number of bytes to allocate and zero.   @param  Buffer                The buffer to copy to the allocated buffer.    @return A pointer to the allocated buffer or NULL if allocation fails.  **/
end_comment

begin_function_decl
name|VOID
modifier|*
name|EFIAPI
name|AllocateCopyPool
parameter_list|(
name|IN
name|UINTN
name|AllocationSize
parameter_list|,
name|IN
name|CONST
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Copies a buffer to an allocated buffer of type EfiRuntimeServicesData.    Allocates the number bytes specified by AllocationSize of type EfiRuntimeServicesData, copies   AllocationSize bytes from Buffer to the newly allocated buffer, and returns a pointer to the   allocated buffer.  If AllocationSize is 0, then a valid buffer of 0 size is returned.  If there   is not enough memory remaining to satisfy the request, then NULL is returned.      If Buffer is NULL, then ASSERT().   If AllocationSize is greater than (MAX_ADDRESS - Buffer + 1), then ASSERT().     @param  AllocationSize        The number of bytes to allocate and zero.   @param  Buffer                The buffer to copy to the allocated buffer.    @return A pointer to the allocated buffer or NULL if allocation fails.  **/
end_comment

begin_function_decl
name|VOID
modifier|*
name|EFIAPI
name|AllocateRuntimeCopyPool
parameter_list|(
name|IN
name|UINTN
name|AllocationSize
parameter_list|,
name|IN
name|CONST
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Copies a buffer to an allocated buffer of type EfiReservedMemoryType.    Allocates the number bytes specified by AllocationSize of type EfiReservedMemoryType, copies   AllocationSize bytes from Buffer to the newly allocated buffer, and returns a pointer to the   allocated buffer.  If AllocationSize is 0, then a valid buffer of 0 size is returned.  If there   is not enough memory remaining to satisfy the request, then NULL is returned.      If Buffer is NULL, then ASSERT().   If AllocationSize is greater than (MAX_ADDRESS - Buffer + 1), then ASSERT().     @param  AllocationSize        The number of bytes to allocate and zero.   @param  Buffer                The buffer to copy to the allocated buffer.    @return A pointer to the allocated buffer or NULL if allocation fails.  **/
end_comment

begin_function_decl
name|VOID
modifier|*
name|EFIAPI
name|AllocateReservedCopyPool
parameter_list|(
name|IN
name|UINTN
name|AllocationSize
parameter_list|,
name|IN
name|CONST
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reallocates a buffer of type EfiBootServicesData.    Allocates and zeros the number bytes specified by NewSize from memory of type   EfiBootServicesData.  If OldBuffer is not NULL, then the smaller of OldSize and    NewSize bytes are copied from OldBuffer to the newly allocated buffer, and    OldBuffer is freed.  A pointer to the newly allocated buffer is returned.     If NewSize is 0, then a valid buffer of 0 size is  returned.  If there is not    enough memory remaining to satisfy the request, then NULL is returned.      If the allocation of the new buffer is successful and the smaller of NewSize and OldSize   is greater than (MAX_ADDRESS - OldBuffer + 1), then ASSERT().    @param  OldSize        The size, in bytes, of OldBuffer.   @param  NewSize        The size, in bytes, of the buffer to reallocate.   @param  OldBuffer      The buffer to copy to the allocated buffer.  This is an optional                           parameter that may be NULL.    @return A pointer to the allocated buffer or NULL if allocation fails.  **/
end_comment

begin_function_decl
name|VOID
modifier|*
name|EFIAPI
name|ReallocatePool
parameter_list|(
name|IN
name|UINTN
name|OldSize
parameter_list|,
name|IN
name|UINTN
name|NewSize
parameter_list|,
name|IN
name|VOID
modifier|*
name|OldBuffer
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reallocates a buffer of type EfiRuntimeServicesData.    Allocates and zeros the number bytes specified by NewSize from memory of type   EfiRuntimeServicesData.  If OldBuffer is not NULL, then the smaller of OldSize and    NewSize bytes are copied from OldBuffer to the newly allocated buffer, and    OldBuffer is freed.  A pointer to the newly allocated buffer is returned.     If NewSize is 0, then a valid buffer of 0 size is  returned.  If there is not    enough memory remaining to satisfy the request, then NULL is returned.    If the allocation of the new buffer is successful and the smaller of NewSize and OldSize   is greater than (MAX_ADDRESS - OldBuffer + 1), then ASSERT().    @param  OldSize        The size, in bytes, of OldBuffer.   @param  NewSize        The size, in bytes, of the buffer to reallocate.   @param  OldBuffer      The buffer to copy to the allocated buffer.  This is an optional                           parameter that may be NULL.    @return A pointer to the allocated buffer or NULL if allocation fails.  **/
end_comment

begin_function_decl
name|VOID
modifier|*
name|EFIAPI
name|ReallocateRuntimePool
parameter_list|(
name|IN
name|UINTN
name|OldSize
parameter_list|,
name|IN
name|UINTN
name|NewSize
parameter_list|,
name|IN
name|VOID
modifier|*
name|OldBuffer
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reallocates a buffer of type EfiReservedMemoryType.    Allocates and zeros the number bytes specified by NewSize from memory of type   EfiReservedMemoryType.  If OldBuffer is not NULL, then the smaller of OldSize and    NewSize bytes are copied from OldBuffer to the newly allocated buffer, and    OldBuffer is freed.  A pointer to the newly allocated buffer is returned.     If NewSize is 0, then a valid buffer of 0 size is  returned.  If there is not    enough memory remaining to satisfy the request, then NULL is returned.    If the allocation of the new buffer is successful and the smaller of NewSize and OldSize   is greater than (MAX_ADDRESS - OldBuffer + 1), then ASSERT().    @param  OldSize        The size, in bytes, of OldBuffer.   @param  NewSize        The size, in bytes, of the buffer to reallocate.   @param  OldBuffer      The buffer to copy to the allocated buffer.  This is an optional                           parameter that may be NULL.    @return A pointer to the allocated buffer or NULL if allocation fails.  **/
end_comment

begin_function_decl
name|VOID
modifier|*
name|EFIAPI
name|ReallocateReservedPool
parameter_list|(
name|IN
name|UINTN
name|OldSize
parameter_list|,
name|IN
name|UINTN
name|NewSize
parameter_list|,
name|IN
name|VOID
modifier|*
name|OldBuffer
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Frees a buffer that was previously allocated with one of the pool allocation functions in the   Memory Allocation Library.    Frees the buffer specified by Buffer.  Buffer must have been allocated on a previous call to the   pool allocation services of the Memory Allocation Library.  If it is not possible to free pool   resources, then this function will perform no actions.      If Buffer was not allocated with a pool allocation function in the Memory Allocation Library,   then ASSERT().    @param  Buffer                Pointer to the buffer to free.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|FreePool
parameter_list|(
name|IN
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

