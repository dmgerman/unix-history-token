begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1997-2001 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  *  * $FreeBSD$  * Id: ip_proxy.h,v 2.31.2.2 2005/03/12 19:33:48 darrenr Exp  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IP_PROXY_H__
end_ifndef

begin_define
define|#
directive|define
name|__IP_PROXY_H__
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SOLARIS
end_ifndef

begin_define
define|#
directive|define
name|SOLARIS
value|(defined(sun)&& (defined(__svr4__) || defined(__SVR4)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIOCPROXY
value|_IOWR('r', 64, struct ap_control)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIOCPROXY
value|_IOWR(r, 64, struct ap_control)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|APR_LABELLEN
end_ifndef

begin_define
define|#
directive|define
name|APR_LABELLEN
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|AP_SESS_SIZE
value|53
end_define

begin_struct_decl
struct_decl|struct
name|nat
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ipnat
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ipstate
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
struct|struct
name|ap_tcp
block|{
name|u_short
name|apt_sport
decl_stmt|;
comment|/* source port */
name|u_short
name|apt_dport
decl_stmt|;
comment|/* destination port */
name|short
name|apt_sel
index|[
literal|2
index|]
decl_stmt|;
comment|/* {seq,ack}{off,min} set selector */
name|short
name|apt_seqoff
index|[
literal|2
index|]
decl_stmt|;
comment|/* sequence # difference */
name|u_32_t
name|apt_seqmin
index|[
literal|2
index|]
decl_stmt|;
comment|/* don't change seq-off until after this */
name|short
name|apt_ackoff
index|[
literal|2
index|]
decl_stmt|;
comment|/* sequence # difference */
name|u_32_t
name|apt_ackmin
index|[
literal|2
index|]
decl_stmt|;
comment|/* don't change seq-off until after this */
name|u_char
name|apt_state
index|[
literal|2
index|]
decl_stmt|;
comment|/* connection state */
block|}
name|ap_tcp_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ap_udp
block|{
name|u_short
name|apu_sport
decl_stmt|;
comment|/* source port */
name|u_short
name|apu_dport
decl_stmt|;
comment|/* destination port */
block|}
name|ap_udp_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ap_session
block|{
name|struct
name|aproxy
modifier|*
name|aps_apr
decl_stmt|;
union|union
block|{
name|struct
name|ap_tcp
name|apu_tcp
decl_stmt|;
name|struct
name|ap_udp
name|apu_udp
decl_stmt|;
block|}
name|aps_un
union|;
name|u_int
name|aps_flags
decl_stmt|;
name|U_QUAD_T
name|aps_bytes
decl_stmt|;
comment|/* bytes sent */
name|U_QUAD_T
name|aps_pkts
decl_stmt|;
comment|/* packets sent */
name|void
modifier|*
name|aps_nat
decl_stmt|;
comment|/* pointer back to nat struct */
name|void
modifier|*
name|aps_data
decl_stmt|;
comment|/* private data */
name|int
name|aps_p
decl_stmt|;
comment|/* protocol */
name|int
name|aps_psiz
decl_stmt|;
comment|/* size of private data */
name|struct
name|ap_session
modifier|*
name|aps_hnext
decl_stmt|;
name|struct
name|ap_session
modifier|*
name|aps_next
decl_stmt|;
block|}
name|ap_session_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|aps_sport
value|aps_un.apu_tcp.apt_sport
end_define

begin_define
define|#
directive|define
name|aps_dport
value|aps_un.apu_tcp.apt_dport
end_define

begin_define
define|#
directive|define
name|aps_sel
value|aps_un.apu_tcp.apt_sel
end_define

begin_define
define|#
directive|define
name|aps_seqoff
value|aps_un.apu_tcp.apt_seqoff
end_define

begin_define
define|#
directive|define
name|aps_seqmin
value|aps_un.apu_tcp.apt_seqmin
end_define

begin_define
define|#
directive|define
name|aps_state
value|aps_un.apu_tcp.apt_state
end_define

begin_define
define|#
directive|define
name|aps_ackoff
value|aps_un.apu_tcp.apt_ackoff
end_define

begin_define
define|#
directive|define
name|aps_ackmin
value|aps_un.apu_tcp.apt_ackmin
end_define

begin_typedef
typedef|typedef
struct|struct
name|ap_control
block|{
name|char
name|apc_label
index|[
name|APR_LABELLEN
index|]
decl_stmt|;
name|u_char
name|apc_p
decl_stmt|;
comment|/* 	 * The following fields are upto the proxy's apr_ctl routine to deal 	 * with.  When the proxy gets this in kernel space, apc_data will 	 * point to a malloc'd region of memory of apc_dsize bytes.  If the 	 * proxy wants to keep that memory, it must set apc_data to NULL 	 * before it returns.  It is expected if this happens that it will 	 * take care to free it in apr_fini or otherwise as appropriate. 	 * apc_cmd is provided as a standard place to put simple commands, 	 * with apc_arg being available to put a simple arg. 	 */
name|u_long
name|apc_cmd
decl_stmt|;
name|u_long
name|apc_arg
decl_stmt|;
name|void
modifier|*
name|apc_data
decl_stmt|;
name|size_t
name|apc_dsize
decl_stmt|;
block|}
name|ap_ctl_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|aproxy
block|{
name|struct
name|aproxy
modifier|*
name|apr_next
decl_stmt|;
name|char
name|apr_label
index|[
name|APR_LABELLEN
index|]
decl_stmt|;
comment|/* Proxy label # */
name|u_char
name|apr_p
decl_stmt|;
comment|/* protocol */
name|int
name|apr_ref
decl_stmt|;
comment|/* +1 per rule referencing it */
name|int
name|apr_flags
decl_stmt|;
name|int
argument_list|(
argument|* apr_init
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|* apr_fini
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|* apr_new
argument_list|)
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|ap_session_t
operator|*
operator|,
expr|struct
name|nat
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|* apr_del
argument_list|)
name|__P
argument_list|(
operator|(
name|ap_session_t
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|* apr_inpkt
argument_list|)
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|ap_session_t
operator|*
operator|,
expr|struct
name|nat
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|* apr_outpkt
argument_list|)
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|ap_session_t
operator|*
operator|,
expr|struct
name|nat
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|* apr_match
argument_list|)
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|ap_session_t
operator|*
operator|,
expr|struct
name|nat
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|* apr_ctl
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|aproxy
operator|*
operator|,
expr|struct
name|ap_control
operator|*
operator|)
argument_list|)
expr_stmt|;
block|}
name|aproxy_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|APR_DELETE
value|1
end_define

begin_define
define|#
directive|define
name|APR_ERR
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|APR_EXIT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xffff)
end_define

begin_define
define|#
directive|define
name|APR_INC
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xffff)
end_define

begin_comment
comment|/*  * Generic #define's to cover missing things in the kernel  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|isdigit
end_ifndef

begin_define
define|#
directive|define
name|isdigit
parameter_list|(
name|x
parameter_list|)
value|((x)>= '0'&& (x)<= '9')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|isupper
end_ifndef

begin_define
define|#
directive|define
name|isupper
parameter_list|(
name|x
parameter_list|)
value|(((unsigned)(x)>= 'A')&& ((unsigned)(x)<= 'Z'))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|islower
end_ifndef

begin_define
define|#
directive|define
name|islower
parameter_list|(
name|x
parameter_list|)
value|(((unsigned)(x)>= 'a')&& ((unsigned)(x)<= 'z'))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|isalpha
end_ifndef

begin_define
define|#
directive|define
name|isalpha
parameter_list|(
name|x
parameter_list|)
value|(isupper(x) || islower(x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|toupper
end_ifndef

begin_define
define|#
directive|define
name|toupper
parameter_list|(
name|x
parameter_list|)
value|(isupper(x) ? (x) : (x) - 'a' + 'A')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|isspace
end_ifndef

begin_define
define|#
directive|define
name|isspace
parameter_list|(
name|x
parameter_list|)
value|(((x) == ' ') || ((x) == '\r') || ((x) == '\n') || \ 			 ((x) == '\t') || ((x) == '\b'))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This is the scratch buffer size used to hold strings from the TCP stream  * that we may want to parse.  It's an arbitrary size, really, but it must  * be at least as large as IPF_FTPBUFSZ.  */
end_comment

begin_define
define|#
directive|define
name|FTP_BUFSZ
value|120
end_define

begin_comment
comment|/*  * This buffer, however, doesn't need to be nearly so big.  It just needs to  * be able to squeeze in the largest command it needs to rewrite, Which ones  * does it rewrite? EPRT, PORT, 227 replies.  */
end_comment

begin_define
define|#
directive|define
name|IPF_FTPBUFSZ
value|80
end_define

begin_comment
comment|/* This *MUST* be>= 53! */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ftpside
block|{
name|char
modifier|*
name|ftps_rptr
decl_stmt|;
name|char
modifier|*
name|ftps_wptr
decl_stmt|;
name|void
modifier|*
name|ftps_ifp
decl_stmt|;
name|u_32_t
name|ftps_seq
index|[
literal|2
index|]
decl_stmt|;
name|u_32_t
name|ftps_len
decl_stmt|;
name|int
name|ftps_junk
decl_stmt|;
comment|/* 2 = no cr/lf yet, 1 = cannot parse */
name|int
name|ftps_cmds
decl_stmt|;
name|char
name|ftps_buf
index|[
name|FTP_BUFSZ
index|]
decl_stmt|;
block|}
name|ftpside_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ftpinfo
block|{
name|int
name|ftp_passok
decl_stmt|;
name|int
name|ftp_incok
decl_stmt|;
name|ftpside_t
name|ftp_side
index|[
literal|2
index|]
decl_stmt|;
block|}
name|ftpinfo_t
typedef|;
end_typedef

begin_comment
comment|/*  * For the irc proxy.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ircinfo
block|{
name|size_t
name|irc_len
decl_stmt|;
name|char
modifier|*
name|irc_snick
decl_stmt|;
name|char
modifier|*
name|irc_dnick
decl_stmt|;
name|char
modifier|*
name|irc_type
decl_stmt|;
name|char
modifier|*
name|irc_arg
decl_stmt|;
name|char
modifier|*
name|irc_addr
decl_stmt|;
name|u_32_t
name|irc_ipnum
decl_stmt|;
name|u_short
name|irc_port
decl_stmt|;
block|}
name|ircinfo_t
typedef|;
end_typedef

begin_comment
comment|/*  * Real audio proxy structure and #defines  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|raudio_s
block|{
name|int
name|rap_seenpna
decl_stmt|;
name|int
name|rap_seenver
decl_stmt|;
name|int
name|rap_version
decl_stmt|;
name|int
name|rap_eos
decl_stmt|;
comment|/* End Of Startup */
name|int
name|rap_gotid
decl_stmt|;
name|int
name|rap_gotlen
decl_stmt|;
name|int
name|rap_mode
decl_stmt|;
name|int
name|rap_sdone
decl_stmt|;
name|u_short
name|rap_plport
decl_stmt|;
name|u_short
name|rap_prport
decl_stmt|;
name|u_short
name|rap_srport
decl_stmt|;
name|char
name|rap_svr
index|[
literal|19
index|]
decl_stmt|;
name|u_32_t
name|rap_sbf
decl_stmt|;
comment|/* flag to indicate which of the 19 bytes have 				 * been filled 				 */
name|u_32_t
name|rap_sseq
decl_stmt|;
block|}
name|raudio_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RA_ID_END
value|0
end_define

begin_define
define|#
directive|define
name|RA_ID_UDP
value|1
end_define

begin_define
define|#
directive|define
name|RA_ID_ROBUST
value|7
end_define

begin_define
define|#
directive|define
name|RAP_M_UDP
value|1
end_define

begin_define
define|#
directive|define
name|RAP_M_ROBUST
value|2
end_define

begin_define
define|#
directive|define
name|RAP_M_TCP
value|4
end_define

begin_define
define|#
directive|define
name|RAP_M_UDP_ROBUST
value|(RAP_M_UDP|RAP_M_ROBUST)
end_define

begin_comment
comment|/*  * MSN RPC proxy  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|msnrpcinfo
block|{
name|u_int
name|mri_flags
decl_stmt|;
name|int
name|mri_cmd
index|[
literal|2
index|]
decl_stmt|;
name|u_int
name|mri_valid
decl_stmt|;
name|struct
name|in_addr
name|mri_raddr
decl_stmt|;
name|u_short
name|mri_rport
decl_stmt|;
block|}
name|msnrpcinfo_t
typedef|;
end_typedef

begin_comment
comment|/*  * IPSec proxy  */
end_comment

begin_typedef
typedef|typedef
name|u_32_t
name|ipsec_cookie_t
index|[
literal|2
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ipsec_pxy
block|{
name|ipsec_cookie_t
name|ipsc_icookie
decl_stmt|;
name|ipsec_cookie_t
name|ipsc_rcookie
decl_stmt|;
name|int
name|ipsc_rckset
decl_stmt|;
name|ipnat_t
name|ipsc_rule
decl_stmt|;
name|nat_t
modifier|*
name|ipsc_nat
decl_stmt|;
name|struct
name|ipstate
modifier|*
name|ipsc_state
decl_stmt|;
block|}
name|ipsec_pxy_t
typedef|;
end_typedef

begin_comment
comment|/*  * PPTP proxy  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pptp_side
block|{
name|u_32_t
name|pptps_nexthdr
decl_stmt|;
name|u_32_t
name|pptps_next
decl_stmt|;
name|int
name|pptps_state
decl_stmt|;
name|int
name|pptps_gothdr
decl_stmt|;
name|int
name|pptps_len
decl_stmt|;
name|int
name|pptps_bytes
decl_stmt|;
name|char
modifier|*
name|pptps_wptr
decl_stmt|;
name|char
name|pptps_buffer
index|[
literal|512
index|]
decl_stmt|;
block|}
name|pptp_side_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|pptp_pxy
block|{
name|ipnat_t
name|pptp_rule
decl_stmt|;
name|nat_t
modifier|*
name|pptp_nat
decl_stmt|;
name|struct
name|ipstate
modifier|*
name|pptp_state
decl_stmt|;
name|u_short
name|pptp_call
index|[
literal|2
index|]
decl_stmt|;
name|pptp_side_t
name|pptp_side
index|[
literal|2
index|]
decl_stmt|;
block|}
name|pptp_pxy_t
typedef|;
end_typedef

begin_comment
comment|/*  * Sun RPCBIND proxy  */
end_comment

begin_define
define|#
directive|define
name|RPCB_MAXMSG
value|888
end_define

begin_define
define|#
directive|define
name|RPCB_RES_PMAP
value|0
end_define

begin_comment
comment|/* Response contains a v2 port. */
end_comment

begin_define
define|#
directive|define
name|RPCB_RES_STRING
value|1
end_define

begin_comment
comment|/* " " " v3 (GETADDR) string. */
end_comment

begin_define
define|#
directive|define
name|RPCB_RES_LIST
value|2
end_define

begin_comment
comment|/* " " " v4 (GETADDRLIST) list. */
end_comment

begin_define
define|#
directive|define
name|RPCB_MAXREQS
value|32
end_define

begin_comment
comment|/* Arbitrary limit on tracked transactions */
end_comment

begin_define
define|#
directive|define
name|RPCB_REQMIN
value|40
end_define

begin_define
define|#
directive|define
name|RPCB_REQMAX
value|888
end_define

begin_define
define|#
directive|define
name|RPCB_REPMIN
value|20
end_define

begin_define
define|#
directive|define
name|RPCB_REPMAX
value|604
end_define

begin_comment
comment|/* XXX double check this! */
end_comment

begin_comment
comment|/*  * These macros determine the number of bytes between p and the end of  * r->rs_buf relative to l.  */
end_comment

begin_define
define|#
directive|define
name|RPCB_BUF_END
parameter_list|(
name|r
parameter_list|)
value|(char *)((r)->rm_msgbuf + (r)->rm_buflen)
end_define

begin_define
define|#
directive|define
name|RPCB_BUF_GEQ
parameter_list|(
name|r
parameter_list|,
name|p
parameter_list|,
name|l
parameter_list|)
define|\
value|((RPCB_BUF_END((r))> (char *)(p))&&           \          ((RPCB_BUF_END((r)) - (char *)(p))>= (l)))
end_define

begin_define
define|#
directive|define
name|RPCB_BUF_EQ
parameter_list|(
name|r
parameter_list|,
name|p
parameter_list|,
name|l
parameter_list|)
define|\
value|(RPCB_BUF_END((r)) == ((char *)(p) + (l)))
end_define

begin_comment
comment|/*  * The following correspond to RPC(B) detailed in RFC183[13].  */
end_comment

begin_define
define|#
directive|define
name|RPCB_CALL
value|0
end_define

begin_define
define|#
directive|define
name|RPCB_REPLY
value|1
end_define

begin_define
define|#
directive|define
name|RPCB_MSG_VERSION
value|2
end_define

begin_define
define|#
directive|define
name|RPCB_PROG
value|100000
end_define

begin_define
define|#
directive|define
name|RPCB_GETPORT
value|3
end_define

begin_define
define|#
directive|define
name|RPCB_GETADDR
value|3
end_define

begin_define
define|#
directive|define
name|RPCB_GETADDRLIST
value|11
end_define

begin_define
define|#
directive|define
name|RPCB_MSG_ACCEPTED
value|0
end_define

begin_define
define|#
directive|define
name|RPCB_MSG_DENIED
value|1
end_define

begin_comment
comment|/* BEGIN (Generic XDR structures) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xdr_string
block|{
name|u_32_t
modifier|*
name|xs_len
decl_stmt|;
name|char
modifier|*
name|xs_str
decl_stmt|;
block|}
name|xdr_string_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xdr_auth
block|{
comment|/* u_32_t	xa_flavor; */
name|xdr_string_t
name|xa_string
decl_stmt|;
block|}
name|xdr_auth_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xdr_uaddr
block|{
name|u_32_t
name|xu_ip
decl_stmt|;
name|u_short
name|xu_port
decl_stmt|;
name|xdr_string_t
name|xu_str
decl_stmt|;
block|}
name|xdr_uaddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xdr_proto
block|{
name|u_int
name|xp_proto
decl_stmt|;
name|xdr_string_t
name|xp_str
decl_stmt|;
block|}
name|xdr_proto_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|xu_xslen
value|xu_str.xs_len
end_define

begin_define
define|#
directive|define
name|xu_xsstr
value|xu_str.xs_str
end_define

begin_define
define|#
directive|define
name|xp_xslen
value|xp_str.xs_len
end_define

begin_define
define|#
directive|define
name|xp_xsstr
value|xp_str.xs_str
end_define

begin_comment
comment|/* END (Generic XDR structures) */
end_comment

begin_comment
comment|/* BEGIN (RPC call structures) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pmap_args
block|{
comment|/* u_32_t	pa_prog; */
comment|/* u_32_t	pa_vers; */
name|u_32_t
modifier|*
name|pa_prot
decl_stmt|;
comment|/* u_32_t	pa_port; */
block|}
name|pmap_args_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|rpcb_args
block|{
comment|/* u_32_t	*ra_prog; */
comment|/* u_32_t	*ra_vers; */
name|xdr_proto_t
name|ra_netid
decl_stmt|;
name|xdr_uaddr_t
name|ra_maddr
decl_stmt|;
comment|/* xdr_string_t	ra_owner; */
block|}
name|rpcb_args_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|rpc_call
block|{
comment|/* u_32_t	rc_rpcvers; */
comment|/* u_32_t	rc_prog; */
name|u_32_t
modifier|*
name|rc_vers
decl_stmt|;
name|u_32_t
modifier|*
name|rc_proc
decl_stmt|;
name|xdr_auth_t
name|rc_authcred
decl_stmt|;
name|xdr_auth_t
name|rc_authverf
decl_stmt|;
union|union
block|{
name|pmap_args_t
name|ra_pmapargs
decl_stmt|;
name|rpcb_args_t
name|ra_rpcbargs
decl_stmt|;
block|}
name|rpcb_args
union|;
block|}
name|rpc_call_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|rc_pmapargs
value|rpcb_args.ra_pmapargs
end_define

begin_define
define|#
directive|define
name|rc_rpcbargs
value|rpcb_args.ra_rpcbargs
end_define

begin_comment
comment|/* END (RPC call structures) */
end_comment

begin_comment
comment|/* BEGIN (RPC reply structures) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rpcb_entry
block|{
name|xdr_uaddr_t
name|re_maddr
decl_stmt|;
name|xdr_proto_t
name|re_netid
decl_stmt|;
comment|/* u_32_t	re_semantics; */
name|xdr_string_t
name|re_family
decl_stmt|;
name|xdr_proto_t
name|re_proto
decl_stmt|;
name|u_32_t
modifier|*
name|re_more
decl_stmt|;
comment|/* 1 == another entry follows */
block|}
name|rpcb_entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|rpcb_listp
block|{
name|u_32_t
modifier|*
name|rl_list
decl_stmt|;
comment|/* 1 == list follows */
name|int
name|rl_cnt
decl_stmt|;
name|rpcb_entry_t
name|rl_entries
index|[
literal|2
index|]
decl_stmt|;
comment|/* TCP / UDP only */
block|}
name|rpcb_listp_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|rpc_resp
block|{
comment|/* u_32_t	rr_acceptdeny; */
comment|/* Omitted 'message denied' fork; we don't care about rejects. */
name|xdr_auth_t
name|rr_authverf
decl_stmt|;
comment|/* u_32_t		*rr_astat;	*/
union|union
block|{
name|u_32_t
modifier|*
name|resp_pmap
decl_stmt|;
name|xdr_uaddr_t
name|resp_getaddr
decl_stmt|;
name|rpcb_listp_t
name|resp_getaddrlist
decl_stmt|;
block|}
name|rpcb_reply
union|;
block|}
name|rpc_resp_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|rr_v2
value|rpcb_reply.resp_pmap
end_define

begin_define
define|#
directive|define
name|rr_v3
value|rpcb_reply.resp_getaddr
end_define

begin_define
define|#
directive|define
name|rr_v4
value|rpcb_reply.resp_getaddrlist
end_define

begin_comment
comment|/* END (RPC reply structures) */
end_comment

begin_comment
comment|/* BEGIN (RPC message structure& macros) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rpc_msg
block|{
name|char
name|rm_msgbuf
index|[
name|RPCB_MAXMSG
index|]
decl_stmt|;
comment|/* RPCB data buffer */
name|u_int
name|rm_buflen
decl_stmt|;
name|u_32_t
modifier|*
name|rm_xid
decl_stmt|;
comment|/* u_32_t Call vs Reply */
union|union
block|{
name|rpc_call_t
name|rb_call
decl_stmt|;
name|rpc_resp_t
name|rb_resp
decl_stmt|;
block|}
name|rm_body
union|;
block|}
name|rpc_msg_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|rm_call
value|rm_body.rb_call
end_define

begin_define
define|#
directive|define
name|rm_resp
value|rm_body.rb_resp
end_define

begin_comment
comment|/* END (RPC message structure& macros) */
end_comment

begin_comment
comment|/*  * These code paths aren't hot enough to warrant per transaction  * mutexes.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rpcb_xact
block|{
name|struct
name|rpcb_xact
modifier|*
name|rx_next
decl_stmt|;
name|struct
name|rpcb_xact
modifier|*
modifier|*
name|rx_pnext
decl_stmt|;
name|u_32_t
name|rx_xid
decl_stmt|;
comment|/* RPC transmission ID */
name|u_int
name|rx_type
decl_stmt|;
comment|/* RPCB response type */
name|u_int
name|rx_ref
decl_stmt|;
comment|/* reference count */
name|u_int
name|rx_proto
decl_stmt|;
comment|/* transport protocol (v2 only) */
block|}
name|rpcb_xact_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|rpcb_session
block|{
name|ipfmutex_t
name|rs_rxlock
decl_stmt|;
name|rpcb_xact_t
modifier|*
name|rs_rxlist
decl_stmt|;
block|}
name|rpcb_session_t
typedef|;
end_typedef

begin_comment
comment|/*  * For an explanation, please see the following:  *   RFC1832 - Sections 3.11, 4.4, and 4.5.  */
end_comment

begin_define
define|#
directive|define
name|XDRALIGN
parameter_list|(
name|x
parameter_list|)
value|((((x) % 4) != 0) ? ((((x) + 3) / 4) * 4) : (x))
end_define

begin_decl_stmt
specifier|extern
name|ap_session_t
modifier|*
name|ap_sess_tab
index|[
name|AP_SESS_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ap_session_t
modifier|*
name|ap_sess_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|aproxy_t
name|ap_proxies
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ippr_ftp_pasvonly
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|appr_add
name|__P
argument_list|(
operator|(
name|aproxy_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|appr_ctl
name|__P
argument_list|(
operator|(
name|ap_ctl_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|appr_del
name|__P
argument_list|(
operator|(
name|aproxy_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|appr_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|appr_unload
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|appr_ok
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|tcphdr_t
operator|*
operator|,
expr|struct
name|ipnat
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|appr_match
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
expr|struct
name|nat
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|appr_free
name|__P
argument_list|(
operator|(
name|aproxy_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|aps_free
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
specifier|extern
name|int
name|appr_check
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
expr|struct
name|nat
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|aproxy_t
modifier|*
name|appr_lookup
name|__P
argument_list|(
operator|(
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
name|int
name|appr_new
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
expr|struct
name|nat
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|appr_ioctl
name|__P
argument_list|(
operator|(
name|caddr_t
operator|,
name|ioctlcmd_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IP_PROXY_H__ */
end_comment

end_unit

