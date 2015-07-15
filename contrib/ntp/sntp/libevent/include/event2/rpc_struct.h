begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2006-2007 Niels Provos<provos@citi.umich.edu>  * Copyright (c) 2007-2012 Niels Provos and Nick Mathewson  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EVENT2_RPC_STRUCT_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|EVENT2_RPC_STRUCT_H_INCLUDED_
end_define

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
comment|/** @file event2/rpc_struct.h    Structures used by rpc.h.  Using these structures directly may harm   forward compatibility: be careful!   */
comment|/**  * provides information about the completed RPC request.  */
struct|struct
name|evrpc_status
block|{
define|#
directive|define
name|EVRPC_STATUS_ERR_NONE
value|0
define|#
directive|define
name|EVRPC_STATUS_ERR_TIMEOUT
value|1
define|#
directive|define
name|EVRPC_STATUS_ERR_BADPAYLOAD
value|2
define|#
directive|define
name|EVRPC_STATUS_ERR_UNSTARTED
value|3
define|#
directive|define
name|EVRPC_STATUS_ERR_HOOKABORTED
value|4
name|int
name|error
decl_stmt|;
comment|/* for looking at headers or other information */
name|struct
name|evhttp_request
modifier|*
name|http_req
decl_stmt|;
block|}
struct|;
comment|/* the structure below needs to be synchronized with evrpc_req_generic */
comment|/* Encapsulates a request */
struct|struct
name|evrpc
block|{
name|TAILQ_ENTRY
argument_list|(
argument|evrpc
argument_list|)
name|next
expr_stmt|;
comment|/* the URI at which the request handler lives */
specifier|const
name|char
modifier|*
name|uri
decl_stmt|;
comment|/* creates a new request structure */
name|void
modifier|*
function_decl|(
modifier|*
name|request_new
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|request_new_arg
decl_stmt|;
comment|/* frees the request structure */
name|void
function_decl|(
modifier|*
name|request_free
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* unmarshals the buffer into the proper request structure */
name|int
function_decl|(
modifier|*
name|request_unmarshal
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|evbuffer
modifier|*
parameter_list|)
function_decl|;
comment|/* creates a new reply structure */
name|void
modifier|*
function_decl|(
modifier|*
name|reply_new
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|reply_new_arg
decl_stmt|;
comment|/* frees the reply structure */
name|void
function_decl|(
modifier|*
name|reply_free
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* verifies that the reply is valid */
name|int
function_decl|(
modifier|*
name|reply_complete
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* marshals the reply into a buffer */
name|void
function_decl|(
modifier|*
name|reply_marshal
function_decl|)
parameter_list|(
name|struct
name|evbuffer
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* the callback invoked for each received rpc */
name|void
function_decl|(
modifier|*
name|cb
function_decl|)
parameter_list|(
name|struct
name|evrpc_req_generic
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|cb_arg
decl_stmt|;
comment|/* reference for further configuration */
name|struct
name|evrpc_base
modifier|*
name|base
decl_stmt|;
block|}
struct|;
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
comment|/* EVENT2_RPC_STRUCT_H_INCLUDED_ */
end_comment

end_unit

