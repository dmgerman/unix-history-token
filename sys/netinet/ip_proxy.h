begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1997-1998 by Darren Reed.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and due credit is given  * to the original author and the contributors.  *  * $Id: ip_proxy.h,v 2.1.2.1 1999/09/19 12:18:20 darrenr Exp $  * $FreeBSD$  */
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

begin_comment
comment|/*  * Real audio proxy structure and #defines  */
end_comment

begin_typedef
typedef|typedef
struct|struct
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
name|appr_match
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IP_PROXY_H__ */
end_comment

end_unit

