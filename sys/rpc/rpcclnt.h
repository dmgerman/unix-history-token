begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$OpenBSD: nfsmount.h,v 1.11 2002/03/14 01:27:13 millert Exp $	*/
end_comment

begin_comment
comment|/*	$NetBSD: nfsmount.h,v 1.10 1996/02/18 11:54:03 fvdl Exp $	*/
end_comment

begin_comment
comment|/*-  * copyright (c) 2003  * the regents of the university of michigan  * all rights reserved  *   * permission is granted to use, copy, create derivative works and redistribute  * this software and such derivative works for any purpose, so long as the name  * of the university of michigan is not used in any advertising or publicity  * pertaining to the use or distribution of this software without specific,  * written prior authorization.  if the above copyright notice or any other  * identification of the university of michigan is included in any copy of any  * portion of this software, then the disclaimer below must also be included.  *   * this software is provided as is, without representation from the university  * of michigan as to its fitness for any purpose, and without warranty by the  * university of michigan of any kind, either express or implied, including  * without limitation the implied warranties of merchantability and fitness for  * a particular purpose. the regents of the university of michigan shall not be  * liable for any damages, including special, indirect, incidental, or  * consequential damages, with respect to any claim arising out of or in  * connection with the use of the software, even if it has been or is hereafter  * advised of the possibility of such damages.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)nfsmount.h	8.3 (Berkeley) 3/30/95  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RPCCLNT_H_
end_ifndef

begin_define
define|#
directive|define
name|_RPCCLNT_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__OpenBSD__
end_ifdef

begin_define
define|#
directive|define
name|RPC_EXEC_CTX
value|struct proc *
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RPC_EXEC_CTX
value|struct thread *
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|RPCCLNT_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|RPCDEBUG
parameter_list|(
name|args
modifier|...
parameter_list|)
value|do{	\ 	if(rpcdebugon != 0){	\ 		printf("%s(): ", __func__);\ 		printf(args);	\ 		printf("\n");	\ 	}}while(0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RPCDEBUG
parameter_list|(
name|args
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* from nfs/nfs.h */
end_comment

begin_define
define|#
directive|define
name|RPC_TICKINTVL
value|10
end_define

begin_comment
comment|/* from nfs/nfsproto.h */
end_comment

begin_define
define|#
directive|define
name|RPC_MAXDATA
value|32768
end_define

begin_define
define|#
directive|define
name|RPC_MAXPKTHDR
value|404
end_define

begin_define
define|#
directive|define
name|RPC_MAXPACKET
value|(RPC_MAXPKTHDR + RPC_MAXDATA)
end_define

begin_define
define|#
directive|define
name|RPCX_UNSIGNED
value|4
end_define

begin_comment
comment|/* defines for rpcclnt's rc_flags    XXX these flags came from the NFSMNT_* flags in OpenBSD's sys/mount.h */
end_comment

begin_define
define|#
directive|define
name|RPCCLNT_SOFT
value|0x001
end_define

begin_comment
comment|/* soft mount (hard is details) */
end_comment

begin_define
define|#
directive|define
name|RPCCLNT_INT
value|0x002
end_define

begin_comment
comment|/* allow interrupts on hard mounts */
end_comment

begin_define
define|#
directive|define
name|RPCCLNT_NOCONN
value|0x004
end_define

begin_comment
comment|/* dont connect the socket (udp) */
end_comment

begin_define
define|#
directive|define
name|RPCCLNT_DUMBTIMR
value|0x010
end_define

begin_define
define|#
directive|define
name|RPCCLNT_SNDLOCK
value|0x100
end_define

begin_define
define|#
directive|define
name|RPCCLNT_WANTSND
value|0x200
end_define

begin_define
define|#
directive|define
name|RPCCLNT_RCVLOCK
value|0x400
end_define

begin_define
define|#
directive|define
name|RPCCLNT_WANTRCV
value|0x800
end_define

begin_comment
comment|/* Flag values for r_flags */
end_comment

begin_define
define|#
directive|define
name|R_TIMING
value|0x01
end_define

begin_comment
comment|/* timing request (in mntp) */
end_comment

begin_define
define|#
directive|define
name|R_SENT
value|0x02
end_define

begin_comment
comment|/* request has been sent */
end_comment

begin_define
define|#
directive|define
name|R_SOFTTERM
value|0x04
end_define

begin_comment
comment|/* soft mnt, too many retries */
end_comment

begin_define
define|#
directive|define
name|R_INTR
value|0x08
end_define

begin_comment
comment|/* intr mnt, signal pending */
end_comment

begin_define
define|#
directive|define
name|R_SOCKERR
value|0x10
end_define

begin_comment
comment|/* Fatal error on socket */
end_comment

begin_define
define|#
directive|define
name|R_TPRINTFMSG
value|0x20
end_define

begin_comment
comment|/* Did a tprintf msg. */
end_comment

begin_define
define|#
directive|define
name|R_MUSTRESEND
value|0x40
end_define

begin_comment
comment|/* Must resend request */
end_comment

begin_define
define|#
directive|define
name|R_GETONEREP
value|0x80
end_define

begin_comment
comment|/* Probe for one reply only */
end_comment

begin_define
define|#
directive|define
name|RPC_HZ
value|(hz / rpcclnt_ticks)
end_define

begin_comment
comment|/* Ticks/sec */
end_comment

begin_define
define|#
directive|define
name|RPC_TIMEO
value|(1 * RPC_HZ)
end_define

begin_comment
comment|/* Default timeout = 1 second */
end_comment

begin_define
define|#
directive|define
name|RPC_MAXREXMIT
value|100
end_define

begin_comment
comment|/* Stop counting after this many */
end_comment

begin_define
define|#
directive|define
name|RPCIGNORE_SOERROR
parameter_list|(
name|s
parameter_list|,
name|e
parameter_list|)
define|\
value|((e) != EINTR&& (e) != ERESTART&& (e) != EWOULDBLOCK&& \                 ((s)& PR_CONNREQUIRED) == 0)
end_define

begin_define
define|#
directive|define
name|RPCINT_SIGMASK
value|(sigmask(SIGINT)|sigmask(SIGTERM)|sigmask(SIGKILL)| \                          sigmask(SIGHUP)|sigmask(SIGQUIT))
end_define

begin_define
define|#
directive|define
name|RPCMADV
parameter_list|(
name|m
parameter_list|,
name|s
parameter_list|)
value|(m)->m_data += (s)
end_define

begin_define
define|#
directive|define
name|RPCAUTH_ROOTCREDS
value|NULL
end_define

begin_define
define|#
directive|define
name|RPCCLNTINT_SIGMASK
parameter_list|(
name|set
parameter_list|)
define|\
value|(SIGISMEMBER(set, SIGINT) || SIGISMEMBER(set, SIGTERM) || \ 	 SIGISMEMBER(set, SIGHUP) || SIGISMEMBER(set, SIGKILL) || \ 	 SIGISMEMBER(set, SIGQUIT))
end_define

begin_define
define|#
directive|define
name|fxdr_unsigned
parameter_list|(
name|t
parameter_list|,
name|v
parameter_list|)
value|((t)ntohl((int32_t)(v)))
end_define

begin_define
define|#
directive|define
name|txdr_unsigned
parameter_list|(
name|v
parameter_list|)
value|(htonl((int32_t)(v)))
end_define

begin_comment
comment|/* global rpcstats   * XXX should be per rpcclnt */
end_comment

begin_struct
struct|struct
name|rpcstats
block|{
name|int
name|rpcretries
decl_stmt|;
name|int
name|rpcrequests
decl_stmt|;
name|int
name|rpctimeouts
decl_stmt|;
name|int
name|rpcunexpected
decl_stmt|;
name|int
name|rpcinvalid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rpc_program
block|{
name|u_int32_t
name|prog_id
decl_stmt|;
name|u_int32_t
name|prog_version
decl_stmt|;
name|char
modifier|*
name|prog_name
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rpc_auth
block|{
name|unsigned
name|int
name|auth_type
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rpctask
block|{
name|TAILQ_ENTRY
argument_list|(
argument|rpctask
argument_list|)
name|r_chain
expr_stmt|;
name|struct
name|mbuf
modifier|*
name|r_mreq
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|r_mrep
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|r_md
decl_stmt|;
name|caddr_t
name|r_dpos
decl_stmt|;
name|struct
name|rpcclnt
modifier|*
name|r_rpcclnt
decl_stmt|;
name|u_int32_t
name|r_xid
decl_stmt|;
name|int
name|r_flags
decl_stmt|;
comment|/* flags on request, see below */
name|int
name|r_retry
decl_stmt|;
comment|/* max retransmission count */
name|int
name|r_rexmit
decl_stmt|;
comment|/* current retrans count */
name|int
name|r_timer
decl_stmt|;
comment|/* tick counter on reply */
name|int
name|r_procnum
decl_stmt|;
comment|/* NFS procedure number */
name|int
name|r_rtt
decl_stmt|;
comment|/* RTT for rpc */
name|RPC_EXEC_CTX
name|r_td
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rpc_reply
block|{
struct|struct
block|{
name|u_int32_t
name|type
decl_stmt|;
name|u_int32_t
name|status
decl_stmt|;
comment|/* used only when reply == RPC_MSGDENIED and 		 * status == RPC_AUTHERR */
name|u_int32_t
name|autherr
decl_stmt|;
comment|/* rpc mismatch info if reply == RPC_MSGDENIED and 	 	* status == RPC_MISMATCH */
struct|struct
block|{
name|u_int32_t
name|low
decl_stmt|;
name|u_int32_t
name|high
decl_stmt|;
block|}
name|mismatch_info
struct|;
block|}
name|stat
struct|;
comment|/* head of the mbuf chain */
name|struct
name|mbuf
modifier|*
name|mrep
decl_stmt|;
comment|/* mbuf and position of the verification opaque data 	 * note that this is only valid when stat.reply == RPC_MSGACCEPTED */
name|u_int32_t
name|verf_type
decl_stmt|;
name|u_int32_t
name|verf_size
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|verf_md
decl_stmt|;
name|caddr_t
name|verf_dpos
decl_stmt|;
comment|/* mbuf and postion of the result of the rpc request */
name|struct
name|mbuf
modifier|*
name|result_md
decl_stmt|;
name|caddr_t
name|result_dpos
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * RPC Client connection context.  * One allocated on every NFS mount.  * Holds RPC specific information for mount.  */
end_comment

begin_comment
comment|/* XXX: please note that all pointer type variables are just set (not copied),  *      so it is up to the user to free these values */
end_comment

begin_struct
struct|struct
name|rpcclnt
block|{
name|int
name|rc_flag
decl_stmt|;
comment|/* For RPCCLNT_* flags  */
name|int
name|rc_wsize
decl_stmt|;
comment|/* Max size of the request data */
name|int
name|rc_rsize
decl_stmt|;
comment|/* Max size of the response data */
name|struct
name|sockaddr
modifier|*
name|rc_name
decl_stmt|;
name|struct
name|socket
modifier|*
name|rc_so
decl_stmt|;
comment|/* Rpc socket */
name|int
name|rc_sotype
decl_stmt|;
comment|/* Type of socket */
name|int
name|rc_soproto
decl_stmt|;
comment|/* and protocol */
name|int
name|rc_soflags
decl_stmt|;
comment|/* pr_flags for socket protocol */
name|int
name|rc_timeo
decl_stmt|;
comment|/* Init timer for NFSMNT_DUMBTIMR */
name|int
name|rc_retry
decl_stmt|;
comment|/* Max retries */
name|int
name|rc_srtt
index|[
literal|4
index|]
decl_stmt|;
comment|/* Timers for rpcs */
name|int
name|rc_sdrtt
index|[
literal|4
index|]
decl_stmt|;
name|int
name|rc_sent
decl_stmt|;
comment|/* Request send count */
name|int
name|rc_cwnd
decl_stmt|;
comment|/* Request send window */
name|int
name|rc_timeouts
decl_stmt|;
comment|/* Request timeouts */
comment|/* XXX: this is not being set!!!! */
name|int
name|rc_deadthresh
decl_stmt|;
comment|/* Threshold of timeouts-->dead server*/
comment|/* authentication: */
comment|/* currently can be RPCAUTH_NULL, RPCAUTH_KERBV4, RPCAUTH_UNIX */
comment|/* should be kept in XDR form */
name|int
name|rc_authtype
decl_stmt|;
comment|/* Authenticator type */
if|#
directive|if
literal|0
comment|/* RPCAUTH_KERB4 */
block|int	rc_authlen;
comment|/* and length */
block|char	*rc_authstr;
comment|/* Authenticator string */
block|int	rc_verflen; 	char	*rc_verfstr;
comment|/* and the verifier */
endif|#
directive|endif
comment|/* RPCAUTH_UNIX*/
name|struct
name|rpc_auth
modifier|*
name|rc_auth
decl_stmt|;
comment|/* authentication */
if|#
directive|if
literal|0
comment|/* stored in XDR form (network byte order) */
block|unsigned int rc_progid;
comment|/* program id */
block|unsigned int rc_progvers;
comment|/* program version */
comment|/* name of server for log messages */
block|const char *rc_servername;
comment|/* for printing error messages */
else|#
directive|else
name|struct
name|rpc_program
modifier|*
name|rc_prog
decl_stmt|;
endif|#
directive|endif
comment|/* XXX: this should be removed */
name|int
name|rc_proctlen
decl_stmt|;
comment|/* if == 0 then rc_proct == NULL */
name|int
modifier|*
name|rc_proct
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|__OpenBSD__
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|pool
name|rpcreply_pool
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pool
name|rpcclnt_pool
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* MALLOC_DECLARE(M_RPC); */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|rpcdebugon
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__OpenBSD__
end_ifdef

begin_define
define|#
directive|define
name|rpcclnt_get
parameter_list|(
name|X
parameter_list|)
define|\
value|do {	\ 	(X) = pool_get(&rpcclnt_pool, PR_WAITOK);	\ 	bzero((X), sizeof(struct rpcclnt));	\ 	}while(0)
end_define

begin_define
define|#
directive|define
name|rpcclnt_put
parameter_list|(
name|X
parameter_list|)
define|\
value|do {	\ 	if ((X) != NULL){	\ 		pool_put(&rpcclnt_pool, (X));	\ 	}}while(0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__OpenBSD__ */
end_comment

begin_comment
comment|/* usage count for module (un)loading */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|rpcclnt_usage
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|rpcclnt_usage_mutex
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|rpcclnt_create
parameter_list|(
name|struct
name|rpcclnt
modifier|*
modifier|*
name|rpc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rpcclnt_destroy
parameter_list|(
name|struct
name|rpcclnt
modifier|*
name|rpc
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|rpcclnt_get
parameter_list|(
name|X
parameter_list|)
value|rpcclnt_create(&(X))
end_define

begin_define
define|#
directive|define
name|rpcclnt_put
parameter_list|(
name|X
parameter_list|)
value|rpcclnt_destroy(X)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|RPCCLNT_TEST
end_ifdef

begin_struct
struct|struct
name|rpcclnt_test_args
block|{
name|int
name|nothing
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|rpcclnt_test
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|rpcclnt_test_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|RPC_RETURN
parameter_list|(
name|X
parameter_list|)
value|do { RPCDEBUG("returning %d", X); return X; }while(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RPCCLNT_TEST */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__OpenBSD__ */
end_comment

begin_function_decl
name|void
name|rpcclnt_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rpcclnt_uninit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|int rpcclnt_setup(struct rpcclnt *, int, struct sockaddr *, int, int, int, int, const char *, int, int);
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|rpcclnt_setup
parameter_list|(
name|struct
name|rpcclnt
modifier|*
parameter_list|,
name|struct
name|rpc_program
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|rpc_auth
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rpcclnt_connect
parameter_list|(
name|struct
name|rpcclnt
modifier|*
parameter_list|,
name|RPC_EXEC_CTX
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rpcclnt_reconnect
parameter_list|(
name|struct
name|rpctask
modifier|*
parameter_list|,
name|RPC_EXEC_CTX
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rpcclnt_disconnect
parameter_list|(
name|struct
name|rpcclnt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rpcclnt_safedisconnect
parameter_list|(
name|struct
name|rpcclnt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rpcclnt_setauth
parameter_list|(
name|struct
name|rpcclnt
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rpcclnt_request
parameter_list|(
name|struct
name|rpcclnt
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|RPC_EXEC_CTX
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|struct
name|rpc_reply
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rpcclnt_err
parameter_list|(
name|struct
name|rpc_reply
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rpcclnt_cancelreqs
parameter_list|(
name|struct
name|rpcclnt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rpcclnt_sigintr
parameter_list|(
name|struct
name|rpcclnt
modifier|*
parameter_list|,
name|struct
name|rpctask
modifier|*
parameter_list|,
name|RPC_EXEC_CTX
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _RPCCLNT_H_ */
end_comment

end_unit

