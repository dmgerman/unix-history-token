begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 David Xu<davidxu@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBPTHREAD_DB_H_
end_ifndef

begin_define
define|#
directive|define
name|_LIBPTHREAD_DB_H_
end_define

begin_include
include|#
directive|include
file|<sys/ucontext.h>
end_include

begin_include
include|#
directive|include
file|<machine/reg.h>
end_include

begin_include
include|#
directive|include
file|"thread_db_int.h"
end_include

begin_struct
struct|struct
name|pt_map
block|{
enum|enum
block|{
name|PT_NONE
block|,
name|PT_USER
block|,
name|PT_LWP
block|}
name|type
enum|;
union|union
block|{
name|lwpid_t
name|lwp
decl_stmt|;
name|psaddr_t
name|thr
decl_stmt|;
block|}
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|td_thragent
block|{
name|TD_THRAGENT_FIELDS
expr_stmt|;
name|psaddr_t
name|libkse_debug_addr
decl_stmt|;
name|psaddr_t
name|thread_list_addr
decl_stmt|;
name|psaddr_t
name|thread_listgen_addr
decl_stmt|;
name|psaddr_t
name|thread_activated_addr
decl_stmt|;
name|psaddr_t
name|thread_active_threads_addr
decl_stmt|;
name|psaddr_t
name|thread_keytable_addr
decl_stmt|;
name|int
name|thread_activated
decl_stmt|;
name|struct
name|pt_map
modifier|*
name|map
decl_stmt|;
name|int
name|map_len
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|pt_md_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pt_reg_to_ucontext
parameter_list|(
specifier|const
name|struct
name|reg
modifier|*
parameter_list|,
name|ucontext_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pt_ucontext_to_reg
parameter_list|(
specifier|const
name|ucontext_t
modifier|*
parameter_list|,
name|struct
name|reg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pt_fpreg_to_ucontext
parameter_list|(
specifier|const
name|struct
name|fpreg
modifier|*
parameter_list|,
name|ucontext_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pt_ucontext_to_fpreg
parameter_list|(
specifier|const
name|ucontext_t
modifier|*
parameter_list|,
name|struct
name|fpreg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pt_reg_sstep
parameter_list|(
name|struct
name|reg
modifier|*
name|reg
parameter_list|,
name|int
name|step
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LIBPTHREAD_DB_H_ */
end_comment

end_unit

