begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)if.h	7.11 (Berkeley) 3/19/91  *	$Id: if.h,v 1.11 1993/12/19 00:52:02 wollman Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_IF_H_
value|1
end_define

begin_comment
comment|/*  * Structures defining a network interface, providing a packet  * transport mechanism (ala level 0 of the PUP protocols).  *  * Each interface accepts output datagrams of a specified maximum  * length, and provides higher level routines with input datagrams  * received from its medium.  *  * Output occurs when the routine if_output is called, with three parameters:  *	(*ifp->if_output)(ifp, m, dst)  * Here m is the mbuf chain to be sent and dst is the destination address.  * The output routine encapsulates the supplied datagram if necessary,  * and then transmits it on its medium.  *  * On input, each interface unwraps the data received by it, and either  * places it on the input queue of a internetwork datagram routine  * and posts the associated software interrupt, or passes the datagram to a raw  * packet input routine.  *  * Routines exist for locating interfaces by their addresses  * or for locating a interface on a certain network, as well as more general  * routing and gateway routines maintaining information used to locate  * interfaces.  These routines live in the files if.c and route.c  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TIME_
end_ifndef

begin_comment
comment|/*  XXX fast fix for SNMP, going away soon */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"../sys/time.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Structure defining a queue for a network interface.  *  * (Would like to call this struct ``if'', but C isn't PL/1.)  */
end_comment

begin_struct_decl
struct_decl|struct
name|rtentry
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ifnet
block|{
name|char
modifier|*
name|if_name
decl_stmt|;
comment|/* name, e.g. ``en'' or ``lo'' */
name|short
name|if_unit
decl_stmt|;
comment|/* sub-unit for lower level driver */
name|u_short
name|if_mtu
decl_stmt|;
comment|/* maximum transmission unit */
name|u_int
name|if_flags
decl_stmt|;
comment|/* up/down, broadcast, etc. */
name|short
name|if_timer
decl_stmt|;
comment|/* time 'til if_watchdog called */
name|int
name|if_metric
decl_stmt|;
comment|/* routing metric (external only) */
name|struct
name|ifaddr
modifier|*
name|if_addrlist
decl_stmt|;
comment|/* linked list of addresses per if */
struct|struct
name|ifqueue
block|{
name|struct
name|mbuf
modifier|*
name|ifq_head
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|ifq_tail
decl_stmt|;
name|int
name|ifq_len
decl_stmt|;
name|int
name|ifq_maxlen
decl_stmt|;
name|int
name|ifq_drops
decl_stmt|;
block|}
name|if_snd
struct|;
comment|/* output queue */
comment|/* procedure handles */
name|void
function_decl|(
modifier|*
name|if_init
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
comment|/* init routine */
name|int
function_decl|(
modifier|*
name|if_output
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|rtentry
modifier|*
parameter_list|)
function_decl|;
comment|/* output routine (enqueue) */
name|void
function_decl|(
modifier|*
name|if_start
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
comment|/* initiate output routine */
name|int
function_decl|(
modifier|*
name|if_done
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
comment|/* output complete routine */
name|int
function_decl|(
modifier|*
name|if_ioctl
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
comment|/* ioctl routine */
name|void
function_decl|(
modifier|*
name|if_reset
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* bus reset routine */
name|void
function_decl|(
modifier|*
name|if_watchdog
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
comment|/* timer routine */
comment|/* generic interface statistics */
name|int
name|if_ipackets
decl_stmt|;
comment|/* packets received on interface */
name|int
name|if_ierrors
decl_stmt|;
comment|/* input errors on interface */
name|int
name|if_opackets
decl_stmt|;
comment|/* packets sent on interface */
name|int
name|if_oerrors
decl_stmt|;
comment|/* output errors on interface */
name|int
name|if_collisions
decl_stmt|;
comment|/* collisions on csma interfaces */
comment|/* end statistics */
name|struct
name|ifnet
modifier|*
name|if_next
decl_stmt|;
name|u_char
name|if_type
decl_stmt|;
comment|/* ethernet, tokenring, etc */
name|u_char
name|if_addrlen
decl_stmt|;
comment|/* media address length */
name|u_char
name|if_hdrlen
decl_stmt|;
comment|/* media header length */
name|u_char
name|if_index
decl_stmt|;
comment|/* numeric abbreviation for this if  */
comment|/* more statistics here to avoid recompiling netstat */
name|struct
name|timeval
name|if_lastchange
decl_stmt|;
comment|/* last updated */
name|int
name|if_ibytes
decl_stmt|;
comment|/* total number of octets received */
name|int
name|if_obytes
decl_stmt|;
comment|/* total number of octets sent */
name|int
name|if_imcasts
decl_stmt|;
comment|/* packets received via multicast */
name|int
name|if_omcasts
decl_stmt|;
comment|/* packets sent via multicast */
name|int
name|if_iqdrops
decl_stmt|;
comment|/* dropped on input, this interface */
name|int
name|if_noproto
decl_stmt|;
comment|/* destined for unsupported protocol */
name|int
name|if_baudrate
decl_stmt|;
comment|/* linespeed */
name|int
name|if_pcount
decl_stmt|;
comment|/* number of promiscuous listeners */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IFF_UP
value|0x1
end_define

begin_comment
comment|/* interface is up */
end_comment

begin_define
define|#
directive|define
name|IFF_BROADCAST
value|0x2
end_define

begin_comment
comment|/* broadcast address valid */
end_comment

begin_define
define|#
directive|define
name|IFF_DEBUG
value|0x4
end_define

begin_comment
comment|/* turn on debugging */
end_comment

begin_define
define|#
directive|define
name|IFF_LOOPBACK
value|0x8
end_define

begin_comment
comment|/* is a loopback net */
end_comment

begin_define
define|#
directive|define
name|IFF_POINTOPOINT
value|0x10
end_define

begin_comment
comment|/* interface is point-to-point link */
end_comment

begin_define
define|#
directive|define
name|IFF_NOTRAILERS
value|0x20
end_define

begin_comment
comment|/* avoid use of trailers */
end_comment

begin_define
define|#
directive|define
name|IFF_RUNNING
value|0x40
end_define

begin_comment
comment|/* resources allocated */
end_comment

begin_define
define|#
directive|define
name|IFF_NOARP
value|0x80
end_define

begin_comment
comment|/* no address resolution protocol */
end_comment

begin_comment
comment|/* next two not supported now, but reserved: */
end_comment

begin_define
define|#
directive|define
name|IFF_PROMISC
value|0x100
end_define

begin_comment
comment|/* receive all packets */
end_comment

begin_define
define|#
directive|define
name|IFF_ALLMULTI
value|0x200
end_define

begin_comment
comment|/* receive all multicast packets */
end_comment

begin_define
define|#
directive|define
name|IFF_OACTIVE
value|0x400
end_define

begin_comment
comment|/* transmission in progress */
end_comment

begin_define
define|#
directive|define
name|IFF_SIMPLEX
value|0x800
end_define

begin_comment
comment|/* can't hear own transmissions */
end_comment

begin_define
define|#
directive|define
name|IFF_LLC0
value|0x1000
end_define

begin_comment
comment|/* IEEE 802.2 LLC class 0 */
end_comment

begin_define
define|#
directive|define
name|IFF_LLC1
value|0x2000
end_define

begin_comment
comment|/* IEEE 802.2 LLC class 1 */
end_comment

begin_define
define|#
directive|define
name|IFF_LLC2
value|0x4000
end_define

begin_comment
comment|/* IEEE 802.2 LLC class 2 */
end_comment

begin_define
define|#
directive|define
name|IFF_ALTPHYS
value|0x8000
end_define

begin_comment
comment|/* alternative physical connection */
end_comment

begin_define
define|#
directive|define
name|IFF_MULTICAST
value|0x10000
end_define

begin_comment
comment|/* i'face supports multicast */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_define
define|#
directive|define
name|IFF_VIRTUAL
value|0x20000
end_define

begin_comment
comment|/* i'face is really a VIF */
end_comment

begin_comment
comment|/* flags set internally only: */
end_comment

begin_define
define|#
directive|define
name|IFF_CANTCHANGE
define|\
value|(IFF_BROADCAST|IFF_POINTOPOINT|IFF_RUNNING|IFF_OACTIVE|IFF_SIMPLEX\ 	 |IFF_MULTICAST|IFF_VIRTUAL)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IFF_CANTCHANGE
define|\
value|(IFF_BROADCAST|IFF_POINTOPOINT|IFF_RUNNING|IFF_OACTIVE|IFF_SIMPLEX\ 	 |IFF_MULTICAST)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Output queues (ifp->if_snd) and internetwork datagram level (pup level 1)  * input routines have queues of messages stored on ifqueue structures  * (defined above).  Entries are added to and deleted from these structures  * by these macros, which should be called with ipl raised to splimp().  */
end_comment

begin_define
define|#
directive|define
name|IF_QFULL
parameter_list|(
name|ifq
parameter_list|)
value|((ifq)->ifq_len>= (ifq)->ifq_maxlen)
end_define

begin_define
define|#
directive|define
name|IF_DROP
parameter_list|(
name|ifq
parameter_list|)
value|((ifq)->ifq_drops++)
end_define

begin_define
define|#
directive|define
name|IF_ENQUEUE
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
value|{ \ 	(m)->m_nextpkt = 0; \ 	if ((ifq)->ifq_tail == 0) \ 		(ifq)->ifq_head = m; \ 	else \ 		(ifq)->ifq_tail->m_nextpkt = m; \ 	(ifq)->ifq_tail = m; \ 	(ifq)->ifq_len++; \ }
end_define

begin_define
define|#
directive|define
name|IF_PREPEND
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
value|{ \ 	(m)->m_nextpkt = (ifq)->ifq_head; \ 	if ((ifq)->ifq_tail == 0) \ 		(ifq)->ifq_tail = (m); \ 	(ifq)->ifq_head = (m); \ 	(ifq)->ifq_len++; \ }
end_define

begin_define
define|#
directive|define
name|IF_DEQUEUE
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
value|{ \ 	(m) = (ifq)->ifq_head; \ 	if (m) { \ 		if (((ifq)->ifq_head = (m)->m_nextpkt) == 0) \ 			(ifq)->ifq_tail = 0; \ 		(m)->m_nextpkt = 0; \ 		(ifq)->ifq_len--; \ 	} \ }
end_define

begin_define
define|#
directive|define
name|IFQ_MAXLEN
value|50
end_define

begin_define
define|#
directive|define
name|IFNET_SLOWHZ
value|1
end_define

begin_comment
comment|/* granularity is 1 second */
end_comment

begin_comment
comment|/*  * The ifaddr structure contains information about one address  * of an interface.  They are maintained by the different address families,  * are allocated and attached when an address is set, and are linked  * together so all addresses for an interface can be located.  */
end_comment

begin_struct_decl
struct_decl|struct
name|rtentry
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ifaddr
block|{
name|struct
name|sockaddr
modifier|*
name|ifa_addr
decl_stmt|;
comment|/* address of interface */
name|struct
name|sockaddr
modifier|*
name|ifa_dstaddr
decl_stmt|;
comment|/* other end of p-to-p link */
define|#
directive|define
name|ifa_broadaddr
value|ifa_dstaddr
comment|/* broadcast address interface */
name|struct
name|sockaddr
modifier|*
name|ifa_netmask
decl_stmt|;
comment|/* used to determine subnet */
name|struct
name|ifnet
modifier|*
name|ifa_ifp
decl_stmt|;
comment|/* back-pointer to interface */
name|struct
name|ifaddr
modifier|*
name|ifa_next
decl_stmt|;
comment|/* next address for interface */
name|void
function_decl|(
modifier|*
name|ifa_rtrequest
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|struct
name|rtentry
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
comment|/* check or clean routes (+ or -)'d */
name|struct
name|rtentry
modifier|*
name|ifa_rt
decl_stmt|;
comment|/* ??? for ROUTETOIF */
name|u_short
name|ifa_flags
decl_stmt|;
comment|/* mostly rt_flags for cloning */
name|u_short
name|ifa_llinfolen
decl_stmt|;
comment|/* extra to malloc for link info */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IFA_ROUTE
value|RTF_UP
end_define

begin_comment
comment|/* route installed */
end_comment

begin_comment
comment|/*  * Interface request structure used for socket  * ioctl's.  All interface ioctl's must have parameter  * definitions which begin with ifr_name.  The  * remainder may be interface specific.  */
end_comment

begin_struct
struct|struct
name|ifreq
block|{
define|#
directive|define
name|IFNAMSIZ
value|16
name|char
name|ifr_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* if name, e.g. "en0" */
union|union
block|{
name|struct
name|sockaddr
name|ifru_addr
decl_stmt|;
name|struct
name|sockaddr
name|ifru_dstaddr
decl_stmt|;
name|struct
name|sockaddr
name|ifru_broadaddr
decl_stmt|;
name|u_int
name|ifru_flags
decl_stmt|;
name|int
name|ifru_metric
decl_stmt|;
name|caddr_t
name|ifru_data
decl_stmt|;
block|}
name|ifr_ifru
union|;
define|#
directive|define
name|ifr_addr
value|ifr_ifru.ifru_addr
comment|/* address */
define|#
directive|define
name|ifr_dstaddr
value|ifr_ifru.ifru_dstaddr
comment|/* other end of p-to-p link */
define|#
directive|define
name|ifr_broadaddr
value|ifr_ifru.ifru_broadaddr
comment|/* broadcast address */
define|#
directive|define
name|ifr_flags
value|ifr_ifru.ifru_flags
comment|/* flags */
define|#
directive|define
name|ifr_metric
value|ifr_ifru.ifru_metric
comment|/* metric */
define|#
directive|define
name|ifr_data
value|ifr_ifru.ifru_data
comment|/* for use by interface */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ifaliasreq
block|{
name|char
name|ifra_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* if name, e.g. "en0" */
name|struct
name|sockaddr
name|ifra_addr
decl_stmt|;
name|struct
name|sockaddr
name|ifra_broadaddr
decl_stmt|;
name|struct
name|sockaddr
name|ifra_mask
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure used in SIOCGIFCONF request.  * Used to retrieve interface configuration  * for machine (useful for programs which  * must know all networks accessible).  */
end_comment

begin_struct
struct|struct
name|ifconf
block|{
name|int
name|ifc_len
decl_stmt|;
comment|/* size of associated buffer */
union|union
block|{
name|caddr_t
name|ifcu_buf
decl_stmt|;
name|struct
name|ifreq
modifier|*
name|ifcu_req
decl_stmt|;
block|}
name|ifc_ifcu
union|;
define|#
directive|define
name|ifc_buf
value|ifc_ifcu.ifcu_buf
comment|/* buffer address */
define|#
directive|define
name|ifc_req
value|ifc_ifcu.ifcu_req
comment|/* array of structures returned */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"../net/if_arp.h"
end_include

begin_decl_stmt
specifier|extern
name|struct
name|ifqueue
name|rawintrq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* raw packet input queue */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|ifnet
modifier|*
name|ifnet
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ifaddr
modifier|*
name|ifa_ifwithaddr
argument_list|()
decl_stmt|,
modifier|*
name|ifa_ifwithnet
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|ifaddr
modifier|*
name|ifa_ifwithdstaddr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ifpromisc
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Loopback interface, used internally by non-loopback code */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|ifnet
name|loif
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|looutput
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|rtentry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* KERNEL */
end_comment

begin_include
include|#
directive|include
file|<net/if_arp.h>
end_include

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
comment|/* _NET_IF_H_ */
end_comment

end_unit

