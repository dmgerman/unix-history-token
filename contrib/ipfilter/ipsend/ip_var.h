begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)ip_var.h 1.11 88/08/19 SMI; from UCB 7.1 6/5/86	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_comment
comment|/*  * Overlay for ip header used by other protocols (tcp, udp).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_netinet_ip_var_h
end_ifndef

begin_define
define|#
directive|define
name|_netinet_ip_var_h
end_define

begin_struct
struct|struct
name|ipovly
block|{
name|caddr_t
name|ih_next
decl_stmt|,
name|ih_prev
decl_stmt|;
comment|/* for protocol sequence q's */
name|u_char
name|ih_x1
decl_stmt|;
comment|/* (unused) */
name|u_char
name|ih_pr
decl_stmt|;
comment|/* protocol */
name|short
name|ih_len
decl_stmt|;
comment|/* protocol length */
name|struct
name|in_addr
name|ih_src
decl_stmt|;
comment|/* source internet address */
name|struct
name|in_addr
name|ih_dst
decl_stmt|;
comment|/* destination internet address */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ip reassembly queue structure.  Each fragment  * being reassembled is attached to one of these structures.  * They are timed out after ipq_ttl drops to 0, and may also  * be reclaimed if memory becomes tight.  */
end_comment

begin_struct
struct|struct
name|ipq
block|{
name|struct
name|ipq
modifier|*
name|next
decl_stmt|,
modifier|*
name|prev
decl_stmt|;
comment|/* to other reass headers */
name|u_char
name|ipq_ttl
decl_stmt|;
comment|/* time for reass q to live */
name|u_char
name|ipq_p
decl_stmt|;
comment|/* protocol of this fragment */
name|u_short
name|ipq_id
decl_stmt|;
comment|/* sequence id for reassembly */
name|struct
name|ipasfrag
modifier|*
name|ipq_next
decl_stmt|,
modifier|*
name|ipq_prev
decl_stmt|;
comment|/* to ip headers of fragments */
name|struct
name|in_addr
name|ipq_src
decl_stmt|,
name|ipq_dst
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ip header, when holding a fragment.  *  * Note: ipf_next must be at same offset as ipq_next above  */
end_comment

begin_struct
struct|struct
name|ipasfrag
block|{
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|i386
argument_list|)
name|u_char
name|ip_hl
range|:
literal|4
decl_stmt|,
name|ip_v
range|:
literal|4
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|mc68000
argument_list|)
operator|||
name|defined
argument_list|(
name|sparc
argument_list|)
name|u_char
name|ip_v
range|:
literal|4
decl_stmt|,
name|ip_hl
range|:
literal|4
decl_stmt|;
endif|#
directive|endif
name|u_char
name|ipf_mff
decl_stmt|;
comment|/* copied from (ip_off&IP_MF) */
name|short
name|ip_len
decl_stmt|;
name|u_short
name|ip_id
decl_stmt|;
name|short
name|ip_off
decl_stmt|;
name|u_char
name|ip_ttl
decl_stmt|;
name|u_char
name|ip_p
decl_stmt|;
name|u_short
name|ip_sum
decl_stmt|;
name|struct
name|ipasfrag
modifier|*
name|ipf_next
decl_stmt|;
comment|/* next fragment */
name|struct
name|ipasfrag
modifier|*
name|ipf_prev
decl_stmt|;
comment|/* previous fragment */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure stored in mbuf in inpcb.ip_options  * and passed to ip_output when ip options are in use.  * The actual length of the options (including ipopt_dst)  * is in m_len.  */
end_comment

begin_define
define|#
directive|define
name|MAX_IPOPTLEN
value|40
end_define

begin_struct
struct|struct
name|ipoption
block|{
name|struct
name|in_addr
name|ipopt_dst
decl_stmt|;
comment|/* first-hop dst if source routed */
name|char
name|ipopt_list
index|[
name|MAX_IPOPTLEN
index|]
decl_stmt|;
comment|/* options proper */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure stored in an mbuf attached to inpcb.ip_moptions and  * passed to ip_output when IP multicast options are in use.  */
end_comment

begin_struct
struct|struct
name|ip_moptions
block|{
name|struct
name|ifnet
modifier|*
name|imo_multicast_ifp
decl_stmt|;
comment|/* ifp for outgoing multicasts */
name|u_char
name|imo_multicast_ttl
decl_stmt|;
comment|/* TTL for outgoing multicasts */
name|u_char
name|imo_multicast_loop
decl_stmt|;
comment|/* 1 => hear sends if a member */
name|u_short
name|imo_num_memberships
decl_stmt|;
comment|/* no. memberships this socket */
name|struct
name|in_multi
modifier|*
name|imo_membership
index|[
name|IP_MAX_MEMBERSHIPS
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|RSVP_ISI
name|long
name|imo_multicast_vif
decl_stmt|;
comment|/* vif for outgoing multicasts */
endif|#
directive|endif
comment|/* RSVP_ISI */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ipstat
block|{
name|long
name|ips_total
decl_stmt|;
comment|/* total packets received */
name|long
name|ips_badsum
decl_stmt|;
comment|/* checksum bad */
name|long
name|ips_tooshort
decl_stmt|;
comment|/* packet too short */
name|long
name|ips_toosmall
decl_stmt|;
comment|/* not enough data */
name|long
name|ips_badhlen
decl_stmt|;
comment|/* ip header length< data size */
name|long
name|ips_badlen
decl_stmt|;
comment|/* ip length< ip header length */
name|long
name|ips_fragments
decl_stmt|;
comment|/* fragments received */
name|long
name|ips_fragdropped
decl_stmt|;
comment|/* frags dropped (dups, out of space) */
name|long
name|ips_fragtimeout
decl_stmt|;
comment|/* fragments timed out */
name|long
name|ips_forward
decl_stmt|;
comment|/* packets forwarded */
name|long
name|ips_cantforward
decl_stmt|;
comment|/* packets rcvd for unreachable dest */
name|long
name|ips_redirectsent
decl_stmt|;
comment|/* packets forwarded on same net */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/* flags passed to ip_output as last parameter */
end_comment

begin_define
define|#
directive|define
name|IP_FORWARDING
value|0x1
end_define

begin_comment
comment|/* most of ip header exists */
end_comment

begin_define
define|#
directive|define
name|IP_MULTICASTOPTS
value|0x2
end_define

begin_comment
comment|/* multicast opts present */
end_comment

begin_define
define|#
directive|define
name|IP_ROUTETOIF
value|SO_DONTROUTE
end_define

begin_comment
comment|/* bypass routing tables */
end_comment

begin_define
define|#
directive|define
name|IP_ALLOWBROADCAST
value|SO_BROADCAST
end_define

begin_comment
comment|/* can send broadcast packets */
end_comment

begin_decl_stmt
name|struct
name|ipstat
name|ipstat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ipq
name|ipq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ip reass. queue */
end_comment

begin_decl_stmt
name|u_short
name|ip_id
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ip packet ctr, for ids */
end_comment

begin_function_decl
name|struct
name|mbuf
modifier|*
name|ip_srcroute
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
comment|/*!_netinet_ip_var_h*/
end_comment

end_unit

