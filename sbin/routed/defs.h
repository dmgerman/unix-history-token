begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgment:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)defs.h	8.1 (Berkeley) 6/5/93  *  * $FreeBSD$  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|sgi
end_ifdef

begin_empty
empty|#ident "$FreeBSD$"
end_empty

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Definitions for RIPv2 routing process.  *  * This code is based on the 4.4BSD `routed` daemon, with extensions to  * support:  *	RIPv2, including variable length subnet masks.  *	Router Discovery  *	aggregate routes in the kernel tables.  *	aggregate advertised routes.  *	maintain spare routes for faster selection of another gateway  *		when the current gateway dies.  *	timers on routes with second granularity so that selection  *		of a new route does not wait 30-60 seconds.  *	tolerance of static routes.  *	tell the kernel hop counts  *	do not advertise if ipforwarding=0  *  * The vestigial support for other protocols has been removed.  There  * is no likelihood that IETF RIPv1 or RIPv2 will ever be used with  * other protocols.  The result is far smaller, faster, cleaner, and  * perhaps understandable.  *  * The accumulation of special flags and kludges added over the many  * years have been simplified and integrated.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|sgi
end_ifdef

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_include
include|#
directive|include
file|<bstring.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|sgi
end_ifdef

begin_define
define|#
directive|define
name|_USER_ROUTE_TREE
end_define

begin_include
include|#
directive|include
file|<net/radix.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"radix.h"
end_include

begin_define
define|#
directive|define
name|UNUSED
value|__attribute__((unused))
end_define

begin_define
define|#
directive|define
name|PATTRIB
parameter_list|(
name|f
parameter_list|,
name|l
parameter_list|)
value|__attribute__((format (printf,f,l)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/route.h>
end_include

begin_include
include|#
directive|include
file|<net/if_dl.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_define
define|#
directive|define
name|RIPVERSION
value|RIPv2
end_define

begin_include
include|#
directive|include
file|<protocols/routed.h>
end_include

begin_comment
comment|/* Type of an IP address.  *	Some systems do not like to pass structures, so do not use in_addr.  *	Some systems think a long has 64 bits, which would be a gross waste.  * So define it here so it can be changed for the target system.  * It should be defined somewhere netinet/in.h, but it is not.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|sgi
end_ifdef

begin_define
define|#
directive|define
name|naddr
value|u_int32_t
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|naddr
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|_HAVE_SA_LEN
end_define

begin_define
define|#
directive|define
name|_HAVE_SIN_LEN
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|naddr
value|u_long
end_define

begin_define
define|#
directive|define
name|_HAVE_SA_LEN
end_define

begin_define
define|#
directive|define
name|_HAVE_SIN_LEN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Turn on if IP_DROP_MEMBERSHIP and IP_ADD_MEMBERSHIP do not look at  * the dstaddr of point-to-point interfaces.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_define
define|#
directive|define
name|MCAST_PPP_BUG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DAY
value|(24*60*60)
end_define

begin_define
define|#
directive|define
name|NEVER
value|DAY
end_define

begin_comment
comment|/* a long time */
end_comment

begin_define
define|#
directive|define
name|EPOCH
value|NEVER
end_define

begin_comment
comment|/* bias time by this to avoid<0 */
end_comment

begin_comment
comment|/* Scan the kernel regularly to see if any interfaces have appeared or been  * turned off.  These must be less than STALE_TIME.  */
end_comment

begin_define
define|#
directive|define
name|CHECK_BAD_INTERVAL
value|5
end_define

begin_comment
comment|/* when an interface is known bad */
end_comment

begin_define
define|#
directive|define
name|CHECK_ACT_INTERVAL
value|30
end_define

begin_comment
comment|/* when advertising */
end_comment

begin_define
define|#
directive|define
name|CHECK_QUIET_INTERVAL
value|300
end_define

begin_comment
comment|/* when not */
end_comment

begin_define
define|#
directive|define
name|LIM_SEC
parameter_list|(
name|s
parameter_list|,
name|l
parameter_list|)
value|((s).tv_sec = MIN((s).tv_sec, (l)))
end_define

begin_comment
comment|/* Metric used for fake default routes.  It ought to be 15, but when  * processing advertised routes, previous versions of `routed` added  * to the received metric and discarded the route if the total was 16  * or larger.  */
end_comment

begin_define
define|#
directive|define
name|FAKE_METRIC
value|(HOPCNT_INFINITY-2)
end_define

begin_comment
comment|/* Router Discovery parameters */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|sgi
end_ifndef

begin_define
define|#
directive|define
name|INADDR_ALLROUTERS_GROUP
value|0xe0000002
end_define

begin_comment
comment|/* 224.0.0.2 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MaxMaxAdvertiseInterval
value|1800
end_define

begin_define
define|#
directive|define
name|MinMaxAdvertiseInterval
value|4
end_define

begin_define
define|#
directive|define
name|DefMaxAdvertiseInterval
value|600
end_define

begin_define
define|#
directive|define
name|DEF_PreferenceLevel
value|0
end_define

begin_define
define|#
directive|define
name|MIN_PreferenceLevel
value|0x80000000
end_define

begin_define
define|#
directive|define
name|MAX_INITIAL_ADVERT_INTERVAL
value|16
end_define

begin_define
define|#
directive|define
name|MAX_INITIAL_ADVERTS
value|3
end_define

begin_define
define|#
directive|define
name|MAX_RESPONSE_DELAY
value|2
end_define

begin_define
define|#
directive|define
name|MAX_SOLICITATION_DELAY
value|1
end_define

begin_define
define|#
directive|define
name|SOLICITATION_INTERVAL
value|3
end_define

begin_define
define|#
directive|define
name|MAX_SOLICITATIONS
value|3
end_define

begin_comment
comment|/* Bloated packet size for systems that simply add authentication to  * full-sized packets  */
end_comment

begin_define
define|#
directive|define
name|OVER_MAXPACKETSIZE
value|(MAXPACKETSIZE+sizeof(struct netinfo)*2)
end_define

begin_comment
comment|/* typical packet buffers */
end_comment

begin_union
union|union
name|pkt_buf
block|{
name|char
name|packet
index|[
name|OVER_MAXPACKETSIZE
operator|*
literal|2
index|]
decl_stmt|;
name|struct
name|rip
name|rip
decl_stmt|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|GNAME_LEN
value|64
end_define

begin_comment
comment|/* assumed=64 in parms.c */
end_comment

begin_comment
comment|/* bigger than IFNAMSIZ, with room for "external()" or "remote()" */
end_comment

begin_define
define|#
directive|define
name|IF_NAME_LEN
value|(GNAME_LEN+15)
end_define

begin_comment
comment|/* No more routes than this, to protect ourself in case something goes  * whacko and starts broadcasting zillions of bogus routes.  */
end_comment

begin_define
define|#
directive|define
name|MAX_ROUTES
value|(128*1024)
end_define

begin_decl_stmt
specifier|extern
name|int
name|total_routes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Main, daemon routing table structure  */
end_comment

begin_struct
struct|struct
name|rt_entry
block|{
name|struct
name|radix_node
name|rt_nodes
index|[
literal|2
index|]
decl_stmt|;
comment|/* radix tree glue */
name|u_int
name|rt_state
decl_stmt|;
define|#
directive|define
name|RS_IF
value|0x001
comment|/* for network interface */
define|#
directive|define
name|RS_NET_INT
value|0x002
comment|/* authority route */
define|#
directive|define
name|RS_NET_SYN
value|0x004
comment|/* fake net route for subnet */
define|#
directive|define
name|RS_NO_NET_SYN
value|(RS_LOCAL | RS_LOCAL | RS_IF)
define|#
directive|define
name|RS_SUBNET
value|0x008
comment|/* subnet route from any source */
define|#
directive|define
name|RS_LOCAL
value|0x010
comment|/* loopback for pt-to-pt */
define|#
directive|define
name|RS_MHOME
value|0x020
comment|/* from -m */
define|#
directive|define
name|RS_STATIC
value|0x040
comment|/* from the kernel */
define|#
directive|define
name|RS_RDISC
value|0x080
comment|/* from router discovery */
name|struct
name|sockaddr_in
name|rt_dst_sock
decl_stmt|;
name|naddr
name|rt_mask
decl_stmt|;
struct|struct
name|rt_spare
block|{
name|struct
name|interface
modifier|*
name|rts_ifp
decl_stmt|;
name|naddr
name|rts_gate
decl_stmt|;
comment|/* forward packets here */
name|naddr
name|rts_router
decl_stmt|;
comment|/* on the authority of this router */
name|char
name|rts_metric
decl_stmt|;
name|u_short
name|rts_tag
decl_stmt|;
name|time_t
name|rts_time
decl_stmt|;
comment|/* timer to junk stale routes */
name|u_int
name|rts_de_ag
decl_stmt|;
comment|/* de-aggregation level */
define|#
directive|define
name|NUM_SPARES
value|4
block|}
name|rt_spares
index|[
name|NUM_SPARES
index|]
struct|;
name|u_int
name|rt_seqno
decl_stmt|;
comment|/* when last changed */
name|char
name|rt_poison_metric
decl_stmt|;
comment|/* to notice maximum recently */
name|time_t
name|rt_poison_time
decl_stmt|;
comment|/*	advertised metric */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|rt_dst
value|rt_dst_sock.sin_addr.s_addr
end_define

begin_define
define|#
directive|define
name|rt_ifp
value|rt_spares[0].rts_ifp
end_define

begin_define
define|#
directive|define
name|rt_gate
value|rt_spares[0].rts_gate
end_define

begin_define
define|#
directive|define
name|rt_router
value|rt_spares[0].rts_router
end_define

begin_define
define|#
directive|define
name|rt_metric
value|rt_spares[0].rts_metric
end_define

begin_define
define|#
directive|define
name|rt_tag
value|rt_spares[0].rts_tag
end_define

begin_define
define|#
directive|define
name|rt_time
value|rt_spares[0].rts_time
end_define

begin_define
define|#
directive|define
name|rt_de_ag
value|rt_spares[0].rts_de_ag
end_define

begin_define
define|#
directive|define
name|HOST_MASK
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|RT_ISHOST
parameter_list|(
name|rt
parameter_list|)
value|((rt)->rt_mask == HOST_MASK)
end_define

begin_comment
comment|/* age all routes that  *	are not from -g, -m, or static routes from the kernel  *	not unbroken interface routes  *		but not broken interfaces  *	nor non-passive, remote interfaces that are not aliases  *		(i.e. remote& metric=0)  */
end_comment

begin_define
define|#
directive|define
name|AGE_RT
parameter_list|(
name|rt_state
parameter_list|,
name|ifp
parameter_list|)
value|(0 == ((rt_state)& (RS_MHOME | RS_STATIC	    \ 						  | RS_NET_SYN | RS_RDISC)) \&& (!((rt_state)& RS_IF)			    \ 				  || (ifp) == 0				    \ 				  || (((ifp)->int_state& IS_REMOTE)	    \&& !((ifp)->int_state& IS_PASSIVE))))
end_define

begin_comment
comment|/* true if A is better than B  * Better if  *	- A is not a poisoned route  *	- and A is not stale  *	- and A has a shorter path  *		- or is the router speaking for itself  *		- or the current route is equal but stale  *		- or it is a host route advertised by a system for itself  */
end_comment

begin_define
define|#
directive|define
name|BETTER_LINK
parameter_list|(
name|rt
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|)
value|((A)->rts_metric< HOPCNT_INFINITY		\&& now_stale<= (A)->rts_time		\&& ((A)->rts_metric< (B)->rts_metric	\ 				 || ((A)->rts_gate == (A)->rts_router	\&& (B)->rts_gate != (B)->rts_router) \ 				 || ((A)->rts_metric == (B)->rts_metric	\&& now_stale> (B)->rts_time)	\ 				 || (RT_ISHOST(rt)			\&& (rt)->rt_dst == (A)->rts_router	\&& (A)->rts_metric == (B)->rts_metric)))
end_define

begin_comment
comment|/* An "interface" is similar to a kernel ifnet structure, except it also  * handles "logical" or "IS_REMOTE" interfaces (remote gateways).  */
end_comment

begin_struct
struct|struct
name|interface
block|{
name|struct
name|interface
modifier|*
name|int_next
decl_stmt|,
modifier|*
modifier|*
name|int_prev
decl_stmt|;
name|struct
name|interface
modifier|*
name|int_ahash
decl_stmt|,
modifier|*
modifier|*
name|int_ahash_prev
decl_stmt|;
name|struct
name|interface
modifier|*
name|int_bhash
decl_stmt|,
modifier|*
modifier|*
name|int_bhash_prev
decl_stmt|;
name|struct
name|interface
modifier|*
name|int_rlink
decl_stmt|,
modifier|*
modifier|*
name|int_rlink_prev
decl_stmt|;
name|struct
name|interface
modifier|*
name|int_nhash
decl_stmt|,
modifier|*
modifier|*
name|int_nhash_prev
decl_stmt|;
name|char
name|int_name
index|[
name|IF_NAME_LEN
operator|+
literal|1
index|]
decl_stmt|;
name|u_short
name|int_index
decl_stmt|;
name|naddr
name|int_addr
decl_stmt|;
comment|/* address on this host (net order) */
name|naddr
name|int_brdaddr
decl_stmt|;
comment|/* broadcast address (n) */
name|naddr
name|int_dstaddr
decl_stmt|;
comment|/* other end of pt-to-pt link (n) */
name|naddr
name|int_net
decl_stmt|;
comment|/* working network # (host order)*/
name|naddr
name|int_mask
decl_stmt|;
comment|/* working net mask (host order) */
name|naddr
name|int_ripv1_mask
decl_stmt|;
comment|/* for inferring a mask (n) */
name|naddr
name|int_std_addr
decl_stmt|;
comment|/* class A/B/C address (n) */
name|naddr
name|int_std_net
decl_stmt|;
comment|/* class A/B/C network (h) */
name|naddr
name|int_std_mask
decl_stmt|;
comment|/* class A/B/C netmask (h) */
name|int
name|int_rip_sock
decl_stmt|;
comment|/* for queries */
name|int
name|int_if_flags
decl_stmt|;
comment|/* some bits copied from kernel */
name|u_int
name|int_state
decl_stmt|;
name|time_t
name|int_act_time
decl_stmt|;
comment|/* last thought healthy */
name|time_t
name|int_query_time
decl_stmt|;
name|u_short
name|int_transitions
decl_stmt|;
comment|/* times gone up-down */
name|char
name|int_metric
decl_stmt|;
name|char
name|int_d_metric
decl_stmt|;
comment|/* for faked default route */
struct|struct
name|int_data
block|{
name|u_int
name|ipackets
decl_stmt|;
comment|/* previous network stats */
name|u_int
name|ierrors
decl_stmt|;
name|u_int
name|opackets
decl_stmt|;
name|u_int
name|oerrors
decl_stmt|;
ifdef|#
directive|ifdef
name|sgi
name|u_int
name|odrops
decl_stmt|;
endif|#
directive|endif
name|time_t
name|ts
decl_stmt|;
comment|/* timestamp on network stats */
block|}
name|int_data
struct|;
define|#
directive|define
name|MAX_AUTH_KEYS
value|5
struct|struct
name|auth
block|{
comment|/* authentication info */
name|u_int16_t
name|type
decl_stmt|;
name|u_char
name|key
index|[
name|RIP_AUTH_PW_LEN
index|]
decl_stmt|;
name|u_char
name|keyid
decl_stmt|;
name|time_t
name|start
decl_stmt|,
name|end
decl_stmt|;
block|}
name|int_auth
index|[
name|MAX_AUTH_KEYS
index|]
struct|;
comment|/* router discovery parameters */
name|int
name|int_rdisc_pref
decl_stmt|;
comment|/* signed preference to advertise */
name|int
name|int_rdisc_int
decl_stmt|;
comment|/* MaxAdvertiseInterval */
name|int
name|int_rdisc_cnt
decl_stmt|;
name|struct
name|timeval
name|int_rdisc_timer
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* bits in int_state */
end_comment

begin_define
define|#
directive|define
name|IS_ALIAS
value|0x0000001
end_define

begin_comment
comment|/* interface alias */
end_comment

begin_define
define|#
directive|define
name|IS_SUBNET
value|0x0000002
end_define

begin_comment
comment|/* interface on subnetted network */
end_comment

begin_define
define|#
directive|define
name|IS_REMOTE
value|0x0000004
end_define

begin_comment
comment|/* interface is not on this machine */
end_comment

begin_define
define|#
directive|define
name|IS_PASSIVE
value|0x0000008
end_define

begin_comment
comment|/* remote and does not do RIP */
end_comment

begin_define
define|#
directive|define
name|IS_EXTERNAL
value|0x0000010
end_define

begin_comment
comment|/* handled by EGP or something */
end_comment

begin_define
define|#
directive|define
name|IS_CHECKED
value|0x0000020
end_define

begin_comment
comment|/* still exists */
end_comment

begin_define
define|#
directive|define
name|IS_ALL_HOSTS
value|0x0000040
end_define

begin_comment
comment|/* in INADDR_ALLHOSTS_GROUP */
end_comment

begin_define
define|#
directive|define
name|IS_ALL_ROUTERS
value|0x0000080
end_define

begin_comment
comment|/* in INADDR_ALLROUTERS_GROUP */
end_comment

begin_define
define|#
directive|define
name|IS_DISTRUST
value|0x0000100
end_define

begin_comment
comment|/* ignore untrusted routers */
end_comment

begin_define
define|#
directive|define
name|IS_REDIRECT_OK
value|0x0000200
end_define

begin_comment
comment|/* accept ICMP redirects */
end_comment

begin_define
define|#
directive|define
name|IS_BROKE
value|0x0000400
end_define

begin_comment
comment|/* seems to be broken */
end_comment

begin_define
define|#
directive|define
name|IS_SICK
value|0x0000800
end_define

begin_comment
comment|/* seems to be broken */
end_comment

begin_define
define|#
directive|define
name|IS_DUP
value|0x0001000
end_define

begin_comment
comment|/* has a duplicate address */
end_comment

begin_define
define|#
directive|define
name|IS_NEED_NET_SYN
value|0x0002000
end_define

begin_comment
comment|/* need RS_NET_SYN route */
end_comment

begin_define
define|#
directive|define
name|IS_NO_AG
value|0x0004000
end_define

begin_comment
comment|/* do not aggregate subnets */
end_comment

begin_define
define|#
directive|define
name|IS_NO_SUPER_AG
value|0x0008000
end_define

begin_comment
comment|/* do not aggregate networks */
end_comment

begin_define
define|#
directive|define
name|IS_NO_RIPV1_IN
value|0x0010000
end_define

begin_comment
comment|/* no RIPv1 input at all */
end_comment

begin_define
define|#
directive|define
name|IS_NO_RIPV2_IN
value|0x0020000
end_define

begin_comment
comment|/* no RIPv2 input at all */
end_comment

begin_define
define|#
directive|define
name|IS_NO_RIP_IN
value|(IS_NO_RIPV1_IN | IS_NO_RIPV2_IN)
end_define

begin_define
define|#
directive|define
name|IS_RIP_IN_OFF
parameter_list|(
name|s
parameter_list|)
value|(((s)& IS_NO_RIP_IN) == IS_NO_RIP_IN)
end_define

begin_define
define|#
directive|define
name|IS_NO_RIPV1_OUT
value|0x0040000
end_define

begin_comment
comment|/* no RIPv1 output at all */
end_comment

begin_define
define|#
directive|define
name|IS_NO_RIPV2_OUT
value|0x0080000
end_define

begin_comment
comment|/* no RIPv2 output at all */
end_comment

begin_define
define|#
directive|define
name|IS_NO_RIP_OUT
value|(IS_NO_RIPV1_OUT | IS_NO_RIPV2_OUT)
end_define

begin_define
define|#
directive|define
name|IS_NO_RIP
value|(IS_NO_RIP_OUT | IS_NO_RIP_IN)
end_define

begin_define
define|#
directive|define
name|IS_RIP_OUT_OFF
parameter_list|(
name|s
parameter_list|)
value|(((s)& IS_NO_RIP_OUT) == IS_NO_RIP_OUT)
end_define

begin_define
define|#
directive|define
name|IS_RIP_OFF
parameter_list|(
name|s
parameter_list|)
value|(((s)& IS_NO_RIP) == IS_NO_RIP)
end_define

begin_define
define|#
directive|define
name|IS_NO_RIP_MCAST
value|0x0100000
end_define

begin_comment
comment|/* broadcast RIPv2 */
end_comment

begin_define
define|#
directive|define
name|IS_NO_ADV_IN
value|0x0200000
end_define

begin_comment
comment|/* do not listen to advertisements */
end_comment

begin_define
define|#
directive|define
name|IS_NO_SOL_OUT
value|0x0400000
end_define

begin_comment
comment|/* send no solicitations */
end_comment

begin_define
define|#
directive|define
name|IS_SOL_OUT
value|0x0800000
end_define

begin_comment
comment|/* send solicitations */
end_comment

begin_define
define|#
directive|define
name|GROUP_IS_SOL_OUT
value|(IS_SOL_OUT | IS_NO_SOL_OUT)
end_define

begin_define
define|#
directive|define
name|IS_NO_ADV_OUT
value|0x1000000
end_define

begin_comment
comment|/* do not advertise rdisc */
end_comment

begin_define
define|#
directive|define
name|IS_ADV_OUT
value|0x2000000
end_define

begin_comment
comment|/* advertise rdisc */
end_comment

begin_define
define|#
directive|define
name|GROUP_IS_ADV_OUT
value|(IS_NO_ADV_OUT | IS_ADV_OUT)
end_define

begin_define
define|#
directive|define
name|IS_BCAST_RDISC
value|0x4000000
end_define

begin_comment
comment|/* broadcast instead of multicast */
end_comment

begin_define
define|#
directive|define
name|IS_NO_RDISC
value|(IS_NO_ADV_IN | IS_NO_SOL_OUT | IS_NO_ADV_OUT)
end_define

begin_define
define|#
directive|define
name|IS_PM_RDISC
value|0x8000000
end_define

begin_comment
comment|/* poor-man's router discovery */
end_comment

begin_define
define|#
directive|define
name|iff_up
parameter_list|(
name|f
parameter_list|)
value|((f)& IFF_UP)
end_define

begin_comment
comment|/* Information for aggregating routes */
end_comment

begin_define
define|#
directive|define
name|NUM_AG_SLOTS
value|32
end_define

begin_struct
struct|struct
name|ag_info
block|{
name|struct
name|ag_info
modifier|*
name|ag_fine
decl_stmt|;
comment|/* slot with finer netmask */
name|struct
name|ag_info
modifier|*
name|ag_cors
decl_stmt|;
comment|/* more coarse netmask */
name|naddr
name|ag_dst_h
decl_stmt|;
comment|/* destination in host byte order */
name|naddr
name|ag_mask
decl_stmt|;
name|naddr
name|ag_gate
decl_stmt|;
name|naddr
name|ag_nhop
decl_stmt|;
name|char
name|ag_metric
decl_stmt|;
comment|/* metric to be advertised */
name|char
name|ag_pref
decl_stmt|;
comment|/* aggregate based on this */
name|u_int
name|ag_seqno
decl_stmt|;
name|u_short
name|ag_tag
decl_stmt|;
name|u_short
name|ag_state
decl_stmt|;
define|#
directive|define
name|AGS_SUPPRESS
value|0x001
comment|/* combine with coarser mask */
define|#
directive|define
name|AGS_AGGREGATE
value|0x002
comment|/* synthesize combined routes */
define|#
directive|define
name|AGS_REDUN0
value|0x004
comment|/* redundant, finer routes output */
define|#
directive|define
name|AGS_REDUN1
value|0x008
define|#
directive|define
name|AG_IS_REDUN
parameter_list|(
name|state
parameter_list|)
value|(((state)& (AGS_REDUN0 | AGS_REDUN1)) \ 				== (AGS_REDUN0 | AGS_REDUN1))
define|#
directive|define
name|AGS_GATEWAY
value|0x010
comment|/* tell kernel RTF_GATEWAY */
define|#
directive|define
name|AGS_IF
value|0x020
comment|/* for an interface */
define|#
directive|define
name|AGS_RIPV2
value|0x040
comment|/* send only as RIPv2 */
define|#
directive|define
name|AGS_FINE_GATE
value|0x080
comment|/* ignore differing ag_gate when this 					 * has the finer netmask */
define|#
directive|define
name|AGS_CORS_GATE
value|0x100
comment|/* ignore differing gate when this 					 * has the coarser netmasks */
define|#
directive|define
name|AGS_SPLIT_HZ
value|0x200
comment|/* suppress for split horizon */
comment|/* some bits are set if they are set on either route */
define|#
directive|define
name|AGS_AGGREGATE_EITHER
value|(AGS_RIPV2 | AGS_GATEWAY |   \ 				  AGS_SUPPRESS | AGS_CORS_GATE)
block|}
struct|;
end_struct

begin_comment
comment|/* parameters for interfaces */
end_comment

begin_struct
specifier|extern
struct|struct
name|parm
block|{
name|struct
name|parm
modifier|*
name|parm_next
decl_stmt|;
name|char
name|parm_name
index|[
name|IF_NAME_LEN
operator|+
literal|1
index|]
decl_stmt|;
name|naddr
name|parm_net
decl_stmt|;
name|naddr
name|parm_mask
decl_stmt|;
name|char
name|parm_d_metric
decl_stmt|;
name|u_int
name|parm_int_state
decl_stmt|;
name|int
name|parm_rdisc_pref
decl_stmt|;
comment|/* signed IRDP preference */
name|int
name|parm_rdisc_int
decl_stmt|;
comment|/* IRDP advertising interval */
name|struct
name|auth
name|parm_auth
index|[
name|MAX_AUTH_KEYS
index|]
decl_stmt|;
block|}
modifier|*
name|parms
struct|;
end_struct

begin_comment
comment|/* authority for internal networks */
end_comment

begin_struct
specifier|extern
struct|struct
name|intnet
block|{
name|struct
name|intnet
modifier|*
name|intnet_next
decl_stmt|;
name|naddr
name|intnet_addr
decl_stmt|;
comment|/* network byte order */
name|naddr
name|intnet_mask
decl_stmt|;
name|char
name|intnet_metric
decl_stmt|;
block|}
modifier|*
name|intnets
struct|;
end_struct

begin_comment
comment|/* defined RIPv1 netmasks */
end_comment

begin_struct
specifier|extern
struct|struct
name|r1net
block|{
name|struct
name|r1net
modifier|*
name|r1net_next
decl_stmt|;
name|naddr
name|r1net_net
decl_stmt|;
comment|/* host order */
name|naddr
name|r1net_match
decl_stmt|;
name|naddr
name|r1net_mask
decl_stmt|;
block|}
modifier|*
name|r1nets
struct|;
end_struct

begin_comment
comment|/* trusted routers */
end_comment

begin_struct
specifier|extern
struct|struct
name|tgate
block|{
name|struct
name|tgate
modifier|*
name|tgate_next
decl_stmt|;
name|naddr
name|tgate_addr
decl_stmt|;
define|#
directive|define
name|MAX_TGATE_NETS
value|32
struct|struct
name|tgate_net
block|{
name|naddr
name|net
decl_stmt|;
comment|/* host order */
name|naddr
name|mask
decl_stmt|;
block|}
name|tgate_nets
index|[
name|MAX_TGATE_NETS
index|]
struct|;
block|}
modifier|*
name|tgates
struct|;
end_struct

begin_enum
enum|enum
name|output_type
block|{
name|OUT_QUERY
block|,
name|OUT_UNICAST
block|,
name|OUT_BROADCAST
block|,
name|OUT_MULTICAST
block|,
name|NO_OUT_MULTICAST
block|,
name|NO_OUT_RIPV2
block|}
enum|;
end_enum

begin_comment
comment|/* common output buffers */
end_comment

begin_struct
specifier|extern
struct|struct
name|ws_buf
block|{
name|struct
name|rip
modifier|*
name|buf
decl_stmt|;
name|struct
name|netinfo
modifier|*
name|n
decl_stmt|;
name|struct
name|netinfo
modifier|*
name|base
decl_stmt|;
name|struct
name|netinfo
modifier|*
name|lim
decl_stmt|;
name|enum
name|output_type
name|type
decl_stmt|;
block|}
name|v12buf
struct|,
name|v2buf
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|pid_t
name|mypid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|naddr
name|myaddr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* main address of this system */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|stopint
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* !=0 to stop */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sock_max
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rip_sock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* RIP socket */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|interface
modifier|*
name|rip_sock_mcast
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current multicast interface */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rt_sock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* routing socket */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rt_sock_seqno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rdisc_sock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* router-discovery raw socket */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|seqno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sequence number for messages */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|supplier
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* process should supply updates */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|supplier_set
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -s or -q requested */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lookforinterfaces
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=probe for new up interfaces */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ridhosts
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=reduce host routes */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mhome
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=want multi-homed host route */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|advertise_mhome
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=must continue advertising it */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|auth_ok
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=ignore auth if we do not care */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|timeval
name|clk
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system clock's idea of time */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|timeval
name|epoch
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system clock when started */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|timeval
name|now
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current idea of time */
end_comment

begin_decl_stmt
specifier|extern
name|time_t
name|now_stale
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|time_t
name|now_expire
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|time_t
name|now_garbage
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|timeval
name|next_bcast
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* next general broadcast */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|timeval
name|age_timer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* next check of old routes */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|timeval
name|no_flash
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* inhibit flash update until then */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|timeval
name|rdisc_timer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* next advert. or solicitation */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rdisc_ok
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* using solicited route */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|timeval
name|ifinit_timer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time to check interfaces */
end_comment

begin_decl_stmt
specifier|extern
name|naddr
name|loopaddr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* our address on loopback */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tot_interfaces
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of remote and local interfaces */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rip_interfaces
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of interfaces doing RIP */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|interface
modifier|*
name|ifnet
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* all interfaces */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|interface
modifier|*
name|remote_if
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* remote interfaces */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|have_ripv1_out
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* have a RIPv1 interface */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|have_ripv1_in
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|need_flash
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flash update needed */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|timeval
name|need_kern
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* need to update kernel table */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|update_seqno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a route has changed */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tracelevel
decl_stmt|,
name|new_tracelevel
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MAX_TRACELEVEL
value|4
end_define

begin_define
define|#
directive|define
name|TRACEKERNEL
value|(tracelevel>= 4)
end_define

begin_comment
comment|/* log kernel changes */
end_comment

begin_define
define|#
directive|define
name|TRACECONTENTS
value|(tracelevel>= 3)
end_define

begin_comment
comment|/* display packet contents */
end_comment

begin_define
define|#
directive|define
name|TRACEPACKETS
value|(tracelevel>= 2)
end_define

begin_comment
comment|/* note packets */
end_comment

begin_define
define|#
directive|define
name|TRACEACTIONS
value|(tracelevel != 0)
end_define

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|ftrace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output trace file */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|inittracename
index|[
name|MAXPATHLEN
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|radix_node_head
modifier|*
name|rhead
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|sgi
end_ifdef

begin_comment
comment|/* Fix conflicts */
end_comment

begin_define
define|#
directive|define
name|dup2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|BSDdup2(x,y)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sgi */
end_comment

begin_function_decl
specifier|extern
name|void
name|fix_sock
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fix_select
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rip_off
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rip_on
parameter_list|(
name|struct
name|interface
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bufinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|output
parameter_list|(
name|enum
name|output_type
parameter_list|,
name|struct
name|sockaddr_in
modifier|*
parameter_list|,
name|struct
name|interface
modifier|*
parameter_list|,
name|struct
name|rip
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|clr_ws_buf
parameter_list|(
name|struct
name|ws_buf
modifier|*
parameter_list|,
name|struct
name|auth
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rip_query
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rip_bcast
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|supply
parameter_list|(
name|struct
name|sockaddr_in
modifier|*
parameter_list|,
name|struct
name|interface
modifier|*
parameter_list|,
name|enum
name|output_type
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|msglog
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|PATTRIB
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_struct
struct|struct
name|msg_limit
block|{
name|time_t
name|reuse
decl_stmt|;
struct|struct
name|msg_sub
block|{
name|naddr
name|addr
decl_stmt|;
name|time_t
name|until
decl_stmt|;
define|#
directive|define
name|MSG_SUBJECT_N
value|8
block|}
name|subs
index|[
name|MSG_SUBJECT_N
index|]
struct|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|void
name|msglim
parameter_list|(
name|struct
name|msg_limit
modifier|*
parameter_list|,
name|naddr
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|PATTRIB
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|LOGERR
parameter_list|(
name|msg
parameter_list|)
value|msglog(msg ": %s", strerror(errno))
end_define

begin_function_decl
specifier|extern
name|void
name|logbad
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|PATTRIB
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|BADERR
parameter_list|(
name|dump
parameter_list|,
name|msg
parameter_list|)
value|logbad(dump,msg ": %s", strerror(errno))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|DBGERR
parameter_list|(
name|dump
parameter_list|,
name|msg
parameter_list|)
value|BADERR(dump,msg)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DBGERR
parameter_list|(
name|dump
parameter_list|,
name|msg
parameter_list|)
value|LOGERR(msg)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|char
modifier|*
name|naddr_ntoa
parameter_list|(
name|naddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|saddr_ntoa
parameter_list|(
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|rtmalloc
parameter_list|(
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|timevaladd
parameter_list|(
name|struct
name|timeval
modifier|*
parameter_list|,
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|intvl_random
parameter_list|(
name|struct
name|timeval
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|getnet
parameter_list|(
name|char
modifier|*
parameter_list|,
name|naddr
modifier|*
parameter_list|,
name|naddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|gethost
parameter_list|(
name|char
modifier|*
parameter_list|,
name|naddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gwkludge
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|parse_parms
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|check_parms
parameter_list|(
name|struct
name|parm
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|get_parms
parameter_list|(
name|struct
name|interface
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lastlog
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|trace_close
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_tracefile
parameter_list|(
specifier|const
name|char
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
specifier|extern
name|void
name|tracelevel_msg
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|trace_off
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|PATTRIB
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|set_tracelevel
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|trace_flush
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|trace_misc
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|PATTRIB
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|trace_act
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|PATTRIB
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|trace_pkt
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|PATTRIB
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|trace_add_del
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|rt_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|trace_change
parameter_list|(
name|struct
name|rt_entry
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|struct
name|rt_spare
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|trace_if
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|interface
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|trace_upslot
parameter_list|(
name|struct
name|rt_entry
modifier|*
parameter_list|,
name|struct
name|rt_spare
modifier|*
parameter_list|,
name|struct
name|rt_spare
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|trace_rip
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|sockaddr_in
modifier|*
parameter_list|,
name|struct
name|interface
modifier|*
parameter_list|,
name|struct
name|rip
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|addrname
parameter_list|(
name|naddr
parameter_list|,
name|naddr
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|rtname
parameter_list|(
name|naddr
parameter_list|,
name|naddr
parameter_list|,
name|naddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rdisc_age
parameter_list|(
name|naddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_rdisc_mg
parameter_list|(
name|struct
name|interface
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_supplier
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|if_bad_rdisc
parameter_list|(
name|struct
name|interface
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|if_ok_rdisc
parameter_list|(
name|struct
name|interface
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|read_rip
parameter_list|(
name|int
parameter_list|,
name|struct
name|interface
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|read_rt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|read_d
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rdisc_adv
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rdisc_sol
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sigalrm
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sigterm
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sigtrace_on
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sigtrace_off
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|flush_kern
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|age
parameter_list|(
name|naddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ag_flush
parameter_list|(
name|naddr
parameter_list|,
name|naddr
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|ag_info
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ag_check
parameter_list|(
name|naddr
parameter_list|,
name|naddr
parameter_list|,
name|naddr
parameter_list|,
name|naddr
parameter_list|,
name|char
parameter_list|,
name|char
parameter_list|,
name|u_int
parameter_list|,
name|u_short
parameter_list|,
name|u_short
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|ag_info
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|del_static
parameter_list|(
name|naddr
parameter_list|,
name|naddr
parameter_list|,
name|naddr
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|del_redirects
parameter_list|(
name|naddr
parameter_list|,
name|time_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|rt_entry
modifier|*
name|rtget
parameter_list|(
name|naddr
parameter_list|,
name|naddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|rt_entry
modifier|*
name|rtfind
parameter_list|(
name|naddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rtinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rtadd
parameter_list|(
name|naddr
parameter_list|,
name|naddr
parameter_list|,
name|u_int
parameter_list|,
name|struct
name|rt_spare
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rtchange
parameter_list|(
name|struct
name|rt_entry
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|struct
name|rt_spare
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rtdelete
parameter_list|(
name|struct
name|rt_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rts_delete
parameter_list|(
name|struct
name|rt_entry
modifier|*
parameter_list|,
name|struct
name|rt_spare
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rtbad_sub
parameter_list|(
name|struct
name|rt_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rtswitch
parameter_list|(
name|struct
name|rt_entry
modifier|*
parameter_list|,
name|struct
name|rt_spare
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rtbad
parameter_list|(
name|struct
name|rt_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|S_ADDR
parameter_list|(
name|x
parameter_list|)
value|(((struct sockaddr_in *)(x))->sin_addr.s_addr)
end_define

begin_define
define|#
directive|define
name|INFO_DST
parameter_list|(
name|I
parameter_list|)
value|((I)->rti_info[RTAX_DST])
end_define

begin_define
define|#
directive|define
name|INFO_GATE
parameter_list|(
name|I
parameter_list|)
value|((I)->rti_info[RTAX_GATEWAY])
end_define

begin_define
define|#
directive|define
name|INFO_MASK
parameter_list|(
name|I
parameter_list|)
value|((I)->rti_info[RTAX_NETMASK])
end_define

begin_define
define|#
directive|define
name|INFO_IFA
parameter_list|(
name|I
parameter_list|)
value|((I)->rti_info[RTAX_IFA])
end_define

begin_define
define|#
directive|define
name|INFO_IFP
parameter_list|(
name|I
parameter_list|)
value|((I)->rti_info[RTAX_IFP])
end_define

begin_define
define|#
directive|define
name|INFO_AUTHOR
parameter_list|(
name|I
parameter_list|)
value|((I)->rti_info[RTAX_AUTHOR])
end_define

begin_define
define|#
directive|define
name|INFO_BRD
parameter_list|(
name|I
parameter_list|)
value|((I)->rti_info[RTAX_BRD])
end_define

begin_function_decl
name|void
name|rt_xaddrs
parameter_list|(
name|struct
name|rt_addrinfo
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|naddr
name|std_mask
parameter_list|(
name|naddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|naddr
name|ripv1_mask_net
parameter_list|(
name|naddr
parameter_list|,
name|struct
name|interface
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|naddr
name|ripv1_mask_host
parameter_list|(
name|naddr
parameter_list|,
name|struct
name|interface
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|on_net
parameter_list|(
name|a
parameter_list|,
name|net
parameter_list|,
name|mask
parameter_list|)
value|(((ntohl(a) ^ (net))& (mask)) == 0)
end_define

begin_function_decl
specifier|extern
name|int
name|check_dst
parameter_list|(
name|naddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|interface
modifier|*
name|check_dup
parameter_list|(
name|naddr
parameter_list|,
name|naddr
parameter_list|,
name|naddr
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|check_remote
parameter_list|(
name|struct
name|interface
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|addrouteforif
parameter_list|(
name|struct
name|interface
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ifinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|walk_bad
parameter_list|(
name|struct
name|radix_node
modifier|*
parameter_list|,
name|struct
name|walkarg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|if_ok
parameter_list|(
name|struct
name|interface
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|if_sick
parameter_list|(
name|struct
name|interface
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|if_bad
parameter_list|(
name|struct
name|interface
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|if_link
parameter_list|(
name|struct
name|interface
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|interface
modifier|*
name|ifwithaddr
parameter_list|(
name|naddr
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|interface
modifier|*
name|ifwithname
parameter_list|(
name|char
modifier|*
parameter_list|,
name|naddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|interface
modifier|*
name|ifwithindex
parameter_list|(
name|u_short
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|interface
modifier|*
name|iflookup
parameter_list|(
name|naddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|auth
modifier|*
name|find_auth
parameter_list|(
name|struct
name|interface
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|end_md5_auth
parameter_list|(
name|struct
name|ws_buf
modifier|*
parameter_list|,
name|struct
name|auth
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MD5_DIGEST_LEN
value|16
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|state
index|[
literal|4
index|]
decl_stmt|;
comment|/* state (ABCD) */
name|u_int32_t
name|count
index|[
literal|2
index|]
decl_stmt|;
comment|/* # of bits, modulo 2^64 (LSB 1st) */
name|unsigned
name|char
name|buffer
index|[
literal|64
index|]
decl_stmt|;
comment|/* input buffer */
block|}
name|MD5_CTX
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|MD5Init
parameter_list|(
name|MD5_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|MD5Update
parameter_list|(
name|MD5_CTX
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|MD5Final
parameter_list|(
name|u_char
index|[
name|MD5_DIGEST_LEN
index|]
parameter_list|,
name|MD5_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

