begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993, 1994 by Chris Provenzano, proven@mit.edu  * Copyright (c) 1995 by John Birrell<jb@cimlogic.com.au>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *  This product includes software developed by Chris Provenzano.  * 4. The name of Chris Provenzano may not be used to endorse or promote   *	  products derived from this software without specific prior written  *	  permission.  *  * THIS SOFTWARE IS PROVIDED BY CHRIS PROVENZANO ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL CHRIS PROVENZANO BE LIABLE FOR ANY   * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR   * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.  *  */
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
comment|/*  * Compile time symbolic constants for portability specifications:  *  * Note that those commented out are not currently supported by the  * implementation.  */
end_comment

begin_define
define|#
directive|define
name|_POSIX_THREADS
end_define

begin_define
define|#
directive|define
name|_POSIX_THREAD_ATTR_STACKADDR
end_define

begin_define
define|#
directive|define
name|_POSIX_THREAD_ATTR_STACKSIZE
end_define

begin_comment
comment|/* #define _POSIX_THREAD_PRIORITY_SCHEDULING */
end_comment

begin_comment
comment|/* #define _POSIX_THREAD_PRIO_INHERIT   */
end_comment

begin_comment
comment|/* #define _POSIX_THREAD_PRIO_PROTECT   */
end_comment

begin_comment
comment|/* #define _POSIX_THREAD_PROCESS_SHARED */
end_comment

begin_define
define|#
directive|define
name|_POSIX_THREAD_SAFE_FUNCTIONS
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
name|sched_param
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
operator|*
operator|(
operator|*
name|pthread_startroutine_t
operator|)
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
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
comment|/*  * Default attribute arguments.  */
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

begin_enum
enum|enum
name|pthread_mutextype
block|{
name|MUTEX_TYPE_FAST
init|=
literal|1
block|,
name|MUTEX_TYPE_COUNTING_FAST
init|=
literal|2
block|,
comment|/* Recursive */
name|MUTEX_TYPE_MAX
block|}
enum|;
end_enum

begin_comment
comment|/*  * Thread function prototype definitions:  */
end_comment

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|pthread_attr_destroy
name|__P
argument_list|(
operator|(
name|pthread_attr_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_attr_getinheritsched
name|__P
argument_list|(
operator|(
name|pthread_attr_t
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_attr_getschedparam
name|__P
argument_list|(
operator|(
name|pthread_attr_t
operator|*
operator|,
expr|struct
name|sched_param
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_attr_getschedpolicy
name|__P
argument_list|(
operator|(
name|pthread_attr_t
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_attr_getscope
name|__P
argument_list|(
operator|(
name|pthread_attr_t
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_attr_getstacksize
name|__P
argument_list|(
operator|(
name|pthread_attr_t
operator|*
operator|,
name|size_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_attr_getstackaddr
name|__P
argument_list|(
operator|(
name|pthread_attr_t
operator|*
operator|,
name|void
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_attr_getdetachstate
name|__P
argument_list|(
operator|(
name|pthread_attr_t
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_attr_init
name|__P
argument_list|(
operator|(
name|pthread_attr_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_attr_setinheritsched
name|__P
argument_list|(
operator|(
name|pthread_attr_t
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_attr_setschedparam
name|__P
argument_list|(
operator|(
name|pthread_attr_t
operator|*
operator|,
expr|struct
name|sched_param
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_attr_setschedpolicy
name|__P
argument_list|(
operator|(
name|pthread_attr_t
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_attr_setscope
name|__P
argument_list|(
operator|(
name|pthread_attr_t
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_attr_setstacksize
name|__P
argument_list|(
operator|(
name|pthread_attr_t
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_attr_setstackaddr
name|__P
argument_list|(
operator|(
name|pthread_attr_t
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_attr_setdetachstate
name|__P
argument_list|(
operator|(
name|pthread_attr_t
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pthread_cleanup_pop
name|__P
argument_list|(
operator|(
name|int
name|execute
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pthread_cleanup_push
name|__P
argument_list|(
operator|(
name|void
argument_list|(
operator|*
name|routine
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
operator|,
name|void
operator|*
name|routine_arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_condattr_destroy
name|__P
argument_list|(
operator|(
name|pthread_condattr_t
operator|*
name|attr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_condattr_init
name|__P
argument_list|(
operator|(
name|pthread_condattr_t
operator|*
name|attr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_condattr_getpshared
name|__P
argument_list|(
operator|(
name|pthread_condattr_t
operator|*
name|attr
operator|,
name|int
operator|*
name|pshared
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_condattr_setpshared
name|__P
argument_list|(
operator|(
name|pthread_condattr_t
operator|*
name|attr
operator|,
name|int
name|pshared
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_cond_broadcast
name|__P
argument_list|(
operator|(
name|pthread_cond_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_cond_destroy
name|__P
argument_list|(
operator|(
name|pthread_cond_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_cond_init
name|__P
argument_list|(
operator|(
name|pthread_cond_t
operator|*
operator|,
specifier|const
name|pthread_condattr_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_cond_signal
name|__P
argument_list|(
operator|(
name|pthread_cond_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_cond_timedwait
name|__P
argument_list|(
operator|(
name|pthread_cond_t
operator|*
operator|,
name|pthread_mutex_t
operator|*
operator|,
specifier|const
expr|struct
name|timespec
operator|*
name|abstime
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_cond_wait
name|__P
argument_list|(
operator|(
name|pthread_cond_t
operator|*
operator|,
name|pthread_mutex_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_create
name|__P
argument_list|(
operator|(
name|pthread_t
operator|*
operator|,
specifier|const
name|pthread_attr_t
operator|*
operator|,
name|void
operator|*
call|(
modifier|*
name|start_routine
call|)
argument_list|(
name|void
operator|*
argument_list|)
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_detach
name|__P
argument_list|(
operator|(
name|pthread_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_equal
name|__P
argument_list|(
operator|(
name|pthread_t
operator|,
name|pthread_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pthread_exit
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|pthread_getspecific
name|__P
argument_list|(
operator|(
name|pthread_key_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_join
name|__P
argument_list|(
operator|(
name|pthread_t
operator|,
name|void
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_key_create
name|__P
argument_list|(
operator|(
name|pthread_key_t
operator|*
operator|,
name|void
argument_list|(
operator|*
name|routine
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_key_delete
name|__P
argument_list|(
operator|(
name|pthread_key_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_kill
name|__P
argument_list|(
operator|(
expr|struct
name|pthread
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_mutexattr_destroy
name|__P
argument_list|(
operator|(
name|pthread_mutexattr_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_mutexattr_getprioceiling
name|__P
argument_list|(
operator|(
name|pthread_mutexattr_t
operator|*
operator|,
name|int
operator|*
name|prioceiling
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_mutexattr_getprotocol
name|__P
argument_list|(
operator|(
name|pthread_mutexattr_t
operator|*
operator|,
name|int
operator|*
name|protocol
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_mutexattr_getpshared
name|__P
argument_list|(
operator|(
name|pthread_mutexattr_t
operator|*
operator|,
name|int
operator|*
name|pshared
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_mutexattr_init
name|__P
argument_list|(
operator|(
name|pthread_mutexattr_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_mutexattr_setprioceiling
name|__P
argument_list|(
operator|(
name|pthread_mutexattr_t
operator|*
operator|,
name|int
name|prioceiling
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_mutexattr_setprotocol
name|__P
argument_list|(
operator|(
name|pthread_mutexattr_t
operator|*
operator|,
name|int
name|protocol
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_mutexattr_setpshared
name|__P
argument_list|(
operator|(
name|pthread_mutexattr_t
operator|*
operator|,
name|int
name|pshared
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_mutex_destroy
name|__P
argument_list|(
operator|(
name|pthread_mutex_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_mutex_getprioceiling
name|__P
argument_list|(
operator|(
name|pthread_mutex_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_mutex_init
name|__P
argument_list|(
operator|(
name|pthread_mutex_t
operator|*
operator|,
specifier|const
name|pthread_mutexattr_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_mutex_lock
name|__P
argument_list|(
operator|(
name|pthread_mutex_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_mutex_setprioceiling
name|__P
argument_list|(
operator|(
name|pthread_mutex_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_mutex_trylock
name|__P
argument_list|(
operator|(
name|pthread_mutex_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_mutex_unlock
name|__P
argument_list|(
operator|(
name|pthread_mutex_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_once
name|__P
argument_list|(
operator|(
name|pthread_once_t
operator|*
operator|,
name|void
argument_list|(
operator|*
name|init_routine
argument_list|)
argument_list|(
name|void
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|pthread_t
name|pthread_self
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_setcancelstate
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_setcanceltype
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_setspecific
name|__P
argument_list|(
operator|(
name|pthread_key_t
operator|,
specifier|const
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_sigmask
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|sigset_t
operator|*
operator|,
name|sigset_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_testcancel
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_getprio
name|__P
argument_list|(
operator|(
name|pthread_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_setprio
name|__P
argument_list|(
operator|(
name|pthread_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pthread_yield
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_setschedparam
name|__P
argument_list|(
operator|(
name|pthread_t
name|pthread
operator|,
name|int
name|policy
operator|,
expr|struct
name|sched_param
operator|*
name|param
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_getschedparam
name|__P
argument_list|(
operator|(
name|pthread_t
name|pthread
operator|,
name|int
operator|*
name|policy
operator|,
expr|struct
name|sched_param
operator|*
name|param
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_attr_setfloatstate
name|__P
argument_list|(
operator|(
name|pthread_attr_t
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_attr_getfloatstate
name|__P
argument_list|(
operator|(
name|pthread_attr_t
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_attr_setcleanup
name|__P
argument_list|(
operator|(
name|pthread_attr_t
operator|*
operator|,
name|void
argument_list|(
operator|*
name|routine
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

