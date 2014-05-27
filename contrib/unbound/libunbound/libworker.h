begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * libunbound/worker.h - worker thread or process that resolves  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains the worker process or thread that performs  * the DNS resolving and validation. The worker is called by a procedure  * and if in the background continues until exit, if in the foreground  * returns from the procedure when done.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LIBUNBOUND_LIBWORKER_H
end_ifndef

begin_define
define|#
directive|define
name|LIBUNBOUND_LIBWORKER_H
end_define

begin_include
include|#
directive|include
file|"util/data/packed_rrset.h"
end_include

begin_struct_decl
struct_decl|struct
name|ub_ctx
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ub_result
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|module_env
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|comm_base
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|outside_network
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ub_randstate
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ctx_query
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|outbound_entry
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|module_qstate
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|comm_point
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|comm_reply
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|regional
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|tube
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sldns_buffer
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|event_base
struct_decl|;
end_struct_decl

begin_comment
comment|/**   * The library-worker status structure  * Internal to the worker.  */
end_comment

begin_struct
struct|struct
name|libworker
block|{
comment|/** every worker has a unique thread_num. (first in struct) */
name|int
name|thread_num
decl_stmt|;
comment|/** context we are operating under */
name|struct
name|ub_ctx
modifier|*
name|ctx
decl_stmt|;
comment|/** is this the bg worker? */
name|int
name|is_bg
decl_stmt|;
comment|/** is this a bg worker that is threaded (not forked)? */
name|int
name|is_bg_thread
decl_stmt|;
comment|/** copy of the module environment with worker local entries. */
name|struct
name|module_env
modifier|*
name|env
decl_stmt|;
comment|/** the event base this worker works with */
name|struct
name|comm_base
modifier|*
name|base
decl_stmt|;
comment|/** the backside outside network interface to the auth servers */
name|struct
name|outside_network
modifier|*
name|back
decl_stmt|;
comment|/** random() table for this worker. */
name|struct
name|ub_randstate
modifier|*
name|rndstate
decl_stmt|;
comment|/** sslcontext for SSL wrapped DNS over TCP queries */
name|void
modifier|*
name|sslctx
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Create a background worker  * @param ctx: is updated with pid/tid of the background worker.  *	a new allocation cache is obtained from ctx. It contains the  *	threadnumber and unique id for further (shared) cache insertions.  * @return 0 if OK, else error.  *	Further communication is done via the pipes in ctx.   */
end_comment

begin_function_decl
name|int
name|libworker_bg
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Create a foreground worker.  * This worker will join the threadpool of resolver threads.  * It exits when the query answer has been obtained (or error).  * This routine blocks until the worker is finished.  * @param ctx: new allocation cache obtained and returned to it.  * @param q: query (result is stored in here).  * @return 0 if finished OK, else error.  */
end_comment

begin_function_decl
name|int
name|libworker_fg
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|,
name|struct
name|ctx_query
modifier|*
name|q
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * create worker for event-based interface.  * @param ctx: context with config.  * @param eb: event base.  * @return new worker or NULL.  */
end_comment

begin_function_decl
name|struct
name|libworker
modifier|*
name|libworker_create_event
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|,
name|struct
name|event_base
modifier|*
name|eb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Attach context_query to mesh for callback in event-driven setup.  * @param ctx: context  * @param q: context query entry  * @param async_id: store query num if query takes long.  * @return 0 if finished OK, else error.  */
end_comment

begin_function_decl
name|int
name|libworker_attach_mesh
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|,
name|struct
name|ctx_query
modifier|*
name|q
parameter_list|,
name|int
modifier|*
name|async_id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * delete worker for event-based interface.  does not free the event_base.  * @param w: event-based worker to delete.  */
end_comment

begin_function_decl
name|void
name|libworker_delete_event
parameter_list|(
name|struct
name|libworker
modifier|*
name|w
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** cleanup the cache to remove all rrset IDs from it, arg is libworker */
end_comment

begin_function_decl
name|void
name|libworker_alloc_cleanup
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * fill result from parsed message, on error fills servfail   * @param res: is clear at start, filled in at end.  * @param buf: contains DNS message.  * @param temp: temporary buffer for parse.  * @param msg_security: security status of the DNS message.  *   On error, the res may contain a different status   *   (out of memory is not secure, not bogus).  */
end_comment

begin_function_decl
name|void
name|libworker_enter_result
parameter_list|(
name|struct
name|ub_result
modifier|*
name|res
parameter_list|,
name|struct
name|sldns_buffer
modifier|*
name|buf
parameter_list|,
name|struct
name|regional
modifier|*
name|temp
parameter_list|,
name|enum
name|sec_status
name|msg_security
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBUNBOUND_LIBWORKER_H */
end_comment

end_unit

