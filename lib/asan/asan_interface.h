begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- asan_interface.h ----------------------------------------*- C++ -*-===//
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
name|ASAN_INTERFACE_H
end_ifndef

begin_define
define|#
directive|define
name|ASAN_INTERFACE_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_interface_defs.h"
end_include

begin_comment
comment|// ----------- ATTENTION -------------
end_comment

begin_comment
comment|// This header should NOT include any other headers from ASan runtime.
end_comment

begin_comment
comment|// All functions in this header are extern "C" and start with __asan_.
end_comment

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
name|void
name|__asan_init
argument_list|()
name|SANITIZER_INTERFACE_ATTRIBUTE
expr_stmt|;
comment|// This function should be called by the instrumented code.
comment|// 'addr' is the address of a global variable called 'name' of 'size' bytes.
name|void
name|__asan_register_global
argument_list|(
name|uptr
name|addr
argument_list|,
name|uptr
name|size
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|)
name|SANITIZER_INTERFACE_ATTRIBUTE
decl_stmt|;
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
comment|// Marks memory region [addr, addr+size) as unaddressable.
comment|// This memory must be previously allocated by the user program. Accessing
comment|// addresses in this region from instrumented code is forbidden until
comment|// this region is unpoisoned. This function is not guaranteed to poison
comment|// the whole region - it may poison only subregion of [addr, addr+size) due
comment|// to ASan alignment restrictions.
comment|// Method is NOT thread-safe in the sense that no two threads can
comment|// (un)poison memory in the same memory region simultaneously.
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
comment|// Marks memory region [addr, addr+size) as addressable.
comment|// This memory must be previously allocated by the user program. Accessing
comment|// addresses in this region is allowed until this region is poisoned again.
comment|// This function may unpoison a superregion of [addr, addr+size) due to
comment|// ASan alignment restrictions.
comment|// Method is NOT thread-safe in the sense that no two threads can
comment|// (un)poison memory in the same memory region simultaneously.
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
comment|// Performs cleanup before a NoReturn function. Must be called before things
comment|// like _exit and execl to avoid false positives on stack.
name|void
name|__asan_handle_no_return
argument_list|()
name|SANITIZER_INTERFACE_ATTRIBUTE
expr_stmt|;
comment|// User code should use macro instead of functions.
if|#
directive|if
name|__has_feature
argument_list|(
name|address_sanitizer
argument_list|)
define|#
directive|define
name|ASAN_POISON_MEMORY_REGION
parameter_list|(
name|addr
parameter_list|,
name|size
parameter_list|)
define|\
value|__asan_poison_memory_region((addr), (size))
define|#
directive|define
name|ASAN_UNPOISON_MEMORY_REGION
parameter_list|(
name|addr
parameter_list|,
name|size
parameter_list|)
define|\
value|__asan_unpoison_memory_region((addr), (size))
else|#
directive|else
define|#
directive|define
name|ASAN_POISON_MEMORY_REGION
parameter_list|(
name|addr
parameter_list|,
name|size
parameter_list|)
define|\
value|((void)(addr), (void)(size))
define|#
directive|define
name|ASAN_UNPOISON_MEMORY_REGION
parameter_list|(
name|addr
parameter_list|,
name|size
parameter_list|)
define|\
value|((void)(addr), (void)(size))
endif|#
directive|endif
comment|// Returns true iff addr is poisoned (i.e. 1-byte read/write access to this
comment|// address will result in error report from AddressSanitizer).
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
comment|// This is an internal function that is called to report an error.
comment|// However it is still a part of the interface because users may want to
comment|// set a breakpoint on this function in a debugger.
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
comment|// Sets the exit code to use when reporting an error.
comment|// Returns the old value.
name|int
name|__asan_set_error_exit_code
argument_list|(
name|int
name|exit_code
argument_list|)
name|SANITIZER_INTERFACE_ATTRIBUTE
decl_stmt|;
comment|// Sets the callback to be called right before death on error.
comment|// Passing 0 will unset the callback.
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
comment|// Returns the estimated number of bytes that will be reserved by allocator
comment|// for request of "size" bytes. If ASan allocator can't allocate that much
comment|// memory, returns the maximal possible allocation size, otherwise returns
comment|// "size".
name|uptr
name|__asan_get_estimated_allocated_size
argument_list|(
name|uptr
name|size
argument_list|)
name|SANITIZER_INTERFACE_ATTRIBUTE
decl_stmt|;
comment|// Returns true if p was returned by the ASan allocator and
comment|// is not yet freed.
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
comment|// Returns the number of bytes reserved for the pointer p.
comment|// Requires (get_ownership(p) == true) or (p == 0).
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
comment|// Number of bytes, allocated and not yet freed by the application.
name|uptr
name|__asan_get_current_allocated_bytes
argument_list|()
name|SANITIZER_INTERFACE_ATTRIBUTE
expr_stmt|;
comment|// Number of bytes, mmaped by asan allocator to fulfill allocation requests.
comment|// Generally, for request of X bytes, allocator can reserve and add to free
comment|// lists a large number of chunks of size X to use them for future requests.
comment|// All these chunks count toward the heap size. Currently, allocator never
comment|// releases memory to OS (instead, it just puts freed chunks to free lists).
name|uptr
name|__asan_get_heap_size
argument_list|()
name|SANITIZER_INTERFACE_ATTRIBUTE
expr_stmt|;
comment|// Number of bytes, mmaped by asan allocator, which can be used to fulfill
comment|// allocation requests. When a user program frees memory chunk, it can first
comment|// fall into quarantine and will count toward __asan_get_free_bytes() later.
name|uptr
name|__asan_get_free_bytes
argument_list|()
name|SANITIZER_INTERFACE_ATTRIBUTE
expr_stmt|;
comment|// Number of bytes in unmapped pages, that are released to OS. Currently,
comment|// always returns 0.
name|uptr
name|__asan_get_unmapped_bytes
argument_list|()
name|SANITIZER_INTERFACE_ATTRIBUTE
expr_stmt|;
comment|// Prints accumulated stats to stderr. Used for debugging.
name|void
name|__asan_print_accumulated_stats
argument_list|()
name|SANITIZER_INTERFACE_ATTRIBUTE
expr_stmt|;
block|}
end_extern

begin_comment
comment|// namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ASAN_INTERFACE_H
end_comment

end_unit

