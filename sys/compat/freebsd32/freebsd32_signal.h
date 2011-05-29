begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 David Xu<davidxu@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_COMPAT_FREEBSD32_SIGNAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_COMPAT_FREEBSD32_SIGNAL_H_
end_define

begin_struct
struct|struct
name|sigaltstack32
block|{
name|u_int32_t
name|ss_sp
decl_stmt|;
comment|/* signal stack base */
name|u_int32_t
name|ss_size
decl_stmt|;
comment|/* signal stack length */
name|int
name|ss_flags
decl_stmt|;
comment|/* SS_DISABLE and/or SS_ONSTACK */
block|}
struct|;
end_struct

begin_union
union|union
name|sigval32
block|{
name|int
name|sival_int
decl_stmt|;
name|u_int32_t
name|sival_ptr
decl_stmt|;
comment|/* 6.0 compatibility */
name|int
name|sigval_int
decl_stmt|;
name|u_int32_t
name|sigval_ptr
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|siginfo32
block|{
name|int
name|si_signo
decl_stmt|;
comment|/* signal number */
name|int
name|si_errno
decl_stmt|;
comment|/* errno association */
name|int
name|si_code
decl_stmt|;
comment|/* signal code */
name|int32_t
name|si_pid
decl_stmt|;
comment|/* sending process */
name|u_int32_t
name|si_uid
decl_stmt|;
comment|/* sender's ruid */
name|int
name|si_status
decl_stmt|;
comment|/* exit value */
name|u_int32_t
name|si_addr
decl_stmt|;
comment|/* faulting instruction */
name|union
name|sigval32
name|si_value
decl_stmt|;
comment|/* signal value */
union|union
block|{
struct|struct
block|{
name|int
name|_trapno
decl_stmt|;
comment|/* machine specific trap code */
block|}
name|_fault
struct|;
struct|struct
block|{
name|int
name|_timerid
decl_stmt|;
name|int
name|_overrun
decl_stmt|;
block|}
name|_timer
struct|;
struct|struct
block|{
name|int
name|_mqd
decl_stmt|;
block|}
name|_mesgq
struct|;
struct|struct
block|{
name|int
name|_band
decl_stmt|;
comment|/* band event for SIGPOLL */
block|}
name|_poll
struct|;
comment|/* was this ever used ? */
struct|struct
block|{
name|int
name|__spare1__
decl_stmt|;
name|int
name|__spare2__
index|[
literal|7
index|]
decl_stmt|;
block|}
name|__spare__
struct|;
block|}
name|_reason
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|osigevent32
block|{
name|int
name|sigev_notify
decl_stmt|;
comment|/* Notification type */
union|union
block|{
name|int
name|__sigev_signo
decl_stmt|;
comment|/* Signal number */
name|int
name|__sigev_notify_kqueue
decl_stmt|;
block|}
name|__sigev_u
union|;
name|union
name|sigval32
name|sigev_value
decl_stmt|;
comment|/* Signal value */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sigevent32
block|{
name|int
name|sigev_notify
decl_stmt|;
comment|/* Notification type */
name|int
name|sigev_signo
decl_stmt|;
comment|/* Signal number */
name|union
name|sigval32
name|sigev_value
decl_stmt|;
comment|/* Signal value */
union|union
block|{
name|__lwpid_t
name|_threadid
decl_stmt|;
struct|struct
block|{
name|uint32_t
name|_function
decl_stmt|;
name|uint32_t
name|_attribute
decl_stmt|;
block|}
name|_sigev_thread
struct|;
name|uint32_t
name|__spare__
index|[
literal|8
index|]
decl_stmt|;
block|}
name|_sigev_un
union|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|siginfo_to_siginfo32
parameter_list|(
specifier|const
name|siginfo_t
modifier|*
name|src
parameter_list|,
name|struct
name|siginfo32
modifier|*
name|dst
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_COMPAT_FREEBSD32_SIGNAL_H_ */
end_comment

end_unit

