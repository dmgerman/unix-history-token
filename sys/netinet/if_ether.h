begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)if_ether.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_IF_ETHER_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_IF_ETHER_H_
end_define

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

begin_comment
comment|/*  * Structure of a 48-bit Ethernet address.  */
end_comment

begin_struct
struct|struct
name|ether_addr
block|{
name|u_char
name|octet
index|[
literal|6
index|]
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

begin_define
define|#
directive|define
name|ETHERTYPE_REVARP
value|0x8035
end_define

begin_comment
comment|/* reverse Addr. resolution protocol */
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * Macro to map an IP multicast address to an Ethernet multicast address.  * The high-order 25 bits of the Ethernet address are statically assigned,  * and the low-order 23 bits are taken from the low end of the IP address.  */
end_comment

begin_define
define|#
directive|define
name|ETHER_MAP_IP_MULTICAST
parameter_list|(
name|ipaddr
parameter_list|,
name|enaddr
parameter_list|)
define|\
comment|/* struct in_addr *ipaddr; */
define|\
comment|/* u_char enaddr[6];	   */
define|\
value|{ \ 	(enaddr)[0] = 0x01; \ 	(enaddr)[1] = 0x00; \ 	(enaddr)[2] = 0x5e; \ 	(enaddr)[3] = ((u_char *)ipaddr)[1]& 0x7f; \ 	(enaddr)[4] = ((u_char *)ipaddr)[2]; \ 	(enaddr)[5] = ((u_char *)ipaddr)[3]; \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Ethernet Address Resolution Protocol.  *  * See RFC 826 for protocol description.  Structure below is adapted  * to resolving internet addresses.  Field names used correspond to  * RFC 826.  */
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
name|struct
name|ether_multi
modifier|*
name|ac_multiaddrs
decl_stmt|;
comment|/* list of ether multicast addrs */
name|int
name|ac_multicnt
decl_stmt|;
comment|/* length of ac_multiaddrs list */
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

begin_comment
comment|/*  * IP and ethernet specific routing flags  */
end_comment

begin_define
define|#
directive|define
name|RTF_USETRAILERS
value|RTF_PROTO1
end_define

begin_comment
comment|/* use trailers */
end_comment

begin_define
define|#
directive|define
name|RTF_ANNOUNCE
value|RTF_PROTO2
end_define

begin_comment
comment|/* announce new arp entry */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|u_char
name|etherbroadcastaddr
index|[
literal|6
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|ether_ipmulticast_min
index|[
literal|6
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|ether_ipmulticast_max
index|[
literal|6
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ifqueue
name|arpintrq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|llinfo_arp
modifier|*
name|arptnew
name|__P
argument_list|(
operator|(
expr|struct
name|in_addr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|llinfo_arp
name|llinfo_arp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of the llinfo queue */
end_comment

begin_decl_stmt
name|void
name|arpwhohas
name|__P
argument_list|(
operator|(
expr|struct
name|arpcom
operator|*
operator|,
expr|struct
name|in_addr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|arpintr
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|arpresolve
name|__P
argument_list|(
operator|(
expr|struct
name|arpcom
operator|*
operator|,
expr|struct
name|rtentry
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
name|u_char
operator|*
operator|,
expr|struct
name|rtentry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|arp_ifinit
name|__P
argument_list|(
operator|(
expr|struct
name|arpcom
operator|*
operator|,
expr|struct
name|ifaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ether_addmulti
name|__P
argument_list|(
operator|(
expr|struct
name|ifreq
operator|*
operator|,
expr|struct
name|arpcom
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ether_delmulti
name|__P
argument_list|(
operator|(
expr|struct
name|ifreq
operator|*
operator|,
expr|struct
name|arpcom
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Ethernet multicast address structure.  There is one of these for each  * multicast address or range of multicast addresses that we are supposed  * to listen to on a particular interface.  They are kept in a linked list,  * rooted in the interface's arpcom structure.  (This really has nothing to  * do with ARP, or with the Internet address family, but this appears to be  * the minimally-disrupting place to put it.)  */
end_comment

begin_struct
struct|struct
name|ether_multi
block|{
name|u_char
name|enm_addrlo
index|[
literal|6
index|]
decl_stmt|;
comment|/* low  or only address of range */
name|u_char
name|enm_addrhi
index|[
literal|6
index|]
decl_stmt|;
comment|/* high or only address of range */
name|struct
name|arpcom
modifier|*
name|enm_ac
decl_stmt|;
comment|/* back pointer to arpcom */
name|u_int
name|enm_refcount
decl_stmt|;
comment|/* no. claims to this addr/range */
name|struct
name|ether_multi
modifier|*
name|enm_next
decl_stmt|;
comment|/* ptr to next ether_multi */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure used by macros below to remember position when stepping through  * all of the ether_multi records.  */
end_comment

begin_struct
struct|struct
name|ether_multistep
block|{
name|struct
name|ether_multi
modifier|*
name|e_enm
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Macro for looking up the ether_multi record for a given range of Ethernet  * multicast addresses connected to a given arpcom structure.  If no matching  * record is found, "enm" returns NULL.  */
end_comment

begin_define
define|#
directive|define
name|ETHER_LOOKUP_MULTI
parameter_list|(
name|addrlo
parameter_list|,
name|addrhi
parameter_list|,
name|ac
parameter_list|,
name|enm
parameter_list|)
define|\
comment|/* u_char addrlo[6]; */
define|\
comment|/* u_char addrhi[6]; */
define|\
comment|/* struct arpcom *ac; */
define|\
comment|/* struct ether_multi *enm; */
define|\
value|{ \ 	for ((enm) = (ac)->ac_multiaddrs; \ 	    (enm) != NULL&& \ 	    (bcmp((enm)->enm_addrlo, (addrlo), 6) != 0 || \ 	     bcmp((enm)->enm_addrhi, (addrhi), 6) != 0); \ 		(enm) = (enm)->enm_next); \ }
end_define

begin_comment
comment|/*  * Macro to step through all of the ether_multi records, one at a time.  * The current position is remembered in "step", which the caller must  * provide.  ETHER_FIRST_MULTI(), below, must be called to initialize "step"  * and get the first record.  Both macros return a NULL "enm" when there  * are no remaining records.  */
end_comment

begin_define
define|#
directive|define
name|ETHER_NEXT_MULTI
parameter_list|(
name|step
parameter_list|,
name|enm
parameter_list|)
define|\
comment|/* struct ether_multistep step; */
define|\
comment|/* struct ether_multi *enm; */
define|\
value|{ \ 	if (((enm) = (step).e_enm) != NULL) \ 		(step).e_enm = (enm)->enm_next; \ }
end_define

begin_define
define|#
directive|define
name|ETHER_FIRST_MULTI
parameter_list|(
name|step
parameter_list|,
name|ac
parameter_list|,
name|enm
parameter_list|)
define|\
comment|/* struct ether_multistep step; */
define|\
comment|/* struct arpcom *ac; */
define|\
comment|/* struct ether_multi *enm; */
define|\
value|{ \ 	(step).e_enm = (ac)->ac_multiaddrs; \ 	ETHER_NEXT_MULTI((step), (enm)); \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

