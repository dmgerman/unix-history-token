begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_allocator_interface.h ------------------------- C++ -----===//
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
comment|// Re-declaration of functions from public sanitizer allocator interface.
end_comment

begin_comment
comment|//
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
file|"sanitizer_internal_defs.h"
end_include

begin_expr_stmt
name|using
name|__sanitizer
operator|::
name|uptr
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern
literal|"C"
block|{
name|SANITIZER_INTERFACE_ATTRIBUTE
name|uptr
name|__sanitizer_get_estimated_allocated_size
parameter_list|(
name|uptr
name|size
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|int
name|__sanitizer_get_ownership
parameter_list|(
specifier|const
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|uptr
name|__sanitizer_get_allocated_size
parameter_list|(
specifier|const
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|uptr
name|__sanitizer_get_current_allocated_bytes
parameter_list|()
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|uptr
name|__sanitizer_get_heap_size
parameter_list|()
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|uptr
name|__sanitizer_get_free_bytes
parameter_list|()
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|uptr
name|__sanitizer_get_unmapped_bytes
parameter_list|()
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|int
name|__sanitizer_install_malloc_and_free_hooks
parameter_list|(
name|void
function_decl|(
modifier|*
name|malloc_hook
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|uptr
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
name|free_hook
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|SANITIZER_WEAK_ATTRIBUTE
name|void
name|__sanitizer_malloc_hook
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|uptr
name|size
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|SANITIZER_WEAK_ATTRIBUTE
name|void
name|__sanitizer_free_hook
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|SANITIZER_WEAK_ATTRIBUTE
name|void
name|__sanitizer_print_memory_profile
parameter_list|(
name|uptr
name|top_percent
parameter_list|,
name|uptr
name|max_number_of_contexts
parameter_list|)
function_decl|;
block|}
end_extern

begin_comment
comment|// extern "C"
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_ALLOCATOR_INTERFACE_H
end_comment

end_unit

