begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2003 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_comment
comment|/*  * Provide wrapper macros for thread synchronization primitives so we  * can use native thread functions for those operating system that  * supports it.  *  * This is so libkrb5.so (or more importantly, libgssapi.so) can have  * thread support while the program that that dlopen(3)s the library  * don't need to be linked to libpthread.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEIM_THREADS_H
end_ifndef

begin_define
define|#
directive|define
name|HEIM_THREADS_H
value|1
end_define

begin_comment
comment|/* assume headers already included */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|&&
name|__NetBSD_Version__
operator|>=
literal|106120000
operator|&&
name|__NetBSD_Version__
operator|<
literal|299001200
operator|&&
name|defined
argument_list|(
name|ENABLE_PTHREAD_SUPPORT
argument_list|)
end_if

begin_comment
comment|/*  * NetBSD have a thread lib that we can use that part of libc that  * works regardless if application are linked to pthreads or not.  * NetBSD newer then 2.99.11 just use pthread.h, and the same thing  * will happen.  */
end_comment

begin_include
include|#
directive|include
file|<threadlib.h>
end_include

begin_define
define|#
directive|define
name|HEIMDAL_MUTEX
value|mutex_t
end_define

begin_define
define|#
directive|define
name|HEIMDAL_MUTEX_INITIALIZER
value|MUTEX_INITIALIZER
end_define

begin_define
define|#
directive|define
name|HEIMDAL_MUTEX_init
parameter_list|(
name|m
parameter_list|)
value|mutex_init(m, NULL)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_MUTEX_lock
parameter_list|(
name|m
parameter_list|)
value|mutex_lock(m)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_MUTEX_unlock
parameter_list|(
name|m
parameter_list|)
value|mutex_unlock(m)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_MUTEX_destroy
parameter_list|(
name|m
parameter_list|)
value|mutex_destroy(m)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK
value|rwlock_t
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK_INITIALIZER
value|RWLOCK_INITIALIZER
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK_init
parameter_list|(
name|l
parameter_list|)
value|rwlock_init(l, NULL)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK_rdlock
parameter_list|(
name|l
parameter_list|)
value|rwlock_rdlock(l)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK_wrlock
parameter_list|(
name|l
parameter_list|)
value|rwlock_wrlock(l)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK_tryrdlock
parameter_list|(
name|l
parameter_list|)
value|rwlock_tryrdlock(l)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK_trywrlock
parameter_list|(
name|l
parameter_list|)
value|rwlock_trywrlock(l)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK_unlock
parameter_list|(
name|l
parameter_list|)
value|rwlock_unlock(l)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK_destroy
parameter_list|(
name|l
parameter_list|)
value|rwlock_destroy(l)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_thread_key
value|thread_key_t
end_define

begin_define
define|#
directive|define
name|HEIMDAL_key_create
parameter_list|(
name|k
parameter_list|,
name|d
parameter_list|,
name|r
parameter_list|)
value|do { r = thr_keycreate(k,d); } while(0)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_setspecific
parameter_list|(
name|k
parameter_list|,
name|s
parameter_list|,
name|r
parameter_list|)
value|do { r = thr_setspecific(k,s); } while(0)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_getspecific
parameter_list|(
name|k
parameter_list|)
value|thr_getspecific(k)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_key_delete
parameter_list|(
name|k
parameter_list|)
value|thr_keydelete(k)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ENABLE_PTHREAD_SUPPORT
argument_list|)
operator|&&
operator|(
operator|!
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|__NetBSD_Version__
operator|>=
literal|299001200
operator|)
end_elif

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_define
define|#
directive|define
name|HEIMDAL_MUTEX
value|pthread_mutex_t
end_define

begin_define
define|#
directive|define
name|HEIMDAL_MUTEX_INITIALIZER
value|PTHREAD_MUTEX_INITIALIZER
end_define

begin_define
define|#
directive|define
name|HEIMDAL_MUTEX_init
parameter_list|(
name|m
parameter_list|)
value|pthread_mutex_init(m, NULL)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_MUTEX_lock
parameter_list|(
name|m
parameter_list|)
value|pthread_mutex_lock(m)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_MUTEX_unlock
parameter_list|(
name|m
parameter_list|)
value|pthread_mutex_unlock(m)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_MUTEX_destroy
parameter_list|(
name|m
parameter_list|)
value|pthread_mutex_destroy(m)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK
value|rwlock_t
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK_INITIALIZER
value|RWLOCK_INITIALIZER
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK_init
parameter_list|(
name|l
parameter_list|)
value|pthread_rwlock_init(l, NULL)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK_rdlock
parameter_list|(
name|l
parameter_list|)
value|pthread_rwlock_rdlock(l)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK_wrlock
parameter_list|(
name|l
parameter_list|)
value|pthread_rwlock_wrlock(l)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK_tryrdlock
parameter_list|(
name|l
parameter_list|)
value|pthread_rwlock_tryrdlock(l)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK_trywrlock
parameter_list|(
name|l
parameter_list|)
value|pthread_rwlock_trywrlock(l)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK_unlock
parameter_list|(
name|l
parameter_list|)
value|pthread_rwlock_unlock(l)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK_destroy
parameter_list|(
name|l
parameter_list|)
value|pthread_rwlock_destroy(l)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_thread_key
value|pthread_key_t
end_define

begin_define
define|#
directive|define
name|HEIMDAL_key_create
parameter_list|(
name|k
parameter_list|,
name|d
parameter_list|,
name|r
parameter_list|)
value|do { r = pthread_key_create(k,d); } while(0)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_setspecific
parameter_list|(
name|k
parameter_list|,
name|s
parameter_list|,
name|r
parameter_list|)
value|do { r = pthread_setspecific(k,s); } while(0)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_getspecific
parameter_list|(
name|k
parameter_list|)
value|pthread_getspecific(k)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_key_delete
parameter_list|(
name|k
parameter_list|)
value|pthread_key_delete(k)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HEIMDAL_DEBUG_THREADS
argument_list|)
end_elif

begin_comment
comment|/* no threads support, just do consistency checks */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_define
define|#
directive|define
name|HEIMDAL_MUTEX
value|int
end_define

begin_define
define|#
directive|define
name|HEIMDAL_MUTEX_INITIALIZER
value|0
end_define

begin_define
define|#
directive|define
name|HEIMDAL_MUTEX_init
parameter_list|(
name|m
parameter_list|)
value|do { (*(m)) = 0; } while(0)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_MUTEX_lock
parameter_list|(
name|m
parameter_list|)
value|do { if ((*(m))++ != 0) abort(); } while(0)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_MUTEX_unlock
parameter_list|(
name|m
parameter_list|)
value|do { if ((*(m))-- != 1) abort(); } while(0)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_MUTEX_destroy
parameter_list|(
name|m
parameter_list|)
value|do {if ((*(m)) != 0) abort(); } while(0)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK
value|rwlock_t int
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK_INITIALIZER
value|0
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK_init
parameter_list|(
name|l
parameter_list|)
value|do { } while(0)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK_rdlock
parameter_list|(
name|l
parameter_list|)
value|do { } while(0)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK_wrlock
parameter_list|(
name|l
parameter_list|)
value|do { } while(0)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK_tryrdlock
parameter_list|(
name|l
parameter_list|)
value|do { } while(0)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK_trywrlock
parameter_list|(
name|l
parameter_list|)
value|do { } while(0)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK_unlock
parameter_list|(
name|l
parameter_list|)
value|do { } while(0)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK_destroy
parameter_list|(
name|l
parameter_list|)
value|do { } while(0)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_internal_thread_key
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* no thread support, no debug case */
end_comment

begin_define
define|#
directive|define
name|HEIMDAL_MUTEX
value|int
end_define

begin_define
define|#
directive|define
name|HEIMDAL_MUTEX_INITIALIZER
value|0
end_define

begin_define
define|#
directive|define
name|HEIMDAL_MUTEX_init
parameter_list|(
name|m
parameter_list|)
value|do { (void)(m); } while(0)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_MUTEX_lock
parameter_list|(
name|m
parameter_list|)
value|do { (void)(m); } while(0)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_MUTEX_unlock
parameter_list|(
name|m
parameter_list|)
value|do { (void)(m); } while(0)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_MUTEX_destroy
parameter_list|(
name|m
parameter_list|)
value|do { (void)(m); } while(0)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK
value|rwlock_t int
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK_INITIALIZER
value|0
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK_init
parameter_list|(
name|l
parameter_list|)
value|do { } while(0)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK_rdlock
parameter_list|(
name|l
parameter_list|)
value|do { } while(0)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK_wrlock
parameter_list|(
name|l
parameter_list|)
value|do { } while(0)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK_tryrdlock
parameter_list|(
name|l
parameter_list|)
value|do { } while(0)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK_trywrlock
parameter_list|(
name|l
parameter_list|)
value|do { } while(0)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK_unlock
parameter_list|(
name|l
parameter_list|)
value|do { } while(0)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_RWLOCK_destroy
parameter_list|(
name|l
parameter_list|)
value|do { } while(0)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_internal_thread_key
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* no thread support */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HEIMDAL_internal_thread_key
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|heim_thread_key
block|{
name|void
modifier|*
name|value
decl_stmt|;
name|void
function_decl|(
modifier|*
name|destructor
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
block|}
name|heim_thread_key
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HEIMDAL_thread_key
value|heim_thread_key
end_define

begin_define
define|#
directive|define
name|HEIMDAL_key_create
parameter_list|(
name|k
parameter_list|,
name|d
parameter_list|,
name|r
parameter_list|)
define|\
value|do { (k)->value = NULL; (k)->destructor = (d); r = 0; } while(0)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_setspecific
parameter_list|(
name|k
parameter_list|,
name|s
parameter_list|,
name|r
parameter_list|)
value|do { (k).value = s ; r = 0; } while(0)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_getspecific
parameter_list|(
name|k
parameter_list|)
value|((k).value)
end_define

begin_define
define|#
directive|define
name|HEIMDAL_key_delete
parameter_list|(
name|k
parameter_list|)
value|do { (*(k).destructor)((k).value); } while(0)
end_define

begin_undef
undef|#
directive|undef
name|HEIMDAL_internal_thread_key
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HEIMDAL_internal_thread_key */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HEIM_THREADS_H */
end_comment

end_unit

