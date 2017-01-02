begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- tsan_posix_util.h ---------------------------------------*- C++ -*-===//
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
comment|// Test POSIX utils.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TSAN_POSIX_UTIL_H
end_ifndef

begin_define
define|#
directive|define
name|TSAN_POSIX_UTIL_H
end_define

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__APPLE__
end_ifdef

begin_define
define|#
directive|define
name|__interceptor_memcpy
value|wrap_memcpy
end_define

begin_define
define|#
directive|define
name|__interceptor_memset
value|wrap_memset
end_define

begin_define
define|#
directive|define
name|__interceptor_pthread_create
value|wrap_pthread_create
end_define

begin_define
define|#
directive|define
name|__interceptor_pthread_join
value|wrap_pthread_join
end_define

begin_define
define|#
directive|define
name|__interceptor_pthread_detach
value|wrap_pthread_detach
end_define

begin_define
define|#
directive|define
name|__interceptor_pthread_mutex_init
value|wrap_pthread_mutex_init
end_define

begin_define
define|#
directive|define
name|__interceptor_pthread_mutex_lock
value|wrap_pthread_mutex_lock
end_define

begin_define
define|#
directive|define
name|__interceptor_pthread_mutex_unlock
value|wrap_pthread_mutex_unlock
end_define

begin_define
define|#
directive|define
name|__interceptor_pthread_mutex_destroy
value|wrap_pthread_mutex_destroy
end_define

begin_define
define|#
directive|define
name|__interceptor_pthread_mutex_trylock
value|wrap_pthread_mutex_trylock
end_define

begin_define
define|#
directive|define
name|__interceptor_pthread_rwlock_init
value|wrap_pthread_rwlock_init
end_define

begin_define
define|#
directive|define
name|__interceptor_pthread_rwlock_destroy
value|wrap_pthread_rwlock_destroy
end_define

begin_define
define|#
directive|define
name|__interceptor_pthread_rwlock_trywrlock
value|wrap_pthread_rwlock_trywrlock
end_define

begin_define
define|#
directive|define
name|__interceptor_pthread_rwlock_wrlock
value|wrap_pthread_rwlock_wrlock
end_define

begin_define
define|#
directive|define
name|__interceptor_pthread_rwlock_unlock
value|wrap_pthread_rwlock_unlock
end_define

begin_define
define|#
directive|define
name|__interceptor_pthread_rwlock_rdlock
value|wrap_pthread_rwlock_rdlock
end_define

begin_define
define|#
directive|define
name|__interceptor_pthread_rwlock_tryrdlock
value|wrap_pthread_rwlock_tryrdlock
end_define

begin_define
define|#
directive|define
name|__interceptor_pthread_cond_init
value|wrap_pthread_cond_init
end_define

begin_define
define|#
directive|define
name|__interceptor_pthread_cond_signal
value|wrap_pthread_cond_signal
end_define

begin_define
define|#
directive|define
name|__interceptor_pthread_cond_broadcast
value|wrap_pthread_cond_broadcast
end_define

begin_define
define|#
directive|define
name|__interceptor_pthread_cond_wait
value|wrap_pthread_cond_wait
end_define

begin_define
define|#
directive|define
name|__interceptor_pthread_cond_destroy
value|wrap_pthread_cond_destroy
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_extern
extern|extern
literal|"C"
name|void
modifier|*
name|__interceptor_memcpy
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|uptr
parameter_list|)
function_decl|;
end_extern

begin_extern
extern|extern
literal|"C"
name|void
modifier|*
name|__interceptor_memset
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|uptr
parameter_list|)
function_decl|;
end_extern

begin_extern
extern|extern
literal|"C"
name|int
name|__interceptor_pthread_create
parameter_list|(
name|pthread_t
modifier|*
name|thread
parameter_list|,
specifier|const
name|pthread_attr_t
modifier|*
name|attr
parameter_list|,
name|void
modifier|*
function_decl|(
modifier|*
name|start_routine
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_extern

begin_extern
extern|extern
literal|"C"
name|int
name|__interceptor_pthread_join
parameter_list|(
name|pthread_t
name|thread
parameter_list|,
name|void
modifier|*
modifier|*
name|value_ptr
parameter_list|)
function_decl|;
end_extern

begin_extern
extern|extern
literal|"C"
name|int
name|__interceptor_pthread_detach
parameter_list|(
name|pthread_t
name|thread
parameter_list|)
function_decl|;
end_extern

begin_extern
extern|extern
literal|"C"
name|int
name|__interceptor_pthread_mutex_init
parameter_list|(
name|pthread_mutex_t
modifier|*
name|mutex
parameter_list|,
specifier|const
name|pthread_mutexattr_t
modifier|*
name|attr
parameter_list|)
function_decl|;
end_extern

begin_extern
extern|extern
literal|"C"
name|int
name|__interceptor_pthread_mutex_lock
parameter_list|(
name|pthread_mutex_t
modifier|*
name|mutex
parameter_list|)
function_decl|;
end_extern

begin_extern
extern|extern
literal|"C"
name|int
name|__interceptor_pthread_mutex_unlock
parameter_list|(
name|pthread_mutex_t
modifier|*
name|mutex
parameter_list|)
function_decl|;
end_extern

begin_extern
extern|extern
literal|"C"
name|int
name|__interceptor_pthread_mutex_destroy
parameter_list|(
name|pthread_mutex_t
modifier|*
name|mutex
parameter_list|)
function_decl|;
end_extern

begin_extern
extern|extern
literal|"C"
name|int
name|__interceptor_pthread_mutex_trylock
parameter_list|(
name|pthread_mutex_t
modifier|*
name|mutex
parameter_list|)
function_decl|;
end_extern

begin_extern
extern|extern
literal|"C"
name|int
name|__interceptor_pthread_rwlock_init
parameter_list|(
name|pthread_rwlock_t
modifier|*
name|rwlock
parameter_list|,
specifier|const
name|pthread_rwlockattr_t
modifier|*
name|attr
parameter_list|)
function_decl|;
end_extern

begin_extern
extern|extern
literal|"C"
name|int
name|__interceptor_pthread_rwlock_destroy
parameter_list|(
name|pthread_rwlock_t
modifier|*
name|rwlock
parameter_list|)
function_decl|;
end_extern

begin_extern
extern|extern
literal|"C"
name|int
name|__interceptor_pthread_rwlock_trywrlock
parameter_list|(
name|pthread_rwlock_t
modifier|*
name|rwlock
parameter_list|)
function_decl|;
end_extern

begin_extern
extern|extern
literal|"C"
name|int
name|__interceptor_pthread_rwlock_wrlock
parameter_list|(
name|pthread_rwlock_t
modifier|*
name|rwlock
parameter_list|)
function_decl|;
end_extern

begin_extern
extern|extern
literal|"C"
name|int
name|__interceptor_pthread_rwlock_unlock
parameter_list|(
name|pthread_rwlock_t
modifier|*
name|rwlock
parameter_list|)
function_decl|;
end_extern

begin_extern
extern|extern
literal|"C"
name|int
name|__interceptor_pthread_rwlock_rdlock
parameter_list|(
name|pthread_rwlock_t
modifier|*
name|rwlock
parameter_list|)
function_decl|;
end_extern

begin_extern
extern|extern
literal|"C"
name|int
name|__interceptor_pthread_rwlock_tryrdlock
parameter_list|(
name|pthread_rwlock_t
modifier|*
name|rwlock
parameter_list|)
function_decl|;
end_extern

begin_extern
extern|extern
literal|"C"
name|int
name|__interceptor_pthread_cond_init
parameter_list|(
name|pthread_cond_t
modifier|*
name|cond
parameter_list|,
specifier|const
name|pthread_condattr_t
modifier|*
name|attr
parameter_list|)
function_decl|;
end_extern

begin_extern
extern|extern
literal|"C"
name|int
name|__interceptor_pthread_cond_signal
parameter_list|(
name|pthread_cond_t
modifier|*
name|cond
parameter_list|)
function_decl|;
end_extern

begin_extern
extern|extern
literal|"C"
name|int
name|__interceptor_pthread_cond_broadcast
parameter_list|(
name|pthread_cond_t
modifier|*
name|cond
parameter_list|)
function_decl|;
end_extern

begin_extern
extern|extern
literal|"C"
name|int
name|__interceptor_pthread_cond_wait
parameter_list|(
name|pthread_cond_t
modifier|*
name|cond
parameter_list|,
name|pthread_mutex_t
modifier|*
name|mutex
parameter_list|)
function_decl|;
end_extern

begin_extern
extern|extern
literal|"C"
name|int
name|__interceptor_pthread_cond_destroy
parameter_list|(
name|pthread_cond_t
modifier|*
name|cond
parameter_list|)
function_decl|;
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef TSAN_POSIX_UTIL_H
end_comment

end_unit

