begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 New Gold Technology.  All rights reserved.  * Copyright (c) 2002 Juli Mallett.  All rights reserved.  *  * This software was written by Juli Mallett<jmallett@FreeBSD.org> for the  * FreeBSD project.  Redistribution and use in source and binary forms, with  * or without modification, are permitted provided that the following  * conditions are met:  *  * 1. Redistribution of source code must retain the above copyright notice,  *    this list of conditions and the following disclaimer.  * 2. Redistribution in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_KSIGINFO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_KSIGINFO_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_error
error|#
directive|error
literal|"no user-serviceable parts inside"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/signal.h>
end_include

begin_comment
comment|/*  * Structures and prototypes for working with the in-kernel representation  * of pending signals, and all the information we have about them.  */
end_comment

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_KSIGINFO
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * This is pushed to userland in the form of a siginfo_t, which is POSIX  * defined.  This is for in-kernel representations only, and has no ABI  * consumers.  */
end_comment

begin_struct
struct|struct
name|ksiginfo
block|{
name|TAILQ_ENTRY
argument_list|(
argument|ksiginfo
argument_list|)
name|ksi_queue
expr_stmt|;
comment|/* Entry in the signal queue. */
name|void
modifier|*
name|ksi_addr
decl_stmt|;
comment|/* [Fault] address. */
name|int
name|ksi_code
decl_stmt|;
comment|/* [Trap] code. */
name|int
name|ksi_errno
decl_stmt|;
comment|/* Error number. */
name|int
name|ksi_signo
decl_stmt|;
comment|/* Signal number. */
name|int
name|ksi_status
decl_stmt|;
comment|/* Exit status (SIGCHLD). */
name|uid_t
name|ksi_ruid
decl_stmt|;
comment|/* Real UID of sender. */
name|pid_t
name|ksi_pid
decl_stmt|;
comment|/* PID of sender. */
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_expr_stmt
name|__BEGIN_DECLS
expr_stmt|;
end_expr_stmt

begin_function_decl
name|int
name|ksiginfo_alloc
parameter_list|(
name|struct
name|ksiginfo
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ksiginfo_dequeue
parameter_list|(
name|struct
name|ksiginfo
modifier|*
modifier|*
parameter_list|,
name|struct
name|proc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ksiginfo_destroy
parameter_list|(
name|struct
name|ksiginfo
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ksiginfo_to_siginfo_t
parameter_list|(
name|struct
name|ksiginfo
modifier|*
parameter_list|,
name|siginfo_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ksiginfo_to_sigset_t
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|,
name|sigset_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|signal_add
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|,
name|struct
name|ksiginfo
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|signal_delete
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|,
name|struct
name|ksiginfo
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|signal_delete_mask
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|signal_pending
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|signal_queued
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|signal_queued_mask
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|,
name|sigset_t
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|__END_DECLS
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_KSIGINFO_H_ */
end_comment

end_unit

