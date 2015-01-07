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
comment|// Returns 1 if addr is poisoned (i.e. 1-byte read/write access to this
comment|// address will result in error report from AddressSanitizer).
comment|// Otherwise returns 0.
name|int
name|__asan_address_is_poisoned
parameter_list|(
name|void
specifier|const
specifier|volatile
modifier|*
name|addr
parameter_list|)
function_decl|;
comment|// If at least one byte in [beg, beg+size) is poisoned, return the address
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
comment|// Useful for calling from a debugger to get information about an ASan error.
comment|// Returns 1 if an error has been (or is being) reported, otherwise returns 0.
name|int
name|__asan_report_present
parameter_list|()
function_decl|;
comment|// Useful for calling from a debugger to get information about an ASan error.
comment|// If an error has been (or is being) reported, the following functions return
comment|// the pc, bp, sp, address, access type (0 = read, 1 = write), access size and
comment|// bug description (e.g. "heap-use-after-free"). Otherwise they return 0.
name|void
modifier|*
name|__asan_get_report_pc
parameter_list|()
function_decl|;
name|void
modifier|*
name|__asan_get_report_bp
parameter_list|()
function_decl|;
name|void
modifier|*
name|__asan_get_report_sp
parameter_list|()
function_decl|;
name|void
modifier|*
name|__asan_get_report_address
parameter_list|()
function_decl|;
name|int
name|__asan_get_report_access_type
parameter_list|()
function_decl|;
name|size_t
name|__asan_get_report_access_size
parameter_list|()
function_decl|;
specifier|const
name|char
modifier|*
name|__asan_get_report_description
parameter_list|()
function_decl|;
comment|// Useful for calling from the debugger to get information about a pointer.
comment|// Returns the category of the given pointer as a constant string.
comment|// Possible return values are "global", "stack", "stack-fake", "heap",
comment|// "heap-invalid", "shadow-low", "shadow-gap", "shadow-high", "unknown".
comment|// If global or stack, tries to also return the variable name, address and
comment|// size. If heap, tries to return the chunk address and size. 'name' should
comment|// point to an allocated buffer of size 'name_size'.
specifier|const
name|char
modifier|*
name|__asan_locate_address
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|size_t
name|name_size
parameter_list|,
name|void
modifier|*
modifier|*
name|region_address
parameter_list|,
name|size_t
modifier|*
name|region_size
parameter_list|)
function_decl|;
comment|// Useful for calling from the debugger to get the allocation stack trace
comment|// and thread ID for a heap address. Stores up to 'size' frames into 'trace',
comment|// returns the number of stored frames or 0 on error.
name|size_t
name|__asan_get_alloc_stack
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|void
modifier|*
modifier|*
name|trace
parameter_list|,
name|size_t
name|size
parameter_list|,
name|int
modifier|*
name|thread_id
parameter_list|)
function_decl|;
comment|// Useful for calling from the debugger to get the free stack trace
comment|// and thread ID for a heap address. Stores up to 'size' frames into 'trace',
comment|// returns the number of stored frames or 0 on error.
name|size_t
name|__asan_get_free_stack
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|void
modifier|*
modifier|*
name|trace
parameter_list|,
name|size_t
name|size
parameter_list|,
name|int
modifier|*
name|thread_id
parameter_list|)
function_decl|;
comment|// Useful for calling from the debugger to get the current shadow memory
comment|// mapping.
name|void
name|__asan_get_shadow_mapping
parameter_list|(
name|size_t
modifier|*
name|shadow_scale
parameter_list|,
name|size_t
modifier|*
name|shadow_offset
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
name|int
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
comment|// The following 2 functions facilitate garbage collection in presence of
comment|// asan's fake stack.
comment|// Returns an opaque handler to be used later in __asan_addr_is_in_fake_stack.
comment|// Returns NULL if the current thread does not have a fake stack.
name|void
modifier|*
name|__asan_get_current_fake_stack
parameter_list|()
function_decl|;
comment|// If fake_stack is non-NULL and addr belongs to a fake frame in
comment|// fake_stack, returns the address on real stack that corresponds to
comment|// the fake frame and sets beg/end to the boundaries of this fake frame.
comment|// Otherwise returns NULL and does not touch beg/end.
comment|// If beg/end are NULL, they are not touched.
comment|// This function may be called from a thread other than the owner of
comment|// fake_stack, but the owner thread need to be alive.
name|void
modifier|*
name|__asan_addr_is_in_fake_stack
parameter_list|(
name|void
modifier|*
name|fake_stack
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|,
name|void
modifier|*
modifier|*
name|beg
parameter_list|,
name|void
modifier|*
modifier|*
name|end
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

