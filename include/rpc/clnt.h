begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: clnt.h,v 1.14 2000/06/02 22:57:55 fvdl Exp $	*/
end_comment

begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *  * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *  * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *  * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *  * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *  * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  *  *	from: @(#)clnt.h 1.31 94/04/29 SMI  *	from: @(#)clnt.h	2.1 88/07/29 4.0 RPCSRC  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * clnt.h - Client side remote procedure call interface.  *  * Copyright (C) 1984, Sun Microsystems, Inc.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RPC_CLNT_H_
end_ifndef

begin_define
define|#
directive|define
name|_RPC_CLNT_H_
end_define

begin_include
include|#
directive|include
file|<rpc/clnt_stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<netconfig.h>
end_include

begin_include
include|#
directive|include
file|<sys/un.h>
end_include

begin_comment
comment|/*  * Well-known IPV6 RPC broadcast address.  */
end_comment

begin_define
define|#
directive|define
name|RPCB_MULTICAST_ADDR
value|"ff02::202"
end_define

begin_comment
comment|/*  * the following errors are in general unrecoverable.  The caller  * should give up rather than retry.  */
end_comment

begin_define
define|#
directive|define
name|IS_UNRECOVERABLE_RPC
parameter_list|(
name|s
parameter_list|)
value|(((s) == RPC_AUTHERROR) || \ 	((s) == RPC_CANTENCODEARGS) || \ 	((s) == RPC_CANTDECODERES) || \ 	((s) == RPC_VERSMISMATCH) || \ 	((s) == RPC_PROCUNAVAIL) || \ 	((s) == RPC_PROGUNAVAIL) || \ 	((s) == RPC_PROGVERSMISMATCH) || \ 	((s) == RPC_CANTDECODEARGS))
end_define

begin_comment
comment|/*  * Error info.  */
end_comment

begin_struct
struct|struct
name|rpc_err
block|{
name|enum
name|clnt_stat
name|re_status
decl_stmt|;
union|union
block|{
name|int
name|RE_errno
decl_stmt|;
comment|/* related system error */
name|enum
name|auth_stat
name|RE_why
decl_stmt|;
comment|/* why the auth error occurred */
struct|struct
block|{
name|rpcvers_t
name|low
decl_stmt|;
comment|/* lowest version supported */
name|rpcvers_t
name|high
decl_stmt|;
comment|/* highest version supported */
block|}
name|RE_vers
struct|;
struct|struct
block|{
comment|/* maybe meaningful if RPC_FAILED */
name|int32_t
name|s1
decl_stmt|;
name|int32_t
name|s2
decl_stmt|;
block|}
name|RE_lb
struct|;
comment|/* life boot& debugging only */
block|}
name|ru
union|;
define|#
directive|define
name|re_errno
value|ru.RE_errno
define|#
directive|define
name|re_why
value|ru.RE_why
define|#
directive|define
name|re_vers
value|ru.RE_vers
define|#
directive|define
name|re_lb
value|ru.RE_lb
block|}
struct|;
end_struct

begin_comment
comment|/*  * Client rpc handle.  * Created by individual implementations  * Client is responsible for initializing auth, see e.g. auth_none.c.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|__rpc_client
block|{
name|AUTH
modifier|*
name|cl_auth
decl_stmt|;
comment|/* authenticator */
struct|struct
name|clnt_ops
block|{
comment|/* call remote procedure */
name|enum
name|clnt_stat
function_decl|(
modifier|*
name|cl_call
function_decl|)
parameter_list|(
name|struct
name|__rpc_client
modifier|*
parameter_list|,
name|rpcproc_t
parameter_list|,
name|xdrproc_t
parameter_list|,
name|caddr_t
parameter_list|,
name|xdrproc_t
parameter_list|,
name|caddr_t
parameter_list|,
name|struct
name|timeval
parameter_list|)
function_decl|;
comment|/* abort a call */
name|void
function_decl|(
modifier|*
name|cl_abort
function_decl|)
parameter_list|(
name|struct
name|__rpc_client
modifier|*
parameter_list|)
function_decl|;
comment|/* get specific error code */
name|void
function_decl|(
modifier|*
name|cl_geterr
function_decl|)
parameter_list|(
name|struct
name|__rpc_client
modifier|*
parameter_list|,
name|struct
name|rpc_err
modifier|*
parameter_list|)
function_decl|;
comment|/* frees results */
name|bool_t
function_decl|(
modifier|*
name|cl_freeres
function_decl|)
parameter_list|(
name|struct
name|__rpc_client
modifier|*
parameter_list|,
name|xdrproc_t
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
comment|/* destroy this structure */
name|void
function_decl|(
modifier|*
name|cl_destroy
function_decl|)
parameter_list|(
name|struct
name|__rpc_client
modifier|*
parameter_list|)
function_decl|;
comment|/* the ioctl() of rpc */
name|bool_t
function_decl|(
modifier|*
name|cl_control
function_decl|)
parameter_list|(
name|struct
name|__rpc_client
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
block|}
modifier|*
name|cl_ops
struct|;
name|void
modifier|*
name|cl_private
decl_stmt|;
comment|/* private stuff */
name|char
modifier|*
name|cl_netid
decl_stmt|;
comment|/* network token */
name|char
modifier|*
name|cl_tp
decl_stmt|;
comment|/* device name */
block|}
name|CLIENT
typedef|;
end_typedef

begin_comment
comment|/*  * Timers used for the pseudo-transport protocol when using datagrams  */
end_comment

begin_struct
struct|struct
name|rpc_timers
block|{
name|u_short
name|rt_srtt
decl_stmt|;
comment|/* smoothed round-trip time */
name|u_short
name|rt_deviate
decl_stmt|;
comment|/* estimated deviation */
name|u_long
name|rt_rtxcur
decl_stmt|;
comment|/* current (backed-off) rto */
block|}
struct|;
end_struct

begin_comment
comment|/*        * Feedback values used for possible congestion and rate control  */
end_comment

begin_define
define|#
directive|define
name|FEEDBACK_REXMIT1
value|1
end_define

begin_comment
comment|/* first retransmit */
end_comment

begin_define
define|#
directive|define
name|FEEDBACK_OK
value|2
end_define

begin_comment
comment|/* no retransmits */
end_comment

begin_comment
comment|/* Used to set version of portmapper used in broadcast */
end_comment

begin_define
define|#
directive|define
name|CLCR_SET_LOWVERS
value|3
end_define

begin_define
define|#
directive|define
name|CLCR_GET_LOWVERS
value|4
end_define

begin_define
define|#
directive|define
name|RPCSMALLMSGSIZE
value|400
end_define

begin_comment
comment|/* a more reasonable packet size */
end_comment

begin_comment
comment|/*  * client side rpc interface ops  *  * Parameter types are:  *  */
end_comment

begin_comment
comment|/*  * enum clnt_stat  * CLNT_CALL(rh, proc, xargs, argsp, xres, resp, timeout)  * 	CLIENT *rh;  *	rpcproc_t proc;  *	xdrproc_t xargs;  *	caddr_t argsp;  *	xdrproc_t xres;  *	caddr_t resp;  *	struct timeval timeout;  */
end_comment

begin_define
define|#
directive|define
name|CLNT_CALL
parameter_list|(
name|rh
parameter_list|,
name|proc
parameter_list|,
name|xargs
parameter_list|,
name|argsp
parameter_list|,
name|xres
parameter_list|,
name|resp
parameter_list|,
name|secs
parameter_list|)
define|\
value|((*(rh)->cl_ops->cl_call)(rh, proc, xargs, \ 		(caddr_t)(void *)argsp,	xres, (caddr_t)(void *)resp, secs))
end_define

begin_define
define|#
directive|define
name|clnt_call
parameter_list|(
name|rh
parameter_list|,
name|proc
parameter_list|,
name|xargs
parameter_list|,
name|argsp
parameter_list|,
name|xres
parameter_list|,
name|resp
parameter_list|,
name|secs
parameter_list|)
define|\
value|((*(rh)->cl_ops->cl_call)(rh, proc, xargs, \ 		(caddr_t)(void *)argsp, xres, (caddr_t)(void *)resp, secs))
end_define

begin_comment
comment|/*  * void  * CLNT_ABORT(rh);  * 	CLIENT *rh;  */
end_comment

begin_define
define|#
directive|define
name|CLNT_ABORT
parameter_list|(
name|rh
parameter_list|)
value|((*(rh)->cl_ops->cl_abort)(rh))
end_define

begin_define
define|#
directive|define
name|clnt_abort
parameter_list|(
name|rh
parameter_list|)
value|((*(rh)->cl_ops->cl_abort)(rh))
end_define

begin_comment
comment|/*  * struct rpc_err  * CLNT_GETERR(rh);  * 	CLIENT *rh;  */
end_comment

begin_define
define|#
directive|define
name|CLNT_GETERR
parameter_list|(
name|rh
parameter_list|,
name|errp
parameter_list|)
value|((*(rh)->cl_ops->cl_geterr)(rh, errp))
end_define

begin_define
define|#
directive|define
name|clnt_geterr
parameter_list|(
name|rh
parameter_list|,
name|errp
parameter_list|)
value|((*(rh)->cl_ops->cl_geterr)(rh, errp))
end_define

begin_comment
comment|/*  * bool_t  * CLNT_FREERES(rh, xres, resp);  * 	CLIENT *rh;  *	xdrproc_t xres;  *	caddr_t resp;  */
end_comment

begin_define
define|#
directive|define
name|CLNT_FREERES
parameter_list|(
name|rh
parameter_list|,
name|xres
parameter_list|,
name|resp
parameter_list|)
value|((*(rh)->cl_ops->cl_freeres)(rh,xres,resp))
end_define

begin_define
define|#
directive|define
name|clnt_freeres
parameter_list|(
name|rh
parameter_list|,
name|xres
parameter_list|,
name|resp
parameter_list|)
value|((*(rh)->cl_ops->cl_freeres)(rh,xres,resp))
end_define

begin_comment
comment|/*  * bool_t  * CLNT_CONTROL(cl, request, info)  *      CLIENT *cl;  *      u_int request;  *      char *info;  */
end_comment

begin_define
define|#
directive|define
name|CLNT_CONTROL
parameter_list|(
name|cl
parameter_list|,
name|rq
parameter_list|,
name|in
parameter_list|)
value|((*(cl)->cl_ops->cl_control)(cl,rq,in))
end_define

begin_define
define|#
directive|define
name|clnt_control
parameter_list|(
name|cl
parameter_list|,
name|rq
parameter_list|,
name|in
parameter_list|)
value|((*(cl)->cl_ops->cl_control)(cl,rq,in))
end_define

begin_comment
comment|/*  * control operations that apply to both udp and tcp transports  */
end_comment

begin_define
define|#
directive|define
name|CLSET_TIMEOUT
value|1
end_define

begin_comment
comment|/* set timeout (timeval) */
end_comment

begin_define
define|#
directive|define
name|CLGET_TIMEOUT
value|2
end_define

begin_comment
comment|/* get timeout (timeval) */
end_comment

begin_define
define|#
directive|define
name|CLGET_SERVER_ADDR
value|3
end_define

begin_comment
comment|/* get server's address (sockaddr) */
end_comment

begin_define
define|#
directive|define
name|CLGET_FD
value|6
end_define

begin_comment
comment|/* get connections file descriptor */
end_comment

begin_define
define|#
directive|define
name|CLGET_SVC_ADDR
value|7
end_define

begin_comment
comment|/* get server's address (netbuf) */
end_comment

begin_define
define|#
directive|define
name|CLSET_FD_CLOSE
value|8
end_define

begin_comment
comment|/* close fd while clnt_destroy */
end_comment

begin_define
define|#
directive|define
name|CLSET_FD_NCLOSE
value|9
end_define

begin_comment
comment|/* Do not close fd while clnt_destroy */
end_comment

begin_define
define|#
directive|define
name|CLGET_XID
value|10
end_define

begin_comment
comment|/* Get xid */
end_comment

begin_define
define|#
directive|define
name|CLSET_XID
value|11
end_define

begin_comment
comment|/* Set xid */
end_comment

begin_define
define|#
directive|define
name|CLGET_VERS
value|12
end_define

begin_comment
comment|/* Get version number */
end_comment

begin_define
define|#
directive|define
name|CLSET_VERS
value|13
end_define

begin_comment
comment|/* Set version number */
end_comment

begin_define
define|#
directive|define
name|CLGET_PROG
value|14
end_define

begin_comment
comment|/* Get program number */
end_comment

begin_define
define|#
directive|define
name|CLSET_PROG
value|15
end_define

begin_comment
comment|/* Set program number */
end_comment

begin_define
define|#
directive|define
name|CLSET_SVC_ADDR
value|16
end_define

begin_comment
comment|/* get server's address (netbuf) */
end_comment

begin_define
define|#
directive|define
name|CLSET_PUSH_TIMOD
value|17
end_define

begin_comment
comment|/* push timod if not already present */
end_comment

begin_define
define|#
directive|define
name|CLSET_POP_TIMOD
value|18
end_define

begin_comment
comment|/* pop timod */
end_comment

begin_comment
comment|/*  * Connectionless only control operations  */
end_comment

begin_define
define|#
directive|define
name|CLSET_RETRY_TIMEOUT
value|4
end_define

begin_comment
comment|/* set retry timeout (timeval) */
end_comment

begin_define
define|#
directive|define
name|CLGET_RETRY_TIMEOUT
value|5
end_define

begin_comment
comment|/* get retry timeout (timeval) */
end_comment

begin_define
define|#
directive|define
name|CLSET_ASYNC
value|19
end_define

begin_define
define|#
directive|define
name|CLSET_CONNECT
value|20
end_define

begin_comment
comment|/* Use connect() for UDP. (int) */
end_comment

begin_comment
comment|/*  * void  * CLNT_DESTROY(rh);  * 	CLIENT *rh;  */
end_comment

begin_define
define|#
directive|define
name|CLNT_DESTROY
parameter_list|(
name|rh
parameter_list|)
value|((*(rh)->cl_ops->cl_destroy)(rh))
end_define

begin_define
define|#
directive|define
name|clnt_destroy
parameter_list|(
name|rh
parameter_list|)
value|((*(rh)->cl_ops->cl_destroy)(rh))
end_define

begin_comment
comment|/*  * RPCTEST is a test program which is accessible on every rpc  * transport/port.  It is used for testing, performance evaluation,  * and network administration.  */
end_comment

begin_define
define|#
directive|define
name|RPCTEST_PROGRAM
value|((rpcprog_t)1)
end_define

begin_define
define|#
directive|define
name|RPCTEST_VERSION
value|((rpcvers_t)1)
end_define

begin_define
define|#
directive|define
name|RPCTEST_NULL_PROC
value|((rpcproc_t)2)
end_define

begin_define
define|#
directive|define
name|RPCTEST_NULL_BATCH_PROC
value|((rpcproc_t)3)
end_define

begin_comment
comment|/*  * By convention, procedure 0 takes null arguments and returns them  */
end_comment

begin_define
define|#
directive|define
name|NULLPROC
value|((rpcproc_t)0)
end_define

begin_comment
comment|/*  * Below are the client handle creation routines for the various  * implementations of client side rpc.  They can return NULL if a  * creation failure occurs.  */
end_comment

begin_comment
comment|/*  * Generic client creation routine. Supported protocols are those that  * belong to the nettype namespace (/etc/netconfig).  * CLIENT *  * clnt_create(host, prog, vers, prot);  *	const char *host; 	-- hostname  *	const rpcprog_t prog;	-- program number  *	const rpcvers_t vers;	-- version number  *	const char *prot;	-- protocol  */
end_comment

begin_function_decl
name|__BEGIN_DECLS
specifier|extern
name|CLIENT
modifier|*
name|clnt_create
parameter_list|(
specifier|const
name|char
modifier|*
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
comment|/*  *  * 	const char *hostname;			-- hostname  *	const rpcprog_t prog;			-- program number  *	const rpcvers_t vers;			-- version number  *	const char *nettype;			-- network type  */
end_comment

begin_comment
comment|/*  * Generic client creation routine. Supported protocols are which belong  * to the nettype name space.  */
end_comment

begin_function_decl
specifier|extern
name|CLIENT
modifier|*
name|clnt_create_vers
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|rpcprog_t
parameter_list|,
name|rpcvers_t
modifier|*
parameter_list|,
specifier|const
name|rpcvers_t
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
comment|/*  *	const char *host;		-- hostname  *	const rpcprog_t prog;		-- program number  *	rpcvers_t *vers_out;		-- servers highest available version  *	const rpcvers_t vers_low;	-- low version number  *	const rpcvers_t vers_high;	-- high version number  *	const char *nettype;		-- network type  */
end_comment

begin_comment
comment|/*  * Generic client creation routine. It takes a netconfig structure  * instead of nettype  */
end_comment

begin_function_decl
specifier|extern
name|CLIENT
modifier|*
name|clnt_tp_create
parameter_list|(
specifier|const
name|char
modifier|*
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
comment|/*  *	const char *hostname;			-- hostname  *	const rpcprog_t prog;			-- program number  *	const rpcvers_t vers;			-- version number  *	const struct netconfig *netconf; 	-- network config structure  */
end_comment

begin_comment
comment|/*  * Generic TLI create routine. Only provided for compatibility.  */
end_comment

begin_function_decl
specifier|extern
name|CLIENT
modifier|*
name|clnt_tli_create
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
name|netbuf
modifier|*
parameter_list|,
specifier|const
name|rpcprog_t
parameter_list|,
specifier|const
name|rpcvers_t
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
comment|/*  *	const register int fd;		-- fd  *	const struct netconfig *nconf;	-- netconfig structure  *	const struct netbuf *svcaddr;		-- servers address  *	const u_long prog;			-- program number  *	const u_long vers;			-- version number  *	const u_int sendsz;			-- send size  *	const u_int recvsz;			-- recv size  */
end_comment

begin_comment
comment|/*  * Low level clnt create routine for connectionful transports, e.g. tcp.  */
end_comment

begin_function_decl
specifier|extern
name|CLIENT
modifier|*
name|clnt_vc_create
parameter_list|(
specifier|const
name|int
parameter_list|,
specifier|const
name|struct
name|netbuf
modifier|*
parameter_list|,
specifier|const
name|rpcprog_t
parameter_list|,
specifier|const
name|rpcvers_t
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
comment|/*  * Added for compatibility to old rpc 4.0. Obsoleted by clnt_vc_create().  */
end_comment

begin_function_decl
specifier|extern
name|CLIENT
modifier|*
name|clntunix_create
parameter_list|(
name|struct
name|sockaddr_un
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|,
name|int
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	const int fd;				-- open file descriptor  *	const struct netbuf *svcaddr;		-- servers address  *	const rpcprog_t prog;			-- program number  *	const rpcvers_t vers;			-- version number  *	const u_int sendsz;			-- buffer recv size  *	const u_int recvsz;			-- buffer send size  */
end_comment

begin_comment
comment|/*  * Low level clnt create routine for connectionless transports, e.g. udp.  */
end_comment

begin_function_decl
specifier|extern
name|CLIENT
modifier|*
name|clnt_dg_create
parameter_list|(
specifier|const
name|int
parameter_list|,
specifier|const
name|struct
name|netbuf
modifier|*
parameter_list|,
specifier|const
name|rpcprog_t
parameter_list|,
specifier|const
name|rpcvers_t
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
comment|/*  *	const int fd;				-- open file descriptor  *	const struct netbuf *svcaddr;		-- servers address  *	const rpcprog_t program;		-- program number  *	const rpcvers_t version;		-- version number  *	const u_int sendsz;			-- buffer recv size  *	const u_int recvsz;			-- buffer send size  */
end_comment

begin_comment
comment|/*  * Memory based rpc (for speed check and testing)  * CLIENT *  * clnt_raw_create(prog, vers)  *	u_long prog;  *	u_long vers;  */
end_comment

begin_function_decl
specifier|extern
name|CLIENT
modifier|*
name|clnt_raw_create
parameter_list|(
name|rpcprog_t
parameter_list|,
name|rpcvers_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__END_DECLS
comment|/*  * Print why creation failed  */
name|__BEGIN_DECLS
specifier|extern
name|void
name|clnt_pcreateerror
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* stderr */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|clnt_spcreateerror
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* string */
end_comment

begin_function_decl
name|__END_DECLS
comment|/*  * Like clnt_perror(), but is more verbose in its output  */
name|__BEGIN_DECLS
specifier|extern
name|void
name|clnt_perrno
parameter_list|(
name|enum
name|clnt_stat
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* stderr */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|clnt_sperrno
parameter_list|(
name|enum
name|clnt_stat
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* string */
end_comment

begin_function_decl
name|__END_DECLS
comment|/*  * Print an English error message, given the client error code  */
name|__BEGIN_DECLS
specifier|extern
name|void
name|clnt_perror
parameter_list|(
name|CLIENT
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* stderr */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|clnt_sperror
parameter_list|(
name|CLIENT
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* string */
end_comment

begin_macro
name|__END_DECLS
end_macro

begin_comment
comment|/*  * If a creation fails, the following allows the user to figure out why.  */
end_comment

begin_struct
struct|struct
name|rpc_createerr
block|{
name|enum
name|clnt_stat
name|cf_stat
decl_stmt|;
name|struct
name|rpc_err
name|cf_error
decl_stmt|;
comment|/* useful when cf_stat == RPC_PMAPFAILURE */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_THREAD_SAFE
end_ifdef

begin_expr_stmt
name|__BEGIN_DECLS
specifier|extern
expr|struct
name|rpc_createerr
operator|*
name|__rpc_createerr
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__END_DECLS
define|#
directive|define
name|rpc_createerr
value|(*(__rpc_createerr()))
else|#
directive|else
specifier|extern
expr|struct
name|rpc_createerr
name|rpc_createerr
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _THREAD_SAFE */
end_comment

begin_comment
comment|/*  * The simplified interface:  * enum clnt_stat  * rpc_call(host, prognum, versnum, procnum, inproc, in, outproc, out, nettype)  *	const char *host;  *	const rpcprog_t prognum;  *	const rpcvers_t versnum;  *	const rpcproc_t procnum;  *	const xdrproc_t inproc, outproc;  *	const char *in;  *	char *out;  *	const char *nettype;  */
end_comment

begin_function_decl
name|__BEGIN_DECLS
specifier|extern
name|enum
name|clnt_stat
name|rpc_call
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|rpcprog_t
parameter_list|,
specifier|const
name|rpcvers_t
parameter_list|,
specifier|const
name|rpcproc_t
parameter_list|,
specifier|const
name|xdrproc_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|xdrproc_t
parameter_list|,
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_comment
comment|/*  * RPC broadcast interface  * The call is broadcasted to all locally connected nets.  *  * extern enum clnt_stat  * rpc_broadcast(prog, vers, proc, xargs, argsp, xresults, resultsp,  *			eachresult, nettype)  *	const rpcprog_t		prog;		-- program number  *	const rpcvers_t		vers;		-- version number  *	const rpcproc_t		proc;		-- procedure number  *	const xdrproc_t	xargs;		-- xdr routine for args  *	caddr_t		argsp;		-- pointer to args  *	const xdrproc_t	xresults;	-- xdr routine for results  *	caddr_t		resultsp;	-- pointer to results  *	const resultproc_t	eachresult;	-- call with each result  *	const char		*nettype;	-- Transport type  *  * For each valid response received, the procedure eachresult is called.  * Its form is:  *		done = eachresult(resp, raddr, nconf)  *			bool_t done;  *			caddr_t resp;  *			struct netbuf *raddr;  *			struct netconfig *nconf;  * where resp points to the results of the call and raddr is the  * address if the responder to the broadcast.  nconf is the transport  * on which the response was received.  *  * extern enum clnt_stat  * rpc_broadcast_exp(prog, vers, proc, xargs, argsp, xresults, resultsp,  *			eachresult, inittime, waittime, nettype)  *	const rpcprog_t		prog;		-- program number  *	const rpcvers_t		vers;		-- version number  *	const rpcproc_t		proc;		-- procedure number  *	const xdrproc_t	xargs;		-- xdr routine for args  *	caddr_t		argsp;		-- pointer to args  *	const xdrproc_t	xresults;	-- xdr routine for results  *	caddr_t		resultsp;	-- pointer to results  *	const resultproc_t	eachresult;	-- call with each result  *	const int 		inittime;	-- how long to wait initially  *	const int 		waittime;	-- maximum time to wait  *	const char		*nettype;	-- Transport type  */
end_comment

begin_typedef
typedef|typedef
name|bool_t
function_decl|(
modifier|*
name|resultproc_t
function_decl|)
parameter_list|(
name|caddr_t
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|__BEGIN_DECLS
specifier|extern
name|enum
name|clnt_stat
name|rpc_broadcast
parameter_list|(
specifier|const
name|rpcprog_t
parameter_list|,
specifier|const
name|rpcvers_t
parameter_list|,
specifier|const
name|rpcproc_t
parameter_list|,
specifier|const
name|xdrproc_t
parameter_list|,
name|caddr_t
parameter_list|,
specifier|const
name|xdrproc_t
parameter_list|,
name|caddr_t
parameter_list|,
specifier|const
name|resultproc_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|enum
name|clnt_stat
name|rpc_broadcast_exp
parameter_list|(
specifier|const
name|rpcprog_t
parameter_list|,
specifier|const
name|rpcvers_t
parameter_list|,
specifier|const
name|rpcproc_t
parameter_list|,
specifier|const
name|xdrproc_t
parameter_list|,
name|caddr_t
parameter_list|,
specifier|const
name|xdrproc_t
parameter_list|,
name|caddr_t
parameter_list|,
specifier|const
name|resultproc_t
parameter_list|,
specifier|const
name|int
parameter_list|,
specifier|const
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_comment
comment|/* For backward compatibility */
end_comment

begin_include
include|#
directive|include
file|<rpc/clnt_soc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RPC_CLNT_H_ */
end_comment

end_unit

