begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *  * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *  * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *  * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *  * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *  * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  *  *	from: @(#)clnt.h 1.31 88/02/08 SMI  *	from: @(#)clnt.h	2.1 88/07/29 4.0 RPCSRC  * $FreeBSD$  */
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
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/un.h>
end_include

begin_comment
comment|/*  * Rpc calls return an enum clnt_stat.  This should be looked at more,  * since each implementation is required to live with this (implementation  * independent) list of errors.  */
end_comment

begin_enum
enum|enum
name|clnt_stat
block|{
name|RPC_SUCCESS
init|=
literal|0
block|,
comment|/* call succeeded */
comment|/* 	 * local errors 	 */
name|RPC_CANTENCODEARGS
init|=
literal|1
block|,
comment|/* can't encode arguments */
name|RPC_CANTDECODERES
init|=
literal|2
block|,
comment|/* can't decode results */
name|RPC_CANTSEND
init|=
literal|3
block|,
comment|/* failure in sending call */
name|RPC_CANTRECV
init|=
literal|4
block|,
comment|/* failure in receiving result */
name|RPC_TIMEDOUT
init|=
literal|5
block|,
comment|/* call timed out */
comment|/* 	 * remote errors 	 */
name|RPC_VERSMISMATCH
init|=
literal|6
block|,
comment|/* rpc versions not compatible */
name|RPC_AUTHERROR
init|=
literal|7
block|,
comment|/* authentication error */
name|RPC_PROGUNAVAIL
init|=
literal|8
block|,
comment|/* program not available */
name|RPC_PROGVERSMISMATCH
init|=
literal|9
block|,
comment|/* program version mismatched */
name|RPC_PROCUNAVAIL
init|=
literal|10
block|,
comment|/* procedure unavailable */
name|RPC_CANTDECODEARGS
init|=
literal|11
block|,
comment|/* decode arguments error */
name|RPC_SYSTEMERROR
init|=
literal|12
block|,
comment|/* generic "other problem" */
comment|/* 	 * callrpc& clnt_create errors 	 */
name|RPC_UNKNOWNHOST
init|=
literal|13
block|,
comment|/* unknown host name */
name|RPC_UNKNOWNPROTO
init|=
literal|17
block|,
comment|/* unkown protocol */
comment|/* 	 * _ create errors 	 */
name|RPC_PMAPFAILURE
init|=
literal|14
block|,
comment|/* the pmapper failed in its call */
name|RPC_PROGNOTREGISTERED
init|=
literal|15
block|,
comment|/* remote program is not registered */
comment|/* 	 * unspecified error 	 */
name|RPC_FAILED
init|=
literal|16
block|}
enum|;
end_enum

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
name|u_int32_t
name|low
decl_stmt|;
comment|/* lowest verion supported */
name|u_int32_t
name|high
decl_stmt|;
comment|/* highest verion supported */
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
comment|/*  * Client rpc handle.  * Created by individual implementations, see e.g. rpc_udp.c.  * Client is responsible for initializing auth, see e.g. auth_none.c.  */
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
argument_list|(
operator|*
name|cl_call
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|__rpc_client
operator|*
operator|,
name|u_long
operator|,
name|xdrproc_t
operator|,
name|caddr_t
operator|,
name|xdrproc_t
operator|,
name|caddr_t
operator|,
expr|struct
name|timeval
operator|)
argument_list|)
decl_stmt|;
comment|/* abort a call */
name|void
argument_list|(
argument|*cl_abort
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|__rpc_client
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* get specific error code */
name|void
argument_list|(
argument|*cl_geterr
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|__rpc_client
operator|*
operator|,
expr|struct
name|rpc_err
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* frees results */
name|bool_t
argument_list|(
argument|*cl_freeres
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|__rpc_client
operator|*
operator|,
name|xdrproc_t
operator|,
name|caddr_t
operator|)
argument_list|)
expr_stmt|;
comment|/* destroy this structure */
name|void
argument_list|(
argument|*cl_destroy
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|__rpc_client
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* the ioctl() of rpc */
name|bool_t
argument_list|(
argument|*cl_control
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|__rpc_client
operator|*
operator|,
name|u_int
operator|,
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
block|}
modifier|*
name|cl_ops
struct|;
name|caddr_t
name|cl_private
decl_stmt|;
comment|/* private stuff */
block|}
name|CLIENT
typedef|;
end_typedef

begin_comment
comment|/*  * client side rpc interface ops  *  * Parameter types are:  *  */
end_comment

begin_comment
comment|/*  * enum clnt_stat  * CLNT_CALL(rh, proc, xargs, argsp, xres, resp, timeout)  * 	CLIENT *rh;  *	u_long proc;  *	xdrproc_t xargs;  *	caddr_t argsp;  *	xdrproc_t xres;  *	caddr_t resp;  *	struct timeval timeout;  */
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
value|((*(rh)->cl_ops->cl_call)(rh, proc, xargs, (caddr_t)argsp, \ 		xres, (caddr_t)resp, secs))
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
value|((*(rh)->cl_ops->cl_call)(rh, proc, xargs, (caddr_t)argsp, \ 		xres, (caddr_t)resp, secs))
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
comment|/*  * control operations that apply to udp, tcp and unix transports  *  * Note: options marked XXX are no-ops in this implementation of RPC.  * The are present in TI-RPC but can't be implemented here since they  * depend on the presence of STREAMS/TLI, which we don't have.  *  */
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
comment|/* get server's address (netbuf)         XXX */
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
comment|/* get server's address (netbuf)         XXX */
end_comment

begin_define
define|#
directive|define
name|CLSET_PUSH_TIMOD
value|17
end_define

begin_comment
comment|/* push timod if not already present     XXX */
end_comment

begin_define
define|#
directive|define
name|CLSET_POP_TIMOD
value|18
end_define

begin_comment
comment|/* pop timod                             XXX */
end_comment

begin_comment
comment|/*  * udp only control operations  */
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
name|CLSET_CONNECT
value|20
end_define

begin_comment
comment|/* Use connect() for UDP. (int) */
end_comment

begin_comment
comment|/*  * Operations which GSSAPI needs. (Bletch.)  */
end_comment

begin_define
define|#
directive|define
name|CLGET_LOCAL_ADDR
value|19
end_define

begin_comment
comment|/* get local addr (sockaddr) */
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
value|((u_long)1)
end_define

begin_define
define|#
directive|define
name|RPCTEST_VERSION
value|((u_long)1)
end_define

begin_define
define|#
directive|define
name|RPCTEST_NULL_PROC
value|((u_long)2)
end_define

begin_define
define|#
directive|define
name|RPCTEST_NULL_BATCH_PROC
value|((u_long)3)
end_define

begin_comment
comment|/*  * By convention, procedure 0 takes null arguments and returns them  */
end_comment

begin_define
define|#
directive|define
name|NULLPROC
value|((u_long)0)
end_define

begin_comment
comment|/*  * Below are the client handle creation routines for the various  * implementations of client side rpc.  They can return NULL if a  * creation failure occurs.  */
end_comment

begin_comment
comment|/*  * Memory based rpc (for speed check and testing)  * CLIENT *  * clntraw_create(prog, vers)  *	u_long prog;  *	u_long vers;  */
end_comment

begin_decl_stmt
name|__BEGIN_DECLS
specifier|extern
name|CLIENT
modifier|*
name|clntraw_create
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
comment|/*  * Generic client creation routine. Supported protocols are "udp", "tcp"  * and "unix".  * CLIENT *  * clnt_create(host, prog, vers, prot);  *	char *host; 	-- hostname  *	u_long prog;	-- program number  *	u_long vers;	-- version number  *	char *prot;	-- protocol  */
name|__BEGIN_DECLS
specifier|extern
name|CLIENT
modifier|*
name|clnt_create
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|u_long
operator|,
name|u_long
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__END_DECLS
comment|/*  * TCP based rpc  * CLIENT *  * clnttcp_create(raddr, prog, vers, sockp, sendsz, recvsz)  *	struct sockaddr_in *raddr;  *	u_long prog;  *	u_long version;  *	register int *sockp;  *	u_int sendsz;  *	u_int recvsz;  */
name|__BEGIN_DECLS
specifier|extern
name|CLIENT
modifier|*
name|clnttcp_create
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in
operator|*
operator|,
name|u_long
operator|,
name|u_long
operator|,
name|int
operator|*
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
comment|/*  * UDP based rpc.  * CLIENT *  * clntudp_create(raddr, program, version, wait, sockp)  *	struct sockaddr_in *raddr;  *	u_long program;  *	u_long version;  *	struct timeval wait;  *	int *sockp;  *  * Same as above, but you specify max packet sizes.  * CLIENT *  * clntudp_bufcreate(raddr, program, version, wait, sockp, sendsz, recvsz)  *	struct sockaddr_in *raddr;  *	u_long program;  *	u_long version;  *	struct timeval wait;  *	int *sockp;  *	u_int sendsz;  *	u_int recvsz;  */
name|__BEGIN_DECLS
specifier|extern
name|CLIENT
modifier|*
name|clntudp_create
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in
operator|*
operator|,
name|u_long
operator|,
name|u_long
operator|,
expr|struct
name|timeval
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CLIENT
modifier|*
name|clntudp_bufcreate
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in
operator|*
operator|,
name|u_long
operator|,
name|u_long
operator|,
expr|struct
name|timeval
operator|,
name|int
operator|*
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
comment|/*  * AF_UNIX based rpc  * CLIENT *  * clntunix_create(raddr, prog, vers, sockp, sendsz, recvsz)  *	struct sockaddr_un *raddr;  *	u_long prog;  *	u_long version;  *	register int *sockp;  *	u_int sendsz;  *	u_int recvsz;  */
name|__BEGIN_DECLS
specifier|extern
name|CLIENT
modifier|*
name|clntunix_create
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_un
operator|*
operator|,
name|u_long
operator|,
name|u_long
operator|,
name|int
operator|*
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
comment|/*  * Print why creation failed  */
name|__BEGIN_DECLS
specifier|extern
name|void
name|clnt_pcreateerror
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stderr */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|clnt_spcreateerror
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string */
end_comment

begin_decl_stmt
name|__END_DECLS
comment|/*  * Like clnt_perror(), but is more verbose in its output  */
name|__BEGIN_DECLS
specifier|extern
name|void
name|clnt_perrno
name|__P
argument_list|(
operator|(
expr|enum
name|clnt_stat
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stderr */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|clnt_sperrno
name|__P
argument_list|(
operator|(
expr|enum
name|clnt_stat
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string */
end_comment

begin_decl_stmt
name|__END_DECLS
comment|/*  * Print an English error message, given the client error code  */
name|__BEGIN_DECLS
specifier|extern
name|void
name|clnt_perror
name|__P
argument_list|(
operator|(
name|CLIENT
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stderr */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|clnt_sperror
name|__P
argument_list|(
operator|(
name|CLIENT
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|struct
name|rpc_createerr
name|rpc_createerr
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|UDPMSGSIZE
value|8800
end_define

begin_comment
comment|/* rpc imposed limit on udp msg size */
end_comment

begin_define
define|#
directive|define
name|RPCSMALLMSGSIZE
value|400
end_define

begin_comment
comment|/* a more reasonable packet size */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RPC_CLNT_H */
end_comment

end_unit

