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
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__asan_init_v3
parameter_list|()
function_decl|;
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
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__asan_register_globals
parameter_list|(
name|__asan_global
modifier|*
name|globals
parameter_list|,
name|uptr
name|n
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__asan_unregister_globals
parameter_list|(
name|__asan_global
modifier|*
name|globals
parameter_list|,
name|uptr
name|n
parameter_list|)
function_decl|;
comment|// These two functions should be called before and after dynamic initializers
comment|// of a single module run, respectively.
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__asan_before_dynamic_init
parameter_list|(
specifier|const
name|char
modifier|*
name|module_name
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__asan_after_dynamic_init
parameter_list|()
function_decl|;
comment|// These two functions are used by instrumented code in the
comment|// use-after-scope mode. They mark memory for local variables as
comment|// unaddressable when they leave scope and addressable before the
comment|// function exits.
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__asan_poison_stack_memory
parameter_list|(
name|uptr
name|addr
parameter_list|,
name|uptr
name|size
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__asan_unpoison_stack_memory
parameter_list|(
name|uptr
name|addr
parameter_list|,
name|uptr
name|size
parameter_list|)
function_decl|;
comment|// Performs cleanup before a NoReturn function. Must be called before things
comment|// like _exit and execl to avoid false positives on stack.
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__asan_handle_no_return
parameter_list|()
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__asan_poison_memory_region
parameter_list|(
name|void
specifier|const
specifier|volatile
modifier|*
name|addr
parameter_list|,
name|uptr
name|size
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__asan_unpoison_memory_region
parameter_list|(
name|void
specifier|const
specifier|volatile
modifier|*
name|addr
parameter_list|,
name|uptr
name|size
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|bool
name|__asan_address_is_poisoned
parameter_list|(
name|void
specifier|const
specifier|volatile
modifier|*
name|addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|uptr
name|__asan_region_is_poisoned
parameter_list|(
name|uptr
name|beg
parameter_list|,
name|uptr
name|size
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__asan_describe_address
parameter_list|(
name|uptr
name|addr
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__asan_report_error
parameter_list|(
name|uptr
name|pc
parameter_list|,
name|uptr
name|bp
parameter_list|,
name|uptr
name|sp
parameter_list|,
name|uptr
name|addr
parameter_list|,
name|bool
name|is_write
parameter_list|,
name|uptr
name|access_size
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|int
name|__asan_set_error_exit_code
parameter_list|(
name|int
name|exit_code
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__asan_set_death_callback
parameter_list|(
name|void
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__asan_set_error_report_callback
parameter_list|(
name|void
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|SANITIZER_WEAK_ATTRIBUTE
comment|/* OPTIONAL */
name|void
name|__asan_on_error
parameter_list|()
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|SANITIZER_WEAK_ATTRIBUTE
comment|/* OPTIONAL */
name|bool
name|__asan_symbolize
parameter_list|(
specifier|const
name|void
modifier|*
name|pc
parameter_list|,
name|char
modifier|*
name|out_buffer
parameter_list|,
name|int
name|out_size
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|uptr
name|__asan_get_estimated_allocated_size
parameter_list|(
name|uptr
name|size
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|bool
name|__asan_get_ownership
parameter_list|(
specifier|const
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|uptr
name|__asan_get_allocated_size
parameter_list|(
specifier|const
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|uptr
name|__asan_get_current_allocated_bytes
parameter_list|()
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|uptr
name|__asan_get_heap_size
parameter_list|()
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|uptr
name|__asan_get_free_bytes
parameter_list|()
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|uptr
name|__asan_get_unmapped_bytes
parameter_list|()
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__asan_print_accumulated_stats
parameter_list|()
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|SANITIZER_WEAK_ATTRIBUTE
comment|/* OPTIONAL */
specifier|const
name|char
modifier|*
name|__asan_default_options
parameter_list|()
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|SANITIZER_WEAK_ATTRIBUTE
comment|/* OPTIONAL */
name|void
name|__asan_malloc_hook
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
comment|/* OPTIONAL */
name|void
name|__asan_free_hook
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
comment|// Global flag, copy of ASAN_OPTIONS=detect_stack_use_after_return
name|SANITIZER_INTERFACE_ATTRIBUTE
specifier|extern
name|int
name|__asan_option_detect_stack_use_after_return
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

