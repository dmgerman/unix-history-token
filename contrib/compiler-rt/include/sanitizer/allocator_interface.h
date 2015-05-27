begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- allocator_interface.h ---------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Public interface header for allocator used in sanitizers (ASan/TSan/MSan).
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_ALLOCATOR_INTERFACE_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_ALLOCATOR_INTERFACE_H
end_define

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* Returns the estimated number of bytes that will be reserved by allocator      for request of "size" bytes. If allocator can't allocate that much      memory, returns the maximal possible allocation size, otherwise returns      "size". */
name|size_t
name|__sanitizer_get_estimated_allocated_size
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
comment|/* Returns true if p was returned by the allocator and      is not yet freed. */
name|int
name|__sanitizer_get_ownership
parameter_list|(
specifier|const
specifier|volatile
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
comment|/* Returns the number of bytes reserved for the pointer p.      Requires (get_ownership(p) == true) or (p == 0). */
name|size_t
name|__sanitizer_get_allocated_size
parameter_list|(
specifier|const
specifier|volatile
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
comment|/* Number of bytes, allocated and not yet freed by the application. */
name|size_t
name|__sanitizer_get_current_allocated_bytes
parameter_list|()
function_decl|;
comment|/* Number of bytes, mmaped by the allocator to fulfill allocation requests.      Generally, for request of X bytes, allocator can reserve and add to free      lists a large number of chunks of size X to use them for future requests.      All these chunks count toward the heap size. Currently, allocator never      releases memory to OS (instead, it just puts freed chunks to free      lists). */
name|size_t
name|__sanitizer_get_heap_size
parameter_list|()
function_decl|;
comment|/* Number of bytes, mmaped by the allocator, which can be used to fulfill      allocation requests. When a user program frees memory chunk, it can first      fall into quarantine and will count toward __sanitizer_get_free_bytes()      later. */
name|size_t
name|__sanitizer_get_free_bytes
parameter_list|()
function_decl|;
comment|/* Number of bytes in unmapped pages, that are released to OS. Currently,      always returns 0. */
name|size_t
name|__sanitizer_get_unmapped_bytes
parameter_list|()
function_decl|;
comment|/* Malloc hooks that may be optionally provided by user.      __sanitizer_malloc_hook(ptr, size) is called immediately after        allocation of "size" bytes, which returned "ptr".      __sanitizer_free_hook(ptr) is called immediately before        deallocation of "ptr". */
name|void
name|__sanitizer_malloc_hook
parameter_list|(
specifier|const
specifier|volatile
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
name|void
name|__sanitizer_free_hook
parameter_list|(
specifier|const
specifier|volatile
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_comment
comment|// extern "C"
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

