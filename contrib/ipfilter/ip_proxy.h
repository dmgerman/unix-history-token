begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1997-2001 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  *  * $Id: ip_proxy.h,v 2.8.2.12 2002/01/01 13:41:43 darrenr Exp $  */
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
name|tcp_seq
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
name|tcp_seq
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
name|ip_t
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
name|ip_t
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
name|ip_t
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
value|(((x)& 0xffff)<< 16)
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

begin_define
define|#
directive|define
name|FTP_BUFSZ
value|160
end_define

begin_comment
comment|/*  * For the ftp proxy.  */
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
name|u_32_t
name|ftps_seq
decl_stmt|;
name|u_32_t
name|ftps_len
decl_stmt|;
name|int
name|ftps_junk
decl_stmt|;
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
name|tcp_seq
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
name|ipstate_t
modifier|*
name|ipsc_state
decl_stmt|;
block|}
name|ipsec_pxy_t
typedef|;
end_typedef

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
name|ip_t
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
name|ip_t
operator|*
operator|,
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
name|ip_t
operator|*
operator|,
expr|struct
name|nat
operator|*
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

