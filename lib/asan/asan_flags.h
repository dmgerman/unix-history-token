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
file|"sanitizer_common/sanitizer_interface_defs.h"
end_include

begin_comment
comment|// ASan flag values can be defined in three ways:
end_comment

begin_comment
comment|// 1) initialized with default values at startup.
end_comment

begin_comment
comment|// 2) overriden from string returned by user-specified function
end_comment

begin_comment
comment|//    __asan_default_options().
end_comment

begin_comment
comment|// 3) overriden from env variable ASAN_OPTIONS.
end_comment

begin_extern
extern|extern
literal|"C"
block|{
comment|// Can be overriden by user.
specifier|const
name|char
operator|*
name|__asan_default_options
argument_list|()
name|SANITIZER_WEAK_ATTRIBUTE
expr_stmt|;
block|}
end_extern

begin_comment
comment|// extern "C"
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
comment|// If set, uses in-process symbolizer from common sanitizer runtime.
name|bool
name|symbolize
decl_stmt|;
comment|// Verbosity level (0 - silent, 1 - a bit of output, 2+ - more output).
name|int
name|verbosity
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
comment|// Max number of stack frames kept for each allocation.
name|int
name|malloc_context_size
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
comment|// Used on Mac only. See comments in asan_mac.cc and asan_malloc_mac.cc.
name|bool
name|replace_cfallocator
decl_stmt|;
comment|// Used on Mac only.
name|bool
name|mac_ignore_invalid_free
decl_stmt|;
comment|// ASan allocator flag. See asan_allocator.cc.
name|bool
name|use_fake_stack
decl_stmt|;
comment|// ASan allocator flag. Sets the maximal size of allocation request
comment|// that would return memory filled with zero bytes.
name|int
name|max_malloc_fill_size
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
comment|// If set, prints ASan exit stats even after program terminates successfully.
name|bool
name|atexit
decl_stmt|;
comment|// By default, disable core dumper on 64-bit - it makes little sense
comment|// to dump 16T+ core.
name|bool
name|disable_core
decl_stmt|;
block|}
struct|;
name|Flags
modifier|*
name|flags
parameter_list|()
function_decl|;
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

