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
name|carp_softc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ifvlantrunk
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|route
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vnet
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

begin_include
include|#
directive|include
file|<sys/buf_ring.h>
end_include

begin_include
include|#
directive|include
file|<net/vnet.h>
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
file|<sys/rwlock.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_include
include|#
directive|include
file|<sys/sx.h>
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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
expr|struct
name|pfil_head
argument_list|,
name|link_pfil_hook
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* packet filter hooks */
end_comment

begin_define
define|#
directive|define
name|V_link_pfil_hook
value|VNET(link_pfil_hook)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|IFCOUNTER_IPACKETS
init|=
literal|0
block|,
name|IFCOUNTER_IERRORS
block|,
name|IFCOUNTER_OPACKETS
block|,
name|IFCOUNTER_OERRORS
block|,
name|IFCOUNTER_COLLISIONS
block|,
name|IFCOUNTER_IBYTES
block|,
name|IFCOUNTER_OBYTES
block|,
name|IFCOUNTER_IMCASTS
block|,
name|IFCOUNTER_OMCASTS
block|,
name|IFCOUNTER_IQDROPS
block|,
name|IFCOUNTER_OQDROPS
block|,
name|IFCOUNTER_NOPROTO
block|,
name|IFCOUNTERS
comment|/* Array size. */
block|}
name|ift_counter
typedef|;
end_typedef

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

begin_struct
struct|struct
name|ifnet_hw_tsomax
block|{
name|u_int
name|tsomaxbytes
decl_stmt|;
comment|/* TSO total burst length limit in bytes */
name|u_int
name|tsomaxsegcount
decl_stmt|;
comment|/* TSO maximum segment count */
name|u_int
name|tsomaxsegsize
decl_stmt|;
comment|/* TSO maximum segment size in bytes */
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
name|struct
name|vnet
modifier|*
name|if_vnet
decl_stmt|;
comment|/* pointer to network stack instance */
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
name|u_int
name|if_refcount
decl_stmt|;
comment|/* reference count */
name|struct
name|ifaddrhead
name|if_addrhead
decl_stmt|;
comment|/* linked list of addresses per if */
comment|/* 		 * if_addrhead is the list of all addresses associated to 		 * an interface. 		 * Some code in the kernel assumes that first element 		 * of the list has type AF_LINK, and contains sockaddr_dl 		 * addresses which store the link-level address and the name 		 * of the interface. 		 * However, access to the AF_LINK address through this 		 * field is deprecated. Use if_addr or ifaddr_byindex() instead. 		 */
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
name|if_index_reserved
decl_stmt|;
comment|/* spare space to grow if_index */
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
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|route
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
name|void
function_decl|(
modifier|*
name|if_qflush
function_decl|)
comment|/* flush any queues */
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|if_transmit
function_decl|)
comment|/* initiate output routine */
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
name|if_reassign
function_decl|)
comment|/* reassign to vnet routine */
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|vnet
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
name|struct
name|vnet
modifier|*
name|if_home_vnet
decl_stmt|;
comment|/* where this ifnet originates from */
name|struct
name|ifaddr
modifier|*
name|if_addr
decl_stmt|;
comment|/* pointer to link-level address */
name|void
modifier|*
name|if_llsoftc
decl_stmt|;
comment|/* link layer softc */
name|int
name|if_drv_flags
decl_stmt|;
comment|/* driver-managed status flags */
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
name|label
modifier|*
name|if_label
decl_stmt|;
comment|/* interface MAC label */
comment|/* these are only used by IPv6 */
name|void
modifier|*
name|if_unused
index|[
literal|2
index|]
decl_stmt|;
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
name|rwlock
name|if_afdata_lock
decl_stmt|;
name|struct
name|task
name|if_linktask
decl_stmt|;
comment|/* task for link change events */
name|struct
name|rwlock
name|if_addr_lock
decl_stmt|;
comment|/* lock to protect address lists */
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
comment|/* protected by if_addr_lock */
name|void
modifier|*
name|if_pf_kif
decl_stmt|;
name|void
modifier|*
name|if_lagg
decl_stmt|;
comment|/* lagg glue */
name|char
modifier|*
name|if_description
decl_stmt|;
comment|/* interface description */
name|u_int
name|if_fib
decl_stmt|;
comment|/* interface FIB */
name|u_char
name|if_alloctype
decl_stmt|;
comment|/* if_type at time of allocation */
comment|/* 	 * Network adapter TSO limits: 	 * =========================== 	 * 	 * If the "if_hw_tsomax" field is zero the maximum segment 	 * length limit does not apply. If the "if_hw_tsomaxsegcount" 	 * or the "if_hw_tsomaxsegsize" field is zero the TSO segment 	 * count limit does not apply. If all three fields are zero, 	 * there is no TSO limit. 	 * 	 * NOTE: The TSO limits should reflect the values used in the 	 * BUSDMA tag a network adapter is using to load a mbuf chain 	 * for transmission. The TCP/IP network stack will subtract 	 * space for all linklevel and protocol level headers and 	 * ensure that the full mbuf chain passed to the network 	 * adapter fits within the given limits. 	 */
name|u_int
name|if_hw_tsomax
decl_stmt|;
comment|/* 	 * Spare fields are added so that we can modify sensitive data 	 * structures without changing the kernel binary interface, and must 	 * be used with care where binary compatibility is required. 	 */
name|char
name|if_cspare
index|[
literal|3
index|]
decl_stmt|;
name|int
name|if_ispare
index|[
literal|2
index|]
decl_stmt|;
comment|/* 	 * TSO fields for segment limits. If a field is zero below, 	 * there is no limit: 	 */
name|u_int
name|if_hw_tsomaxsegcount
decl_stmt|;
comment|/* TSO maximum segment count */
name|u_int
name|if_hw_tsomaxsegsize
decl_stmt|;
comment|/* TSO maximum segment size in bytes */
name|void
modifier|*
name|if_pspare
index|[
literal|7
index|]
decl_stmt|;
comment|/* 1 netmap, 6 TDB */
name|void
modifier|*
name|if_hw_addr
decl_stmt|;
comment|/* hardware link-level address */
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
name|if_baudrate_pf
value|if_data.ifi_baudrate_pf
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
define|if)	rw_init(&(if)->if_addr_lock, "if_addr_lock")
end_define

begin_define
define|#
directive|define
name|IF_ADDR_LOCK_DESTROY
parameter_list|(
define|if)	rw_destroy(&(if)->if_addr_lock)
end_define

begin_define
define|#
directive|define
name|IF_ADDR_WLOCK
parameter_list|(
define|if)	rw_wlock(&(if)->if_addr_lock)
end_define

begin_define
define|#
directive|define
name|IF_ADDR_WUNLOCK
parameter_list|(
define|if)	rw_wunlock(&(if)->if_addr_lock)
end_define

begin_define
define|#
directive|define
name|IF_ADDR_RLOCK
parameter_list|(
define|if)	rw_rlock(&(if)->if_addr_lock)
end_define

begin_define
define|#
directive|define
name|IF_ADDR_RUNLOCK
parameter_list|(
define|if)	rw_runlock(&(if)->if_addr_lock)
end_define

begin_define
define|#
directive|define
name|IF_ADDR_LOCK_ASSERT
parameter_list|(
define|if)	rw_assert(&(if)->if_addr_lock, RA_LOCKED)
end_define

begin_define
define|#
directive|define
name|IF_ADDR_WLOCK_ASSERT
parameter_list|(
define|if) rw_assert(&(if)->if_addr_lock, RA_WLOCKED)
end_define

begin_comment
comment|/*  * Function variations on locking macros intended to be used by loadable  * kernel modules in order to divorce them from the internals of address list  * locking.  */
end_comment

begin_function_decl
name|void
name|if_addr_rlock
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* if_addrhead */
end_comment

begin_function_decl
name|void
name|if_addr_runlock
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* if_addrhead */
end_comment

begin_function_decl
name|void
name|if_maddr_rlock
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* if_multiaddrs */
end_comment

begin_function_decl
name|void
name|if_maddr_runlock
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* if_multiaddrs */
end_comment

begin_comment
comment|/*  * Output queues (ifp->if_snd) and slow device input queues (*ifp->if_slowq)  * are queues of messages stored on ifqueue structures  * (defined above).  Entries are added to and deleted from these structures  * by these macros.  */
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
name|_IF_DEQUEUE_ALL
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
value|do {				\ 	(m) = (ifq)->ifq_head;					\ 	(ifq)->ifq_head = (ifq)->ifq_tail = NULL;		\ 	(ifq)->ifq_len = 0;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|IF_DEQUEUE_ALL
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
value|do {				\ 	IF_LOCK(ifq); 						\ 	_IF_DEQUEUE_ALL(ifq, m);				\ 	IF_UNLOCK(ifq); 					\ } while (0)
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
comment|/* interface link layer address change event */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|iflladdr_event_handler_t
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
name|iflladdr_event
argument_list|,
name|iflladdr_event_handler_t
argument_list|)
expr_stmt|;
end_expr_stmt

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
comment|/* Interface link state change event */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ifnet_link_event_handler_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|ifnet_link_event
argument_list|,
name|ifnet_link_event_handler_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Interface up/down event */
end_comment

begin_define
define|#
directive|define
name|IFNET_EVENT_UP
value|0
end_define

begin_define
define|#
directive|define
name|IFNET_EVENT_DOWN
value|1
end_define

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ifnet_event_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|int
name|event
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|ifnet_event
argument_list|,
name|ifnet_event_fn
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
value|rw_init(&(ifp)->if_afdata_lock, "if_afdata")
end_define

begin_define
define|#
directive|define
name|IF_AFDATA_WLOCK
parameter_list|(
name|ifp
parameter_list|)
value|rw_wlock(&(ifp)->if_afdata_lock)
end_define

begin_define
define|#
directive|define
name|IF_AFDATA_RLOCK
parameter_list|(
name|ifp
parameter_list|)
value|rw_rlock(&(ifp)->if_afdata_lock)
end_define

begin_define
define|#
directive|define
name|IF_AFDATA_WUNLOCK
parameter_list|(
name|ifp
parameter_list|)
value|rw_wunlock(&(ifp)->if_afdata_lock)
end_define

begin_define
define|#
directive|define
name|IF_AFDATA_RUNLOCK
parameter_list|(
name|ifp
parameter_list|)
value|rw_runlock(&(ifp)->if_afdata_lock)
end_define

begin_define
define|#
directive|define
name|IF_AFDATA_LOCK
parameter_list|(
name|ifp
parameter_list|)
value|IF_AFDATA_WLOCK(ifp)
end_define

begin_define
define|#
directive|define
name|IF_AFDATA_UNLOCK
parameter_list|(
name|ifp
parameter_list|)
value|IF_AFDATA_WUNLOCK(ifp)
end_define

begin_define
define|#
directive|define
name|IF_AFDATA_TRYLOCK
parameter_list|(
name|ifp
parameter_list|)
value|rw_try_wlock(&(ifp)->if_afdata_lock)
end_define

begin_define
define|#
directive|define
name|IF_AFDATA_DESTROY
parameter_list|(
name|ifp
parameter_list|)
value|rw_destroy(&(ifp)->if_afdata_lock)
end_define

begin_define
define|#
directive|define
name|IF_AFDATA_LOCK_ASSERT
parameter_list|(
name|ifp
parameter_list|)
value|rw_assert(&(ifp)->if_afdata_lock, RA_LOCKED)
end_define

begin_define
define|#
directive|define
name|IF_AFDATA_RLOCK_ASSERT
parameter_list|(
name|ifp
parameter_list|)
value|rw_assert(&(ifp)->if_afdata_lock, RA_RLOCKED)
end_define

begin_define
define|#
directive|define
name|IF_AFDATA_WLOCK_ASSERT
parameter_list|(
name|ifp
parameter_list|)
value|rw_assert(&(ifp)->if_afdata_lock, RA_WLOCKED)
end_define

begin_define
define|#
directive|define
name|IF_AFDATA_UNLOCK_ASSERT
parameter_list|(
name|ifp
parameter_list|)
value|rw_assert(&(ifp)->if_afdata_lock, RA_UNLOCKED)
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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function
specifier|static
name|__inline
name|void
name|if_initbaudrate
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|uintmax_t
name|baud
parameter_list|)
block|{
name|ifp
operator|->
name|if_baudrate_pf
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|baud
operator|>
call|(
name|u_long
call|)
argument_list|(
operator|~
literal|0UL
argument_list|)
condition|)
block|{
name|baud
operator|/=
literal|10
expr_stmt|;
name|ifp
operator|->
name|if_baudrate_pf
operator|++
expr_stmt|;
block|}
name|ifp
operator|->
name|if_baudrate
operator|=
name|baud
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|drbr_enqueue
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|buf_ring
modifier|*
name|br
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
block|{
name|int
name|error
init|=
literal|0
decl_stmt|;
ifdef|#
directive|ifdef
name|ALTQ
if|if
condition|(
name|ALTQ_IS_ENABLED
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|)
condition|)
block|{
name|IFQ_ENQUEUE
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|,
name|m
argument_list|,
name|error
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
endif|#
directive|endif
name|error
operator|=
name|buf_ring_enqueue
argument_list|(
name|br
argument_list|,
name|m
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
name|m_freem
argument_list|(
name|m
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|drbr_putback
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|buf_ring
modifier|*
name|br
parameter_list|,
name|struct
name|mbuf
modifier|*
name|new
parameter_list|)
block|{
comment|/* 	 * The top of the list needs to be swapped  	 * for this one. 	 */
ifdef|#
directive|ifdef
name|ALTQ
if|if
condition|(
name|ifp
operator|!=
name|NULL
operator|&&
name|ALTQ_IS_ENABLED
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|)
condition|)
block|{
comment|/*  		 * Peek in altq case dequeued it 		 * so put it back. 		 */
name|IFQ_DRV_PREPEND
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|,
name|new
argument_list|)
expr_stmt|;
return|return;
block|}
endif|#
directive|endif
name|buf_ring_putback_sc
argument_list|(
name|br
argument_list|,
name|new
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|mbuf
operator|*
name|drbr_peek
argument_list|(
argument|struct ifnet *ifp
argument_list|,
argument|struct buf_ring *br
argument_list|)
block|{
ifdef|#
directive|ifdef
name|ALTQ
block|struct
name|mbuf
operator|*
name|m
block|;
if|if
condition|(
name|ifp
operator|!=
name|NULL
operator|&&
name|ALTQ_IS_ENABLED
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|)
condition|)
block|{
comment|/*  		 * Pull it off like a dequeue 		 * since drbr_advance() does nothing 		 * for altq and drbr_putback() will 		 * use the old prepend function. 		 */
name|IFQ_DEQUEUE
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|,
name|m
argument_list|)
expr_stmt|;
return|return
operator|(
name|m
operator|)
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_return
return|return
operator|(
name|buf_ring_peek_clear_sc
argument_list|(
name|br
argument_list|)
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|void
name|drbr_flush
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|buf_ring
modifier|*
name|br
parameter_list|)
block|{
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
ifdef|#
directive|ifdef
name|ALTQ
if|if
condition|(
name|ifp
operator|!=
name|NULL
operator|&&
name|ALTQ_IS_ENABLED
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|)
condition|)
name|IFQ_PURGE
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|)
expr_stmt|;
endif|#
directive|endif
while|while
condition|(
operator|(
name|m
operator|=
name|buf_ring_dequeue_sc
argument_list|(
name|br
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
name|m_freem
argument_list|(
name|m
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|drbr_free
parameter_list|(
name|struct
name|buf_ring
modifier|*
name|br
parameter_list|,
name|struct
name|malloc_type
modifier|*
name|type
parameter_list|)
block|{
name|drbr_flush
argument_list|(
name|NULL
argument_list|,
name|br
argument_list|)
expr_stmt|;
name|buf_ring_free
argument_list|(
name|br
argument_list|,
name|type
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|mbuf
operator|*
name|drbr_dequeue
argument_list|(
argument|struct ifnet *ifp
argument_list|,
argument|struct buf_ring *br
argument_list|)
block|{
ifdef|#
directive|ifdef
name|ALTQ
block|struct
name|mbuf
operator|*
name|m
block|;
if|if
condition|(
name|ifp
operator|!=
name|NULL
operator|&&
name|ALTQ_IS_ENABLED
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|)
condition|)
block|{
name|IFQ_DEQUEUE
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|,
name|m
argument_list|)
expr_stmt|;
return|return
operator|(
name|m
operator|)
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_return
return|return
operator|(
name|buf_ring_dequeue_sc
argument_list|(
name|br
argument_list|)
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|void
name|drbr_advance
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|buf_ring
modifier|*
name|br
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|ALTQ
comment|/* Nothing to do here since peek dequeues in altq case */
if|if
condition|(
name|ifp
operator|!=
name|NULL
operator|&&
name|ALTQ_IS_ENABLED
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|)
condition|)
return|return;
endif|#
directive|endif
return|return
operator|(
name|buf_ring_advance_sc
argument_list|(
name|br
argument_list|)
operator|)
return|;
block|}
end_function

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|mbuf
operator|*
name|drbr_dequeue_cond
argument_list|(
argument|struct ifnet *ifp
argument_list|,
argument|struct buf_ring *br
argument_list|,
argument|int (*func) (struct mbuf *, void *)
argument_list|,
argument|void *arg
argument_list|)
block|{ 	struct
name|mbuf
operator|*
name|m
block|;
ifdef|#
directive|ifdef
name|ALTQ
if|if
condition|(
name|ALTQ_IS_ENABLED
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|)
condition|)
block|{
name|IFQ_LOCK
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|)
expr_stmt|;
name|IFQ_POLL_NOLOCK
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|,
name|m
argument_list|)
expr_stmt|;
if|if
condition|(
name|m
operator|!=
name|NULL
operator|&&
name|func
argument_list|(
name|m
argument_list|,
name|arg
argument_list|)
operator|==
literal|0
condition|)
block|{
name|IFQ_UNLOCK
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|)
expr_stmt|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
name|IFQ_DEQUEUE_NOLOCK
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|,
name|m
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|IFQ_UNLOCK
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
name|m
operator|)
return|;
end_return

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_expr_stmt
unit|m
operator|=
name|buf_ring_peek
argument_list|(
name|br
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|m
operator|==
name|NULL
operator|||
name|func
argument_list|(
name|m
argument_list|,
name|arg
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
end_if

begin_return
return|return
operator|(
name|buf_ring_dequeue_sc
argument_list|(
name|br
argument_list|)
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|int
name|drbr_empty
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|buf_ring
modifier|*
name|br
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|ALTQ
if|if
condition|(
name|ALTQ_IS_ENABLED
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|)
condition|)
return|return
operator|(
name|IFQ_IS_EMPTY
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|)
operator|)
return|;
endif|#
directive|endif
return|return
operator|(
name|buf_ring_empty
argument_list|(
name|br
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|drbr_needs_enqueue
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|buf_ring
modifier|*
name|br
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|ALTQ
if|if
condition|(
name|ALTQ_IS_ENABLED
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
endif|#
directive|endif
return|return
operator|(
operator|!
name|buf_ring_empty
argument_list|(
name|br
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|drbr_inuse
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|buf_ring
modifier|*
name|br
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|ALTQ
if|if
condition|(
name|ALTQ_IS_ENABLED
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|)
condition|)
return|return
operator|(
name|ifp
operator|->
name|if_snd
operator|.
name|ifq_len
operator|)
return|;
endif|#
directive|endif
return|return
operator|(
name|buf_ring_count
argument_list|(
name|br
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

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

begin_define
define|#
directive|define
name|TOEDEV
parameter_list|(
name|ifp
parameter_list|)
value|((ifp)->if_llsoftc)
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
name|struct
name|carp_softc
modifier|*
name|ifa_carp
decl_stmt|;
comment|/* pointer to CARP data */
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

begin_define
define|#
directive|define
name|IFA_RTSELF
value|RTF_HOST
end_define

begin_comment
comment|/* loopback route to self installed */
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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

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

begin_function_decl
name|void
name|ifa_free
parameter_list|(
name|struct
name|ifaddr
modifier|*
name|ifa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ifa_init
parameter_list|(
name|struct
name|ifaddr
modifier|*
name|ifa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ifa_ref
parameter_list|(
name|struct
name|ifaddr
modifier|*
name|ifa
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

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

begin_decl_stmt
specifier|extern
name|struct
name|rwlock
name|ifnet_rwlock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sx
name|ifnet_sxlock
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IFNET_LOCK_INIT
parameter_list|()
value|do {						\ 	rw_init_flags(&ifnet_rwlock, "ifnet_rw",  RW_RECURSE);		\ 	sx_init_flags(&ifnet_sxlock, "ifnet_sx",  SX_RECURSE);		\ } while(0)
end_define

begin_define
define|#
directive|define
name|IFNET_WLOCK
parameter_list|()
value|do {						\ 	sx_xlock(&ifnet_sxlock);					\ 	rw_wlock(&ifnet_rwlock);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|IFNET_WUNLOCK
parameter_list|()
value|do {						\ 	rw_wunlock(&ifnet_rwlock);					\ 	sx_xunlock(&ifnet_sxlock);					\ } while (0)
end_define

begin_comment
comment|/*  * To assert the ifnet lock, you must know not only whether it's for read or  * write, but also whether it was acquired with sleep support or not.  */
end_comment

begin_define
define|#
directive|define
name|IFNET_RLOCK_ASSERT
parameter_list|()
value|sx_assert(&ifnet_sxlock, SA_SLOCKED)
end_define

begin_define
define|#
directive|define
name|IFNET_RLOCK_NOSLEEP_ASSERT
parameter_list|()
value|rw_assert(&ifnet_rwlock, RA_RLOCKED)
end_define

begin_define
define|#
directive|define
name|IFNET_WLOCK_ASSERT
parameter_list|()
value|do {					\ 	sx_assert(&ifnet_sxlock, SA_XLOCKED);				\ 	rw_assert(&ifnet_rwlock, RA_WLOCKED);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|IFNET_RLOCK
parameter_list|()
value|sx_slock(&ifnet_sxlock)
end_define

begin_define
define|#
directive|define
name|IFNET_RLOCK_NOSLEEP
parameter_list|()
value|rw_rlock(&ifnet_rwlock)
end_define

begin_define
define|#
directive|define
name|IFNET_RUNLOCK
parameter_list|()
value|sx_sunlock(&ifnet_sxlock)
end_define

begin_define
define|#
directive|define
name|IFNET_RUNLOCK_NOSLEEP
parameter_list|()
value|rw_runlock(&ifnet_rwlock)
end_define

begin_comment
comment|/*  * Look up an ifnet given its index; the _ref variant also acquires a  * reference that must be freed using if_rele().  It is almost always a bug  * to call ifnet_byindex() instead if ifnet_byindex_ref().  */
end_comment

begin_function_decl
name|struct
name|ifnet
modifier|*
name|ifnet_byindex
parameter_list|(
name|u_short
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ifnet
modifier|*
name|ifnet_byindex_locked
parameter_list|(
name|u_short
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ifnet
modifier|*
name|ifnet_byindex_ref
parameter_list|(
name|u_short
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Given the index, ifaddr_byindex() returns the one and only  * link-level ifaddr for the interface. You are not supposed to use  * it to traverse the list of addresses associated to the interface.  */
end_comment

begin_function_decl
name|struct
name|ifaddr
modifier|*
name|ifaddr_byindex
parameter_list|(
name|u_short
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
expr|struct
name|ifnethead
argument_list|,
name|ifnet
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
expr|struct
name|ifgrouphead
argument_list|,
name|ifg_head
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|if_index
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
expr|struct
name|ifnet
operator|*
argument_list|,
name|loif
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* first loopback interface */
end_comment

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|useloopback
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_ifnet
value|VNET(ifnet)
end_define

begin_define
define|#
directive|define
name|V_ifg_head
value|VNET(ifg_head)
end_define

begin_define
define|#
directive|define
name|V_if_index
value|VNET(if_index)
end_define

begin_define
define|#
directive|define
name|V_loif
value|VNET(loif)
end_define

begin_define
define|#
directive|define
name|V_useloopback
value|VNET(useloopback)
end_define

begin_decl_stmt
specifier|extern
name|int
name|ifqmaxlen
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
name|void
name|if_dead
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
name|if_vmove
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|vnet
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
name|if_delallmulti
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
name|void
name|if_qflush
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_ref
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_rele
parameter_list|(
name|struct
name|ifnet
modifier|*
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
name|int
name|if_gethwaddr
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|ifreq
modifier|*
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
name|ifunit_ref
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ifq_init
parameter_list|(
name|struct
name|ifaltq
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ifq_delete
parameter_list|(
name|struct
name|ifaltq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ifa_add_loopback_route
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
end_function_decl

begin_function_decl
name|int
name|ifa_del_loopback_route
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
name|int
name|ifa_ifwithaddr_check
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
name|ifa_ifwithdstaddr_fib
parameter_list|(
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
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
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ifaddr
modifier|*
name|ifa_ifwithnet_fib
parameter_list|(
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
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
name|ifa_ifwithroute_fib
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
parameter_list|,
name|u_int
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
name|ifa_preferred
parameter_list|(
name|struct
name|ifaddr
modifier|*
parameter_list|,
name|struct
name|ifaddr
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

begin_function_decl
name|uint64_t
name|if_get_counter_default
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|ift_counter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_inc_counter
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|ift_counter
parameter_list|,
name|int64_t
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
name|int
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

begin_comment
comment|/* TSO */
end_comment

begin_function_decl
name|void
name|if_hw_tsomax_common
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|ifnet_hw_tsomax
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_hw_tsomax_update
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|ifnet_hw_tsomax
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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

