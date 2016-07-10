begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Roman Divacky  * Copyright (c) 2013 Dmitry Chagin  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_EMUL_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_EMUL_H_
end_define

begin_comment
comment|/*  * modeled after similar structure in NetBSD  * this will be extended as we need more functionality  */
end_comment

begin_struct
struct|struct
name|linux_emuldata
block|{
name|int
modifier|*
name|child_set_tid
decl_stmt|;
comment|/* in clone(): Child's TID to set on clone */
name|int
modifier|*
name|child_clear_tid
decl_stmt|;
comment|/* in clone(): Child's TID to clear on exit */
name|int
name|pdeath_signal
decl_stmt|;
comment|/* parent death signal */
name|int
name|flags
decl_stmt|;
comment|/* thread emuldata flags */
name|int
name|em_tid
decl_stmt|;
comment|/* thread id */
name|struct
name|linux_robust_list_head
modifier|*
name|robust_futexes
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|linux_emuldata
modifier|*
name|em_find
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|linux_proc_init
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|linux_proc_exit
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|linux_schedtail
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|linux_proc_exec
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|proc
modifier|*
parameter_list|,
name|struct
name|image_params
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|linux_thread_dtor
parameter_list|(
name|void
modifier|*
name|arg
name|__unused
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|linux_thread_detach
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_common_execve
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|image_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* process emuldata flags */
end_comment

begin_define
define|#
directive|define
name|LINUX_XDEPR_REQUEUEOP
value|0x00000001
end_define

begin_comment
comment|/* uses deprecated 						   futex REQUEUE op*/
end_comment

begin_define
define|#
directive|define
name|LINUX_XUNSUP_EPOLL
value|0x00000002
end_define

begin_comment
comment|/* unsupported epoll events */
end_comment

begin_define
define|#
directive|define
name|LINUX_XUNSUP_FUTEXPIOP
value|0x00000004
end_define

begin_comment
comment|/* uses unsupported pi futex */
end_comment

begin_struct
struct|struct
name|linux_pemuldata
block|{
name|uint32_t
name|flags
decl_stmt|;
comment|/* process emuldata flags */
name|struct
name|sx
name|pem_sx
decl_stmt|;
comment|/* lock for this struct */
name|void
modifier|*
name|epoll
decl_stmt|;
comment|/* epoll data */
name|uint32_t
name|persona
decl_stmt|;
comment|/* process execution domain */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LINUX_PEM_XLOCK
parameter_list|(
name|p
parameter_list|)
value|sx_xlock(&(p)->pem_sx)
end_define

begin_define
define|#
directive|define
name|LINUX_PEM_XUNLOCK
parameter_list|(
name|p
parameter_list|)
value|sx_xunlock(&(p)->pem_sx)
end_define

begin_define
define|#
directive|define
name|LINUX_PEM_SLOCK
parameter_list|(
name|p
parameter_list|)
value|sx_slock(&(p)->pem_sx)
end_define

begin_define
define|#
directive|define
name|LINUX_PEM_SUNLOCK
parameter_list|(
name|p
parameter_list|)
value|sx_sunlock(&(p)->pem_sx)
end_define

begin_function_decl
name|struct
name|linux_pemuldata
modifier|*
name|pem_find
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_LINUX_EMUL_H_ */
end_comment

end_unit

