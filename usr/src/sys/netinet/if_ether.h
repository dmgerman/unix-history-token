begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	if_ether.h	6.4	85/04/16	*/
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
comment|/*  * The ETHERTYPE_NTRAILER packet types starting at ETHERTYPE_TRAIL have  * (type-ETHERPUP_TRAIL)*512 bytes of data followed  * by a PUP type (as given above) and then the (variable-length) header.  */
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
name|u_short
name|arp_hrd
decl_stmt|;
comment|/* format of hardware address */
define|#
directive|define
name|ARPHRD_ETHER
value|1
comment|/* ethernet hardware address */
name|u_short
name|arp_pro
decl_stmt|;
comment|/* format of proto. address (ETHERPUP_IPTYPE) */
name|u_char
name|arp_hln
decl_stmt|;
comment|/* length of hardware address (6) */
name|u_char
name|arp_pln
decl_stmt|;
comment|/* length of protocol address (4) */
name|u_short
name|arp_op
decl_stmt|;
define|#
directive|define
name|ARPOP_REQUEST
value|1
comment|/* request to resolve address */
define|#
directive|define
name|ARPOP_REPLY
value|2
comment|/* response to previous request */
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
name|struct
name|mbuf
modifier|*
name|at_hold
decl_stmt|;
comment|/* last packet until resolved/timeout */
name|u_char
name|at_timer
decl_stmt|;
comment|/* minutes since last reference */
name|u_char
name|at_flags
decl_stmt|;
comment|/* flags */
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
name|arptab
modifier|*
name|arptnew
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

