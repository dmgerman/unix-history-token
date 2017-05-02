begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- tsan_interface.h ----------------------------------------*- C++ -*-===//
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
comment|// Public interface header for TSan.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_TSAN_INTERFACE_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_TSAN_INTERFACE_H
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
comment|// __tsan_release establishes a happens-before relation with a preceding
comment|// __tsan_acquire on the same address.
name|void
name|__tsan_acquire
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
name|void
name|__tsan_release
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
comment|// Annotations for custom mutexes.
comment|// The annotations allow to get better reports (with sets of locked mutexes),
comment|// detect more types of bugs (e.g. mutex misuses, races between lock/unlock and
comment|// destruction and potential deadlocks) and improve precision and performance
comment|// (by ignoring individual atomic operations in mutex code). However, the
comment|// downside is that annotated mutex code itself is not checked for correctness.
comment|// Mutex creation flags are passed to __tsan_mutex_create annotation.
comment|// If mutex has no constructor and __tsan_mutex_create is not called,
comment|// the flags may be passed to __tsan_mutex_pre_lock/__tsan_mutex_post_lock
comment|// annotations.
comment|// Mutex has static storage duration and no-op constructor and destructor.
comment|// This effectively makes tsan ignore destroy annotation.
specifier|const
name|unsigned
name|__tsan_mutex_linker_init
init|=
literal|1
operator|<<
literal|0
decl_stmt|;
comment|// Mutex is write reentrant.
specifier|const
name|unsigned
name|__tsan_mutex_write_reentrant
init|=
literal|1
operator|<<
literal|1
decl_stmt|;
comment|// Mutex is read reentrant.
specifier|const
name|unsigned
name|__tsan_mutex_read_reentrant
init|=
literal|1
operator|<<
literal|2
decl_stmt|;
comment|// Mutex operation flags:
comment|// Denotes read lock operation.
specifier|const
name|unsigned
name|__tsan_mutex_read_lock
init|=
literal|1
operator|<<
literal|3
decl_stmt|;
comment|// Denotes try lock operation.
specifier|const
name|unsigned
name|__tsan_mutex_try_lock
init|=
literal|1
operator|<<
literal|4
decl_stmt|;
comment|// Denotes that a try lock operation has failed to acquire the mutex.
specifier|const
name|unsigned
name|__tsan_mutex_try_lock_failed
init|=
literal|1
operator|<<
literal|5
decl_stmt|;
comment|// Denotes that the lock operation acquires multiple recursion levels.
comment|// Number of levels is passed in recursion parameter.
comment|// This is useful for annotation of e.g. Java builtin monitors,
comment|// for which wait operation releases all recursive acquisitions of the mutex.
specifier|const
name|unsigned
name|__tsan_mutex_recursive_lock
init|=
literal|1
operator|<<
literal|6
decl_stmt|;
comment|// Denotes that the unlock operation releases all recursion levels.
comment|// Number of released levels is returned and later must be passed to
comment|// the corresponding __tsan_mutex_post_lock annotation.
specifier|const
name|unsigned
name|__tsan_mutex_recursive_unlock
init|=
literal|1
operator|<<
literal|7
decl_stmt|;
comment|// Annotate creation of a mutex.
comment|// Supported flags: mutex creation flags.
name|void
name|__tsan_mutex_create
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|unsigned
name|flags
parameter_list|)
function_decl|;
comment|// Annotate destruction of a mutex.
comment|// Supported flags:
comment|//   - __tsan_mutex_linker_init
name|void
name|__tsan_mutex_destroy
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|unsigned
name|flags
parameter_list|)
function_decl|;
comment|// Annotate start of lock operation.
comment|// Supported flags:
comment|//   - __tsan_mutex_read_lock
comment|//   - __tsan_mutex_try_lock
comment|//   - all mutex creation flags
name|void
name|__tsan_mutex_pre_lock
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|unsigned
name|flags
parameter_list|)
function_decl|;
comment|// Annotate end of lock operation.
comment|// Supported flags:
comment|//   - __tsan_mutex_read_lock (must match __tsan_mutex_pre_lock)
comment|//   - __tsan_mutex_try_lock (must match __tsan_mutex_pre_lock)
comment|//   - __tsan_mutex_try_lock_failed
comment|//   - __tsan_mutex_recursive_lock
comment|//   - all mutex creation flags
name|void
name|__tsan_mutex_post_lock
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|unsigned
name|flags
parameter_list|,
name|int
name|recursion
parameter_list|)
function_decl|;
comment|// Annotate start of unlock operation.
comment|// Supported flags:
comment|//   - __tsan_mutex_read_lock
comment|//   - __tsan_mutex_recursive_unlock
name|int
name|__tsan_mutex_pre_unlock
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|unsigned
name|flags
parameter_list|)
function_decl|;
comment|// Annotate end of unlock operation.
comment|// Supported flags:
comment|//   - __tsan_mutex_read_lock (must match __tsan_mutex_pre_unlock)
name|void
name|__tsan_mutex_post_unlock
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|unsigned
name|flags
parameter_list|)
function_decl|;
comment|// Annotate start/end of notify/signal/broadcast operation.
comment|// Supported flags: none.
name|void
name|__tsan_mutex_pre_signal
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|unsigned
name|flags
parameter_list|)
function_decl|;
name|void
name|__tsan_mutex_post_signal
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|unsigned
name|flags
parameter_list|)
function_decl|;
comment|// Annotate start/end of a region of code where lock/unlock/signal operation
comment|// diverts to do something else unrelated to the mutex. This can be used to
comment|// annotate, for example, calls into cooperative scheduler or contention
comment|// profiling code.
comment|// These annotations must be called only from within
comment|// __tsan_mutex_pre/post_lock, __tsan_mutex_pre/post_unlock,
comment|// __tsan_mutex_pre/post_signal regions.
comment|// Supported flags: none.
name|void
name|__tsan_mutex_pre_divert
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|unsigned
name|flags
parameter_list|)
function_decl|;
name|void
name|__tsan_mutex_post_divert
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|unsigned
name|flags
parameter_list|)
function_decl|;
comment|// External race detection API.
comment|// Can be used by non-instrumented libraries to detect when their objects are
comment|// being used in an unsafe manner.
comment|//   - __tsan_external_read/__tsan_external_write annotates the logical reads
comment|//       and writes of the object at the specified address. 'caller_pc' should
comment|//       be the PC of the library user, which the library can obtain with e.g.
comment|//       `__builtin_return_address(0)`.
comment|//   - __tsan_external_register_tag registers a 'tag' with the specified name,
comment|//       which is later used in read/write annotations to denote the object type
comment|//   - __tsan_external_assign_tag can optionally mark a heap object with a tag
name|void
modifier|*
name|__tsan_external_register_tag
parameter_list|(
specifier|const
name|char
modifier|*
name|object_type
parameter_list|)
function_decl|;
name|void
name|__tsan_external_assign_tag
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|void
modifier|*
name|tag
parameter_list|)
function_decl|;
name|void
name|__tsan_external_read
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|void
modifier|*
name|caller_pc
parameter_list|,
name|void
modifier|*
name|tag
parameter_list|)
function_decl|;
name|void
name|__tsan_external_write
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|void
modifier|*
name|caller_pc
parameter_list|,
name|void
modifier|*
name|tag
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
comment|// SANITIZER_TSAN_INTERFACE_H
end_comment

end_unit

