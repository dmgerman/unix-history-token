begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2006-2007 Niels Provos<provos@citi.umich.edu>  * Copyright (c) 2007-2012 Niels Provos and Nick Mathewson  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EVRPC_INTERNAL_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|EVRPC_INTERNAL_H_INCLUDED_
end_define

begin_include
include|#
directive|include
file|"http-internal.h"
end_include

begin_struct_decl
struct_decl|struct
name|evrpc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|evrpc_request_wrapper
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|EVRPC_URI_PREFIX
value|"/.rpc."
end_define

begin_struct
struct|struct
name|evrpc_hook
block|{
name|TAILQ_ENTRY
argument_list|(
argument|evrpc_hook
argument_list|)
name|next
expr_stmt|;
comment|/* returns EVRPC_TERMINATE; if the rpc should be aborted. 	 * a hook is is allowed to rewrite the evbuffer 	 */
name|int
function_decl|(
modifier|*
name|process
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|evhttp_request
modifier|*
parameter_list|,
name|struct
name|evbuffer
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|process_arg
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|evrpc_hook_list
argument_list|,
name|evrpc_hook
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * this is shared between the base and the pool, so that we can reuse  * the hook adding functions; we alias both evrpc_pool and evrpc_base  * to this common structure.  */
end_comment

begin_struct_decl
struct_decl|struct
name|evrpc_hook_ctx
struct_decl|;
end_struct_decl

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|evrpc_pause_list
argument_list|,
name|evrpc_hook_ctx
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|evrpc_hooks_
block|{
comment|/* hooks for processing outbound and inbound rpcs */
name|struct
name|evrpc_hook_list
name|in_hooks
decl_stmt|;
name|struct
name|evrpc_hook_list
name|out_hooks
decl_stmt|;
name|struct
name|evrpc_pause_list
name|pause_requests
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|input_hooks
value|common.in_hooks
end_define

begin_define
define|#
directive|define
name|output_hooks
value|common.out_hooks
end_define

begin_define
define|#
directive|define
name|paused_requests
value|common.pause_requests
end_define

begin_struct
struct|struct
name|evrpc_base
block|{
name|struct
name|evrpc_hooks_
name|common
decl_stmt|;
comment|/* the HTTP server under which we register our RPC calls */
name|struct
name|evhttp
modifier|*
name|http_server
decl_stmt|;
comment|/* a list of all RPCs registered with us */
name|TAILQ_HEAD
argument_list|(
argument|evrpc_list
argument_list|,
argument|evrpc
argument_list|)
name|registered_rpcs
expr_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|evrpc_req_generic
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|evrpc_reqstate_free_
parameter_list|(
name|struct
name|evrpc_req_generic
modifier|*
name|rpc_state
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* A pool for holding evhttp_connection objects */
end_comment

begin_struct
struct|struct
name|evrpc_pool
block|{
name|struct
name|evrpc_hooks_
name|common
decl_stmt|;
name|struct
name|event_base
modifier|*
name|base
decl_stmt|;
name|struct
name|evconq
name|connections
decl_stmt|;
name|int
name|timeout
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
name|evrpc_requestq
argument_list|,
name|evrpc_request_wrapper
argument_list|)
argument_list|(
name|requests
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|evrpc_hook_ctx
block|{
name|TAILQ_ENTRY
argument_list|(
argument|evrpc_hook_ctx
argument_list|)
name|next
expr_stmt|;
name|void
modifier|*
name|ctx
decl_stmt|;
name|void
function_decl|(
modifier|*
name|cb
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|enum
name|EVRPC_HOOK_RESULT
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|evrpc_meta
block|{
name|TAILQ_ENTRY
argument_list|(
argument|evrpc_meta
argument_list|)
name|next
expr_stmt|;
name|char
modifier|*
name|key
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
name|size_t
name|data_size
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|evrpc_meta_list
argument_list|,
name|evrpc_meta
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|evrpc_hook_meta
block|{
name|struct
name|evrpc_meta_list
name|meta_data
decl_stmt|;
name|struct
name|evhttp_connection
modifier|*
name|evcon
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* allows association of meta data with a request */
end_comment

begin_function_decl
specifier|static
name|void
name|evrpc_hook_associate_meta_
parameter_list|(
name|struct
name|evrpc_hook_meta
modifier|*
modifier|*
name|pctx
parameter_list|,
name|struct
name|evhttp_connection
modifier|*
name|evcon
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* creates a new meta data store */
end_comment

begin_function_decl
specifier|static
name|struct
name|evrpc_hook_meta
modifier|*
name|evrpc_hook_meta_new_
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* frees the meta data associated with a request */
end_comment

begin_function_decl
specifier|static
name|void
name|evrpc_hook_context_free_
parameter_list|(
name|struct
name|evrpc_hook_meta
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* the server side of an rpc */
end_comment

begin_comment
comment|/* We alias the RPC specific structs to this voided one */
end_comment

begin_struct
struct|struct
name|evrpc_req_generic
block|{
comment|/* 	 * allows association of meta data via hooks - needs to be 	 * synchronized with evrpc_request_wrapper 	 */
name|struct
name|evrpc_hook_meta
modifier|*
name|hook_meta
decl_stmt|;
comment|/* the unmarshaled request object */
name|void
modifier|*
name|request
decl_stmt|;
comment|/* the empty reply object that needs to be filled in */
name|void
modifier|*
name|reply
decl_stmt|;
comment|/* 	 * the static structure for this rpc; that can be used to 	 * automatically unmarshal and marshal the http buffers. 	 */
name|struct
name|evrpc
modifier|*
name|rpc
decl_stmt|;
comment|/* 	 * the http request structure on which we need to answer. 	 */
name|struct
name|evhttp_request
modifier|*
name|http_req
decl_stmt|;
comment|/* 	 * Temporary data store for marshaled data 	 */
name|struct
name|evbuffer
modifier|*
name|rpc_data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* the client side of an rpc request */
end_comment

begin_struct
struct|struct
name|evrpc_request_wrapper
block|{
comment|/* 	 * allows association of meta data via hooks - needs to be 	 * synchronized with evrpc_req_generic. 	 */
name|struct
name|evrpc_hook_meta
modifier|*
name|hook_meta
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|evrpc_request_wrapper
argument_list|)
name|next
expr_stmt|;
comment|/* pool on which this rpc request is being made */
name|struct
name|evrpc_pool
modifier|*
name|pool
decl_stmt|;
comment|/* connection on which the request is being sent */
name|struct
name|evhttp_connection
modifier|*
name|evcon
decl_stmt|;
comment|/* the actual  request */
name|struct
name|evhttp_request
modifier|*
name|req
decl_stmt|;
comment|/* event for implementing request timeouts */
name|struct
name|event
name|ev_timeout
decl_stmt|;
comment|/* the name of the rpc */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* callback */
name|void
function_decl|(
modifier|*
name|cb
function_decl|)
parameter_list|(
name|struct
name|evrpc_status
modifier|*
parameter_list|,
name|void
modifier|*
name|request
parameter_list|,
name|void
modifier|*
name|reply
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
name|void
modifier|*
name|cb_arg
decl_stmt|;
name|void
modifier|*
name|request
decl_stmt|;
name|void
modifier|*
name|reply
decl_stmt|;
comment|/* unmarshals the buffer into the proper request structure */
name|void
function_decl|(
modifier|*
name|request_marshal
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
comment|/* removes all stored state in the reply */
name|void
function_decl|(
modifier|*
name|reply_clear
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* marshals the reply into a buffer */
name|int
function_decl|(
modifier|*
name|reply_unmarshal
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
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EVRPC_INTERNAL_H_INCLUDED_ */
end_comment

end_unit

