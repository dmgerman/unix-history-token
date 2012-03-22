begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2009 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Portions Copyright (c) 2009 Apple Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<asn1-common.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|heim_ipc
modifier|*
name|heim_ipc
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|heim_sipc
modifier|*
name|heim_sipc
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|heim_icred
modifier|*
name|heim_icred
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|heim_isemaphore
modifier|*
name|heim_isemaphore
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|heim_octet_string
name|heim_idata
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|heim_sipc_call
modifier|*
name|heim_sipc_call
typedef|;
end_typedef

begin_comment
comment|/* common */
end_comment

begin_function_decl
name|void
name|heim_ipc_free_cred
parameter_list|(
name|heim_icred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uid_t
name|heim_ipc_cred_get_uid
parameter_list|(
name|heim_icred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|gid_t
name|heim_ipc_cred_get_gid
parameter_list|(
name|heim_icred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pid_t
name|heim_ipc_cred_get_pid
parameter_list|(
name|heim_icred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pid_t
name|heim_ipc_cred_get_session
parameter_list|(
name|heim_icred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|heim_ipc_main
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|heim_isemaphore
name|heim_ipc_semaphore_create
parameter_list|(
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|heim_ipc_semaphore_wait
parameter_list|(
name|heim_isemaphore
parameter_list|,
name|time_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|heim_ipc_semaphore_signal
parameter_list|(
name|heim_isemaphore
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|heim_ipc_semaphore_release
parameter_list|(
name|heim_isemaphore
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|HEIM_IPC_WAIT_FOREVER
value|((time_t)-1)
end_define

begin_function_decl
name|void
name|heim_ipc_free_data
parameter_list|(
name|heim_idata
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* client */
end_comment

begin_function_decl
name|int
name|heim_ipc_init_context
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|heim_ipc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|heim_ipc_free_context
parameter_list|(
name|heim_ipc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|heim_ipc_call
parameter_list|(
name|heim_ipc
parameter_list|,
specifier|const
name|heim_idata
modifier|*
parameter_list|,
name|heim_idata
modifier|*
parameter_list|,
name|heim_icred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|heim_ipc_async
parameter_list|(
name|heim_ipc
parameter_list|,
specifier|const
name|heim_idata
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|heim_idata
modifier|*
parameter_list|,
name|heim_icred
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* server */
end_comment

begin_define
define|#
directive|define
name|HEIM_SIPC_TYPE_IPC
value|1
end_define

begin_define
define|#
directive|define
name|HEIM_SIPC_TYPE_UINT32
value|2
end_define

begin_define
define|#
directive|define
name|HEIM_SIPC_TYPE_HTTP
value|4
end_define

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|heim_ipc_complete
function_decl|)
parameter_list|(
name|heim_sipc_call
parameter_list|,
name|int
parameter_list|,
name|heim_idata
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|heim_ipc_callback
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|heim_idata
modifier|*
parameter_list|,
specifier|const
name|heim_icred
parameter_list|,
name|heim_ipc_complete
parameter_list|,
name|heim_sipc_call
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|int
name|heim_sipc_launchd_mach_init
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|heim_ipc_callback
parameter_list|,
name|void
modifier|*
parameter_list|,
name|heim_sipc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|heim_sipc_stream_listener
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|heim_ipc_callback
parameter_list|,
name|void
modifier|*
parameter_list|,
name|heim_sipc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|heim_sipc_service_unix
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|heim_ipc_callback
parameter_list|,
name|void
modifier|*
parameter_list|,
name|heim_sipc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|heim_sipc_timeout
parameter_list|(
name|time_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|heim_sipc_set_timeout_handler
parameter_list|(
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
name|void
name|heim_sipc_free_context
parameter_list|(
name|heim_sipc
parameter_list|)
function_decl|;
end_function_decl

end_unit

