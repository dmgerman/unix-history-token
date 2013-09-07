begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 2012 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  *  * @(#)ip_nat.h	1.5 2/4/96  * $FreeBSD$  * Id: ip_nat.h,v 2.90.2.20 2007/09/25 08:27:32 darrenr Exp $  */
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
operator|||
name|defined
argument_list|(
name|_AIX51
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIOCADNAT
value|_IOW('r', 60, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCRMNAT
value|_IOW('r', 61, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCGNATS
value|_IOWR('r', 62, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCGNATL
value|_IOWR('r', 63, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCPURGENAT
value|_IOWR('r', 100, struct ipfobj)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIOCADNAT
value|_IOW(r, 60, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCRMNAT
value|_IOW(r, 61, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCGNATS
value|_IOWR(r, 62, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCGNATL
value|_IOWR(r, 63, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCPURGENAT
value|_IOWR(r, 100, struct ipfobj)
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
comment|/* define	this if you're setting up a system to NAT 			 * LARGE numbers of networks/hosts - i.e. in the 			 * hundreds or thousands.  In such a case, you should 			 * also change the RDR_SIZE and NAT_SIZE below to more 			 * appropriate sizes.  The figures below were used for 			 * a setup with 1000-2000 networks to NAT. 			 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NAT_SIZE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|LARGE_NAT
end_ifdef

begin_define
define|#
directive|define
name|NAT_SIZE
value|2047
end_define

begin_else
else|#
directive|else
end_else

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

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RDR_SIZE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|LARGE_NAT
end_ifdef

begin_define
define|#
directive|define
name|RDR_SIZE
value|2047
end_define

begin_else
else|#
directive|else
end_else

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

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HOSTMAP_SIZE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|LARGE_NAT
end_ifdef

begin_define
define|#
directive|define
name|HOSTMAP_SIZE
value|8191
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HOSTMAP_SIZE
value|2047
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NAT_TABLE_MAX
end_ifndef

begin_comment
comment|/*  * This is newly introduced and for the sake of "least surprise", the numbers  * present aren't what we'd normally use for creating a proper hash table.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LARGE_NAT
end_ifdef

begin_define
define|#
directive|define
name|NAT_TABLE_MAX
value|180000
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NAT_TABLE_MAX
value|30000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NAT_TABLE_SZ
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|LARGE_NAT
end_ifdef

begin_define
define|#
directive|define
name|NAT_TABLE_SZ
value|16383
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NAT_TABLE_SZ
value|2047
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|NAT_HW_CKSUM_PART
value|0x40000000
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
name|ipstate
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ap_session
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * This structure is used in the active NAT table and represents an  * active NAT session.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nat
block|{
name|ipfmutex_t
name|nat_lock
decl_stmt|;
name|struct
name|nat
modifier|*
name|nat_next
decl_stmt|;
name|struct
name|nat
modifier|*
modifier|*
name|nat_pnext
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
name|struct
name|hostmap
modifier|*
name|nat_hm
decl_stmt|;
name|void
modifier|*
name|nat_data
decl_stmt|;
name|struct
name|nat
modifier|*
modifier|*
name|nat_me
decl_stmt|;
name|struct
name|ipstate
modifier|*
name|nat_state
decl_stmt|;
name|struct
name|ap_session
modifier|*
name|nat_aps
decl_stmt|;
comment|/* proxy session */
name|frentry_t
modifier|*
name|nat_fr
decl_stmt|;
comment|/* filter rule ptr if appropriate */
name|struct
name|ipnat
modifier|*
name|nat_ptr
decl_stmt|;
comment|/* pointer back to the rule */
name|void
modifier|*
name|nat_ifps
index|[
literal|2
index|]
decl_stmt|;
name|void
modifier|*
name|nat_sync
decl_stmt|;
name|ipftqent_t
name|nat_tqe
decl_stmt|;
name|int
name|nat_mtu
index|[
literal|2
index|]
decl_stmt|;
name|u_32_t
name|nat_flags
decl_stmt|;
name|u_32_t
name|nat_sumd
index|[
literal|2
index|]
decl_stmt|;
comment|/* ip checksum delta for data segment*/
name|u_32_t
name|nat_ipsumd
decl_stmt|;
comment|/* ip checksum delta for ip header */
name|u_32_t
name|nat_mssclamp
decl_stmt|;
comment|/* if != zero clamp MSS to this */
name|i6addr_t
name|nat_odst6
decl_stmt|;
name|i6addr_t
name|nat_osrc6
decl_stmt|;
name|i6addr_t
name|nat_ndst6
decl_stmt|;
name|i6addr_t
name|nat_nsrc6
decl_stmt|;
name|U_QUAD_T
name|nat_pkts
index|[
literal|2
index|]
decl_stmt|;
name|U_QUAD_T
name|nat_bytes
index|[
literal|2
index|]
decl_stmt|;
union|union
block|{
name|udpinfo_t
name|nat_unu
decl_stmt|;
name|tcpinfo_t
name|nat_unt
decl_stmt|;
name|icmpinfo_t
name|nat_uni
decl_stmt|;
name|greinfo_t
name|nat_ugre
decl_stmt|;
block|}
name|nat_unold
union|,
name|nat_unnew
union|;
name|int
name|nat_use
decl_stmt|;
name|int
name|nat_pr
index|[
literal|2
index|]
decl_stmt|;
comment|/* protocol for NAT */
name|int
name|nat_dir
decl_stmt|;
name|int
name|nat_ref
decl_stmt|;
comment|/* reference count */
name|u_int
name|nat_hv
index|[
literal|2
index|]
decl_stmt|;
name|char
name|nat_ifnames
index|[
literal|2
index|]
index|[
name|LIFNAMSIZ
index|]
decl_stmt|;
name|int
name|nat_rev
decl_stmt|;
comment|/* 0 = forward, 1 = reverse */
name|int
name|nat_dlocal
decl_stmt|;
name|int
name|nat_v
index|[
literal|2
index|]
decl_stmt|;
comment|/* 0 = old, 1 = new */
name|u_int
name|nat_redir
decl_stmt|;
comment|/* copy of in_redir */
block|}
name|nat_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|nat_osrcip
value|nat_osrc6.in4
end_define

begin_define
define|#
directive|define
name|nat_odstip
value|nat_odst6.in4
end_define

begin_define
define|#
directive|define
name|nat_nsrcip
value|nat_nsrc6.in4
end_define

begin_define
define|#
directive|define
name|nat_ndstip
value|nat_ndst6.in4
end_define

begin_define
define|#
directive|define
name|nat_osrcaddr
value|nat_osrc6.in4.s_addr
end_define

begin_define
define|#
directive|define
name|nat_odstaddr
value|nat_odst6.in4.s_addr
end_define

begin_define
define|#
directive|define
name|nat_nsrcaddr
value|nat_nsrc6.in4.s_addr
end_define

begin_define
define|#
directive|define
name|nat_ndstaddr
value|nat_ndst6.in4.s_addr
end_define

begin_define
define|#
directive|define
name|nat_age
value|nat_tqe.tqe_die
end_define

begin_define
define|#
directive|define
name|nat_osport
value|nat_unold.nat_unt.ts_sport
end_define

begin_define
define|#
directive|define
name|nat_odport
value|nat_unold.nat_unt.ts_dport
end_define

begin_define
define|#
directive|define
name|nat_nsport
value|nat_unnew.nat_unt.ts_sport
end_define

begin_define
define|#
directive|define
name|nat_ndport
value|nat_unnew.nat_unt.ts_dport
end_define

begin_define
define|#
directive|define
name|nat_oicmpid
value|nat_unold.nat_uni.ici_id
end_define

begin_define
define|#
directive|define
name|nat_nicmpid
value|nat_unnew.nat_uni.ici_id
end_define

begin_define
define|#
directive|define
name|nat_type
value|nat_unold.nat_uni.ici_type
end_define

begin_define
define|#
directive|define
name|nat_oseq
value|nat_unold.nat_uni.ici_seq
end_define

begin_define
define|#
directive|define
name|nat_nseq
value|nat_unnew.nat_uni.ici_seq
end_define

begin_define
define|#
directive|define
name|nat_tcpstate
value|nat_tqe.tqe_state
end_define

begin_define
define|#
directive|define
name|nat_die
value|nat_tqe.tqe_die
end_define

begin_define
define|#
directive|define
name|nat_touched
value|nat_tqe.tqe_touched
end_define

begin_comment
comment|/*  * Values for nat_dir  */
end_comment

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
name|NAT_ENCAPIN
value|2
end_define

begin_define
define|#
directive|define
name|NAT_ENCAPOUT
value|3
end_define

begin_define
define|#
directive|define
name|NAT_DIVERTIN
value|4
end_define

begin_define
define|#
directive|define
name|NAT_DIVERTOUT
value|5
end_define

begin_comment
comment|/*  * Definitions for nat_flags  */
end_comment

begin_define
define|#
directive|define
name|NAT_TCP
value|0x0001
end_define

begin_comment
comment|/* IPN_TCP */
end_comment

begin_define
define|#
directive|define
name|NAT_UDP
value|0x0002
end_define

begin_comment
comment|/* IPN_UDP */
end_comment

begin_define
define|#
directive|define
name|NAT_ICMPERR
value|0x0004
end_define

begin_comment
comment|/* IPN_ICMPERR */
end_comment

begin_define
define|#
directive|define
name|NAT_ICMPQUERY
value|0x0008
end_define

begin_comment
comment|/* IPN_ICMPQUERY */
end_comment

begin_define
define|#
directive|define
name|NAT_SEARCH
value|0x0010
end_define

begin_define
define|#
directive|define
name|NAT_SLAVE
value|0x0020
end_define

begin_comment
comment|/* Slave connection for a proxy */
end_comment

begin_define
define|#
directive|define
name|NAT_NOTRULEPORT
value|0x0040
end_define

begin_comment
comment|/* Don't use the port # in the NAT rule */
end_comment

begin_define
define|#
directive|define
name|NAT_TCPUDP
value|(NAT_TCP|NAT_UDP)
end_define

begin_define
define|#
directive|define
name|NAT_TCPUDPICMP
value|(NAT_TCP|NAT_UDP|NAT_ICMPERR)
end_define

begin_define
define|#
directive|define
name|NAT_TCPUDPICMPQ
value|(NAT_TCP|NAT_UDP|NAT_ICMPQUERY)
end_define

begin_define
define|#
directive|define
name|NAT_FROMRULE
value|(NAT_TCP|NAT_UDP)
end_define

begin_comment
comment|/* 0x0100 reserved for FI_W_SPORT */
end_comment

begin_comment
comment|/* 0x0200 reserved for FI_W_DPORT */
end_comment

begin_comment
comment|/* 0x0400 reserved for FI_W_SADDR */
end_comment

begin_comment
comment|/* 0x0800 reserved for FI_W_DADDR */
end_comment

begin_comment
comment|/* 0x1000 reserved for FI_W_NEWFR */
end_comment

begin_comment
comment|/* 0x2000 reserved for SI_CLONE */
end_comment

begin_comment
comment|/* 0x4000 reserved for SI_CLONED */
end_comment

begin_comment
comment|/* 0x8000 reserved for SI_IGNOREPKT */
end_comment

begin_define
define|#
directive|define
name|NAT_DEBUG
value|0x800000
end_define

begin_typedef
typedef|typedef
struct|struct
name|nat_addr_s
block|{
name|i6addr_t
name|na_addr
index|[
literal|2
index|]
decl_stmt|;
name|i6addr_t
name|na_nextaddr
decl_stmt|;
name|int
name|na_atype
decl_stmt|;
name|int
name|na_function
decl_stmt|;
block|}
name|nat_addr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|na_nextip
value|na_nextaddr.in4.s_addr
end_define

begin_define
define|#
directive|define
name|na_nextip6
value|na_nextaddr.in6
end_define

begin_define
define|#
directive|define
name|na_num
value|na_addr[0].iplookupnum
end_define

begin_define
define|#
directive|define
name|na_type
value|na_addr[0].iplookuptype
end_define

begin_define
define|#
directive|define
name|na_subtype
value|na_addr[0].iplookupsubtype
end_define

begin_define
define|#
directive|define
name|na_ptr
value|na_addr[1].iplookupptr
end_define

begin_define
define|#
directive|define
name|na_func
value|na_addr[1].iplookupfunc
end_define

begin_comment
comment|/*  * This structure represents an actual NAT rule, loaded by ipnat.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ipnat
block|{
name|ipfmutex_t
name|in_lock
decl_stmt|;
name|struct
name|ipnat
modifier|*
name|in_next
decl_stmt|;
comment|/* NAT rule list next */
name|struct
name|ipnat
modifier|*
modifier|*
name|in_pnext
decl_stmt|;
comment|/* prior rdr next ptr */
name|struct
name|ipnat
modifier|*
name|in_rnext
decl_stmt|;
comment|/* rdr rule hash next */
name|struct
name|ipnat
modifier|*
modifier|*
name|in_prnext
decl_stmt|;
comment|/* prior rdr next ptr */
name|struct
name|ipnat
modifier|*
name|in_mnext
decl_stmt|;
comment|/* map rule hash next */
name|struct
name|ipnat
modifier|*
modifier|*
name|in_pmnext
decl_stmt|;
comment|/* prior map next ptr */
name|struct
name|ipftq
modifier|*
name|in_tqehead
index|[
literal|2
index|]
decl_stmt|;
name|void
modifier|*
name|in_ifps
index|[
literal|2
index|]
decl_stmt|;
name|void
modifier|*
name|in_apr
decl_stmt|;
name|char
modifier|*
name|in_comment
decl_stmt|;
name|mb_t
modifier|*
name|in_divmp
decl_stmt|;
name|void
modifier|*
name|in_pconf
decl_stmt|;
name|U_QUAD_T
name|in_pkts
index|[
literal|2
index|]
decl_stmt|;
name|U_QUAD_T
name|in_bytes
index|[
literal|2
index|]
decl_stmt|;
name|u_long
name|in_space
decl_stmt|;
name|u_long
name|in_hits
decl_stmt|;
name|int
name|in_size
decl_stmt|;
name|int
name|in_use
decl_stmt|;
name|u_int
name|in_hv
index|[
literal|2
index|]
decl_stmt|;
name|int
name|in_flineno
decl_stmt|;
comment|/* conf. file line number */
name|int
name|in_stepnext
decl_stmt|;
name|int
name|in_dlocal
decl_stmt|;
name|u_short
name|in_dpnext
decl_stmt|;
name|u_short
name|in_spnext
decl_stmt|;
comment|/* From here to the end is covered by IPN_CMPSIZ */
name|u_char
name|in_v
index|[
literal|2
index|]
decl_stmt|;
comment|/* 0 = old, 1 = new */
name|u_32_t
name|in_flags
decl_stmt|;
name|u_32_t
name|in_mssclamp
decl_stmt|;
comment|/* if != 0 clamp MSS to this */
name|u_int
name|in_age
index|[
literal|2
index|]
decl_stmt|;
name|int
name|in_redir
decl_stmt|;
comment|/* see below for values */
name|int
name|in_pr
index|[
literal|2
index|]
decl_stmt|;
comment|/* protocol. */
name|nat_addr_t
name|in_ndst
decl_stmt|;
name|nat_addr_t
name|in_nsrc
decl_stmt|;
name|nat_addr_t
name|in_osrc
decl_stmt|;
name|nat_addr_t
name|in_odst
decl_stmt|;
name|frtuc_t
name|in_tuc
decl_stmt|;
name|u_short
name|in_ppip
decl_stmt|;
comment|/* ports per IP. */
name|u_short
name|in_ippip
decl_stmt|;
comment|/* IP #'s per IP# */
name|u_short
name|in_ndports
index|[
literal|2
index|]
decl_stmt|;
name|u_short
name|in_nsports
index|[
literal|2
index|]
decl_stmt|;
name|int
name|in_ifnames
index|[
literal|2
index|]
decl_stmt|;
name|int
name|in_plabel
decl_stmt|;
comment|/* proxy label. */
name|int
name|in_pconfig
decl_stmt|;
comment|/* proxy label. */
name|ipftag_t
name|in_tag
decl_stmt|;
name|int
name|in_namelen
decl_stmt|;
name|char
name|in_names
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ipnat_t
typedef|;
end_typedef

begin_comment
comment|/*  *      MAP-IN MAP-OUT RDR-IN RDR-OUT  * osrc    X   == src  == src    X  * odst    X   == dst  == dst    X  * nsrc == dst   X       X    == dst  * ndst == src   X       X    == src  */
end_comment

begin_define
define|#
directive|define
name|in_dpmin
value|in_ndports[0]
end_define

begin_comment
comment|/* Also holds static redir port */
end_comment

begin_define
define|#
directive|define
name|in_dpmax
value|in_ndports[1]
end_define

begin_define
define|#
directive|define
name|in_spmin
value|in_nsports[0]
end_define

begin_comment
comment|/* Also holds static redir port */
end_comment

begin_define
define|#
directive|define
name|in_spmax
value|in_nsports[1]
end_define

begin_define
define|#
directive|define
name|in_ndport
value|in_ndports[0]
end_define

begin_define
define|#
directive|define
name|in_nsport
value|in_nsports[0]
end_define

begin_define
define|#
directive|define
name|in_dipnext
value|in_ndst.na_nextaddr.in4
end_define

begin_define
define|#
directive|define
name|in_dipnext6
value|in_ndst.na_nextaddr
end_define

begin_define
define|#
directive|define
name|in_dnip
value|in_ndst.na_nextaddr.in4.s_addr
end_define

begin_define
define|#
directive|define
name|in_dnip6
value|in_ndst.na_nextaddr
end_define

begin_define
define|#
directive|define
name|in_sipnext
value|in_nsrc.na_nextaddr.in4
end_define

begin_define
define|#
directive|define
name|in_snip
value|in_nsrc.na_nextaddr.in4.s_addr
end_define

begin_define
define|#
directive|define
name|in_snip6
value|in_nsrc.na_nextaddr
end_define

begin_define
define|#
directive|define
name|in_odstip
value|in_odst.na_addr[0].in4
end_define

begin_define
define|#
directive|define
name|in_odstip6
value|in_odst.na_addr[0]
end_define

begin_define
define|#
directive|define
name|in_odstaddr
value|in_odst.na_addr[0].in4.s_addr
end_define

begin_define
define|#
directive|define
name|in_odstmsk
value|in_odst.na_addr[1].in4.s_addr
end_define

begin_define
define|#
directive|define
name|in_odstmsk6
value|in_odst.na_addr[1]
end_define

begin_define
define|#
directive|define
name|in_odstatype
value|in_odst.na_atype
end_define

begin_define
define|#
directive|define
name|in_osrcip
value|in_osrc.na_addr[0].in4
end_define

begin_define
define|#
directive|define
name|in_osrcip6
value|in_osrc.na_addr[0]
end_define

begin_define
define|#
directive|define
name|in_osrcaddr
value|in_osrc.na_addr[0].in4.s_addr
end_define

begin_define
define|#
directive|define
name|in_osrcmsk
value|in_osrc.na_addr[1].in4.s_addr
end_define

begin_define
define|#
directive|define
name|in_osrcmsk6
value|in_osrc.na_addr[1]
end_define

begin_define
define|#
directive|define
name|in_osrcatype
value|in_osrc.na_atype
end_define

begin_define
define|#
directive|define
name|in_ndstip
value|in_ndst.na_addr[0].in4
end_define

begin_define
define|#
directive|define
name|in_ndstip6
value|in_ndst.na_addr[0]
end_define

begin_define
define|#
directive|define
name|in_ndstaddr
value|in_ndst.na_addr[0].in4.s_addr
end_define

begin_define
define|#
directive|define
name|in_ndstmsk
value|in_ndst.na_addr[1].in4.s_addr
end_define

begin_define
define|#
directive|define
name|in_ndstmsk6
value|in_ndst.na_addr[1]
end_define

begin_define
define|#
directive|define
name|in_ndstatype
value|in_ndst.na_atype
end_define

begin_define
define|#
directive|define
name|in_ndstafunc
value|in_ndst.na_function
end_define

begin_define
define|#
directive|define
name|in_nsrcip
value|in_nsrc.na_addr[0].in4
end_define

begin_define
define|#
directive|define
name|in_nsrcip6
value|in_nsrc.na_addr[0]
end_define

begin_define
define|#
directive|define
name|in_nsrcaddr
value|in_nsrc.na_addr[0].in4.s_addr
end_define

begin_define
define|#
directive|define
name|in_nsrcmsk
value|in_nsrc.na_addr[1].in4.s_addr
end_define

begin_define
define|#
directive|define
name|in_nsrcmsk6
value|in_nsrc.na_addr[1]
end_define

begin_define
define|#
directive|define
name|in_nsrcatype
value|in_nsrc.na_atype
end_define

begin_define
define|#
directive|define
name|in_nsrcafunc
value|in_nsrc.na_function
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
name|in_osport
value|in_tuc.ftu_sport
end_define

begin_define
define|#
directive|define
name|in_odport
value|in_tuc.ftu_dport
end_define

begin_define
define|#
directive|define
name|in_ndstnum
value|in_ndst.na_addr[0].iplookupnum
end_define

begin_define
define|#
directive|define
name|in_ndsttype
value|in_ndst.na_addr[0].iplookuptype
end_define

begin_define
define|#
directive|define
name|in_ndstptr
value|in_ndst.na_addr[1].iplookupptr
end_define

begin_define
define|#
directive|define
name|in_ndstfunc
value|in_ndst.na_addr[1].iplookupfunc
end_define

begin_define
define|#
directive|define
name|in_nsrcnum
value|in_nsrc.na_addr[0].iplookupnum
end_define

begin_define
define|#
directive|define
name|in_nsrctype
value|in_nsrc.na_addr[0].iplookuptype
end_define

begin_define
define|#
directive|define
name|in_nsrcptr
value|in_nsrc.na_addr[1].iplookupptr
end_define

begin_define
define|#
directive|define
name|in_nsrcfunc
value|in_nsrc.na_addr[1].iplookupfunc
end_define

begin_define
define|#
directive|define
name|in_odstnum
value|in_odst.na_addr[0].iplookupnum
end_define

begin_define
define|#
directive|define
name|in_odsttype
value|in_odst.na_addr[0].iplookuptype
end_define

begin_define
define|#
directive|define
name|in_odstptr
value|in_odst.na_addr[1].iplookupptr
end_define

begin_define
define|#
directive|define
name|in_odstfunc
value|in_odst.na_addr[1].iplookupfunc
end_define

begin_define
define|#
directive|define
name|in_osrcnum
value|in_osrc.na_addr[0].iplookupnum
end_define

begin_define
define|#
directive|define
name|in_osrctype
value|in_osrc.na_addr[0].iplookuptype
end_define

begin_define
define|#
directive|define
name|in_osrcptr
value|in_osrc.na_addr[1].iplookupptr
end_define

begin_define
define|#
directive|define
name|in_osrcfunc
value|in_osrc.na_addr[1].iplookupfunc
end_define

begin_define
define|#
directive|define
name|in_icmpidmin
value|in_nsports[0]
end_define

begin_define
define|#
directive|define
name|in_icmpidmax
value|in_nsports[1]
end_define

begin_comment
comment|/*  * Bit definitions for in_flags  */
end_comment

begin_define
define|#
directive|define
name|IPN_ANY
value|0x00000
end_define

begin_define
define|#
directive|define
name|IPN_TCP
value|0x00001
end_define

begin_define
define|#
directive|define
name|IPN_UDP
value|0x00002
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
name|IPN_ICMPERR
value|0x00004
end_define

begin_define
define|#
directive|define
name|IPN_TCPUDPICMP
value|(IPN_TCP|IPN_UDP|IPN_ICMPERR)
end_define

begin_define
define|#
directive|define
name|IPN_ICMPQUERY
value|0x00008
end_define

begin_define
define|#
directive|define
name|IPN_TCPUDPICMPQ
value|(IPN_TCP|IPN_UDP|IPN_ICMPQUERY)
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
value|0x00010
end_define

begin_define
define|#
directive|define
name|IPN_FILTER
value|0x00020
end_define

begin_define
define|#
directive|define
name|IPN_SPLIT
value|0x00040
end_define

begin_define
define|#
directive|define
name|IPN_ROUNDR
value|0x00080
end_define

begin_define
define|#
directive|define
name|IPN_SIPRANGE
value|0x00100
end_define

begin_define
define|#
directive|define
name|IPN_DIPRANGE
value|0x00200
end_define

begin_define
define|#
directive|define
name|IPN_NOTSRC
value|0x00400
end_define

begin_define
define|#
directive|define
name|IPN_NOTDST
value|0x00800
end_define

begin_define
define|#
directive|define
name|IPN_NO
value|0x01000
end_define

begin_define
define|#
directive|define
name|IPN_DYNSRCIP
value|0x02000
end_define

begin_comment
comment|/* dynamic src IP# */
end_comment

begin_define
define|#
directive|define
name|IPN_DYNDSTIP
value|0x04000
end_define

begin_comment
comment|/* dynamic dst IP# */
end_comment

begin_define
define|#
directive|define
name|IPN_DELETE
value|0x08000
end_define

begin_define
define|#
directive|define
name|IPN_STICKY
value|0x10000
end_define

begin_define
define|#
directive|define
name|IPN_FRAG
value|0x20000
end_define

begin_define
define|#
directive|define
name|IPN_FIXEDSPORT
value|0x40000
end_define

begin_define
define|#
directive|define
name|IPN_FIXEDDPORT
value|0x80000
end_define

begin_define
define|#
directive|define
name|IPN_FINDFORWARD
value|0x100000
end_define

begin_define
define|#
directive|define
name|IPN_IN
value|0x200000
end_define

begin_define
define|#
directive|define
name|IPN_SEQUENTIAL
value|0x400000
end_define

begin_define
define|#
directive|define
name|IPN_PURGE
value|0x800000
end_define

begin_define
define|#
directive|define
name|IPN_PROXYRULE
value|0x1000000
end_define

begin_define
define|#
directive|define
name|IPN_USERFLAGS
value|(IPN_TCPUDP|IPN_AUTOPORTMAP|IPN_SIPRANGE|IPN_SPLIT|\ 			 IPN_ROUNDR|IPN_FILTER|IPN_NOTSRC|IPN_NOTDST|IPN_NO|\ 			 IPN_FRAG|IPN_STICKY|IPN_FIXEDDPORT|IPN_ICMPQUERY|\ 			 IPN_DIPRANGE|IPN_SEQUENTIAL|IPN_PURGE)
end_define

begin_comment
comment|/*  * Values for in_redir  */
end_comment

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

begin_define
define|#
directive|define
name|NAT_REWRITE
value|0x08
end_define

begin_define
define|#
directive|define
name|NAT_ENCAP
value|0x10
end_define

begin_define
define|#
directive|define
name|NAT_DIVERTUDP
value|0x20
end_define

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
value|(sizeof(ipnat_t) - offsetof(ipnat_t, in_v))
end_define

begin_typedef
typedef|typedef
struct|struct
name|natlookup
block|{
name|i6addr_t
name|nl_inipaddr
decl_stmt|;
name|i6addr_t
name|nl_outipaddr
decl_stmt|;
name|i6addr_t
name|nl_realipaddr
decl_stmt|;
name|int
name|nl_v
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

begin_define
define|#
directive|define
name|nl_inip
value|nl_inipaddr.in4
end_define

begin_define
define|#
directive|define
name|nl_outip
value|nl_outipaddr.in4
end_define

begin_define
define|#
directive|define
name|nl_realip
value|nl_realipaddr.in4
end_define

begin_define
define|#
directive|define
name|nl_inip6
value|nl_inipaddr.in6
end_define

begin_define
define|#
directive|define
name|nl_outip6
value|nl_outipaddr.in6
end_define

begin_define
define|#
directive|define
name|nl_realip6
value|nl_realipaddr.in6
end_define

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

begin_comment
comment|/*  * This structure gets used to help NAT sessions keep the same NAT rule (and  * thus translation for IP address) when:  * (a) round-robin redirects are in use  * (b) different IP add  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|hostmap
block|{
name|struct
name|hostmap
modifier|*
name|hm_hnext
decl_stmt|;
name|struct
name|hostmap
modifier|*
modifier|*
name|hm_phnext
decl_stmt|;
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
name|i6addr_t
name|hm_osrcip6
decl_stmt|;
name|i6addr_t
name|hm_odstip6
decl_stmt|;
name|i6addr_t
name|hm_nsrcip6
decl_stmt|;
name|i6addr_t
name|hm_ndstip6
decl_stmt|;
name|u_32_t
name|hm_port
decl_stmt|;
name|int
name|hm_ref
decl_stmt|;
name|int
name|hm_hv
decl_stmt|;
name|int
name|hm_v
decl_stmt|;
block|}
name|hostmap_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|hm_osrcip
value|hm_osrcip6.in4
end_define

begin_define
define|#
directive|define
name|hm_odstip
value|hm_odstip6.in4
end_define

begin_define
define|#
directive|define
name|hm_nsrcip
value|hm_nsrcip6.in4
end_define

begin_define
define|#
directive|define
name|hm_ndstip
value|hm_ndstip6.in4
end_define

begin_define
define|#
directive|define
name|hm_osrc6
value|hm_osrcip6.in6
end_define

begin_define
define|#
directive|define
name|hm_odst6
value|hm_odstip6.in6
end_define

begin_define
define|#
directive|define
name|hm_nsrc6
value|hm_nsrcip6.in6
end_define

begin_define
define|#
directive|define
name|hm_ndst6
value|hm_ndstip6.in6
end_define

begin_comment
comment|/*  * Structure used to pass information in to nat_newmap and nat_newrdr.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|natinfo
block|{
name|ipnat_t
modifier|*
name|nai_np
decl_stmt|;
name|u_32_t
name|nai_sum1
decl_stmt|;
name|u_32_t
name|nai_sum2
decl_stmt|;
name|struct
name|in_addr
name|nai_ip
decl_stmt|;
comment|/* In host byte order */
name|u_short
name|nai_port
decl_stmt|;
name|u_short
name|nai_nport
decl_stmt|;
name|u_short
name|nai_sport
decl_stmt|;
name|u_short
name|nai_dport
decl_stmt|;
block|}
name|natinfo_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|nat_stat_side
block|{
name|u_int
modifier|*
name|ns_bucketlen
decl_stmt|;
name|nat_t
modifier|*
modifier|*
name|ns_table
decl_stmt|;
name|u_long
name|ns_added
decl_stmt|;
name|u_long
name|ns_appr_fail
decl_stmt|;
name|u_long
name|ns_badnat
decl_stmt|;
name|u_long
name|ns_badnatnew
decl_stmt|;
name|u_long
name|ns_badnextaddr
decl_stmt|;
name|u_long
name|ns_bucket_max
decl_stmt|;
name|u_long
name|ns_clone_nomem
decl_stmt|;
name|u_long
name|ns_decap_bad
decl_stmt|;
name|u_long
name|ns_decap_fail
decl_stmt|;
name|u_long
name|ns_decap_pullup
decl_stmt|;
name|u_long
name|ns_divert_dup
decl_stmt|;
name|u_long
name|ns_divert_exist
decl_stmt|;
name|u_long
name|ns_drop
decl_stmt|;
name|u_long
name|ns_encap_dup
decl_stmt|;
name|u_long
name|ns_encap_pullup
decl_stmt|;
name|u_long
name|ns_exhausted
decl_stmt|;
name|u_long
name|ns_icmp_address
decl_stmt|;
name|u_long
name|ns_icmp_basic
decl_stmt|;
name|u_long
name|ns_icmp_mbuf
decl_stmt|;
name|u_long
name|ns_icmp_notfound
decl_stmt|;
name|u_long
name|ns_icmp_rebuild
decl_stmt|;
name|u_long
name|ns_icmp_short
decl_stmt|;
name|u_long
name|ns_icmp_size
decl_stmt|;
name|u_long
name|ns_ifpaddrfail
decl_stmt|;
name|u_long
name|ns_ignored
decl_stmt|;
name|u_long
name|ns_insert_fail
decl_stmt|;
name|u_long
name|ns_inuse
decl_stmt|;
name|u_long
name|ns_log
decl_stmt|;
name|u_long
name|ns_lookup_miss
decl_stmt|;
name|u_long
name|ns_lookup_nowild
decl_stmt|;
name|u_long
name|ns_new_ifpaddr
decl_stmt|;
name|u_long
name|ns_memfail
decl_stmt|;
name|u_long
name|ns_table_max
decl_stmt|;
name|u_long
name|ns_translated
decl_stmt|;
name|u_long
name|ns_unfinalised
decl_stmt|;
name|u_long
name|ns_wrap
decl_stmt|;
name|u_long
name|ns_xlate_null
decl_stmt|;
name|u_long
name|ns_xlate_exists
decl_stmt|;
name|u_long
name|ns_ipf_proxy_fail
decl_stmt|;
name|u_long
name|ns_uncreate
index|[
literal|2
index|]
decl_stmt|;
block|}
name|nat_stat_side_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|natstat
block|{
name|nat_t
modifier|*
name|ns_instances
decl_stmt|;
name|ipnat_t
modifier|*
name|ns_list
decl_stmt|;
name|hostmap_t
modifier|*
name|ns_maplist
decl_stmt|;
name|hostmap_t
modifier|*
modifier|*
name|ns_maptable
decl_stmt|;
name|u_int
name|ns_active
decl_stmt|;
name|u_long
name|ns_addtrpnt
decl_stmt|;
name|u_long
name|ns_divert_build
decl_stmt|;
name|u_long
name|ns_expire
decl_stmt|;
name|u_long
name|ns_flush_all
decl_stmt|;
name|u_long
name|ns_flush_closing
decl_stmt|;
name|u_long
name|ns_flush_queue
decl_stmt|;
name|u_long
name|ns_flush_state
decl_stmt|;
name|u_long
name|ns_flush_timeout
decl_stmt|;
name|u_long
name|ns_hm_new
decl_stmt|;
name|u_long
name|ns_hm_newfail
decl_stmt|;
name|u_long
name|ns_hm_addref
decl_stmt|;
name|u_long
name|ns_hm_nullnp
decl_stmt|;
name|u_long
name|ns_log_ok
decl_stmt|;
name|u_long
name|ns_log_fail
decl_stmt|;
name|u_int
name|ns_hostmap_sz
decl_stmt|;
name|u_int
name|ns_nattab_sz
decl_stmt|;
name|u_int
name|ns_nattab_max
decl_stmt|;
name|u_int
name|ns_orphans
decl_stmt|;
name|u_int
name|ns_rules
decl_stmt|;
name|u_int
name|ns_rules_map
decl_stmt|;
name|u_int
name|ns_rules_rdr
decl_stmt|;
name|u_int
name|ns_rultab_sz
decl_stmt|;
name|u_int
name|ns_rdrtab_sz
decl_stmt|;
name|u_32_t
name|ns_ticks
decl_stmt|;
name|u_int
name|ns_trpntab_sz
decl_stmt|;
name|u_int
name|ns_wilds
decl_stmt|;
name|u_long
name|ns_proto
index|[
literal|256
index|]
decl_stmt|;
name|nat_stat_side_t
name|ns_side
index|[
literal|2
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|USE_INET6
name|nat_stat_side_t
name|ns_side6
index|[
literal|2
index|]
decl_stmt|;
endif|#
directive|endif
block|}
name|natstat_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|natlog
block|{
name|i6addr_t
name|nl_osrcip
decl_stmt|;
name|i6addr_t
name|nl_odstip
decl_stmt|;
name|i6addr_t
name|nl_nsrcip
decl_stmt|;
name|i6addr_t
name|nl_ndstip
decl_stmt|;
name|u_short
name|nl_osrcport
decl_stmt|;
name|u_short
name|nl_odstport
decl_stmt|;
name|u_short
name|nl_nsrcport
decl_stmt|;
name|u_short
name|nl_ndstport
decl_stmt|;
name|int
name|nl_action
decl_stmt|;
name|int
name|nl_type
decl_stmt|;
name|int
name|nl_rule
decl_stmt|;
name|U_QUAD_T
name|nl_pkts
index|[
literal|2
index|]
decl_stmt|;
name|U_QUAD_T
name|nl_bytes
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|nl_p
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|nl_v
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|nl_ifnames
index|[
literal|2
index|]
index|[
name|LIFNAMSIZ
index|]
decl_stmt|;
block|}
name|natlog_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NL_NEW
value|0
end_define

begin_define
define|#
directive|define
name|NL_CLONE
value|1
end_define

begin_define
define|#
directive|define
name|NL_PURGE
value|0xfffc
end_define

begin_define
define|#
directive|define
name|NL_DESTROY
value|0xfffd
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
name|_k
parameter_list|,
name|_l
parameter_list|,
name|_m
parameter_list|)
value|(((_k) + ((_k)>> 12) + _l) % (_m))
end_define

begin_define
define|#
directive|define
name|NAT_HASH_FN6
parameter_list|(
name|_k
parameter_list|,
name|_l
parameter_list|,
name|_m
parameter_list|)
value|((((u_32_t *)(_k))[3] \ 				 + (((u_32_t *)(_k))[3]>> 12) \ 				 + (((u_32_t *)(_k))[2]) \ 				 + (((u_32_t *)(_k))[2]>> 12) \ 				 + (((u_32_t *)(_k))[1]) \ 				 + (((u_32_t *)(_k))[1]>> 12) \ 				 + (((u_32_t *)(_k))[0]) \ 				 + (((u_32_t *)(_k))[0]>> 12) \ 				 + _l) % (_m))
end_define

begin_define
define|#
directive|define
name|LONG_SUM
parameter_list|(
name|_i
parameter_list|)
value|(((_i)& 0xffff) + ((_i)>> 16))
end_define

begin_define
define|#
directive|define
name|LONG_SUM6
parameter_list|(
name|_i
parameter_list|)
value|(LONG_SUM(ntohl(((u_32_t *)(_i))[0])) + \ 			 LONG_SUM(ntohl(((u_32_t *)(_i))[1])) + \ 			 LONG_SUM(ntohl(((u_32_t *)(_i))[2])) + \ 			 LONG_SUM(ntohl(((u_32_t *)(_i))[3])))
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

begin_define
define|#
directive|define
name|NAT_SYSSPACE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|NAT_LOCKHELD
value|0x40000000
end_define

begin_comment
comment|/*  * This is present in ip_nat.h because it needs to be shared between  * ip_nat.c and ip_nat6.c  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ipf_nat_softc_s
block|{
name|ipfmutex_t
name|ipf_nat_new
decl_stmt|;
name|ipfmutex_t
name|ipf_nat_io
decl_stmt|;
name|int
name|ipf_nat_doflush
decl_stmt|;
name|int
name|ipf_nat_logging
decl_stmt|;
name|int
name|ipf_nat_lock
decl_stmt|;
name|int
name|ipf_nat_inited
decl_stmt|;
name|int
name|ipf_nat_table_wm_high
decl_stmt|;
name|int
name|ipf_nat_table_wm_low
decl_stmt|;
name|u_int
name|ipf_nat_table_max
decl_stmt|;
name|u_int
name|ipf_nat_table_sz
decl_stmt|;
name|u_int
name|ipf_nat_maprules_sz
decl_stmt|;
name|u_int
name|ipf_nat_rdrrules_sz
decl_stmt|;
name|u_int
name|ipf_nat_hostmap_sz
decl_stmt|;
name|u_int
name|ipf_nat_maxbucket
decl_stmt|;
name|u_int
name|ipf_nat_last_force_flush
decl_stmt|;
name|u_int
name|ipf_nat_defage
decl_stmt|;
name|u_int
name|ipf_nat_defipage
decl_stmt|;
name|u_int
name|ipf_nat_deficmpage
decl_stmt|;
name|ipf_v4_masktab_t
name|ipf_nat_map_mask
decl_stmt|;
name|ipf_v6_masktab_t
name|ipf_nat6_map_mask
decl_stmt|;
name|ipf_v4_masktab_t
name|ipf_nat_rdr_mask
decl_stmt|;
name|ipf_v6_masktab_t
name|ipf_nat6_rdr_mask
decl_stmt|;
name|nat_t
modifier|*
modifier|*
name|ipf_nat_table
index|[
literal|2
index|]
decl_stmt|;
name|nat_t
modifier|*
name|ipf_nat_instances
decl_stmt|;
name|ipnat_t
modifier|*
name|ipf_nat_list
decl_stmt|;
name|ipnat_t
modifier|*
modifier|*
name|ipf_nat_list_tail
decl_stmt|;
name|ipnat_t
modifier|*
modifier|*
name|ipf_nat_map_rules
decl_stmt|;
name|ipnat_t
modifier|*
modifier|*
name|ipf_nat_rdr_rules
decl_stmt|;
name|ipftq_t
modifier|*
name|ipf_nat_utqe
decl_stmt|;
name|hostmap_t
modifier|*
modifier|*
name|ipf_hm_maptable
decl_stmt|;
name|hostmap_t
modifier|*
name|ipf_hm_maplist
decl_stmt|;
name|ipftuneable_t
modifier|*
name|ipf_nat_tune
decl_stmt|;
name|ipftq_t
name|ipf_nat_udptq
decl_stmt|;
name|ipftq_t
name|ipf_nat_udpacktq
decl_stmt|;
name|ipftq_t
name|ipf_nat_icmptq
decl_stmt|;
name|ipftq_t
name|ipf_nat_icmpacktq
decl_stmt|;
name|ipftq_t
name|ipf_nat_iptq
decl_stmt|;
name|ipftq_t
name|ipf_nat_pending
decl_stmt|;
name|ipftq_t
name|ipf_nat_tcptq
index|[
name|IPF_TCP_NSTATES
index|]
decl_stmt|;
name|natstat_t
name|ipf_nat_stats
decl_stmt|;
block|}
name|ipf_nat_softc_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ipf_nat_map_max
value|ipf_nat_map_mask.imt4_max
end_define

begin_define
define|#
directive|define
name|ipf_nat_rdr_max
value|ipf_nat_rdr_mask.imt4_max
end_define

begin_define
define|#
directive|define
name|ipf_nat6_map_max
value|ipf_nat6_map_mask.imt6_max
end_define

begin_define
define|#
directive|define
name|ipf_nat6_rdr_max
value|ipf_nat6_rdr_mask.imt6_max
end_define

begin_define
define|#
directive|define
name|ipf_nat_map_active_masks
value|ipf_nat_map_mask.imt4_active
end_define

begin_define
define|#
directive|define
name|ipf_nat_rdr_active_masks
value|ipf_nat_rdr_mask.imt4_active
end_define

begin_define
define|#
directive|define
name|ipf_nat6_map_active_masks
value|ipf_nat6_map_mask.imt6_active
end_define

begin_define
define|#
directive|define
name|ipf_nat6_rdr_active_masks
value|ipf_nat6_rdr_mask.imt6_active
end_define

begin_decl_stmt
specifier|extern
name|frentry_t
name|ipfnatblock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ipf_fix_datacksum
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

begin_decl_stmt
specifier|extern
name|void
name|ipf_fix_incksum
name|__P
argument_list|(
operator|(
name|int
operator|,
name|u_short
operator|*
operator|,
name|u_32_t
operator|,
name|u_32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ipf_fix_outcksum
name|__P
argument_list|(
operator|(
name|int
operator|,
name|u_short
operator|*
operator|,
name|u_32_t
operator|,
name|u_32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipf_nat_checkin
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|u_32_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipf_nat_checkout
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|u_32_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ipf_nat_delete
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
expr|struct
name|nat
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
name|ipf_nat_deref
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|nat_t
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ipf_nat_expire
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipf_nat_hashtab_add
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|ipf_nat_softc_t
operator|*
operator|,
name|nat_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ipf_nat_hostmapdel
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|hostmap_t
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipf_nat_hostmap_rehash
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|ipftuneable_t
operator|*
operator|,
name|ipftuneval_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|nat_t
modifier|*
name|ipf_nat_icmperrorlookup
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

begin_decl_stmt
specifier|extern
name|nat_t
modifier|*
name|ipf_nat_icmperror
name|__P
argument_list|(
operator|(
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|void
name|ipf_nat_ifdetach
name|__P
argument_list|(
operator|(
name|void
operator|*
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
name|ipf_nat_init
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
name|ipf_nat_inlookup
name|__P
argument_list|(
operator|(
name|fr_info_t
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipf_nat_in
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|nat_t
operator|*
operator|,
name|int
operator|,
name|u_32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipf_nat_insert
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|ipf_nat_softc_t
operator|*
operator|,
name|nat_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipf_nat_ioctl
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|caddr_t
operator|,
name|ioctlcmd_t
operator|,
name|int
operator|,
name|int
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ipf_nat_log
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|ipf_nat_softc_t
operator|*
operator|,
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
name|nat_t
modifier|*
name|ipf_nat_lookupredir
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
name|ipf_nat_maplookup
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
name|ipf_nat_add
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|ipnat_t
operator|*
operator|,
name|nat_t
operator|*
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
name|int
name|ipf_nat_out
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|nat_t
operator|*
operator|,
name|int
operator|,
name|u_32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|nat_t
modifier|*
name|ipf_nat_outlookup
name|__P
argument_list|(
operator|(
name|fr_info_t
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_short
modifier|*
name|ipf_nat_proto
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ipf_nat_rule_deref
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|ipnat_t
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ipf_nat_setqueue
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|ipf_nat_softc_t
operator|*
operator|,
name|nat_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ipf_nat_setpending
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|nat_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|nat_t
modifier|*
name|ipf_nat_tnlookup
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

begin_decl_stmt
specifier|extern
name|void
name|ipf_nat_update
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|nat_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipf_nat_rehash
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|ipftuneable_t
operator|*
operator|,
name|ipftuneval_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipf_nat_rehash_rules
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|ipftuneable_t
operator|*
operator|,
name|ipftuneval_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipf_nat_settimeout
name|__P
argument_list|(
operator|(
expr|struct
name|ipf_main_softc_s
operator|*
operator|,
name|ipftuneable_t
operator|*
operator|,
name|ipftuneval_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ipf_nat_sync
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|nat_t
modifier|*
name|ipf_nat_clone
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|nat_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ipf_nat_delmap
name|__P
argument_list|(
operator|(
name|ipf_nat_softc_t
operator|*
operator|,
name|ipnat_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ipf_nat_delrdr
name|__P
argument_list|(
operator|(
name|ipf_nat_softc_t
operator|*
operator|,
name|ipnat_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipf_nat_wildok
name|__P
argument_list|(
operator|(
name|nat_t
operator|*
operator|,
name|int
operator|,
name|int
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
name|ipf_nat_setlock
name|__P
argument_list|(
operator|(
name|void
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
name|ipf_nat_load
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
modifier|*
name|ipf_nat_soft_create
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipf_nat_soft_init
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ipf_nat_soft_destroy
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipf_nat_soft_fini
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipf_nat_main_load
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
name|ipf_nat_main_unload
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
name|ipftq_t
modifier|*
name|ipf_nat_add_tq
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
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
name|ipf_nat_uncreate
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|USE_INET6
end_ifdef

begin_decl_stmt
specifier|extern
name|nat_t
modifier|*
name|ipf_nat6_add
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|ipnat_t
operator|*
operator|,
name|nat_t
operator|*
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
name|void
name|ipf_nat6_addrdr
name|__P
argument_list|(
operator|(
name|ipf_nat_softc_t
operator|*
operator|,
name|ipnat_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ipf_nat6_addmap
name|__P
argument_list|(
operator|(
name|ipf_nat_softc_t
operator|*
operator|,
name|ipnat_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ipf_nat6_addencap
name|__P
argument_list|(
operator|(
name|ipf_nat_softc_t
operator|*
operator|,
name|ipnat_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipf_nat6_checkout
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|u_32_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipf_nat6_checkin
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|u_32_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ipf_nat6_delmap
name|__P
argument_list|(
operator|(
name|ipf_nat_softc_t
operator|*
operator|,
name|ipnat_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ipf_nat6_delrdr
name|__P
argument_list|(
operator|(
name|ipf_nat_softc_t
operator|*
operator|,
name|ipnat_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipf_nat6_finalise
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|nat_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|nat_t
modifier|*
name|ipf_nat6_icmperror
name|__P
argument_list|(
operator|(
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
name|nat_t
modifier|*
name|ipf_nat6_icmperrorlookup
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

begin_decl_stmt
specifier|extern
name|nat_t
modifier|*
name|ipf_nat6_inlookup
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|u_int
operator|,
name|u_int
operator|,
expr|struct
name|in6_addr
operator|*
operator|,
expr|struct
name|in6_addr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_32_t
name|ipf_nat6_ip6subtract
name|__P
argument_list|(
operator|(
name|i6addr_t
operator|*
operator|,
name|i6addr_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|frentry_t
modifier|*
name|ipf_nat6_ipfin
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|u_32_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|frentry_t
modifier|*
name|ipf_nat6_ipfout
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|u_32_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|nat_t
modifier|*
name|ipf_nat6_lookupredir
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
name|int
name|ipf_nat6_newmap
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|nat_t
operator|*
operator|,
name|natinfo_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipf_nat6_newrdr
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|nat_t
operator|*
operator|,
name|natinfo_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|nat_t
modifier|*
name|ipf_nat6_outlookup
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|u_int
operator|,
name|u_int
operator|,
expr|struct
name|in6_addr
operator|*
operator|,
expr|struct
name|in6_addr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipf_nat6_newrewrite
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|nat_t
operator|*
operator|,
name|natinfo_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipf_nat6_newdivert
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|nat_t
operator|*
operator|,
name|natinfo_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipf_nat6_ruleaddrinit
name|__P
argument_list|(
operator|(
name|ipf_main_softc_t
operator|*
operator|,
name|ipf_nat_softc_t
operator|*
operator|,
name|ipnat_t
operator|*
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
comment|/* __IP_NAT_H__ */
end_comment

end_unit

