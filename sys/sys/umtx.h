begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002, Jeffrey Roberson<jeff@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_UMTX_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_UMTX_H_
end_define

begin_include
include|#
directive|include
file|<sys/_umtx.h>
end_include

begin_include
include|#
directive|include
file|<sys/limits.h>
end_include

begin_define
define|#
directive|define
name|UMTX_UNOWNED
value|0x0
end_define

begin_define
define|#
directive|define
name|UMTX_CONTESTED
value|LONG_MIN
end_define

begin_define
define|#
directive|define
name|USYNC_PROCESS_SHARED
value|0x0001
end_define

begin_comment
comment|/* Process shared sync objs */
end_comment

begin_define
define|#
directive|define
name|UMUTEX_UNOWNED
value|0x0
end_define

begin_define
define|#
directive|define
name|UMUTEX_CONTESTED
value|0x80000000U
end_define

begin_define
define|#
directive|define
name|UMUTEX_ERROR_CHECK
value|0x0002
end_define

begin_comment
comment|/* Error-checking mutex */
end_comment

begin_define
define|#
directive|define
name|UMUTEX_PRIO_INHERIT
value|0x0004
end_define

begin_comment
comment|/* Priority inherited mutex */
end_comment

begin_define
define|#
directive|define
name|UMUTEX_PRIO_PROTECT
value|0x0008
end_define

begin_comment
comment|/* Priority protect mutex */
end_comment

begin_comment
comment|/* urwlock flags */
end_comment

begin_define
define|#
directive|define
name|URWLOCK_PREFER_READER
value|0x0002
end_define

begin_define
define|#
directive|define
name|URWLOCK_WRITE_OWNER
value|0x80000000U
end_define

begin_define
define|#
directive|define
name|URWLOCK_WRITE_WAITERS
value|0x40000000U
end_define

begin_define
define|#
directive|define
name|URWLOCK_READ_WAITERS
value|0x20000000U
end_define

begin_define
define|#
directive|define
name|URWLOCK_MAX_READERS
value|0x1fffffffU
end_define

begin_define
define|#
directive|define
name|URWLOCK_READER_COUNT
parameter_list|(
name|c
parameter_list|)
value|((c)& URWLOCK_MAX_READERS)
end_define

begin_comment
comment|/* _usem flags */
end_comment

begin_define
define|#
directive|define
name|SEM_NAMED
value|0x0002
end_define

begin_comment
comment|/* op code for _umtx_op */
end_comment

begin_define
define|#
directive|define
name|UMTX_OP_LOCK
value|0
end_define

begin_define
define|#
directive|define
name|UMTX_OP_UNLOCK
value|1
end_define

begin_define
define|#
directive|define
name|UMTX_OP_WAIT
value|2
end_define

begin_define
define|#
directive|define
name|UMTX_OP_WAKE
value|3
end_define

begin_define
define|#
directive|define
name|UMTX_OP_MUTEX_TRYLOCK
value|4
end_define

begin_define
define|#
directive|define
name|UMTX_OP_MUTEX_LOCK
value|5
end_define

begin_define
define|#
directive|define
name|UMTX_OP_MUTEX_UNLOCK
value|6
end_define

begin_define
define|#
directive|define
name|UMTX_OP_SET_CEILING
value|7
end_define

begin_define
define|#
directive|define
name|UMTX_OP_CV_WAIT
value|8
end_define

begin_define
define|#
directive|define
name|UMTX_OP_CV_SIGNAL
value|9
end_define

begin_define
define|#
directive|define
name|UMTX_OP_CV_BROADCAST
value|10
end_define

begin_define
define|#
directive|define
name|UMTX_OP_WAIT_UINT
value|11
end_define

begin_define
define|#
directive|define
name|UMTX_OP_RW_RDLOCK
value|12
end_define

begin_define
define|#
directive|define
name|UMTX_OP_RW_WRLOCK
value|13
end_define

begin_define
define|#
directive|define
name|UMTX_OP_RW_UNLOCK
value|14
end_define

begin_define
define|#
directive|define
name|UMTX_OP_WAIT_UINT_PRIVATE
value|15
end_define

begin_define
define|#
directive|define
name|UMTX_OP_WAKE_PRIVATE
value|16
end_define

begin_define
define|#
directive|define
name|UMTX_OP_MUTEX_WAIT
value|17
end_define

begin_define
define|#
directive|define
name|UMTX_OP_MUTEX_WAKE
value|18
end_define

begin_define
define|#
directive|define
name|UMTX_OP_SEM_WAIT
value|19
end_define

begin_define
define|#
directive|define
name|UMTX_OP_SEM_WAKE
value|20
end_define

begin_define
define|#
directive|define
name|UMTX_OP_MAX
value|21
end_define

begin_comment
comment|/* flags for UMTX_OP_CV_WAIT */
end_comment

begin_define
define|#
directive|define
name|UMTX_CHECK_UNPARKING
value|0x01
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_function_decl
name|int
name|_umtx_op
parameter_list|(
name|void
modifier|*
name|obj
parameter_list|,
name|int
name|op
parameter_list|,
name|u_long
name|val
parameter_list|,
name|void
modifier|*
name|uaddr
parameter_list|,
name|void
modifier|*
name|uaddr2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Old (deprecated) userland mutex system calls.  */
end_comment

begin_function_decl
name|int
name|_umtx_lock
parameter_list|(
name|struct
name|umtx
modifier|*
name|mtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_umtx_unlock
parameter_list|(
name|struct
name|umtx
modifier|*
name|mtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Standard api.  Try uncontested acquire/release and asks the  * kernel to resolve failures.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|umtx_init
parameter_list|(
name|struct
name|umtx
modifier|*
name|umtx
parameter_list|)
block|{
name|umtx
operator|->
name|u_owner
operator|=
name|UMTX_UNOWNED
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_long
name|umtx_owner
parameter_list|(
name|struct
name|umtx
modifier|*
name|umtx
parameter_list|)
block|{
return|return
operator|(
name|umtx
operator|->
name|u_owner
operator|&
operator|~
name|LONG_MIN
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|umtx_lock
parameter_list|(
name|struct
name|umtx
modifier|*
name|umtx
parameter_list|,
name|u_long
name|id
parameter_list|)
block|{
if|if
condition|(
name|atomic_cmpset_acq_long
argument_list|(
operator|&
name|umtx
operator|->
name|u_owner
argument_list|,
name|UMTX_UNOWNED
argument_list|,
name|id
argument_list|)
operator|==
literal|0
condition|)
if|if
condition|(
name|_umtx_lock
argument_list|(
name|umtx
argument_list|)
operator|==
operator|-
literal|1
condition|)
return|return
operator|(
name|errno
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|umtx_trylock
parameter_list|(
name|struct
name|umtx
modifier|*
name|umtx
parameter_list|,
name|u_long
name|id
parameter_list|)
block|{
if|if
condition|(
name|atomic_cmpset_acq_long
argument_list|(
operator|&
name|umtx
operator|->
name|u_owner
argument_list|,
name|UMTX_UNOWNED
argument_list|,
name|id
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|EBUSY
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|umtx_timedlock
parameter_list|(
name|struct
name|umtx
modifier|*
name|umtx
parameter_list|,
name|u_long
name|id
parameter_list|,
specifier|const
name|struct
name|timespec
modifier|*
name|timeout
parameter_list|)
block|{
if|if
condition|(
name|atomic_cmpset_acq_long
argument_list|(
operator|&
name|umtx
operator|->
name|u_owner
argument_list|,
name|UMTX_UNOWNED
argument_list|,
name|id
argument_list|)
operator|==
literal|0
condition|)
if|if
condition|(
name|_umtx_op
argument_list|(
name|umtx
argument_list|,
name|UMTX_OP_LOCK
argument_list|,
name|id
argument_list|,
literal|0
argument_list|,
name|__DECONST
argument_list|(
name|void
operator|*
argument_list|,
name|timeout
argument_list|)
argument_list|)
operator|==
operator|-
literal|1
condition|)
return|return
operator|(
name|errno
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|umtx_unlock
parameter_list|(
name|struct
name|umtx
modifier|*
name|umtx
parameter_list|,
name|u_long
name|id
parameter_list|)
block|{
if|if
condition|(
name|atomic_cmpset_rel_long
argument_list|(
operator|&
name|umtx
operator|->
name|u_owner
argument_list|,
name|id
argument_list|,
name|UMTX_UNOWNED
argument_list|)
operator|==
literal|0
condition|)
if|if
condition|(
name|_umtx_unlock
argument_list|(
name|umtx
argument_list|)
operator|==
operator|-
literal|1
condition|)
return|return
operator|(
name|errno
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|umtx_wait
parameter_list|(
name|u_long
modifier|*
name|p
parameter_list|,
name|long
name|val
parameter_list|,
specifier|const
name|struct
name|timespec
modifier|*
name|timeout
parameter_list|)
block|{
if|if
condition|(
name|_umtx_op
argument_list|(
name|p
argument_list|,
name|UMTX_OP_WAIT
argument_list|,
name|val
argument_list|,
literal|0
argument_list|,
name|__DECONST
argument_list|(
name|void
operator|*
argument_list|,
name|timeout
argument_list|)
argument_list|)
operator|==
operator|-
literal|1
condition|)
return|return
operator|(
name|errno
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Wake threads waiting on a user address. */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|umtx_wake
parameter_list|(
name|u_long
modifier|*
name|p
parameter_list|,
name|int
name|nr_wakeup
parameter_list|)
block|{
if|if
condition|(
name|_umtx_op
argument_list|(
name|p
argument_list|,
name|UMTX_OP_WAKE
argument_list|,
name|nr_wakeup
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|==
operator|-
literal|1
condition|)
return|return
operator|(
name|errno
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|umtx_q
modifier|*
name|umtxq_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|umtxq_free
parameter_list|(
name|struct
name|umtx_q
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kern_umtx_wake
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|umtx_pi_adjust
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|u_char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|umtx_thread_init
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|umtx_thread_fini
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|umtx_thread_alloc
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|umtx_thread_exit
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_UMTX_H_ */
end_comment

end_unit

