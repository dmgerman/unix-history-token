begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer/asan_interface.h ------------------------------*- C++ -*-===//
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
comment|// This file is a part of AddressSanitizer.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Public interface header.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_ASAN_INTERFACE_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_ASAN_INTERFACE_H
end_define

begin_include
include|#
directive|include
file|<sanitizer/common_interface_defs.h>
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
comment|// Marks memory region [addr, addr+size) as addressable.
comment|// This memory must be previously allocated by the user program. Accessing
comment|// addresses in this region is allowed until this region is poisoned again.
comment|// This function may unpoison a superregion of [addr, addr+size) due to
comment|// ASan alignment restrictions.
comment|// Method is NOT thread-safe in the sense that no two threads can
comment|// (un)poison memory in the same memory region simultaneously.
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
comment|// User code should use macros instead of functions.
if|#
directive|if
name|__has_feature
argument_list|(
name|address_sanitizer
argument_list|)
operator|||
name|defined
argument_list|(
name|__SANITIZE_ADDRESS__
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
parameter_list|(
name|void
specifier|const
specifier|volatile
modifier|*
name|addr
parameter_list|)
function_decl|;
comment|// If at least on byte in [beg, beg+size) is poisoned, return the address
comment|// of the first such byte. Otherwise return 0.
name|void
modifier|*
name|__asan_region_is_poisoned
parameter_list|(
name|void
modifier|*
name|beg
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
comment|// Print the description of addr (useful when debugging in gdb).
name|void
name|__asan_describe_address
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
comment|// This is an internal function that is called to report an error.
comment|// However it is still a part of the interface because users may want to
comment|// set a breakpoint on this function in a debugger.
name|void
name|__asan_report_error
parameter_list|(
name|void
modifier|*
name|pc
parameter_list|,
name|void
modifier|*
name|bp
parameter_list|,
name|void
modifier|*
name|sp
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|,
name|bool
name|is_write
parameter_list|,
name|size_t
name|access_size
parameter_list|)
function_decl|;
comment|// Sets the exit code to use when reporting an error.
comment|// Returns the old value.
name|int
name|__asan_set_error_exit_code
parameter_list|(
name|int
name|exit_code
parameter_list|)
function_decl|;
comment|// Sets the callback to be called right before death on error.
comment|// Passing 0 will unset the callback.
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
comment|// User may provide function that would be called right when ASan detects
comment|// an error. This can be used to notice cases when ASan detects an error, but
comment|// the program crashes before ASan report is printed.
name|void
name|__asan_on_error
parameter_list|()
function_decl|;
comment|// User may provide its own implementation for symbolization function.
comment|// It should print the description of instruction at address "pc" to
comment|// "out_buffer". Description should be at most "out_size" bytes long.
comment|// User-specified function should return true if symbolization was
comment|// successful.
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
comment|// Returns the estimated number of bytes that will be reserved by allocator
comment|// for request of "size" bytes. If ASan allocator can't allocate that much
comment|// memory, returns the maximal possible allocation size, otherwise returns
comment|// "size".
name|size_t
name|__asan_get_estimated_allocated_size
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
comment|// Returns true if p was returned by the ASan allocator and
comment|// is not yet freed.
name|bool
name|__asan_get_ownership
parameter_list|(
specifier|const
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
comment|// Returns the number of bytes reserved for the pointer p.
comment|// Requires (get_ownership(p) == true) or (p == 0).
name|size_t
name|__asan_get_allocated_size
parameter_list|(
specifier|const
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
comment|// Number of bytes, allocated and not yet freed by the application.
name|size_t
name|__asan_get_current_allocated_bytes
parameter_list|()
function_decl|;
comment|// Number of bytes, mmaped by asan allocator to fulfill allocation requests.
comment|// Generally, for request of X bytes, allocator can reserve and add to free
comment|// lists a large number of chunks of size X to use them for future requests.
comment|// All these chunks count toward the heap size. Currently, allocator never
comment|// releases memory to OS (instead, it just puts freed chunks to free lists).
name|size_t
name|__asan_get_heap_size
parameter_list|()
function_decl|;
comment|// Number of bytes, mmaped by asan allocator, which can be used to fulfill
comment|// allocation requests. When a user program frees memory chunk, it can first
comment|// fall into quarantine and will count toward __asan_get_free_bytes() later.
name|size_t
name|__asan_get_free_bytes
parameter_list|()
function_decl|;
comment|// Number of bytes in unmapped pages, that are released to OS. Currently,
comment|// always returns 0.
name|size_t
name|__asan_get_unmapped_bytes
parameter_list|()
function_decl|;
comment|// Prints accumulated stats to stderr. Used for debugging.
name|void
name|__asan_print_accumulated_stats
parameter_list|()
function_decl|;
comment|// This function may be optionally provided by user and should return
comment|// a string containing ASan runtime options. See asan_flags.h for details.
specifier|const
name|char
modifier|*
name|__asan_default_options
parameter_list|()
function_decl|;
comment|// Malloc hooks that may be optionally provided by user.
comment|// __asan_malloc_hook(ptr, size) is called immediately after
comment|//   allocation of "size" bytes, which returned "ptr".
comment|// __asan_free_hook(ptr) is called immediately before
comment|//   deallocation of "ptr".
name|void
name|__asan_malloc_hook
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
name|void
name|__asan_free_hook
parameter_list|(
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

begin_comment
comment|// SANITIZER_ASAN_INTERFACE_H
end_comment

end_unit

