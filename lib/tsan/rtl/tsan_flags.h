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
comment|// Suppress weird race reports that can be seen if JVM is embed
comment|// into the process.
name|bool
name|suppress_java
decl_stmt|;
comment|// Turns off bug reporting entirely (useful for benchmarking).
name|bool
name|report_bugs
decl_stmt|;
comment|// Report thread leaks at exit?
name|bool
name|report_thread_leaks
decl_stmt|;
comment|// Report destruction of a locked mutex?
name|bool
name|report_destroy_locked
decl_stmt|;
comment|// Report violations of async signal-safety
comment|// (e.g. malloc() call from a signal handler).
name|bool
name|report_signal_unsafe
decl_stmt|;
comment|// Report races between atomic and plain memory accesses.
name|bool
name|report_atomic_races
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
comment|// Print matched suppressions at exit.
name|bool
name|print_suppressions
decl_stmt|;
comment|// Print matched "benign" races at exit.
name|bool
name|print_benign
decl_stmt|;
comment|// Override exit status if something was reported.
name|int
name|exitcode
decl_stmt|;
comment|// Write logs to "log_path.pid".
comment|// The special values are "stdout" and "stderr".
comment|// The default is "stderr".
specifier|const
name|char
modifier|*
name|log_path
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
comment|// Flush symbolizer caches every X ms.
name|int
name|flush_symbolizer_ms
decl_stmt|;
comment|// Stops on start until __tsan_resume() is called (for debugging).
name|bool
name|stop_on_start
decl_stmt|;
comment|// Controls whether RunningOnValgrind() returns true or false.
name|bool
name|running_on_valgrind
decl_stmt|;
comment|// Path to external symbolizer.
specifier|const
name|char
modifier|*
name|external_symbolizer_path
decl_stmt|;
comment|// Per-thread history size, controls how many previous memory accesses
comment|// are remembered per thread.  Possible values are [0..7].
comment|// history_size=0 amounts to 32K memory accesses.  Each next value doubles
comment|// the amount of memory accesses, up to history_size=7 that amounts to
comment|// 4M memory accesses.  The default value is 2 (128K memory accesses).
name|int
name|history_size
decl_stmt|;
comment|// Controls level of synchronization implied by IO operations.
comment|// 0 - no synchronization
comment|// 1 - reasonable level of synchronization (write->read)
comment|// 2 - global synchronization of all IO operations
name|int
name|io_sync
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

begin_comment
comment|// namespace __tsan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// TSAN_FLAGS_H
end_comment

end_unit

