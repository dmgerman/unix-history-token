begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1995-2001 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  *  * @(#)ip_nat.h	1.5 2/4/96  * $Id: ip_nat.h,v 2.17.2.20 2001/06/26 10:43:15 darrenr Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IP_NAT_H__
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
value|_IOW('r', 60, struct ipnat *)
end_define

begin_define
define|#
directive|define
name|SIOCRMNAT
value|_IOW('r', 61, struct ipnat *)
end_define

begin_define
define|#
directive|define
name|SIOCGNATS
value|_IOWR('r', 62, struct natstat *)
end_define

begin_define
define|#
directive|define
name|SIOCGNATL
value|_IOWR('r', 63, struct natlookup *)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIOCADNAT
value|_IOW(r, 60, struct ipnat *)
end_define

begin_define
define|#
directive|define
name|SIOCRMNAT
value|_IOW(r, 61, struct ipnat *)
end_define

begin_define
define|#
directive|define
name|SIOCGNATS
value|_IOWR(r, 62, struct natstat *)
end_define

begin_define
define|#
directive|define
name|SIOCGNATL
value|_IOWR(r, 63, struct natlookup *)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|LARGE_NAT
end_undef

begin_comment
comment|/* define this if you're setting up a system to NAT 			 * LARGE numbers of networks/hosts - i.e. in the 			 * hundreds or thousands.  In such a case, you should 			 * also change the RDR_SIZE and NAT_SIZE below to more 			 * appropriate sizes.  The figures below were used for 			 * a setup with 1000-2000 networks to NAT. 			 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NAT_SIZE
end_ifndef

begin_define
define|#
directive|define
name|NAT_SIZE
value|127
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RDR_SIZE
end_ifndef

begin_define
define|#
directive|define
name|RDR_SIZE
value|127
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HOSTMAP_SIZE
end_ifndef

begin_define
define|#
directive|define
name|HOSTMAP_SIZE
value|127
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NAT_TABLE_SZ
end_ifndef

begin_define
define|#
directive|define
name|NAT_TABLE_SZ
value|127
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|LARGE_NAT
end_ifdef

begin_undef
undef|#
directive|undef
name|NAT_SIZE
end_undef

begin_undef
undef|#
directive|undef
name|RDR_SIZE
end_undef

begin_undef
undef|#
directive|undef
name|NAT_TABLE_SZ
end_undef

begin_undef
undef|#
directive|undef
name|HOSTMAP_SIZE
name|127
end_undef

begin_define
define|#
directive|define
name|NAT_SIZE
value|2047
end_define

begin_define
define|#
directive|define
name|RDR_SIZE
value|2047
end_define

begin_define
define|#
directive|define
name|NAT_TABLE_SZ
value|16383
end_define

begin_define
define|#
directive|define
name|HOSTMAP_SIZE
value|8191
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
name|NAT_HW_CKSUM
value|0x80000000
end_define

begin_define
define|#
directive|define
name|DEF_NAT_AGE
value|1200
end_define

begin_comment
comment|/* 10 minutes (600 seconds) */
end_comment

begin_struct_decl
struct_decl|struct
name|ap_session
struct_decl|;
end_struct_decl

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
name|u_32_t
name|nat_sumd
index|[
literal|2
index|]
decl_stmt|;
name|u_32_t
name|nat_ipsumd
decl_stmt|;
name|void
modifier|*
name|nat_data
decl_stmt|;
name|struct
name|ap_session
modifier|*
name|nat_aps
decl_stmt|;
comment|/* proxy session */
name|struct
name|frentry
modifier|*
name|nat_fr
decl_stmt|;
comment|/* filter rule ptr if appropriate */
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
name|U_QUAD_T
name|nat_pkts
decl_stmt|;
name|U_QUAD_T
name|nat_bytes
decl_stmt|;
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
name|nat_tcpstate
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|nat_p
decl_stmt|;
comment|/* protocol for NAT */
name|struct
name|ipnat
modifier|*
name|nat_ptr
decl_stmt|;
comment|/* pointer back to the rule */
name|struct
name|hostmap
modifier|*
name|nat_hm
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
name|nat_phnext
index|[
literal|2
index|]
decl_stmt|;
name|void
modifier|*
name|nat_ifp
decl_stmt|;
name|int
name|nat_dir
decl_stmt|;
name|char
name|nat_ifname
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
name|nat_lock
decl_stmt|;
endif|#
directive|endif
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
name|struct
name|ipnat
modifier|*
name|in_rnext
decl_stmt|;
name|struct
name|ipnat
modifier|*
modifier|*
name|in_prnext
decl_stmt|;
name|struct
name|ipnat
modifier|*
name|in_mnext
decl_stmt|;
name|struct
name|ipnat
modifier|*
modifier|*
name|in_pmnext
decl_stmt|;
name|void
modifier|*
name|in_ifp
decl_stmt|;
name|void
modifier|*
name|in_apr
decl_stmt|;
name|u_long
name|in_space
decl_stmt|;
name|u_int
name|in_use
decl_stmt|;
name|u_int
name|in_hits
decl_stmt|;
name|struct
name|in_addr
name|in_nextip
decl_stmt|;
name|u_short
name|in_pnext
decl_stmt|;
name|u_short
name|in_ippip
decl_stmt|;
comment|/* IP #'s per IP# */
name|u_32_t
name|in_flags
decl_stmt|;
comment|/* From here to in_dport must be reflected */
name|u_short
name|in_spare
decl_stmt|;
name|u_short
name|in_ppip
decl_stmt|;
comment|/* ports per IP */
name|u_short
name|in_port
index|[
literal|2
index|]
decl_stmt|;
comment|/* correctly in IPN_CMPSIZ */
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
name|struct
name|in_addr
name|in_src
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|frtuc
name|in_tuc
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
name|char
name|in_plabel
index|[
name|APR_LABELLEN
index|]
decl_stmt|;
comment|/* proxy label */
name|char
name|in_p
decl_stmt|;
comment|/* protocol */
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
name|in_srcip
value|in_src[0].s_addr
end_define

begin_define
define|#
directive|define
name|in_srcmsk
value|in_src[1].s_addr
end_define

begin_define
define|#
directive|define
name|in_scmp
value|in_tuc.ftu_scmp
end_define

begin_define
define|#
directive|define
name|in_dcmp
value|in_tuc.ftu_dcmp
end_define

begin_define
define|#
directive|define
name|in_stop
value|in_tuc.ftu_stop
end_define

begin_define
define|#
directive|define
name|in_dtop
value|in_tuc.ftu_dtop
end_define

begin_define
define|#
directive|define
name|in_sport
value|in_tuc.ftu_sport
end_define

begin_define
define|#
directive|define
name|in_dport
value|in_tuc.ftu_dport
end_define

begin_define
define|#
directive|define
name|NAT_OUTBOUND
value|0
end_define

begin_define
define|#
directive|define
name|NAT_INBOUND
value|1
end_define

begin_define
define|#
directive|define
name|NAT_MAP
value|0x01
end_define

begin_define
define|#
directive|define
name|NAT_REDIRECT
value|0x02
end_define

begin_define
define|#
directive|define
name|NAT_BIMAP
value|(NAT_MAP|NAT_REDIRECT)
end_define

begin_define
define|#
directive|define
name|NAT_MAPBLK
value|0x04
end_define

begin_comment
comment|/* 0x100 reserved for FI_W_SPORT */
end_comment

begin_comment
comment|/* 0x200 reserved for FI_W_DPORT */
end_comment

begin_comment
comment|/* 0x400 reserved for FI_W_SADDR */
end_comment

begin_comment
comment|/* 0x800 reserved for FI_W_DADDR */
end_comment

begin_comment
comment|/* 0x1000 reserved for FI_W_NEWFR */
end_comment

begin_define
define|#
directive|define
name|MAPBLK_MINPORT
value|1024
end_define

begin_comment
comment|/* don't use reserved ports for src port */
end_comment

begin_define
define|#
directive|define
name|USABLE_PORTS
value|(65536 - MAPBLK_MINPORT)
end_define

begin_define
define|#
directive|define
name|IPN_CMPSIZ
value|(sizeof(ipnat_t) - offsetof(ipnat_t, in_flags))
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
name|struct
name|in_addr
name|nl_realip
decl_stmt|;
name|int
name|nl_flags
decl_stmt|;
name|u_short
name|nl_inport
decl_stmt|;
name|u_short
name|nl_outport
decl_stmt|;
name|u_short
name|nl_realport
decl_stmt|;
block|}
name|natlookup_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|nat_save
block|{
name|void
modifier|*
name|ipn_next
decl_stmt|;
name|struct
name|nat
name|ipn_nat
decl_stmt|;
name|struct
name|ipnat
name|ipn_ipnat
decl_stmt|;
name|struct
name|frentry
name|ipn_fr
decl_stmt|;
name|int
name|ipn_dsize
decl_stmt|;
name|char
name|ipn_data
index|[
literal|4
index|]
decl_stmt|;
block|}
name|nat_save_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ipn_rule
value|ipn_nat.nat_fr
end_define

begin_typedef
typedef|typedef
struct|struct
name|natget
block|{
name|void
modifier|*
name|ng_ptr
decl_stmt|;
name|int
name|ng_sz
decl_stmt|;
block|}
name|natget_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|hostmap
block|{
name|struct
name|hostmap
modifier|*
name|hm_next
decl_stmt|;
name|struct
name|hostmap
modifier|*
modifier|*
name|hm_pnext
decl_stmt|;
name|struct
name|ipnat
modifier|*
name|hm_ipnat
decl_stmt|;
name|struct
name|in_addr
name|hm_realip
decl_stmt|;
name|struct
name|in_addr
name|hm_mapip
decl_stmt|;
name|int
name|hm_ref
decl_stmt|;
block|}
name|hostmap_t
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
name|ns_rules
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
name|u_long
name|ns_memfail
decl_stmt|;
name|u_long
name|ns_badnat
decl_stmt|;
name|nat_t
modifier|*
modifier|*
name|ns_table
index|[
literal|2
index|]
decl_stmt|;
name|hostmap_t
modifier|*
modifier|*
name|ns_maptable
decl_stmt|;
name|ipnat_t
modifier|*
name|ns_list
decl_stmt|;
name|void
modifier|*
name|ns_apslist
decl_stmt|;
name|u_int
name|ns_nattab_sz
decl_stmt|;
name|u_int
name|ns_rultab_sz
decl_stmt|;
name|u_int
name|ns_rdrtab_sz
decl_stmt|;
name|u_int
name|ns_hostmap_sz
decl_stmt|;
name|nat_t
modifier|*
name|ns_instances
decl_stmt|;
name|u_int
name|ns_wilds
decl_stmt|;
block|}
name|natstat_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IPN_ANY
value|0x000
end_define

begin_define
define|#
directive|define
name|IPN_TCP
value|0x001
end_define

begin_define
define|#
directive|define
name|IPN_UDP
value|0x002
end_define

begin_define
define|#
directive|define
name|IPN_TCPUDP
value|(IPN_TCP|IPN_UDP)
end_define

begin_define
define|#
directive|define
name|IPN_DELETE
value|0x004
end_define

begin_define
define|#
directive|define
name|IPN_ICMPERR
value|0x008
end_define

begin_define
define|#
directive|define
name|IPN_RF
value|(IPN_TCPUDP|IPN_DELETE|IPN_ICMPERR)
end_define

begin_define
define|#
directive|define
name|IPN_AUTOPORTMAP
value|0x010
end_define

begin_define
define|#
directive|define
name|IPN_IPRANGE
value|0x020
end_define

begin_define
define|#
directive|define
name|IPN_USERFLAGS
value|(IPN_TCPUDP|IPN_AUTOPORTMAP|IPN_IPRANGE|IPN_SPLIT|\ 			 IPN_ROUNDR|IPN_FILTER|IPN_NOTSRC|IPN_NOTDST|IPN_FRAG)
end_define

begin_define
define|#
directive|define
name|IPN_FILTER
value|0x040
end_define

begin_define
define|#
directive|define
name|IPN_SPLIT
value|0x080
end_define

begin_define
define|#
directive|define
name|IPN_ROUNDR
value|0x100
end_define

begin_define
define|#
directive|define
name|IPN_NOTSRC
value|0x080000
end_define

begin_define
define|#
directive|define
name|IPN_NOTDST
value|0x100000
end_define

begin_define
define|#
directive|define
name|IPN_FRAG
value|0x200000
end_define

begin_typedef
typedef|typedef
struct|struct
name|natlog
block|{
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
name|U_QUAD_T
name|nl_pkts
decl_stmt|;
name|U_QUAD_T
name|nl_bytes
decl_stmt|;
name|u_char
name|nl_p
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
name|NL_NEWBIMAP
value|NAT_BIMAP
end_define

begin_define
define|#
directive|define
name|NL_NEWBLOCK
value|NAT_MAPBLK
end_define

begin_define
define|#
directive|define
name|NL_FLUSH
value|0xfffe
end_define

begin_define
define|#
directive|define
name|NL_EXPIRE
value|0xffff
end_define

begin_define
define|#
directive|define
name|NAT_HASH_FN
parameter_list|(
name|k
parameter_list|,
name|l
parameter_list|,
name|m
parameter_list|)
value|(((k) + ((k)>> 12) + l) % (m))
end_define

begin_define
define|#
directive|define
name|LONG_SUM
parameter_list|(
name|in
parameter_list|)
value|(((in)& 0xffff) + ((in)>> 16))
end_define

begin_define
define|#
directive|define
name|CALC_SUMD
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|sd
parameter_list|)
value|{ \ 			    (s1) = ((s1)& 0xffff) + ((s1)>> 16); \ 			    (s2) = ((s2)& 0xffff) + ((s2)>> 16); \
comment|/* Do it twice */
value|\ 			    (s1) = ((s1)& 0xffff) + ((s1)>> 16); \ 			    (s2) = ((s2)& 0xffff) + ((s2)>> 16); \
comment|/* Because ~1 == -2, We really need ~1 == -1 */
value|\ 			    if ((s1)> (s2)) (s2)--; \ 			    (sd) = (s2) - (s1); \ 			    (sd) = ((sd)& 0xffff) + ((sd)>> 16); }
end_define

begin_decl_stmt
specifier|extern
name|u_int
name|ipf_nattable_sz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|ipf_natrules_sz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|ipf_rdrrules_sz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_nat_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ip_natsync
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
name|u_long
name|fr_defnatage
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|fr_defnaticmpage
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|nat_t
modifier|*
modifier|*
name|nat_table
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|nat_t
modifier|*
name|nat_instances
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ipnat_t
modifier|*
modifier|*
name|nat_rules
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ipnat_t
modifier|*
modifier|*
name|rdr_rules
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|natstat_t
name|nat_stats
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
operator|||
operator|(
name|__FreeBSD_version
operator|>=
literal|300003
operator|)
end_if

begin_decl_stmt
specifier|extern
name|int
name|nat_ioctl
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

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|nat_init
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
name|nat_t
modifier|*
name|nat_new
name|__P
argument_list|(
operator|(
name|ipnat_t
operator|*
operator|,
name|ip_t
operator|*
operator|,
name|fr_info_t
operator|*
operator|,
name|u_int
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
name|void
operator|*
operator|,
name|u_int
operator|,
name|u_int
operator|,
expr|struct
name|in_addr
operator|,
expr|struct
name|in_addr
operator|,
name|u_32_t
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
name|nat_inlookup
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|u_int
operator|,
name|u_int
operator|,
expr|struct
name|in_addr
operator|,
expr|struct
name|in_addr
operator|,
name|u_32_t
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
name|nat_maplookup
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|u_int
operator|,
expr|struct
name|in_addr
operator|,
expr|struct
name|in_addr
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
name|nat_icmplookup
name|__P
argument_list|(
operator|(
name|ip_t
operator|*
operator|,
name|fr_info_t
operator|*
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
name|nat_icmp
name|__P
argument_list|(
operator|(
name|ip_t
operator|*
operator|,
name|fr_info_t
operator|*
operator|,
name|u_int
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|nat_insert
name|__P
argument_list|(
operator|(
name|nat_t
operator|*
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
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fix_incksum
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|u_short
operator|*
operator|,
name|u_32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fix_outcksum
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|u_short
operator|*
operator|,
name|u_32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fix_datacksum
name|__P
argument_list|(
operator|(
name|u_short
operator|*
operator|,
name|u_32_t
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

