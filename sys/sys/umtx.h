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
name|UMTX_OP_RESERVED0
value|0
end_define

begin_define
define|#
directive|define
name|UMTX_OP_RESERVED1
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

begin_comment
comment|/* deprecated */
end_comment

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
name|UMTX_OP_NWAKE_PRIVATE
value|21
end_define

begin_define
define|#
directive|define
name|UMTX_OP_MUTEX_WAKE2
value|22
end_define

begin_define
define|#
directive|define
name|UMTX_OP_MAX
value|23
end_define

begin_comment
comment|/* Flags for UMTX_OP_CV_WAIT */
end_comment

begin_define
define|#
directive|define
name|CVWAIT_CHECK_UNPARKING
value|0x01
end_define

begin_define
define|#
directive|define
name|CVWAIT_ABSTIME
value|0x02
end_define

begin_define
define|#
directive|define
name|CVWAIT_CLOCKID
value|0x04
end_define

begin_define
define|#
directive|define
name|UMTX_ABSTIME
value|0x01
end_define

begin_define
define|#
directive|define
name|UMTX_CHECK_UNPARKING
value|CVWAIT_CHECK_UNPARKING
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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * The umtx_key structure is used by both the Linux futex code and the  * umtx implementation to map userland addresses to unique keys.  */
end_comment

begin_enum
enum|enum
block|{
name|TYPE_SIMPLE_WAIT
block|,
name|TYPE_CV
block|,
name|TYPE_SEM
block|,
name|TYPE_SIMPLE_LOCK
block|,
name|TYPE_NORMAL_UMUTEX
block|,
name|TYPE_PI_UMUTEX
block|,
name|TYPE_PP_UMUTEX
block|,
name|TYPE_RWLOCK
block|,
name|TYPE_FUTEX
block|}
enum|;
end_enum

begin_comment
comment|/* Key to represent a unique userland synchronous object */
end_comment

begin_struct
struct|struct
name|umtx_key
block|{
name|int
name|hash
decl_stmt|;
name|int
name|type
decl_stmt|;
name|int
name|shared
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|struct
name|vm_object
modifier|*
name|object
decl_stmt|;
name|uintptr_t
name|offset
decl_stmt|;
block|}
name|shared
struct|;
struct|struct
block|{
name|struct
name|vmspace
modifier|*
name|vs
decl_stmt|;
name|uintptr_t
name|addr
decl_stmt|;
block|}
name|private
struct|;
struct|struct
block|{
name|void
modifier|*
name|a
decl_stmt|;
name|uintptr_t
name|b
decl_stmt|;
block|}
name|both
struct|;
block|}
name|info
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|THREAD_SHARE
value|0
end_define

begin_define
define|#
directive|define
name|PROCESS_SHARE
value|1
end_define

begin_define
define|#
directive|define
name|AUTO_SHARE
value|2
end_define

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_function
specifier|static
specifier|inline
name|int
name|umtx_key_match
parameter_list|(
specifier|const
name|struct
name|umtx_key
modifier|*
name|k1
parameter_list|,
specifier|const
name|struct
name|umtx_key
modifier|*
name|k2
parameter_list|)
block|{
return|return
operator|(
name|k1
operator|->
name|type
operator|==
name|k2
operator|->
name|type
operator|&&
name|k1
operator|->
name|info
operator|.
name|both
operator|.
name|a
operator|==
name|k2
operator|->
name|info
operator|.
name|both
operator|.
name|a
operator|&&
name|k1
operator|->
name|info
operator|.
name|both
operator|.
name|b
operator|==
name|k2
operator|->
name|info
operator|.
name|both
operator|.
name|b
operator|)
return|;
block|}
end_function

begin_function_decl
name|int
name|umtx_copyin_timeout
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|umtx_key_get
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|umtx_key
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|umtx_key_release
parameter_list|(
name|struct
name|umtx_key
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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

