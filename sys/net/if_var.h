begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	From: @(#)if.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_IF_VAR_H_
end_define

begin_comment
comment|/*  * Structures defining a network interface, providing a packet  * transport mechanism (ala level 0 of the PUP protocols).  *  * Each interface accepts output datagrams of a specified maximum  * length, and provides higher level routines with input datagrams  * received from its medium.  *  * Output occurs when the routine if_output is called, with three parameters:  *	(*ifp->if_output)(ifp, m, dst, rt)  * Here m is the mbuf chain to be sent and dst is the destination address.  * The output routine encapsulates the supplied datagram if necessary,  * and then transmits it on its medium.  *  * On input, each interface unwraps the data received by it, and either  * places it on the input queue of a internetwork datagram routine  * and posts the associated software interrupt, or passes the datagram to a raw  * packet input routine.  *  * Routines exist for locating interfaces by their addresses  * or for locating a interface on a certain network, as well as more general  * routing and gateway routines maintaining information used to locate  * interfaces.  These routines live in the files if.c and route.c  */
end_comment

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
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rtentry
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rt_addrinfo
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|socket
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ether_header
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/* get TAILQ macros */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_include
include|#
directive|include
file|<sys/event.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|ifnethead
argument_list|,
name|ifnet
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* we use TAILQs so that the order of */
end_comment

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|ifaddrhead
argument_list|,
name|ifaddr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* instantiation is preserved in the list */
end_comment

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|ifprefixhead
argument_list|,
name|ifprefix
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|ifmultihead
argument_list|,
name|ifmultiaddr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Structure defining a queue for a network interface.  */
end_comment

begin_struct
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
name|struct
name|mtx
name|ifq_mtx
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure defining a network interface.  *  * (Would like to call this struct ``if'', but C isn't PL/1.)  */
end_comment

begin_comment
comment|/*  * NB: For FreeBSD, it is assumed that each NIC driver's softc starts with  * one of these structures, typically held within an arpcom structure.  *  *	struct<foo>_softc {  *		struct arpcom {  *			struct  ifnet ac_if;  *			...  *		}<arpcom> ;  *		...  *	};  *  * The assumption is used in a number of places, including many  * files in sys/net, device drivers, and sys/dev/mii.c:miibus_attach().  *  * Unfortunately devices' softc are opaque, so we depend on this layout  * to locate the struct ifnet from the softc in the generic code.  *   */
end_comment

begin_struct
struct|struct
name|ifnet
block|{
name|void
modifier|*
name|if_softc
decl_stmt|;
comment|/* pointer to driver state */
name|char
modifier|*
name|if_name
decl_stmt|;
comment|/* name, e.g. ``en'' or ``lo'' */
name|TAILQ_ENTRY
argument_list|(
argument|ifnet
argument_list|)
name|if_link
expr_stmt|;
comment|/* all struct ifnets are chained */
name|struct
name|ifaddrhead
name|if_addrhead
decl_stmt|;
comment|/* linked list of addresses per if */
name|struct
name|klist
name|if_klist
decl_stmt|;
comment|/* events attached to this if */
name|int
name|if_pcount
decl_stmt|;
comment|/* number of promiscuous listeners */
name|struct
name|bpf_if
modifier|*
name|if_bpf
decl_stmt|;
comment|/* packet filter structure */
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
name|int
name|if_capabilities
decl_stmt|;
comment|/* interface capabilities */
name|int
name|if_capenable
decl_stmt|;
comment|/* enabled features */
name|int
name|if_ipending
decl_stmt|;
comment|/* interrupts pending */
name|void
modifier|*
name|if_linkmib
decl_stmt|;
comment|/* link-type-specific MIB data */
name|size_t
name|if_linkmiblen
decl_stmt|;
comment|/* length of above data */
name|struct
name|if_data
name|if_data
decl_stmt|;
name|struct
name|ifmultihead
name|if_multiaddrs
decl_stmt|;
comment|/* multicast addresses configured */
name|int
name|if_amcount
decl_stmt|;
comment|/* number of all-multicast requests */
comment|/* procedure handles */
name|int
function_decl|(
modifier|*
name|if_output
function_decl|)
comment|/* output routine (enqueue) */
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
name|void
function_decl|(
modifier|*
name|if_start
function_decl|)
comment|/* initiate output routine */
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|if_done
function_decl|)
comment|/* output complete routine */
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
comment|/* (XXX not used; fake prototype) */
name|int
function_decl|(
modifier|*
name|if_ioctl
function_decl|)
comment|/* ioctl routine */
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|if_watchdog
function_decl|)
comment|/* timer routine */
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|if_poll_recv
function_decl|)
comment|/* polled receive routine */
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|if_poll_xmit
function_decl|)
comment|/* polled transmit routine */
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|if_poll_intren
function_decl|)
comment|/* polled interrupt reenable routine */
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|if_poll_slowinput
function_decl|)
comment|/* input routine for slow devices */
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|if_init
function_decl|)
comment|/* Init routine */
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|if_resolvemulti
function_decl|)
comment|/* validate/resolve multicast */
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
name|struct
name|ifqueue
name|if_snd
decl_stmt|;
comment|/* output queue */
name|struct
name|ifqueue
modifier|*
name|if_poll_slowq
decl_stmt|;
comment|/* input queue for slow devices */
name|struct
name|ifprefixhead
name|if_prefixhead
decl_stmt|;
comment|/* list of prefixes per if */
name|u_int8_t
modifier|*
name|if_broadcastaddr
decl_stmt|;
comment|/* linklevel broadcast bytestring */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|void
name|if_init_f_t
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

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
name|if_physical
value|if_data.ifi_physical
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
name|if_hwassist
value|if_data.ifi_hwassist
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
name|if_recvquota
value|if_data.ifi_recvquota
end_define

begin_define
define|#
directive|define
name|if_xmitquota
value|if_data.ifi_xmitquota
end_define

begin_define
define|#
directive|define
name|if_rawoutput
parameter_list|(
define|if, m, sa) if_output(if, m, sa, (struct rtentry *)0)
end_define

begin_comment
comment|/* for compatibility with other BSDs */
end_comment

begin_define
define|#
directive|define
name|if_addrlist
value|if_addrhead
end_define

begin_define
define|#
directive|define
name|if_list
value|if_link
end_define

begin_comment
comment|/*  * Bit values in if_ipending  */
end_comment

begin_define
define|#
directive|define
name|IFI_RECV
value|1
end_define

begin_comment
comment|/* I want to receive */
end_comment

begin_define
define|#
directive|define
name|IFI_XMIT
value|2
end_define

begin_comment
comment|/* I want to transmit */
end_comment

begin_comment
comment|/*  * Output queues (ifp->if_snd) and slow device input queues (*ifp->if_slowq)  * are queues of messages stored on ifqueue structures  * (defined above).  Entries are added to and deleted from these structures  * by these macros, which should be called with ipl raised to splimp().  */
end_comment

begin_define
define|#
directive|define
name|IF_LOCK
parameter_list|(
name|ifq
parameter_list|)
value|mtx_lock(&(ifq)->ifq_mtx)
end_define

begin_define
define|#
directive|define
name|IF_UNLOCK
parameter_list|(
name|ifq
parameter_list|)
value|mtx_unlock(&(ifq)->ifq_mtx)
end_define

begin_define
define|#
directive|define
name|_IF_QFULL
parameter_list|(
name|ifq
parameter_list|)
value|((ifq)->ifq_len>= (ifq)->ifq_maxlen)
end_define

begin_define
define|#
directive|define
name|_IF_DROP
parameter_list|(
name|ifq
parameter_list|)
value|((ifq)->ifq_drops++)
end_define

begin_define
define|#
directive|define
name|_IF_QLEN
parameter_list|(
name|ifq
parameter_list|)
value|((ifq)->ifq_len)
end_define

begin_define
define|#
directive|define
name|_IF_ENQUEUE
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
value|do { 				\ 	(m)->m_nextpkt = NULL;					\ 	if ((ifq)->ifq_tail == NULL) 				\ 		(ifq)->ifq_head = m; 				\ 	else 							\ 		(ifq)->ifq_tail->m_nextpkt = m; 		\ 	(ifq)->ifq_tail = m; 					\ 	(ifq)->ifq_len++; 					\ } while (0)
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
value|do {					\ 	IF_LOCK(ifq); 						\ 	_IF_ENQUEUE(ifq, m); 					\ 	IF_UNLOCK(ifq); 					\ } while (0)
end_define

begin_define
define|#
directive|define
name|_IF_PREPEND
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
value|do {				\ 	(m)->m_nextpkt = (ifq)->ifq_head; 			\ 	if ((ifq)->ifq_tail == NULL) 				\ 		(ifq)->ifq_tail = (m); 				\ 	(ifq)->ifq_head = (m); 					\ 	(ifq)->ifq_len++; 					\ } while (0)
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
value|do {		 			\ 	IF_LOCK(ifq); 						\ 	_IF_PREPEND(ifq, m); 					\ 	IF_UNLOCK(ifq); 					\ } while (0)
end_define

begin_define
define|#
directive|define
name|_IF_DEQUEUE
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
value|do { 				\ 	(m) = (ifq)->ifq_head; 					\ 	if (m) { 						\ 		if (((ifq)->ifq_head = (m)->m_nextpkt) == 0) 	\ 			(ifq)->ifq_tail = NULL; 		\ 		(m)->m_nextpkt = NULL; 				\ 		(ifq)->ifq_len--; 				\ 	} 							\ } while (0)
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
value|do { 				\ 	IF_LOCK(ifq); 						\ 	_IF_DEQUEUE(ifq, m); 					\ 	IF_UNLOCK(ifq); 					\ } while (0)
end_define

begin_define
define|#
directive|define
name|IF_DRAIN
parameter_list|(
name|ifq
parameter_list|)
value|do { 					\ 	struct mbuf *m; 					\ 	IF_LOCK(ifq); 						\ 	for (;;) { 						\ 		_IF_DEQUEUE(ifq, m); 				\ 		if (m == NULL) 					\ 			break; 					\ 		m_freem(m); 					\ 	} 							\ 	IF_UNLOCK(ifq); 					\ } while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|IF_HANDOFF
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|,
name|ifp
parameter_list|)
value|if_handoff(ifq, m, ifp, 0)
end_define

begin_define
define|#
directive|define
name|IF_HANDOFF_ADJ
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|,
name|ifp
parameter_list|,
name|adj
parameter_list|)
value|if_handoff(ifq, m, ifp, adj)
end_define

begin_function
specifier|static
name|__inline
name|int
name|if_handoff
parameter_list|(
name|struct
name|ifqueue
modifier|*
name|ifq
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|int
name|adjust
parameter_list|)
block|{
name|int
name|active
init|=
literal|0
decl_stmt|;
name|IF_LOCK
argument_list|(
name|ifq
argument_list|)
expr_stmt|;
if|if
condition|(
name|_IF_QFULL
argument_list|(
name|ifq
argument_list|)
condition|)
block|{
name|_IF_DROP
argument_list|(
name|ifq
argument_list|)
expr_stmt|;
name|IF_UNLOCK
argument_list|(
name|ifq
argument_list|)
expr_stmt|;
name|m_freem
argument_list|(
name|m
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
if|if
condition|(
name|ifp
operator|!=
name|NULL
condition|)
block|{
name|ifp
operator|->
name|if_obytes
operator|+=
name|m
operator|->
name|m_pkthdr
operator|.
name|len
operator|+
name|adjust
expr_stmt|;
if|if
condition|(
name|m
operator|->
name|m_flags
operator|&
name|M_MCAST
condition|)
name|ifp
operator|->
name|if_omcasts
operator|++
expr_stmt|;
name|active
operator|=
name|ifp
operator|->
name|if_flags
operator|&
name|IFF_OACTIVE
expr_stmt|;
block|}
name|_IF_ENQUEUE
argument_list|(
name|ifq
argument_list|,
name|m
argument_list|)
expr_stmt|;
name|IF_UNLOCK
argument_list|(
name|ifq
argument_list|)
expr_stmt|;
if|if
condition|(
name|ifp
operator|!=
name|NULL
operator|&&
operator|!
name|active
condition|)
call|(
modifier|*
name|ifp
operator|->
name|if_start
call|)
argument_list|(
name|ifp
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * 72 was chosen below because it is the size of a TCP/IP  * header (40) + the minimum mss (32).  */
end_comment

begin_define
define|#
directive|define
name|IF_MINMTU
value|72
end_define

begin_define
define|#
directive|define
name|IF_MAXMTU
value|65535
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
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
name|if_data
name|if_data
decl_stmt|;
comment|/* not all members are meaningful */
name|struct
name|ifnet
modifier|*
name|ifa_ifp
decl_stmt|;
comment|/* back-pointer to interface */
name|TAILQ_ENTRY
argument_list|(
argument|ifaddr
argument_list|)
name|ifa_link
expr_stmt|;
comment|/* queue macro glue */
name|void
function_decl|(
modifier|*
name|ifa_rtrequest
function_decl|)
comment|/* check or clean routes (+ or -)'d */
parameter_list|(
name|int
parameter_list|,
name|struct
name|rtentry
modifier|*
parameter_list|,
name|struct
name|rt_addrinfo
modifier|*
parameter_list|)
function_decl|;
name|u_short
name|ifa_flags
decl_stmt|;
comment|/* mostly rt_flags for cloning */
name|u_int
name|ifa_refcnt
decl_stmt|;
comment|/* references to this structure */
name|int
name|ifa_metric
decl_stmt|;
comment|/* cost of going out this interface */
ifdef|#
directive|ifdef
name|notdef
name|struct
name|rtentry
modifier|*
name|ifa_rt
decl_stmt|;
comment|/* XXXX for ROUTETOIF ????? */
endif|#
directive|endif
name|int
function_decl|(
modifier|*
name|ifa_claim_addr
function_decl|)
comment|/* check if an addr goes to this if */
parameter_list|(
name|struct
name|ifaddr
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
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
comment|/* for compatibility with other BSDs */
end_comment

begin_define
define|#
directive|define
name|ifa_list
value|ifa_link
end_define

begin_comment
comment|/*  * The prefix structure contains information about one prefix  * of an interface.  They are maintained by the different address families,  * are allocated and attached when an prefix or an address is set,  * and are linked together so all prefixes for an interface can be located.  */
end_comment

begin_struct
struct|struct
name|ifprefix
block|{
name|struct
name|sockaddr
modifier|*
name|ifpr_prefix
decl_stmt|;
comment|/* prefix of interface */
name|struct
name|ifnet
modifier|*
name|ifpr_ifp
decl_stmt|;
comment|/* back-pointer to interface */
name|TAILQ_ENTRY
argument_list|(
argument|ifprefix
argument_list|)
name|ifpr_list
expr_stmt|;
comment|/* queue macro glue */
name|u_char
name|ifpr_plen
decl_stmt|;
comment|/* prefix length in bits */
name|u_char
name|ifpr_type
decl_stmt|;
comment|/* protocol dependent prefix type */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Multicast address structure.  This is analogous to the ifaddr  * structure except that it keeps track of multicast addresses.  * Also, the reference count here is a count of requests for this  * address, not a count of pointers to this structure.  */
end_comment

begin_struct
struct|struct
name|ifmultiaddr
block|{
name|TAILQ_ENTRY
argument_list|(
argument|ifmultiaddr
argument_list|)
name|ifma_link
expr_stmt|;
comment|/* queue macro glue */
name|struct
name|sockaddr
modifier|*
name|ifma_addr
decl_stmt|;
comment|/* address this membership is for */
name|struct
name|sockaddr
modifier|*
name|ifma_lladdr
decl_stmt|;
comment|/* link-layer translation, if any */
name|struct
name|ifnet
modifier|*
name|ifma_ifp
decl_stmt|;
comment|/* back-pointer to interface */
name|u_int
name|ifma_refcount
decl_stmt|;
comment|/* reference count */
name|void
modifier|*
name|ifma_protospec
decl_stmt|;
comment|/* protocol-specific state, if any */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|IFAFREE
parameter_list|(
name|ifa
parameter_list|)
define|\
value|do { \ 		if ((ifa)->ifa_refcnt<= 0) \ 			ifafree(ifa); \ 		else \ 			(ifa)->ifa_refcnt--; \ 	} while (0)
end_define

begin_struct
struct|struct
name|ifindex_entry
block|{
name|struct
name|ifnet
modifier|*
name|ife_ifnet
decl_stmt|;
name|struct
name|ifaddr
modifier|*
name|ife_ifnet_addr
decl_stmt|;
name|dev_t
name|ife_dev
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ifnet_byindex
parameter_list|(
name|idx
parameter_list|)
value|ifindex_table[(idx)].ife_ifnet
end_define

begin_define
define|#
directive|define
name|ifaddr_byindex
parameter_list|(
name|idx
parameter_list|)
value|ifindex_table[(idx)].ife_ifnet_addr
end_define

begin_define
define|#
directive|define
name|ifdev_byindex
parameter_list|(
name|idx
parameter_list|)
value|ifindex_table[(idx)].ife_dev
end_define

begin_decl_stmt
specifier|extern
name|struct
name|ifnethead
name|ifnet
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ifindex_entry
modifier|*
name|ifindex_table
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ifqmaxlen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ifnet
modifier|*
name|loif
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* first loopback interface */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|if_index
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|ether_ifattach
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ether_ifdetach
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|void
name|ether_demux
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
name|int
name|ether_output
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

begin_function_decl
name|int
name|ether_output_frame
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ether_ioctl
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
end_function_decl

begin_function_decl
name|int
name|if_addmulti
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|ifmultiaddr
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_allmulti
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_attach
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_delmulti
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_detach
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_down
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_route
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
name|flag
parameter_list|,
name|int
name|fam
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_setlladdr
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_unroute
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
name|flag
parameter_list|,
name|int
name|fam
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_up
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*void	ifinit(void);*/
end_comment

begin_comment
comment|/* declared in systm.h for main() */
end_comment

begin_function_decl
name|int
name|ifioctl
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|caddr_t
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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

begin_function_decl
name|struct
name|ifnet
modifier|*
name|ifunit
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ifnet
modifier|*
name|if_withname
parameter_list|(
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_poll_recv_slow
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|int
modifier|*
name|quotap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_poll_xmit_slow
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|int
modifier|*
name|quotap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_poll_throttle
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_poll_unthrottle
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_poll_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_poll
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ifaddr
modifier|*
name|ifa_ifwithaddr
parameter_list|(
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ifaddr
modifier|*
name|ifa_ifwithdstaddr
parameter_list|(
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ifaddr
modifier|*
name|ifa_ifwithnet
parameter_list|(
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ifaddr
modifier|*
name|ifa_ifwithroute
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ifaddr
modifier|*
name|ifaof_ifpforaddr
parameter_list|(
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ifafree
parameter_list|(
name|struct
name|ifaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ifmultiaddr
modifier|*
name|ifmaof_ifpforaddr
parameter_list|(
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_simloop
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|af
parameter_list|,
name|int
name|hlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_clone_attach
parameter_list|(
name|struct
name|if_clone
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_clone_detach
parameter_list|(
name|struct
name|if_clone
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_clone_create
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_clone_destroy
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|IF_LLADDR
parameter_list|(
name|ifp
parameter_list|)
define|\
value|LLADDR((struct sockaddr_dl *) ifaddr_byindex((ifp)->if_index)->ifa_addr)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEVICE_POLLING
end_ifdef

begin_enum
enum|enum
name|poll_cmd
block|{
name|POLL_ONLY
block|,
name|POLL_AND_CHECK_STATUS
block|,
name|POLL_DEREGISTER
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|void
name|poll_handler_t
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|enum
name|poll_cmd
name|cmd
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|int
name|ether_poll_register
parameter_list|(
name|poll_handler_t
modifier|*
name|h
parameter_list|,
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ether_poll_deregister
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEVICE_POLLING */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NET_IF_VAR_H_ */
end_comment

end_unit

