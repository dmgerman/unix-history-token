begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Adrian Chadd<adrian@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SF_SYNC_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SF_SYNC_H_
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|SF_STATE_NONE
block|,
name|SF_STATE_SETUP
block|,
name|SF_STATE_RUNNING
block|,
name|SF_STATE_COMPLETED
block|,
name|SF_STATE_FREEING
block|}
name|sendfile_sync_state_t
typedef|;
end_typedef

begin_struct
struct|struct
name|sendfile_sync
block|{
name|struct
name|mtx
name|mtx
decl_stmt|;
name|struct
name|cv
name|cv
decl_stmt|;
name|struct
name|knlist
name|klist
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|count
decl_stmt|;
name|int32_t
name|xerrno
decl_stmt|;
comment|/* Completion errno, if retval< 0 */
name|off_t
name|retval
decl_stmt|;
comment|/* Completion retval (eg written bytes) */
name|sendfile_sync_state_t
name|state
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* XXX pollution */
end_comment

begin_struct_decl
struct_decl|struct
name|sf_hdtr_kq
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|struct
name|sendfile_sync
modifier|*
name|sf_sync_alloc
parameter_list|(
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sf_sync_syscall_wait
parameter_list|(
name|struct
name|sendfile_sync
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sf_sync_free
parameter_list|(
name|struct
name|sendfile_sync
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sf_sync_try_free
parameter_list|(
name|struct
name|sendfile_sync
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sf_sync_ref
parameter_list|(
name|struct
name|sendfile_sync
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sf_sync_deref
parameter_list|(
name|struct
name|sendfile_sync
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sf_sync_kqueue_setup
parameter_list|(
name|struct
name|sendfile_sync
modifier|*
parameter_list|,
name|struct
name|sf_hdtr_kq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sf_sync_set_state
parameter_list|(
name|struct
name|sendfile_sync
modifier|*
parameter_list|,
name|sendfile_sync_state_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sf_sync_set_retval
parameter_list|(
name|struct
name|sendfile_sync
modifier|*
parameter_list|,
name|off_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SF_BUF_H_ */
end_comment

end_unit

