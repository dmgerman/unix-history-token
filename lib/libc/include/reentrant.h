begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997,98 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by J.T. Conklin.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Requirements:  *   * 1. The thread safe mechanism should be lightweight so the library can  *    be used by non-threaded applications without unreasonable overhead.  *   * 2. There should be no dependency on a thread engine for non-threaded  *    applications.  *   * 3. There should be no dependency on any particular thread engine.  *   * 4. The library should be able to be compiled without support for thread  *    safety.  *   *   * Rationale:  *   * One approach for thread safety is to provide discrete versions of the  * library: one thread safe, the other not.  The disadvantage of this is  * that libc is rather large, and two copies of a library which are 99%+  * identical is not an efficent use of resources.  *   * Another approach is to provide a single thread safe library.  However,  * it should not add significant run time or code size overhead to non-  * threaded applications.  *   * Since the NetBSD C library is used in other projects, it should be  * easy to replace the mutual exclusion primitives with ones provided by  * another system.  Similarly, it should also be easy to remove all  * support for thread safety completely if the target environment does  * not support threads.  *   *   * Implementation Details:  *   * The mutex primitives used by the library (mutex_t, mutex_lock, etc.)  * are macros which expand to the cooresponding primitives provided by  * the thread engine or to nothing.  The latter is used so that code is  * not unreasonably cluttered with #ifdefs when all thread safe support  * is removed.  *   * The mutex macros can be directly mapped to the mutex primitives from  * pthreads, however it should be reasonably easy to wrap another mutex  * implementation so it presents a similar interface.  *   * Stub implementations of the mutex functions are provided with *weak*  * linkage.  These functions simply return success.  When linked with a  * thread library (i.e. -lpthread), the functions will override the  * stubs.  */
end_comment

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<pthread_np.h>
end_include

begin_include
include|#
directive|include
file|"libc_private.h"
end_include

begin_define
define|#
directive|define
name|mutex_t
value|pthread_mutex_t
end_define

begin_define
define|#
directive|define
name|cond_t
value|pthread_cond_t
end_define

begin_define
define|#
directive|define
name|rwlock_t
value|pthread_rwlock_t
end_define

begin_define
define|#
directive|define
name|once_t
value|pthread_once_t
end_define

begin_define
define|#
directive|define
name|thread_key_t
value|pthread_key_t
end_define

begin_define
define|#
directive|define
name|MUTEX_INITIALIZER
value|PTHREAD_MUTEX_INITIALIZER
end_define

begin_define
define|#
directive|define
name|RWLOCK_INITIALIZER
value|PTHREAD_RWLOCK_INITIALIZER
end_define

begin_define
define|#
directive|define
name|ONCE_INITIALIZER
value|PTHREAD_ONCE_INIT
end_define

begin_define
define|#
directive|define
name|mutex_init
parameter_list|(
name|m
parameter_list|,
name|a
parameter_list|)
value|_pthread_mutex_init(m, a)
end_define

begin_define
define|#
directive|define
name|mutex_lock
parameter_list|(
name|m
parameter_list|)
value|if (__isthreaded) \ 				_pthread_mutex_lock(m)
end_define

begin_define
define|#
directive|define
name|mutex_unlock
parameter_list|(
name|m
parameter_list|)
value|if (__isthreaded) \ 				_pthread_mutex_unlock(m)
end_define

begin_define
define|#
directive|define
name|mutex_trylock
parameter_list|(
name|m
parameter_list|)
value|(__isthreaded ? 0 : _pthread_mutex_trylock(m))
end_define

begin_define
define|#
directive|define
name|cond_init
parameter_list|(
name|c
parameter_list|,
name|a
parameter_list|,
name|p
parameter_list|)
value|_pthread_cond_init(c, a)
end_define

begin_define
define|#
directive|define
name|cond_signal
parameter_list|(
name|m
parameter_list|)
value|if (__isthreaded) \ 				_pthread_cond_signal(m)
end_define

begin_define
define|#
directive|define
name|cond_broadcast
parameter_list|(
name|m
parameter_list|)
value|if (__isthreaded) \ 				_pthread_cond_broadcast(m)
end_define

begin_define
define|#
directive|define
name|cond_wait
parameter_list|(
name|c
parameter_list|,
name|m
parameter_list|)
value|if (__isthreaded) \ 				_pthread_cond_wait(c, m)
end_define

begin_define
define|#
directive|define
name|rwlock_init
parameter_list|(
name|l
parameter_list|,
name|a
parameter_list|)
value|_pthread_rwlock_init(l, a)
end_define

begin_define
define|#
directive|define
name|rwlock_rdlock
parameter_list|(
name|l
parameter_list|)
value|if (__isthreaded) \ 				_pthread_rwlock_rdlock(l)
end_define

begin_define
define|#
directive|define
name|rwlock_wrlock
parameter_list|(
name|l
parameter_list|)
value|if (__isthreaded) \ 				_pthread_rwlock_wrlock(l)
end_define

begin_define
define|#
directive|define
name|rwlock_unlock
parameter_list|(
name|l
parameter_list|)
value|if (__isthreaded) \ 				_pthread_rwlock_unlock(l)
end_define

begin_define
define|#
directive|define
name|thr_keycreate
parameter_list|(
name|k
parameter_list|,
name|d
parameter_list|)
value|_pthread_key_create(k, d)
end_define

begin_define
define|#
directive|define
name|thr_setspecific
parameter_list|(
name|k
parameter_list|,
name|p
parameter_list|)
value|_pthread_setspecific(k, p)
end_define

begin_define
define|#
directive|define
name|thr_getspecific
parameter_list|(
name|k
parameter_list|)
value|_pthread_getspecific(k)
end_define

begin_define
define|#
directive|define
name|thr_sigsetmask
parameter_list|(
name|f
parameter_list|,
name|n
parameter_list|,
name|o
parameter_list|)
value|_pthread_sigmask(f, n, o)
end_define

begin_define
define|#
directive|define
name|thr_once
parameter_list|(
name|o
parameter_list|,
name|i
parameter_list|)
value|_pthread_once(o, i)
end_define

begin_define
define|#
directive|define
name|thr_self
parameter_list|()
value|_pthread_self()
end_define

begin_define
define|#
directive|define
name|thr_exit
parameter_list|(
name|x
parameter_list|)
value|_pthread_exit(x)
end_define

begin_define
define|#
directive|define
name|thr_main
parameter_list|()
value|_pthread_main_np()
end_define

end_unit

