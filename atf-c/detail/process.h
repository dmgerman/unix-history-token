begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2008 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND  * CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE  * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN  * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ATF_C_DETAIL_PROCESS_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|ATF_C_DETAIL_PROCESS_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|<atf-c/detail/fs.h>
end_include

begin_include
include|#
directive|include
file|<atf-c/detail/list.h>
end_include

begin_include
include|#
directive|include
file|<atf-c/error_fwd.h>
end_include

begin_comment
comment|/* ---------------------------------------------------------------------  * The "atf_process_stream" type.  * --------------------------------------------------------------------- */
end_comment

begin_struct
struct|struct
name|atf_process_stream
block|{
name|int
name|m_type
decl_stmt|;
comment|/* Valid if m_type == connect. */
name|int
name|m_src_fd
decl_stmt|;
name|int
name|m_tgt_fd
decl_stmt|;
comment|/* Valid if m_type == redirect_fd. */
name|int
name|m_fd
decl_stmt|;
comment|/* Valid if m_type == redirect_path. */
specifier|const
name|atf_fs_path_t
modifier|*
name|m_path
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|atf_process_stream
name|atf_process_stream_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|atf_process_stream_type_capture
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|atf_process_stream_type_connect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|atf_process_stream_type_inherit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|atf_process_stream_type_redirect_fd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|atf_process_stream_type_redirect_path
decl_stmt|;
end_decl_stmt

begin_function_decl
name|atf_error_t
name|atf_process_stream_init_capture
parameter_list|(
name|atf_process_stream_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_error_t
name|atf_process_stream_init_connect
parameter_list|(
name|atf_process_stream_t
modifier|*
parameter_list|,
specifier|const
name|int
parameter_list|,
specifier|const
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_error_t
name|atf_process_stream_init_inherit
parameter_list|(
name|atf_process_stream_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_error_t
name|atf_process_stream_init_redirect_fd
parameter_list|(
name|atf_process_stream_t
modifier|*
parameter_list|,
specifier|const
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_error_t
name|atf_process_stream_init_redirect_path
parameter_list|(
name|atf_process_stream_t
modifier|*
parameter_list|,
specifier|const
name|atf_fs_path_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atf_process_stream_fini
parameter_list|(
name|atf_process_stream_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atf_process_stream_type
parameter_list|(
specifier|const
name|atf_process_stream_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ---------------------------------------------------------------------  * The "atf_process_status" type.  * --------------------------------------------------------------------- */
end_comment

begin_struct
struct|struct
name|atf_process_status
block|{
name|int
name|m_status
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|atf_process_status
name|atf_process_status_t
typedef|;
end_typedef

begin_function_decl
name|void
name|atf_process_status_fini
parameter_list|(
name|atf_process_status_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|atf_process_status_exited
parameter_list|(
specifier|const
name|atf_process_status_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atf_process_status_exitstatus
parameter_list|(
specifier|const
name|atf_process_status_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|atf_process_status_signaled
parameter_list|(
specifier|const
name|atf_process_status_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atf_process_status_termsig
parameter_list|(
specifier|const
name|atf_process_status_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|atf_process_status_coredump
parameter_list|(
specifier|const
name|atf_process_status_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ---------------------------------------------------------------------  * The "atf_process_child" type.  * --------------------------------------------------------------------- */
end_comment

begin_struct
struct|struct
name|atf_process_child
block|{
name|pid_t
name|m_pid
decl_stmt|;
name|int
name|m_stdout
decl_stmt|;
name|int
name|m_stderr
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|atf_process_child
name|atf_process_child_t
typedef|;
end_typedef

begin_function_decl
name|atf_error_t
name|atf_process_child_wait
parameter_list|(
name|atf_process_child_t
modifier|*
parameter_list|,
name|atf_process_status_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pid_t
name|atf_process_child_pid
parameter_list|(
specifier|const
name|atf_process_child_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atf_process_child_stdout
parameter_list|(
name|atf_process_child_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atf_process_child_stderr
parameter_list|(
name|atf_process_child_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ---------------------------------------------------------------------  * Free functions.  * --------------------------------------------------------------------- */
end_comment

begin_function_decl
name|atf_error_t
name|atf_process_fork
parameter_list|(
name|atf_process_child_t
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
specifier|const
name|atf_process_stream_t
modifier|*
parameter_list|,
specifier|const
name|atf_process_stream_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_error_t
name|atf_process_exec_array
parameter_list|(
name|atf_process_status_t
modifier|*
parameter_list|,
specifier|const
name|atf_fs_path_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
specifier|const
modifier|*
parameter_list|,
specifier|const
name|atf_process_stream_t
modifier|*
parameter_list|,
specifier|const
name|atf_process_stream_t
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_error_t
name|atf_process_exec_list
parameter_list|(
name|atf_process_status_t
modifier|*
parameter_list|,
specifier|const
name|atf_fs_path_t
modifier|*
parameter_list|,
specifier|const
name|atf_list_t
modifier|*
parameter_list|,
specifier|const
name|atf_process_stream_t
modifier|*
parameter_list|,
specifier|const
name|atf_process_stream_t
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(ATF_C_DETAIL_PROCESS_H) */
end_comment

end_unit

