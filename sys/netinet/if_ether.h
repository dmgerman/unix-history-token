begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)if_ether.h	7.5 (Berkeley) 6/28/90  *	$Id: if_ether.h,v 1.4 1993/11/25 01:35:01 wollman Exp $  */
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
value|1
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * Macro to map an IP multicast address to an Ethernet multicast address.  * The high-order 25 bites of the Ethernet address are staticall assigned,  * and the low-rder 23 bites are taken from the low end of the IP address.  */
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
comment|/* u_char enaddr[6]; */
define|\
value|{ \ 	(enaddr)[0] = 0x01; \ 	(enaddr)[1] = 0x00; \ 	(enaddr)[2] = 0x5e; \ 	(enaddr)[3] = ((u_char *)ipaddr)[1]& 0x7f; \ 	(enaddr)[4] = ((u_char *)ipaddr)[2]; \ 	(enaddr)[5] = ((u_char *)ipaddr)[3]; \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|struct
name|ether_multi
modifier|*
name|ac_multiaddrs
decl_stmt|;
comment|/* list of ether m'cast addrs */
name|int
name|ac_multicnt
decl_stmt|;
comment|/* length of ac_multiaddrs list */
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

begin_comment
comment|/* defined in net/if_ethersubr.c */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ISO
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MULTICAST
argument_list|)
end_if

begin_define
define|#
directive|define
name|MULTICAST
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MULTICAST
end_ifdef

begin_decl_stmt
name|u_char
name|ether_ipmulticast_min
index|[
literal|6
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
name|ether_ipmulticast_max
index|[
literal|6
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|struct
name|arptab
modifier|*
name|arptnew
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ether_input
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|ether_header
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|ether_sprintf
parameter_list|(
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|MULTICAST
end_ifdef

begin_comment
comment|/*      * Ethernet multicast address structure.  There is one of these for each  * multicast address or range of multicast addresses that we are supposed  * to listen to on a particular interface.  They are kept in a linked list,  * rooted in the interface's arpcom structure.  (This really has nothing to  * do with ARP, or with the Internet address family, but this appears to be  * the minimally-disrupting place to put it.)  */
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
comment|/* low or only address of range */
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
comment|/* back point to arpcom */
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
value|{ \       for ((enm) = (ac)->ac_multiaddrs; \           (enm) != NULL&& \           (bcmp((enm)->enm_addrlo, (addrlo), 6) != 0 || \            bcmp((enm)->enm_addrhi, (addrhi), 6) != 0); \               (enm) = (enm)->enm_next); \ }
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
value|{ \       if (((enm) = (step).e_enm) != NULL) \               (step).e_enm = (enm)->enm_next; \ }
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
value|{ \       (step).e_enm = (ac)->ac_multiaddrs; \       ETHER_NEXT_MULTI((step), (enm)); \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MULTICAST */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETINET_IF_ETHER_H_ */
end_comment

end_unit

