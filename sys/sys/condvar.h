begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Jake Burkholder<jake@freebsd.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CONDVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_CONDVAR_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_struct_decl
struct_decl|struct
name|lock_object
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|cv_waitq
argument_list|,
name|thread
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Condition variable.  The waiters count is protected by the mutex that  * protects the condition; that is, the mutex that is passed to cv_wait*()  * and is held across calls to cv_signal() and cv_broadcast().  It is an  * optimization to avoid looking up the sleep queue if there are no waiters.  */
end_comment

begin_struct
struct|struct
name|cv
block|{
specifier|const
name|char
modifier|*
name|cv_description
decl_stmt|;
name|int
name|cv_waiters
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|void
name|cv_init
parameter_list|(
name|struct
name|cv
modifier|*
name|cvp
parameter_list|,
specifier|const
name|char
modifier|*
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cv_destroy
parameter_list|(
name|struct
name|cv
modifier|*
name|cvp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_cv_wait
parameter_list|(
name|struct
name|cv
modifier|*
name|cvp
parameter_list|,
name|struct
name|lock_object
modifier|*
name|lock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_cv_wait_unlock
parameter_list|(
name|struct
name|cv
modifier|*
name|cvp
parameter_list|,
name|struct
name|lock_object
modifier|*
name|lock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_cv_wait_sig
parameter_list|(
name|struct
name|cv
modifier|*
name|cvp
parameter_list|,
name|struct
name|lock_object
modifier|*
name|lock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_cv_timedwait
parameter_list|(
name|struct
name|cv
modifier|*
name|cvp
parameter_list|,
name|struct
name|lock_object
modifier|*
name|lock
parameter_list|,
name|int
name|timo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_cv_timedwait_sig
parameter_list|(
name|struct
name|cv
modifier|*
name|cvp
parameter_list|,
name|struct
name|lock_object
modifier|*
name|lock
parameter_list|,
name|int
name|timo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cv_signal
parameter_list|(
name|struct
name|cv
modifier|*
name|cvp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cv_broadcastpri
parameter_list|(
name|struct
name|cv
modifier|*
name|cvp
parameter_list|,
name|int
name|pri
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|cv_wait
parameter_list|(
name|cvp
parameter_list|,
name|lock
parameter_list|)
define|\
value|_cv_wait((cvp),&(lock)->lock_object)
end_define

begin_define
define|#
directive|define
name|cv_wait_unlock
parameter_list|(
name|cvp
parameter_list|,
name|lock
parameter_list|)
define|\
value|_cv_wait_unlock((cvp),&(lock)->lock_object)
end_define

begin_define
define|#
directive|define
name|cv_wait_sig
parameter_list|(
name|cvp
parameter_list|,
name|lock
parameter_list|)
define|\
value|_cv_wait_sig((cvp),&(lock)->lock_object)
end_define

begin_define
define|#
directive|define
name|cv_timedwait
parameter_list|(
name|cvp
parameter_list|,
name|lock
parameter_list|,
name|timo
parameter_list|)
define|\
value|_cv_timedwait((cvp),&(lock)->lock_object, (timo))
end_define

begin_define
define|#
directive|define
name|cv_timedwait_sig
parameter_list|(
name|cvp
parameter_list|,
name|lock
parameter_list|,
name|timo
parameter_list|)
define|\
value|_cv_timedwait_sig((cvp),&(lock)->lock_object, (timo))
end_define

begin_define
define|#
directive|define
name|cv_broadcast
parameter_list|(
name|cvp
parameter_list|)
value|cv_broadcastpri(cvp, -1)
end_define

begin_define
define|#
directive|define
name|cv_wmesg
parameter_list|(
name|cvp
parameter_list|)
value|((cvp)->cv_description)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_CONDVAR_H_ */
end_comment

end_unit

