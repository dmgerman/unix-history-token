begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)route.h	7.9 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Kernel resident routing tables.  *   * The routing tables are initialized when interface addresses  * are set by making entries for all directly connected interfaces.  */
end_comment

begin_comment
comment|/*  * A route consists of a destination address and a reference  * to a routing entry.  These are often held by protocols  * in their control blocks, e.g. inpcb.  */
end_comment

begin_struct
struct|struct
name|route
block|{
name|struct
name|rtentry
modifier|*
name|ro_rt
decl_stmt|;
name|struct
name|sockaddr
name|ro_dst
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * These numbers are used by reliable protocols for determining  * retransmission behavior and are included in the routing structure.  */
end_comment

begin_struct
struct|struct
name|rt_metrics
block|{
name|u_long
name|rmx_locks
decl_stmt|;
comment|/* Kernel must leave these values alone */
name|u_long
name|rmx_mtu
decl_stmt|;
comment|/* MTU for this path */
name|u_long
name|rmx_hopcount
decl_stmt|;
comment|/* max hops expected */
name|u_long
name|rmx_expire
decl_stmt|;
comment|/* lifetime for route, e.g. redirect */
name|u_long
name|rmx_recvpipe
decl_stmt|;
comment|/* inbound delay-bandwith product */
name|u_long
name|rmx_sendpipe
decl_stmt|;
comment|/* outbound delay-bandwith product */
name|u_long
name|rmx_ssthresh
decl_stmt|;
comment|/* outbound gateway buffer limit */
name|u_long
name|rmx_rtt
decl_stmt|;
comment|/* estimated round trip time */
name|u_long
name|rmx_rttvar
decl_stmt|;
comment|/* estimated rtt variance */
block|}
struct|;
end_struct

begin_comment
comment|/*  * We distinguish between routes to hosts and routes to networks,  * preferring the former if available.  For each route we infer  * the interface to use from the gateway address supplied when  * the route was entered.  Routes that forward packets through  * gateways are marked so that the output routines know to address the  * gateway rather than the ultimate destination.  */
end_comment

begin_include
include|#
directive|include
file|"radix.h"
end_include

begin_struct
struct|struct
name|rtentry
block|{
name|struct
name|radix_node
name|rt_nodes
index|[
literal|2
index|]
decl_stmt|;
comment|/* tree glue, and other values */
define|#
directive|define
name|rt_key
parameter_list|(
name|r
parameter_list|)
value|((struct sockaddr *)((r)->rt_nodes->rn_key))
define|#
directive|define
name|rt_mask
parameter_list|(
name|r
parameter_list|)
value|((struct sockaddr *)((r)->rt_nodes->rn_mask))
name|struct
name|sockaddr
modifier|*
name|rt_gateway
decl_stmt|;
comment|/* value */
name|short
name|rt_flags
decl_stmt|;
comment|/* up/down?, host/net */
name|short
name|rt_refcnt
decl_stmt|;
comment|/* # held references */
name|u_long
name|rt_use
decl_stmt|;
comment|/* raw # packets forwarded */
name|struct
name|ifnet
modifier|*
name|rt_ifp
decl_stmt|;
comment|/* the answer: interface to use */
name|struct
name|ifaddr
modifier|*
name|rt_ifa
decl_stmt|;
comment|/* the answer: interface to use */
name|struct
name|sockaddr
modifier|*
name|rt_genmask
decl_stmt|;
comment|/* for generation of cloned routes */
name|caddr_t
name|rt_llinfo
decl_stmt|;
comment|/* pointer to link level info cache */
name|struct
name|rt_metrics
name|rt_rmx
decl_stmt|;
comment|/* metrics used by rx'ing protocols */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Following structure necessary for 4.3 compatibility;  * We should eventually move it to a compat file.  */
end_comment

begin_struct
struct|struct
name|ortentry
block|{
name|u_long
name|rt_hash
decl_stmt|;
comment|/* to speed lookups */
name|struct
name|sockaddr
name|rt_dst
decl_stmt|;
comment|/* key */
name|struct
name|sockaddr
name|rt_gateway
decl_stmt|;
comment|/* value */
name|short
name|rt_flags
decl_stmt|;
comment|/* up/down?, host/net */
name|short
name|rt_refcnt
decl_stmt|;
comment|/* # held references */
name|u_long
name|rt_use
decl_stmt|;
comment|/* raw # packets forwarded */
name|struct
name|ifnet
modifier|*
name|rt_ifp
decl_stmt|;
comment|/* the answer: interface to use */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RTF_UP
value|0x1
end_define

begin_comment
comment|/* route useable */
end_comment

begin_define
define|#
directive|define
name|RTF_GATEWAY
value|0x2
end_define

begin_comment
comment|/* destination is a gateway */
end_comment

begin_define
define|#
directive|define
name|RTF_HOST
value|0x4
end_define

begin_comment
comment|/* host entry (net otherwise) */
end_comment

begin_define
define|#
directive|define
name|RTF_DYNAMIC
value|0x10
end_define

begin_comment
comment|/* created dynamically (by redirect) */
end_comment

begin_define
define|#
directive|define
name|RTF_MODIFIED
value|0x20
end_define

begin_comment
comment|/* modified dynamically (by redirect) */
end_comment

begin_define
define|#
directive|define
name|RTF_DONE
value|0x40
end_define

begin_comment
comment|/* message confirmed */
end_comment

begin_define
define|#
directive|define
name|RTF_MASK
value|0x80
end_define

begin_comment
comment|/* subnet mask present */
end_comment

begin_define
define|#
directive|define
name|RTF_CLONING
value|0x100
end_define

begin_comment
comment|/* generate new routes on use */
end_comment

begin_define
define|#
directive|define
name|RTF_XRESOLVE
value|0x200
end_define

begin_comment
comment|/* external daemon resolves name */
end_comment

begin_comment
comment|/*  * Routing statistics.  */
end_comment

begin_struct
struct|struct
name|rtstat
block|{
name|short
name|rts_badredirect
decl_stmt|;
comment|/* bogus redirect calls */
name|short
name|rts_dynamic
decl_stmt|;
comment|/* routes created by redirects */
name|short
name|rts_newgateway
decl_stmt|;
comment|/* routes modified by redirects */
name|short
name|rts_unreach
decl_stmt|;
comment|/* lookups which failed */
name|short
name|rts_wildcard
decl_stmt|;
comment|/* lookups satisfied by a wildcard */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structures for routing messages.  */
end_comment

begin_struct
struct|struct
name|rt_msghdr
block|{
name|u_short
name|rtm_msglen
decl_stmt|;
comment|/* to skip over non-understood messages */
name|u_char
name|rtm_version
decl_stmt|;
comment|/* future binary compatability */
name|u_char
name|rtm_type
decl_stmt|;
comment|/* message type */
name|u_short
name|rtm_index
decl_stmt|;
comment|/* index for associated ifp */
name|pid_t
name|rtm_pid
decl_stmt|;
comment|/* identify sender */
name|int
name|rtm_addrs
decl_stmt|;
comment|/* bitmask identifying sockaddrs in msg */
name|int
name|rtm_seq
decl_stmt|;
comment|/* for sender to identify action */
name|int
name|rtm_errno
decl_stmt|;
comment|/* why failed */
name|int
name|rtm_flags
decl_stmt|;
comment|/* flags, incl. kern& message, e.g. DONE */
name|int
name|rtm_use
decl_stmt|;
comment|/* from rtentry */
name|u_long
name|rtm_inits
decl_stmt|;
comment|/* which metrics we are initializing */
name|struct
name|rt_metrics
name|rtm_rmx
decl_stmt|;
comment|/* metrics themselves */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|route_cb
block|{
name|int
name|ip_count
decl_stmt|;
name|int
name|ns_count
decl_stmt|;
name|int
name|iso_count
decl_stmt|;
name|int
name|any_count
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RTM_VERSION
value|2
end_define

begin_comment
comment|/* Up the ante and ignore older versions */
end_comment

begin_define
define|#
directive|define
name|RTM_ADD
value|0x1
end_define

begin_comment
comment|/* Add Route */
end_comment

begin_define
define|#
directive|define
name|RTM_DELETE
value|0x2
end_define

begin_comment
comment|/* Delete Route */
end_comment

begin_define
define|#
directive|define
name|RTM_CHANGE
value|0x3
end_define

begin_comment
comment|/* Change Metrics or flags */
end_comment

begin_define
define|#
directive|define
name|RTM_GET
value|0x4
end_define

begin_comment
comment|/* Report Metrics */
end_comment

begin_define
define|#
directive|define
name|RTM_LOSING
value|0x5
end_define

begin_comment
comment|/* Kernel Suspects Partitioning */
end_comment

begin_define
define|#
directive|define
name|RTM_REDIRECT
value|0x6
end_define

begin_comment
comment|/* Told to use different route */
end_comment

begin_define
define|#
directive|define
name|RTM_MISS
value|0x7
end_define

begin_comment
comment|/* Lookup failed on this address */
end_comment

begin_define
define|#
directive|define
name|RTM_LOCK
value|0x8
end_define

begin_comment
comment|/* fix specified metrics */
end_comment

begin_define
define|#
directive|define
name|RTM_OLDADD
value|0x9
end_define

begin_comment
comment|/* caused by SIOCADDRT */
end_comment

begin_define
define|#
directive|define
name|RTM_OLDDEL
value|0xa
end_define

begin_comment
comment|/* caused by SIOCDELRT */
end_comment

begin_define
define|#
directive|define
name|RTM_RESOLVE
value|0xb
end_define

begin_comment
comment|/* req to resolve dst to LL addr */
end_comment

begin_define
define|#
directive|define
name|RTV_MTU
value|0x1
end_define

begin_comment
comment|/* init or lock _mtu */
end_comment

begin_define
define|#
directive|define
name|RTV_HOPCOUNT
value|0x2
end_define

begin_comment
comment|/* init or lock _hopcount */
end_comment

begin_define
define|#
directive|define
name|RTV_EXPIRE
value|0x4
end_define

begin_comment
comment|/* init or lock _hopcount */
end_comment

begin_define
define|#
directive|define
name|RTV_RPIPE
value|0x8
end_define

begin_comment
comment|/* init or lock _recvpipe */
end_comment

begin_define
define|#
directive|define
name|RTV_SPIPE
value|0x10
end_define

begin_comment
comment|/* init or lock _sendpipe */
end_comment

begin_define
define|#
directive|define
name|RTV_SSTHRESH
value|0x20
end_define

begin_comment
comment|/* init or lock _ssthresh */
end_comment

begin_define
define|#
directive|define
name|RTV_RTT
value|0x40
end_define

begin_comment
comment|/* init or lock _rtt */
end_comment

begin_define
define|#
directive|define
name|RTV_RTTVAR
value|0x80
end_define

begin_comment
comment|/* init or lock _rttvar */
end_comment

begin_define
define|#
directive|define
name|RTA_DST
value|0x1
end_define

begin_comment
comment|/* destination sockaddr present */
end_comment

begin_define
define|#
directive|define
name|RTA_GATEWAY
value|0x2
end_define

begin_comment
comment|/* gateway sockaddr present */
end_comment

begin_define
define|#
directive|define
name|RTA_NETMASK
value|0x4
end_define

begin_comment
comment|/* netmask sockaddr present */
end_comment

begin_define
define|#
directive|define
name|RTA_GENMASK
value|0x8
end_define

begin_comment
comment|/* cloning mask sockaddr present */
end_comment

begin_define
define|#
directive|define
name|RTA_IFP
value|0x10
end_define

begin_comment
comment|/* interface name sockaddr present */
end_comment

begin_define
define|#
directive|define
name|RTA_IFA
value|0x20
end_define

begin_comment
comment|/* interface addr sockaddr present */
end_comment

begin_define
define|#
directive|define
name|RTA_AUTHOR
value|0x40
end_define

begin_comment
comment|/* sockaddr for author of redirect */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|route_cb
name|route_cb
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|RTFREE
parameter_list|(
name|rt
parameter_list|)
define|\
value|if ((rt)->rt_refcnt<= 1) \ 		rtfree(rt); \ 	else \ 		(rt)->rt_refcnt--;
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|GATEWAY
end_ifdef

begin_define
define|#
directive|define
name|RTHASHSIZ
value|64
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RTHASHSIZ
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|RTHASHSIZ
operator|&
operator|(
name|RTHASHSIZ
operator|-
literal|1
operator|)
operator|)
operator|==
literal|0
end_if

begin_define
define|#
directive|define
name|RTHASHMOD
parameter_list|(
name|h
parameter_list|)
value|((h)& (RTHASHSIZ - 1))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RTHASHMOD
parameter_list|(
name|h
parameter_list|)
value|((h) % RTHASHSIZ)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|rthost
index|[
name|RTHASHSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|rtnet
index|[
name|RTHASHSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|rtstat
name|rtstat
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|rtentry
modifier|*
name|rtalloc1
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

