begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- tsan_interface_java.h -----------------------------------*- C++ -*-===//
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
comment|//
end_comment

begin_comment
comment|// Interface for verification of Java or mixed Java/C++ programs.
end_comment

begin_comment
comment|// The interface is intended to be used from within a JVM and notify TSan
end_comment

begin_comment
comment|// about such events like Java locks and GC memory compaction.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// For plain memory accesses and function entry/exit a JVM is intended to use
end_comment

begin_comment
comment|// C++ interfaces: __tsan_readN/writeN and __tsan_func_enter/exit.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// For volatile memory accesses and atomic operations JVM is intended to use
end_comment

begin_comment
comment|// standard atomics API: __tsan_atomicN_load/store/etc.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// For usage examples see lit_tests/java_*.cc
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TSAN_INTERFACE_JAVA_H
end_ifndef

begin_define
define|#
directive|define
name|TSAN_INTERFACE_JAVA_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|INTERFACE_ATTRIBUTE
end_ifndef

begin_define
define|#
directive|define
name|INTERFACE_ATTRIBUTE
value|__attribute__((visibility("default")))
end_define

begin_endif
endif|#
directive|endif
end_endif

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
typedef|typedef
name|unsigned
name|long
name|jptr
typedef|;
comment|// NOLINT
comment|// Must be called before any other callback from Java.
name|void
name|__tsan_java_init
argument_list|(
name|jptr
name|heap_begin
argument_list|,
name|jptr
name|heap_size
argument_list|)
name|INTERFACE_ATTRIBUTE
decl_stmt|;
comment|// Must be called when the application exits.
comment|// Not necessary the last callback (concurrently running threads are OK).
comment|// Returns exit status or 0 if tsan does not want to override it.
name|int
name|__tsan_java_fini
argument_list|()
name|INTERFACE_ATTRIBUTE
expr_stmt|;
comment|// Callback for memory allocations.
comment|// May be omitted for allocations that are not subject to data races
comment|// nor contain synchronization objects (e.g. String).
name|void
name|__tsan_java_alloc
argument_list|(
name|jptr
name|ptr
argument_list|,
name|jptr
name|size
argument_list|)
name|INTERFACE_ATTRIBUTE
decl_stmt|;
comment|// Callback for memory free.
comment|// Can be aggregated for several objects (preferably).
name|void
name|__tsan_java_free
argument_list|(
name|jptr
name|ptr
argument_list|,
name|jptr
name|size
argument_list|)
name|INTERFACE_ATTRIBUTE
decl_stmt|;
comment|// Callback for memory move by GC.
comment|// Can be aggregated for several objects (preferably).
comment|// The ranges can overlap.
name|void
name|__tsan_java_move
argument_list|(
name|jptr
name|src
argument_list|,
name|jptr
name|dst
argument_list|,
name|jptr
name|size
argument_list|)
name|INTERFACE_ATTRIBUTE
decl_stmt|;
comment|// This function must be called on the finalizer thread
comment|// before executing a batch of finalizers.
comment|// It ensures necessary synchronization between
comment|// java object creation and finalization.
name|void
name|__tsan_java_finalize
argument_list|()
name|INTERFACE_ATTRIBUTE
expr_stmt|;
comment|// Mutex lock.
comment|// Addr is any unique address associated with the mutex.
comment|// Can be called on recursive reentry.
name|void
name|__tsan_java_mutex_lock
argument_list|(
name|jptr
name|addr
argument_list|)
name|INTERFACE_ATTRIBUTE
decl_stmt|;
comment|// Mutex unlock.
name|void
name|__tsan_java_mutex_unlock
argument_list|(
name|jptr
name|addr
argument_list|)
name|INTERFACE_ATTRIBUTE
decl_stmt|;
comment|// Mutex read lock.
name|void
name|__tsan_java_mutex_read_lock
argument_list|(
name|jptr
name|addr
argument_list|)
name|INTERFACE_ATTRIBUTE
decl_stmt|;
comment|// Mutex read unlock.
name|void
name|__tsan_java_mutex_read_unlock
argument_list|(
name|jptr
name|addr
argument_list|)
name|INTERFACE_ATTRIBUTE
decl_stmt|;
comment|// Recursive mutex lock, intended for handling of Object.wait().
comment|// The 'rec' value must be obtained from the previous
comment|// __tsan_java_mutex_unlock_rec().
name|void
name|__tsan_java_mutex_lock_rec
argument_list|(
name|jptr
name|addr
argument_list|,
name|int
name|rec
argument_list|)
name|INTERFACE_ATTRIBUTE
decl_stmt|;
comment|// Recursive mutex unlock, intended for handling of Object.wait().
comment|// The return value says how many times this thread called lock()
comment|// w/o a pairing unlock() (i.e. how many recursive levels it unlocked).
comment|// It must be passed back to __tsan_java_mutex_lock_rec() to restore
comment|// the same recursion level.
name|int
name|__tsan_java_mutex_unlock_rec
argument_list|(
name|jptr
name|addr
argument_list|)
name|INTERFACE_ATTRIBUTE
decl_stmt|;
comment|// Raw acquire/release primitives.
comment|// Can be used to establish happens-before edges on volatile/final fields,
comment|// in atomic operations, etc. release_store is the same as release, but it
comment|// breaks release sequence on addr (see C++ standard 1.10/7 for details).
name|void
name|__tsan_java_acquire
argument_list|(
name|jptr
name|addr
argument_list|)
name|INTERFACE_ATTRIBUTE
decl_stmt|;
name|void
name|__tsan_java_release
argument_list|(
name|jptr
name|addr
argument_list|)
name|INTERFACE_ATTRIBUTE
decl_stmt|;
name|void
name|__tsan_java_release_store
argument_list|(
name|jptr
name|addr
argument_list|)
name|INTERFACE_ATTRIBUTE
decl_stmt|;
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

begin_undef
undef|#
directive|undef
name|INTERFACE_ATTRIBUTE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef TSAN_INTERFACE_JAVA_H
end_comment

end_unit

