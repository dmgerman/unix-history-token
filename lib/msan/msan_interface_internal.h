begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- msan_interface_internal.h -------------------------------*- C++ -*-===//
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
comment|// This file is a part of MemorySanitizer.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Private MSan interface header.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MSAN_INTERFACE_INTERNAL_H
end_ifndef

begin_define
define|#
directive|define
name|MSAN_INTERFACE_INTERNAL_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_internal_defs.h"
end_include

begin_extern
extern|extern
literal|"C"
block|{
comment|// FIXME: document all interface functions.
name|SANITIZER_INTERFACE_ATTRIBUTE
name|int
name|__msan_get_track_origins
parameter_list|()
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__msan_init
parameter_list|()
function_decl|;
comment|// Print a warning and maybe return.
comment|// This function can die based on flags()->exit_code.
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__msan_warning
parameter_list|()
function_decl|;
comment|// Print a warning and die.
comment|// Intrumentation inserts calls to this function when building in "fast" mode
comment|// (i.e. -mllvm -msan-keep-going)
name|SANITIZER_INTERFACE_ATTRIBUTE
name|__attribute__
argument_list|(
operator|(
name|noreturn
operator|)
argument_list|)
name|void
name|__msan_warning_noreturn
argument_list|()
decl_stmt|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__msan_unpoison
parameter_list|(
specifier|const
name|void
modifier|*
name|a
parameter_list|,
name|uptr
name|size
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__msan_clear_and_unpoison
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|uptr
name|size
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
modifier|*
name|__msan_memcpy
parameter_list|(
name|void
modifier|*
name|dst
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|uptr
name|size
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
modifier|*
name|__msan_memset
parameter_list|(
name|void
modifier|*
name|s
parameter_list|,
name|int
name|c
parameter_list|,
name|uptr
name|n
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
modifier|*
name|__msan_memmove
parameter_list|(
name|void
modifier|*
name|dest
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|uptr
name|n
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__msan_copy_poison
parameter_list|(
name|void
modifier|*
name|dst
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|uptr
name|size
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__msan_copy_origin
parameter_list|(
name|void
modifier|*
name|dst
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|uptr
name|size
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__msan_move_poison
parameter_list|(
name|void
modifier|*
name|dst
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|uptr
name|size
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__msan_poison
parameter_list|(
specifier|const
name|void
modifier|*
name|a
parameter_list|,
name|uptr
name|size
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__msan_poison_stack
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|uptr
name|size
parameter_list|)
function_decl|;
comment|// Copy size bytes from src to dst and unpoison the result.
comment|// Useful to implement unsafe loads.
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__msan_load_unpoisoned
parameter_list|(
name|void
modifier|*
name|src
parameter_list|,
name|uptr
name|size
parameter_list|,
name|void
modifier|*
name|dst
parameter_list|)
function_decl|;
comment|// Returns the offset of the first (at least partially) poisoned byte,
comment|// or -1 if the whole range is good.
name|SANITIZER_INTERFACE_ATTRIBUTE
name|sptr
name|__msan_test_shadow
parameter_list|(
specifier|const
name|void
modifier|*
name|x
parameter_list|,
name|uptr
name|size
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__msan_set_origin
parameter_list|(
specifier|const
name|void
modifier|*
name|a
parameter_list|,
name|uptr
name|size
parameter_list|,
name|u32
name|origin
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__msan_set_alloca_origin
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|uptr
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|descr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|u32
name|__msan_get_origin
parameter_list|(
specifier|const
name|void
modifier|*
name|a
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__msan_clear_on_return
parameter_list|()
function_decl|;
comment|// Default: -1 (don't exit on error).
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__msan_set_exit_code
parameter_list|(
name|int
name|exit_code
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|int
name|__msan_set_poison_in_malloc
parameter_list|(
name|int
name|do_poison
parameter_list|)
function_decl|;
name|SANITIZER_WEAK_ATTRIBUTE
name|SANITIZER_INTERFACE_ATTRIBUTE
comment|/* OPTIONAL */
specifier|const
name|char
modifier|*
name|__msan_default_options
parameter_list|()
function_decl|;
comment|// For testing.
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__msan_set_expect_umr
parameter_list|(
name|int
name|expect_umr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__msan_print_shadow
parameter_list|(
specifier|const
name|void
modifier|*
name|x
parameter_list|,
name|uptr
name|size
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__msan_print_param_shadow
parameter_list|()
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|int
name|__msan_has_dynamic_component
parameter_list|()
function_decl|;
comment|// Returns x such that %fs:x is the first byte of __msan_retval_tls.
name|SANITIZER_INTERFACE_ATTRIBUTE
name|int
name|__msan_get_retval_tls_offset
parameter_list|()
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|int
name|__msan_get_param_tls_offset
parameter_list|()
function_decl|;
comment|// For intercepting mmap from ld.so in msandr.
name|SANITIZER_INTERFACE_ATTRIBUTE
name|bool
name|__msan_is_in_loader
parameter_list|()
function_decl|;
comment|// For testing.
name|SANITIZER_INTERFACE_ATTRIBUTE
name|u32
name|__msan_get_umr_origin
parameter_list|()
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
specifier|const
name|char
modifier|*
name|__msan_get_origin_descr_if_stack
parameter_list|(
name|u32
name|id
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__msan_partial_poison
parameter_list|(
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|void
modifier|*
name|shadow
parameter_list|,
name|uptr
name|size
parameter_list|)
function_decl|;
comment|// Tell MSan about newly allocated memory (ex.: custom allocator).
comment|// Memory will be marked uninitialized, with origin at the call site.
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__msan_allocated_memory
parameter_list|(
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|uptr
name|size
parameter_list|)
function_decl|;
block|}
end_extern

begin_comment
comment|// extern "C"
end_comment

begin_comment
comment|// Unpoison first n function arguments.
end_comment

begin_function_decl
name|void
name|__msan_unpoison_param
parameter_list|(
name|uptr
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// MSAN_INTERFACE_INTERNAL_H
end_comment

end_unit

