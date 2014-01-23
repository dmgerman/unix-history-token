begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *   * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *   * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *   * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *   * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *   * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RPC_KRPC_H_
end_ifndef

begin_define
define|#
directive|define
name|_RPC_KRPC_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Definitions now shared between client and server RPC for backchannels.  */
end_comment

begin_define
define|#
directive|define
name|MCALL_MSG_SIZE
value|24
end_define

begin_comment
comment|/*  * A pending RPC request which awaits a reply. Requests which have  * received their reply will have cr_xid set to zero and cr_mrep to  * the mbuf chain of the reply.  */
end_comment

begin_struct
struct|struct
name|ct_request
block|{
name|TAILQ_ENTRY
argument_list|(
argument|ct_request
argument_list|)
name|cr_link
expr_stmt|;
name|uint32_t
name|cr_xid
decl_stmt|;
comment|/* XID of request */
name|struct
name|mbuf
modifier|*
name|cr_mrep
decl_stmt|;
comment|/* reply received by upcall */
name|int
name|cr_error
decl_stmt|;
comment|/* any error from upcall */
name|char
name|cr_verf
index|[
name|MAX_AUTH_BYTES
index|]
decl_stmt|;
comment|/* reply verf */
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|ct_request_list
argument_list|,
name|ct_request
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|rc_data
block|{
name|struct
name|mtx
name|rc_lock
decl_stmt|;
name|struct
name|sockaddr_storage
name|rc_addr
decl_stmt|;
comment|/* server address */
name|struct
name|netconfig
modifier|*
name|rc_nconf
decl_stmt|;
comment|/* network type */
name|rpcprog_t
name|rc_prog
decl_stmt|;
comment|/* program number */
name|rpcvers_t
name|rc_vers
decl_stmt|;
comment|/* version number */
name|size_t
name|rc_sendsz
decl_stmt|;
name|size_t
name|rc_recvsz
decl_stmt|;
name|struct
name|timeval
name|rc_timeout
decl_stmt|;
name|struct
name|timeval
name|rc_retry
decl_stmt|;
name|int
name|rc_retries
decl_stmt|;
name|int
name|rc_privport
decl_stmt|;
name|char
modifier|*
name|rc_waitchan
decl_stmt|;
name|int
name|rc_intr
decl_stmt|;
name|int
name|rc_connecting
decl_stmt|;
name|int
name|rc_closed
decl_stmt|;
name|struct
name|ucred
modifier|*
name|rc_ucred
decl_stmt|;
name|CLIENT
modifier|*
name|rc_client
decl_stmt|;
comment|/* underlying RPC client */
name|struct
name|rpc_err
name|rc_err
decl_stmt|;
name|void
modifier|*
name|rc_backchannel
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ct_data
block|{
name|struct
name|mtx
name|ct_lock
decl_stmt|;
name|int
name|ct_threads
decl_stmt|;
comment|/* number of threads in clnt_vc_call */
name|bool_t
name|ct_closing
decl_stmt|;
comment|/* TRUE if we are closing */
name|bool_t
name|ct_closed
decl_stmt|;
comment|/* TRUE if we are closed */
name|struct
name|socket
modifier|*
name|ct_socket
decl_stmt|;
comment|/* connection socket */
name|bool_t
name|ct_closeit
decl_stmt|;
comment|/* close it on destroy */
name|struct
name|timeval
name|ct_wait
decl_stmt|;
comment|/* wait interval in milliseconds */
name|struct
name|sockaddr_storage
name|ct_addr
decl_stmt|;
comment|/* remote addr */
name|struct
name|rpc_err
name|ct_error
decl_stmt|;
name|uint32_t
name|ct_xid
decl_stmt|;
name|char
name|ct_mcallc
index|[
name|MCALL_MSG_SIZE
index|]
decl_stmt|;
comment|/* marshalled callmsg */
name|size_t
name|ct_mpos
decl_stmt|;
comment|/* pos after marshal */
specifier|const
name|char
modifier|*
name|ct_waitchan
decl_stmt|;
name|int
name|ct_waitflag
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|ct_record
decl_stmt|;
comment|/* current reply record */
name|size_t
name|ct_record_resid
decl_stmt|;
comment|/* how much left of reply to read */
name|bool_t
name|ct_record_eor
decl_stmt|;
comment|/* true if reading last fragment */
name|struct
name|ct_request_list
name|ct_pending
decl_stmt|;
name|int
name|ct_upcallrefs
decl_stmt|;
comment|/* Ref cnt of upcalls in prog. */
name|SVCXPRT
modifier|*
name|ct_backchannelxprt
decl_stmt|;
comment|/* xprt for backchannel */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cf_conn
block|{
comment|/* kept in xprt->xp_p1 for actual connection */
name|enum
name|xprt_stat
name|strm_stat
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|mpending
decl_stmt|;
comment|/* unparsed data read from the socket */
name|struct
name|mbuf
modifier|*
name|mreq
decl_stmt|;
comment|/* current record being built from mpending */
name|uint32_t
name|resid
decl_stmt|;
comment|/* number of bytes needed for fragment */
name|bool_t
name|eor
decl_stmt|;
comment|/* reading last fragment of current record */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _RPC_KRPC_H_ */
end_comment

end_unit

