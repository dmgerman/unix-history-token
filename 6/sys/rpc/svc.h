begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: svc.h,v 1.17 2000/06/02 22:57:56 fvdl Exp $	*/
end_comment

begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *  * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *  * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *  * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *  * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *  * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  *  *	from: @(#)svc.h 1.35 88/12/17 SMI  *	from: @(#)svc.h      1.27    94/04/25 SMI  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * svc.h, Server-side remote procedure call interface.  *  * Copyright (C) 1986-1993 by Sun Microsystems, Inc.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RPC_SVC_H
end_ifndef

begin_define
define|#
directive|define
name|_RPC_SVC_H
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_mutex.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This interface must manage two items concerning remote procedure calling:  *  * 1) An arbitrary number of transport connections upon which rpc requests  * are received.  The two most notable transports are TCP and UDP;  they are  * created and registered by routines in svc_tcp.c and svc_udp.c, respectively;  * they in turn call xprt_register and xprt_unregister.  *  * 2) An arbitrary number of locally registered services.  Services are  * described by the following four data: program number, version number,  * "service dispatch" function, a transport handle, and a boolean that  * indicates whether or not the exported program should be registered with a  * local binder service;  if true the program's number and version and the  * port number from the transport handle are registered with the binder.  * These data are registered with the rpc svc system via svc_register.  *  * A service's dispatch function is called whenever an rpc request comes in  * on a transport.  The request's program and version numbers must match  * those of the registered service.  The dispatch function is passed two  * parameters, struct svc_req * and SVCXPRT *, defined below.  */
end_comment

begin_comment
comment|/*  *      Service control requests  */
end_comment

begin_define
define|#
directive|define
name|SVCGET_VERSQUIET
value|1
end_define

begin_define
define|#
directive|define
name|SVCSET_VERSQUIET
value|2
end_define

begin_define
define|#
directive|define
name|SVCGET_CONNMAXREC
value|3
end_define

begin_define
define|#
directive|define
name|SVCSET_CONNMAXREC
value|4
end_define

begin_comment
comment|/*  * Operations for rpc_control().  */
end_comment

begin_define
define|#
directive|define
name|RPC_SVC_CONNMAXREC_SET
value|0
end_define

begin_comment
comment|/* set max rec size, enable nonblock */
end_comment

begin_define
define|#
directive|define
name|RPC_SVC_CONNMAXREC_GET
value|1
end_define

begin_enum
enum|enum
name|xprt_stat
block|{
name|XPRT_DIED
block|,
name|XPRT_MOREREQS
block|,
name|XPRT_IDLE
block|}
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|__rpc_svcxprt
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|xp_ops
block|{
comment|/* receive incoming requests */
name|bool_t
function_decl|(
modifier|*
name|xp_recv
function_decl|)
parameter_list|(
name|struct
name|__rpc_svcxprt
modifier|*
parameter_list|,
name|struct
name|rpc_msg
modifier|*
parameter_list|)
function_decl|;
comment|/* get transport status */
name|enum
name|xprt_stat
function_decl|(
modifier|*
name|xp_stat
function_decl|)
parameter_list|(
name|struct
name|__rpc_svcxprt
modifier|*
parameter_list|)
function_decl|;
comment|/* get arguments */
name|bool_t
function_decl|(
modifier|*
name|xp_getargs
function_decl|)
parameter_list|(
name|struct
name|__rpc_svcxprt
modifier|*
parameter_list|,
name|xdrproc_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* send reply */
name|bool_t
function_decl|(
modifier|*
name|xp_reply
function_decl|)
parameter_list|(
name|struct
name|__rpc_svcxprt
modifier|*
parameter_list|,
name|struct
name|rpc_msg
modifier|*
parameter_list|)
function_decl|;
comment|/* free mem allocated for args */
name|bool_t
function_decl|(
modifier|*
name|xp_freeargs
function_decl|)
parameter_list|(
name|struct
name|__rpc_svcxprt
modifier|*
parameter_list|,
name|xdrproc_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* destroy this struct */
name|void
function_decl|(
modifier|*
name|xp_destroy
function_decl|)
parameter_list|(
name|struct
name|__rpc_svcxprt
modifier|*
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|_KERNEL
comment|/* catch-all function */
name|bool_t
function_decl|(
modifier|*
name|xp_control
function_decl|)
parameter_list|(
name|struct
name|__rpc_svcxprt
modifier|*
parameter_list|,
specifier|const
name|u_int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_struct
struct|struct
name|xp_ops2
block|{
comment|/* catch-all function */
name|bool_t
function_decl|(
modifier|*
name|xp_control
function_decl|)
parameter_list|(
name|struct
name|__rpc_svcxprt
modifier|*
parameter_list|,
specifier|const
name|u_int
parameter_list|,
name|void
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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|__rpc_svcpool
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Server side transport handle  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|__rpc_svcxprt
block|{
ifdef|#
directive|ifdef
name|_KERNEL
name|struct
name|mtx
name|xp_lock
decl_stmt|;
name|struct
name|__rpc_svcpool
modifier|*
name|xp_pool
decl_stmt|;
comment|/* owning pool (see below) */
name|TAILQ_ENTRY
argument_list|(
argument|__rpc_svcxprt
argument_list|)
name|xp_link
expr_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|__rpc_svcxprt
argument_list|)
name|xp_alink
expr_stmt|;
name|bool_t
name|xp_registered
decl_stmt|;
comment|/* xprt_register has been called */
name|bool_t
name|xp_active
decl_stmt|;
comment|/* xprt_active has been called */
name|struct
name|socket
modifier|*
name|xp_socket
decl_stmt|;
specifier|const
name|struct
name|xp_ops
modifier|*
name|xp_ops
decl_stmt|;
name|char
modifier|*
name|xp_netid
decl_stmt|;
comment|/* network token */
name|struct
name|netbuf
name|xp_ltaddr
decl_stmt|;
comment|/* local transport address */
name|struct
name|netbuf
name|xp_rtaddr
decl_stmt|;
comment|/* remote transport address */
name|struct
name|opaque_auth
name|xp_verf
decl_stmt|;
comment|/* raw response verifier */
name|uint32_t
name|xp_xid
decl_stmt|;
comment|/* current transaction ID */
name|XDR
name|xp_xdrreq
decl_stmt|;
comment|/* xdr stream for decoding request */
name|XDR
name|xp_xdrrep
decl_stmt|;
comment|/* xdr stream for encoding reply */
name|void
modifier|*
name|xp_p1
decl_stmt|;
comment|/* private: for use by svc ops */
name|void
modifier|*
name|xp_p2
decl_stmt|;
comment|/* private: for use by svc ops */
name|void
modifier|*
name|xp_p3
decl_stmt|;
comment|/* private: for use by svc lib */
name|int
name|xp_type
decl_stmt|;
comment|/* transport type */
else|#
directive|else
name|int
name|xp_fd
decl_stmt|;
name|u_short
name|xp_port
decl_stmt|;
comment|/* associated port number */
specifier|const
name|struct
name|xp_ops
modifier|*
name|xp_ops
decl_stmt|;
name|int
name|xp_addrlen
decl_stmt|;
comment|/* length of remote address */
name|struct
name|sockaddr_in
name|xp_raddr
decl_stmt|;
comment|/* remote addr. (backward ABI compat) */
comment|/* XXX - fvdl stick this here for ABI backward compat reasons */
specifier|const
name|struct
name|xp_ops2
modifier|*
name|xp_ops2
decl_stmt|;
name|char
modifier|*
name|xp_tp
decl_stmt|;
comment|/* transport provider device name */
name|char
modifier|*
name|xp_netid
decl_stmt|;
comment|/* network token */
name|struct
name|netbuf
name|xp_ltaddr
decl_stmt|;
comment|/* local transport address */
name|struct
name|netbuf
name|xp_rtaddr
decl_stmt|;
comment|/* remote transport address */
name|struct
name|opaque_auth
name|xp_verf
decl_stmt|;
comment|/* raw response verifier */
name|void
modifier|*
name|xp_p1
decl_stmt|;
comment|/* private: for use by svc ops */
name|void
modifier|*
name|xp_p2
decl_stmt|;
comment|/* private: for use by svc ops */
name|void
modifier|*
name|xp_p3
decl_stmt|;
comment|/* private: for use by svc lib */
name|int
name|xp_type
decl_stmt|;
comment|/* transport type */
endif|#
directive|endif
block|}
name|SVCXPRT
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * The services list  * Each entry represents a set of procedures (an rpc program).  * The dispatch routine takes request structs and runs the  * apropriate procedure.  */
end_comment

begin_struct
struct|struct
name|svc_callout
block|{
name|TAILQ_ENTRY
argument_list|(
argument|svc_callout
argument_list|)
name|sc_link
expr_stmt|;
name|rpcprog_t
name|sc_prog
decl_stmt|;
name|rpcvers_t
name|sc_vers
decl_stmt|;
name|char
modifier|*
name|sc_netid
decl_stmt|;
name|void
function_decl|(
modifier|*
name|sc_dispatch
function_decl|)
parameter_list|(
name|struct
name|svc_req
modifier|*
parameter_list|,
name|SVCXPRT
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|svc_callout_list
argument_list|,
name|svc_callout
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * In the kernel, we can't use global variables to store lists of  * transports etc. since otherwise we could not have two unrelated RPC  * services running, each on its own thread. We solve this by  * importing a tiny part of a Solaris kernel concept, SVCPOOL.  *  * A service pool contains a set of transports and service callbacks  * for a set of related RPC services. The pool handle should be passed  * when creating new transports etc. Future work may include extending  * this to support something similar to the Solaris multi-threaded RPC  * server.  */
end_comment

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|svcxprt_list
argument_list|,
name|__rpc_svcxprt
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
struct|struct
name|__rpc_svcpool
block|{
name|struct
name|mtx
name|sp_lock
decl_stmt|;
comment|/* protect the transport lists */
name|struct
name|svcxprt_list
name|sp_xlist
decl_stmt|;
comment|/* all transports in the pool */
name|struct
name|svcxprt_list
name|sp_active
decl_stmt|;
comment|/* transports needing service */
name|struct
name|svc_callout_list
name|sp_callouts
decl_stmt|;
comment|/* (prog,vers)->dispatch list */
name|bool_t
name|sp_exited
decl_stmt|;
comment|/* true if shutting down */
block|}
name|SVCPOOL
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Service request  */
end_comment

begin_struct
struct|struct
name|svc_req
block|{
name|uint32_t
name|rq_prog
decl_stmt|;
comment|/* service program number */
name|uint32_t
name|rq_vers
decl_stmt|;
comment|/* service protocol version */
name|uint32_t
name|rq_proc
decl_stmt|;
comment|/* the desired procedure */
name|struct
name|opaque_auth
name|rq_cred
decl_stmt|;
comment|/* raw creds from the wire */
name|void
modifier|*
name|rq_clntcred
decl_stmt|;
comment|/* read only cooked cred */
name|SVCXPRT
modifier|*
name|rq_xprt
decl_stmt|;
comment|/* associated transport */
block|}
struct|;
end_struct

begin_comment
comment|/*  *  Approved way of getting address of caller  */
end_comment

begin_define
define|#
directive|define
name|svc_getrpccaller
parameter_list|(
name|x
parameter_list|)
value|(&(x)->xp_rtaddr)
end_define

begin_comment
comment|/*  * Operations defined on an SVCXPRT handle  *  * SVCXPRT		*xprt;  * struct rpc_msg	*msg;  * xdrproc_t		 xargs;  * void *		 argsp;  */
end_comment

begin_define
define|#
directive|define
name|SVC_RECV
parameter_list|(
name|xprt
parameter_list|,
name|msg
parameter_list|)
define|\
value|(*(xprt)->xp_ops->xp_recv)((xprt), (msg))
end_define

begin_define
define|#
directive|define
name|svc_recv
parameter_list|(
name|xprt
parameter_list|,
name|msg
parameter_list|)
define|\
value|(*(xprt)->xp_ops->xp_recv)((xprt), (msg))
end_define

begin_define
define|#
directive|define
name|SVC_STAT
parameter_list|(
name|xprt
parameter_list|)
define|\
value|(*(xprt)->xp_ops->xp_stat)(xprt)
end_define

begin_define
define|#
directive|define
name|svc_stat
parameter_list|(
name|xprt
parameter_list|)
define|\
value|(*(xprt)->xp_ops->xp_stat)(xprt)
end_define

begin_define
define|#
directive|define
name|SVC_GETARGS
parameter_list|(
name|xprt
parameter_list|,
name|xargs
parameter_list|,
name|argsp
parameter_list|)
define|\
value|(*(xprt)->xp_ops->xp_getargs)((xprt), (xargs), (argsp))
end_define

begin_define
define|#
directive|define
name|svc_getargs
parameter_list|(
name|xprt
parameter_list|,
name|xargs
parameter_list|,
name|argsp
parameter_list|)
define|\
value|(*(xprt)->xp_ops->xp_getargs)((xprt), (xargs), (argsp))
end_define

begin_define
define|#
directive|define
name|SVC_REPLY
parameter_list|(
name|xprt
parameter_list|,
name|msg
parameter_list|)
define|\
value|(*(xprt)->xp_ops->xp_reply) ((xprt), (msg))
end_define

begin_define
define|#
directive|define
name|svc_reply
parameter_list|(
name|xprt
parameter_list|,
name|msg
parameter_list|)
define|\
value|(*(xprt)->xp_ops->xp_reply) ((xprt), (msg))
end_define

begin_define
define|#
directive|define
name|SVC_FREEARGS
parameter_list|(
name|xprt
parameter_list|,
name|xargs
parameter_list|,
name|argsp
parameter_list|)
define|\
value|(*(xprt)->xp_ops->xp_freeargs)((xprt), (xargs), (argsp))
end_define

begin_define
define|#
directive|define
name|svc_freeargs
parameter_list|(
name|xprt
parameter_list|,
name|xargs
parameter_list|,
name|argsp
parameter_list|)
define|\
value|(*(xprt)->xp_ops->xp_freeargs)((xprt), (xargs), (argsp))
end_define

begin_define
define|#
directive|define
name|SVC_DESTROY
parameter_list|(
name|xprt
parameter_list|)
define|\
value|(*(xprt)->xp_ops->xp_destroy)(xprt)
end_define

begin_define
define|#
directive|define
name|svc_destroy
parameter_list|(
name|xprt
parameter_list|)
define|\
value|(*(xprt)->xp_ops->xp_destroy)(xprt)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|SVC_CONTROL
parameter_list|(
name|xprt
parameter_list|,
name|rq
parameter_list|,
name|in
parameter_list|)
define|\
value|(*(xprt)->xp_ops->xp_control)((xprt), (rq), (in))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SVC_CONTROL
parameter_list|(
name|xprt
parameter_list|,
name|rq
parameter_list|,
name|in
parameter_list|)
define|\
value|(*(xprt)->xp_ops2->xp_control)((xprt), (rq), (in))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Service registration  *  * svc_reg(xprt, prog, vers, dispatch, nconf)  *	const SVCXPRT *xprt;  *	const rpcprog_t prog;  *	const rpcvers_t vers;  *	const void (*dispatch)();  *	const struct netconfig *nconf;  */
end_comment

begin_function_decl
name|__BEGIN_DECLS
specifier|extern
name|bool_t
name|svc_reg
parameter_list|(
name|SVCXPRT
modifier|*
parameter_list|,
specifier|const
name|rpcprog_t
parameter_list|,
specifier|const
name|rpcvers_t
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|svc_req
modifier|*
parameter_list|,
name|SVCXPRT
modifier|*
parameter_list|)
parameter_list|,
specifier|const
name|struct
name|netconfig
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__END_DECLS
comment|/*  * Service un-registration  *  * svc_unreg(prog, vers)  *	const rpcprog_t prog;  *	const rpcvers_t vers;  */
name|__BEGIN_DECLS
ifdef|#
directive|ifdef
name|_KERNEL
specifier|extern
name|void
name|svc_unreg
parameter_list|(
name|SVCPOOL
modifier|*
parameter_list|,
specifier|const
name|rpcprog_t
parameter_list|,
specifier|const
name|rpcvers_t
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|svc_unreg
parameter_list|(
specifier|const
name|rpcprog_t
parameter_list|,
specifier|const
name|rpcvers_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|__END_DECLS
comment|/*  * Transport registration.  *  * xprt_register(xprt)  *	SVCXPRT *xprt;  */
name|__BEGIN_DECLS
specifier|extern
name|void
name|xprt_register
parameter_list|(
name|SVCXPRT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__END_DECLS
comment|/*  * Transport un-register  *  * xprt_unregister(xprt)  *	SVCXPRT *xprt;  */
name|__BEGIN_DECLS
specifier|extern
name|void
name|xprt_unregister
parameter_list|(
name|SVCXPRT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__xprt_unregister_unlocked
parameter_list|(
name|SVCXPRT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__END_DECLS
ifdef|#
directive|ifdef
name|_KERNEL
comment|/*  * Called when a transport has pending requests.  */
name|__BEGIN_DECLS
specifier|extern
name|void
name|xprt_active
parameter_list|(
name|SVCXPRT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xprt_inactive
parameter_list|(
name|SVCXPRT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__END_DECLS
endif|#
directive|endif
comment|/*  * When the service routine is called, it must first check to see if it  * knows about the procedure;  if not, it should call svcerr_noproc  * and return.  If so, it should deserialize its arguments via  * SVC_GETARGS (defined above).  If the deserialization does not work,  * svcerr_decode should be called followed by a return.  Successful  * decoding of the arguments should be followed the execution of the  * procedure's code and a call to svc_sendreply.  *  * Also, if the service refuses to execute the procedure due to too-  * weak authentication parameters, svcerr_weakauth should be called.  * Note: do not confuse access-control failure with weak authentication!  *  * NB: In pure implementations of rpc, the caller always waits for a reply  * msg.  This message is sent when svc_sendreply is called.  * Therefore pure service implementations should always call  * svc_sendreply even if the function logically returns void;  use  * xdr.h - xdr_void for the xdr routine.  HOWEVER, tcp based rpc allows  * for the abuse of pure rpc via batched calling or pipelining.  In the  * case of a batched call, svc_sendreply should NOT be called since  * this would send a return message, which is what batching tries to avoid.  * It is the service/protocol writer's responsibility to know which calls are  * batched and which are not.  Warning: responding to batch calls may  * deadlock the caller and server processes!  */
name|__BEGIN_DECLS
specifier|extern
name|bool_t
name|svc_sendreply
parameter_list|(
name|SVCXPRT
modifier|*
parameter_list|,
name|xdrproc_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|svcerr_decode
parameter_list|(
name|SVCXPRT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|svcerr_weakauth
parameter_list|(
name|SVCXPRT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|svcerr_noproc
parameter_list|(
name|SVCXPRT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|svcerr_progvers
parameter_list|(
name|SVCXPRT
modifier|*
parameter_list|,
name|rpcvers_t
parameter_list|,
name|rpcvers_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|svcerr_auth
parameter_list|(
name|SVCXPRT
modifier|*
parameter_list|,
name|enum
name|auth_stat
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|svcerr_noprog
parameter_list|(
name|SVCXPRT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|svcerr_systemerr
parameter_list|(
name|SVCXPRT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|rpc_reg
parameter_list|(
name|rpcprog_t
parameter_list|,
name|rpcvers_t
parameter_list|,
name|rpcproc_t
parameter_list|,
name|char
modifier|*
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|)
parameter_list|,
name|xdrproc_t
parameter_list|,
name|xdrproc_t
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|__END_DECLS
comment|/*  * Lowest level dispatching -OR- who owns this process anyway.  * Somebody has to wait for incoming requests and then call the correct  * service routine.  The routine svc_run does infinite waiting; i.e.,  * svc_run never returns.  * Since another (co-existant) package may wish to selectively wait for  * incoming calls or other events outside of the rpc architecture, the  * routine svc_getreq is provided.  It must be passed readfds, the  * "in-place" results of a select system call (see select, section 2).  */
ifndef|#
directive|ifndef
name|_KERNEL
comment|/*  * Global keeper of rpc service descriptors in use  * dynamic; must be inspected before each call to select  */
specifier|extern
name|int
name|svc_maxfd
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|FD_SETSIZE
end_ifdef

begin_decl_stmt
specifier|extern
name|fd_set
name|svc_fdset
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|svc_fds
value|svc_fdset.fds_bits[0]
end_define

begin_comment
comment|/* compatibility */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|int
name|svc_fds
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* def FD_SETSIZE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * a small program implemented by the svc_rpc implementation itself;  * also see clnt.h for protocol numbers.  */
end_comment

begin_function_decl
name|__BEGIN_DECLS
specifier|extern
name|void
name|rpctest_service
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__END_DECLS
name|__BEGIN_DECLS
ifndef|#
directive|ifndef
name|_KERNEL
specifier|extern
name|void
name|svc_getreq
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|svc_getreqset
parameter_list|(
name|fd_set
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|svc_getreq_common
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|pollfd
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|svc_getreq_poll
parameter_list|(
name|struct
name|pollfd
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|svc_run
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|svc_exit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|svc_run
parameter_list|(
name|SVCPOOL
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|svc_exit
parameter_list|(
name|SVCPOOL
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|__END_DECLS
comment|/*  * Socket to use on svcxxx_create call to get default socket  */
define|#
directive|define
name|RPC_ANYSOCK
value|-1
define|#
directive|define
name|RPC_ANYFD
value|RPC_ANYSOCK
comment|/*  * These are the existing service side transport implementations  */
name|__BEGIN_DECLS
ifdef|#
directive|ifdef
name|_KERNEL
comment|/*  * Create a new service pool.  */
specifier|extern
name|SVCPOOL
modifier|*
name|svcpool_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Destroy a service pool, including all registered transports.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|svcpool_destroy
parameter_list|(
name|SVCPOOL
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Transport independent svc_create routine.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|svc_create
parameter_list|(
name|SVCPOOL
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|svc_req
modifier|*
parameter_list|,
name|SVCXPRT
modifier|*
parameter_list|)
parameter_list|,
specifier|const
name|rpcprog_t
parameter_list|,
specifier|const
name|rpcvers_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *      void (*dispatch)();             -- dispatch routine  *      const rpcprog_t prognum;        -- program number  *      const rpcvers_t versnum;        -- version number  *      const char *nettype;            -- network type  */
end_comment

begin_comment
comment|/*  * Generic server creation routine. It takes a netconfig structure  * instead of a nettype.  */
end_comment

begin_function_decl
specifier|extern
name|SVCXPRT
modifier|*
name|svc_tp_create
parameter_list|(
name|SVCPOOL
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|svc_req
modifier|*
parameter_list|,
name|SVCXPRT
modifier|*
parameter_list|)
parameter_list|,
specifier|const
name|rpcprog_t
parameter_list|,
specifier|const
name|rpcvers_t
parameter_list|,
specifier|const
name|char
modifier|*
name|uaddr
parameter_list|,
specifier|const
name|struct
name|netconfig
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*          * void (*dispatch)();            -- dispatch routine          * const rpcprog_t prognum;       -- program number          * const rpcvers_t versnum;       -- version number 	 * const char *uaddr;		  -- universal address of service          * const struct netconfig *nconf; -- netconfig structure          */
end_comment

begin_function_decl
specifier|extern
name|SVCXPRT
modifier|*
name|svc_dg_create
parameter_list|(
name|SVCPOOL
modifier|*
parameter_list|,
name|struct
name|socket
modifier|*
parameter_list|,
specifier|const
name|size_t
parameter_list|,
specifier|const
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*          * struct socket *;                             -- open connection          * const size_t sendsize;                        -- max send size          * const size_t recvsize;                        -- max recv size          */
end_comment

begin_function_decl
specifier|extern
name|SVCXPRT
modifier|*
name|svc_vc_create
parameter_list|(
name|SVCPOOL
modifier|*
parameter_list|,
name|struct
name|socket
modifier|*
parameter_list|,
specifier|const
name|size_t
parameter_list|,
specifier|const
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*          * struct socket *;                             -- open connection          * const size_t sendsize;                        -- max send size          * const size_t recvsize;                        -- max recv size          */
end_comment

begin_comment
comment|/*  * Generic TLI create routine  */
end_comment

begin_function_decl
specifier|extern
name|SVCXPRT
modifier|*
name|svc_tli_create
parameter_list|(
name|SVCPOOL
modifier|*
parameter_list|,
name|struct
name|socket
modifier|*
parameter_list|,
specifier|const
name|struct
name|netconfig
modifier|*
parameter_list|,
specifier|const
name|struct
name|t_bind
modifier|*
parameter_list|,
specifier|const
name|size_t
parameter_list|,
specifier|const
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *      struct socket * so;             -- connection end point  *      const struct netconfig *nconf;  -- netconfig structure for network  *      const struct t_bind *bindaddr;  -- local bind address  *      const size_t sendsz;             -- max sendsize  *      const size_t recvsz;             -- max recvsize  */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_comment
comment|/*  * Transport independent svc_create routine.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|svc_create
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|svc_req
modifier|*
parameter_list|,
name|SVCXPRT
modifier|*
parameter_list|)
parameter_list|,
specifier|const
name|rpcprog_t
parameter_list|,
specifier|const
name|rpcvers_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *      void (*dispatch)();             -- dispatch routine  *      const rpcprog_t prognum;        -- program number  *      const rpcvers_t versnum;        -- version number  *      const char *nettype;            -- network type  */
end_comment

begin_comment
comment|/*  * Generic server creation routine. It takes a netconfig structure  * instead of a nettype.  */
end_comment

begin_function_decl
specifier|extern
name|SVCXPRT
modifier|*
name|svc_tp_create
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|svc_req
modifier|*
parameter_list|,
name|SVCXPRT
modifier|*
parameter_list|)
parameter_list|,
specifier|const
name|rpcprog_t
parameter_list|,
specifier|const
name|rpcvers_t
parameter_list|,
specifier|const
name|struct
name|netconfig
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*          * void (*dispatch)();            -- dispatch routine          * const rpcprog_t prognum;       -- program number          * const rpcvers_t versnum;       -- version number          * const struct netconfig *nconf; -- netconfig structure          */
end_comment

begin_comment
comment|/*  * Generic TLI create routine  */
end_comment

begin_function_decl
specifier|extern
name|SVCXPRT
modifier|*
name|svc_tli_create
parameter_list|(
specifier|const
name|int
parameter_list|,
specifier|const
name|struct
name|netconfig
modifier|*
parameter_list|,
specifier|const
name|struct
name|t_bind
modifier|*
parameter_list|,
specifier|const
name|u_int
parameter_list|,
specifier|const
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *      const int fd;                   -- connection end point  *      const struct netconfig *nconf;  -- netconfig structure for network  *      const struct t_bind *bindaddr;  -- local bind address  *      const u_int sendsz;             -- max sendsize  *      const u_int recvsz;             -- max recvsize  */
end_comment

begin_comment
comment|/*  * Connectionless and connectionful create routines  */
end_comment

begin_function_decl
specifier|extern
name|SVCXPRT
modifier|*
name|svc_vc_create
parameter_list|(
specifier|const
name|int
parameter_list|,
specifier|const
name|u_int
parameter_list|,
specifier|const
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *      const int fd;                           -- open connection end point  *      const u_int sendsize;                   -- max send size  *      const u_int recvsize;                   -- max recv size  */
end_comment

begin_comment
comment|/*  * Added for compatibility to old rpc 4.0. Obsoleted by svc_vc_create().  */
end_comment

begin_function_decl
specifier|extern
name|SVCXPRT
modifier|*
name|svcunix_create
parameter_list|(
name|int
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|SVCXPRT
modifier|*
name|svc_dg_create
parameter_list|(
specifier|const
name|int
parameter_list|,
specifier|const
name|u_int
parameter_list|,
specifier|const
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*          * const int fd;                                -- open connection          * const u_int sendsize;                        -- max send size          * const u_int recvsize;                        -- max recv size          */
end_comment

begin_comment
comment|/*  * the routine takes any *open* connection  * descriptor as its first input and is used for open connections.  */
end_comment

begin_function_decl
specifier|extern
name|SVCXPRT
modifier|*
name|svc_fd_create
parameter_list|(
specifier|const
name|int
parameter_list|,
specifier|const
name|u_int
parameter_list|,
specifier|const
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *      const int fd;                           -- open connection end point  *      const u_int sendsize;                   -- max send size  *      const u_int recvsize;                   -- max recv size  */
end_comment

begin_comment
comment|/*  * Added for compatibility to old rpc 4.0. Obsoleted by svc_fd_create().  */
end_comment

begin_function_decl
specifier|extern
name|SVCXPRT
modifier|*
name|svcunixfd_create
parameter_list|(
name|int
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Memory based rpc (for speed check and testing)  */
end_comment

begin_function_decl
specifier|extern
name|SVCXPRT
modifier|*
name|svc_raw_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * svc_dg_enable_cache() enables the cache on dg transports.  */
end_comment

begin_function_decl
name|int
name|svc_dg_enablecache
parameter_list|(
name|SVCXPRT
modifier|*
parameter_list|,
specifier|const
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__rpc_get_local_uid
parameter_list|(
name|SVCXPRT
modifier|*
name|_transp
parameter_list|,
name|uid_t
modifier|*
name|_uid
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_macro
name|__END_DECLS
end_macro

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_comment
comment|/* for backward compatibility */
end_comment

begin_include
include|#
directive|include
file|<rpc/svc_soc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RPC_SVC_H */
end_comment

end_unit

