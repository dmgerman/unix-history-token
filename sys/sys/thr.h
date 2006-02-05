begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003, Jeffrey Roberson<jeff@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_THR_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_THR_H_
end_define

begin_comment
comment|/* Create the thread in the suspended state. */
end_comment

begin_define
define|#
directive|define
name|THR_SUSPENDED
value|0x0001
end_define

begin_comment
comment|/* Create the system scope thread. */
end_comment

begin_define
define|#
directive|define
name|THR_SYSTEM_SCOPE
value|0x0002
end_define

begin_struct
struct|struct
name|thr_param
block|{
name|void
function_decl|(
modifier|*
name|start_func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* thread entry function. */
name|void
modifier|*
name|arg
decl_stmt|;
comment|/* argument for entry function. */
name|char
modifier|*
name|stack_base
decl_stmt|;
comment|/* stack base address. */
name|size_t
name|stack_size
decl_stmt|;
comment|/* stack size. */
name|char
modifier|*
name|tls_base
decl_stmt|;
comment|/* tls base address. */
name|size_t
name|tls_size
decl_stmt|;
comment|/* tls size. */
name|long
modifier|*
name|child_tid
decl_stmt|;
comment|/* address to store new TID. */
name|long
modifier|*
name|parent_tid
decl_stmt|;
comment|/* parent accesses the new TID here. */
name|int
name|flags
decl_stmt|;
comment|/* thread flags. */
name|void
modifier|*
name|spare
index|[
literal|4
index|]
decl_stmt|;
comment|/* TODO: cpu affinity mask etc. */
block|}
struct|;
end_struct

begin_comment
comment|/*   * See pthread_*  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_function_decl
name|int
name|thr_create
parameter_list|(
name|ucontext_t
modifier|*
name|ctx
parameter_list|,
name|long
modifier|*
name|id
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|thr_new
parameter_list|(
name|struct
name|thr_param
modifier|*
name|param
parameter_list|,
name|int
name|param_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|thr_self
parameter_list|(
name|long
modifier|*
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|thr_exit
parameter_list|(
name|long
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|thr_kill
parameter_list|(
name|long
name|id
parameter_list|,
name|int
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|thr_suspend
parameter_list|(
specifier|const
name|struct
name|timespec
modifier|*
name|timeout
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|thr_wake
parameter_list|(
name|long
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|thr_set_name
parameter_list|(
name|long
name|id
parameter_list|,
specifier|const
name|char
modifier|*
name|name
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
comment|/* ! _SYS_THR_H_ */
end_comment

end_unit

