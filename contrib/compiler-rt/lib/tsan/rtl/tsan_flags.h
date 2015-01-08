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

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_flags.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_deadlock_detector_interface.h"
end_include

begin_decl_stmt
name|namespace
name|__tsan
block|{
name|struct
name|Flags
range|:
name|DDFlags
block|{
comment|// Enable dynamic annotations, otherwise they are no-ops.
name|bool
name|enable_annotations
block|;
comment|// Suppress a race report if we've already output another race report
comment|// with the same stack.
name|bool
name|suppress_equal_stacks
block|;
comment|// Suppress a race report if we've already output another race report
comment|// on the same address.
name|bool
name|suppress_equal_addresses
block|;
comment|// Turns off bug reporting entirely (useful for benchmarking).
name|bool
name|report_bugs
block|;
comment|// Report thread leaks at exit?
name|bool
name|report_thread_leaks
block|;
comment|// Report destruction of a locked mutex?
name|bool
name|report_destroy_locked
block|;
comment|// Report incorrect usages of mutexes and mutex annotations?
name|bool
name|report_mutex_bugs
block|;
comment|// Report violations of async signal-safety
comment|// (e.g. malloc() call from a signal handler).
name|bool
name|report_signal_unsafe
block|;
comment|// Report races between atomic and plain memory accesses.
name|bool
name|report_atomic_races
block|;
comment|// If set, all atomics are effectively sequentially consistent (seq_cst),
comment|// regardless of what user actually specified.
name|bool
name|force_seq_cst_atomics
block|;
comment|// Print matched "benign" races at exit.
name|bool
name|print_benign
block|;
comment|// Override exit status if something was reported.
name|int
name|exitcode
block|;
comment|// Exit after first reported error.
name|bool
name|halt_on_error
block|;
comment|// Sleep in main thread before exiting for that many ms
comment|// (useful to catch "at exit" races).
name|int
name|atexit_sleep_ms
block|;
comment|// If set, periodically write memory profile to that file.
specifier|const
name|char
operator|*
name|profile_memory
block|;
comment|// Flush shadow memory every X ms.
name|int
name|flush_memory_ms
block|;
comment|// Flush symbolizer caches every X ms.
name|int
name|flush_symbolizer_ms
block|;
comment|// Resident memory limit in MB to aim at.
comment|// If the process consumes more memory, then TSan will flush shadow memory.
name|int
name|memory_limit_mb
block|;
comment|// Stops on start until __tsan_resume() is called (for debugging).
name|bool
name|stop_on_start
block|;
comment|// Controls whether RunningOnValgrind() returns true or false.
name|bool
name|running_on_valgrind
block|;
comment|// Per-thread history size, controls how many previous memory accesses
comment|// are remembered per thread.  Possible values are [0..7].
comment|// history_size=0 amounts to 32K memory accesses.  Each next value doubles
comment|// the amount of memory accesses, up to history_size=7 that amounts to
comment|// 4M memory accesses.  The default value is 2 (128K memory accesses).
name|int
name|history_size
block|;
comment|// Controls level of synchronization implied by IO operations.
comment|// 0 - no synchronization
comment|// 1 - reasonable level of synchronization (write->read)
comment|// 2 - global synchronization of all IO operations
name|int
name|io_sync
block|;
comment|// Die after multi-threaded fork if the child creates new threads.
name|bool
name|die_after_fork
block|; }
decl_stmt|;
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

