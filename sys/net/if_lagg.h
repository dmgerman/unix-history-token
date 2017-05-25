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
name|_NET_LAGG_H
end_ifndef

begin_define
define|#
directive|define
name|_NET_LAGG_H
end_define

begin_comment
comment|/*  * Global definitions  */
end_comment

begin_define
define|#
directive|define
name|LAGG_MAX_PORTS
value|32
end_define

begin_comment
comment|/* logically */
end_comment

begin_define
define|#
directive|define
name|LAGG_MAX_NAMESIZE
value|32
end_define

begin_comment
comment|/* name of a protocol */
end_comment

begin_define
define|#
directive|define
name|LAGG_MAX_STACKING
value|4
end_define

begin_comment
comment|/* maximum number of stacked laggs */
end_comment

begin_comment
comment|/* Lagg flags */
end_comment

begin_define
define|#
directive|define
name|LAGG_F_HASHL2
value|0x00000001
end_define

begin_comment
comment|/* hash layer 2 */
end_comment

begin_define
define|#
directive|define
name|LAGG_F_HASHL3
value|0x00000002
end_define

begin_comment
comment|/* hash layer 3 */
end_comment

begin_define
define|#
directive|define
name|LAGG_F_HASHL4
value|0x00000004
end_define

begin_comment
comment|/* hash layer 4 */
end_comment

begin_define
define|#
directive|define
name|LAGG_F_HASHMASK
value|0x00000007
end_define

begin_comment
comment|/* Port flags */
end_comment

begin_define
define|#
directive|define
name|LAGG_PORT_SLAVE
value|0x00000000
end_define

begin_comment
comment|/* normal enslaved port */
end_comment

begin_define
define|#
directive|define
name|LAGG_PORT_MASTER
value|0x00000001
end_define

begin_comment
comment|/* primary port */
end_comment

begin_define
define|#
directive|define
name|LAGG_PORT_STACK
value|0x00000002
end_define

begin_comment
comment|/* stacked lagg port */
end_comment

begin_define
define|#
directive|define
name|LAGG_PORT_ACTIVE
value|0x00000004
end_define

begin_comment
comment|/* port is active */
end_comment

begin_define
define|#
directive|define
name|LAGG_PORT_COLLECTING
value|0x00000008
end_define

begin_comment
comment|/* port is receiving frames */
end_comment

begin_define
define|#
directive|define
name|LAGG_PORT_DISTRIBUTING
value|0x00000010
end_define

begin_comment
comment|/* port is sending frames */
end_comment

begin_define
define|#
directive|define
name|LAGG_PORT_DISABLED
value|0x00000020
end_define

begin_comment
comment|/* port is disabled */
end_comment

begin_define
define|#
directive|define
name|LAGG_PORT_BITS
value|"\20\01MASTER\02STACK\03ACTIVE\04COLLECTING" \ 				  "\05DISTRIBUTING\06DISABLED"
end_define

begin_comment
comment|/* Supported lagg PROTOs */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|LAGG_PROTO_NONE
init|=
literal|0
block|,
comment|/* no lagg protocol defined */
name|LAGG_PROTO_ROUNDROBIN
block|,
comment|/* simple round robin */
name|LAGG_PROTO_FAILOVER
block|,
comment|/* active failover */
name|LAGG_PROTO_LOADBALANCE
block|,
comment|/* loadbalance */
name|LAGG_PROTO_LACP
block|,
comment|/* 802.3ad lacp */
name|LAGG_PROTO_BROADCAST
block|,
comment|/* broadcast */
name|LAGG_PROTO_MAX
block|, }
name|lagg_proto
typedef|;
end_typedef

begin_struct
struct|struct
name|lagg_protos
block|{
specifier|const
name|char
modifier|*
name|lpr_name
decl_stmt|;
name|lagg_proto
name|lpr_proto
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LAGG_PROTO_DEFAULT
value|LAGG_PROTO_FAILOVER
end_define

begin_define
define|#
directive|define
name|LAGG_PROTOS
value|{						\ 	{ "failover",		LAGG_PROTO_FAILOVER },		\ 	{ "lacp",		LAGG_PROTO_LACP },			\ 	{ "loadbalance",	LAGG_PROTO_LOADBALANCE },		\ 	{ "roundrobin",	LAGG_PROTO_ROUNDROBIN },		\ 	{ "broadcast",	LAGG_PROTO_BROADCAST },		\ 	{ "none",		LAGG_PROTO_NONE },			\ 	{ "default",		LAGG_PROTO_DEFAULT }			\ }
end_define

begin_comment
comment|/*  * lagg ioctls.  */
end_comment

begin_comment
comment|/*  * LACP current operational parameters structure.  */
end_comment

begin_struct
struct|struct
name|lacp_opreq
block|{
name|uint16_t
name|actor_prio
decl_stmt|;
name|uint8_t
name|actor_mac
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|uint16_t
name|actor_key
decl_stmt|;
name|uint16_t
name|actor_portprio
decl_stmt|;
name|uint16_t
name|actor_portno
decl_stmt|;
name|uint8_t
name|actor_state
decl_stmt|;
name|uint16_t
name|partner_prio
decl_stmt|;
name|uint8_t
name|partner_mac
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|uint16_t
name|partner_key
decl_stmt|;
name|uint16_t
name|partner_portprio
decl_stmt|;
name|uint16_t
name|partner_portno
decl_stmt|;
name|uint8_t
name|partner_state
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* lagg port settings */
end_comment

begin_struct
struct|struct
name|lagg_reqport
block|{
name|char
name|rp_ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* name of the lagg */
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
union|union
block|{
name|struct
name|lacp_opreq
name|rpsc_lacp
decl_stmt|;
block|}
name|rp_psc
union|;
define|#
directive|define
name|rp_lacpreq
value|rp_psc.rpsc_lacp
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOCGLAGGPORT
value|_IOWR('i', 140, struct lagg_reqport)
end_define

begin_define
define|#
directive|define
name|SIOCSLAGGPORT
value|_IOW('i', 141, struct lagg_reqport)
end_define

begin_define
define|#
directive|define
name|SIOCSLAGGDELPORT
value|_IOW('i', 142, struct lagg_reqport)
end_define

begin_comment
comment|/* lagg, ports and options */
end_comment

begin_struct
struct|struct
name|lagg_reqall
block|{
name|char
name|ra_ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* name of the lagg */
name|u_int
name|ra_proto
decl_stmt|;
comment|/* lagg protocol */
name|size_t
name|ra_size
decl_stmt|;
comment|/* size of buffer */
name|struct
name|lagg_reqport
modifier|*
name|ra_port
decl_stmt|;
comment|/* allocated buffer */
name|int
name|ra_ports
decl_stmt|;
comment|/* total port count */
union|union
block|{
name|struct
name|lacp_opreq
name|rpsc_lacp
decl_stmt|;
block|}
name|ra_psc
union|;
define|#
directive|define
name|ra_lacpreq
value|ra_psc.rpsc_lacp
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOCGLAGG
value|_IOWR('i', 143, struct lagg_reqall)
end_define

begin_define
define|#
directive|define
name|SIOCSLAGG
value|_IOW('i', 144, struct lagg_reqall)
end_define

begin_struct
struct|struct
name|lagg_reqflags
block|{
name|char
name|rf_ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* name of the lagg */
name|uint32_t
name|rf_flags
decl_stmt|;
comment|/* lagg protocol */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOCGLAGGFLAGS
value|_IOWR('i', 145, struct lagg_reqflags)
end_define

begin_define
define|#
directive|define
name|SIOCSLAGGHASH
value|_IOW('i', 146, struct lagg_reqflags)
end_define

begin_struct
struct|struct
name|lagg_reqopts
block|{
name|char
name|ro_ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* name of the lagg */
name|int
name|ro_opts
decl_stmt|;
comment|/* Option bitmap */
define|#
directive|define
name|LAGG_OPT_NONE
value|0x00
define|#
directive|define
name|LAGG_OPT_USE_FLOWID
value|0x01
comment|/* enable use of flowid */
comment|/* Pseudo flags which are used in ro_opts but not stored into sc_opts. */
define|#
directive|define
name|LAGG_OPT_FLOWIDSHIFT
value|0x02
comment|/* set flowid shift */
define|#
directive|define
name|LAGG_OPT_FLOWIDSHIFT_MASK
value|0x1f
comment|/* flowid is uint32_t */
define|#
directive|define
name|LAGG_OPT_LACP_STRICT
value|0x10
comment|/* LACP strict mode */
define|#
directive|define
name|LAGG_OPT_LACP_TXTEST
value|0x20
comment|/* LACP debug: txtest */
define|#
directive|define
name|LAGG_OPT_LACP_RXTEST
value|0x40
comment|/* LACP debug: rxtest */
define|#
directive|define
name|LAGG_OPT_LACP_TIMEOUT
value|0x80
comment|/* LACP timeout */
name|u_int
name|ro_count
decl_stmt|;
comment|/* number of ports */
name|u_int
name|ro_active
decl_stmt|;
comment|/* active port count */
name|u_int
name|ro_flapping
decl_stmt|;
comment|/* number of flapping */
name|int
name|ro_flowid_shift
decl_stmt|;
comment|/* shift the flowid */
name|uint32_t
name|ro_bkt
decl_stmt|;
comment|/* packet bucket for roundrobin */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOCGLAGGOPTS
value|_IOWR('i', 152, struct lagg_reqopts)
end_define

begin_define
define|#
directive|define
name|SIOCSLAGGOPTS
value|_IOW('i', 153, struct lagg_reqopts)
end_define

begin_define
define|#
directive|define
name|LAGG_OPT_BITS
value|"\020\001USE_FLOWID\005LACP_STRICT" \ 				"\006LACP_TXTEST\007LACP_RXTEST"
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
name|LAGG_PORTACTIVE
parameter_list|(
name|_tp
parameter_list|)
value|(					\ 	((_tp)->lp_ifp->if_link_state == LINK_STATE_UP)&&		\ 	((_tp)->lp_ifp->if_flags& IFF_UP)				\ )
end_define

begin_struct
struct|struct
name|lagg_ifreq
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
name|sc_ifflags
value|sc_ifp->if_flags
end_define

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|sc_ifname
value|sc_ifp->if_xname
end_define

begin_comment
comment|/* name */
end_comment

begin_comment
comment|/* Private data used by the loadbalancing protocol */
end_comment

begin_struct
struct|struct
name|lagg_lb
block|{
name|u_int32_t
name|lb_key
decl_stmt|;
name|struct
name|lagg_port
modifier|*
name|lb_ports
index|[
name|LAGG_MAX_PORTS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lagg_mc
block|{
name|struct
name|sockaddr_dl
name|mc_addr
decl_stmt|;
name|struct
name|ifmultiaddr
modifier|*
name|mc_ifma
decl_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|lagg_mc
argument_list|)
name|mc_entries
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lagg_counters
block|{
name|uint64_t
name|val
index|[
name|IFCOUNTERS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lagg_softc
block|{
name|struct
name|ifnet
modifier|*
name|sc_ifp
decl_stmt|;
comment|/* virtual interface */
name|struct
name|rmlock
name|sc_mtx
decl_stmt|;
name|struct
name|sx
name|sc_sx
decl_stmt|;
name|int
name|sc_proto
decl_stmt|;
comment|/* lagg protocol */
name|u_int
name|sc_count
decl_stmt|;
comment|/* number of ports */
name|u_int
name|sc_active
decl_stmt|;
comment|/* active port count */
name|u_int
name|sc_flapping
decl_stmt|;
comment|/* number of flapping 							 * events */
name|struct
name|lagg_port
modifier|*
name|sc_primary
decl_stmt|;
comment|/* primary port */
name|struct
name|ifmedia
name|sc_media
decl_stmt|;
comment|/* media config */
name|void
modifier|*
name|sc_psc
decl_stmt|;
comment|/* protocol data */
name|uint32_t
name|sc_seq
decl_stmt|;
comment|/* sequence counter */
name|uint32_t
name|sc_flags
decl_stmt|;
name|int
name|sc_destroying
decl_stmt|;
comment|/* destroying lagg */
name|SLIST_HEAD
argument_list|(
argument|__tplhd
argument_list|,
argument|lagg_port
argument_list|)
name|sc_ports
expr_stmt|;
comment|/* list of interfaces */
name|SLIST_ENTRY
argument_list|(
argument|lagg_softc
argument_list|)
name|sc_entries
expr_stmt|;
name|eventhandler_tag
name|vlan_attach
decl_stmt|;
name|eventhandler_tag
name|vlan_detach
decl_stmt|;
name|struct
name|callout
name|sc_callout
decl_stmt|;
name|u_int
name|sc_opts
decl_stmt|;
name|int
name|flowid_shift
decl_stmt|;
comment|/* shift the flowid */
name|uint32_t
name|sc_bkt
decl_stmt|;
comment|/* packates bucket for roundrobin */
name|uint32_t
name|sc_bkt_count
decl_stmt|;
comment|/* packates bucket count for roundrobin */
name|struct
name|lagg_counters
name|detached_counters
decl_stmt|;
comment|/* detached ports sum */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lagg_port
block|{
name|struct
name|ifnet
modifier|*
name|lp_ifp
decl_stmt|;
comment|/* physical interface */
name|struct
name|lagg_softc
modifier|*
name|lp_softc
decl_stmt|;
comment|/* parent lagg */
name|uint8_t
name|lp_lladdr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|u_char
name|lp_iftype
decl_stmt|;
comment|/* interface type */
name|uint32_t
name|lp_prio
decl_stmt|;
comment|/* port priority */
name|uint32_t
name|lp_flags
decl_stmt|;
comment|/* port flags */
name|int
name|lp_ifflags
decl_stmt|;
comment|/* saved ifp flags */
name|int
name|lp_ifcapenable
decl_stmt|;
comment|/* saved ifp capenable */
name|void
modifier|*
name|lh_cookie
decl_stmt|;
comment|/* if state hook */
name|void
modifier|*
name|lp_psc
decl_stmt|;
comment|/* protocol data */
name|int
name|lp_detaching
decl_stmt|;
comment|/* ifnet is detaching */
name|SLIST_HEAD
argument_list|(
argument|__mclhd
argument_list|,
argument|lagg_mc
argument_list|)
name|lp_mc_head
expr_stmt|;
comment|/* multicast addresses */
comment|/* Redirected callbacks */
name|int
function_decl|(
modifier|*
name|lp_ioctl
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
name|lp_output
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
name|struct
name|lagg_counters
name|port_counters
decl_stmt|;
comment|/* ifp counters copy */
name|SLIST_ENTRY
argument_list|(
argument|lagg_port
argument_list|)
name|lp_entries
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LAGG_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|)
value|rm_init(&(_sc)->sc_mtx, "if_lagg rmlock")
end_define

begin_define
define|#
directive|define
name|LAGG_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|rm_destroy(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|LAGG_RLOCK
parameter_list|(
name|_sc
parameter_list|,
name|_p
parameter_list|)
value|rm_rlock(&(_sc)->sc_mtx, (_p))
end_define

begin_define
define|#
directive|define
name|LAGG_WLOCK
parameter_list|(
name|_sc
parameter_list|)
value|rm_wlock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|LAGG_RUNLOCK
parameter_list|(
name|_sc
parameter_list|,
name|_p
parameter_list|)
value|rm_runlock(&(_sc)->sc_mtx, (_p))
end_define

begin_define
define|#
directive|define
name|LAGG_WUNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|rm_wunlock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|LAGG_RLOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|rm_assert(&(_sc)->sc_mtx, RA_RLOCKED)
end_define

begin_define
define|#
directive|define
name|LAGG_WLOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|rm_assert(&(_sc)->sc_mtx, RA_WLOCKED)
end_define

begin_define
define|#
directive|define
name|LAGG_UNLOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|rm_assert(&(_sc)->sc_mtx, RA_UNLOCKED)
end_define

begin_define
define|#
directive|define
name|LAGG_SX_INIT
parameter_list|(
name|_sc
parameter_list|)
value|sx_init(&(_sc)->sc_sx, "if_lagg sx")
end_define

begin_define
define|#
directive|define
name|LAGG_SX_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|sx_destroy(&(_sc)->sc_sx)
end_define

begin_define
define|#
directive|define
name|LAGG_SLOCK
parameter_list|(
name|_sc
parameter_list|)
value|sx_slock(&(_sc)->sc_sx)
end_define

begin_define
define|#
directive|define
name|LAGG_XLOCK
parameter_list|(
name|_sc
parameter_list|)
value|sx_xlock(&(_sc)->sc_sx)
end_define

begin_define
define|#
directive|define
name|LAGG_SUNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|sx_sunlock(&(_sc)->sc_sx)
end_define

begin_define
define|#
directive|define
name|LAGG_XUNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|sx_xunlock(&(_sc)->sc_sx)
end_define

begin_define
define|#
directive|define
name|LAGG_SXLOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|sx_assert(&(_sc)->sc_sx, SA_LOCKED)
end_define

begin_define
define|#
directive|define
name|LAGG_SLOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|sx_assert(&(_sc)->sc_sx, SA_SLOCKED)
end_define

begin_define
define|#
directive|define
name|LAGG_XLOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|sx_assert(&(_sc)->sc_sx, SA_XLOCKED)
end_define

begin_function_decl
specifier|extern
name|struct
name|mbuf
modifier|*
function_decl|(
modifier|*
name|lagg_input_p
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
name|lagg_linkstate_p
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
name|lagg_enqueue
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

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_net_link_lagg
argument_list|)
expr_stmt|;
end_expr_stmt

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
comment|/* _NET_LAGG_H */
end_comment

end_unit

