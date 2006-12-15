begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2003 Daniel M. Eischen<deischen@freebsd.org>  * Copyright (c) 1995-1998 John Birrell<jb@cimlogic.com.au>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by John Birrell.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"namespace.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/signalvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/ttycom.h>
end_include

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_include
include|#
directive|include
file|<sys/rtprio.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<paths.h>
end_include

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
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"un-namespace.h"
end_include

begin_include
include|#
directive|include
file|"libc_private.h"
end_include

begin_include
include|#
directive|include
file|"thr_private.h"
end_include

begin_decl_stmt
name|char
modifier|*
name|_usrstack
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pthread
modifier|*
name|_thr_initial
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_libthr_debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_thread_event_mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pthread
modifier|*
name|_thread_last_event
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|pthreadlist
name|_thread_list
init|=
name|TAILQ_HEAD_INITIALIZER
argument_list|(
name|_thread_list
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|pthreadlist
name|_thread_gc_list
init|=
name|TAILQ_HEAD_INITIALIZER
argument_list|(
name|_thread_gc_list
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_thread_active_threads
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|atfork_head
name|_thr_atfork_list
init|=
name|TAILQ_HEAD_INITIALIZER
argument_list|(
name|_thr_atfork_list
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|umutex
name|_thr_atfork_lock
init|=
name|DEFAULT_UMUTEX
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pthread_prio
name|_thr_priorities
index|[
literal|3
index|]
init|=
block|{
block|{
name|RTP_PRIO_MIN
block|,
name|RTP_PRIO_MAX
block|,
literal|0
block|}
block|,
comment|/* FIFO */
block|{
literal|0
block|,
literal|0
block|,
literal|63
block|}
block|,
comment|/* OTHER */
block|{
name|RTP_PRIO_MIN
block|,
name|RTP_PRIO_MAX
block|,
literal|0
block|}
comment|/* RR */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pthread_attr
name|_pthread_attr_default
init|=
block|{
operator|.
name|sched_policy
operator|=
name|SCHED_OTHER
block|,
operator|.
name|sched_inherit
operator|=
literal|0
block|,
operator|.
name|prio
operator|=
literal|0
block|,
operator|.
name|suspend
operator|=
name|THR_CREATE_RUNNING
block|,
operator|.
name|flags
operator|=
name|PTHREAD_SCOPE_SYSTEM
block|,
operator|.
name|stackaddr_attr
operator|=
name|NULL
block|,
operator|.
name|stacksize_attr
operator|=
name|THR_STACK_DEFAULT
block|,
operator|.
name|guardsize_attr
operator|=
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pthread_mutex_attr
name|_pthread_mutexattr_default
init|=
block|{
operator|.
name|m_type
operator|=
name|PTHREAD_MUTEX_DEFAULT
block|,
operator|.
name|m_protocol
operator|=
name|PTHREAD_PRIO_NONE
block|,
operator|.
name|m_ceiling
operator|=
literal|0
block|,
operator|.
name|m_flags
operator|=
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default condition variable attributes: */
end_comment

begin_decl_stmt
name|struct
name|pthread_cond_attr
name|_pthread_condattr_default
init|=
block|{
operator|.
name|c_pshared
operator|=
name|PTHREAD_PROCESS_PRIVATE
block|,
operator|.
name|c_clockid
operator|=
name|CLOCK_REALTIME
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|pid_t
name|_thr_pid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_thr_is_smp
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|_thr_guard_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|_thr_stack_default
init|=
name|THR_STACK_DEFAULT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|_thr_stack_initial
init|=
name|THR_STACK_INITIAL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_thr_page_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_gc_count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|umutex
name|_mutex_static_lock
init|=
name|DEFAULT_UMUTEX
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|umutex
name|_cond_static_lock
init|=
name|DEFAULT_UMUTEX
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|umutex
name|_rwlock_static_lock
init|=
name|DEFAULT_UMUTEX
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|umutex
name|_keytable_lock
init|=
name|DEFAULT_UMUTEX
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|umutex
name|_thr_list_lock
init|=
name|DEFAULT_UMUTEX
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|umutex
name|_thr_event_lock
init|=
name|DEFAULT_UMUTEX
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|__pthread_cond_wait
parameter_list|(
name|pthread_cond_t
modifier|*
parameter_list|,
name|pthread_mutex_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__pthread_mutex_lock
parameter_list|(
name|pthread_mutex_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__pthread_mutex_trylock
parameter_list|(
name|pthread_mutex_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_thread_init_hack
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(constructor
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|static
name|void
name|init_private
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|init_main_thread
parameter_list|(
name|struct
name|pthread
modifier|*
name|thread
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * All weak references used within libc should be in this table.  * This is so that static libraries will work.  */
end_comment

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_fork
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_pthread_getspecific
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_pthread_key_create
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_pthread_key_delete
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_pthread_mutex_destroy
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_pthread_mutex_init
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_pthread_mutex_lock
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_pthread_mutex_trylock
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_pthread_mutex_unlock
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_pthread_mutexattr_init
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_pthread_mutexattr_destroy
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_pthread_mutexattr_settype
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_pthread_once
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_pthread_setspecific
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_raise
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_sem_destroy
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_sem_getvalue
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_sem_init
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_sem_post
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_sem_timedwait
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_sem_trywait
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_sem_wait
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_sigaction
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_sigprocmask
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_sigsuspend
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_sigtimedwait
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_sigwait
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_sigwaitinfo
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_spinlock
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_spinlock_debug
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_spinunlock
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_thread_init_hack
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_vfork
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * These are needed when linking statically.  All references within  * libgcc (and in the future libc) to these routines are weak, but  * if they are not (strongly) referenced by the application or other  * libraries, then the actual functions will not be loaded.  */
end_comment

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_pthread_once
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_pthread_key_create
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_pthread_key_delete
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_pthread_getspecific
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_pthread_setspecific
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_pthread_mutex_init
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_pthread_mutex_destroy
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_pthread_mutex_lock
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_pthread_mutex_trylock
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_pthread_mutex_unlock
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_pthread_create
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Pull in all symbols required by libthread_db */
end_comment

begin_expr_stmt
name|STATIC_LIB_REQUIRE
argument_list|(
name|_thread_state_running
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|DUAL_ENTRY
parameter_list|(
name|entry
parameter_list|)
define|\
value|(pthread_func_t)entry, (pthread_func_t)entry
end_define

begin_decl_stmt
specifier|static
name|pthread_func_t
name|jmp_table
index|[]
index|[
literal|2
index|]
init|=
block|{
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_atfork
argument_list|)
block|}
block|,
comment|/* PJT_ATFORK */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_attr_destroy
argument_list|)
block|}
block|,
comment|/* PJT_ATTR_DESTROY */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_attr_getdetachstate
argument_list|)
block|}
block|,
comment|/* PJT_ATTR_GETDETACHSTATE */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_attr_getguardsize
argument_list|)
block|}
block|,
comment|/* PJT_ATTR_GETGUARDSIZE */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_attr_getinheritsched
argument_list|)
block|}
block|,
comment|/* PJT_ATTR_GETINHERITSCHED */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_attr_getschedparam
argument_list|)
block|}
block|,
comment|/* PJT_ATTR_GETSCHEDPARAM */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_attr_getschedpolicy
argument_list|)
block|}
block|,
comment|/* PJT_ATTR_GETSCHEDPOLICY */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_attr_getscope
argument_list|)
block|}
block|,
comment|/* PJT_ATTR_GETSCOPE */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_attr_getstackaddr
argument_list|)
block|}
block|,
comment|/* PJT_ATTR_GETSTACKADDR */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_attr_getstacksize
argument_list|)
block|}
block|,
comment|/* PJT_ATTR_GETSTACKSIZE */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_attr_init
argument_list|)
block|}
block|,
comment|/* PJT_ATTR_INIT */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_attr_setdetachstate
argument_list|)
block|}
block|,
comment|/* PJT_ATTR_SETDETACHSTATE */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_attr_setguardsize
argument_list|)
block|}
block|,
comment|/* PJT_ATTR_SETGUARDSIZE */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_attr_setinheritsched
argument_list|)
block|}
block|,
comment|/* PJT_ATTR_SETINHERITSCHED */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_attr_setschedparam
argument_list|)
block|}
block|,
comment|/* PJT_ATTR_SETSCHEDPARAM */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_attr_setschedpolicy
argument_list|)
block|}
block|,
comment|/* PJT_ATTR_SETSCHEDPOLICY */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_attr_setscope
argument_list|)
block|}
block|,
comment|/* PJT_ATTR_SETSCOPE */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_attr_setstackaddr
argument_list|)
block|}
block|,
comment|/* PJT_ATTR_SETSTACKADDR */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_attr_setstacksize
argument_list|)
block|}
block|,
comment|/* PJT_ATTR_SETSTACKSIZE */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_cancel
argument_list|)
block|}
block|,
comment|/* PJT_CANCEL */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_cleanup_pop
argument_list|)
block|}
block|,
comment|/* PJT_CLEANUP_POP */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_cleanup_push
argument_list|)
block|}
block|,
comment|/* PJT_CLEANUP_PUSH */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_cond_broadcast
argument_list|)
block|}
block|,
comment|/* PJT_COND_BROADCAST */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_cond_destroy
argument_list|)
block|}
block|,
comment|/* PJT_COND_DESTROY */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_cond_init
argument_list|)
block|}
block|,
comment|/* PJT_COND_INIT */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_cond_signal
argument_list|)
block|}
block|,
comment|/* PJT_COND_SIGNAL */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_cond_timedwait
argument_list|)
block|}
block|,
comment|/* PJT_COND_TIMEDWAIT */
block|{
operator|(
name|pthread_func_t
operator|)
name|__pthread_cond_wait
block|,
operator|(
name|pthread_func_t
operator|)
name|_pthread_cond_wait
block|}
block|,
comment|/* PJT_COND_WAIT */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_detach
argument_list|)
block|}
block|,
comment|/* PJT_DETACH */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_equal
argument_list|)
block|}
block|,
comment|/* PJT_EQUAL */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_exit
argument_list|)
block|}
block|,
comment|/* PJT_EXIT */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_getspecific
argument_list|)
block|}
block|,
comment|/* PJT_GETSPECIFIC */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_join
argument_list|)
block|}
block|,
comment|/* PJT_JOIN */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_key_create
argument_list|)
block|}
block|,
comment|/* PJT_KEY_CREATE */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_key_delete
argument_list|)
block|}
block|,
comment|/* PJT_KEY_DELETE*/
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_kill
argument_list|)
block|}
block|,
comment|/* PJT_KILL */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_main_np
argument_list|)
block|}
block|,
comment|/* PJT_MAIN_NP */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_mutexattr_destroy
argument_list|)
block|}
block|,
comment|/* PJT_MUTEXATTR_DESTROY */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_mutexattr_init
argument_list|)
block|}
block|,
comment|/* PJT_MUTEXATTR_INIT */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_mutexattr_settype
argument_list|)
block|}
block|,
comment|/* PJT_MUTEXATTR_SETTYPE */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_mutex_destroy
argument_list|)
block|}
block|,
comment|/* PJT_MUTEX_DESTROY */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_mutex_init
argument_list|)
block|}
block|,
comment|/* PJT_MUTEX_INIT */
block|{
operator|(
name|pthread_func_t
operator|)
name|__pthread_mutex_lock
block|,
operator|(
name|pthread_func_t
operator|)
name|_pthread_mutex_lock
block|}
block|,
comment|/* PJT_MUTEX_LOCK */
block|{
operator|(
name|pthread_func_t
operator|)
name|__pthread_mutex_trylock
block|,
operator|(
name|pthread_func_t
operator|)
name|_pthread_mutex_trylock
block|}
block|,
comment|/* PJT_MUTEX_TRYLOCK */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_mutex_unlock
argument_list|)
block|}
block|,
comment|/* PJT_MUTEX_UNLOCK */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_once
argument_list|)
block|}
block|,
comment|/* PJT_ONCE */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_rwlock_destroy
argument_list|)
block|}
block|,
comment|/* PJT_RWLOCK_DESTROY */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_rwlock_init
argument_list|)
block|}
block|,
comment|/* PJT_RWLOCK_INIT */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_rwlock_rdlock
argument_list|)
block|}
block|,
comment|/* PJT_RWLOCK_RDLOCK */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_rwlock_tryrdlock
argument_list|)
block|}
block|,
comment|/* PJT_RWLOCK_TRYRDLOCK */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_rwlock_trywrlock
argument_list|)
block|}
block|,
comment|/* PJT_RWLOCK_TRYWRLOCK */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_rwlock_unlock
argument_list|)
block|}
block|,
comment|/* PJT_RWLOCK_UNLOCK */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_rwlock_wrlock
argument_list|)
block|}
block|,
comment|/* PJT_RWLOCK_WRLOCK */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_self
argument_list|)
block|}
block|,
comment|/* PJT_SELF */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_setcancelstate
argument_list|)
block|}
block|,
comment|/* PJT_SETCANCELSTATE */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_setcanceltype
argument_list|)
block|}
block|,
comment|/* PJT_SETCANCELTYPE */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_setspecific
argument_list|)
block|}
block|,
comment|/* PJT_SETSPECIFIC */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_sigmask
argument_list|)
block|}
block|,
comment|/* PJT_SIGMASK */
block|{
name|DUAL_ENTRY
argument_list|(
argument|_pthread_testcancel
argument_list|)
block|}
comment|/* PJT_TESTCANCEL */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|init_once
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * For the shared version of the threads library, the above is sufficient.  * But for the archive version of the library, we need a little bit more.  * Namely, we must arrange for this particular module to be pulled in from  * the archive library at link time.  To accomplish that, we define and  * initialize a variable, "_thread_autoinit_dummy_decl".  This variable is  * referenced (as an extern) from libc/stdlib/exit.c. This will always  * create a need for this module, ensuring that it is present in the  * executable.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_thread_autoinit_dummy_decl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_thread_autoinit_dummy_decl
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|_thread_init_hack
parameter_list|(
name|void
parameter_list|)
block|{
name|_libpthread_init
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Threaded process initialization.  *  * This is only called under two conditions:  *  *   1) Some thread routines have detected that the library hasn't yet  *      been initialized (_thr_initial == NULL&& curthread == NULL), or  *  *   2) An explicit call to reinitialize after a fork (indicated  *      by curthread != NULL)  */
end_comment

begin_function
name|void
name|_libpthread_init
parameter_list|(
name|struct
name|pthread
modifier|*
name|curthread
parameter_list|)
block|{
name|int
name|fd
decl_stmt|,
name|first
init|=
literal|0
decl_stmt|;
name|sigset_t
name|sigset
decl_stmt|,
name|oldset
decl_stmt|;
comment|/* Check if this function has already been called: */
if|if
condition|(
operator|(
name|_thr_initial
operator|!=
name|NULL
operator|)
operator|&&
operator|(
name|curthread
operator|==
name|NULL
operator|)
condition|)
comment|/* Only initialize the threaded application once. */
return|return;
comment|/* 	 * Check the size of the jump table to make sure it is preset 	 * with the correct number of entries. 	 */
if|if
condition|(
sizeof|sizeof
argument_list|(
name|jmp_table
argument_list|)
operator|!=
operator|(
sizeof|sizeof
argument_list|(
name|pthread_func_t
argument_list|)
operator|*
name|PJT_MAX
operator|*
literal|2
operator|)
condition|)
name|PANIC
argument_list|(
literal|"Thread jump table not properly initialized"
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|__thr_jtable
argument_list|,
name|jmp_table
argument_list|,
sizeof|sizeof
argument_list|(
name|jmp_table
argument_list|)
argument_list|)
expr_stmt|;
comment|/* 	 * Check for the special case of this process running as 	 * or in place of init as pid = 1: 	 */
if|if
condition|(
operator|(
name|_thr_pid
operator|=
name|getpid
argument_list|()
operator|)
operator|==
literal|1
condition|)
block|{
comment|/* 		 * Setup a new session for this process which is 		 * assumed to be running as root. 		 */
if|if
condition|(
name|setsid
argument_list|()
operator|==
operator|-
literal|1
condition|)
name|PANIC
argument_list|(
literal|"Can't set session ID"
argument_list|)
expr_stmt|;
if|if
condition|(
name|revoke
argument_list|(
name|_PATH_CONSOLE
argument_list|)
operator|!=
literal|0
condition|)
name|PANIC
argument_list|(
literal|"Can't revoke console"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|fd
operator|=
name|__sys_open
argument_list|(
name|_PATH_CONSOLE
argument_list|,
name|O_RDWR
argument_list|)
operator|)
operator|<
literal|0
condition|)
name|PANIC
argument_list|(
literal|"Can't open console"
argument_list|)
expr_stmt|;
if|if
condition|(
name|setlogin
argument_list|(
literal|"root"
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|PANIC
argument_list|(
literal|"Can't set login to root"
argument_list|)
expr_stmt|;
if|if
condition|(
name|_ioctl
argument_list|(
name|fd
argument_list|,
name|TIOCSCTTY
argument_list|,
operator|(
name|char
operator|*
operator|)
name|NULL
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|PANIC
argument_list|(
literal|"Can't set controlling terminal"
argument_list|)
expr_stmt|;
block|}
comment|/* Initialize pthread private data. */
name|init_private
argument_list|()
expr_stmt|;
comment|/* Set the initial thread. */
if|if
condition|(
name|curthread
operator|==
name|NULL
condition|)
block|{
name|first
operator|=
literal|1
expr_stmt|;
comment|/* Create and initialize the initial thread. */
name|curthread
operator|=
name|_thr_alloc
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|curthread
operator|==
name|NULL
condition|)
name|PANIC
argument_list|(
literal|"Can't allocate initial thread"
argument_list|)
expr_stmt|;
name|init_main_thread
argument_list|(
name|curthread
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Add the thread to the thread list queue. 	 */
name|THR_LIST_ADD
argument_list|(
name|curthread
argument_list|)
expr_stmt|;
name|_thread_active_threads
operator|=
literal|1
expr_stmt|;
comment|/* Setup the thread specific data */
name|_tcb_set
argument_list|(
name|curthread
operator|->
name|tcb
argument_list|)
expr_stmt|;
if|if
condition|(
name|first
condition|)
block|{
name|SIGFILLSET
argument_list|(
name|sigset
argument_list|)
expr_stmt|;
name|SIGDELSET
argument_list|(
name|sigset
argument_list|,
name|SIGTRAP
argument_list|)
expr_stmt|;
name|__sys_sigprocmask
argument_list|(
name|SIG_SETMASK
argument_list|,
operator|&
name|sigset
argument_list|,
operator|&
name|oldset
argument_list|)
expr_stmt|;
name|_thr_signal_init
argument_list|()
expr_stmt|;
name|_thr_initial
operator|=
name|curthread
expr_stmt|;
name|SIGDELSET
argument_list|(
name|oldset
argument_list|,
name|SIGCANCEL
argument_list|)
expr_stmt|;
name|__sys_sigprocmask
argument_list|(
name|SIG_SETMASK
argument_list|,
operator|&
name|oldset
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|_thread_event_mask
operator|&
name|TD_CREATE
condition|)
name|_thr_report_creation
argument_list|(
name|curthread
argument_list|,
name|curthread
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * This function and pthread_create() do a lot of the same things.  * It'd be nice to consolidate the common stuff in one place.  */
end_comment

begin_function
specifier|static
name|void
name|init_main_thread
parameter_list|(
name|struct
name|pthread
modifier|*
name|thread
parameter_list|)
block|{
name|struct
name|sched_param
name|sched_param
decl_stmt|;
comment|/* Setup the thread attributes. */
name|thr_self
argument_list|(
operator|&
name|thread
operator|->
name|tid
argument_list|)
expr_stmt|;
name|thread
operator|->
name|attr
operator|=
name|_pthread_attr_default
expr_stmt|;
comment|/* 	 * Set up the thread stack. 	 * 	 * Create a red zone below the main stack.  All other stacks 	 * are constrained to a maximum size by the parameters 	 * passed to mmap(), but this stack is only limited by 	 * resource limits, so this stack needs an explicitly mapped 	 * red zone to protect the thread stack that is just beyond. 	 */
if|if
condition|(
name|mmap
argument_list|(
name|_usrstack
operator|-
name|_thr_stack_initial
operator|-
name|_thr_guard_default
argument_list|,
name|_thr_guard_default
argument_list|,
literal|0
argument_list|,
name|MAP_ANON
argument_list|,
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
operator|==
name|MAP_FAILED
condition|)
name|PANIC
argument_list|(
literal|"Cannot allocate red zone for initial thread"
argument_list|)
expr_stmt|;
comment|/* 	 * Mark the stack as an application supplied stack so that it 	 * isn't deallocated. 	 * 	 * XXX - I'm not sure it would hurt anything to deallocate 	 *       the main thread stack because deallocation doesn't 	 *       actually free() it; it just puts it in the free 	 *       stack queue for later reuse. 	 */
name|thread
operator|->
name|attr
operator|.
name|stackaddr_attr
operator|=
name|_usrstack
operator|-
name|_thr_stack_initial
expr_stmt|;
name|thread
operator|->
name|attr
operator|.
name|stacksize_attr
operator|=
name|_thr_stack_initial
expr_stmt|;
name|thread
operator|->
name|attr
operator|.
name|guardsize_attr
operator|=
name|_thr_guard_default
expr_stmt|;
name|thread
operator|->
name|attr
operator|.
name|flags
operator||=
name|THR_STACK_USER
expr_stmt|;
comment|/* 	 * Write a magic value to the thread structure 	 * to help identify valid ones: 	 */
name|thread
operator|->
name|magic
operator|=
name|THR_MAGIC
expr_stmt|;
name|thread
operator|->
name|cancel_enable
operator|=
literal|1
expr_stmt|;
name|thread
operator|->
name|cancel_async
operator|=
literal|0
expr_stmt|;
name|thr_set_name
argument_list|(
name|thread
operator|->
name|tid
argument_list|,
literal|"initial thread"
argument_list|)
expr_stmt|;
comment|/* Initialize the mutex queue: */
name|TAILQ_INIT
argument_list|(
operator|&
name|thread
operator|->
name|mutexq
argument_list|)
expr_stmt|;
name|TAILQ_INIT
argument_list|(
operator|&
name|thread
operator|->
name|pp_mutexq
argument_list|)
expr_stmt|;
name|thread
operator|->
name|state
operator|=
name|PS_RUNNING
expr_stmt|;
name|_thr_getscheduler
argument_list|(
name|thread
operator|->
name|tid
argument_list|,
operator|&
name|thread
operator|->
name|attr
operator|.
name|sched_policy
argument_list|,
operator|&
name|sched_param
argument_list|)
expr_stmt|;
name|thread
operator|->
name|attr
operator|.
name|prio
operator|=
name|sched_param
operator|.
name|sched_priority
expr_stmt|;
comment|/* Others cleared to zero by thr_alloc() */
block|}
end_function

begin_function
specifier|static
name|void
name|init_private
parameter_list|(
name|void
parameter_list|)
block|{
name|size_t
name|len
decl_stmt|;
name|int
name|mib
index|[
literal|2
index|]
decl_stmt|;
name|_thr_umutex_init
argument_list|(
operator|&
name|_mutex_static_lock
argument_list|)
expr_stmt|;
name|_thr_umutex_init
argument_list|(
operator|&
name|_cond_static_lock
argument_list|)
expr_stmt|;
name|_thr_umutex_init
argument_list|(
operator|&
name|_rwlock_static_lock
argument_list|)
expr_stmt|;
name|_thr_umutex_init
argument_list|(
operator|&
name|_keytable_lock
argument_list|)
expr_stmt|;
name|_thr_umutex_init
argument_list|(
operator|&
name|_thr_atfork_lock
argument_list|)
expr_stmt|;
name|_thr_umutex_init
argument_list|(
operator|&
name|_thr_event_lock
argument_list|)
expr_stmt|;
name|_thr_once_init
argument_list|()
expr_stmt|;
name|_thr_spinlock_init
argument_list|()
expr_stmt|;
name|_thr_list_init
argument_list|()
expr_stmt|;
comment|/* 	 * Avoid reinitializing some things if they don't need to be, 	 * e.g. after a fork(). 	 */
if|if
condition|(
name|init_once
operator|==
literal|0
condition|)
block|{
comment|/* Find the stack top */
name|mib
index|[
literal|0
index|]
operator|=
name|CTL_KERN
expr_stmt|;
name|mib
index|[
literal|1
index|]
operator|=
name|KERN_USRSTACK
expr_stmt|;
name|len
operator|=
sizeof|sizeof
argument_list|(
name|_usrstack
argument_list|)
expr_stmt|;
if|if
condition|(
name|sysctl
argument_list|(
name|mib
argument_list|,
literal|2
argument_list|,
operator|&
name|_usrstack
argument_list|,
operator|&
name|len
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|PANIC
argument_list|(
literal|"Cannot get kern.usrstack from sysctl"
argument_list|)
expr_stmt|;
name|len
operator|=
sizeof|sizeof
argument_list|(
name|_thr_is_smp
argument_list|)
expr_stmt|;
name|sysctlbyname
argument_list|(
literal|"kern.smp.cpus"
argument_list|,
operator|&
name|_thr_is_smp
argument_list|,
operator|&
name|len
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|_thr_is_smp
operator|=
operator|(
name|_thr_is_smp
operator|>
literal|1
operator|)
expr_stmt|;
name|_thr_page_size
operator|=
name|getpagesize
argument_list|()
expr_stmt|;
name|_thr_guard_default
operator|=
name|_thr_page_size
expr_stmt|;
name|_pthread_attr_default
operator|.
name|guardsize_attr
operator|=
name|_thr_guard_default
expr_stmt|;
name|_pthread_attr_default
operator|.
name|stacksize_attr
operator|=
name|_thr_stack_default
expr_stmt|;
name|TAILQ_INIT
argument_list|(
operator|&
name|_thr_atfork_list
argument_list|)
expr_stmt|;
block|}
name|init_once
operator|=
literal|1
expr_stmt|;
block|}
end_function

end_unit

