begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * (C)opyright 1995 by Darren Reed.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and due credit is given  * to the original author and the contributors.  *  * @(#)ip_state.h	1.3 1/12/96 (C) 1995 Darren Reed  * $Id: ip_state.h,v 2.0.1.1 1997/01/09 15:14:43 darrenr Exp $  */
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

begin_define
define|#
directive|define
name|IPSTATE_SIZE
value|257
end_define

begin_define
define|#
directive|define
name|IPSTATE_MAX
value|2048
end_define

begin_comment
comment|/* Maximum number of states held */
end_comment

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
name|tcpstate
block|{
name|u_short
name|ts_sport
decl_stmt|;
name|u_short
name|ts_dport
decl_stmt|;
name|u_long
name|ts_seq
decl_stmt|;
name|u_long
name|ts_ack
decl_stmt|;
name|u_short
name|ts_swin
decl_stmt|;
name|u_short
name|ts_dwin
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
name|int
name|is_age
decl_stmt|;
name|u_int
name|is_pass
decl_stmt|;
name|struct
name|in_addr
name|is_src
decl_stmt|;
name|struct
name|in_addr
name|is_dst
decl_stmt|;
name|u_char
name|is_p
decl_stmt|;
name|u_char
name|is_flags
decl_stmt|;
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
block|}
name|ipstate_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|is_icmp
value|is_ps.is_ics
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
name|is_seq
value|is_tcp.ts_seq
end_define

begin_define
define|#
directive|define
name|is_ack
value|is_tcp.ts_ack
end_define

begin_define
define|#
directive|define
name|is_dwin
value|is_tcp.ts_dwin
end_define

begin_define
define|#
directive|define
name|is_swin
value|is_tcp.ts_swin
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
name|TH_OPENING
value|(TH_SYN|TH_ACK)
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
name|ipstate_t
modifier|*
modifier|*
name|iss_table
decl_stmt|;
block|}
name|ips_stat_t
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|ips_stat_t
modifier|*
name|fr_statetstats
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|fr_addstate
argument_list|()
decl_stmt|,
name|fr_checkstate
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fr_timeoutstate
argument_list|()
decl_stmt|,
name|set_tcp_age
argument_list|()
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
specifier|extern
name|void
name|fr_stateunload
parameter_list|()
function_decl|;
end_function_decl

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

