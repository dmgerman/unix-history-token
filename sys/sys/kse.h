begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2001 Julian Elischer<julian@freebsd.org>  * for the FreeBSD Foundation.  *  *  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice(s), this list of conditions and the following disclaimer as  *    the first lines of this file unmodified other than the possible   *    addition of one or more copyright notices.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice(s), this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER(S) ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER(S) BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_KSE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_KSE_H_
end_define

begin_include
include|#
directive|include
file|<machine/kse.h>
end_include

begin_include
include|#
directive|include
file|<sys/ucontext.h>
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

begin_comment
comment|/*  * This file defines the structures needed for communication between  * the userland and the kernel when running a KSE-based threading system.  * The only programs that should see this file are the user thread  * scheduler (UTS) and the kernel.  */
end_comment

begin_struct_decl
struct_decl|struct
name|kse_mailbox
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
name|kse_func_t
parameter_list|(
name|struct
name|kse_mailbox
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Thread mailbox.  *  * This describes a user thread to the kernel scheduler.  */
end_comment

begin_struct
struct|struct
name|kse_thr_mailbox
block|{
name|ucontext_t
name|tm_context
decl_stmt|;
comment|/* User and machine context */
name|unsigned
name|int
name|tm_flags
decl_stmt|;
comment|/* Thread flags */
name|struct
name|kse_thr_mailbox
modifier|*
name|tm_next
decl_stmt|;
comment|/* Next thread in list */
name|void
modifier|*
name|tm_udata
decl_stmt|;
comment|/* For use by the UTS */
name|uint32_t
name|tm_uticks
decl_stmt|;
name|uint32_t
name|tm_sticks
decl_stmt|;
name|siginfo_t
name|tm_syncsig
decl_stmt|;
name|int
name|tm_spare
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * KSE mailbox.  *  * Communication path between the UTS and the kernel scheduler specific to  * a single KSE.  */
end_comment

begin_struct
struct|struct
name|kse_mailbox
block|{
name|int
name|km_version
decl_stmt|;
comment|/* Mailbox version */
name|struct
name|kse_thr_mailbox
modifier|*
name|km_curthread
decl_stmt|;
comment|/* Currently running thread */
name|struct
name|kse_thr_mailbox
modifier|*
name|km_completed
decl_stmt|;
comment|/* Threads back from kernel */
name|sigset_t
name|km_sigscaught
decl_stmt|;
comment|/* Caught signals */
name|uint32_t
name|km_flags
decl_stmt|;
comment|/* KSE flags */
name|kse_func_t
modifier|*
name|km_func
decl_stmt|;
comment|/* UTS function */
name|stack_t
name|km_stack
decl_stmt|;
comment|/* UTS context */
name|void
modifier|*
name|km_udata
decl_stmt|;
comment|/* For use by the UTS */
name|struct
name|timespec
name|km_timeofday
decl_stmt|;
comment|/* Time of day */
name|int
name|km_quantum
decl_stmt|;
comment|/* Upcall quantum in msecs */
name|int
name|km_spare
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KSE_VER_0
value|0
end_define

begin_define
define|#
directive|define
name|KSE_VERSION
value|KSE_VER_0
end_define

begin_comment
comment|/* These flags are kept in km_flags */
end_comment

begin_define
define|#
directive|define
name|KMF_NOUPCALL
value|0x01
end_define

begin_define
define|#
directive|define
name|KMF_NOCOMPLETED
value|0x02
end_define

begin_define
define|#
directive|define
name|KMF_DONE
value|0x04
end_define

begin_define
define|#
directive|define
name|KMF_BOUND
value|0x08
end_define

begin_define
define|#
directive|define
name|KMF_WAITSIGEVENT
value|0x10
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_function_decl
name|int
name|kse_create
parameter_list|(
name|struct
name|kse_mailbox
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kse_exit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kse_release
parameter_list|(
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kse_thr_interrupt
parameter_list|(
name|struct
name|kse_thr_mailbox
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kse_wakeup
parameter_list|(
name|struct
name|kse_mailbox
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
comment|/* !_SYS_KSE_H_ */
end_comment

end_unit

