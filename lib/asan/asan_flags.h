begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- asan_flags.h -------------------------------------------*- C++ -*-===//
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
comment|// ASan runtime flags.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASAN_FLAGS_H
end_ifndef

begin_define
define|#
directive|define
name|ASAN_FLAGS_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_internal_defs.h"
end_include

begin_comment
comment|// ASan flag values can be defined in four ways:
end_comment

begin_comment
comment|// 1) initialized with default values at startup.
end_comment

begin_comment
comment|// 2) overriden during compilation of ASan runtime by providing
end_comment

begin_comment
comment|//    compile definition ASAN_DEFAULT_OPTIONS.
end_comment

begin_comment
comment|// 3) overriden from string returned by user-specified function
end_comment

begin_comment
comment|//    __asan_default_options().
end_comment

begin_comment
comment|// 4) overriden from env variable ASAN_OPTIONS.
end_comment

begin_decl_stmt
name|namespace
name|__asan
block|{
struct|struct
name|Flags
block|{
comment|// Size (in bytes) of quarantine used to detect use-after-free errors.
comment|// Lower value may reduce memory usage but increase the chance of
comment|// false negatives.
name|int
name|quarantine_size
decl_stmt|;
comment|// Size (in bytes) of redzones around heap objects.
comment|// Requirement: redzone>= 32, is a power of two.
name|int
name|redzone
decl_stmt|;
comment|// If set, prints some debugging information and does additional checks.
name|bool
name|debug
decl_stmt|;
comment|// Controls the way to handle globals (0 - don't detect buffer overflow
comment|// on globals, 1 - detect buffer overflow, 2 - print data about registered
comment|// globals).
name|int
name|report_globals
decl_stmt|;
comment|// If set, attempts to catch initialization order issues.
name|bool
name|check_initialization_order
decl_stmt|;
comment|// If set, uses custom wrappers and replacements for libc string functions
comment|// to find more errors.
name|bool
name|replace_str
decl_stmt|;
comment|// If set, uses custom wrappers for memset/memcpy/memmove intinsics.
name|bool
name|replace_intrin
decl_stmt|;
comment|// Used on Mac only.
name|bool
name|mac_ignore_invalid_free
decl_stmt|;
comment|// Enables stack-use-after-return checking at run-time.
name|bool
name|detect_stack_use_after_return
decl_stmt|;
comment|// The minimal fake stack size log.
name|int
name|uar_stack_size_log
decl_stmt|;
comment|// ASan allocator flag. max_malloc_fill_size is the maximal amount of bytes
comment|// that will be filled with malloc_fill_byte on malloc.
name|int
name|max_malloc_fill_size
decl_stmt|,
name|malloc_fill_byte
decl_stmt|;
comment|// Override exit status if something was reported.
name|int
name|exitcode
decl_stmt|;
comment|// If set, user may manually mark memory regions as poisoned or unpoisoned.
name|bool
name|allow_user_poisoning
decl_stmt|;
comment|// Number of seconds to sleep between printing an error report and
comment|// terminating application. Useful for debug purposes (when one needs
comment|// to attach gdb, for example).
name|int
name|sleep_before_dying
decl_stmt|;
comment|// If set, registers ASan custom segv handler.
name|bool
name|handle_segv
decl_stmt|;
comment|// If set, allows user register segv handler even if ASan registers one.
name|bool
name|allow_user_segv_handler
decl_stmt|;
comment|// If set, uses alternate stack for signal handling.
name|bool
name|use_sigaltstack
decl_stmt|;
comment|// Allow the users to work around the bug in Nvidia drivers prior to 295.*.
name|bool
name|check_malloc_usable_size
decl_stmt|;
comment|// If set, explicitly unmaps (huge) shadow at exit.
name|bool
name|unmap_shadow_on_exit
decl_stmt|;
comment|// If set, calls abort() instead of _exit() after printing an error report.
name|bool
name|abort_on_error
decl_stmt|;
comment|// Print various statistics after printing an error message or if atexit=1.
name|bool
name|print_stats
decl_stmt|;
comment|// Print the legend for the shadow bytes.
name|bool
name|print_legend
decl_stmt|;
comment|// If set, prints ASan exit stats even after program terminates successfully.
name|bool
name|atexit
decl_stmt|;
comment|// If set, coverage information will be dumped at shutdown time if the
comment|// appropriate instrumentation was enabled.
name|bool
name|coverage
decl_stmt|;
comment|// By default, disable core dumper on 64-bit - it makes little sense
comment|// to dump 16T+ core.
name|bool
name|disable_core
decl_stmt|;
comment|// Allow the tool to re-exec the program. This may interfere badly with the
comment|// debugger.
name|bool
name|allow_reexec
decl_stmt|;
comment|// If set, prints not only thread creation stacks for threads in error report,
comment|// but also thread creation stacks for threads that created those threads,
comment|// etc. up to main thread.
name|bool
name|print_full_thread_history
decl_stmt|;
comment|// Poison (or not) the heap memory on [de]allocation. Zero value is useful
comment|// for benchmarking the allocator or instrumentator.
name|bool
name|poison_heap
decl_stmt|;
comment|// If true, poison partially addressable 8-byte aligned words (default=true).
comment|// This flag affects heap and global buffers, but not stack buffers.
name|bool
name|poison_partial
decl_stmt|;
comment|// Report errors on malloc/delete, new/free, new/delete[], etc.
name|bool
name|alloc_dealloc_mismatch
decl_stmt|;
comment|// If true, assume that memcmp(p1, p2, n) always reads n bytes before
comment|// comparing p1 and p2.
name|bool
name|strict_memcmp
decl_stmt|;
comment|// If true, assume that dynamic initializers can never access globals from
comment|// other modules, even if the latter are already initialized.
name|bool
name|strict_init_order
decl_stmt|;
block|}
struct|;
specifier|extern
name|Flags
name|asan_flags_dont_use_directly
decl_stmt|;
specifier|inline
name|Flags
modifier|*
name|flags
parameter_list|()
block|{
return|return
operator|&
name|asan_flags_dont_use_directly
return|;
block|}
name|void
name|InitializeFlags
parameter_list|(
name|Flags
modifier|*
name|f
parameter_list|,
specifier|const
name|char
modifier|*
name|env
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __asan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ASAN_FLAGS_H
end_comment

end_unit

