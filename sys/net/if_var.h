begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	From: @(#)if.h	8.1 (Berkeley) 6/10/93  *	$Id: if_var.h,v 1.10 1998/12/16 18:30:43 phk Exp $  */
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
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rtentry
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
name|LIST_HEAD
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
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure defining a network interface.  *  * (Would like to call this struct ``if'', but C isn't PL/1.)  */
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
name|void
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
name|u_long
operator|,
name|caddr_t
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*if_watchdog
argument_list|)
comment|/* timer routine */
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
argument|*if_poll_recv
argument_list|)
comment|/* polled receive routine */
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*if_poll_xmit
argument_list|)
comment|/* polled transmit routine */
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*if_poll_intren
argument_list|)
comment|/* polled interrupt reenable routine */
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*if_poll_slowinput
argument_list|)
comment|/* input routine for slow devices */
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
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*if_init
argument_list|)
comment|/* Init routine */
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*if_resolvemulti
argument_list|)
comment|/* validate/resolve multicast */
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|)
argument_list|)
expr_stmt|;
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
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|void
name|if_init_f_t
name|__P
typedef|((
name|void
modifier|*
typedef|));
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|IF_ENQ_DROP
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
value|if_enq_drop(ifq, m)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|MT_HEADER
argument_list|)
end_if

begin_function
specifier|static
name|__inline
name|int
name|if_queue_drop
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
parameter_list|)
block|{
name|IF_DROP
argument_list|(
name|ifq
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|if_enq_drop
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
parameter_list|)
block|{
if|if
condition|(
name|IF_QFULL
argument_list|(
name|ifq
argument_list|)
operator|&&
operator|!
name|if_queue_drop
argument_list|(
name|ifq
argument_list|,
name|m
argument_list|)
condition|)
return|return
literal|0
return|;
name|IF_ENQUEUE
argument_list|(
name|ifq
argument_list|,
name|m
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|MT_HEADER
end_ifdef

begin_decl_stmt
name|int
name|if_enq_drop
name|__P
argument_list|(
operator|(
expr|struct
name|ifqueue
operator|*
operator|,
expr|struct
name|mbuf
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
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
name|TAILQ_ENTRY
argument_list|(
argument|ifaddr
argument_list|)
name|ifa_link
expr_stmt|;
comment|/* queue macro glue */
name|void
argument_list|(
argument|*ifa_rtrequest
argument_list|)
comment|/* check or clean routes (+ or -)'d */
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|rtentry
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|)
argument_list|)
expr_stmt|;
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
argument_list|(
argument|*ifa_claim_addr
argument_list|)
comment|/* check if an addr goes to this if */
name|__P
argument_list|(
operator|(
expr|struct
name|ifaddr
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|)
argument_list|)
expr_stmt|;
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
comment|/*  * Multicast address structure.  This is analogous to the ifaddr  * structure except that it keeps track of multicast addresses.  * Also, the reference count here is a count of requests for this  * address, not a count of pointers to this structure.  */
end_comment

begin_struct
struct|struct
name|ifmultiaddr
block|{
name|LIST_ENTRY
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

begin_decl_stmt
specifier|extern
name|struct
name|ifnethead
name|ifnet
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
name|loif
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|if_index
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ifaddr
modifier|*
modifier|*
name|ifnet_addrs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ether_ifattach
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

begin_decl_stmt
name|void
name|ether_input
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
expr|struct
name|ether_header
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ether_output
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
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ether_ioctl
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
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|if_addmulti
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
expr|struct
name|ifmultiaddr
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|if_allmulti
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
name|int
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

begin_decl_stmt
name|int
name|if_delmulti
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|if_down
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

begin_decl_stmt
name|void
name|if_route
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
name|int
name|flag
operator|,
name|int
name|fam
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|if_unroute
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
name|int
name|flag
operator|,
name|int
name|fam
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|if_up
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

begin_comment
comment|/*void	ifinit __P((void));*/
end_comment

begin_comment
comment|/* declared in systm.h for main() */
end_comment

begin_decl_stmt
name|int
name|ifioctl
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
operator|,
name|u_long
operator|,
name|caddr_t
operator|,
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ifpromisc
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ifnet
modifier|*
name|ifunit
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|if_poll_recv_slow
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
name|ifp
operator|,
name|int
operator|*
name|quotap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|if_poll_xmit_slow
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
name|ifp
operator|,
name|int
operator|*
name|quotap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|if_poll_throttle
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|if_poll_unthrottle
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|if_poll_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|if_poll
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
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
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ifaddr
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
name|struct
name|ifaddr
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
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ifaddr
modifier|*
name|ifa_ifwithroute
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ifaddr
modifier|*
name|ifaof_ifpforaddr
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr
operator|*
operator|,
expr|struct
name|ifnet
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
name|struct
name|ifmultiaddr
modifier|*
name|ifmaof_ifpforaddr
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr
operator|*
operator|,
expr|struct
name|ifnet
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|if_simloop
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
name|ifp
operator|,
expr|struct
name|mbuf
operator|*
name|m
operator|,
expr|struct
name|sockaddr
operator|*
name|dst
operator|,
name|int
name|hlen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
comment|/* !_NET_IF_VAR_H_ */
end_comment

end_unit

