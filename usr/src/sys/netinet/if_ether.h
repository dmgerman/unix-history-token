begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)if_ether.h	7.6 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Structure of a 10Mb/s Ethernet header.  */
end_comment

begin_struct
struct|struct
name|ether_header
block|{
name|u_char
name|ether_dhost
index|[
literal|6
index|]
decl_stmt|;
name|u_char
name|ether_shost
index|[
literal|6
index|]
decl_stmt|;
name|u_short
name|ether_type
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ETHERTYPE_PUP
value|0x0200
end_define

begin_comment
comment|/* PUP protocol */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_IP
value|0x0800
end_define

begin_comment
comment|/* IP protocol */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_ARP
value|0x0806
end_define

begin_comment
comment|/* Addr. resolution protocol */
end_comment

begin_comment
comment|/*  * The ETHERTYPE_NTRAILER packet types starting at ETHERTYPE_TRAIL have  * (type-ETHERTYPE_TRAIL)*512 bytes of data followed  * by an ETHER type (as given above) and then the (variable-length) header.  */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_TRAIL
value|0x1000
end_define

begin_comment
comment|/* Trailer packet */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_NTRAILER
value|16
end_define

begin_define
define|#
directive|define
name|ETHERMTU
value|1500
end_define

begin_define
define|#
directive|define
name|ETHERMIN
value|(60-14)
end_define

begin_comment
comment|/*  * Ethernet Address Resolution Protocol.  *  * See RFC 826 for protocol description.  Structure below is adapted  * to resolving internet addresses.  Field names used correspond to   * RFC 826.  */
end_comment

begin_struct
struct|struct
name|ether_arp
block|{
name|struct
name|arphdr
name|ea_hdr
decl_stmt|;
comment|/* fixed-size header */
name|u_char
name|arp_sha
index|[
literal|6
index|]
decl_stmt|;
comment|/* sender hardware address */
name|u_char
name|arp_spa
index|[
literal|4
index|]
decl_stmt|;
comment|/* sender protocol address */
name|u_char
name|arp_tha
index|[
literal|6
index|]
decl_stmt|;
comment|/* target hardware address */
name|u_char
name|arp_tpa
index|[
literal|4
index|]
decl_stmt|;
comment|/* target protocol address */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|arp_hrd
value|ea_hdr.ar_hrd
end_define

begin_define
define|#
directive|define
name|arp_pro
value|ea_hdr.ar_pro
end_define

begin_define
define|#
directive|define
name|arp_hln
value|ea_hdr.ar_hln
end_define

begin_define
define|#
directive|define
name|arp_pln
value|ea_hdr.ar_pln
end_define

begin_define
define|#
directive|define
name|arp_op
value|ea_hdr.ar_op
end_define

begin_comment
comment|/*  * Structure shared between the ethernet driver modules and  * the address resolution code.  For example, each ec_softc or il_softc  * begins with this structure.  */
end_comment

begin_struct
struct|struct
name|arpcom
block|{
name|struct
name|ifnet
name|ac_if
decl_stmt|;
comment|/* network-visible interface */
name|u_char
name|ac_enaddr
index|[
literal|6
index|]
decl_stmt|;
comment|/* ethernet hardware address */
name|struct
name|in_addr
name|ac_ipaddr
decl_stmt|;
comment|/* copy of ip address- XXX */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Internet to ethernet address resolution table.  */
end_comment

begin_struct
struct|struct
name|arptab
block|{
name|struct
name|in_addr
name|at_iaddr
decl_stmt|;
comment|/* internet address */
name|u_char
name|at_enaddr
index|[
literal|6
index|]
decl_stmt|;
comment|/* ethernet address */
name|u_char
name|at_timer
decl_stmt|;
comment|/* minutes since last reference */
name|u_char
name|at_flags
decl_stmt|;
comment|/* flags */
name|struct
name|mbuf
modifier|*
name|at_hold
decl_stmt|;
comment|/* last packet until resolved/timeout */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|llinfo_arp
block|{
name|struct
name|llinfo_arp
modifier|*
name|la_next
decl_stmt|;
name|struct
name|llinfo_arp
modifier|*
name|la_prev
decl_stmt|;
name|struct
name|rtentry
modifier|*
name|la_rt
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|la_hold
decl_stmt|;
comment|/* last packet until resolved/timeout */
name|long
name|la_asked
decl_stmt|;
comment|/* last time we QUERIED for this addr */
define|#
directive|define
name|la_timer
value|la_rt->rt_rmx.rmx_expire
comment|/* deletion time in seconds */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sockaddr_inarp
block|{
name|u_char
name|sin_len
decl_stmt|;
name|u_char
name|sin_family
decl_stmt|;
name|u_short
name|sin_port
decl_stmt|;
name|struct
name|in_addr
name|sin_addr
decl_stmt|;
name|struct
name|in_addr
name|sin_srcaddr
decl_stmt|;
name|u_short
name|sin_tos
decl_stmt|;
name|u_short
name|sin_other
decl_stmt|;
define|#
directive|define
name|SIN_PROXY
value|1
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|u_char
name|etherbroadcastaddr
index|[
literal|6
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|llinfo_arp
modifier|*
name|arptnew
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|llinfo_arp
name|llinfo_arp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of the llinfo queue */
end_comment

begin_decl_stmt
name|int
name|ether_output
argument_list|()
decl_stmt|,
name|ether_input
argument_list|()
decl_stmt|,
name|arp_rtrequest
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|ether_sprintf
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|ifqueue
name|arpintrq
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

