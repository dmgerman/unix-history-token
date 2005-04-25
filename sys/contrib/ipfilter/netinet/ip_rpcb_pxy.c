begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 2002-2003 by Ryan Beasley<ryanb@goddamnbastard.org>  *  * See the IPFILTER.LICENCE file for details on licencing.  */
end_comment

begin_comment
comment|/*  * Overview:  *   This is an in-kernel application proxy for Sun's RPCBIND (nee portmap)  *   protocol as defined in RFC1833.  It is far from complete, mostly  *   lacking in less-likely corner cases, but it's definitely functional.  *  *   Invocation:  *     rdr<int><e_ip>/32 port<e_p> -><i_ip> port<i_p> udp proxy rpcbu  *  *   If the host running IP Filter is the same as the RPC server, it's  *   perfectly legal for both the internal and external addresses and ports  *   to match.  *  *   When triggered by appropriate IP NAT rules, this proxy works by  *   examining data contained in received packets.  Requests and replies are  *   modified, NAT and state table entries created, etc., as necessary.  */
end_comment

begin_comment
comment|/*  * TODO / NOTES  *  *   o Must implement locking to protect proxy session data.  *   o Fragmentation isn't supported.  *   o Only supports UDP.  *   o Doesn't support multiple RPC records in a single request.  *   o Errors should be more fine-grained.  (e.g., malloc failure vs.  *     illegal RPCB request / reply)  *   o Even with the limit on the total amount of recorded transactions,  *     should there be a timeout on transaction removal?  *   o There is a potential collision between cloning, wildcard NAT and  *     state entries.  There should be an appr_getport routine for  *     to avoid this.  *   o The enclosed hack of STREAMS support is pretty sick and most likely  *     broken.  *  *	Id: ip_rpcb_pxy.c,v 2.25.2.3 2005/02/04 10:22:56 darrenr Exp  */
end_comment

begin_define
define|#
directive|define
name|IPF_RPCB_PROXY
end_define

begin_comment
comment|/*  * Function prototypes  */
end_comment

begin_decl_stmt
name|int
name|ippr_rpcb_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ippr_rpcb_fini
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ippr_rpcb_new
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|ap_session_t
operator|*
operator|,
name|nat_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ippr_rpcb_del
name|__P
argument_list|(
operator|(
name|ap_session_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ippr_rpcb_in
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|ap_session_t
operator|*
operator|,
name|nat_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ippr_rpcb_out
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|ap_session_t
operator|*
operator|,
name|nat_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|ippr_rpcb_flush
name|__P
argument_list|(
operator|(
name|rpcb_session_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ippr_rpcb_decodereq
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|nat_t
operator|*
operator|,
name|rpcb_session_t
operator|*
operator|,
name|rpc_msg_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ippr_rpcb_skipauth
name|__P
argument_list|(
operator|(
name|rpc_msg_t
operator|*
operator|,
name|xdr_auth_t
operator|*
operator|,
name|u_32_t
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ippr_rpcb_insert
name|__P
argument_list|(
operator|(
name|rpcb_session_t
operator|*
operator|,
name|rpcb_xact_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ippr_rpcb_xdrrpcb
name|__P
argument_list|(
operator|(
name|rpc_msg_t
operator|*
operator|,
name|u_32_t
operator|*
operator|,
name|rpcb_args_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ippr_rpcb_getuaddr
name|__P
argument_list|(
operator|(
name|rpc_msg_t
operator|*
operator|,
name|xdr_uaddr_t
operator|*
operator|,
name|u_32_t
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|u_int
name|ippr_rpcb_atoi
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ippr_rpcb_modreq
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|nat_t
operator|*
operator|,
name|rpc_msg_t
operator|*
operator|,
name|mb_t
operator|*
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ippr_rpcb_decoderep
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|nat_t
operator|*
operator|,
name|rpcb_session_t
operator|*
operator|,
name|rpc_msg_t
operator|*
operator|,
name|rpcb_xact_t
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|rpcb_xact_t
modifier|*
name|ippr_rpcb_lookup
name|__P
argument_list|(
operator|(
name|rpcb_session_t
operator|*
operator|,
name|u_32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|ippr_rpcb_deref
name|__P
argument_list|(
operator|(
name|rpcb_session_t
operator|*
operator|,
name|rpcb_xact_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ippr_rpcb_getproto
name|__P
argument_list|(
operator|(
name|rpc_msg_t
operator|*
operator|,
name|xdr_proto_t
operator|*
operator|,
name|u_32_t
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ippr_rpcb_getnat
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|nat_t
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
specifier|static
name|int
name|ippr_rpcb_modv3
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|nat_t
operator|*
operator|,
name|rpc_msg_t
operator|*
operator|,
name|mb_t
operator|*
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ippr_rpcb_modv4
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|nat_t
operator|*
operator|,
name|rpc_msg_t
operator|*
operator|,
name|mb_t
operator|*
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|ippr_rpcb_fixlen
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Global variables  */
end_comment

begin_decl_stmt
specifier|static
name|frentry_t
name|rpcbfr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Skeleton rule for reference by entities 				   this proxy creates. */
end_comment

begin_decl_stmt
specifier|static
name|int
name|rpcbcnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Upper bound of allocated RPCB sessions. */
end_comment

begin_comment
comment|/* XXX rpcbcnt still requires locking. */
end_comment

begin_decl_stmt
name|int
name|rpcb_proxy_init
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Since rpc_msg contains only pointers, one should use this macro as a  * handy way to get to the goods.  (In case you're wondering about the name,  * this started as BYTEREF -> BREF -> B.)  */
end_comment

begin_define
define|#
directive|define
name|B
parameter_list|(
name|r
parameter_list|)
value|(u_32_t)ntohl(*(r))
end_define

begin_comment
comment|/*  * Public subroutines  */
end_comment

begin_comment
comment|/* --------------------------------------------------------------------	*/
end_comment

begin_comment
comment|/* Function:	ippr_rpcb_init						*/
end_comment

begin_comment
comment|/* Returns:	int - 0 == success					*/
end_comment

begin_comment
comment|/* Parameters:	(void)							*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/* Initialize the filter rule entry and session limiter.		*/
end_comment

begin_comment
comment|/* --------------------------------------------------------------------	*/
end_comment

begin_function
name|int
name|ippr_rpcb_init
parameter_list|()
block|{
name|rpcbcnt
operator|=
literal|0
expr_stmt|;
name|bzero
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|rpcbfr
argument_list|,
sizeof|sizeof
argument_list|(
name|rpcbfr
argument_list|)
argument_list|)
expr_stmt|;
name|rpcbfr
operator|.
name|fr_ref
operator|=
literal|1
expr_stmt|;
name|rpcbfr
operator|.
name|fr_flags
operator|=
name|FR_PASS
operator||
name|FR_QUICK
operator||
name|FR_KEEPSTATE
expr_stmt|;
name|MUTEX_INIT
argument_list|(
operator|&
name|rpcbfr
operator|.
name|fr_lock
argument_list|,
literal|"ipf Sun RPCB proxy rule lock"
argument_list|)
expr_stmt|;
name|rpcb_proxy_init
operator|=
literal|1
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/* --------------------------------------------------------------------	*/
end_comment

begin_comment
comment|/* Function:	ippr_rpcb_fini						*/
end_comment

begin_comment
comment|/* Returns:	void							*/
end_comment

begin_comment
comment|/* Parameters:	(void)							*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/* Destroy rpcbfr's mutex to avoid a lock leak.				*/
end_comment

begin_comment
comment|/* --------------------------------------------------------------------	*/
end_comment

begin_function
name|void
name|ippr_rpcb_fini
parameter_list|()
block|{
if|if
condition|(
name|rpcb_proxy_init
operator|==
literal|1
condition|)
block|{
name|MUTEX_DESTROY
argument_list|(
operator|&
name|rpcbfr
operator|.
name|fr_lock
argument_list|)
expr_stmt|;
name|rpcb_proxy_init
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* --------------------------------------------------------------------	*/
end_comment

begin_comment
comment|/* Function:	ippr_rpcb_new						*/
end_comment

begin_comment
comment|/* Returns:	int - -1 == failure, 0 == success			*/
end_comment

begin_comment
comment|/* Parameters:	fin(I)	- pointer to packet information			*/
end_comment

begin_comment
comment|/*		aps(I)	- pointer to proxy session structure		*/
end_comment

begin_comment
comment|/*		nat(I)	- pointer to NAT session structure		*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/* Allocate resources for per-session proxy structures.			*/
end_comment

begin_comment
comment|/* --------------------------------------------------------------------	*/
end_comment

begin_function
name|int
name|ippr_rpcb_new
parameter_list|(
name|fin
parameter_list|,
name|aps
parameter_list|,
name|nat
parameter_list|)
name|fr_info_t
modifier|*
name|fin
decl_stmt|;
name|ap_session_t
modifier|*
name|aps
decl_stmt|;
name|nat_t
modifier|*
name|nat
decl_stmt|;
block|{
name|rpcb_session_t
modifier|*
name|rs
decl_stmt|;
name|fin
operator|=
name|fin
expr_stmt|;
comment|/* LINT */
name|nat
operator|=
name|nat
expr_stmt|;
comment|/* LINT */
name|KMALLOC
argument_list|(
name|rs
argument_list|,
name|rpcb_session_t
operator|*
argument_list|)
expr_stmt|;
if|if
condition|(
name|rs
operator|==
name|NULL
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|bzero
argument_list|(
operator|(
name|char
operator|*
operator|)
name|rs
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|rs
argument_list|)
argument_list|)
expr_stmt|;
name|MUTEX_INIT
argument_list|(
operator|&
name|rs
operator|->
name|rs_rxlock
argument_list|,
literal|"ipf Sun RPCB proxy session lock"
argument_list|)
expr_stmt|;
name|aps
operator|->
name|aps_data
operator|=
name|rs
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/* --------------------------------------------------------------------	*/
end_comment

begin_comment
comment|/* Function:	ippr_rpcb_del						*/
end_comment

begin_comment
comment|/* Returns:	void							*/
end_comment

begin_comment
comment|/* Parameters:	aps(I)	- pointer to proxy session structure		*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/* Free up a session's list of RPCB requests.				*/
end_comment

begin_comment
comment|/* --------------------------------------------------------------------	*/
end_comment

begin_function
name|void
name|ippr_rpcb_del
parameter_list|(
name|aps
parameter_list|)
name|ap_session_t
modifier|*
name|aps
decl_stmt|;
block|{
name|rpcb_session_t
modifier|*
name|rs
decl_stmt|;
name|rs
operator|=
operator|(
name|rpcb_session_t
operator|*
operator|)
name|aps
operator|->
name|aps_data
expr_stmt|;
name|MUTEX_ENTER
argument_list|(
operator|&
name|rs
operator|->
name|rs_rxlock
argument_list|)
expr_stmt|;
name|ippr_rpcb_flush
argument_list|(
name|rs
argument_list|)
expr_stmt|;
name|MUTEX_EXIT
argument_list|(
operator|&
name|rs
operator|->
name|rs_rxlock
argument_list|)
expr_stmt|;
name|MUTEX_DESTROY
argument_list|(
operator|&
name|rs
operator|->
name|rs_rxlock
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* --------------------------------------------------------------------	*/
end_comment

begin_comment
comment|/* Function:	ippr_rpcb_in						*/
end_comment

begin_comment
comment|/* Returns:	int - APR_ERR(1) == drop the packet, 			*/
end_comment

begin_comment
comment|/*		      APR_ERR(2) == kill the proxy session,		*/
end_comment

begin_comment
comment|/*		      else change in packet length (in bytes)		*/
end_comment

begin_comment
comment|/* Parameters:	fin(I)	- pointer to packet information			*/
end_comment

begin_comment
comment|/*		ip(I)	- pointer to packet header			*/
end_comment

begin_comment
comment|/*		aps(I)	- pointer to proxy session structure		*/
end_comment

begin_comment
comment|/*		nat(I)	- pointer to NAT session structure		*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/* Given a presumed RPCB request, perform some minor tests and pass off */
end_comment

begin_comment
comment|/* for decoding.  Also pass packet off for a rewrite if necessary.	*/
end_comment

begin_comment
comment|/* --------------------------------------------------------------------	*/
end_comment

begin_function
name|int
name|ippr_rpcb_in
parameter_list|(
name|fin
parameter_list|,
name|aps
parameter_list|,
name|nat
parameter_list|)
name|fr_info_t
modifier|*
name|fin
decl_stmt|;
name|ap_session_t
modifier|*
name|aps
decl_stmt|;
name|nat_t
modifier|*
name|nat
decl_stmt|;
block|{
name|rpc_msg_t
name|rpcmsg
decl_stmt|,
modifier|*
name|rm
decl_stmt|;
name|rpcb_session_t
modifier|*
name|rs
decl_stmt|;
name|u_int
name|off
decl_stmt|,
name|dlen
decl_stmt|;
name|mb_t
modifier|*
name|m
decl_stmt|;
name|int
name|rv
decl_stmt|;
comment|/* Disallow fragmented or illegally short packets. */
if|if
condition|(
operator|(
name|fin
operator|->
name|fin_flx
operator|&
operator|(
name|FI_FRAG
operator||
name|FI_SHORT
operator|)
operator|)
operator|!=
literal|0
condition|)
return|return
operator|(
name|APR_ERR
argument_list|(
literal|1
argument_list|)
operator|)
return|;
comment|/* Perform basic variable initialization. */
name|rs
operator|=
operator|(
name|rpcb_session_t
operator|*
operator|)
name|aps
operator|->
name|aps_data
expr_stmt|;
name|m
operator|=
name|fin
operator|->
name|fin_m
expr_stmt|;
name|off
operator|=
operator|(
name|char
operator|*
operator|)
name|fin
operator|->
name|fin_dp
operator|-
operator|(
name|char
operator|*
operator|)
name|fin
operator|->
name|fin_ip
expr_stmt|;
name|off
operator|+=
sizeof|sizeof
argument_list|(
name|udphdr_t
argument_list|)
operator|+
name|fin
operator|->
name|fin_ipoff
expr_stmt|;
name|dlen
operator|=
name|fin
operator|->
name|fin_dlen
operator|-
sizeof|sizeof
argument_list|(
name|udphdr_t
argument_list|)
expr_stmt|;
comment|/* Disallow packets outside legal range for supported requests. */
if|if
condition|(
operator|(
name|dlen
operator|<
name|RPCB_REQMIN
operator|)
operator|||
operator|(
name|dlen
operator|>
name|RPCB_REQMAX
operator|)
condition|)
return|return
operator|(
name|APR_ERR
argument_list|(
literal|1
argument_list|)
operator|)
return|;
comment|/* Copy packet over to convenience buffer. */
name|rm
operator|=
operator|&
name|rpcmsg
expr_stmt|;
name|bzero
argument_list|(
operator|(
name|char
operator|*
operator|)
name|rm
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|rm
argument_list|)
argument_list|)
expr_stmt|;
name|COPYDATA
argument_list|(
name|m
argument_list|,
name|off
argument_list|,
name|dlen
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|rm
operator|->
name|rm_msgbuf
argument_list|)
expr_stmt|;
name|rm
operator|->
name|rm_buflen
operator|=
name|dlen
expr_stmt|;
comment|/* Send off to decode request. */
name|rv
operator|=
name|ippr_rpcb_decodereq
argument_list|(
name|fin
argument_list|,
name|nat
argument_list|,
name|rs
argument_list|,
name|rm
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|rv
condition|)
block|{
case|case
operator|-
literal|1
case|:
return|return
operator|(
name|APR_ERR
argument_list|(
literal|1
argument_list|)
operator|)
return|;
comment|/*NOTREACHED*/
break|break;
case|case
literal|0
case|:
break|break;
case|case
literal|1
case|:
name|rv
operator|=
name|ippr_rpcb_modreq
argument_list|(
name|fin
argument_list|,
name|nat
argument_list|,
name|rm
argument_list|,
name|m
argument_list|,
name|off
argument_list|)
expr_stmt|;
break|break;
default|default:
comment|/*CONSTANTCONDITION*/
name|IPF_PANIC
argument_list|(
literal|1
argument_list|,
operator|(
literal|"illegal rv %d (ippr_rpcb_req)"
operator|,
name|rv
operator|)
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|rv
operator|)
return|;
block|}
end_function

begin_comment
comment|/* --------------------------------------------------------------------	*/
end_comment

begin_comment
comment|/* Function:	ippr_rpcb_out						*/
end_comment

begin_comment
comment|/* Returns:	int - APR_ERR(1) == drop the packet, 			*/
end_comment

begin_comment
comment|/*		      APR_ERR(2) == kill the proxy session,		*/
end_comment

begin_comment
comment|/*		      else change in packet length (in bytes)		*/
end_comment

begin_comment
comment|/* Parameters:	fin(I)	- pointer to packet information			*/
end_comment

begin_comment
comment|/*		ip(I)	- pointer to packet header			*/
end_comment

begin_comment
comment|/*		aps(I)	- pointer to proxy session structure		*/
end_comment

begin_comment
comment|/*		nat(I)	- pointer to NAT session structure		*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/* Given a presumed RPCB reply, perform some minor tests and pass off	*/
end_comment

begin_comment
comment|/* for decoding.  If the message indicates a successful request with	*/
end_comment

begin_comment
comment|/* valid addressing information, create NAT and state structures to	*/
end_comment

begin_comment
comment|/* allow direct communication between RPC client and server.		*/
end_comment

begin_comment
comment|/* --------------------------------------------------------------------	*/
end_comment

begin_function
name|int
name|ippr_rpcb_out
parameter_list|(
name|fin
parameter_list|,
name|aps
parameter_list|,
name|nat
parameter_list|)
name|fr_info_t
modifier|*
name|fin
decl_stmt|;
name|ap_session_t
modifier|*
name|aps
decl_stmt|;
name|nat_t
modifier|*
name|nat
decl_stmt|;
block|{
name|rpc_msg_t
name|rpcmsg
decl_stmt|,
modifier|*
name|rm
decl_stmt|;
name|rpcb_session_t
modifier|*
name|rs
decl_stmt|;
name|rpcb_xact_t
modifier|*
name|rx
decl_stmt|;
name|u_int
name|off
decl_stmt|,
name|dlen
decl_stmt|;
name|int
name|rv
decl_stmt|,
name|diff
decl_stmt|;
name|mb_t
modifier|*
name|m
decl_stmt|;
comment|/* Disallow fragmented or illegally short packets. */
if|if
condition|(
operator|(
name|fin
operator|->
name|fin_flx
operator|&
operator|(
name|FI_FRAG
operator||
name|FI_SHORT
operator|)
operator|)
operator|!=
literal|0
condition|)
return|return
operator|(
name|APR_ERR
argument_list|(
literal|1
argument_list|)
operator|)
return|;
comment|/* Perform basic variable initialization. */
name|rs
operator|=
operator|(
name|rpcb_session_t
operator|*
operator|)
name|aps
operator|->
name|aps_data
expr_stmt|;
name|m
operator|=
name|fin
operator|->
name|fin_m
expr_stmt|;
name|off
operator|=
operator|(
name|char
operator|*
operator|)
name|fin
operator|->
name|fin_dp
operator|-
operator|(
name|char
operator|*
operator|)
name|fin
operator|->
name|fin_ip
expr_stmt|;
name|off
operator|+=
sizeof|sizeof
argument_list|(
name|udphdr_t
argument_list|)
operator|+
name|fin
operator|->
name|fin_ipoff
expr_stmt|;
name|dlen
operator|=
name|fin
operator|->
name|fin_dlen
operator|-
sizeof|sizeof
argument_list|(
name|udphdr_t
argument_list|)
expr_stmt|;
name|diff
operator|=
literal|0
expr_stmt|;
comment|/* Disallow packets outside legal range for supported requests. */
if|if
condition|(
operator|(
name|dlen
operator|<
name|RPCB_REPMIN
operator|)
operator|||
operator|(
name|dlen
operator|>
name|RPCB_REPMAX
operator|)
condition|)
return|return
operator|(
name|APR_ERR
argument_list|(
literal|1
argument_list|)
operator|)
return|;
comment|/* Copy packet over to convenience buffer. */
name|rm
operator|=
operator|&
name|rpcmsg
expr_stmt|;
name|bzero
argument_list|(
operator|(
name|char
operator|*
operator|)
name|rm
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|rm
argument_list|)
argument_list|)
expr_stmt|;
name|COPYDATA
argument_list|(
name|m
argument_list|,
name|off
argument_list|,
name|dlen
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|rm
operator|->
name|rm_msgbuf
argument_list|)
expr_stmt|;
name|rm
operator|->
name|rm_buflen
operator|=
name|dlen
expr_stmt|;
comment|/* Send off to decode reply. */
name|rv
operator|=
name|ippr_rpcb_decoderep
argument_list|(
name|fin
argument_list|,
name|nat
argument_list|,
name|rs
argument_list|,
name|rm
argument_list|,
operator|&
name|rx
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|rv
condition|)
block|{
case|case
operator|-
literal|1
case|:
comment|/* Bad packet */
if|if
condition|(
name|rx
operator|!=
name|NULL
condition|)
block|{
name|MUTEX_ENTER
argument_list|(
operator|&
name|rs
operator|->
name|rs_rxlock
argument_list|)
expr_stmt|;
name|ippr_rpcb_deref
argument_list|(
name|rs
argument_list|,
name|rx
argument_list|)
expr_stmt|;
name|MUTEX_EXIT
argument_list|(
operator|&
name|rs
operator|->
name|rs_rxlock
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|APR_ERR
argument_list|(
literal|1
argument_list|)
operator|)
return|;
comment|/*NOTREACHED*/
break|break;
case|case
literal|0
case|:
comment|/* Negative reply / request rejected */
break|break;
case|case
literal|1
case|:
comment|/* Positive reply */
comment|/* 		 * With the IP address embedded in a GETADDR(LIST) reply, 		 * we'll need to rewrite the packet in the very possible 		 * event that the internal& external addresses aren't the 		 * same.  (i.e., this box is either a router or rpcbind 		 * only listens on loopback.) 		 */
if|if
condition|(
name|nat
operator|->
name|nat_inip
operator|.
name|s_addr
operator|!=
name|nat
operator|->
name|nat_outip
operator|.
name|s_addr
condition|)
block|{
if|if
condition|(
name|rx
operator|->
name|rx_type
operator|==
name|RPCB_RES_STRING
condition|)
name|diff
operator|=
name|ippr_rpcb_modv3
argument_list|(
name|fin
argument_list|,
name|nat
argument_list|,
name|rm
argument_list|,
name|m
argument_list|,
name|off
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|rx
operator|->
name|rx_type
operator|==
name|RPCB_RES_LIST
condition|)
name|diff
operator|=
name|ippr_rpcb_modv4
argument_list|(
name|fin
argument_list|,
name|nat
argument_list|,
name|rm
argument_list|,
name|m
argument_list|,
name|off
argument_list|)
expr_stmt|;
block|}
break|break;
default|default:
comment|/*CONSTANTCONDITION*/
name|IPF_PANIC
argument_list|(
literal|1
argument_list|,
operator|(
literal|"illegal rv %d (ippr_rpcb_decoderep)"
operator|,
name|rv
operator|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|rx
operator|!=
name|NULL
condition|)
block|{
name|MUTEX_ENTER
argument_list|(
operator|&
name|rs
operator|->
name|rs_rxlock
argument_list|)
expr_stmt|;
comment|/* XXX Gross hack - I'm overloading the reference                  * counter to deal with both threads and retransmitted                  * requests.  One deref signals that this thread is                  * finished with rx, and the other signals that we've                  * processed its reply.                  */
name|ippr_rpcb_deref
argument_list|(
name|rs
argument_list|,
name|rx
argument_list|)
expr_stmt|;
name|ippr_rpcb_deref
argument_list|(
name|rs
argument_list|,
name|rx
argument_list|)
expr_stmt|;
name|MUTEX_EXIT
argument_list|(
operator|&
name|rs
operator|->
name|rs_rxlock
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|diff
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Private support subroutines  */
end_comment

begin_comment
comment|/* --------------------------------------------------------------------	*/
end_comment

begin_comment
comment|/* Function:	ippr_rpcb_flush						*/
end_comment

begin_comment
comment|/* Returns:	void							*/
end_comment

begin_comment
comment|/* Parameters:	rs(I)	- pointer to RPCB session structure		*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/* Simply flushes the list of outstanding transactions, if any.		*/
end_comment

begin_comment
comment|/* --------------------------------------------------------------------	*/
end_comment

begin_function
specifier|static
name|void
name|ippr_rpcb_flush
parameter_list|(
name|rs
parameter_list|)
name|rpcb_session_t
modifier|*
name|rs
decl_stmt|;
block|{
name|rpcb_xact_t
modifier|*
name|r1
decl_stmt|,
modifier|*
name|r2
decl_stmt|;
name|r1
operator|=
name|rs
operator|->
name|rs_rxlist
expr_stmt|;
if|if
condition|(
name|r1
operator|==
name|NULL
condition|)
return|return;
while|while
condition|(
name|r1
operator|!=
name|NULL
condition|)
block|{
name|r2
operator|=
name|r1
expr_stmt|;
name|r1
operator|=
name|r1
operator|->
name|rx_next
expr_stmt|;
name|KFREE
argument_list|(
name|r2
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* --------------------------------------------------------------------	*/
end_comment

begin_comment
comment|/* Function:	ippr_rpcb_decodereq					*/
end_comment

begin_comment
comment|/* Returns:	int - -1 == bad request or critical failure,		*/
end_comment

begin_comment
comment|/*		       0 == request successfully decoded,		*/
end_comment

begin_comment
comment|/*		       1 == request successfully decoded; requires	*/
end_comment

begin_comment
comment|/*			    address rewrite/modification		*/
end_comment

begin_comment
comment|/* Parameters:	fin(I)	- pointer to packet information			*/
end_comment

begin_comment
comment|/*		nat(I)	- pointer to NAT session structure		*/
end_comment

begin_comment
comment|/*		rs(I)	- pointer to RPCB session structure		*/
end_comment

begin_comment
comment|/*		rm(I)	- pointer to RPC message structure		*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/* Take a presumed RPCB request, decode it, and store the results in	*/
end_comment

begin_comment
comment|/* the transaction list.  If the internal target address needs to be	*/
end_comment

begin_comment
comment|/* modified, store its location in ptr.					*/
end_comment

begin_comment
comment|/* WARNING:  It's the responsibility of the caller to make sure there	*/
end_comment

begin_comment
comment|/* is enough room in rs_buf for the basic RPC message "preamble".	*/
end_comment

begin_comment
comment|/* --------------------------------------------------------------------	*/
end_comment

begin_function
specifier|static
name|int
name|ippr_rpcb_decodereq
parameter_list|(
name|fin
parameter_list|,
name|nat
parameter_list|,
name|rs
parameter_list|,
name|rm
parameter_list|)
name|fr_info_t
modifier|*
name|fin
decl_stmt|;
name|nat_t
modifier|*
name|nat
decl_stmt|;
name|rpcb_session_t
modifier|*
name|rs
decl_stmt|;
name|rpc_msg_t
modifier|*
name|rm
decl_stmt|;
block|{
name|rpcb_args_t
modifier|*
name|ra
decl_stmt|;
name|u_32_t
name|xdr
decl_stmt|,
modifier|*
name|p
decl_stmt|;
name|rpc_call_t
modifier|*
name|rc
decl_stmt|;
name|rpcb_xact_t
name|rx
decl_stmt|;
name|int
name|mod
decl_stmt|;
name|p
operator|=
operator|(
name|u_32_t
operator|*
operator|)
name|rm
operator|->
name|rm_msgbuf
expr_stmt|;
name|mod
operator|=
literal|0
expr_stmt|;
name|bzero
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|rx
argument_list|,
sizeof|sizeof
argument_list|(
name|rx
argument_list|)
argument_list|)
expr_stmt|;
name|rc
operator|=
operator|&
name|rm
operator|->
name|rm_call
expr_stmt|;
name|rm
operator|->
name|rm_xid
operator|=
name|p
expr_stmt|;
name|rx
operator|.
name|rx_xid
operator|=
name|B
argument_list|(
name|p
operator|++
argument_list|)
expr_stmt|;
comment|/* Record this message's XID. */
comment|/* Parse out and test the RPC header. */
if|if
condition|(
operator|(
name|B
argument_list|(
name|p
operator|++
argument_list|)
operator|!=
name|RPCB_CALL
operator|)
operator|||
operator|(
name|B
argument_list|(
name|p
operator|++
argument_list|)
operator|!=
name|RPCB_MSG_VERSION
operator|)
operator|||
operator|(
name|B
argument_list|(
name|p
operator|++
argument_list|)
operator|!=
name|RPCB_PROG
operator|)
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Record the RPCB version and procedure. */
name|rc
operator|->
name|rc_vers
operator|=
name|p
operator|++
expr_stmt|;
name|rc
operator|->
name|rc_proc
operator|=
name|p
operator|++
expr_stmt|;
comment|/* Bypass RPC authentication stuff. */
if|if
condition|(
name|ippr_rpcb_skipauth
argument_list|(
name|rm
argument_list|,
operator|&
name|rc
operator|->
name|rc_authcred
argument_list|,
operator|&
name|p
argument_list|)
operator|!=
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|ippr_rpcb_skipauth
argument_list|(
name|rm
argument_list|,
operator|&
name|rc
operator|->
name|rc_authverf
argument_list|,
operator|&
name|p
argument_list|)
operator|!=
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Compare RPCB version and procedure numbers. */
switch|switch
condition|(
name|B
argument_list|(
name|rc
operator|->
name|rc_vers
argument_list|)
condition|)
block|{
case|case
literal|2
case|:
comment|/* This proxy only supports PMAP_GETPORT. */
if|if
condition|(
name|B
argument_list|(
name|rc
operator|->
name|rc_proc
argument_list|)
operator|!=
name|RPCB_GETPORT
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Portmap requests contain four 4 byte parameters. */
if|if
condition|(
name|RPCB_BUF_EQ
argument_list|(
name|rm
argument_list|,
name|p
argument_list|,
literal|16
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|p
operator|+=
literal|2
expr_stmt|;
comment|/* Skip requested program and version numbers. */
comment|/* Sanity check the requested protocol. */
name|xdr
operator|=
name|B
argument_list|(
name|p
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|xdr
operator|==
name|IPPROTO_UDP
operator|||
name|xdr
operator|==
name|IPPROTO_TCP
operator|)
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|rx
operator|.
name|rx_type
operator|=
name|RPCB_RES_PMAP
expr_stmt|;
name|rx
operator|.
name|rx_proto
operator|=
name|xdr
expr_stmt|;
break|break;
case|case
literal|3
case|:
case|case
literal|4
case|:
comment|/* GETADDRLIST is exclusive to v4; GETADDR for v3& v4 */
switch|switch
condition|(
name|B
argument_list|(
name|rc
operator|->
name|rc_proc
argument_list|)
condition|)
block|{
case|case
name|RPCB_GETADDR
case|:
name|rx
operator|.
name|rx_type
operator|=
name|RPCB_RES_STRING
expr_stmt|;
name|rx
operator|.
name|rx_proto
operator|=
operator|(
name|u_int
operator|)
name|fin
operator|->
name|fin_p
expr_stmt|;
break|break;
case|case
name|RPCB_GETADDRLIST
case|:
if|if
condition|(
name|B
argument_list|(
name|rc
operator|->
name|rc_vers
argument_list|)
operator|!=
literal|4
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|rx
operator|.
name|rx_type
operator|=
name|RPCB_RES_LIST
expr_stmt|;
break|break;
default|default:
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|ra
operator|=
operator|&
name|rc
operator|->
name|rc_rpcbargs
expr_stmt|;
comment|/* Decode the 'struct rpcb' request. */
if|if
condition|(
name|ippr_rpcb_xdrrpcb
argument_list|(
name|rm
argument_list|,
name|p
argument_list|,
name|ra
argument_list|)
operator|!=
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Are the target address& port valid? */
if|if
condition|(
operator|(
name|ra
operator|->
name|ra_maddr
operator|.
name|xu_ip
operator|!=
name|nat
operator|->
name|nat_outip
operator|.
name|s_addr
operator|)
operator|||
operator|(
name|ra
operator|->
name|ra_maddr
operator|.
name|xu_port
operator|!=
name|nat
operator|->
name|nat_outport
operator|)
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Do we need to rewrite this packet? */
if|if
condition|(
operator|(
name|nat
operator|->
name|nat_outip
operator|.
name|s_addr
operator|!=
name|nat
operator|->
name|nat_inip
operator|.
name|s_addr
operator|)
operator|||
operator|(
name|nat
operator|->
name|nat_outport
operator|!=
name|nat
operator|->
name|nat_inport
operator|)
condition|)
name|mod
operator|=
literal|1
expr_stmt|;
break|break;
default|default:
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|MUTEX_ENTER
argument_list|(
operator|&
name|rs
operator|->
name|rs_rxlock
argument_list|)
expr_stmt|;
if|if
condition|(
name|ippr_rpcb_insert
argument_list|(
name|rs
argument_list|,
operator|&
name|rx
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|MUTEX_EXIT
argument_list|(
operator|&
name|rs
operator|->
name|rs_rxlock
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|MUTEX_EXIT
argument_list|(
operator|&
name|rs
operator|->
name|rs_rxlock
argument_list|)
expr_stmt|;
return|return
operator|(
name|mod
operator|)
return|;
block|}
end_function

begin_comment
comment|/* --------------------------------------------------------------------	*/
end_comment

begin_comment
comment|/* Function:	ippr_rpcb_skipauth					*/
end_comment

begin_comment
comment|/* Returns:	int -- -1 == illegal auth parameters (lengths)		*/
end_comment

begin_comment
comment|/*			0 == valid parameters, pointer advanced		*/
end_comment

begin_comment
comment|/* Parameters:	rm(I)	- pointer to RPC message structure		*/
end_comment

begin_comment
comment|/*		auth(I)	- pointer to RPC auth structure			*/
end_comment

begin_comment
comment|/*		buf(IO)	- pointer to location within convenience buffer	*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/* Record auth data length& location of auth data, then advance past	*/
end_comment

begin_comment
comment|/* it.									*/
end_comment

begin_comment
comment|/* --------------------------------------------------------------------	*/
end_comment

begin_function
specifier|static
name|int
name|ippr_rpcb_skipauth
parameter_list|(
name|rm
parameter_list|,
name|auth
parameter_list|,
name|buf
parameter_list|)
name|rpc_msg_t
modifier|*
name|rm
decl_stmt|;
name|xdr_auth_t
modifier|*
name|auth
decl_stmt|;
name|u_32_t
modifier|*
modifier|*
name|buf
decl_stmt|;
block|{
name|u_32_t
modifier|*
name|p
decl_stmt|,
name|xdr
decl_stmt|;
name|p
operator|=
operator|*
name|buf
expr_stmt|;
comment|/* Make sure we have enough space for expected fixed auth parms. */
if|if
condition|(
name|RPCB_BUF_GEQ
argument_list|(
name|rm
argument_list|,
name|p
argument_list|,
literal|8
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|p
operator|++
expr_stmt|;
comment|/* We don't care about auth_flavor. */
name|auth
operator|->
name|xa_string
operator|.
name|xs_len
operator|=
name|p
expr_stmt|;
name|xdr
operator|=
name|B
argument_list|(
name|p
operator|++
argument_list|)
expr_stmt|;
comment|/* Length of auth_data */
comment|/* Test for absurdity / illegality of auth_data length. */
if|if
condition|(
operator|(
name|XDRALIGN
argument_list|(
name|xdr
argument_list|)
operator|<
name|xdr
operator|)
operator|||
operator|(
name|RPCB_BUF_GEQ
argument_list|(
name|rm
argument_list|,
name|p
argument_list|,
name|XDRALIGN
argument_list|(
name|xdr
argument_list|)
argument_list|)
operator|==
literal|0
operator|)
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|auth
operator|->
name|xa_string
operator|.
name|xs_str
operator|=
operator|(
name|char
operator|*
operator|)
name|p
expr_stmt|;
name|p
operator|+=
name|XDRALIGN
argument_list|(
name|xdr
argument_list|)
expr_stmt|;
comment|/* Advance our location. */
operator|*
name|buf
operator|=
operator|(
name|u_32_t
operator|*
operator|)
name|p
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/* --------------------------------------------------------------------	*/
end_comment

begin_comment
comment|/* Function:	ippr_rpcb_insert					*/
end_comment

begin_comment
comment|/* Returns:	int -- -1 == list insertion failed,			*/
end_comment

begin_comment
comment|/*			0 == item successfully added			*/
end_comment

begin_comment
comment|/* Parameters:	rs(I)	- pointer to RPCB session structure		*/
end_comment

begin_comment
comment|/*		rx(I)	- pointer to RPCB transaction structure		*/
end_comment

begin_comment
comment|/* --------------------------------------------------------------------	*/
end_comment

begin_function
specifier|static
name|int
name|ippr_rpcb_insert
parameter_list|(
name|rs
parameter_list|,
name|rx
parameter_list|)
name|rpcb_session_t
modifier|*
name|rs
decl_stmt|;
name|rpcb_xact_t
modifier|*
name|rx
decl_stmt|;
block|{
name|rpcb_xact_t
modifier|*
name|rxp
decl_stmt|;
name|rxp
operator|=
name|ippr_rpcb_lookup
argument_list|(
name|rs
argument_list|,
name|rx
operator|->
name|rx_xid
argument_list|)
expr_stmt|;
if|if
condition|(
name|rxp
operator|!=
name|NULL
condition|)
block|{
operator|++
name|rxp
operator|->
name|rx_ref
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
if|if
condition|(
name|rpcbcnt
operator|==
name|RPCB_MAXREQS
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|KMALLOC
argument_list|(
name|rxp
argument_list|,
name|rpcb_xact_t
operator|*
argument_list|)
expr_stmt|;
if|if
condition|(
name|rxp
operator|==
name|NULL
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|bcopy
argument_list|(
operator|(
name|char
operator|*
operator|)
name|rx
argument_list|,
operator|(
name|char
operator|*
operator|)
name|rxp
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|rx
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|rs
operator|->
name|rs_rxlist
operator|!=
name|NULL
condition|)
name|rs
operator|->
name|rs_rxlist
operator|->
name|rx_pnext
operator|=
operator|&
name|rxp
operator|->
name|rx_next
expr_stmt|;
name|rxp
operator|->
name|rx_pnext
operator|=
operator|&
name|rs
operator|->
name|rs_rxlist
expr_stmt|;
name|rxp
operator|->
name|rx_next
operator|=
name|rs
operator|->
name|rs_rxlist
expr_stmt|;
name|rs
operator|->
name|rs_rxlist
operator|=
name|rxp
expr_stmt|;
name|rxp
operator|->
name|rx_ref
operator|=
literal|1
expr_stmt|;
operator|++
name|rpcbcnt
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/* --------------------------------------------------------------------	*/
end_comment

begin_comment
comment|/* Function:	ippr_rpcb_xdrrpcb					*/
end_comment

begin_comment
comment|/* Returns:	int -- -1 == failure to properly decode the request	*/
end_comment

begin_comment
comment|/*			0 == rpcb successfully decoded			*/
end_comment

begin_comment
comment|/* Parameters:	rs(I)	- pointer to RPCB session structure		*/
end_comment

begin_comment
comment|/*		p(I)	- pointer to location within session buffer	*/
end_comment

begin_comment
comment|/*		rpcb(O)	- pointer to rpcb (xdr type) structure		*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/* Decode a XDR encoded rpcb structure and record its contents in rpcb  */
end_comment

begin_comment
comment|/* within only the context of TCP/UDP over IP networks.			*/
end_comment

begin_comment
comment|/* --------------------------------------------------------------------	*/
end_comment

begin_function
specifier|static
name|int
name|ippr_rpcb_xdrrpcb
parameter_list|(
name|rm
parameter_list|,
name|p
parameter_list|,
name|ra
parameter_list|)
name|rpc_msg_t
modifier|*
name|rm
decl_stmt|;
name|u_32_t
modifier|*
name|p
decl_stmt|;
name|rpcb_args_t
modifier|*
name|ra
decl_stmt|;
block|{
if|if
condition|(
operator|!
name|RPCB_BUF_GEQ
argument_list|(
name|rm
argument_list|,
name|p
argument_list|,
literal|20
argument_list|)
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Bypass target program& version. */
name|p
operator|+=
literal|2
expr_stmt|;
comment|/* Decode r_netid.  Must be "tcp" or "udp". */
if|if
condition|(
name|ippr_rpcb_getproto
argument_list|(
name|rm
argument_list|,
operator|&
name|ra
operator|->
name|ra_netid
argument_list|,
operator|&
name|p
argument_list|)
operator|!=
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Decode r_maddr. */
if|if
condition|(
name|ippr_rpcb_getuaddr
argument_list|(
name|rm
argument_list|,
operator|&
name|ra
operator|->
name|ra_maddr
argument_list|,
operator|&
name|p
argument_list|)
operator|!=
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Advance to r_owner and make sure it's empty. */
if|if
condition|(
operator|!
name|RPCB_BUF_EQ
argument_list|(
name|rm
argument_list|,
name|p
argument_list|,
literal|4
argument_list|)
operator|||
operator|(
name|B
argument_list|(
name|p
argument_list|)
operator|!=
literal|0
operator|)
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/* --------------------------------------------------------------------	*/
end_comment

begin_comment
comment|/* Function:	ippr_rpcb_getuaddr					*/
end_comment

begin_comment
comment|/* Returns:	int -- -1 == illegal string,				*/
end_comment

begin_comment
comment|/*			0 == string parsed; contents recorded		*/
end_comment

begin_comment
comment|/* Parameters:	rm(I)	- pointer to RPC message structure		*/
end_comment

begin_comment
comment|/*		xu(I)	- pointer to universal address structure	*/
end_comment

begin_comment
comment|/*		p(IO)	- pointer to location within message buffer	*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/* Decode the IP address / port at p and record them in xu.		*/
end_comment

begin_comment
comment|/* --------------------------------------------------------------------	*/
end_comment

begin_function
specifier|static
name|int
name|ippr_rpcb_getuaddr
parameter_list|(
name|rm
parameter_list|,
name|xu
parameter_list|,
name|p
parameter_list|)
name|rpc_msg_t
modifier|*
name|rm
decl_stmt|;
name|xdr_uaddr_t
modifier|*
name|xu
decl_stmt|;
name|u_32_t
modifier|*
modifier|*
name|p
decl_stmt|;
block|{
name|char
modifier|*
name|c
decl_stmt|,
modifier|*
name|i
decl_stmt|,
modifier|*
name|b
decl_stmt|,
modifier|*
name|pp
decl_stmt|;
name|u_int
name|d
decl_stmt|,
name|dd
decl_stmt|,
name|l
decl_stmt|,
name|t
decl_stmt|;
name|char
name|uastr
index|[
literal|24
index|]
decl_stmt|;
comment|/* Test for string length. */
if|if
condition|(
operator|!
name|RPCB_BUF_GEQ
argument_list|(
name|rm
argument_list|,
operator|*
name|p
argument_list|,
literal|4
argument_list|)
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|xu
operator|->
name|xu_xslen
operator|=
operator|(
operator|*
name|p
operator|)
operator|++
expr_stmt|;
name|xu
operator|->
name|xu_xsstr
operator|=
operator|(
name|char
operator|*
operator|)
operator|*
name|p
expr_stmt|;
comment|/* Length check */
name|l
operator|=
name|B
argument_list|(
name|xu
operator|->
name|xu_xslen
argument_list|)
expr_stmt|;
if|if
condition|(
name|l
operator|<
literal|11
operator|||
name|l
operator|>
literal|23
operator|||
operator|!
name|RPCB_BUF_GEQ
argument_list|(
name|rm
argument_list|,
operator|*
name|p
argument_list|,
name|XDRALIGN
argument_list|(
name|l
argument_list|)
argument_list|)
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Advance p */
operator|*
operator|(
name|char
operator|*
operator|*
operator|)
name|p
operator|+=
name|XDRALIGN
argument_list|(
name|l
argument_list|)
expr_stmt|;
comment|/* Copy string to local buffer& terminate C style */
name|bcopy
argument_list|(
name|xu
operator|->
name|xu_xsstr
argument_list|,
name|uastr
argument_list|,
name|l
argument_list|)
expr_stmt|;
name|uastr
index|[
name|l
index|]
operator|=
literal|'\0'
expr_stmt|;
name|i
operator|=
operator|(
name|char
operator|*
operator|)
operator|&
name|xu
operator|->
name|xu_ip
expr_stmt|;
name|pp
operator|=
operator|(
name|char
operator|*
operator|)
operator|&
name|xu
operator|->
name|xu_port
expr_stmt|;
comment|/* 	 * Expected format: a.b.c.d.e.f where [a-d] correspond to bytes of 	 * an IP address and [ef] are the bytes of a L4 port. 	 */
if|if
condition|(
operator|!
operator|(
name|ISDIGIT
argument_list|(
name|uastr
index|[
literal|0
index|]
argument_list|)
operator|&&
name|ISDIGIT
argument_list|(
name|uastr
index|[
name|l
operator|-
literal|1
index|]
argument_list|)
operator|)
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|b
operator|=
name|uastr
expr_stmt|;
for|for
control|(
name|c
operator|=
operator|&
name|uastr
index|[
literal|1
index|]
operator|,
name|d
operator|=
literal|0
operator|,
name|dd
operator|=
literal|0
init|;
name|c
operator|<
operator|&
name|uastr
index|[
name|l
operator|-
literal|1
index|]
condition|;
name|c
operator|++
control|)
block|{
if|if
condition|(
name|ISDIGIT
argument_list|(
operator|*
name|c
argument_list|)
condition|)
block|{
name|dd
operator|=
literal|0
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
operator|*
name|c
operator|==
literal|'.'
condition|)
block|{
if|if
condition|(
name|dd
operator|!=
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Check for ASCII byte. */
operator|*
name|c
operator|=
literal|'\0'
expr_stmt|;
name|t
operator|=
name|ippr_rpcb_atoi
argument_list|(
name|b
argument_list|)
expr_stmt|;
if|if
condition|(
name|t
operator|>
literal|255
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Aim b at beginning of the next byte. */
name|b
operator|=
name|c
operator|+
literal|1
expr_stmt|;
comment|/* Switch off IP addr vs port parsing. */
if|if
condition|(
name|d
operator|<
literal|4
condition|)
name|i
index|[
name|d
operator|++
index|]
operator|=
name|t
operator|&
literal|0xff
expr_stmt|;
else|else
name|pp
index|[
name|d
operator|++
operator|-
literal|4
index|]
operator|=
name|t
operator|&
literal|0xff
expr_stmt|;
name|dd
operator|=
literal|1
expr_stmt|;
continue|continue;
block|}
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|d
operator|!=
literal|5
condition|)
comment|/* String must contain exactly 5 periods. */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Handle the last byte (port low byte) */
name|t
operator|=
name|ippr_rpcb_atoi
argument_list|(
name|b
argument_list|)
expr_stmt|;
if|if
condition|(
name|t
operator|>
literal|255
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|pp
index|[
name|d
operator|-
literal|4
index|]
operator|=
name|t
operator|&
literal|0xff
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/* --------------------------------------------------------------------	*/
end_comment

begin_comment
comment|/* Function:	ippr_rpcb_atoi (XXX should be generic for all proxies)	*/
end_comment

begin_comment
comment|/* Returns:	int -- integer representation of supplied string	*/
end_comment

begin_comment
comment|/* Parameters:	ptr(I)	- input string					*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/* Simple version of atoi(3) ripped from ip_rcmd_pxy.c.			*/
end_comment

begin_comment
comment|/* --------------------------------------------------------------------	*/
end_comment

begin_function
specifier|static
name|u_int
name|ippr_rpcb_atoi
parameter_list|(
name|ptr
parameter_list|)
name|char
modifier|*
name|ptr
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|s
init|=
name|ptr
decl_stmt|,
name|c
decl_stmt|;
specifier|register
name|u_int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
operator|(
operator|(
name|c
operator|=
operator|*
name|s
operator|++
operator|)
operator|!=
literal|'\0'
operator|)
operator|&&
name|ISDIGIT
argument_list|(
name|c
argument_list|)
condition|)
block|{
name|i
operator|*=
literal|10
expr_stmt|;
name|i
operator|+=
name|c
operator|-
literal|'0'
expr_stmt|;
block|}
return|return
name|i
return|;
block|}
end_function

begin_comment
comment|/* --------------------------------------------------------------------	*/
end_comment

begin_comment
comment|/* Function:	ippr_rpcb_modreq					*/
end_comment

begin_comment
comment|/* Returns:	int -- change in datagram length			*/
end_comment

begin_comment
comment|/*			APR_ERR(2) - critical failure			*/
end_comment

begin_comment
comment|/* Parameters:	fin(I)	- pointer to packet information			*/
end_comment

begin_comment
comment|/*		nat(I)	- pointer to NAT session			*/
end_comment

begin_comment
comment|/*		rm(I)	- pointer to RPC message structure		*/
end_comment

begin_comment
comment|/*		m(I)	- pointer to mbuf chain				*/
end_comment

begin_comment
comment|/*		off(I)	- current offset within mbuf chain		*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/* When external and internal addresses differ, we rewrite the former	*/
end_comment

begin_comment
comment|/* with the latter.  (This is exclusive to protocol versions 3& 4).	*/
end_comment

begin_comment
comment|/* --------------------------------------------------------------------	*/
end_comment

begin_function
specifier|static
name|int
name|ippr_rpcb_modreq
parameter_list|(
name|fin
parameter_list|,
name|nat
parameter_list|,
name|rm
parameter_list|,
name|m
parameter_list|,
name|off
parameter_list|)
name|fr_info_t
modifier|*
name|fin
decl_stmt|;
name|nat_t
modifier|*
name|nat
decl_stmt|;
name|rpc_msg_t
modifier|*
name|rm
decl_stmt|;
name|mb_t
modifier|*
name|m
decl_stmt|;
name|u_int
name|off
decl_stmt|;
block|{
name|u_int
name|len
decl_stmt|,
name|xlen
decl_stmt|,
name|pos
decl_stmt|,
name|bogo
decl_stmt|;
name|rpcb_args_t
modifier|*
name|ra
decl_stmt|;
name|char
name|uaddr
index|[
literal|24
index|]
decl_stmt|;
name|udphdr_t
modifier|*
name|udp
decl_stmt|;
name|char
modifier|*
name|i
decl_stmt|,
modifier|*
name|p
decl_stmt|;
name|int
name|diff
decl_stmt|;
name|ra
operator|=
operator|&
name|rm
operator|->
name|rm_call
operator|.
name|rc_rpcbargs
expr_stmt|;
name|i
operator|=
operator|(
name|char
operator|*
operator|)
operator|&
name|nat
operator|->
name|nat_inip
operator|.
name|s_addr
expr_stmt|;
name|p
operator|=
operator|(
name|char
operator|*
operator|)
operator|&
name|nat
operator|->
name|nat_inport
expr_stmt|;
comment|/* Form new string. */
name|bzero
argument_list|(
name|uaddr
argument_list|,
sizeof|sizeof
argument_list|(
name|uaddr
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Just in case we need padding. */
if|#
directive|if
name|defined
argument_list|(
name|SNPRINTF
argument_list|)
operator|&&
name|defined
argument_list|(
name|_KERNEL
argument_list|)
name|SNPRINTF
argument_list|(
argument|uaddr
argument_list|,
argument|sizeof(uaddr)
argument_list|,
else|#
directive|else
argument|(void) sprintf(uaddr,
endif|#
directive|endif
literal|"%u.%u.%u.%u.%u.%u"
argument|, i[
literal|0
argument|]&
literal|0xff
argument|, i[
literal|1
argument|]&
literal|0xff
argument|, 		       i[
literal|2
argument|]&
literal|0xff
argument|, i[
literal|3
argument|]&
literal|0xff
argument|, p[
literal|0
argument|]&
literal|0xff
argument|, p[
literal|1
argument|]&
literal|0xff
argument|); 	len = strlen(uaddr); 	xlen = XDRALIGN(len);
comment|/* Determine mbuf offset to start writing to. */
argument|pos = (char *)ra->ra_maddr.xu_xslen - rm->rm_msgbuf; 	off += pos;
comment|/* Write new string length. */
argument|bogo = htonl(len); 	COPYBACK(m, off,
literal|4
argument|, (caddr_t)&bogo); 	off +=
literal|4
argument|;
comment|/* Write new string. */
argument|COPYBACK(m, off, xlen, uaddr); 	off += xlen;
comment|/* Write in zero r_owner. */
argument|bogo =
literal|0
argument|; 	COPYBACK(m, off,
literal|4
argument|, (caddr_t)&bogo);
comment|/* Determine difference in data lengths. */
argument|diff = xlen - XDRALIGN(B(ra->ra_maddr.xu_xslen));
comment|/* 	 * If our new string has a different length, make necessary 	 * adjustments. 	 */
argument|if (diff !=
literal|0
argument|) { 		udp = fin->fin_dp; 		udp->uh_ulen = htons(ntohs(udp->uh_ulen) + diff); 		fin->fin_ip->ip_len += diff; 		fin->fin_dlen += diff; 		fin->fin_plen += diff;
comment|/* XXX Storage lengths. */
argument|}  	return(diff); }
comment|/* --------------------------------------------------------------------	*/
comment|/* Function:	ippr_rpcb_decoderep					*/
comment|/* Returns:	int - -1 == bad request or critical failure,		*/
comment|/*		       0 == valid, negative reply			*/
comment|/*		       1 == vaddlid, positive reply; needs no changes	*/
comment|/* Parameters:	fin(I)	- pointer to packet information			*/
comment|/*		nat(I)	- pointer to NAT session structure		*/
comment|/*		rs(I)	- pointer to RPCB session structure		*/
comment|/*		rm(I)	- pointer to RPC message structure		*/
comment|/*		rxp(O)	- pointer to RPCB transaction structure		*/
comment|/*									*/
comment|/* Take a presumed RPCB reply, extract the XID, search for the original */
comment|/* request information, and determine whether the request was accepted	*/
comment|/* or rejected.  With a valid accepted reply, go ahead and create NAT	*/
comment|/* and state entries, and finish up by rewriting the packet as 		*/
comment|/* required.								*/
comment|/*									*/
comment|/* WARNING:  It's the responsibility of the caller to make sure there	*/
comment|/* is enough room in rs_buf for the basic RPC message "preamble".	*/
comment|/* --------------------------------------------------------------------	*/
argument|static int ippr_rpcb_decoderep(fin, nat, rs, rm, rxp) 	fr_info_t *fin; 	nat_t *nat; 	rpcb_session_t *rs; 	rpc_msg_t *rm; 	rpcb_xact_t **rxp; { 	rpcb_listp_t *rl; 	rpcb_entry_t *re; 	rpcb_xact_t *rx; 	u_32_t xdr
argument_list|,
argument|*p; 	rpc_resp_t *rr; 	int rv
argument_list|,
argument|cnt;  	p = (u_32_t *)rm->rm_msgbuf;  	bzero((char *)&rx, sizeof(rx)); 	rr =&rm->rm_resp;  	rm->rm_xid = p; 	xdr = B(p++);
comment|/* Record this message's XID. */
comment|/* Lookup XID */
argument|MUTEX_ENTER(&rs->rs_rxlock); 	if ((rx = ippr_rpcb_lookup(rs, xdr)) == NULL) {                 MUTEX_EXIT(&rs->rs_rxlock); 		return(-
literal|1
argument|);         }         ++rx->rx_ref;
comment|/* per thread reference */
argument|MUTEX_EXIT(&rs->rs_rxlock);  	*rxp = rx;
comment|/* Test call vs reply */
argument|if (B(p++) != RPCB_REPLY) 		return(-
literal|1
argument|);
comment|/* Test reply_stat */
argument|switch(B(p++)) 	{ 	case RPCB_MSG_DENIED: 		return(
literal|0
argument|); 	case RPCB_MSG_ACCEPTED: 		break; 	default: 		return(-
literal|1
argument|); 	}
comment|/* Bypass RPC authentication stuff. */
argument|if (ippr_rpcb_skipauth(rm,&rr->rr_authverf,&p) !=
literal|0
argument|) 		return(-
literal|1
argument|);
comment|/* Test accept status */
argument|if (!RPCB_BUF_GEQ(rm, p,
literal|4
argument|)) 		return(-
literal|1
argument|); 	if (B(p++) !=
literal|0
argument|) 		return(
literal|0
argument|);
comment|/* Parse out the expected reply */
argument|switch(rx->rx_type) 	{ 	case RPCB_RES_PMAP:
comment|/* There must be only one 4 byte argument. */
argument|if (!RPCB_BUF_EQ(rm, p,
literal|4
argument|)) 			return(-
literal|1
argument|); 		 		rr->rr_v2 = p; 		xdr = B(rr->rr_v2);
comment|/* Reply w/ a 0 port indicates service isn't registered */
argument|if (xdr ==
literal|0
argument|) 			return(
literal|0
argument|);
comment|/* Is the value sane? */
argument|if (xdr>
literal|65535
argument|) 			return(-
literal|1
argument|);
comment|/* Create NAT& state table entries. */
argument|if (ippr_rpcb_getnat(fin, nat, rx->rx_proto, (u_int)xdr) !=
literal|0
argument|) 			return(-
literal|1
argument|); 		break; 	case RPCB_RES_STRING:
comment|/* Expecting a XDR string; need 4 bytes for length */
argument|if (!RPCB_BUF_GEQ(rm, p,
literal|4
argument|)) 			return(-
literal|1
argument|);  		rr->rr_v3.xu_str.xs_len = p++; 		rr->rr_v3.xu_str.xs_str = (char *)p;  		xdr = B(rr->rr_v3.xu_xslen);
comment|/* A null string indicates an unregistered service */
argument|if ((xdr ==
literal|0
argument|)&& RPCB_BUF_EQ(rm, p,
literal|0
argument|)) 			return(
literal|0
argument|);
comment|/* Decode the target IP address / port. */
argument|if (ippr_rpcb_getuaddr(rm,&rr->rr_v3,&p) !=
literal|0
argument|) 			return(-
literal|1
argument|);
comment|/* Validate the IP address and port contained. */
argument|if (nat->nat_inip.s_addr != rr->rr_v3.xu_ip) 			return(-
literal|1
argument|);
comment|/* Create NAT& state table entries. */
argument|if (ippr_rpcb_getnat(fin, nat, rx->rx_proto, 				     (u_int)rr->rr_v3.xu_port) !=
literal|0
argument|) 			return(-
literal|1
argument|); 		break; 	case RPCB_RES_LIST: 		if (!RPCB_BUF_GEQ(rm, p,
literal|4
argument|)) 			return(-
literal|1
argument|);
comment|/* rpcb_entry_list_ptr */
argument|switch(B(p)) 		{ 		case
literal|0
argument|: 			return(
literal|0
argument|);
comment|/*NOTREACHED*/
argument|break; 		case
literal|1
argument|: 			break; 		default: 			return(-
literal|1
argument|); 		} 		rl =&rr->rr_v4; 		rl->rl_list = p++; 		cnt =
literal|0
argument|;  		for(;;) { 			re =&rl->rl_entries[rl->rl_cnt]; 			if (ippr_rpcb_getuaddr(rm,&re->re_maddr,&p) !=
literal|0
argument|) 				return(-
literal|1
argument|); 			if (ippr_rpcb_getproto(rm,&re->re_netid,&p) !=
literal|0
argument|) 				return(-
literal|1
argument|);
comment|/* re_semantics& re_pfamily length */
argument|if (!RPCB_BUF_GEQ(rm, p,
literal|12
argument|)) 				return(-
literal|1
argument|); 			p++;
comment|/* Skipping re_semantics. */
argument|xdr = B(p++); 			if ((xdr !=
literal|4
argument|) || strncmp((char *)p,
literal|"inet"
argument|,
literal|4
argument|)) 				return(-
literal|1
argument|); 			p++; 			if (ippr_rpcb_getproto(rm,&re->re_proto,&p) !=
literal|0
argument|) 				return(-
literal|1
argument|); 			if (!RPCB_BUF_GEQ(rm, p,
literal|4
argument|)) 				return(-
literal|1
argument|); 			re->re_more = p; 			if (B(re->re_more)>
literal|1
argument|)
comment|/* 0,1 only legal values */
argument|return(-
literal|1
argument|); 			++rl->rl_cnt; 			++cnt; 			if (B(re->re_more) ==
literal|0
argument|) 				break;
comment|/* Replies in  max out at 2; TCP and/or UDP */
argument|if (cnt>
literal|2
argument|) 				return(-
literal|1
argument|); 			p++; 		}  		for(rl->rl_cnt =
literal|0
argument|; rl->rl_cnt< cnt; rl->rl_cnt++) { 			re =&rl->rl_entries[rl->rl_cnt]; 			rv = ippr_rpcb_getnat(fin, nat, 			                      re->re_proto.xp_proto, 				              (u_int)re->re_maddr.xu_port); 			if (rv !=
literal|0
argument|) 				return(-
literal|1
argument|); 		} 		break; 	default:
comment|/*CONSTANTCONDITION*/
argument|IPF_PANIC(
literal|1
argument|, (
literal|"illegal rx_type %d"
argument|, rx->rx_type)); 	}  	return(
literal|1
argument|); }
comment|/* --------------------------------------------------------------------	*/
comment|/* Function:	ippr_rpcb_lookup					*/
comment|/* Returns:	rpcb_xact_t * 	- NULL == no matching record,		*/
comment|/*				  else pointer to relevant entry	*/
comment|/* Parameters:	rs(I)	- pointer to RPCB session			*/
comment|/*		xid(I)	- XID to look for				*/
comment|/* --------------------------------------------------------------------	*/
argument|static rpcb_xact_t * ippr_rpcb_lookup(rs, xid) 	rpcb_session_t *rs; 	u_32_t xid; { 	rpcb_xact_t *rx;  	if (rs->rs_rxlist == NULL) 		return(NULL);  	for (rx = rs->rs_rxlist; rx != NULL; rx = rx->rx_next) 		if (rx->rx_xid == xid) 			break;  	return(rx); }
comment|/* --------------------------------------------------------------------	*/
comment|/* Function:	ippr_rpcb_deref					        */
comment|/* Returns:	(void)							*/
comment|/* Parameters:	rs(I)	- pointer to RPCB session			*/
comment|/*		rx(I)	- pointer to RPC transaction struct to remove	*/
comment|/*              force(I) - indicates to delete entry regardless of      */
comment|/*                         reference count                              */
comment|/* Locking:	rs->rs_rxlock must be held write only			*/
comment|/*									*/
comment|/* Free the RPCB transaction record rx from the chain of entries.	*/
comment|/* --------------------------------------------------------------------	*/
argument|static void ippr_rpcb_deref(rs, rx) 	rpcb_session_t *rs; 	rpcb_xact_t *rx; { 	rs = rs;
comment|/* LINT */
argument|if (rx == NULL) 		return;  	if (--rx->rx_ref !=
literal|0
argument|) 		return;  	if (rx->rx_next != NULL) 		rx->rx_next->rx_pnext = rx->rx_pnext;  	*rx->rx_pnext = rx->rx_next;  	KFREE(rx);  	--rpcbcnt; }
comment|/* --------------------------------------------------------------------	*/
comment|/* Function:	ippr_rpcb_getproto					*/
comment|/* Returns:	int - -1 == illegal protocol/netid,			*/
comment|/*		       0 == legal protocol/netid			*/
comment|/* Parameters:	rm(I)	- pointer to RPC message structure		*/
comment|/*		xp(I)	- pointer to netid structure			*/
comment|/*		p(IO)	- pointer to location within packet buffer	*/
comment|/* 									*/
comment|/* Decode netid/proto stored at p and record its numeric value.	 	*/
comment|/* --------------------------------------------------------------------	*/
argument|static int ippr_rpcb_getproto(rm, xp, p) 	rpc_msg_t *rm; 	xdr_proto_t *xp; 	u_32_t **p; { 	u_int len;
comment|/* Must have 4 bytes for length& 4 bytes for "tcp" or "udp". */
argument|if (!RPCB_BUF_GEQ(rm, p,
literal|8
argument|)) 		return(-
literal|1
argument|);  	xp->xp_xslen = (*p)++; 	xp->xp_xsstr = (char *)*p;
comment|/* Test the string length. */
argument|len = B(xp->xp_xslen); 	if (len !=
literal|3
argument|) 	 	return(-
literal|1
argument|);
comment|/* Test the actual string& record the protocol accordingly. */
argument|if (!strncmp((char *)xp->xp_xsstr,
literal|"tcp\0"
argument|,
literal|4
argument|)) 		xp->xp_proto = IPPROTO_TCP; 	else if (!strncmp((char *)xp->xp_xsstr,
literal|"udp\0"
argument|,
literal|4
argument|)) 		xp->xp_proto = IPPROTO_UDP; 	else { 		return(-
literal|1
argument|); 	}
comment|/* Advance past the string. */
argument|(*p)++;  	return(
literal|0
argument|); }
comment|/* --------------------------------------------------------------------	*/
comment|/* Function:	ippr_rpcb_getnat					*/
comment|/* Returns:	int -- -1 == failed to create table entries,		*/
comment|/*			0 == success					*/
comment|/* Parameters:	fin(I)	- pointer to packet information			*/
comment|/*		nat(I)	- pointer to NAT table entry			*/
comment|/*		proto(I) - transport protocol for new entries		*/
comment|/*		port(I)	- new port to use w/ wildcard table entries	*/
comment|/*									*/
comment|/* Create state and NAT entries to handle an anticipated connection	*/
comment|/* attempt between RPC client and server.				*/
comment|/* --------------------------------------------------------------------	*/
argument|static int ippr_rpcb_getnat(fin, nat, proto, port) 	fr_info_t *fin; 	nat_t *nat; 	u_int proto; 	u_int port; { 	ipnat_t *ipn
argument_list|,
argument|ipnat; 	tcphdr_t tcp; 	ipstate_t *is; 	fr_info_t fi; 	nat_t *natl; 	int nflags;  	ipn = nat->nat_ptr;
comment|/* Generate dummy fr_info */
argument|bcopy((char *)fin, (char *)&fi, sizeof(fi)); 	fi.fin_out =
literal|0
argument|; 	fi.fin_src = fin->fin_dst; 	fi.fin_dst = nat->nat_outip; 	fi.fin_p = proto; 	fi.fin_sport =
literal|0
argument|; 	fi.fin_dport = port&
literal|0xffff
argument|; 	fi.fin_flx |= FI_IGNORE;  	bzero((char *)&tcp, sizeof(tcp)); 	tcp.th_dport = htons(port);  	if (proto == IPPROTO_TCP) { 		tcp.th_win = htons(
literal|8192
argument|); 		TCP_OFF_A(&tcp, sizeof(tcphdr_t)>>
literal|2
argument|); 		fi.fin_dlen = sizeof(tcphdr_t); 		tcp.th_flags = TH_SYN; 		nflags = NAT_TCP; 	} else { 		fi.fin_dlen = sizeof(udphdr_t); 		nflags = NAT_UDP; 	}  	nflags |= SI_W_SPORT|NAT_SEARCH; 	fi.fin_dp =&tcp; 	fi.fin_plen = fi.fin_hlen + fi.fin_dlen;
comment|/* 	 * Search for existing NAT& state entries.  Pay close attention to 	 * mutexes / locks grabbed from lookup routines, as not doing so could 	 * lead to bad things. 	 * 	 * If successful, fr_stlookup returns with ipf_state locked.  We have 	 * no use for this lock, so simply unlock it if necessary. 	 */
argument|is = fr_stlookup(&fi,&tcp, NULL); 	if (is != NULL) 		RWLOCK_EXIT(&ipf_state);  	RWLOCK_EXIT(&ipf_nat);  	WRITE_ENTER(&ipf_nat); 	natl = nat_inlookup(&fi, nflags, proto, fi.fin_src, fi.fin_dst);  	if ((natl != NULL)&& (is != NULL)) { 		MUTEX_DOWNGRADE(&ipf_nat); 		return(
literal|0
argument|); 	}
comment|/* Slightly modify the following structures for actual use in creating 	 * NAT and/or state entries.  We're primarily concerned with stripping 	 * flags that may be detrimental to the creation process or simply 	 * shouldn't be associated with a table entry. 	 */
argument|fi.fin_fr =&rpcbfr; 	fi.fin_flx&= ~FI_IGNORE; 	nflags&= ~NAT_SEARCH;  	if (natl == NULL) {
comment|/* XXX Since we're just copying the original ipn contents 		 * back, would we be better off just sending a pointer to 		 * the 'temp' copy off to nat_new instead? 		 */
comment|/* Generate template/bogus NAT rule. */
argument|bcopy((char *)ipn, (char *)&ipnat, sizeof(ipnat)); 		ipn->in_flags = nflags& IPN_TCPUDP; 		ipn->in_apr = NULL; 		ipn->in_p = proto; 		ipn->in_pmin = htons(fi.fin_dport); 		ipn->in_pmax = htons(fi.fin_dport); 		ipn->in_pnext = htons(fi.fin_dport); 		ipn->in_space =
literal|1
argument|; 		ipn->in_ippip =
literal|1
argument|; 		if (ipn->in_flags& IPN_FILTER) { 			ipn->in_scmp =
literal|0
argument|; 			ipn->in_dcmp =
literal|0
argument|; 		} 		*ipn->in_plabel =
literal|'\0'
argument|;
comment|/* Create NAT entry.  return NULL if this fails. */
argument|natl = nat_new(&fi, ipn, NULL, nflags|SI_CLONE|NAT_SLAVE, 			       NAT_INBOUND);  		bcopy((char *)&ipnat, (char *)ipn, sizeof(ipnat));  		if (natl == NULL) { 			MUTEX_DOWNGRADE(&ipf_nat); 			return(-
literal|1
argument|); 		}  		ipn->in_use++; 		(void) nat_proto(&fi, natl, nflags); 		nat_update(&fi, natl, natl->nat_ptr); 	} 	MUTEX_DOWNGRADE(&ipf_nat);  	if (is == NULL) {
comment|/* Create state entry.  Return NULL if this fails. */
argument|fi.fin_dst = nat->nat_inip; 		fi.fin_nat = (void *)natl; 		fi.fin_flx |= FI_NATED; 		fi.fin_flx&= ~FI_STATE; 		nflags&= NAT_TCPUDP; 		nflags |= SI_W_SPORT|SI_CLONE;  		is = fr_addstate(&fi, NULL, nflags); 		if (is == NULL) {
comment|/* 			 * XXX nat_delete is private to ip_nat.c.  Should 			 * check w/ Darren about this one. 			 * 			 * nat_delete(natl, NL_EXPIRE); 			 */
argument|return(-
literal|1
argument|); 		} 		if (fi.fin_state != NULL) 			fr_statederef(&fi, (ipstate_t **)&fi.fin_state); 	}  	return(
literal|0
argument|); }
comment|/* --------------------------------------------------------------------	*/
comment|/* Function:	ippr_rpcb_modv3						*/
comment|/* Returns:	int -- change in packet length				*/
comment|/* Parameters:	fin(I)	- pointer to packet information			*/
comment|/*		nat(I)	- pointer to NAT session			*/
comment|/*		rm(I)	- pointer to RPC message structure		*/
comment|/*		m(I)	- pointer to mbuf chain				*/
comment|/*		off(I)	- offset within mbuf chain			*/
comment|/*									*/
comment|/* Write a new universal address string to this packet, adjusting	*/
comment|/* lengths as necessary.						*/
comment|/* --------------------------------------------------------------------	*/
argument|static int ippr_rpcb_modv3(fin, nat, rm, m, off) 	fr_info_t *fin; 	nat_t *nat; 	rpc_msg_t *rm; 	mb_t *m; 	u_int off; { 	u_int len
argument_list|,
argument|xlen
argument_list|,
argument|pos
argument_list|,
argument|bogo; 	rpc_resp_t *rr; 	char uaddr[
literal|24
argument|]; 	char *i
argument_list|,
argument|*p; 	int diff;  	rr =&rm->rm_resp; 	i = (char *)&nat->nat_outip.s_addr; 	p = (char *)&rr->rr_v3.xu_port;
comment|/* Form new string. */
argument|bzero(uaddr, sizeof(uaddr));
comment|/* Just in case we need padding. */
if|#
directive|if
name|defined
argument_list|(
name|SNPRINTF
argument_list|)
operator|&&
name|defined
argument_list|(
name|_KERNEL
argument_list|)
argument|SNPRINTF(uaddr, sizeof(uaddr),
else|#
directive|else
argument|(void) sprintf(uaddr,
endif|#
directive|endif
literal|"%u.%u.%u.%u.%u.%u"
argument|, i[
literal|0
argument|]&
literal|0xff
argument|, i[
literal|1
argument|]&
literal|0xff
argument|, 		       i[
literal|2
argument|]&
literal|0xff
argument|, i[
literal|3
argument|]&
literal|0xff
argument|, p[
literal|0
argument|]&
literal|0xff
argument|, p[
literal|1
argument|]&
literal|0xff
argument|); 	len = strlen(uaddr); 	xlen = XDRALIGN(len);
comment|/* Determine mbuf offset to write to. */
argument|pos = (char *)rr->rr_v3.xu_xslen - rm->rm_msgbuf; 	off += pos;
comment|/* Write new string length. */
argument|bogo = htonl(len); 	COPYBACK(m, off,
literal|4
argument|, (caddr_t)&bogo); 	off +=
literal|4
argument|;
comment|/* Write new string. */
argument|COPYBACK(m, off, xlen, uaddr);
comment|/* Determine difference in data lengths. */
argument|diff = xlen - XDRALIGN(B(rr->rr_v3.xu_xslen));
comment|/* 	 * If our new string has a different length, make necessary 	 * adjustments. 	 */
argument|if (diff !=
literal|0
argument|) 		ippr_rpcb_fixlen(fin, diff);  	return(diff); }
comment|/* --------------------------------------------------------------------	*/
comment|/* Function:	ippr_rpcb_modv4						*/
comment|/* Returns:	int -- change in packet length				*/
comment|/* Parameters:	fin(I)	- pointer to packet information			*/
comment|/*		nat(I)	- pointer to NAT session			*/
comment|/*		rm(I)	- pointer to RPC message structure		*/
comment|/*		m(I)	- pointer to mbuf chain				*/
comment|/*		off(I)	- offset within mbuf chain			*/
comment|/*									*/
comment|/* Write new rpcb_entry list, adjusting	lengths as necessary.		*/
comment|/* --------------------------------------------------------------------	*/
argument|static int ippr_rpcb_modv4(fin, nat, rm, m, off) 	fr_info_t *fin; 	nat_t *nat; 	rpc_msg_t *rm; 	mb_t *m; 	u_int off; { 	u_int len, xlen, pos, bogo; 	rpcb_listp_t *rl; 	rpcb_entry_t *re; 	rpc_resp_t *rr; 	char uaddr[
literal|24
argument|]; 	int diff, cnt; 	char *i, *p;  	diff =
literal|0
argument|; 	rr =&rm->rm_resp; 	rl =&rr->rr_v4;  	i = (char *)&nat->nat_outip.s_addr;
comment|/* Determine mbuf offset to write to. */
argument|re =&rl->rl_entries[
literal|0
argument|]; 	pos = (char *)re->re_maddr.xu_xslen - rm->rm_msgbuf; 	off += pos;  	for (cnt =
literal|0
argument|; cnt< rl->rl_cnt; cnt++) { 		re =&rl->rl_entries[cnt]; 		p = (char *)&re->re_maddr.xu_port;
comment|/* Form new string. */
argument|bzero(uaddr, sizeof(uaddr));
comment|/* Just in case we need 						padding. */
if|#
directive|if
name|defined
argument_list|(
name|SNPRINTF
argument_list|)
operator|&&
name|defined
argument_list|(
name|_KERNEL
argument_list|)
argument|SNPRINTF(uaddr, sizeof(uaddr),
else|#
directive|else
argument|(void) sprintf(uaddr,
endif|#
directive|endif
literal|"%u.%u.%u.%u.%u.%u"
argument|, i[
literal|0
argument|]&
literal|0xff
argument|, 			       i[
literal|1
argument|]&
literal|0xff
argument|, i[
literal|2
argument|]&
literal|0xff
argument|, i[
literal|3
argument|]&
literal|0xff
argument|, 			       p[
literal|0
argument|]&
literal|0xff
argument|, p[
literal|1
argument|]&
literal|0xff
argument|); 		len = strlen(uaddr); 		xlen = XDRALIGN(len);
comment|/* Write new string length. */
argument|bogo = htonl(len); 		COPYBACK(m, off,
literal|4
argument|, (caddr_t)&bogo); 		off +=
literal|4
argument|;
comment|/* Write new string. */
argument|COPYBACK(m, off, xlen, uaddr); 		off += xlen;
comment|/* Record any change in length. */
argument|diff += xlen - XDRALIGN(B(re->re_maddr.xu_xslen));
comment|/* If the length changed, copy back the rest of this entry. */
argument|len = ((char *)re->re_more +
literal|4
argument|) - 		       (char *)re->re_netid.xp_xslen; 		if (diff !=
literal|0
argument|) { 			COPYBACK(m, off, len, (caddr_t)re->re_netid.xp_xslen); 		} 		off += len; 	}
comment|/* 	 * If our new string has a different length, make necessary 	 * adjustments. 	 */
argument|if (diff !=
literal|0
argument|) 		ippr_rpcb_fixlen(fin, diff);  	return(diff); }
comment|/* --------------------------------------------------------------------	*/
comment|/* Function:    ippr_rpcb_fixlen                                        */
comment|/* Returns:     (void)                                                  */
comment|/* Parameters:  fin(I)  - pointer to packet information                 */
comment|/*              len(I)  - change in packet length                       */
comment|/*                                                                      */
comment|/* Adjust various packet related lengths held in structure and packet   */
comment|/* header fields.                                                       */
comment|/* --------------------------------------------------------------------	*/
argument|static void ippr_rpcb_fixlen(fin, len)         fr_info_t *fin;         int len; {         udphdr_t *udp;          udp = fin->fin_dp;         udp->uh_ulen = htons(ntohs(udp->uh_ulen) + len);         fin->fin_ip->ip_len += len;         fin->fin_dlen += len;         fin->fin_plen += len; }
end_function

begin_undef
undef|#
directive|undef
name|B
end_undef

end_unit

