begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1995-2001 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  *  * @(#)ip_state.h	1.3 1/12/96 (C) 1995 Darren Reed  * $Id: ip_state.h,v 2.13.2.1 2000/07/08 02:15:35 darrenr Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IP_STATE_H__
end_ifndef

begin_define
define|#
directive|define
name|__IP_STATE_H__
end_define

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
name|SIOCDELST
value|_IOW('r', 61, struct ipstate *)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIOCDELST
value|_IOW(r, 61, struct ipstate *)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPSTATE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|IPSTATE_SIZE
value|5737
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPSTATE_MAX
end_ifndef

begin_define
define|#
directive|define
name|IPSTATE_MAX
value|4013
end_define

begin_comment
comment|/* Maximum number of states held */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PAIRS
parameter_list|(
name|s1
parameter_list|,
name|d1
parameter_list|,
name|s2
parameter_list|,
name|d2
parameter_list|)
value|((((s1) == (s2))&& ((d1) == (d2))) ||\ 				 (((s1) == (d2))&& ((d1) == (s2))))
end_define

begin_define
define|#
directive|define
name|IPPAIR
parameter_list|(
name|s1
parameter_list|,
name|d1
parameter_list|,
name|s2
parameter_list|,
name|d2
parameter_list|)
value|PAIRS((s1).s_addr, (d1).s_addr, \ 				      (s2).s_addr, (d2).s_addr)
end_define

begin_typedef
typedef|typedef
struct|struct
name|udpstate
block|{
name|u_short
name|us_sport
decl_stmt|;
name|u_short
name|us_dport
decl_stmt|;
block|}
name|udpstate_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|icmpstate
block|{
name|u_short
name|ics_id
decl_stmt|;
name|u_short
name|ics_seq
decl_stmt|;
name|u_char
name|ics_type
decl_stmt|;
block|}
name|icmpstate_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tcpdata
block|{
name|u_32_t
name|td_end
decl_stmt|;
name|u_32_t
name|td_maxend
decl_stmt|;
name|u_32_t
name|td_maxwin
decl_stmt|;
name|u_char
name|td_wscale
decl_stmt|;
block|}
name|tcpdata_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tcpstate
block|{
name|u_short
name|ts_sport
decl_stmt|;
name|u_short
name|ts_dport
decl_stmt|;
name|tcpdata_t
name|ts_data
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|ts_state
index|[
literal|2
index|]
decl_stmt|;
block|}
name|tcpstate_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ipstate
block|{
name|struct
name|ipstate
modifier|*
name|is_next
decl_stmt|;
name|struct
name|ipstate
modifier|*
modifier|*
name|is_pnext
decl_stmt|;
name|struct
name|ipstate
modifier|*
name|is_hnext
decl_stmt|;
name|struct
name|ipstate
modifier|*
modifier|*
name|is_phnext
decl_stmt|;
name|struct
name|ipstate
modifier|*
modifier|*
name|is_me
decl_stmt|;
name|frentry_t
modifier|*
name|is_rule
decl_stmt|;
name|U_QUAD_T
name|is_pkts
decl_stmt|;
name|U_QUAD_T
name|is_bytes
decl_stmt|;
name|U_QUAD_T
name|is_icmppkts
decl_stmt|;
name|union
name|i6addr
name|is_src
decl_stmt|;
name|union
name|i6addr
name|is_dst
decl_stmt|;
name|void
modifier|*
name|is_ifp
index|[
literal|4
index|]
decl_stmt|;
name|u_long
name|is_age
decl_stmt|;
name|u_int
name|is_frage
index|[
literal|2
index|]
decl_stmt|;
comment|/* age from filter rule, forward& reverse */
name|u_int
name|is_pass
decl_stmt|;
name|u_char
name|is_p
decl_stmt|;
comment|/* Protocol */
name|u_char
name|is_v
decl_stmt|;
comment|/* IP version */
name|u_char
name|is_fsm
decl_stmt|;
comment|/* 1 = following FSM, 0 = not */
name|u_char
name|is_xxx
decl_stmt|;
comment|/* pad */
name|u_int
name|is_hv
decl_stmt|;
comment|/* hash value for this in the table */
name|u_32_t
name|is_rulen
decl_stmt|;
comment|/* rule number */
name|u_32_t
name|is_flags
decl_stmt|;
comment|/* flags for this structure */
name|u_32_t
name|is_opt
decl_stmt|;
comment|/* packet options set */
name|u_32_t
name|is_optmsk
decl_stmt|;
comment|/*    "      "    mask */
name|u_short
name|is_sec
decl_stmt|;
comment|/* security options set */
name|u_short
name|is_secmsk
decl_stmt|;
comment|/*    "        "    mask */
name|u_short
name|is_auth
decl_stmt|;
comment|/* authentication options set */
name|u_short
name|is_authmsk
decl_stmt|;
comment|/*    "              "    mask */
union|union
block|{
name|icmpstate_t
name|is_ics
decl_stmt|;
name|tcpstate_t
name|is_ts
decl_stmt|;
name|udpstate_t
name|is_us
decl_stmt|;
block|}
name|is_ps
union|;
name|u_32_t
name|is_group
decl_stmt|;
name|char
name|is_ifname
index|[
literal|4
index|]
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
if|#
directive|if
name|SOLARIS
operator|||
name|defined
argument_list|(
name|__sgi
argument_list|)
name|kmutex_t
name|is_lock
decl_stmt|;
endif|#
directive|endif
block|}
name|ipstate_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|is_saddr
value|is_src.in4.s_addr
end_define

begin_define
define|#
directive|define
name|is_daddr
value|is_dst.in4.s_addr
end_define

begin_define
define|#
directive|define
name|is_icmp
value|is_ps.is_ics
end_define

begin_define
define|#
directive|define
name|is_type
value|is_icmp.ics_type
end_define

begin_define
define|#
directive|define
name|is_code
value|is_icmp.ics_code
end_define

begin_define
define|#
directive|define
name|is_tcp
value|is_ps.is_ts
end_define

begin_define
define|#
directive|define
name|is_udp
value|is_ps.is_us
end_define

begin_define
define|#
directive|define
name|is_send
value|is_tcp.ts_data[0].td_end
end_define

begin_define
define|#
directive|define
name|is_dend
value|is_tcp.ts_data[1].td_end
end_define

begin_define
define|#
directive|define
name|is_maxswin
value|is_tcp.ts_data[0].td_maxwin
end_define

begin_define
define|#
directive|define
name|is_maxdwin
value|is_tcp.ts_data[1].td_maxwin
end_define

begin_define
define|#
directive|define
name|is_swscale
value|is_tcp.ts_data[0].td_wscale
end_define

begin_define
define|#
directive|define
name|is_dwscale
value|is_tcp.ts_data[1].td_wscale
end_define

begin_define
define|#
directive|define
name|is_maxsend
value|is_tcp.ts_data[0].td_maxend
end_define

begin_define
define|#
directive|define
name|is_maxdend
value|is_tcp.ts_data[1].td_maxend
end_define

begin_define
define|#
directive|define
name|is_sport
value|is_tcp.ts_sport
end_define

begin_define
define|#
directive|define
name|is_dport
value|is_tcp.ts_dport
end_define

begin_define
define|#
directive|define
name|is_state
value|is_tcp.ts_state
end_define

begin_define
define|#
directive|define
name|is_ifpin
value|is_ifp[0]
end_define

begin_define
define|#
directive|define
name|is_ifpout
value|is_ifp[2]
end_define

begin_define
define|#
directive|define
name|TH_OPENING
value|(TH_SYN|TH_ACK)
end_define

begin_comment
comment|/*  * is_flags:  * Bits 0 - 3 are use as a mask with the current packet's bits to check for  * whether it is short, tcp/udp, a fragment or the presence of IP options.  * Bits 4 - 7 are set from the initial packet and contain what the packet  * anded with bits 0-3 must match.  * Bits 8,9 are used to indicate wildcard source/destination port matching.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ipstate_save
block|{
name|void
modifier|*
name|ips_next
decl_stmt|;
name|struct
name|ipstate
name|ips_is
decl_stmt|;
name|struct
name|frentry
name|ips_fr
decl_stmt|;
block|}
name|ipstate_save_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ips_rule
value|ips_is.is_rule
end_define

begin_typedef
typedef|typedef
struct|struct
name|ipslog
block|{
name|U_QUAD_T
name|isl_pkts
decl_stmt|;
name|U_QUAD_T
name|isl_bytes
decl_stmt|;
name|union
name|i6addr
name|isl_src
decl_stmt|;
name|union
name|i6addr
name|isl_dst
decl_stmt|;
name|u_short
name|isl_type
decl_stmt|;
union|union
block|{
name|u_short
name|isl_filler
index|[
literal|2
index|]
decl_stmt|;
name|u_short
name|isl_ports
index|[
literal|2
index|]
decl_stmt|;
name|u_short
name|isl_icmp
decl_stmt|;
block|}
name|isl_ps
union|;
name|u_char
name|isl_v
decl_stmt|;
name|u_char
name|isl_p
decl_stmt|;
name|u_char
name|isl_flags
decl_stmt|;
name|u_char
name|isl_state
index|[
literal|2
index|]
decl_stmt|;
name|u_32_t
name|isl_rulen
decl_stmt|;
name|u_32_t
name|isl_group
decl_stmt|;
block|}
name|ipslog_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|isl_sport
value|isl_ps.isl_ports[0]
end_define

begin_define
define|#
directive|define
name|isl_dport
value|isl_ps.isl_ports[1]
end_define

begin_define
define|#
directive|define
name|isl_itype
value|isl_ps.isl_icmp
end_define

begin_define
define|#
directive|define
name|ISL_NEW
value|0
end_define

begin_define
define|#
directive|define
name|ISL_EXPIRE
value|0xffff
end_define

begin_define
define|#
directive|define
name|ISL_FLUSH
value|0xfffe
end_define

begin_define
define|#
directive|define
name|ISL_REMOVE
value|0xfffd
end_define

begin_typedef
typedef|typedef
struct|struct
name|ips_stat
block|{
name|u_long
name|iss_hits
decl_stmt|;
name|u_long
name|iss_miss
decl_stmt|;
name|u_long
name|iss_max
decl_stmt|;
name|u_long
name|iss_tcp
decl_stmt|;
name|u_long
name|iss_udp
decl_stmt|;
name|u_long
name|iss_icmp
decl_stmt|;
name|u_long
name|iss_nomem
decl_stmt|;
name|u_long
name|iss_expire
decl_stmt|;
name|u_long
name|iss_fin
decl_stmt|;
name|u_long
name|iss_active
decl_stmt|;
name|u_long
name|iss_logged
decl_stmt|;
name|u_long
name|iss_logfail
decl_stmt|;
name|u_long
name|iss_inuse
decl_stmt|;
name|ipstate_t
modifier|*
modifier|*
name|iss_table
decl_stmt|;
name|ipstate_t
modifier|*
name|iss_list
decl_stmt|;
block|}
name|ips_stat_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|u_long
name|fr_tcpidletimeout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|fr_tcpclosewait
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|fr_tcplastack
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|fr_tcptimeout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|fr_tcpclosed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|fr_tcphalfclosed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|fr_udptimeout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|fr_udpacktimeout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|fr_icmptimeout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|fr_icmpacktimeout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ipstate_t
modifier|*
name|ips_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_state_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_stateinit
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
name|fr_tcpstate
name|__P
argument_list|(
operator|(
name|ipstate_t
operator|*
operator|,
name|fr_info_t
operator|*
operator|,
name|ip_t
operator|*
operator|,
name|tcphdr_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ipstate_t
modifier|*
name|fr_addstate
name|__P
argument_list|(
operator|(
name|ip_t
operator|*
operator|,
name|fr_info_t
operator|*
operator|,
name|ipstate_t
operator|*
operator|*
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|frentry_t
modifier|*
name|fr_checkstate
name|__P
argument_list|(
operator|(
name|ip_t
operator|*
operator|,
name|fr_info_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ip_statesync
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fr_timeoutstate
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
name|fr_tcp_age
name|__P
argument_list|(
operator|(
name|u_long
operator|*
operator|,
name|u_char
operator|*
operator|,
name|fr_info_t
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fr_stateunload
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
name|ipstate_log
name|__P
argument_list|(
operator|(
expr|struct
name|ipstate
operator|*
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|int
name|fr_state_ioctl
name|__P
argument_list|(
operator|(
name|caddr_t
operator|,
name|u_long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|int
name|fr_state_ioctl
name|__P
argument_list|(
operator|(
name|caddr_t
operator|,
name|int
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IP_STATE_H__ */
end_comment

end_unit

