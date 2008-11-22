begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 Isilon Inc http://www.isilon.com/  * Authors: Doug Rabson<dfr@rabson.org>  * Developed with Red Inc: Alfred Perlstein<alfred@freebsd.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NLM_NLM_H_
end_ifndef

begin_define
define|#
directive|define
name|_NLM_NLM_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|_SYS_MALLOC_H_
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NLM
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|nlm_host
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Copy a struct netobj.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|nlm_copy_netobj
parameter_list|(
name|struct
name|netobj
modifier|*
name|dst
parameter_list|,
name|struct
name|netobj
modifier|*
name|src
parameter_list|,
name|struct
name|malloc_type
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Search for an existing NLM host that matches the given name  * (typically the caller_name element of an nlm4_lock).  If none is  * found, create a new host. If 'rqstp' is non-NULL, record the remote  * address of the host so that we can call it back for async  * responses.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|nlm_host
modifier|*
name|nlm_find_host_by_name
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|struct
name|svc_req
modifier|*
name|rqstp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Search for an existing NLM host that matches the given remote  * address. If none is found, create a new host with the requested  * address and remember 'vers' as the NLM protocol version to use for  * that host.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|nlm_host
modifier|*
name|nlm_find_host_by_addr
parameter_list|(
specifier|const
name|struct
name|sockaddr
modifier|*
name|addr
parameter_list|,
name|int
name|vers
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return an RPC client handle that can be used to talk to the NLM  * running on the given host.  */
end_comment

begin_function_decl
specifier|extern
name|CLIENT
modifier|*
name|nlm_host_get_rpc
parameter_list|(
name|struct
name|nlm_host
modifier|*
name|host
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Called when a host restarts.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|nlm_sm_notify
parameter_list|(
name|nlm_sm_status
modifier|*
name|argp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Implementation for lock testing RPCs. Returns the NLM host that  * matches the RPC arguments.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|nlm_host
modifier|*
name|nlm_do_test
parameter_list|(
name|nlm4_testargs
modifier|*
name|argp
parameter_list|,
name|nlm4_testres
modifier|*
name|result
parameter_list|,
name|struct
name|svc_req
modifier|*
name|rqstp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Implementation for lock setting RPCs. Returns the NLM host that  * matches the RPC arguments. If monitor is TRUE, set up an NSM  * monitor for this host.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|nlm_host
modifier|*
name|nlm_do_lock
parameter_list|(
name|nlm4_lockargs
modifier|*
name|argp
parameter_list|,
name|nlm4_res
modifier|*
name|result
parameter_list|,
name|struct
name|svc_req
modifier|*
name|rqstp
parameter_list|,
name|bool_t
name|monitor
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Implementation for cancelling a pending lock request. Returns the  * NLM host that matches the RPC arguments.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|nlm_host
modifier|*
name|nlm_do_cancel
parameter_list|(
name|nlm4_cancargs
modifier|*
name|argp
parameter_list|,
name|nlm4_res
modifier|*
name|result
parameter_list|,
name|struct
name|svc_req
modifier|*
name|rqstp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Implementation for unlocking RPCs. Returns the NLM host that  * matches the RPC arguments.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|nlm_host
modifier|*
name|nlm_do_unlock
parameter_list|(
name|nlm4_unlockargs
modifier|*
name|argp
parameter_list|,
name|nlm4_res
modifier|*
name|result
parameter_list|,
name|struct
name|svc_req
modifier|*
name|rqstp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Free all locks associated with the hostname argp->name.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|nlm_do_free_all
parameter_list|(
name|nlm4_notify
modifier|*
name|argp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Find an RPC transport that can be used to communicate with the  * userland part of lockd.  */
end_comment

begin_function_decl
specifier|extern
name|CLIENT
modifier|*
name|nlm_user_lockd
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

