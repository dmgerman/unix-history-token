begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * (C)opyright 1995 by Darren Reed.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and due credit is given  * to the original author and the contributors.  *  * @(#)ip_nat.h	1.5 2/4/96  * $Id: ip_nat.h,v 1.1.1.2 1997/04/03 10:11:19 darrenr Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IP_NAT_H_
end_ifndef

begin_define
define|#
directive|define
name|__IP_NAT_H__
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
name|SIOCADNAT
value|_IOW('r', 80, struct ipnat)
end_define

begin_define
define|#
directive|define
name|SIOCRMNAT
value|_IOW('r', 81, struct ipnat)
end_define

begin_define
define|#
directive|define
name|SIOCGNATS
value|_IOR('r', 82, struct natstat)
end_define

begin_define
define|#
directive|define
name|SIOCGNATL
value|_IOWR('r', 83, struct natlookup)
end_define

begin_define
define|#
directive|define
name|SIOCGFRST
value|_IOR('r', 84, struct ipfrstat)
end_define

begin_define
define|#
directive|define
name|SIOCGIPST
value|_IOR('r', 85, struct ips_stat)
end_define

begin_define
define|#
directive|define
name|SIOCFLNAT
value|_IOWR('r', 86, int)
end_define

begin_define
define|#
directive|define
name|SIOCCNATL
value|_IOWR('r', 87, int)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIOCADNAT
value|_IOW(r, 80, struct ipnat)
end_define

begin_define
define|#
directive|define
name|SIOCRMNAT
value|_IOW(r, 81, struct ipnat)
end_define

begin_define
define|#
directive|define
name|SIOCGNATS
value|_IOR(r, 82, struct natstat)
end_define

begin_define
define|#
directive|define
name|SIOCGNATL
value|_IOWR(r, 83, struct natlookup)
end_define

begin_define
define|#
directive|define
name|SIOCGFRST
value|_IOR(r, 84, struct ipfrstat)
end_define

begin_define
define|#
directive|define
name|SIOCGIPST
value|_IOR(r, 85, struct ips_stat)
end_define

begin_define
define|#
directive|define
name|SIOCFLNAT
value|_IOWR(r, 86, int)
end_define

begin_define
define|#
directive|define
name|SIOCCNATL
value|_IOWR(r, 87, int)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NAT_SIZE
value|367
end_define

begin_typedef
typedef|typedef
struct|struct
name|nat
block|{
name|u_long
name|nat_age
decl_stmt|;
name|int
name|nat_flags
decl_stmt|;
name|u_long
name|nat_sumd
decl_stmt|;
name|u_long
name|nat_ipsumd
decl_stmt|;
name|struct
name|in_addr
name|nat_inip
decl_stmt|;
name|struct
name|in_addr
name|nat_outip
decl_stmt|;
name|struct
name|in_addr
name|nat_oip
decl_stmt|;
comment|/* other ip */
name|u_short
name|nat_oport
decl_stmt|;
comment|/* other port */
name|u_short
name|nat_inport
decl_stmt|;
name|u_short
name|nat_outport
decl_stmt|;
name|u_short
name|nat_use
decl_stmt|;
name|u_char
name|nat_state
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|ipnat
modifier|*
name|nat_ptr
decl_stmt|;
name|struct
name|nat
modifier|*
name|nat_next
decl_stmt|;
name|struct
name|nat
modifier|*
name|nat_hnext
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|nat
modifier|*
modifier|*
name|nat_hstart
index|[
literal|2
index|]
decl_stmt|;
block|}
name|nat_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ipnat
block|{
name|struct
name|ipnat
modifier|*
name|in_next
decl_stmt|;
name|void
modifier|*
name|in_ifp
decl_stmt|;
name|u_int
name|in_space
decl_stmt|;
name|u_int
name|in_use
decl_stmt|;
name|struct
name|in_addr
name|in_nextip
decl_stmt|;
name|u_short
name|in_pnext
decl_stmt|;
name|u_short
name|in_flags
decl_stmt|;
name|u_short
name|in_port
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|in_addr
name|in_in
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|in_addr
name|in_out
index|[
literal|2
index|]
decl_stmt|;
name|int
name|in_redir
decl_stmt|;
comment|/* 0 if it's a mapping, 1 if it's a hard redir */
name|char
name|in_ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
block|}
name|ipnat_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|in_pmin
value|in_port[0]
end_define

begin_comment
comment|/* Also holds static redir port */
end_comment

begin_define
define|#
directive|define
name|in_pmax
value|in_port[1]
end_define

begin_define
define|#
directive|define
name|in_nip
value|in_nextip.s_addr
end_define

begin_define
define|#
directive|define
name|in_inip
value|in_in[0].s_addr
end_define

begin_define
define|#
directive|define
name|in_inmsk
value|in_in[1].s_addr
end_define

begin_define
define|#
directive|define
name|in_outip
value|in_out[0].s_addr
end_define

begin_define
define|#
directive|define
name|in_outmsk
value|in_out[1].s_addr
end_define

begin_define
define|#
directive|define
name|NAT_INBOUND
value|0
end_define

begin_define
define|#
directive|define
name|NAT_OUTBOUND
value|1
end_define

begin_define
define|#
directive|define
name|NAT_MAP
value|0
end_define

begin_define
define|#
directive|define
name|NAT_REDIRECT
value|1
end_define

begin_define
define|#
directive|define
name|IPN_CMPSIZ
value|(sizeof(struct in_addr) * 4 + sizeof(u_short) * 3 + \ 			 sizeof(int))
end_define

begin_typedef
typedef|typedef
struct|struct
name|natlookup
block|{
name|struct
name|in_addr
name|nl_inip
decl_stmt|;
name|struct
name|in_addr
name|nl_outip
decl_stmt|;
name|u_short
name|nl_inport
decl_stmt|;
name|u_short
name|nl_outport
decl_stmt|;
block|}
name|natlookup_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|natstat
block|{
name|u_long
name|ns_mapped
index|[
literal|2
index|]
decl_stmt|;
name|u_long
name|ns_added
decl_stmt|;
name|u_long
name|ns_expire
decl_stmt|;
name|u_long
name|ns_inuse
decl_stmt|;
name|u_long
name|ns_logged
decl_stmt|;
name|u_long
name|ns_logfail
decl_stmt|;
name|nat_t
modifier|*
modifier|*
name|ns_table
index|[
literal|2
index|]
decl_stmt|;
name|ipnat_t
modifier|*
name|ns_list
decl_stmt|;
block|}
name|natstat_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IPN_ANY
value|0
end_define

begin_define
define|#
directive|define
name|IPN_TCP
value|1
end_define

begin_define
define|#
directive|define
name|IPN_UDP
value|2
end_define

begin_define
define|#
directive|define
name|IPN_TCPUDP
value|3
end_define

begin_typedef
typedef|typedef
struct|struct
name|natlog
block|{
name|struct
name|timeval
name|nl_tv
decl_stmt|;
name|struct
name|in_addr
name|nl_origip
decl_stmt|;
name|struct
name|in_addr
name|nl_outip
decl_stmt|;
name|struct
name|in_addr
name|nl_inip
decl_stmt|;
name|u_short
name|nl_origport
decl_stmt|;
name|u_short
name|nl_outport
decl_stmt|;
name|u_short
name|nl_inport
decl_stmt|;
name|u_short
name|nl_type
decl_stmt|;
name|int
name|nl_rule
decl_stmt|;
block|}
name|natlog_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NL_NEWMAP
value|NAT_MAP
end_define

begin_define
define|#
directive|define
name|NL_NEWRDR
value|NAT_REDIRECT
end_define

begin_define
define|#
directive|define
name|NL_EXPIRE
value|0xffff
end_define

begin_decl_stmt
specifier|extern
name|nat_t
modifier|*
name|nat_table
index|[
literal|2
index|]
index|[
name|NAT_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nat_ioctl
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

begin_decl_stmt
specifier|extern
name|nat_t
modifier|*
name|nat_outlookup
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|in_addr
operator|,
name|u_short
operator|,
expr|struct
name|in_addr
operator|,
name|u_short
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|nat_t
modifier|*
name|nat_inlookup
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|in_addr
operator|,
name|u_short
operator|,
expr|struct
name|in_addr
operator|,
name|u_short
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|nat_t
modifier|*
name|nat_lookupredir
name|__P
argument_list|(
operator|(
name|natlookup_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|nat_t
modifier|*
name|nat_lookupmapip
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|in_addr
operator|,
name|u_short
operator|,
expr|struct
name|in_addr
operator|,
name|u_short
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ip_natout
name|__P
argument_list|(
operator|(
name|ip_t
operator|*
operator|,
name|int
operator|,
name|fr_info_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ip_natin
name|__P
argument_list|(
operator|(
name|ip_t
operator|*
operator|,
name|int
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
name|ip_natunload
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|ip_natexpire
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
name|nat_log
name|__P
argument_list|(
operator|(
expr|struct
name|nat
operator|*
operator|,
name|u_short
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IP_NAT_H__ */
end_comment

end_unit

