begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: if_trunk.h,v 1.11 2007/01/31 06:20:19 reyk Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2005, 2006 Reyk Floeter<reyk@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_TRUNK_H
end_ifndef

begin_define
define|#
directive|define
name|_NET_TRUNK_H
end_define

begin_comment
comment|/*  * Global definitions  */
end_comment

begin_define
define|#
directive|define
name|TRUNK_MAX_PORTS
value|32
end_define

begin_comment
comment|/* logically */
end_comment

begin_define
define|#
directive|define
name|TRUNK_MAX_NAMESIZE
value|32
end_define

begin_comment
comment|/* name of a protocol */
end_comment

begin_define
define|#
directive|define
name|TRUNK_MAX_STACKING
value|4
end_define

begin_comment
comment|/* maximum number of stacked trunks */
end_comment

begin_comment
comment|/* Port flags */
end_comment

begin_define
define|#
directive|define
name|TRUNK_PORT_SLAVE
value|0x00000000
end_define

begin_comment
comment|/* normal enslaved port */
end_comment

begin_define
define|#
directive|define
name|TRUNK_PORT_MASTER
value|0x00000001
end_define

begin_comment
comment|/* primary port */
end_comment

begin_define
define|#
directive|define
name|TRUNK_PORT_STACK
value|0x00000002
end_define

begin_comment
comment|/* stacked trunk port */
end_comment

begin_define
define|#
directive|define
name|TRUNK_PORT_ACTIVE
value|0x00000004
end_define

begin_comment
comment|/* port is active */
end_comment

begin_define
define|#
directive|define
name|TRUNK_PORT_COLLECTING
value|0x00000008
end_define

begin_comment
comment|/* port is active */
end_comment

begin_define
define|#
directive|define
name|TRUNK_PORT_DISTRIBUTING
value|0x00000010
end_define

begin_comment
comment|/* port is active */
end_comment

begin_define
define|#
directive|define
name|TRUNK_PORT_GLOBAL
value|0x80000000
end_define

begin_comment
comment|/* IOCTL: global flag */
end_comment

begin_define
define|#
directive|define
name|TRUNK_PORT_BITS
value|"\20\01MASTER\02STACK\03ACTIVE\04COLLECTING" \ 				  "\05DISTRIBUTING"
end_define

begin_comment
comment|/* Supported trunk PROTOs */
end_comment

begin_define
define|#
directive|define
name|TRUNK_PROTO_NONE
value|0
end_define

begin_comment
comment|/* no trunk protocol defined */
end_comment

begin_define
define|#
directive|define
name|TRUNK_PROTO_ROUNDROBIN
value|1
end_define

begin_comment
comment|/* simple round robin */
end_comment

begin_define
define|#
directive|define
name|TRUNK_PROTO_FAILOVER
value|2
end_define

begin_comment
comment|/* active failover */
end_comment

begin_define
define|#
directive|define
name|TRUNK_PROTO_LOADBALANCE
value|3
end_define

begin_comment
comment|/* loadbalance */
end_comment

begin_define
define|#
directive|define
name|TRUNK_PROTO_LACP
value|4
end_define

begin_comment
comment|/* 802.3ad lacp */
end_comment

begin_define
define|#
directive|define
name|TRUNK_PROTO_ETHERCHANNEL
value|5
end_define

begin_comment
comment|/* Cisco FEC */
end_comment

begin_define
define|#
directive|define
name|TRUNK_PROTO_MAX
value|6
end_define

begin_struct
struct|struct
name|trunk_protos
block|{
specifier|const
name|char
modifier|*
name|tpr_name
decl_stmt|;
name|int
name|tpr_proto
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TRUNK_PROTO_DEFAULT
value|TRUNK_PROTO_FAILOVER
end_define

begin_define
define|#
directive|define
name|TRUNK_PROTOS
value|{						\ 	{ "failover",		TRUNK_PROTO_FAILOVER },			\ 	{ "fec",		TRUNK_PROTO_ETHERCHANNEL },		\ 	{ "lacp",		TRUNK_PROTO_LACP },			\ 	{ "loadbalance",	TRUNK_PROTO_LOADBALANCE },		\ 	{ "roundrobin",		TRUNK_PROTO_ROUNDROBIN },		\ 	{ "none",		TRUNK_PROTO_NONE },			\ 	{ "default",		TRUNK_PROTO_DEFAULT }			\ }
end_define

begin_comment
comment|/*  * Trunk ioctls.  */
end_comment

begin_comment
comment|/* Trunk port settings */
end_comment

begin_struct
struct|struct
name|trunk_reqport
block|{
name|char
name|rp_ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* name of the trunk */
name|char
name|rp_portname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* name of the port */
name|u_int32_t
name|rp_prio
decl_stmt|;
comment|/* port priority */
name|u_int32_t
name|rp_flags
decl_stmt|;
comment|/* port flags */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOCGTRUNKPORT
value|_IOWR('i', 140, struct trunk_reqport)
end_define

begin_define
define|#
directive|define
name|SIOCSTRUNKPORT
value|_IOW('i', 141, struct trunk_reqport)
end_define

begin_define
define|#
directive|define
name|SIOCSTRUNKDELPORT
value|_IOW('i', 142, struct trunk_reqport)
end_define

begin_comment
comment|/* Trunk, ports and options */
end_comment

begin_struct
struct|struct
name|trunk_reqall
block|{
name|char
name|ra_ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* name of the trunk */
name|u_int
name|ra_proto
decl_stmt|;
comment|/* trunk protocol */
name|size_t
name|ra_size
decl_stmt|;
comment|/* size of buffer */
name|struct
name|trunk_reqport
modifier|*
name|ra_port
decl_stmt|;
comment|/* allocated buffer */
name|int
name|ra_ports
decl_stmt|;
comment|/* total port count */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOCGTRUNK
value|_IOWR('i', 143, struct trunk_reqall)
end_define

begin_define
define|#
directive|define
name|SIOCSTRUNK
value|_IOW('i', 144, struct trunk_reqall)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Internal kernel part  */
end_comment

begin_define
define|#
directive|define
name|tp_ifname
value|tp_ifp->if_xname
end_define

begin_comment
comment|/* interface name */
end_comment

begin_define
define|#
directive|define
name|tp_link_state
value|tp_ifp->if_link_state
end_define

begin_comment
comment|/* link state */
end_comment

begin_define
define|#
directive|define
name|tp_capabilities
value|tp_ifp->if_capabilities
end_define

begin_comment
comment|/* capabilities */
end_comment

begin_define
define|#
directive|define
name|TRUNK_PORTACTIVE
parameter_list|(
name|_tp
parameter_list|)
value|(					\ 	((_tp)->tp_link_state == LINK_STATE_UP)&&			\ 	((_tp)->tp_ifp->if_flags& IFF_UP)					\ )
end_define

begin_define
define|#
directive|define
name|mc_enm
value|mc_u.mcu_enm
end_define

begin_struct
struct|struct
name|trunk_ifreq
block|{
union|union
block|{
name|struct
name|ifreq
name|ifreq
decl_stmt|;
struct|struct
block|{
name|char
name|ifr_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|struct
name|sockaddr_storage
name|ifr_ss
decl_stmt|;
block|}
name|ifreq_storage
struct|;
block|}
name|ifreq
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|tr_ifflags
value|tr_ifp->if_flags
end_define

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|tr_ifname
value|tr_ifp->if_xname
end_define

begin_comment
comment|/* name */
end_comment

begin_define
define|#
directive|define
name|tr_capabilities
value|tr_ifp->if_capabilities
end_define

begin_comment
comment|/* capabilities */
end_comment

begin_define
define|#
directive|define
name|IFCAP_TRUNK_MASK
value|0xffff0000
end_define

begin_comment
comment|/* private capabilities */
end_comment

begin_define
define|#
directive|define
name|IFCAP_TRUNK_FULLDUPLEX
value|0x00010000
end_define

begin_comment
comment|/* full duplex with>1 ports */
end_comment

begin_comment
comment|/* Private data used by the loadbalancing protocol */
end_comment

begin_define
define|#
directive|define
name|TRUNK_LB_MAXKEYS
value|8
end_define

begin_struct
struct|struct
name|trunk_lb
block|{
name|u_int32_t
name|lb_key
decl_stmt|;
name|struct
name|trunk_port
modifier|*
name|lb_ports
index|[
name|TRUNK_MAX_PORTS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|trunk_mc
block|{
union|union
block|{
name|struct
name|ether_multi
modifier|*
name|mcu_enm
decl_stmt|;
block|}
name|mc_u
union|;
name|struct
name|sockaddr_storage
name|mc_addr
decl_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|trunk_mc
argument_list|)
name|mc_entries
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|trunk_softc
block|{
name|struct
name|ifnet
modifier|*
name|tr_ifp
decl_stmt|;
comment|/* virtual interface */
name|struct
name|mtx
name|tr_mtx
decl_stmt|;
name|int
name|tr_proto
decl_stmt|;
comment|/* trunk protocol */
name|u_int
name|tr_count
decl_stmt|;
comment|/* number of ports */
name|struct
name|trunk_port
modifier|*
name|tr_primary
decl_stmt|;
comment|/* primary port */
name|struct
name|ifmedia
name|tr_media
decl_stmt|;
comment|/* media config */
name|caddr_t
name|tr_psc
decl_stmt|;
comment|/* protocol data */
name|SLIST_HEAD
argument_list|(
argument|__tplhd
argument_list|,
argument|trunk_port
argument_list|)
name|tr_ports
expr_stmt|;
comment|/* list of interfaces */
name|SLIST_ENTRY
argument_list|(
argument|trunk_softc
argument_list|)
name|tr_entries
expr_stmt|;
name|SLIST_HEAD
argument_list|(
argument|__mclhd
argument_list|,
argument|trunk_mc
argument_list|)
name|tr_mc_head
expr_stmt|;
comment|/* multicast addresses */
comment|/* Trunk protocol callbacks */
name|int
function_decl|(
modifier|*
name|tr_detach
function_decl|)
parameter_list|(
name|struct
name|trunk_softc
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|tr_start
function_decl|)
parameter_list|(
name|struct
name|trunk_softc
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
name|struct
name|mbuf
modifier|*
function_decl|(
modifier|*
name|tr_input
function_decl|)
parameter_list|(
name|struct
name|trunk_softc
modifier|*
parameter_list|,
name|struct
name|trunk_port
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|tr_port_create
function_decl|)
parameter_list|(
name|struct
name|trunk_port
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|tr_port_destroy
function_decl|)
parameter_list|(
name|struct
name|trunk_port
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|tr_linkstate
function_decl|)
parameter_list|(
name|struct
name|trunk_port
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|tr_init
function_decl|)
parameter_list|(
name|struct
name|trunk_softc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|tr_stop
function_decl|)
parameter_list|(
name|struct
name|trunk_softc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|tr_lladdr
function_decl|)
parameter_list|(
name|struct
name|trunk_softc
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|trunk_port
block|{
name|struct
name|ifnet
modifier|*
name|tp_ifp
decl_stmt|;
comment|/* physical interface */
name|struct
name|trunk_softc
modifier|*
name|tp_trunk
decl_stmt|;
comment|/* parent trunk */
name|uint8_t
name|tp_lladdr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|u_char
name|tp_iftype
decl_stmt|;
comment|/* interface type */
name|uint32_t
name|tp_prio
decl_stmt|;
comment|/* port priority */
name|uint32_t
name|tp_flags
decl_stmt|;
comment|/* port flags */
name|int
name|tp_ifflags
decl_stmt|;
comment|/* saved ifp flags */
name|void
modifier|*
name|lh_cookie
decl_stmt|;
comment|/* if state hook */
name|caddr_t
name|tp_psc
decl_stmt|;
comment|/* protocol data */
comment|/* Redirected callbacks */
name|int
function_decl|(
modifier|*
name|tp_ioctl
function_decl|)
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
name|int
function_decl|(
modifier|*
name|tp_output
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
name|SLIST_ENTRY
argument_list|(
argument|trunk_port
argument_list|)
name|tp_entries
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TRUNK_LOCK_INIT
parameter_list|(
name|_tr
parameter_list|)
value|mtx_init(&(_tr)->tr_mtx, "if_trunk", NULL, \ 				    MTX_DEF)
end_define

begin_define
define|#
directive|define
name|TRUNK_LOCK_DESTROY
parameter_list|(
name|_tr
parameter_list|)
value|mtx_destroy(&(_tr)->tr_mtx)
end_define

begin_define
define|#
directive|define
name|TRUNK_LOCK
parameter_list|(
name|_tr
parameter_list|)
value|mtx_lock(&(_tr)->tr_mtx)
end_define

begin_define
define|#
directive|define
name|TRUNK_UNLOCK
parameter_list|(
name|_tr
parameter_list|)
value|mtx_unlock(&(_tr)->tr_mtx)
end_define

begin_define
define|#
directive|define
name|TRUNK_LOCKED
parameter_list|(
name|_tr
parameter_list|)
value|mtx_owned(&(_tr)->tr_mtx)
end_define

begin_define
define|#
directive|define
name|TRUNK_LOCK_ASSERT
parameter_list|(
name|_tr
parameter_list|)
value|mtx_assert(&(_tr)->tr_mtx, MA_OWNED)
end_define

begin_function_decl
specifier|extern
name|struct
name|mbuf
modifier|*
function_decl|(
modifier|*
name|trunk_input_p
function_decl|)
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
specifier|extern
name|void
function_decl|(
modifier|*
name|trunk_linkstate_p
function_decl|)
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
name|trunk_enqueue
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
name|uint32_t
name|trunk_hashmbuf
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|uint32_t
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
comment|/* _NET_TRUNK_H */
end_comment

end_unit

