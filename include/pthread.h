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

begin_comment
comment|/*  * Forward thread structure definition. This is opaque to the user.  */
end_comment

begin_struct_decl
struct_decl|struct
name|pthread
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Queue definitions.  */
end_comment

begin_struct
struct|struct
name|pthread_queue
block|{
name|struct
name|pthread
modifier|*
name|q_next
decl_stmt|;
name|struct
name|pthread
modifier|*
name|q_last
decl_stmt|;
name|void
modifier|*
name|q_data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Static queue initialization values.   */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_QUEUE_INITIALIZER
value|{ NULL, NULL, NULL }
end_define

begin_comment
comment|/*   * Mutex definitions.  */
end_comment

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

begin_union
union|union
name|pthread_mutex_data
block|{
name|void
modifier|*
name|m_ptr
decl_stmt|;
name|int
name|m_count
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|pthread_mutex
block|{
name|enum
name|pthread_mutextype
name|m_type
decl_stmt|;
name|struct
name|pthread_queue
name|m_queue
decl_stmt|;
name|struct
name|pthread
modifier|*
name|m_owner
decl_stmt|;
name|union
name|pthread_mutex_data
name|m_data
decl_stmt|;
name|long
name|m_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags for mutexes.   */
end_comment

begin_define
define|#
directive|define
name|MUTEX_FLAGS_PRIVATE
value|0x01
end_define

begin_define
define|#
directive|define
name|MUTEX_FLAGS_INITED
value|0x02
end_define

begin_define
define|#
directive|define
name|MUTEX_FLAGS_BUSY
value|0x04
end_define

begin_comment
comment|/*  * Static mutex initialization values.   */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_MUTEX_INITIALIZER
define|\
value|{ MUTEX_TYPE_FAST, PTHREAD_QUEUE_INITIALIZER, \ 	NULL, { NULL }, MUTEX_FLAGS_INITED }
end_define

begin_struct
struct|struct
name|pthread_mutex_attr
block|{
name|enum
name|pthread_mutextype
name|m_type
decl_stmt|;
name|long
name|m_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*   * Condition variable definitions.  */
end_comment

begin_enum
enum|enum
name|pthread_cond_type
block|{
name|COND_TYPE_FAST
block|,
name|COND_TYPE_MAX
block|}
enum|;
end_enum

begin_struct
struct|struct
name|pthread_cond
block|{
name|enum
name|pthread_cond_type
name|c_type
decl_stmt|;
name|struct
name|pthread_queue
name|c_queue
decl_stmt|;
name|void
modifier|*
name|c_data
decl_stmt|;
name|long
name|c_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pthread_cond_attr
block|{
name|enum
name|pthread_cond_type
name|c_type
decl_stmt|;
name|long
name|c_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags for condition variables.  */
end_comment

begin_define
define|#
directive|define
name|COND_FLAGS_PRIVATE
value|0x01
end_define

begin_define
define|#
directive|define
name|COND_FLAGS_INITED
value|0x02
end_define

begin_define
define|#
directive|define
name|COND_FLAGS_BUSY
value|0x04
end_define

begin_comment
comment|/*  * Static cond initialization values.   */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_COND_INITIALIZER
define|\
value|{ COND_TYPE_FAST, PTHREAD_QUEUE_INITIALIZER, NULL, COND_FLAGS_INITED }
end_define

begin_comment
comment|/*  * Cleanup definitions.  */
end_comment

begin_struct
struct|struct
name|pthread_cleanup
block|{
name|struct
name|pthread_cleanup
modifier|*
name|next
decl_stmt|;
name|void
function_decl|(
modifier|*
name|routine
function_decl|)
parameter_list|()
function_decl|;
name|void
modifier|*
name|routine_arg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Scheduling definitions.  */
end_comment

begin_enum
enum|enum
name|schedparam_policy
block|{
name|SCHED_RR
block|,
name|SCHED_IO
block|,
name|SCHED_FIFO
block|,
name|SCHED_OTHER
block|}
enum|;
end_enum

begin_struct
struct|struct
name|pthread_attr
block|{
name|enum
name|schedparam_policy
name|schedparam_policy
decl_stmt|;
name|int
name|prio
decl_stmt|;
name|int
name|suspend
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|void
modifier|*
name|arg_attr
decl_stmt|;
name|void
function_decl|(
modifier|*
name|cleanup_attr
function_decl|)
parameter_list|()
function_decl|;
name|void
modifier|*
name|stackaddr_attr
decl_stmt|;
name|size_t
name|stacksize_attr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sched_param
block|{
name|int
name|prio
decl_stmt|;
name|void
modifier|*
name|no_data
decl_stmt|;
block|}
struct|;
end_struct

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
name|struct
name|pthread_mutex
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
value|{ PTHREAD_NEEDS_INIT, PTHREAD_MUTEX_INITIALIZER }
end_define

begin_comment
comment|/*  * Type definitions.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|pthread_key_t
typedef|;
end_typedef

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
name|pthread_attr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|pthread_cond
name|pthread_cond_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|pthread_cond_attr
name|pthread_condattr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|pthread_mutex
name|pthread_mutex_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|pthread_mutex_attr
name|pthread_mutexattr_t
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
comment|/*  * Default attribute arguments.  */
end_comment

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

begin_ifndef
ifndef|#
directive|ifndef
name|PTHREAD_KERNEL
end_ifndef

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

begin_comment
comment|/*  * Thread function prototype definitions:  */
end_comment

begin_decl_stmt
name|__BEGIN_DECLS
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
name|pthread_detach
name|__P
argument_list|(
operator|(
name|pthread_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_resume
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
name|pthread_suspend
name|__P
argument_list|(
operator|(
name|pthread_t
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

begin_decl_stmt
name|int
name|pthread_attr_setcreatesuspend
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
name|int
name|pthread_keycreate
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
name|pthread_getspecific
name|__P
argument_list|(
operator|(
name|pthread_key_t
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
name|pthread_key_delete
name|__P
argument_list|(
operator|(
name|pthread_key_t
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

