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

begin_struct_decl
struct_decl|struct
name|rtentry
struct_decl|;
end_struct_decl

begin_comment
comment|/* ifa_rtrequest */
end_comment

begin_struct_decl
struct_decl|struct
name|rt_addrinfo
struct_decl|;
end_struct_decl

begin_comment
comment|/* ifa_rtrequest */
end_comment

begin_struct_decl
struct_decl|struct
name|socket
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

begin_comment
comment|/* if_output */
end_comment

begin_struct_decl
struct_decl|struct
name|vnet
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ifmedia
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|netmap_adapter
struct_decl|;
end_struct_decl

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

begin_comment
comment|/* ifqueue only? */
end_comment

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
file|<sys/counter.h>
end_include

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
comment|/* struct ifqueue */
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
file|<sys/_task.h>
end_include

begin_comment
comment|/* if_link_task */
end_comment

begin_define
define|#
directive|define
name|IF_DUNIT_NONE
value|-1
end_define

begin_include
include|#
directive|include
file|<net/altq/if_altq.h>
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

begin_define
define|#
directive|define
name|HHOOK_IPSEC_INET
value|0
end_define

begin_define
define|#
directive|define
name|HHOOK_IPSEC_INET6
value|1
end_define

begin_define
define|#
directive|define
name|HHOOK_IPSEC_COUNT
value|2
end_define

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
expr|struct
name|hhook_head
operator|*
argument_list|,
name|ipsec_hhh_in
index|[
name|HHOOK_IPSEC_COUNT
index|]
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
expr|struct
name|hhook_head
operator|*
argument_list|,
name|ipsec_hhh_out
index|[
name|HHOOK_IPSEC_COUNT
index|]
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_ipsec_hhh_in
value|VNET(ipsec_hhh_in)
end_define

begin_define
define|#
directive|define
name|V_ipsec_hhh_out
value|VNET(ipsec_hhh_out)
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

begin_typedef
typedef|typedef
name|struct
name|ifnet
modifier|*
name|if_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|if_start_fn_t
function_decl|)
parameter_list|(
name|if_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|if_ioctl_fn_t
function_decl|)
parameter_list|(
name|if_t
parameter_list|,
name|u_long
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|if_init_fn_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|if_qflush_fn_t
function_decl|)
parameter_list|(
name|if_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|if_transmit_fn_t
function_decl|)
parameter_list|(
name|if_t
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
function_decl|(
modifier|*
name|if_get_counter_t
function_decl|)
parameter_list|(
name|if_t
parameter_list|,
name|ift_counter
parameter_list|)
function_decl|;
end_typedef

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
comment|/* Interface encap request types */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|IFENCAP_LL
init|=
literal|1
comment|/* pre-calculate link-layer header */
block|}
name|ife_type
typedef|;
end_typedef

begin_comment
comment|/*  * The structure below allows to request various pre-calculated L2/L3 headers  * for different media. Requests varies by type (rtype field).  *  * IFENCAP_LL type: pre-calculates link header based on address family  *   and destination lladdr.  *  *   Input data fields:  *     buf: pointer to destination buffer  *     bufsize: buffer size  *     flags: IFENCAP_FLAG_BROADCAST if destination is broadcast  *     family: address family defined by AF_ constant.  *     lladdr: pointer to link-layer address  *     lladdr_len: length of link-layer address  *     hdata: pointer to L3 header (optional, used for ARP requests).  *   Output data fields:  *     buf: encap data is stored here  *     bufsize: resulting encap length is stored here  *     lladdr_off: offset of link-layer address from encap hdr start  *     hdata: L3 header may be altered if necessary  */
end_comment

begin_struct
struct|struct
name|if_encap_req
block|{
name|u_char
modifier|*
name|buf
decl_stmt|;
comment|/* Destination buffer (w) */
name|size_t
name|bufsize
decl_stmt|;
comment|/* size of provided buffer (r) */
name|ife_type
name|rtype
decl_stmt|;
comment|/* request type (r) */
name|uint32_t
name|flags
decl_stmt|;
comment|/* Request flags (r) */
name|int
name|family
decl_stmt|;
comment|/* Address family AF_* (r) */
name|int
name|lladdr_off
decl_stmt|;
comment|/* offset from header start (w) */
name|int
name|lladdr_len
decl_stmt|;
comment|/* lladdr length (r) */
name|char
modifier|*
name|lladdr
decl_stmt|;
comment|/* link-level address pointer (r) */
name|char
modifier|*
name|hdata
decl_stmt|;
comment|/* Upper layer header data (rw) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IFENCAP_FLAG_BROADCAST
value|0x02
end_define

begin_comment
comment|/* Destination is broadcast */
end_comment

begin_comment
comment|/*  * Structure defining a network interface.  *  * Size ILP32:  592 (approx)  *	 LP64: 1048 (approx)  */
end_comment

begin_struct
struct|struct
name|ifnet
block|{
comment|/* General book keeping of interface lists. */
name|TAILQ_ENTRY
argument_list|(
argument|ifnet
argument_list|)
name|if_link
expr_stmt|;
comment|/* all struct ifnets are chained */
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
name|u_char
name|if_alloctype
decl_stmt|;
comment|/* if_type at time of allocation */
comment|/* Driver and protocol specific information that remains stable. */
name|void
modifier|*
name|if_softc
decl_stmt|;
comment|/* pointer to driver state */
name|void
modifier|*
name|if_llsoftc
decl_stmt|;
comment|/* link layer softc */
name|void
modifier|*
name|if_l2com
decl_stmt|;
comment|/* pointer to protocol bits */
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
name|u_short
name|if_index
decl_stmt|;
comment|/* numeric abbreviation for this if  */
name|short
name|if_index_reserved
decl_stmt|;
comment|/* spare space to grow if_index */
name|char
name|if_xname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* external name (name + unit) */
name|char
modifier|*
name|if_description
decl_stmt|;
comment|/* interface description */
comment|/* Variable fields that are touched by the stack and drivers. */
name|int
name|if_flags
decl_stmt|;
comment|/* up/down, broadcast, etc. */
name|int
name|if_drv_flags
decl_stmt|;
comment|/* driver-managed status flags */
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
name|u_int
name|if_refcount
decl_stmt|;
comment|/* reference count */
comment|/* These fields are shared with struct if_data. */
name|uint8_t
name|if_type
decl_stmt|;
comment|/* ethernet, tokenring, etc */
name|uint8_t
name|if_addrlen
decl_stmt|;
comment|/* media address length */
name|uint8_t
name|if_hdrlen
decl_stmt|;
comment|/* media header length */
name|uint8_t
name|if_link_state
decl_stmt|;
comment|/* current link state */
name|uint32_t
name|if_mtu
decl_stmt|;
comment|/* maximum transmission unit */
name|uint32_t
name|if_metric
decl_stmt|;
comment|/* routing metric (external only) */
name|uint64_t
name|if_baudrate
decl_stmt|;
comment|/* linespeed */
name|uint64_t
name|if_hwassist
decl_stmt|;
comment|/* HW offload capabilities, see IFCAP */
name|time_t
name|if_epoch
decl_stmt|;
comment|/* uptime at attach or stat reset */
name|struct
name|timeval
name|if_lastchange
decl_stmt|;
comment|/* time of last administrative change */
name|struct
name|ifaltq
name|if_snd
decl_stmt|;
comment|/* output queue (includes altq) */
name|struct
name|task
name|if_linktask
decl_stmt|;
comment|/* task for link change events */
comment|/* Addresses of different protocol families assigned to this if. */
name|struct
name|rwlock
name|if_addr_lock
decl_stmt|;
comment|/* lock to protect address lists */
comment|/* 		 * if_addrhead is the list of all addresses associated to 		 * an interface. 		 * Some code in the kernel assumes that first element 		 * of the list has type AF_LINK, and contains sockaddr_dl 		 * addresses which store the link-level address and the name 		 * of the interface. 		 * However, access to the AF_LINK address through this 		 * field is deprecated. Use if_addr or ifaddr_byindex() instead. 		 */
name|struct
name|ifaddrhead
name|if_addrhead
decl_stmt|;
comment|/* linked list of addresses per if */
name|struct
name|ifmultihead
name|if_multiaddrs
decl_stmt|;
comment|/* multicast addresses configured */
name|int
name|if_amcount
decl_stmt|;
comment|/* number of all-multicast requests */
name|struct
name|ifaddr
modifier|*
name|if_addr
decl_stmt|;
comment|/* pointer to link-level address */
name|void
modifier|*
name|if_hw_addr
decl_stmt|;
comment|/* hardware link-level address */
specifier|const
name|u_int8_t
modifier|*
name|if_broadcastaddr
decl_stmt|;
comment|/* linklevel broadcast bytestring */
name|struct
name|rwlock
name|if_afdata_lock
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
comment|/* Additional features hung off the interface. */
name|u_int
name|if_fib
decl_stmt|;
comment|/* interface FIB */
name|struct
name|vnet
modifier|*
name|if_vnet
decl_stmt|;
comment|/* pointer to network stack instance */
name|struct
name|vnet
modifier|*
name|if_home_vnet
decl_stmt|;
comment|/* where this ifnet originates from */
name|struct
name|ifvlantrunk
modifier|*
name|if_vlantrunk
decl_stmt|;
comment|/* pointer to 802.1q data */
name|struct
name|bpf_if
modifier|*
name|if_bpf
decl_stmt|;
comment|/* packet filter structure */
name|int
name|if_pcount
decl_stmt|;
comment|/* number of promiscuous listeners */
name|void
modifier|*
name|if_bridge
decl_stmt|;
comment|/* bridge glue */
name|void
modifier|*
name|if_lagg
decl_stmt|;
comment|/* lagg glue */
name|void
modifier|*
name|if_pf_kif
decl_stmt|;
comment|/* pf glue */
name|struct
name|carp_if
modifier|*
name|if_carp
decl_stmt|;
comment|/* carp interface structure */
name|struct
name|label
modifier|*
name|if_label
decl_stmt|;
comment|/* interface MAC label */
name|struct
name|netmap_adapter
modifier|*
name|if_netmap
decl_stmt|;
comment|/* netmap(4) softc */
comment|/* Various procedures of the layer2 encapsulation and drivers. */
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
name|if_start_fn_t
name|if_start
decl_stmt|;
comment|/* initiate output routine */
name|if_ioctl_fn_t
name|if_ioctl
decl_stmt|;
comment|/* ioctl routine */
name|if_init_fn_t
name|if_init
decl_stmt|;
comment|/* Init routine */
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
name|if_qflush_fn_t
name|if_qflush
decl_stmt|;
comment|/* flush any queue */
name|if_transmit_fn_t
name|if_transmit
decl_stmt|;
comment|/* initiate output routine */
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
name|if_get_counter_t
name|if_get_counter
decl_stmt|;
comment|/* get counter values */
name|int
function_decl|(
modifier|*
name|if_requestencap
function_decl|)
comment|/* make link header from request */
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|if_encap_req
modifier|*
parameter_list|)
function_decl|;
comment|/* Statistics. */
name|counter_u64_t
name|if_counters
index|[
name|IFCOUNTERS
index|]
decl_stmt|;
comment|/* Stuff that's only temporary and doesn't belong here. */
comment|/* 	 * Network adapter TSO limits: 	 * =========================== 	 * 	 * If the "if_hw_tsomax" field is zero the maximum segment 	 * length limit does not apply. If the "if_hw_tsomaxsegcount" 	 * or the "if_hw_tsomaxsegsize" field is zero the TSO segment 	 * count limit does not apply. If all three fields are zero, 	 * there is no TSO limit. 	 * 	 * NOTE: The TSO limits should reflect the values used in the 	 * BUSDMA tag a network adapter is using to load a mbuf chain 	 * for transmission. The TCP/IP network stack will subtract 	 * space for all linklevel and protocol level headers and 	 * ensure that the full mbuf chain passed to the network 	 * adapter fits within the given limits. 	 */
name|u_int
name|if_hw_tsomax
decl_stmt|;
comment|/* TSO maximum size in bytes */
name|u_int
name|if_hw_tsomaxsegcount
decl_stmt|;
comment|/* TSO maximum segment count */
name|u_int
name|if_hw_tsomaxsegsize
decl_stmt|;
comment|/* TSO maximum segment size in bytes */
comment|/* 	 * Spare fields to be added before branching a stable branch, so 	 * that structure can be enhanced without changing the kernel 	 * binary interface. 	 */
name|void
modifier|*
name|if_pspare
index|[
literal|4
index|]
decl_stmt|;
comment|/* packet pacing / general use */
name|int
name|if_ispare
index|[
literal|4
index|]
decl_stmt|;
comment|/* packet pacing / general use */
block|}
struct|;
end_struct

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
name|if_t
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
name|if_t
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* if_multiaddrs */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|_SYS_EVENTHANDLER_H_
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_EVENTHANDLER_H_ */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|_SYS_EVENTHANDLER_H_
end_ifdef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_EVENTHANDLER_H_ */
end_comment

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
define|#
directive|define
name|IFA_ROUTE
value|RTF_UP
comment|/* route installed */
define|#
directive|define
name|IFA_RTSELF
value|RTF_HOST
comment|/* loopback route to self installed */
name|u_int
name|ifa_refcnt
decl_stmt|;
comment|/* references to this structure */
name|counter_u64_t
name|ifa_ipackets
decl_stmt|;
name|counter_u64_t
name|ifa_opackets
decl_stmt|;
name|counter_u64_t
name|ifa_ibytes
decl_stmt|;
name|counter_u64_t
name|ifa_obytes
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* For compatibility with other BSDs. SCTP uses it. */
end_comment

begin_define
define|#
directive|define
name|ifa_list
value|ifa_link
end_define

begin_function_decl
name|struct
name|ifaddr
modifier|*
name|ifa_alloc
parameter_list|(
name|size_t
name|size
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

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
name|ifa_ref
parameter_list|(
name|struct
name|ifaddr
modifier|*
name|ifa
parameter_list|)
function_decl|;
end_function_decl

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
specifier|const
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
name|int
name|ifa_switch_loopback_route
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
specifier|const
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
specifier|const
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
specifier|const
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
name|ifa_ifwithdstaddr
parameter_list|(
specifier|const
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
specifier|const
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
specifier|const
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
specifier|const
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
name|void
name|if_data_copy
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|if_data
modifier|*
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

begin_function_decl
name|uint64_t
name|if_setbaudrate
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|uint64_t
name|baudrate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|if_getbaudrate
parameter_list|(
name|if_t
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_setcapabilities
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|int
name|capabilities
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_setcapabilitiesbit
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|int
name|setbit
parameter_list|,
name|int
name|clearbit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_getcapabilities
parameter_list|(
name|if_t
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_togglecapenable
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|int
name|togglecap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_setcapenable
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|int
name|capenable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_setcapenablebit
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|int
name|setcap
parameter_list|,
name|int
name|clearcap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_getcapenable
parameter_list|(
name|if_t
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|if_getdname
parameter_list|(
name|if_t
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_setdev
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|void
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_setdrvflagbits
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|int
name|if_setflags
parameter_list|,
name|int
name|clear_flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_getdrvflags
parameter_list|(
name|if_t
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_setdrvflags
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_clearhwassist
parameter_list|(
name|if_t
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_sethwassistbits
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|int
name|toset
parameter_list|,
name|int
name|toclear
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_sethwassist
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|int
name|hwassist_bit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_gethwassist
parameter_list|(
name|if_t
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_setsoftc
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|void
modifier|*
name|softc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|if_getsoftc
parameter_list|(
name|if_t
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_setflags
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_gethwaddr
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|struct
name|ifreq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_setmtu
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|int
name|mtu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_getmtu
parameter_list|(
name|if_t
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_getmtu_family
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|int
name|family
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_setflagbits
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|int
name|set
parameter_list|,
name|int
name|clear
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_getflags
parameter_list|(
name|if_t
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_sendq_empty
parameter_list|(
name|if_t
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_setsendqready
parameter_list|(
name|if_t
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_setsendqlen
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|int
name|tx_desc_count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_input
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|struct
name|mbuf
modifier|*
name|sendmp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_sendq_prepend
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|if_dequeue
parameter_list|(
name|if_t
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_setifheaderlen
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_setrcvif
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|if_t
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_setvtag
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|u_int16_t
name|tag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int16_t
name|if_getvtag
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_vlantrunkinuse
parameter_list|(
name|if_t
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|caddr_t
name|if_getlladdr
parameter_list|(
name|if_t
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|if_gethandle
parameter_list|(
name|u_char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_bpfmtap
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_etherbpfmtap
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_vlancap
parameter_list|(
name|if_t
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_setupmultiaddr
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|void
modifier|*
name|mta
parameter_list|,
name|int
modifier|*
name|cnt
parameter_list|,
name|int
name|max
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_multiaddr_array
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|void
modifier|*
name|mta
parameter_list|,
name|int
modifier|*
name|cnt
parameter_list|,
name|int
name|max
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_multiaddr_count
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|int
name|max
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_multi_apply
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|int
function_decl|(
modifier|*
name|filter
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|ifmultiaddr
modifier|*
parameter_list|,
name|int
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_getamcount
parameter_list|(
name|if_t
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ifaddr
modifier|*
name|if_getifaddr
parameter_list|(
name|if_t
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Functions */
end_comment

begin_function_decl
name|void
name|if_setinitfn
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_setioctlfn
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|if_t
parameter_list|,
name|u_long
parameter_list|,
name|caddr_t
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_setstartfn
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|if_t
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_settransmitfn
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|if_transmit_fn_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_setqflushfn
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|if_qflush_fn_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_setgetcounterfn
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|if_get_counter_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Revisit the below. These are inline functions originally */
end_comment

begin_function_decl
name|int
name|drbr_inuse_drv
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|struct
name|buf_ring
modifier|*
name|br
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|drbr_dequeue_drv
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|struct
name|buf_ring
modifier|*
name|br
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drbr_needs_enqueue_drv
parameter_list|(
name|if_t
name|ifp
parameter_list|,
name|struct
name|buf_ring
modifier|*
name|br
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drbr_enqueue_drv
parameter_list|(
name|if_t
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
function_decl|;
end_function_decl

begin_comment
comment|/* TSO */
end_comment

begin_function_decl
name|void
name|if_hw_tsomax_common
parameter_list|(
name|if_t
name|ifp
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
name|if_t
name|ifp
parameter_list|,
name|struct
name|ifnet_hw_tsomax
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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
name|if_t
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
name|if_t
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ether_poll_deregister
parameter_list|(
name|if_t
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

begin_include
include|#
directive|include
file|<net/ifq.h>
end_include

begin_comment
comment|/* XXXAO: temporary unconditional include */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NET_IF_VAR_H_ */
end_comment

end_unit

