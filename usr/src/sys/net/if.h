begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)if.h	7.17 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Structures defining a network interface, providing a packet  * transport mechanism (ala level 0 of the PUP protocols).  *  * Each interface accepts output datagrams of a specified maximum  * length, and provides higher level routines with input datagrams  * received from its medium.  *  * Output occurs when the routine if_output is called, with three parameters:  *	(*ifp->if_output)(ifp, m, dst, rt)  * Here m is the mbuf chain to be sent and dst is the destination address.  * The output routine encapsulates the supplied datagram if necessary,  * and then transmits it on its medium.  *  * On input, each interface unwraps the data received by it, and either  * places it on the input queue of a internetwork datagram routine  * and posts the associated software interrupt, or passes the datagram to a raw  * packet input routine.  *  * Routines exist for locating interfaces by their addresses  * or for locating a interface on a certain network, as well as more general  * routing and gateway routines maintaining information used to locate  * interfaces.  These routines live in the files if.c and route.c  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_comment
comment|/*  * Forward structure declarations for function prototypes [sic].  */
end_comment

begin_struct_decl
struct_decl|struct
name|rtentry
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Structure describing information about an interface  * which may be of interest to management entities.  */
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
name|struct
name|ifnet
modifier|*
name|if_next
decl_stmt|;
comment|/* all struct ifnets are chained */
name|struct
name|ifaddr
modifier|*
name|if_addrlist
decl_stmt|;
comment|/* linked list of addresses per if */
name|int
name|if_pcount
decl_stmt|;
comment|/* number of promiscuous listeners */
name|u_short
name|if_index
decl_stmt|;
comment|/* numeric abbreviation for this if  */
name|short
name|if_unit
decl_stmt|;
comment|/* sub-unit for lower level driver */
name|short
name|if_timer
decl_stmt|;
comment|/* time 'til if_watchdog called */
name|short
name|if_flags
decl_stmt|;
comment|/* up/down, broadcast, etc. */
struct|struct
name|if_data
block|{
comment|/* generic interface information */
name|short
name|ifi_mtu
decl_stmt|;
comment|/* maximum transmission unit */
name|u_char
name|ifi_type
decl_stmt|;
comment|/* ethernet, tokenring, etc */
name|u_char
name|ifi_addrlen
decl_stmt|;
comment|/* media address length */
name|u_char
name|ifi_hdrlen
decl_stmt|;
comment|/* media header length */
name|int
name|ifi_metric
decl_stmt|;
comment|/* routing metric (external only) */
name|int
name|ifi_baudrate
decl_stmt|;
comment|/* linespeed */
comment|/* volatile statistics */
name|int
name|ifi_ipackets
decl_stmt|;
comment|/* packets received on interface */
name|int
name|ifi_ierrors
decl_stmt|;
comment|/* input errors on interface */
name|int
name|ifi_opackets
decl_stmt|;
comment|/* packets sent on interface */
name|int
name|ifi_oerrors
decl_stmt|;
comment|/* output errors on interface */
name|int
name|ifi_collisions
decl_stmt|;
comment|/* collisions on csma interfaces */
name|int
name|ifi_ibytes
decl_stmt|;
comment|/* total number of octets received */
name|int
name|ifi_obytes
decl_stmt|;
comment|/* total number of octets sent */
name|int
name|ifi_imcasts
decl_stmt|;
comment|/* packets received via multicast */
name|int
name|ifi_omcasts
decl_stmt|;
comment|/* packets sent via multicast */
name|int
name|ifi_iqdrops
decl_stmt|;
comment|/* dropped on input, this interface */
name|int
name|ifi_noproto
decl_stmt|;
comment|/* destined for unsupported protocol */
name|struct
name|timeval
name|ifi_lastchange
decl_stmt|;
comment|/* last updated */
block|}
name|if_data
struct|;
comment|/* procedure handles */
name|int
argument_list|(
argument|*if_init
argument_list|)
comment|/* init routine */
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*if_output
argument_list|)
comment|/* output routine (enqueue) */
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
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
expr|struct
name|rtentry
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*if_start
argument_list|)
comment|/* initiate output routine */
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*if_done
argument_list|)
comment|/* output complete routine */
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* (XXX not used; fake prototype) */
name|int
argument_list|(
argument|*if_ioctl
argument_list|)
comment|/* ioctl routine */
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
name|int
operator|,
name|caddr_t
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*if_reset
argument_list|)
comment|/* XXX; Unibus reset routine for vax */
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* new autoconfig will permit removal */
name|int
argument_list|(
argument|*if_watchdog
argument_list|)
comment|/* timer routine */
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
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
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|if_mtu
value|if_data.ifi_mtu
end_define

begin_define
define|#
directive|define
name|if_type
value|if_data.ifi_type
end_define

begin_define
define|#
directive|define
name|if_addrlen
value|if_data.ifi_addrlen
end_define

begin_define
define|#
directive|define
name|if_hdrlen
value|if_data.ifi_hdrlen
end_define

begin_define
define|#
directive|define
name|if_metric
value|if_data.ifi_metric
end_define

begin_define
define|#
directive|define
name|if_baudrate
value|if_data.ifi_baudrate
end_define

begin_define
define|#
directive|define
name|if_ipackets
value|if_data.ifi_ipackets
end_define

begin_define
define|#
directive|define
name|if_ierrors
value|if_data.ifi_ierrors
end_define

begin_define
define|#
directive|define
name|if_opackets
value|if_data.ifi_opackets
end_define

begin_define
define|#
directive|define
name|if_oerrors
value|if_data.ifi_oerrors
end_define

begin_define
define|#
directive|define
name|if_collisions
value|if_data.ifi_collisions
end_define

begin_define
define|#
directive|define
name|if_ibytes
value|if_data.ifi_ibytes
end_define

begin_define
define|#
directive|define
name|if_obytes
value|if_data.ifi_obytes
end_define

begin_define
define|#
directive|define
name|if_imcasts
value|if_data.ifi_imcasts
end_define

begin_define
define|#
directive|define
name|if_omcasts
value|if_data.ifi_omcasts
end_define

begin_define
define|#
directive|define
name|if_iqdrops
value|if_data.ifi_iqdrops
end_define

begin_define
define|#
directive|define
name|if_noproto
value|if_data.ifi_noproto
end_define

begin_define
define|#
directive|define
name|if_lastchange
value|if_data.ifi_lastchange
end_define

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
name|IFF_LINK0
value|0x1000
end_define

begin_comment
comment|/* per link layer defined bit */
end_comment

begin_define
define|#
directive|define
name|IFF_LINK1
value|0x2000
end_define

begin_comment
comment|/* per link layer defined bit */
end_comment

begin_define
define|#
directive|define
name|IFF_LINK2
value|0x4000
end_define

begin_comment
comment|/* per link layer defined bit */
end_comment

begin_comment
comment|/* flags set internally only: */
end_comment

begin_define
define|#
directive|define
name|IFF_CANTCHANGE
define|\
value|(IFF_BROADCAST|IFF_POINTOPOINT|IFF_RUNNING|IFF_OACTIVE|IFF_SIMPLEX)
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
name|int
function_decl|(
modifier|*
name|ifa_rtrequest
function_decl|)
parameter_list|()
function_decl|;
comment|/* check or clean routes (+ or -)'d */
name|u_short
name|ifa_flags
decl_stmt|;
comment|/* mostly rt_flags for cloning */
name|short
name|ifa_refcnt
decl_stmt|;
comment|/* extra to malloc for link info */
name|int
name|ifa_metric
decl_stmt|;
comment|/* cost of going out this interface */
comment|/*	struct	rtentry *ifa_rt;	/* XXXX for ROUTETOIF ????? */
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
comment|/*  * Message format for use in obtaining information about interfaces  * from getkerninfo and the routing socket  */
end_comment

begin_struct
struct|struct
name|if_msghdr
block|{
name|u_short
name|ifm_msglen
decl_stmt|;
comment|/* to skip over non-understood messages */
name|u_char
name|ifm_version
decl_stmt|;
comment|/* future binary compatability */
name|u_char
name|ifm_type
decl_stmt|;
comment|/* message type */
name|int
name|ifm_addrs
decl_stmt|;
comment|/* like rtm_addrs */
name|int
name|ifm_flags
decl_stmt|;
comment|/* value of if_flags */
name|u_short
name|ifm_index
decl_stmt|;
comment|/* index for associated ifp */
name|struct
name|if_data
name|ifm_data
decl_stmt|;
comment|/* statistics and other data about if */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Message format for use in obtaining information about interface addresses  * from getkerninfo and the routing socket  */
end_comment

begin_struct
struct|struct
name|ifa_msghdr
block|{
name|u_short
name|ifam_msglen
decl_stmt|;
comment|/* to skip over non-understood messages */
name|u_char
name|ifam_version
decl_stmt|;
comment|/* future binary compatability */
name|u_char
name|ifam_type
decl_stmt|;
comment|/* message type */
name|int
name|ifam_addrs
decl_stmt|;
comment|/* like rtm_addrs */
name|int
name|ifam_flags
decl_stmt|;
comment|/* value of ifa_flags */
name|u_short
name|ifam_index
decl_stmt|;
comment|/* index for associated ifp */
name|int
name|ifam_metric
decl_stmt|;
comment|/* value of ifa_metric */
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

begin_define
define|#
directive|define
name|IFAFREE
parameter_list|(
name|ifa
parameter_list|)
define|\
value|if ((ifa)->ifa_refcnt<= 0) \ 		ifafree(ifa); \ 	else \ 		(ifa)->ifa_refcnt--;
end_define

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
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
argument_list|)
decl_stmt|,
modifier|*
name|ifa_ifwithnet
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
argument_list|)
decl_stmt|,
modifier|*
name|ifa_ifwithdstaddr
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ifafree
name|__P
argument_list|(
operator|(
expr|struct
name|ifaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|if_attach
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

