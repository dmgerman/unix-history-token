begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	From: @(#)if.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
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
comment|/*  * Structures defining a network interface, providing a packet  * transport mechanism (ala level 0 of the PUP protocols).  *  * Each interface accepts output datagrams of a specified maximum  * length, and provides higher level routines with input datagrams  * received from its medium.  *  * Output occurs when the routine if_output is called, with three parameters:  *	(*ifp->if_output)(ifp, m, dst, rt)  * Here m is the mbuf chain to be sent and dst is the destination address.  * The output routine encapsulates the supplied datagram if necessary,  * and then transmits it on its medium.  *  * On input, each interface unwraps the data received by it, and either  * places it on the input queue of an internetwork datagram routine  * and posts the associated software interrupt, or passes the datagram to a raw  * packet input routine.  *  * Routines exist for locating interfaces by their addresses  * or for locating an interface on a certain network, as well as more general  * routing and gateway routines maintaining information used to locate  * interfaces.  These routines live in the files if.c and route.c  */
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

begin_struct_decl
struct_decl|struct
name|carp_if
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ifvlantrunk
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
file|<sys/eventhandler.h>
end_include

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

begin_include
include|#
directive|include
file|<sys/_task.h>
end_include

begin_define
define|#
directive|define
name|IF_DUNIT_NONE
value|-1
end_define

begin_include
include|#
directive|include
file|<altq/if_altq.h>
end_include

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

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|ifgrouphead
argument_list|,
name|ifg_group
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

begin_struct
struct|struct
name|ifnet
block|{
name|void
modifier|*
name|if_softc
decl_stmt|;
comment|/* pointer to driver state */
name|void
modifier|*
name|if_l2com
decl_stmt|;
comment|/* pointer to protocol bits */
name|TAILQ_ENTRY
argument_list|(
argument|ifnet
argument_list|)
name|if_link
expr_stmt|;
comment|/* all struct ifnets are chained */
name|char
name|if_xname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* external name (name + unit) */
specifier|const
name|char
modifier|*
name|if_dname
decl_stmt|;
comment|/* driver name */
name|int
name|if_dunit
decl_stmt|;
comment|/* unit or IF_DUNIT_NONE */
name|struct
name|ifaddrhead
name|if_addrhead
decl_stmt|;
comment|/* linked list of addresses per if */
comment|/* 		 * if_addrhead is the list of all addresses associated to 		 * an interface. 		 * Some code in the kernel assumes that first element 		 * of the list has type AF_LINK, and contains sockaddr_dl 		 * addresses which store the link-level address and the name 		 * of the interface. 		 * However, access to the AF_LINK address through this 		 * field is deprecated. Use if_addr or ifaddr_byindex() instead. 		 */
name|struct
name|knlist
name|if_klist
decl_stmt|;
comment|/* events attached to this if */
name|int
name|if_pcount
decl_stmt|;
comment|/* number of promiscuous listeners */
name|struct
name|carp_if
modifier|*
name|if_carp
decl_stmt|;
comment|/* carp interface structure */
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
name|if_timer
decl_stmt|;
comment|/* time 'til if_watchdog called */
name|struct
name|ifvlantrunk
modifier|*
name|if_vlantrunk
decl_stmt|;
comment|/* pointer to 802.1q data */
name|int
name|if_flags
decl_stmt|;
comment|/* up/down, broadcast, etc. */
name|int
name|if_capabilities
decl_stmt|;
comment|/* interface features& capabilities */
name|int
name|if_capenable
decl_stmt|;
comment|/* enabled features& capabilities */
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
name|if_input
function_decl|)
comment|/* input routine (from h/w driver) */
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
name|ifaddr
modifier|*
name|if_addr
decl_stmt|;
comment|/* pointer to link-level address */
name|void
modifier|*
name|if_spare2
decl_stmt|;
comment|/* spare pointer 2 */
name|void
modifier|*
name|if_spare3
decl_stmt|;
comment|/* spare pointer 3 */
name|int
name|if_drv_flags
decl_stmt|;
comment|/* driver-managed status flags */
name|u_int
name|if_spare_flags2
decl_stmt|;
comment|/* spare flags 2 */
name|struct
name|ifaltq
name|if_snd
decl_stmt|;
comment|/* output queue (includes altq) */
specifier|const
name|u_int8_t
modifier|*
name|if_broadcastaddr
decl_stmt|;
comment|/* linklevel broadcast bytestring */
name|void
modifier|*
name|if_bridge
decl_stmt|;
comment|/* bridge glue */
name|struct
name|lltable
modifier|*
name|lltables
decl_stmt|;
comment|/* list of L3-L2 resolution tables */
name|struct
name|label
modifier|*
name|if_label
decl_stmt|;
comment|/* interface MAC label */
comment|/* these are only used by IPv6 */
name|struct
name|ifprefixhead
name|if_prefixhead
decl_stmt|;
comment|/* list of prefixes per if */
name|void
modifier|*
name|if_afdata
index|[
name|AF_MAX
index|]
decl_stmt|;
name|int
name|if_afdata_initialized
decl_stmt|;
name|struct
name|mtx
name|if_afdata_mtx
decl_stmt|;
name|struct
name|task
name|if_starttask
decl_stmt|;
comment|/* task for IFF_NEEDSGIANT */
name|struct
name|task
name|if_linktask
decl_stmt|;
comment|/* task for link change events */
name|struct
name|mtx
name|if_addr_mtx
decl_stmt|;
comment|/* mutex to protect address lists */
name|LIST_ENTRY
argument_list|(
argument|ifnet
argument_list|)
name|if_clones
expr_stmt|;
comment|/* interfaces of a cloner */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ifg_list
argument_list|)
name|if_groups
expr_stmt|;
comment|/* linked list of groups per if */
comment|/* protected by if_addr_mtx */
name|void
modifier|*
name|if_pf_kif
decl_stmt|;
name|void
modifier|*
name|if_trunk
decl_stmt|;
comment|/* trunk glue */
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

begin_comment
comment|/*  * XXX These aliases are terribly dangerous because they could apply  * to anything.  */
end_comment

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
name|if_link_state
value|if_data.ifi_link_state
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
define|if, m, sa) if_output(if, m, sa, (struct rtentry *)NULL)
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

begin_define
define|#
directive|define
name|if_name
parameter_list|(
name|ifp
parameter_list|)
value|((ifp)->if_xname)
end_define

begin_comment
comment|/*  * Locks for address lists on the network interface.  */
end_comment

begin_define
define|#
directive|define
name|IF_ADDR_LOCK_INIT
parameter_list|(
define|if)	mtx_init(&(if)->if_addr_mtx,		\ 				    "if_addr_mtx", NULL, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|IF_ADDR_LOCK_DESTROY
parameter_list|(
define|if)	mtx_destroy(&(if)->if_addr_mtx)
end_define

begin_define
define|#
directive|define
name|IF_ADDR_LOCK
parameter_list|(
define|if)	mtx_lock(&(if)->if_addr_mtx)
end_define

begin_define
define|#
directive|define
name|IF_ADDR_UNLOCK
parameter_list|(
define|if)	mtx_unlock(&(if)->if_addr_mtx)
end_define

begin_define
define|#
directive|define
name|IF_ADDR_LOCK_ASSERT
parameter_list|(
define|if)	mtx_assert(&(if)->if_addr_mtx, MA_OWNED)
end_define

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
name|IF_LOCK_ASSERT
parameter_list|(
name|ifq
parameter_list|)
value|mtx_assert(&(ifq)->ifq_mtx, MA_OWNED)
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
value|do { 				\ 	(m) = (ifq)->ifq_head; 					\ 	if (m) { 						\ 		if (((ifq)->ifq_head = (m)->m_nextpkt) == NULL)	\ 			(ifq)->ifq_tail = NULL; 		\ 		(m)->m_nextpkt = NULL; 				\ 		(ifq)->ifq_len--; 				\ 	} 							\ } while (0)
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
name|_IF_POLL
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
value|((m) = (ifq)->ifq_head)
end_define

begin_define
define|#
directive|define
name|IF_POLL
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
value|_IF_POLL(ifq, m)
end_define

begin_define
define|#
directive|define
name|_IF_DRAIN
parameter_list|(
name|ifq
parameter_list|)
value|do { 					\ 	struct mbuf *m; 					\ 	for (;;) { 						\ 		_IF_DEQUEUE(ifq, m); 				\ 		if (m == NULL) 					\ 			break; 					\ 		m_freem(m); 					\ 	} 							\ } while (0)
end_define

begin_define
define|#
directive|define
name|IF_DRAIN
parameter_list|(
name|ifq
parameter_list|)
value|do {					\ 	IF_LOCK(ifq);						\ 	_IF_DRAIN(ifq);						\ 	IF_UNLOCK(ifq);						\ } while(0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* interface address change event */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ifaddr_event_handler_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|ifaddr_event
argument_list|,
name|ifaddr_event_handler_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* new interface arrival event */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ifnet_arrival_event_handler_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|ifnet_arrival_event
argument_list|,
name|ifnet_arrival_event_handler_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* interface departure event */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ifnet_departure_event_handler_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|ifnet_departure_event
argument_list|,
name|ifnet_departure_event_handler_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * interface groups  */
end_comment

begin_struct
struct|struct
name|ifg_group
block|{
name|char
name|ifg_group
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|u_int
name|ifg_refcnt
decl_stmt|;
name|void
modifier|*
name|ifg_pf_kif
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ifg_member
argument_list|)
name|ifg_members
expr_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|ifg_group
argument_list|)
name|ifg_next
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ifg_member
block|{
name|TAILQ_ENTRY
argument_list|(
argument|ifg_member
argument_list|)
name|ifgm_next
expr_stmt|;
name|struct
name|ifnet
modifier|*
name|ifgm_ifp
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ifg_list
block|{
name|struct
name|ifg_group
modifier|*
name|ifgl_group
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|ifg_list
argument_list|)
name|ifgl_next
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* group attach event */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|group_attach_event_handler_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|ifg_group
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|group_attach_event
argument_list|,
name|group_attach_event_handler_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* group detach event */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|group_detach_event_handler_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|ifg_group
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|group_detach_event
argument_list|,
name|group_detach_event_handler_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* group change event */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|group_change_event_handler_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|group_change_event
argument_list|,
name|group_change_event_handler_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|IF_AFDATA_LOCK_INIT
parameter_list|(
name|ifp
parameter_list|)
define|\
value|mtx_init(&(ifp)->if_afdata_mtx, "if_afdata", NULL, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|IF_AFDATA_LOCK
parameter_list|(
name|ifp
parameter_list|)
value|mtx_lock(&(ifp)->if_afdata_mtx)
end_define

begin_define
define|#
directive|define
name|IF_AFDATA_TRYLOCK
parameter_list|(
name|ifp
parameter_list|)
value|mtx_trylock(&(ifp)->if_afdata_mtx)
end_define

begin_define
define|#
directive|define
name|IF_AFDATA_UNLOCK
parameter_list|(
name|ifp
parameter_list|)
value|mtx_unlock(&(ifp)->if_afdata_mtx)
end_define

begin_define
define|#
directive|define
name|IF_AFDATA_DESTROY
parameter_list|(
name|ifp
parameter_list|)
value|mtx_destroy(&(ifp)->if_afdata_mtx)
end_define

begin_define
define|#
directive|define
name|IFF_LOCKGIANT
parameter_list|(
name|ifp
parameter_list|)
value|do {						\ 	if ((ifp)->if_flags& IFF_NEEDSGIANT)				\ 		mtx_lock(&Giant);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|IFF_UNLOCKGIANT
parameter_list|(
name|ifp
parameter_list|)
value|do {					\ 	if ((ifp)->if_flags& IFF_NEEDSGIANT)				\ 		mtx_unlock(&Giant);					\ } while (0)
end_define

begin_function_decl
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
function_decl|;
end_function_decl

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
define|\
value|if_handoff((struct ifqueue *)ifq, m, ifp, 0)
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
define|\
value|if_handoff((struct ifqueue *)ifq, m, ifp, adj)
end_define

begin_function_decl
name|void
name|if_start
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|IFQ_ENQUEUE
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|,
name|err
parameter_list|)
define|\
value|do {									\ 	IF_LOCK(ifq);							\ 	if (ALTQ_IS_ENABLED(ifq))					\ 		ALTQ_ENQUEUE(ifq, m, NULL, err);			\ 	else {								\ 		if (_IF_QFULL(ifq)) {					\ 			m_freem(m);					\ 			(err) = ENOBUFS;				\ 		} else {						\ 			_IF_ENQUEUE(ifq, m);				\ 			(err) = 0;					\ 		}							\ 	}								\ 	if (err)							\ 		(ifq)->ifq_drops++;					\ 	IF_UNLOCK(ifq);							\ } while (0)
end_define

begin_define
define|#
directive|define
name|IFQ_DEQUEUE_NOLOCK
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
define|\
value|do {									\ 	if (TBR_IS_ENABLED(ifq))					\ 		(m) = tbr_dequeue_ptr(ifq, ALTDQ_REMOVE);		\ 	else if (ALTQ_IS_ENABLED(ifq))					\ 		ALTQ_DEQUEUE(ifq, m);					\ 	else								\ 		_IF_DEQUEUE(ifq, m);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|IFQ_DEQUEUE
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
define|\
value|do {									\ 	IF_LOCK(ifq);							\ 	IFQ_DEQUEUE_NOLOCK(ifq, m);					\ 	IF_UNLOCK(ifq);							\ } while (0)
end_define

begin_define
define|#
directive|define
name|IFQ_POLL_NOLOCK
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
define|\
value|do {									\ 	if (TBR_IS_ENABLED(ifq))					\ 		(m) = tbr_dequeue_ptr(ifq, ALTDQ_POLL);			\ 	else if (ALTQ_IS_ENABLED(ifq))					\ 		ALTQ_POLL(ifq, m);					\ 	else								\ 		_IF_POLL(ifq, m);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|IFQ_POLL
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
define|\
value|do {									\ 	IF_LOCK(ifq);							\ 	IFQ_POLL_NOLOCK(ifq, m);					\ 	IF_UNLOCK(ifq);							\ } while (0)
end_define

begin_define
define|#
directive|define
name|IFQ_PURGE_NOLOCK
parameter_list|(
name|ifq
parameter_list|)
define|\
value|do {									\ 	if (ALTQ_IS_ENABLED(ifq)) {					\ 		ALTQ_PURGE(ifq);					\ 	} else								\ 		_IF_DRAIN(ifq);						\ } while (0)
end_define

begin_define
define|#
directive|define
name|IFQ_PURGE
parameter_list|(
name|ifq
parameter_list|)
define|\
value|do {									\ 	IF_LOCK(ifq);							\ 	IFQ_PURGE_NOLOCK(ifq);						\ 	IF_UNLOCK(ifq);							\ } while (0)
end_define

begin_define
define|#
directive|define
name|IFQ_SET_READY
parameter_list|(
name|ifq
parameter_list|)
define|\
value|do { ((ifq)->altq_flags |= ALTQF_READY); } while (0)
end_define

begin_define
define|#
directive|define
name|IFQ_LOCK
parameter_list|(
name|ifq
parameter_list|)
value|IF_LOCK(ifq)
end_define

begin_define
define|#
directive|define
name|IFQ_UNLOCK
parameter_list|(
name|ifq
parameter_list|)
value|IF_UNLOCK(ifq)
end_define

begin_define
define|#
directive|define
name|IFQ_LOCK_ASSERT
parameter_list|(
name|ifq
parameter_list|)
value|IF_LOCK_ASSERT(ifq)
end_define

begin_define
define|#
directive|define
name|IFQ_IS_EMPTY
parameter_list|(
name|ifq
parameter_list|)
value|((ifq)->ifq_len == 0)
end_define

begin_define
define|#
directive|define
name|IFQ_INC_LEN
parameter_list|(
name|ifq
parameter_list|)
value|((ifq)->ifq_len++)
end_define

begin_define
define|#
directive|define
name|IFQ_DEC_LEN
parameter_list|(
name|ifq
parameter_list|)
value|(--(ifq)->ifq_len)
end_define

begin_define
define|#
directive|define
name|IFQ_INC_DROPS
parameter_list|(
name|ifq
parameter_list|)
value|((ifq)->ifq_drops++)
end_define

begin_define
define|#
directive|define
name|IFQ_SET_MAXLEN
parameter_list|(
name|ifq
parameter_list|,
name|len
parameter_list|)
value|((ifq)->ifq_maxlen = (len))
end_define

begin_comment
comment|/*  * The IFF_DRV_OACTIVE test should really occur in the device driver, not in  * the handoff logic, as that flag is locked by the device driver.  */
end_comment

begin_define
define|#
directive|define
name|IFQ_HANDOFF_ADJ
parameter_list|(
name|ifp
parameter_list|,
name|m
parameter_list|,
name|adj
parameter_list|,
name|err
parameter_list|)
define|\
value|do {									\ 	int len;							\ 	short mflags;							\ 									\ 	len = (m)->m_pkthdr.len;					\ 	mflags = (m)->m_flags;						\ 	IFQ_ENQUEUE(&(ifp)->if_snd, m, err);				\ 	if ((err) == 0) {						\ 		(ifp)->if_obytes += len + (adj);			\ 		if (mflags& M_MCAST)					\ 			(ifp)->if_omcasts++;				\ 		if (((ifp)->if_drv_flags& IFF_DRV_OACTIVE) == 0)	\ 			if_start(ifp);					\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|IFQ_HANDOFF
parameter_list|(
name|ifp
parameter_list|,
name|m
parameter_list|,
name|err
parameter_list|)
define|\
value|IFQ_HANDOFF_ADJ(ifp, m, 0, err)
end_define

begin_define
define|#
directive|define
name|IFQ_DRV_DEQUEUE
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
define|\
value|do {									\ 	(m) = (ifq)->ifq_drv_head;					\ 	if (m) {							\ 		if (((ifq)->ifq_drv_head = (m)->m_nextpkt) == NULL)	\ 			(ifq)->ifq_drv_tail = NULL;			\ 		(m)->m_nextpkt = NULL;					\ 		(ifq)->ifq_drv_len--;					\ 	} else {							\ 		IFQ_LOCK(ifq);						\ 		IFQ_DEQUEUE_NOLOCK(ifq, m);				\ 		while ((ifq)->ifq_drv_len< (ifq)->ifq_drv_maxlen) {	\ 			struct mbuf *m0;				\ 			IFQ_DEQUEUE_NOLOCK(ifq, m0);			\ 			if (m0 == NULL)					\ 				break;					\ 			m0->m_nextpkt = NULL;				\ 			if ((ifq)->ifq_drv_tail == NULL)		\ 				(ifq)->ifq_drv_head = m0;		\ 			else						\ 				(ifq)->ifq_drv_tail->m_nextpkt = m0;	\ 			(ifq)->ifq_drv_tail = m0;			\ 			(ifq)->ifq_drv_len++;				\ 		}							\ 		IFQ_UNLOCK(ifq);					\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|IFQ_DRV_PREPEND
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
define|\
value|do {									\ 	(m)->m_nextpkt = (ifq)->ifq_drv_head;				\ 	if ((ifq)->ifq_drv_tail == NULL)				\ 		(ifq)->ifq_drv_tail = (m);				\ 	(ifq)->ifq_drv_head = (m);					\ 	(ifq)->ifq_drv_len++;						\ } while (0)
end_define

begin_define
define|#
directive|define
name|IFQ_DRV_IS_EMPTY
parameter_list|(
name|ifq
parameter_list|)
define|\
value|(((ifq)->ifq_drv_len == 0)&& ((ifq)->ifq_len == 0))
end_define

begin_define
define|#
directive|define
name|IFQ_DRV_PURGE
parameter_list|(
name|ifq
parameter_list|)
define|\
value|do {									\ 	struct mbuf *m, *n = (ifq)->ifq_drv_head;			\ 	while((m = n) != NULL) {					\ 		n = m->m_nextpkt;					\ 		m_freem(m);						\ 	}								\ 	(ifq)->ifq_drv_head = (ifq)->ifq_drv_tail = NULL;		\ 	(ifq)->ifq_drv_len = 0;						\ 	IFQ_PURGE(ifq);							\ } while (0)
end_define

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
comment|/*  * The ifaddr structure contains information about one address  * of an interface.  They are maintained by the different address families,  * are allocated and attached when an address is set, and are linked  * together so all addresses for an interface can be located.  *  * NOTE: a 'struct ifaddr' is always at the beginning of a larger  * chunk of malloc'ed memory, where we store the three addresses  * (ifa_addr, ifa_dstaddr and ifa_netmask) referenced here.  */
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
name|struct
name|mtx
name|ifa_mtx
decl_stmt|;
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

begin_define
define|#
directive|define
name|IFA_LOCK_INIT
parameter_list|(
name|ifa
parameter_list|)
define|\
value|mtx_init(&(ifa)->ifa_mtx, "ifaddr", NULL, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|IFA_LOCK
parameter_list|(
name|ifa
parameter_list|)
value|mtx_lock(&(ifa)->ifa_mtx)
end_define

begin_define
define|#
directive|define
name|IFA_UNLOCK
parameter_list|(
name|ifa
parameter_list|)
value|mtx_unlock(&(ifa)->ifa_mtx)
end_define

begin_define
define|#
directive|define
name|IFA_DESTROY
parameter_list|(
name|ifa
parameter_list|)
value|mtx_destroy(&(ifa)->ifa_mtx)
end_define

begin_comment
comment|/*  * The prefix structure contains information about one prefix  * of an interface.  They are maintained by the different address families,  * are allocated and attached when a prefix or an address is set,  * and are linked together so all prefixes for an interface can be located.  */
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
comment|/*  * Multicast address structure.  This is analogous to the ifaddr  * structure except that it keeps track of multicast addresses.  */
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
name|struct
name|ifmultiaddr
modifier|*
name|ifma_llifma
decl_stmt|;
comment|/* pointer to ifma for ifma_lladdr */
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
value|do {						\ 		IFA_LOCK(ifa);				\ 		KASSERT((ifa)->ifa_refcnt> 0,		\ 		    ("ifa %p !(ifa_refcnt> 0)", ifa));	\ 		if (--(ifa)->ifa_refcnt == 0) {		\ 			IFA_DESTROY(ifa);		\ 			free(ifa, M_IFADDR);		\ 		} else 					\ 			IFA_UNLOCK(ifa);		\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|IFAREF
parameter_list|(
name|ifa
parameter_list|)
define|\
value|do {						\ 		IFA_LOCK(ifa);				\ 		++(ifa)->ifa_refcnt;			\ 		IFA_UNLOCK(ifa);			\ 	} while (0)
end_define

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|ifnet_lock
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IFNET_LOCK_INIT
parameter_list|()
define|\
value|mtx_init(&ifnet_lock, "ifnet", NULL, MTX_DEF | MTX_RECURSE)
end_define

begin_define
define|#
directive|define
name|IFNET_WLOCK
parameter_list|()
value|mtx_lock(&ifnet_lock)
end_define

begin_define
define|#
directive|define
name|IFNET_WUNLOCK
parameter_list|()
value|mtx_unlock(&ifnet_lock)
end_define

begin_define
define|#
directive|define
name|IFNET_RLOCK
parameter_list|()
value|IFNET_WLOCK()
end_define

begin_define
define|#
directive|define
name|IFNET_RUNLOCK
parameter_list|()
value|IFNET_WUNLOCK()
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
name|cdev
modifier|*
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

begin_comment
comment|/*  * Given the index, ifaddr_byindex() returns the one and only  * link-level ifaddr for the interface. You are not supposed to use  * it to traverse the list of addresses associated to the interface.  */
end_comment

begin_define
define|#
directive|define
name|ifaddr_byindex
parameter_list|(
name|idx
parameter_list|)
value|ifnet_byindex(idx)->if_addr
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
name|int
name|if_addgroup
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_delgroup
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
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
name|struct
name|ifnet
modifier|*
name|if_alloc
parameter_list|(
name|u_char
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
name|if_delmulti_ifma
parameter_list|(
name|struct
name|ifmultiaddr
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
name|if_purgeaddrs
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
name|struct
name|ifmultiaddr
modifier|*
name|if_findmulti
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
name|if_free
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_free_type
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|u_char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_initname
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_link_state_change
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
name|int
name|if_printf
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

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
name|ifa_ifwithbroadaddr
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

begin_typedef
typedef|typedef
name|void
modifier|*
name|if_com_alloc_t
parameter_list|(
name|u_char
name|type
parameter_list|,
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|if_com_free_t
parameter_list|(
name|void
modifier|*
name|com
parameter_list|,
name|u_char
name|type
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|if_register_com_alloc
parameter_list|(
name|u_char
name|type
parameter_list|,
name|if_com_alloc_t
modifier|*
name|a
parameter_list|,
name|if_com_free_t
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_deregister_com_alloc
parameter_list|(
name|u_char
name|type
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
value|LLADDR((struct sockaddr_dl *)((ifp)->if_addr->ifa_addr))
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

