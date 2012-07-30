begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- tsan_flags.h --------------------------------------------*- C++ -*-===//
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
comment|// This file is a part of ThreadSanitizer (TSan), a race detector.
end_comment

begin_comment
comment|// NOTE: This file may be included into user code.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TSAN_FLAGS_H
end_ifndef

begin_define
define|#
directive|define
name|TSAN_FLAGS_H
end_define

begin_comment
comment|// ----------- ATTENTION -------------
end_comment

begin_comment
comment|// ThreadSanitizer user may provide its implementation of weak
end_comment

begin_comment
comment|// symbol __tsan::OverrideFlags(__tsan::Flags). Therefore, this
end_comment

begin_comment
comment|// header may be included in the user code, and shouldn't include
end_comment

begin_comment
comment|// other headers from TSan or common sanitizer runtime.
end_comment

begin_decl_stmt
name|namespace
name|__tsan
block|{
struct|struct
name|Flags
block|{
comment|// Enable dynamic annotations, otherwise they are no-ops.
name|bool
name|enable_annotations
decl_stmt|;
comment|// Supress a race report if we've already output another race report
comment|// with the same stack.
name|bool
name|suppress_equal_stacks
decl_stmt|;
comment|// Supress a race report if we've already output another race report
comment|// on the same address.
name|bool
name|suppress_equal_addresses
decl_stmt|;
comment|// Report thread leaks at exit?
name|bool
name|report_thread_leaks
decl_stmt|;
comment|// Report violations of async signal-safety
comment|// (e.g. malloc() call from a signal handler).
name|bool
name|report_signal_unsafe
decl_stmt|;
comment|// If set, all atomics are effectively sequentially consistent (seq_cst),
comment|// regardless of what user actually specified.
name|bool
name|force_seq_cst_atomics
decl_stmt|;
comment|// Strip that prefix from file paths in reports.
specifier|const
name|char
modifier|*
name|strip_path_prefix
decl_stmt|;
comment|// Suppressions filename.
specifier|const
name|char
modifier|*
name|suppressions
decl_stmt|;
comment|// Override exit status if something was reported.
name|int
name|exitcode
decl_stmt|;
comment|// Log fileno (1 - stdout, 2 - stderr).
name|int
name|log_fileno
decl_stmt|;
comment|// Sleep in main thread before exiting for that many ms
comment|// (useful to catch "at exit" races).
name|int
name|atexit_sleep_ms
decl_stmt|;
comment|// Verbosity level (0 - silent, 1 - a bit of output, 2+ - more output).
name|int
name|verbosity
decl_stmt|;
comment|// If set, periodically write memory profile to that file.
specifier|const
name|char
modifier|*
name|profile_memory
decl_stmt|;
comment|// Flush shadow memory every X ms.
name|int
name|flush_memory_ms
decl_stmt|;
comment|// Stops on start until __tsan_resume() is called (for debugging).
name|bool
name|stop_on_start
decl_stmt|;
comment|// Controls whether RunningOnValgrind() returns true or false.
name|bool
name|running_on_valgrind
decl_stmt|;
comment|// If set, uses in-process symbolizer from common sanitizer runtime.
name|bool
name|use_internal_symbolizer
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
name|flags
parameter_list|,
specifier|const
name|char
modifier|*
name|env
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// TSAN_FLAGS_H
end_comment

end_unit

