begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993, 1994 by Chris Provenzano, proven@mit.edu  * Copyright (c) 1995-1998 by John Birrell<jb@cimlogic.com.au>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *  This product includes software developed by Chris Provenzano.  * 4. The name of Chris Provenzano may not be used to endorse or promote   *	  products derived from this software without specific prior written  *	  permission.  *  * THIS SOFTWARE IS PROVIDED BY CHRIS PROVENZANO ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL CHRIS PROVENZANO BE LIABLE FOR ANY   * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR   * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PTHREAD_H_
end_ifndef

begin_define
define|#
directive|define
name|_PTHREAD_H_
end_define

begin_comment
comment|/*  * Header files.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/signal.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<sched.h>
end_include

begin_comment
comment|/*  * Run-time invariant values:  */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_DESTRUCTOR_ITERATIONS
value|4
end_define

begin_define
define|#
directive|define
name|PTHREAD_KEYS_MAX
value|256
end_define

begin_define
define|#
directive|define
name|PTHREAD_STACK_MIN
value|1024
end_define

begin_define
define|#
directive|define
name|PTHREAD_THREADS_MAX
value|ULONG_MAX
end_define

begin_comment
comment|/*  * Flags for threads and thread attributes.  */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_DETACHED
value|0x1
end_define

begin_define
define|#
directive|define
name|PTHREAD_SCOPE_SYSTEM
value|0x2
end_define

begin_define
define|#
directive|define
name|PTHREAD_INHERIT_SCHED
value|0x4
end_define

begin_define
define|#
directive|define
name|PTHREAD_NOFLOAT
value|0x8
end_define

begin_define
define|#
directive|define
name|PTHREAD_CREATE_DETACHED
value|PTHREAD_DETACHED
end_define

begin_define
define|#
directive|define
name|PTHREAD_CREATE_JOINABLE
value|0
end_define

begin_define
define|#
directive|define
name|PTHREAD_SCOPE_PROCESS
value|0
end_define

begin_define
define|#
directive|define
name|PTHREAD_EXPLICIT_SCHED
value|0
end_define

begin_comment
comment|/*  * Flags for read/write lock attributes  */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_PROCESS_PRIVATE
value|0
end_define

begin_define
define|#
directive|define
name|PTHREAD_PROCESS_SHARED
value|1
end_define

begin_comment
comment|/*  * Flags for cancelling threads  */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_CANCEL_ENABLE
value|0
end_define

begin_define
define|#
directive|define
name|PTHREAD_CANCEL_DISABLE
value|1
end_define

begin_define
define|#
directive|define
name|PTHREAD_CANCEL_DEFERRED
value|0
end_define

begin_define
define|#
directive|define
name|PTHREAD_CANCEL_ASYNCHRONOUS
value|2
end_define

begin_define
define|#
directive|define
name|PTHREAD_CANCELED
value|((void *) 1)
end_define

begin_comment
comment|/*  * Forward structure definitions.  *  * These are mostly opaque to the user.  */
end_comment

begin_struct_decl
struct_decl|struct
name|pthread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pthread_attr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pthread_cond
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pthread_cond_attr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pthread_mutex
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pthread_mutex_attr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pthread_once
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pthread_rwlock
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pthread_rwlockattr
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Primitive system data type definitions required by P1003.1c.  *  * Note that P1003.1c specifies that there are no defined comparison  * or assignment operators for the types pthread_attr_t, pthread_cond_t,  * pthread_condattr_t, pthread_mutex_t, pthread_mutexattr_t.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|pthread
modifier|*
name|pthread_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|pthread_attr
modifier|*
name|pthread_attr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|pthread_mutex
modifier|*
name|pthread_mutex_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|pthread_mutex_attr
modifier|*
name|pthread_mutexattr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|pthread_cond
modifier|*
name|pthread_cond_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|pthread_cond_attr
modifier|*
name|pthread_condattr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|pthread_key_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|pthread_once
name|pthread_once_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|pthread_rwlock
modifier|*
name|pthread_rwlock_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|pthread_rwlockattr
modifier|*
name|pthread_rwlockattr_t
typedef|;
end_typedef

begin_comment
comment|/*  * Additional type definitions:  *  * Note that P1003.1c reserves the prefixes pthread_ and PTHREAD_ for  * use in header symbols.  */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|pthread_addr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|pthread_startroutine_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Once definitions.  */
end_comment

begin_struct
struct|struct
name|pthread_once
block|{
name|int
name|state
decl_stmt|;
name|pthread_mutex_t
name|mutex
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags for once initialization.  */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_NEEDS_INIT
value|0
end_define

begin_define
define|#
directive|define
name|PTHREAD_DONE_INIT
value|1
end_define

begin_comment
comment|/*  * Static once initialization values.   */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_ONCE_INIT
value|{ PTHREAD_NEEDS_INIT, NULL }
end_define

begin_comment
comment|/*  * Static initialization values.   */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_MUTEX_INITIALIZER
value|NULL
end_define

begin_define
define|#
directive|define
name|PTHREAD_COND_INITIALIZER
value|NULL
end_define

begin_define
define|#
directive|define
name|PTHREAD_RWLOCK_INITIALIZER
value|NULL
end_define

begin_comment
comment|/*  * Default attribute arguments (draft 4, deprecated).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PTHREAD_KERNEL
end_ifndef

begin_define
define|#
directive|define
name|pthread_condattr_default
value|NULL
end_define

begin_define
define|#
directive|define
name|pthread_mutexattr_default
value|NULL
end_define

begin_define
define|#
directive|define
name|pthread_attr_default
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PTHREAD_PRIO_NONE
value|0
end_define

begin_define
define|#
directive|define
name|PTHREAD_PRIO_INHERIT
value|1
end_define

begin_define
define|#
directive|define
name|PTHREAD_PRIO_PROTECT
value|2
end_define

begin_comment
comment|/*  * Mutex types (Single UNIX Specification, Version 2, 1997).  *  * Note that a mutex attribute with one of the following types:  *  *	PTHREAD_MUTEX_NORMAL  *	PTHREAD_MUTEX_RECURSIVE  *      MUTEX_TYPE_FAST (deprecated)  *	MUTEX_TYPE_COUNTING_FAST (deprecated)  *  * will deviate from POSIX specified semantics.  */
end_comment

begin_enum
enum|enum
name|pthread_mutextype
block|{
name|PTHREAD_MUTEX_ERRORCHECK
init|=
literal|1
block|,
comment|/* Default POSIX mutex */
name|PTHREAD_MUTEX_RECURSIVE
init|=
literal|2
block|,
comment|/* Recursive mutex */
name|PTHREAD_MUTEX_NORMAL
init|=
literal|3
block|,
comment|/* No error checking */
name|MUTEX_TYPE_MAX
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|PTHREAD_MUTEX_DEFAULT
value|PTHREAD_MUTEX_ERRORCHECK
end_define

begin_define
define|#
directive|define
name|MUTEX_TYPE_FAST
value|PTHREAD_MUTEX_NORMAL
end_define

begin_define
define|#
directive|define
name|MUTEX_TYPE_COUNTING_FAST
value|PTHREAD_MUTEX_RECURSIVE
end_define

begin_comment
comment|/*  * Thread function prototype definitions:  */
end_comment

begin_function_decl
name|__BEGIN_DECLS
name|int
name|pthread_attr_destroy
parameter_list|(
name|pthread_attr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_attr_getstacksize
parameter_list|(
specifier|const
name|pthread_attr_t
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_attr_getguardsize
parameter_list|(
specifier|const
name|pthread_attr_t
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_attr_getstackaddr
parameter_list|(
specifier|const
name|pthread_attr_t
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_attr_getdetachstate
parameter_list|(
specifier|const
name|pthread_attr_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_attr_init
parameter_list|(
name|pthread_attr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_attr_setstacksize
parameter_list|(
name|pthread_attr_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_attr_setguardsize
parameter_list|(
name|pthread_attr_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_attr_setstackaddr
parameter_list|(
name|pthread_attr_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_attr_setdetachstate
parameter_list|(
name|pthread_attr_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pthread_cleanup_pop
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pthread_cleanup_push
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|routine_arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_condattr_destroy
parameter_list|(
name|pthread_condattr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_condattr_init
parameter_list|(
name|pthread_condattr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_THREAD_PROCESS_SHARED
argument_list|)
end_if

begin_function_decl
name|int
name|pthread_condattr_getpshared
parameter_list|(
name|pthread_condattr_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_condattr_setpshared
parameter_list|(
name|pthread_condattr_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|pthread_cond_broadcast
parameter_list|(
name|pthread_cond_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_cond_destroy
parameter_list|(
name|pthread_cond_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_cond_init
parameter_list|(
name|pthread_cond_t
modifier|*
parameter_list|,
specifier|const
name|pthread_condattr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_cond_signal
parameter_list|(
name|pthread_cond_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_cond_timedwait
parameter_list|(
name|pthread_cond_t
modifier|*
parameter_list|,
name|pthread_mutex_t
modifier|*
parameter_list|,
specifier|const
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_cond_wait
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
name|pthread_create
parameter_list|(
name|pthread_t
modifier|*
parameter_list|,
specifier|const
name|pthread_attr_t
modifier|*
parameter_list|,
name|void
modifier|*
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_detach
parameter_list|(
name|pthread_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_equal
parameter_list|(
name|pthread_t
parameter_list|,
name|pthread_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|pthread_exit
argument_list|(
name|void
operator|*
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
modifier|*
name|pthread_getspecific
parameter_list|(
name|pthread_key_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_join
parameter_list|(
name|pthread_t
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_key_create
parameter_list|(
name|pthread_key_t
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_key_delete
parameter_list|(
name|pthread_key_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_kill
parameter_list|(
name|pthread_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_mutexattr_init
parameter_list|(
name|pthread_mutexattr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_mutexattr_destroy
parameter_list|(
name|pthread_mutexattr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_mutexattr_gettype
parameter_list|(
name|pthread_mutexattr_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_mutexattr_settype
parameter_list|(
name|pthread_mutexattr_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_mutex_destroy
parameter_list|(
name|pthread_mutex_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_mutex_init
parameter_list|(
name|pthread_mutex_t
modifier|*
parameter_list|,
specifier|const
name|pthread_mutexattr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_mutex_lock
parameter_list|(
name|pthread_mutex_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_mutex_trylock
parameter_list|(
name|pthread_mutex_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_mutex_unlock
parameter_list|(
name|pthread_mutex_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_once
parameter_list|(
name|pthread_once_t
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_rwlock_destroy
parameter_list|(
name|pthread_rwlock_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_rwlock_init
parameter_list|(
name|pthread_rwlock_t
modifier|*
parameter_list|,
specifier|const
name|pthread_rwlockattr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_rwlock_rdlock
parameter_list|(
name|pthread_rwlock_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_rwlock_tryrdlock
parameter_list|(
name|pthread_rwlock_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_rwlock_trywrlock
parameter_list|(
name|pthread_rwlock_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_rwlock_unlock
parameter_list|(
name|pthread_rwlock_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_rwlock_wrlock
parameter_list|(
name|pthread_rwlock_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_rwlockattr_init
parameter_list|(
name|pthread_rwlockattr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_rwlockattr_getpshared
parameter_list|(
specifier|const
name|pthread_rwlockattr_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_rwlockattr_setpshared
parameter_list|(
name|pthread_rwlockattr_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_rwlockattr_destroy
parameter_list|(
name|pthread_rwlockattr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pthread_t
name|pthread_self
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_setspecific
parameter_list|(
name|pthread_key_t
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_sigmask
parameter_list|(
name|int
parameter_list|,
specifier|const
name|sigset_t
modifier|*
parameter_list|,
name|sigset_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_cancel
parameter_list|(
name|pthread_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_setcancelstate
parameter_list|(
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_setcanceltype
parameter_list|(
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pthread_testcancel
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_getprio
parameter_list|(
name|pthread_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_setprio
parameter_list|(
name|pthread_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pthread_yield
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_THREAD_PROCESS_SHARED
argument_list|)
end_if

begin_function_decl
name|int
name|pthread_mutexattr_getpshared
parameter_list|(
name|pthread_mutexattr_t
modifier|*
parameter_list|,
name|int
modifier|*
name|pshared
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_mutexattr_setpshared
parameter_list|(
name|pthread_mutexattr_t
modifier|*
parameter_list|,
name|int
name|pshared
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|pthread_mutexattr_getprioceiling
parameter_list|(
name|pthread_mutexattr_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_mutexattr_setprioceiling
parameter_list|(
name|pthread_mutexattr_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_mutex_getprioceiling
parameter_list|(
name|pthread_mutex_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_mutex_setprioceiling
parameter_list|(
name|pthread_mutex_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_mutexattr_getprotocol
parameter_list|(
name|pthread_mutexattr_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_mutexattr_setprotocol
parameter_list|(
name|pthread_mutexattr_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_attr_getinheritsched
parameter_list|(
specifier|const
name|pthread_attr_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_attr_getschedparam
parameter_list|(
specifier|const
name|pthread_attr_t
modifier|*
parameter_list|,
name|struct
name|sched_param
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_attr_getschedpolicy
parameter_list|(
specifier|const
name|pthread_attr_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_attr_getscope
parameter_list|(
specifier|const
name|pthread_attr_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_attr_setinheritsched
parameter_list|(
name|pthread_attr_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_attr_setschedparam
parameter_list|(
name|pthread_attr_t
modifier|*
parameter_list|,
specifier|const
name|struct
name|sched_param
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_attr_setschedpolicy
parameter_list|(
name|pthread_attr_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_attr_setscope
parameter_list|(
name|pthread_attr_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_getschedparam
parameter_list|(
name|pthread_t
name|pthread
parameter_list|,
name|int
modifier|*
parameter_list|,
name|struct
name|sched_param
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pthread_setschedparam
parameter_list|(
name|pthread_t
parameter_list|,
name|int
parameter_list|,
specifier|const
name|struct
name|sched_param
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

