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
comment|// Flag descriptions are in asan_rtl.cc.
name|int
name|quarantine_size
decl_stmt|;
name|int
name|redzone
decl_stmt|;
name|int
name|max_redzone
decl_stmt|;
name|bool
name|debug
decl_stmt|;
name|int
name|report_globals
decl_stmt|;
name|bool
name|check_initialization_order
decl_stmt|;
name|bool
name|replace_str
decl_stmt|;
name|bool
name|replace_intrin
decl_stmt|;
name|bool
name|mac_ignore_invalid_free
decl_stmt|;
name|bool
name|detect_stack_use_after_return
decl_stmt|;
name|int
name|min_uar_stack_size_log
decl_stmt|;
name|int
name|max_uar_stack_size_log
decl_stmt|;
name|bool
name|uar_noreserve
decl_stmt|;
name|int
name|max_malloc_fill_size
decl_stmt|,
name|malloc_fill_byte
decl_stmt|;
name|int
name|exitcode
decl_stmt|;
name|bool
name|allow_user_poisoning
decl_stmt|;
name|int
name|sleep_before_dying
decl_stmt|;
name|bool
name|check_malloc_usable_size
decl_stmt|;
name|bool
name|unmap_shadow_on_exit
decl_stmt|;
name|bool
name|abort_on_error
decl_stmt|;
name|bool
name|print_stats
decl_stmt|;
name|bool
name|print_legend
decl_stmt|;
name|bool
name|atexit
decl_stmt|;
name|bool
name|allow_reexec
decl_stmt|;
name|bool
name|print_full_thread_history
decl_stmt|;
name|bool
name|poison_heap
decl_stmt|;
name|bool
name|poison_partial
decl_stmt|;
name|bool
name|poison_array_cookie
decl_stmt|;
name|bool
name|alloc_dealloc_mismatch
decl_stmt|;
name|bool
name|new_delete_type_mismatch
decl_stmt|;
name|bool
name|strict_memcmp
decl_stmt|;
name|bool
name|strict_init_order
decl_stmt|;
name|bool
name|start_deactivated
decl_stmt|;
name|int
name|detect_invalid_pointer_pairs
decl_stmt|;
name|bool
name|detect_container_overflow
decl_stmt|;
name|int
name|detect_odr_violation
decl_stmt|;
name|bool
name|dump_instruction_bytes
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

