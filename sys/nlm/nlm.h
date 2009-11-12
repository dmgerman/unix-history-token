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

begin_comment
comment|/*  * This value is added to host system IDs when recording NFS client  * locks in the local lock manager.  */
end_comment

begin_define
define|#
directive|define
name|NLM_SYSID_CLIENT
value|0x1000000
end_define

begin_struct_decl
struct_decl|struct
name|nlm_host
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vnode
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|struct
name|timeval
name|nlm_zero_tv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nlm_nsm_state
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Make a struct netobj.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|nlm_make_netobj
parameter_list|(
name|struct
name|netobj
modifier|*
name|dst
parameter_list|,
name|caddr_t
name|srt
parameter_list|,
name|size_t
name|srcsize
parameter_list|,
name|struct
name|malloc_type
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

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
comment|/*  * Search for an existing NLM host that matches the given name  * (typically the caller_name element of an nlm4_lock).  If none is  * found, create a new host. If 'addr' is non-NULL, record the remote  * address of the host so that we can call it back for async  * responses. If 'vers' is greater than zero then record the NLM  * program version to use to communicate with this client. The host  * reference count is incremented - the caller must call  * nlm_host_release when it has finished using it.  */
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
specifier|const
name|struct
name|sockaddr
modifier|*
name|addr
parameter_list|,
name|rpcvers_t
name|vers
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Search for an existing NLM host that matches the given remote  * address. If none is found, create a new host with the requested  * address and remember 'vers' as the NLM protocol version to use for  * that host. The host reference count is incremented - the caller  * must call nlm_host_release when it has finished using it.  */
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
comment|/*  * Register this NLM host with the local NSM so that we can be  * notified if it reboots.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|nlm_host_monitor
parameter_list|(
name|struct
name|nlm_host
modifier|*
name|host
parameter_list|,
name|int
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Decrement the host reference count, freeing resources if the  * reference count reaches zero.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|nlm_host_release
parameter_list|(
name|struct
name|nlm_host
modifier|*
name|host
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
parameter_list|,
name|bool_t
name|isserver
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return the system ID for a host.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|nlm_host_get_sysid
parameter_list|(
name|struct
name|nlm_host
modifier|*
name|host
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return the remote NSM state value for a host.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|nlm_host_get_state
parameter_list|(
name|struct
name|nlm_host
modifier|*
name|host
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * When sending a blocking lock request, we need to track the request  * in our waiting lock list. We add an entry to the waiting list  * before we send the lock RPC so that we can cope with a granted  * message arriving at any time. Call this function before sending the  * lock rpc. If the lock succeeds, call nlm_deregister_wait_lock with  * the handle this function returns, otherwise nlm_wait_lock. Both  * will remove the entry from the waiting list.  */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|nlm_register_wait_lock
parameter_list|(
name|struct
name|nlm4_lock
modifier|*
name|lock
parameter_list|,
name|struct
name|vnode
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Deregister a blocking lock request. Call this if the lock succeeded  * without blocking.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|nlm_deregister_wait_lock
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Wait for a granted callback for a blocked lock request, waiting at  * most timo ticks. If no granted message is received within the  * timeout, return EWOULDBLOCK. If a signal interrupted the wait,  * return EINTR - the caller must arrange to send a cancellation to  * the server. In both cases, the request is removed from the waiting  * list.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|nlm_wait_lock
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|,
name|int
name|timo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Cancel any pending waits for this vnode - called on forcible unmounts.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|nlm_cancel_wait
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
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
comment|/*  * Implementation for lock testing RPCs. If the request was handled  * successfully and rpcp is non-NULL, *rpcp is set to an RPC client  * handle which can be used to send an async rpc reply. Returns zero  * if the request was handled, or a suitable unix error code  * otherwise.  */
end_comment

begin_function_decl
specifier|extern
name|int
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
parameter_list|,
name|CLIENT
modifier|*
modifier|*
name|rpcp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Implementation for lock setting RPCs. If the request was handled  * successfully and rpcp is non-NULL, *rpcp is set to an RPC client  * handle which can be used to send an async rpc reply. Returns zero  * if the request was handled, or a suitable unix error code  * otherwise.  */
end_comment

begin_function_decl
specifier|extern
name|int
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
parameter_list|,
name|CLIENT
modifier|*
modifier|*
name|rpcp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Implementation for cancelling a pending lock request. If the  * request was handled successfully and rpcp is non-NULL, *rpcp is set  * to an RPC client handle which can be used to send an async rpc  * reply. Returns zero if the request was handled, or a suitable unix  * error code otherwise.  */
end_comment

begin_function_decl
specifier|extern
name|int
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
parameter_list|,
name|CLIENT
modifier|*
modifier|*
name|rpcp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Implementation for unlocking RPCs. If the request was handled  * successfully and rpcp is non-NULL, *rpcp is set to an RPC client  * handle which can be used to send an async rpc reply. Returns zero  * if the request was handled, or a suitable unix error code  * otherwise.  */
end_comment

begin_function_decl
specifier|extern
name|int
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
parameter_list|,
name|CLIENT
modifier|*
modifier|*
name|rpcp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Implementation for granted RPCs. If the request was handled  * successfully and rpcp is non-NULL, *rpcp is set to an RPC client  * handle which can be used to send an async rpc reply. Returns zero  * if the request was handled, or a suitable unix error code  * otherwise.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|nlm_do_granted
parameter_list|(
name|nlm4_testargs
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
name|CLIENT
modifier|*
modifier|*
name|rpcp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Implementation for the granted result RPC. The client may reject the granted  * message, in which case we need to handle it appropriately.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|nlm_do_granted_res
parameter_list|(
name|nlm4_res
modifier|*
name|argp
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
comment|/*  * Recover client lock state after a server reboot.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|nlm_client_recovery
parameter_list|(
name|struct
name|nlm_host
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Interface from NFS client code to the NLM.  */
end_comment

begin_struct_decl
struct_decl|struct
name|vop_advlock_args
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vop_reclaim_args
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|nlm_advlock
parameter_list|(
name|struct
name|vop_advlock_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nlm_reclaim
parameter_list|(
name|struct
name|vop_reclaim_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Acquire the next sysid for remote locks not handled by the NLM.  */
end_comment

begin_function_decl
specifier|extern
name|uint32_t
name|nlm_acquire_next_sysid
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

