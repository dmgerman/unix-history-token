begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *  * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *  * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *  * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *  * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *  * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  *  *	from: @(#)svc.h 1.20 88/02/08 SMI  *	from: @(#)svc.h	2.2 88/07/29 4.0 RPCSRC  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * svc.h, Server-side remote procedure call interface.  *  * Copyright (C) 1984, Sun Microsystems, Inc.  */
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

begin_comment
comment|/*  * This interface must manage two items concerning remote procedure calling:  *  * 1) An arbitrary number of transport connections upon which rpc requests  * are received.  The two most notable transports are TCP and UDP;  they are  * created and registered by routines in svc_tcp.c and svc_udp.c, respectively;  * they in turn call xprt_register and xprt_unregister.  *  * 2) An arbitrary number of locally registered services.  Services are  * described by the following four data: program number, version number,  * "service dispatch" function, a transport handle, and a boolean that  * indicates whether or not the exported program should be registered with a  * local binder service;  if true the program's number and version and the  * port number from the transport handle are registered with the binder.  * These data are registered with the rpc svc system via svc_register.  *  * A service's dispatch function is called whenever an rpc request comes in  * on a transport.  The request's program and version numbers must match  * those of the registered service.  The dispatch function is passed two  * parameters, struct svc_req * and SVCXPRT *, defined below.  */
end_comment

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
name|rpc_msg
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Server side transport handle  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|__rpc_svcxprt
block|{
name|int
name|xp_sock
decl_stmt|;
name|u_short
name|xp_port
decl_stmt|;
comment|/* associated port number */
struct|struct
name|xp_ops
block|{
comment|/* receive incoming requests */
name|bool_t
argument_list|(
argument|*xp_recv
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|__rpc_svcxprt
operator|*
operator|,
expr|struct
name|rpc_msg
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* get transport status */
name|enum
name|xprt_stat
argument_list|(
operator|*
name|xp_stat
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|__rpc_svcxprt
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* get arguments */
name|bool_t
argument_list|(
argument|*xp_getargs
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|__rpc_svcxprt
operator|*
operator|,
name|xdrproc_t
operator|,
name|caddr_t
operator|)
argument_list|)
expr_stmt|;
comment|/* send reply */
name|bool_t
argument_list|(
argument|*xp_reply
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|__rpc_svcxprt
operator|*
operator|,
expr|struct
name|rpc_msg
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* free mem allocated for args */
name|bool_t
argument_list|(
argument|*xp_freeargs
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|__rpc_svcxprt
operator|*
operator|,
name|xdrproc_t
operator|,
name|caddr_t
operator|)
argument_list|)
expr_stmt|;
comment|/* destroy this struct */
name|void
argument_list|(
argument|*xp_destroy
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|__rpc_svcxprt
operator|*
operator|)
argument_list|)
expr_stmt|;
block|}
modifier|*
name|xp_ops
struct|;
name|int
name|xp_addrlen
decl_stmt|;
comment|/* length of remote address */
name|struct
name|sockaddr_in
name|xp_raddr
decl_stmt|;
comment|/* remote address */
name|struct
name|opaque_auth
name|xp_verf
decl_stmt|;
comment|/* raw response verifier */
name|caddr_t
name|xp_p1
decl_stmt|;
comment|/* private */
name|caddr_t
name|xp_p2
decl_stmt|;
comment|/* private */
block|}
name|SVCXPRT
typedef|;
end_typedef

begin_comment
comment|/*  *  Approved way of getting address of caller  */
end_comment

begin_define
define|#
directive|define
name|svc_getcaller
parameter_list|(
name|x
parameter_list|)
value|(&(x)->xp_raddr)
end_define

begin_comment
comment|/*  * Operations defined on an SVCXPRT handle  *  * SVCXPRT		*xprt;  * struct rpc_msg	*msg;  * xdrproc_t		 xargs;  * caddr_t		 argsp;  */
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

begin_comment
comment|/*  * Service request  */
end_comment

begin_struct
struct|struct
name|svc_req
block|{
name|u_int32_t
name|rq_prog
decl_stmt|;
comment|/* service program number */
name|u_int32_t
name|rq_vers
decl_stmt|;
comment|/* service protocol version */
name|u_int32_t
name|rq_proc
decl_stmt|;
comment|/* the desired procedure */
name|struct
name|opaque_auth
name|rq_cred
decl_stmt|;
comment|/* raw creds from the wire */
name|caddr_t
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
comment|/*  * Service registration  *  * svc_register(xprt, prog, vers, dispatch, protocol)  *	SVCXPRT *xprt;  *	u_long prog;  *	u_long vers;  *	void (*dispatch)();  *	int protocol;        (like TCP or UDP, zero means do not register)  */
end_comment

begin_decl_stmt
name|__BEGIN_DECLS
specifier|extern
name|bool_t
name|svc_register
name|__P
argument_list|(
operator|(
name|SVCXPRT
operator|*
operator|,
name|u_long
operator|,
name|u_long
operator|,
name|void
argument_list|(
argument|*
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|svc_req
operator|*
operator|,
name|SVCXPRT
operator|*
operator|)
argument_list|)
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__END_DECLS
comment|/*  * Service un-registration  *  * svc_unregister(prog, vers)  *	u_long prog;  *	u_long vers;  */
name|__BEGIN_DECLS
specifier|extern
name|void
name|svc_unregister
name|__P
argument_list|(
operator|(
name|u_long
operator|,
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__END_DECLS
comment|/*  * Transport registration.  *  * xprt_register(xprt)  *	SVCXPRT *xprt;  */
name|__BEGIN_DECLS
specifier|extern
name|void
name|xprt_register
name|__P
argument_list|(
operator|(
name|SVCXPRT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__END_DECLS
comment|/*  * Transport un-register  *  * xprt_unregister(xprt)  *	SVCXPRT *xprt;  */
name|__BEGIN_DECLS
specifier|extern
name|void
name|xprt_unregister
name|__P
argument_list|(
operator|(
name|SVCXPRT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__END_DECLS
comment|/*  * When the service routine is called, it must first check to see if it  * knows about the procedure;  if not, it should call svcerr_noproc  * and return.  If so, it should deserialize its arguments via  * SVC_GETARGS (defined above).  If the deserialization does not work,  * svcerr_decode should be called followed by a return.  Successful  * decoding of the arguments should be followed the execution of the  * procedure's code and a call to svc_sendreply.  *  * Also, if the service refuses to execute the procedure due to too-  * weak authentication parameters, svcerr_weakauth should be called.  * Note: do not confuse access-control failure with weak authentication!  *  * NB: In pure implementations of rpc, the caller always waits for a reply  * msg.  This message is sent when svc_sendreply is called.  * Therefore pure service implementations should always call  * svc_sendreply even if the function logically returns void;  use  * xdr.h - xdr_void for the xdr routine.  HOWEVER, tcp based rpc allows  * for the abuse of pure rpc via batched calling or pipelining.  In the  * case of a batched call, svc_sendreply should NOT be called since  * this would send a return message, which is what batching tries to avoid.  * It is the service/protocol writer's responsibility to know which calls are  * batched and which are not.  Warning: responding to batch calls may  * deadlock the caller and server processes!  */
name|__BEGIN_DECLS
specifier|extern
name|bool_t
name|svc_sendreply
name|__P
argument_list|(
operator|(
name|SVCXPRT
operator|*
operator|,
name|xdrproc_t
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|svcerr_decode
name|__P
argument_list|(
operator|(
name|SVCXPRT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|svcerr_weakauth
name|__P
argument_list|(
operator|(
name|SVCXPRT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|svcerr_noproc
name|__P
argument_list|(
operator|(
name|SVCXPRT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|svcerr_progvers
name|__P
argument_list|(
operator|(
name|SVCXPRT
operator|*
operator|,
name|u_long
operator|,
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|svcerr_auth
name|__P
argument_list|(
operator|(
name|SVCXPRT
operator|*
operator|,
expr|enum
name|auth_stat
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|svcerr_noprog
name|__P
argument_list|(
operator|(
name|SVCXPRT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|svcerr_systemerr
name|__P
argument_list|(
operator|(
name|SVCXPRT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__END_DECLS
comment|/*  * Lowest level dispatching -OR- who owns this process anyway.  * Somebody has to wait for incoming requests and then call the correct  * service routine.  The routine svc_run does infinite waiting; i.e.,  * svc_run never returns.  * Since another (co-existant) package may wish to selectively wait for  * incoming calls or other events outside of the rpc architecture, the  * routine svc_getreq is provided.  It must be passed readfds, the  * "in-place" results of a select system call (see select, section 2).  */
comment|/*  * Global keeper of rpc service descriptors in use  * dynamic; must be inspected before each call to select  */
specifier|extern
name|int
name|svc_maxfd
decl_stmt|;
end_decl_stmt

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

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_comment
comment|/*  * a small program implemented by the svc_rpc implementation itself;  * also see clnt.h for protocol numbers.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|rpctest_service
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|__BEGIN_DECLS
specifier|extern
name|void
name|svc_getreq
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|svc_getreqset
name|__P
argument_list|(
operator|(
name|fd_set
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|svc_getreqset2
name|__P
argument_list|(
operator|(
name|fd_set
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX: nonstd, undoc */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|svc_run
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__END_DECLS
comment|/*  * Socket to use on svcxxx_create call to get default socket  */
define|#
directive|define
name|RPC_ANYSOCK
value|-1
comment|/*  * These are the existing service side transport implementations  */
comment|/*  * Memory based rpc for testing and timing.  */
name|__BEGIN_DECLS
specifier|extern
name|SVCXPRT
modifier|*
name|svcraw_create
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__END_DECLS
comment|/*  * Udp based rpc.  */
name|__BEGIN_DECLS
specifier|extern
name|SVCXPRT
modifier|*
name|svcudp_create
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SVCXPRT
modifier|*
name|svcudp_bufcreate
name|__P
argument_list|(
operator|(
name|int
operator|,
name|u_int
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__END_DECLS
comment|/*  * Tcp based rpc.  */
name|__BEGIN_DECLS
specifier|extern
name|SVCXPRT
modifier|*
name|svctcp_create
name|__P
argument_list|(
operator|(
name|int
operator|,
name|u_int
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SVCXPRT
modifier|*
name|svcfd_create
name|__P
argument_list|(
operator|(
name|int
operator|,
name|u_int
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__END_DECLS
comment|/*  * AF_UNIX socket based rpc.  */
name|__BEGIN_DECLS
specifier|extern
name|SVCXPRT
modifier|*
name|svcunix_create
name|__P
argument_list|(
operator|(
name|int
operator|,
name|u_int
operator|,
name|u_int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SVCXPRT
modifier|*
name|svcunixfd_create
name|__P
argument_list|(
operator|(
name|int
operator|,
name|u_int
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RPC_SVC_H */
end_comment

end_unit

