begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001, 2003 Daniel Eischen<deischen@freebsd.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LOCK_H_
end_ifndef

begin_define
define|#
directive|define
name|_LOCK_H_
end_define

begin_struct_decl
struct_decl|struct
name|lockreq
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|lockuser
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|lock
struct_decl|;
end_struct_decl

begin_enum
enum|enum
name|lock_type
block|{
name|LCK_DEFAULT
init|=
literal|0x0000
block|,
comment|/* default is FIFO spin locks */
name|LCK_PRIORITY
init|=
literal|0x0001
block|,
name|LCK_ADAPTIVE
init|=
literal|0x0002
comment|/* call user-supplied handlers */
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|void
name|lock_handler_t
parameter_list|(
name|struct
name|lock
modifier|*
parameter_list|,
name|struct
name|lockuser
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|lock
block|{
name|struct
name|lockreq
modifier|*
name|l_head
decl_stmt|;
name|struct
name|lockreq
modifier|*
name|l_tail
decl_stmt|;
comment|/* only used for priority locks */
name|enum
name|lock_type
name|l_type
decl_stmt|;
name|lock_handler_t
modifier|*
name|l_wait
decl_stmt|;
comment|/* only used for adaptive locks */
name|lock_handler_t
modifier|*
name|l_wakeup
decl_stmt|;
comment|/* only used for adaptive locks */
block|}
struct|;
end_struct

begin_comment
comment|/* Try to make this>= CACHELINESIZE */
end_comment

begin_struct
struct|struct
name|lockreq
block|{
name|struct
name|lockuser
modifier|*
name|lr_watcher
decl_stmt|;
comment|/* only used for priority locks */
name|struct
name|lockuser
modifier|*
name|lr_owner
decl_stmt|;
comment|/* only used for priority locks */
specifier|volatile
name|int
name|lr_locked
decl_stmt|;
comment|/* lock granted = 0, busy otherwise */
specifier|volatile
name|int
name|lr_active
decl_stmt|;
comment|/* non-zero if the lock is last lock for thread */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lockuser
block|{
name|struct
name|lockreq
modifier|*
name|lu_myreq
decl_stmt|;
comment|/* request to give up/trade */
name|struct
name|lockreq
modifier|*
name|lu_watchreq
decl_stmt|;
comment|/* watch this request */
name|int
name|lu_priority
decl_stmt|;
comment|/* only used for priority locks */
name|void
modifier|*
name|lu_private1
decl_stmt|;
comment|/* private{1,2} are initialized to */
name|void
modifier|*
name|lu_private2
decl_stmt|;
comment|/*   NULL and can be used by caller */
define|#
directive|define
name|lu_private
value|lu_private1
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|_LCK_INITIALIZER
parameter_list|(
name|lck_req
parameter_list|)
value|{&lck_req, NULL, LCK_DEFAULT, \ 					  NULL, NULL }
end_define

begin_define
define|#
directive|define
name|_LCK_REQUEST_INITIALIZER
value|{ 0, NULL, NULL, 0 }
end_define

begin_define
define|#
directive|define
name|_LCK_BUSY
parameter_list|(
name|lu
parameter_list|)
value|((lu)->lu_watchreq->lr_locked != 0)
end_define

begin_define
define|#
directive|define
name|_LCK_ACTIVE
parameter_list|(
name|lu
parameter_list|)
value|((lu)->lu_watchreq->lr_active != 0)
end_define

begin_define
define|#
directive|define
name|_LCK_GRANTED
parameter_list|(
name|lu
parameter_list|)
value|((lu)->lu_watchreq->lr_locked == 3)
end_define

begin_define
define|#
directive|define
name|_LCK_SET_PRIVATE
parameter_list|(
name|lu
parameter_list|,
name|p
parameter_list|)
value|(lu)->lu_private = (void *)(p)
end_define

begin_define
define|#
directive|define
name|_LCK_GET_PRIVATE
parameter_list|(
name|lu
parameter_list|)
value|(lu)->lu_private
end_define

begin_define
define|#
directive|define
name|_LCK_SET_PRIVATE2
parameter_list|(
name|lu
parameter_list|,
name|p
parameter_list|)
value|(lu)->lu_private2 = (void *)(p)
end_define

begin_define
define|#
directive|define
name|_LCK_GET_PRIVATE2
parameter_list|(
name|lu
parameter_list|)
value|(lu)->lu_private2
end_define

begin_function_decl
name|void
name|_lock_destroy
parameter_list|(
name|struct
name|lock
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_lock_init
parameter_list|(
name|struct
name|lock
modifier|*
parameter_list|,
name|enum
name|lock_type
parameter_list|,
name|lock_handler_t
modifier|*
parameter_list|,
name|lock_handler_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_lockuser_init
parameter_list|(
name|struct
name|lockuser
modifier|*
name|lu
parameter_list|,
name|void
modifier|*
name|priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_lockuser_destroy
parameter_list|(
name|struct
name|lockuser
modifier|*
name|lu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_lockuser_setactive
parameter_list|(
name|struct
name|lockuser
modifier|*
name|lu
parameter_list|,
name|int
name|active
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_lock_acquire
parameter_list|(
name|struct
name|lock
modifier|*
parameter_list|,
name|struct
name|lockuser
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_lock_release
parameter_list|(
name|struct
name|lock
modifier|*
parameter_list|,
name|struct
name|lockuser
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_lock_grant
parameter_list|(
name|struct
name|lock
modifier|*
parameter_list|,
name|struct
name|lockuser
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

