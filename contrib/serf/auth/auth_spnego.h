begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright 2010 Justin Erenkrantz and Greg Stein  *  * Licensed under the Apache License, Version 2.0 (the "License");  * you may not use this file except in compliance with the License.  * You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AUTH_SPNEGO_H
end_ifndef

begin_define
define|#
directive|define
name|AUTH_SPNEGO_H
end_define

begin_include
include|#
directive|include
file|<apr.h>
end_include

begin_include
include|#
directive|include
file|<apr_pools.h>
end_include

begin_include
include|#
directive|include
file|"serf.h"
end_include

begin_include
include|#
directive|include
file|"serf_private.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SERF_HAVE_SSPI
argument_list|)
end_if

begin_define
define|#
directive|define
name|SERF_HAVE_SPNEGO
end_define

begin_define
define|#
directive|define
name|SERF_USE_SSPI
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SERF_HAVE_GSSAPI
argument_list|)
end_elif

begin_define
define|#
directive|define
name|SERF_HAVE_SPNEGO
end_define

begin_define
define|#
directive|define
name|SERF_USE_GSSAPI
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SERF_HAVE_SPNEGO
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
typedef|typedef
name|struct
name|serf__spnego_context_t
name|serf__spnego_context_t
typedef|;
typedef|typedef
struct|struct
name|serf__spnego_buffer_t
block|{
name|apr_size_t
name|length
decl_stmt|;
name|void
modifier|*
name|value
decl_stmt|;
block|}
name|serf__spnego_buffer_t
typedef|;
comment|/* Create outbound security context.  *  * All temporary allocations will be performed in SCRATCH_POOL, while security  * context will be allocated in result_pool and will be destroyed automatically  * on RESULT_POOL cleanup.  *  */
name|apr_status_t
name|serf__spnego_create_sec_context
parameter_list|(
name|serf__spnego_context_t
modifier|*
modifier|*
name|ctx_p
parameter_list|,
specifier|const
name|serf__authn_scheme_t
modifier|*
name|scheme
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
comment|/* Initialize outbound security context.  *  * The function is used to build a security context between the client  * application and a remote peer.  *  * CTX is pointer to existing context created using  * serf__spnego_create_sec_context() function.  *  * SERVICE is name of Kerberos service name. Usually 'HTTP'. HOSTNAME is  * canonical name of destination server. Caller should resolve server's alias  * to canonical name.  *  * INPUT_BUF is pointer structure describing input token if any. Should be  * zero length on first call.  *  * OUTPUT_BUF will be populated with pointer to output data that should send  * to destination server. This buffer will be automatically freed on  * RESULT_POOL cleanup.  *  * All temporary allocations will be performed in SCRATCH_POOL.  *  * Return value:  * - APR_EAGAIN The client must send the output token to the server and wait  *   for a return token.  *  * - APR_SUCCESS The security context was successfully initialized. There is no  *   need for another serf__spnego_init_sec_context call. If the function returns  *   an output token, that is, if the OUTPUT_BUF is of nonzero length, that  *   token must be sent to the server.  *  * Other returns values indicates error.  */
name|apr_status_t
name|serf__spnego_init_sec_context
parameter_list|(
name|serf_connection_t
modifier|*
name|conn
parameter_list|,
name|serf__spnego_context_t
modifier|*
name|ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|service
parameter_list|,
specifier|const
name|char
modifier|*
name|hostname
parameter_list|,
name|serf__spnego_buffer_t
modifier|*
name|input_buf
parameter_list|,
name|serf__spnego_buffer_t
modifier|*
name|output_buf
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
comment|/*  * Reset a previously created security context so we can start with a new one.  *  * This is triggered when the server requires per-request authentication,  * where each request requires a new security context.  */
name|apr_status_t
name|serf__spnego_reset_sec_context
parameter_list|(
name|serf__spnego_context_t
modifier|*
name|ctx
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SERF_HAVE_SPNEGO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !AUTH_SPNEGO_H */
end_comment

end_unit

