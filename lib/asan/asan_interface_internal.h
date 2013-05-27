begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- asan_interface_internal.h -------------------------------*- C++ -*-===//
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
comment|// This file is a part of AddressSanitizer, an address sanity checker.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This header can be included by the instrumented program to fetch
end_comment

begin_comment
comment|// data (mostly allocator statistics) from ASan runtime library.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASAN_INTERFACE_INTERNAL_H
end_ifndef

begin_define
define|#
directive|define
name|ASAN_INTERFACE_INTERNAL_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_internal_defs.h"
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
comment|// This function should be called at the very beginning of the process,
comment|// before any instrumented code is executed and before any call to malloc.
comment|// Everytime the asan ABI changes we also change the version number in this
comment|// name. Objects build with incompatible asan ABI version
comment|// will not link with run-time.
comment|// Changes between ABI versions:
comment|// v1=>v2: added 'module_name' to __asan_global
comment|// v2=>v3: stack frame description (created by the compiler)
comment|//         contains the function PC as the 3-rd field (see
comment|//         DescribeAddressIfStack).
name|void
name|__asan_init_v3
argument_list|()
name|SANITIZER_INTERFACE_ATTRIBUTE
expr_stmt|;
define|#
directive|define
name|__asan_init
value|__asan_init_v3
comment|// This structure describes an instrumented global variable.
struct|struct
name|__asan_global
block|{
name|uptr
name|beg
decl_stmt|;
comment|// The address of the global.
name|uptr
name|size
decl_stmt|;
comment|// The original size of the global.
name|uptr
name|size_with_redzone
decl_stmt|;
comment|// The size with the redzone.
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|// Name as a C string.
specifier|const
name|char
modifier|*
name|module_name
decl_stmt|;
comment|// Module name as a C string. This pointer is a
comment|// unique identifier of a module.
name|uptr
name|has_dynamic_init
decl_stmt|;
comment|// Non-zero if the global has dynamic initializer.
block|}
struct|;
comment|// These two functions should be called by the instrumented code.
comment|// 'globals' is an array of structures describing 'n' globals.
name|void
name|__asan_register_globals
argument_list|(
name|__asan_global
operator|*
name|globals
argument_list|,
name|uptr
name|n
argument_list|)
name|SANITIZER_INTERFACE_ATTRIBUTE
decl_stmt|;
name|void
name|__asan_unregister_globals
argument_list|(
name|__asan_global
operator|*
name|globals
argument_list|,
name|uptr
name|n
argument_list|)
name|SANITIZER_INTERFACE_ATTRIBUTE
decl_stmt|;
comment|// These two functions should be called before and after dynamic initializers
comment|// of a single module run, respectively.
name|void
name|__asan_before_dynamic_init
argument_list|(
specifier|const
name|char
operator|*
name|module_name
argument_list|)
name|SANITIZER_INTERFACE_ATTRIBUTE
decl_stmt|;
name|void
name|__asan_after_dynamic_init
argument_list|()
name|SANITIZER_INTERFACE_ATTRIBUTE
expr_stmt|;
comment|// These two functions are used by the instrumented code in the
comment|// use-after-return mode. __asan_stack_malloc allocates size bytes of
comment|// fake stack and __asan_stack_free poisons it. real_stack is a pointer to
comment|// the real stack region.
name|uptr
name|__asan_stack_malloc
argument_list|(
name|uptr
name|size
argument_list|,
name|uptr
name|real_stack
argument_list|)
name|SANITIZER_INTERFACE_ATTRIBUTE
decl_stmt|;
name|void
name|__asan_stack_free
argument_list|(
name|uptr
name|ptr
argument_list|,
name|uptr
name|size
argument_list|,
name|uptr
name|real_stack
argument_list|)
name|SANITIZER_INTERFACE_ATTRIBUTE
decl_stmt|;
comment|// These two functions are used by instrumented code in the
comment|// use-after-scope mode. They mark memory for local variables as
comment|// unaddressable when they leave scope and addressable before the
comment|// function exits.
name|void
name|__asan_poison_stack_memory
argument_list|(
name|uptr
name|addr
argument_list|,
name|uptr
name|size
argument_list|)
name|SANITIZER_INTERFACE_ATTRIBUTE
decl_stmt|;
name|void
name|__asan_unpoison_stack_memory
argument_list|(
name|uptr
name|addr
argument_list|,
name|uptr
name|size
argument_list|)
name|SANITIZER_INTERFACE_ATTRIBUTE
decl_stmt|;
comment|// Performs cleanup before a NoReturn function. Must be called before things
comment|// like _exit and execl to avoid false positives on stack.
name|void
name|__asan_handle_no_return
argument_list|()
name|SANITIZER_INTERFACE_ATTRIBUTE
expr_stmt|;
name|void
name|__asan_poison_memory_region
argument_list|(
name|void
specifier|const
specifier|volatile
operator|*
name|addr
argument_list|,
name|uptr
name|size
argument_list|)
name|SANITIZER_INTERFACE_ATTRIBUTE
decl_stmt|;
name|void
name|__asan_unpoison_memory_region
argument_list|(
name|void
specifier|const
specifier|volatile
operator|*
name|addr
argument_list|,
name|uptr
name|size
argument_list|)
name|SANITIZER_INTERFACE_ATTRIBUTE
decl_stmt|;
name|bool
name|__asan_address_is_poisoned
argument_list|(
name|void
specifier|const
specifier|volatile
operator|*
name|addr
argument_list|)
name|SANITIZER_INTERFACE_ATTRIBUTE
decl_stmt|;
name|uptr
name|__asan_region_is_poisoned
argument_list|(
name|uptr
name|beg
argument_list|,
name|uptr
name|size
argument_list|)
name|SANITIZER_INTERFACE_ATTRIBUTE
decl_stmt|;
name|void
name|__asan_describe_address
argument_list|(
name|uptr
name|addr
argument_list|)
name|SANITIZER_INTERFACE_ATTRIBUTE
decl_stmt|;
name|void
name|__asan_report_error
argument_list|(
name|uptr
name|pc
argument_list|,
name|uptr
name|bp
argument_list|,
name|uptr
name|sp
argument_list|,
name|uptr
name|addr
argument_list|,
name|bool
name|is_write
argument_list|,
name|uptr
name|access_size
argument_list|)
name|SANITIZER_INTERFACE_ATTRIBUTE
decl_stmt|;
name|int
name|__asan_set_error_exit_code
argument_list|(
name|int
name|exit_code
argument_list|)
name|SANITIZER_INTERFACE_ATTRIBUTE
decl_stmt|;
name|void
name|__asan_set_death_callback
argument_list|(
name|void
argument_list|(
operator|*
name|callback
argument_list|)
argument_list|(
name|void
argument_list|)
argument_list|)
name|SANITIZER_INTERFACE_ATTRIBUTE
decl_stmt|;
name|void
name|__asan_set_error_report_callback
argument_list|(
name|void
argument_list|(
operator|*
name|callback
argument_list|)
argument_list|(
specifier|const
name|char
operator|*
argument_list|)
argument_list|)
name|SANITIZER_INTERFACE_ATTRIBUTE
decl_stmt|;
comment|/* OPTIONAL */
name|void
name|__asan_on_error
argument_list|()
name|SANITIZER_WEAK_ATTRIBUTE
name|SANITIZER_INTERFACE_ATTRIBUTE
expr_stmt|;
comment|/* OPTIONAL */
name|bool
name|__asan_symbolize
argument_list|(
specifier|const
name|void
operator|*
name|pc
argument_list|,
name|char
operator|*
name|out_buffer
argument_list|,
name|int
name|out_size
argument_list|)
name|SANITIZER_WEAK_ATTRIBUTE
name|SANITIZER_INTERFACE_ATTRIBUTE
decl_stmt|;
name|uptr
name|__asan_get_estimated_allocated_size
argument_list|(
name|uptr
name|size
argument_list|)
name|SANITIZER_INTERFACE_ATTRIBUTE
decl_stmt|;
name|bool
name|__asan_get_ownership
argument_list|(
specifier|const
name|void
operator|*
name|p
argument_list|)
name|SANITIZER_INTERFACE_ATTRIBUTE
decl_stmt|;
name|uptr
name|__asan_get_allocated_size
argument_list|(
specifier|const
name|void
operator|*
name|p
argument_list|)
name|SANITIZER_INTERFACE_ATTRIBUTE
decl_stmt|;
name|uptr
name|__asan_get_current_allocated_bytes
argument_list|()
name|SANITIZER_INTERFACE_ATTRIBUTE
expr_stmt|;
name|uptr
name|__asan_get_heap_size
argument_list|()
name|SANITIZER_INTERFACE_ATTRIBUTE
expr_stmt|;
name|uptr
name|__asan_get_free_bytes
argument_list|()
name|SANITIZER_INTERFACE_ATTRIBUTE
expr_stmt|;
name|uptr
name|__asan_get_unmapped_bytes
argument_list|()
name|SANITIZER_INTERFACE_ATTRIBUTE
expr_stmt|;
name|void
name|__asan_print_accumulated_stats
argument_list|()
name|SANITIZER_INTERFACE_ATTRIBUTE
expr_stmt|;
comment|/* OPTIONAL */
specifier|const
name|char
operator|*
name|__asan_default_options
argument_list|()
name|SANITIZER_WEAK_ATTRIBUTE
name|SANITIZER_INTERFACE_ATTRIBUTE
expr_stmt|;
comment|/* OPTIONAL */
name|void
name|__asan_malloc_hook
argument_list|(
name|void
operator|*
name|ptr
argument_list|,
name|uptr
name|size
argument_list|)
name|SANITIZER_WEAK_ATTRIBUTE
name|SANITIZER_INTERFACE_ATTRIBUTE
decl_stmt|;
comment|/* OPTIONAL */
name|void
name|__asan_free_hook
argument_list|(
name|void
operator|*
name|ptr
argument_list|)
name|SANITIZER_WEAK_ATTRIBUTE
name|SANITIZER_INTERFACE_ATTRIBUTE
decl_stmt|;
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
comment|// ASAN_INTERFACE_INTERNAL_H
end_comment

end_unit

