begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)if.h	7.3 (Berkeley) 6/27/88  */
end_comment

begin_comment
comment|/*  * Structures defining a network interface, providing a packet  * transport mechanism (ala level 0 of the PUP protocols).  *  * Each interface accepts output datagrams of a specified maximum  * length, and provides higher level routines with input datagrams  * received from its medium.  *  * Output occurs when the routine if_output is called, with three parameters:  *	(*ifp->if_output)(ifp, m, dst)  * Here m is the mbuf chain to be sent and dst is the destination address.  * The output routine encapsulates the supplied datagram if necessary,  * and then transmits it on its medium.  *  * On input, each interface unwraps the data received by it, and either  * places it on the input queue of a internetwork datagram routine  * and posts the associated software interrupt, or passes the datagram to a raw  * packet input routine.  *  * Routines exist for locating interfaces by their addresses  * or for locating a interface on a certain network, as well as more general  * routing and gateway routines maintaining information used to locate  * interfaces.  These routines live in the files if.c and route.c  */
end_comment

begin_comment
comment|/*  * Structure defining a queue for a network interface.  *  * (Would like to call this struct ``if'', but C isn't PL/1.)  */
end_comment

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
name|short
name|if_mtu
decl_stmt|;
comment|/* maximum transmission unit */
name|short
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
name|int
function_decl|(
modifier|*
name|if_init
function_decl|)
parameter_list|()
function_decl|;
comment|/* init routine */
name|int
function_decl|(
modifier|*
name|if_output
function_decl|)
parameter_list|()
function_decl|;
comment|/* output routine */
name|int
function_decl|(
modifier|*
name|if_ioctl
function_decl|)
parameter_list|()
function_decl|;
comment|/* ioctl routine */
name|int
function_decl|(
modifier|*
name|if_reset
function_decl|)
parameter_list|()
function_decl|;
comment|/* bus reset routine */
name|int
function_decl|(
modifier|*
name|if_watchdog
function_decl|)
parameter_list|()
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

begin_comment
comment|/* flags set internally only: */
end_comment

begin_define
define|#
directive|define
name|IFF_CANTCHANGE
value|(IFF_BROADCAST | IFF_POINTOPOINT | IFF_RUNNING)
end_define

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
value|{ \ 	(m)->m_act = 0; \ 	if ((ifq)->ifq_tail == 0) \ 		(ifq)->ifq_head = m; \ 	else \ 		(ifq)->ifq_tail->m_act = m; \ 	(ifq)->ifq_tail = m; \ 	(ifq)->ifq_len++; \ }
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
value|{ \ 	(m)->m_act = (ifq)->ifq_head; \ 	if ((ifq)->ifq_tail == 0) \ 		(ifq)->ifq_tail = (m); \ 	(ifq)->ifq_head = (m); \ 	(ifq)->ifq_len++; \ }
end_define

begin_comment
comment|/*  * Packets destined for level-1 protocol input routines  * have a pointer to the receiving interface prepended to the data.  * IF_DEQUEUEIF extracts and returns this pointer when dequeueing the packet.  * IF_ADJ should be used otherwise to adjust for its presence.  */
end_comment

begin_define
define|#
directive|define
name|IF_ADJ
parameter_list|(
name|m
parameter_list|)
value|{ \ 	(m)->m_off += sizeof(struct ifnet *); \ 	(m)->m_len -= sizeof(struct ifnet *); \ 	if ((m)->m_len == 0) { \ 		struct mbuf *n; \ 		MFREE((m), n); \ 		(m) = n; \ 	} \ }
end_define

begin_define
define|#
directive|define
name|IF_DEQUEUEIF
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|,
name|ifp
parameter_list|)
value|{ \ 	(m) = (ifq)->ifq_head; \ 	if (m) { \ 		if (((ifq)->ifq_head = (m)->m_act) == 0) \ 			(ifq)->ifq_tail = 0; \ 		(m)->m_act = 0; \ 		(ifq)->ifq_len--; \ 		(ifp) = *(mtod((m), struct ifnet **)); \ 		IF_ADJ(m); \ 	} \ }
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
value|{ \ 	(m) = (ifq)->ifq_head; \ 	if (m) { \ 		if (((ifq)->ifq_head = (m)->m_act) == 0) \ 			(ifq)->ifq_tail = 0; \ 		(m)->m_act = 0; \ 		(ifq)->ifq_len--; \ 	} \ }
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

begin_struct
struct|struct
name|ifaddr
block|{
name|struct
name|sockaddr
name|ifa_addr
decl_stmt|;
comment|/* address of interface */
union|union
block|{
name|struct
name|sockaddr
name|ifu_broadaddr
decl_stmt|;
name|struct
name|sockaddr
name|ifu_dstaddr
decl_stmt|;
block|}
name|ifa_ifu
union|;
define|#
directive|define
name|ifa_broadaddr
value|ifa_ifu.ifu_broadaddr
comment|/* broadcast address */
define|#
directive|define
name|ifa_dstaddr
value|ifa_ifu.ifu_dstaddr
comment|/* other end of p-to-p link */
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
block|}
struct|;
end_struct

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
name|short
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
name|struct
name|ifqueue
name|rawintrq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* raw packet input queue */
end_comment

begin_decl_stmt
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

begin_else
else|#
directive|else
else|KERNEL
end_else

begin_include
include|#
directive|include
file|<net/if_arp.h>
end_include

begin_endif
endif|#
directive|endif
endif|KERNEL
end_endif

end_unit

