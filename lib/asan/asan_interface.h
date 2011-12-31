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
file|<stdint.h>
end_include

begin_comment
comment|// for __WORDSIZE
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|// for size_t
end_comment

begin_comment
comment|// This header should NOT include any other headers from ASan runtime.
end_comment

begin_comment
comment|// All functions in this header are extern "C" and start with __asan_.
end_comment

begin_extern
extern|extern
literal|"C"
block|{
comment|// This function should be called at the very beginning of the process,
comment|// before any instrumented code is executed and before any call to malloc.
name|void
name|__asan_init
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(visibility
parameter_list|(
function_decl|"default"
block|)
end_extern

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// This function should be called by the instrumented code.
end_comment

begin_comment
comment|// 'addr' is the address of a global variable called 'name' of 'size' bytes.
end_comment

begin_function_decl
name|void
name|__asan_register_global
parameter_list|(
name|uintptr_t
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(visibility
parameter_list|(
function_decl|"default"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// This structure describes an instrumented global variable.
end_comment

begin_struct
struct|struct
name|__asan_global
block|{
name|size_t
name|beg
decl_stmt|;
comment|// The address of the global.
name|size_t
name|size
decl_stmt|;
comment|// The original size of the global.
name|size_t
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
end_struct

begin_comment
comment|// These two functions should be called by the instrumented code.
end_comment

begin_comment
comment|// 'globals' is an array of structures describing 'n' globals.
end_comment

begin_function_decl
name|void
name|__asan_register_globals
parameter_list|(
name|__asan_global
modifier|*
name|globals
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(visibility
parameter_list|(
function_decl|"default"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|__asan_unregister_globals
parameter_list|(
name|__asan_global
modifier|*
name|globals
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(visibility
parameter_list|(
function_decl|"default"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// These two functions are used by the instrumented code in the
end_comment

begin_comment
comment|// use-after-return mode. __asan_stack_malloc allocates size bytes of
end_comment

begin_comment
comment|// fake stack and __asan_stack_free poisons it. real_stack is a pointer to
end_comment

begin_comment
comment|// the real stack region.
end_comment

begin_function_decl
name|size_t
name|__asan_stack_malloc
parameter_list|(
name|size_t
name|size
parameter_list|,
name|size_t
name|real_stack
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(visibility
parameter_list|(
function_decl|"default"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|__asan_stack_free
parameter_list|(
name|size_t
name|ptr
parameter_list|,
name|size_t
name|size
parameter_list|,
name|size_t
name|real_stack
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(visibility
parameter_list|(
function_decl|"default"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Marks memory region [addr, addr+size) as unaddressable.
end_comment

begin_comment
comment|// This memory must be previously allocated by the user program. Accessing
end_comment

begin_comment
comment|// addresses in this region from instrumented code is forbidden until
end_comment

begin_comment
comment|// this region is unpoisoned. This function is not guaranteed to poison
end_comment

begin_comment
comment|// the whole region - it may poison only subregion of [addr, addr+size) due
end_comment

begin_comment
comment|// to ASan alignment restrictions.
end_comment

begin_comment
comment|// Method is NOT thread-safe in the sense that no two threads can
end_comment

begin_comment
comment|// (un)poison memory in the same memory region simultaneously.
end_comment

begin_function_decl
name|void
name|__asan_poison_memory_region
parameter_list|(
name|void
specifier|const
specifier|volatile
modifier|*
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Marks memory region [addr, addr+size) as addressable.
end_comment

begin_comment
comment|// This memory must be previously allocated by the user program. Accessing
end_comment

begin_comment
comment|// addresses in this region is allowed until this region is poisoned again.
end_comment

begin_comment
comment|// This function may unpoison a superregion of [addr, addr+size) due to
end_comment

begin_comment
comment|// ASan alignment restrictions.
end_comment

begin_comment
comment|// Method is NOT thread-safe in the sense that no two threads can
end_comment

begin_comment
comment|// (un)poison memory in the same memory region simultaneously.
end_comment

begin_function_decl
name|void
name|__asan_unpoison_memory_region
parameter_list|(
name|void
specifier|const
specifier|volatile
modifier|*
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// User code should use macro instead of functions.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__has_feature
argument_list|)
operator|&&
name|__has_feature
argument_list|(
name|address_sanitizer
argument_list|)
end_if

begin_define
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
end_define

begin_define
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
end_define

begin_else
else|#
directive|else
end_else

begin_define
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
end_define

begin_define
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
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Returns true iff addr is poisoned (i.e. 1-byte read/write access to this
end_comment

begin_comment
comment|// address will result in error report from AddressSanitizer).
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|// This is an internal function that is called to report an error.
end_comment

begin_comment
comment|// However it is still a part of the interface because users may want to
end_comment

begin_comment
comment|// set a breakpoint on this function in a debugger.
end_comment

begin_function_decl
name|void
name|__asan_report_error
parameter_list|(
name|uintptr_t
name|pc
parameter_list|,
name|uintptr_t
name|bp
parameter_list|,
name|uintptr_t
name|sp
parameter_list|,
name|uintptr_t
name|addr
parameter_list|,
name|bool
name|is_write
parameter_list|,
name|size_t
name|access_size
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(visibility
parameter_list|(
function_decl|"default"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Sets the exit code to use when reporting an error.
end_comment

begin_comment
comment|// Returns the old value.
end_comment

begin_function_decl
name|int
name|__asan_set_error_exit_code
parameter_list|(
name|int
name|exit_code
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Returns the estimated number of bytes that will be reserved by allocator
end_comment

begin_comment
comment|// for request of "size" bytes. If ASan allocator can't allocate that much
end_comment

begin_comment
comment|// memory, returns the maximal possible allocation size, otherwise returns
end_comment

begin_comment
comment|// "size".
end_comment

begin_function_decl
name|size_t
name|__asan_get_estimated_allocated_size
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Returns true if p is NULL or if p was returned by the ASan allocator and
end_comment

begin_comment
comment|// is not yet freed.
end_comment

begin_function_decl
name|bool
name|__asan_get_ownership
parameter_list|(
specifier|const
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Returns the number of bytes reserved for the pointer p.
end_comment

begin_comment
comment|// Requires (get_ownership(p) == true).
end_comment

begin_function_decl
name|size_t
name|__asan_get_allocated_size
parameter_list|(
specifier|const
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Number of bytes, allocated and not yet freed by the application.
end_comment

begin_function_decl
name|size_t
name|__asan_get_current_allocated_bytes
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Number of bytes, mmaped by asan allocator to fulfill allocation requests.
end_comment

begin_comment
comment|// Generally, for request of X bytes, allocator can reserve and add to free
end_comment

begin_comment
comment|// lists a large number of chunks of size X to use them for future requests.
end_comment

begin_comment
comment|// All these chunks count toward the heap size. Currently, allocator never
end_comment

begin_comment
comment|// releases memory to OS (instead, it just puts freed chunks to free lists).
end_comment

begin_function_decl
name|size_t
name|__asan_get_heap_size
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Number of bytes, mmaped by asan allocator, which can be used to fulfill
end_comment

begin_comment
comment|// allocation requests. When a user program frees memory chunk, it can first
end_comment

begin_comment
comment|// fall into quarantine and will count toward __asan_get_free_bytes() later.
end_comment

begin_function_decl
name|size_t
name|__asan_get_free_bytes
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Number of bytes in unmapped pages, that are released to OS. Currently,
end_comment

begin_comment
comment|// always returns 0.
end_comment

begin_function_decl
name|size_t
name|__asan_get_unmapped_bytes
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Prints accumulated stats to stderr. Used for debugging.
end_comment

begin_function_decl
name|void
name|__asan_print_accumulated_stats
parameter_list|()
function_decl|;
end_function_decl

begin_comment
unit|}
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

