begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: in6_proto.c,v 1.64 2000/06/20 16:20:27 itojun Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)in_proto.c	8.1 (Berkeley) 6/10/93  */
end_comment

begin_include
include|#
directive|include
file|"opt_inet.h"
end_include

begin_include
include|#
directive|include
file|"opt_inet6.h"
end_include

begin_include
include|#
directive|include
file|"opt_ipsec.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/socketvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/protosw.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/domain.h>
end_include

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

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/radix.h>
end_include

begin_include
include|#
directive|include
file|<net/route.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip_encap.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip6.h>
end_include

begin_include
include|#
directive|include
file|<netinet6/ip6_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/icmp6.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp_timer.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/udp.h>
end_include

begin_include
include|#
directive|include
file|<netinet/udp_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet6/tcp6_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet6/udp6_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet6/pim6_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet6/nd6.h>
end_include

begin_include
include|#
directive|include
file|<netinet6/in6_prefix.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|IPSEC
end_ifdef

begin_include
include|#
directive|include
file|<netinet6/ipsec.h>
end_include

begin_include
include|#
directive|include
file|<netinet6/ipsec6.h>
end_include

begin_include
include|#
directive|include
file|<netinet6/ah.h>
end_include

begin_include
include|#
directive|include
file|<netinet6/ah6.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|IPSEC_ESP
end_ifdef

begin_include
include|#
directive|include
file|<netinet6/esp.h>
end_include

begin_include
include|#
directive|include
file|<netinet6/esp6.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<netinet6/ipcomp.h>
end_include

begin_include
include|#
directive|include
file|<netinet6/ipcomp6.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*IPSEC*/
end_comment

begin_include
include|#
directive|include
file|<netinet6/ip6protosw.h>
end_include

begin_include
include|#
directive|include
file|"gif.h"
end_include

begin_if
if|#
directive|if
name|NGIF
operator|>
literal|0
end_if

begin_include
include|#
directive|include
file|<netinet6/in6_gif.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<net/net_osdep.h>
end_include

begin_define
define|#
directive|define
name|offsetof
parameter_list|(
name|type
parameter_list|,
name|member
parameter_list|)
value|((size_t)(&((type *)0)->member))
end_define

begin_comment
comment|/*  * TCP/IP protocol family: IP6, ICMP6, UDP, TCP.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|domain
name|inet6domain
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pr_usrreqs
name|nousrreqs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ip6protosw
name|inet6sw
index|[]
init|=
block|{
block|{
literal|0
block|,
operator|&
name|inet6domain
block|,
name|IPPROTO_IPV6
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|ip6_init
block|,
literal|0
block|,
name|frag6_slowtimo
block|,
name|frag6_drain
block|,
operator|&
name|nousrreqs
block|, }
block|,
block|{
name|SOCK_DGRAM
block|,
operator|&
name|inet6domain
block|,
name|IPPROTO_UDP
block|,
name|PR_ATOMIC
operator||
name|PR_ADDR
block|,
name|udp6_input
block|,
literal|0
block|,
name|udp6_ctlinput
block|,
name|ip6_ctloutput
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
operator|&
name|udp6_usrreqs
block|, }
block|,
block|{
name|SOCK_STREAM
block|,
operator|&
name|inet6domain
block|,
name|IPPROTO_TCP
block|,
name|PR_CONNREQUIRED
operator||
name|PR_WANTRCVD
block|,
name|tcp6_input
block|,
literal|0
block|,
name|tcp6_ctlinput
block|,
name|tcp_ctloutput
block|,
literal|0
block|,
ifdef|#
directive|ifdef
name|INET
comment|/* don't call timeout routines twice */
name|tcp_init
block|,
literal|0
block|,
literal|0
block|,
name|tcp_drain
block|,
else|#
directive|else
name|tcp_init
block|,
name|tcp_fasttimo
block|,
name|tcp_slowtimo
block|,
name|tcp_drain
block|,
endif|#
directive|endif
operator|&
name|tcp6_usrreqs
block|, }
block|,
block|{
name|SOCK_RAW
block|,
operator|&
name|inet6domain
block|,
name|IPPROTO_RAW
block|,
name|PR_ATOMIC
operator||
name|PR_ADDR
block|,
name|rip6_input
block|,
name|rip6_output
block|,
name|rip6_ctlinput
block|,
name|rip6_ctloutput
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
operator|&
name|rip6_usrreqs
block|}
block|,
block|{
name|SOCK_RAW
block|,
operator|&
name|inet6domain
block|,
name|IPPROTO_ICMPV6
block|,
name|PR_ATOMIC
operator||
name|PR_ADDR
block|,
name|icmp6_input
block|,
name|rip6_output
block|,
literal|0
block|,
name|rip6_ctloutput
block|,
literal|0
block|,
name|icmp6_init
block|,
name|icmp6_fasttimo
block|,
literal|0
block|,
literal|0
block|,
operator|&
name|rip6_usrreqs
block|}
block|,
block|{
name|SOCK_RAW
block|,
operator|&
name|inet6domain
block|,
name|IPPROTO_DSTOPTS
block|,
name|PR_ATOMIC
operator||
name|PR_ADDR
block|,
name|dest6_input
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
operator|&
name|nousrreqs
block|}
block|,
block|{
name|SOCK_RAW
block|,
operator|&
name|inet6domain
block|,
name|IPPROTO_ROUTING
block|,
name|PR_ATOMIC
operator||
name|PR_ADDR
block|,
name|route6_input
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
operator|&
name|nousrreqs
block|}
block|,
block|{
name|SOCK_RAW
block|,
operator|&
name|inet6domain
block|,
name|IPPROTO_FRAGMENT
block|,
name|PR_ATOMIC
operator||
name|PR_ADDR
block|,
name|frag6_input
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
operator|&
name|nousrreqs
block|}
block|,
ifdef|#
directive|ifdef
name|IPSEC
block|{
name|SOCK_RAW
block|,
operator|&
name|inet6domain
block|,
name|IPPROTO_AH
block|,
name|PR_ATOMIC
operator||
name|PR_ADDR
block|,
name|ah6_input
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
operator|&
name|nousrreqs
block|, }
block|,
ifdef|#
directive|ifdef
name|IPSEC_ESP
block|{
name|SOCK_RAW
block|,
operator|&
name|inet6domain
block|,
name|IPPROTO_ESP
block|,
name|PR_ATOMIC
operator||
name|PR_ADDR
block|,
name|esp6_input
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
operator|&
name|nousrreqs
block|, }
block|,
endif|#
directive|endif
block|{
name|SOCK_RAW
block|,
operator|&
name|inet6domain
block|,
name|IPPROTO_IPCOMP
block|,
name|PR_ATOMIC
operator||
name|PR_ADDR
block|,
name|ipcomp6_input
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
operator|&
name|nousrreqs
block|, }
block|,
endif|#
directive|endif
comment|/* IPSEC */
ifdef|#
directive|ifdef
name|INET
block|{
name|SOCK_RAW
block|,
operator|&
name|inet6domain
block|,
name|IPPROTO_IPV4
block|,
name|PR_ATOMIC
operator||
name|PR_ADDR
block|,
name|encap6_input
block|,
name|rip6_output
block|,
literal|0
block|,
name|rip6_ctloutput
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
operator|&
name|rip6_usrreqs
block|}
block|,
endif|#
directive|endif
comment|/*INET*/
block|{
name|SOCK_RAW
block|,
operator|&
name|inet6domain
block|,
name|IPPROTO_IPV6
block|,
name|PR_ATOMIC
operator||
name|PR_ADDR
block|,
name|encap6_input
block|,
name|rip6_output
block|,
literal|0
block|,
name|rip6_ctloutput
block|,
literal|0
block|,
ifndef|#
directive|ifndef
name|INET
name|encap_init
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
else|#
directive|else
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
endif|#
directive|endif
operator|&
name|rip6_usrreqs
block|}
block|,
block|{
name|SOCK_RAW
block|,
operator|&
name|inet6domain
block|,
name|IPPROTO_PIM
block|,
name|PR_ATOMIC
operator||
name|PR_ADDR
block|,
name|pim6_input
block|,
name|rip6_output
block|,
literal|0
block|,
name|rip6_ctloutput
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
operator|&
name|rip6_usrreqs
block|}
block|,
comment|/* raw wildcard */
block|{
name|SOCK_RAW
block|,
operator|&
name|inet6domain
block|,
literal|0
block|,
name|PR_ATOMIC
operator||
name|PR_ADDR
block|,
name|rip6_input
block|,
name|rip6_output
block|,
literal|0
block|,
name|rip6_ctloutput
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
operator|&
name|rip6_usrreqs
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|NGIF
operator|>
literal|0
end_if

begin_decl_stmt
name|struct
name|ip6protosw
name|in6_gif_protosw
init|=
block|{
name|SOCK_RAW
block|,
operator|&
name|inet6domain
block|,
literal|0
comment|/*IPPROTO_IPV[46]*/
block|,
name|PR_ATOMIC
operator||
name|PR_ADDR
block|,
name|in6_gif_input
block|,
name|rip6_output
block|,
literal|0
block|,
name|rip6_ctloutput
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
operator|&
name|rip6_usrreqs
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*NGIF*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|in6_inithead
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|domain
name|inet6domain
init|=
block|{
name|AF_INET6
block|,
literal|"internet6"
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
operator|(
expr|struct
name|protosw
operator|*
operator|)
name|inet6sw
block|,
operator|(
expr|struct
name|protosw
operator|*
operator|)
operator|&
name|inet6sw
index|[
sizeof|sizeof
argument_list|(
name|inet6sw
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|inet6sw
index|[
literal|0
index|]
argument_list|)
index|]
block|,
literal|0
block|,
name|in6_inithead
block|,
name|offsetof
argument_list|(
expr|struct
name|sockaddr_in6
argument_list|,
name|sin6_addr
argument_list|)
operator|<<
literal|3
block|,
expr|sizeof
operator|(
expr|struct
name|sockaddr_in6
operator|)
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DOMAIN_SET
argument_list|(
name|inet6
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Internet configuration info  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IPV6FORWARDING
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|GATEWAY6
end_ifdef

begin_define
define|#
directive|define
name|IPV6FORWARDING
value|1
end_define

begin_comment
comment|/* forward IP6 packets not for us */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IPV6FORWARDING
value|0
end_define

begin_comment
comment|/* don't forward IP6 packets not for us */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GATEWAY6 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !IPV6FORWARDING */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IPV6_SENDREDIRECTS
end_ifndef

begin_define
define|#
directive|define
name|IPV6_SENDREDIRECTS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|ip6_forwarding
init|=
name|IPV6FORWARDING
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* act as router? */
end_comment

begin_decl_stmt
name|int
name|ip6_sendredirects
init|=
name|IPV6_SENDREDIRECTS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ip6_defhlim
init|=
name|IPV6_DEFHLIM
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ip6_defmcasthlim
init|=
name|IPV6_DEFAULT_MULTICAST_HOPS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ip6_accept_rtadv
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* "IPV6FORWARDING ? 0 : 1" is dangerous */
end_comment

begin_decl_stmt
name|int
name|ip6_maxfragpackets
init|=
literal|200
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ip6_log_interval
init|=
literal|5
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ip6_hdrnestlimit
init|=
literal|50
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* appropriate? */
end_comment

begin_decl_stmt
name|int
name|ip6_dad_count
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DupAddrDetectionTransmits */
end_comment

begin_decl_stmt
name|u_int32_t
name|ip6_flow_seq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ip6_auto_flowlabel
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|NGIF
operator|>
literal|0
end_if

begin_decl_stmt
name|int
name|ip6_gif_hlim
init|=
name|GIF_HLIM
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|ip6_gif_hlim
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|ip6_use_deprecated
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* allow deprecated addr (RFC2462 5.5.4) */
end_comment

begin_decl_stmt
name|int
name|ip6_rr_prune
init|=
literal|5
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* router renumbering prefix 				 * walk list every 5 sec.    */
end_comment

begin_decl_stmt
name|int
name|ip6_mapped_addr_on
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int32_t
name|ip6_id
init|=
literal|0UL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ip6_keepfaith
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|time_t
name|ip6_log_time
init|=
operator|(
name|time_t
operator|)
literal|0L
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* icmp6 */
end_comment

begin_comment
comment|/*  * BSDI4 defines these variables in in_proto.c...  * XXX: what if we don't define INET? Should we define pmtu6_expire  * or so? (jinmei@kame.net 19990310)  */
end_comment

begin_decl_stmt
name|int
name|pmtu_expire
init|=
literal|60
operator|*
literal|10
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pmtu_probe
init|=
literal|60
operator|*
literal|2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* raw IP6 parameters */
end_comment

begin_comment
comment|/*  * Nominal space allocated to a raw ip socket.  */
end_comment

begin_define
define|#
directive|define
name|RIPV6SNDQ
value|8192
end_define

begin_define
define|#
directive|define
name|RIPV6RCVQ
value|8192
end_define

begin_decl_stmt
name|u_long
name|rip6_sendspace
init|=
name|RIPV6SNDQ
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_long
name|rip6_recvspace
init|=
name|RIPV6RCVQ
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ICMPV6 parameters */
end_comment

begin_decl_stmt
name|int
name|icmp6_rediraccept
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* accept and process redirects */
end_comment

begin_decl_stmt
name|int
name|icmp6_redirtimeout
init|=
literal|10
operator|*
literal|60
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 10 minutes */
end_comment

begin_decl_stmt
name|struct
name|timeval
name|icmp6errratelim
init|=
block|{
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* no ratelimit */
end_comment

begin_decl_stmt
name|int
name|icmp6errppslim
init|=
literal|100
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 100pps */
end_comment

begin_decl_stmt
name|int
name|icmp6_nodeinfo
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* enable/disable NI response */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TCP6
end_ifdef

begin_comment
comment|/* TCP on IP6 parameters */
end_comment

begin_decl_stmt
name|int
name|tcp6_sendspace
init|=
literal|1024
operator|*
literal|8
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tcp6_recvspace
init|=
literal|1024
operator|*
literal|8
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tcp6_mssdflt
init|=
name|TCP6_MSS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tcp6_rttdflt
init|=
name|TCP6TV_SRTTDFLT
operator|/
name|PR_SLOWHZ
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tcp6_do_rfc1323
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tcp6_conntimeo
init|=
name|TCP6TV_KEEP_INIT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial connection timeout */
end_comment

begin_decl_stmt
name|int
name|tcp6_43maxseg
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tcp6_pmtu
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Parameters for keepalive option.  * Connections for which SO_KEEPALIVE is set will be probed  * after being idle for a time of tcp6_keepidle (in units of PR_SLOWHZ).  * Starting at that time, the connection is probed at intervals  * of tcp6_keepintvl (same units) until a response is received  * or until tcp6_keepcnt probes have been made, at which time  * the connection is dropped.  Note that a tcp6_keepidle value  * under 2 hours is nonconformant with RFC-1122, Internet Host Requirements.  */
end_comment

begin_decl_stmt
name|int
name|tcp6_keepidle
init|=
name|TCP6TV_KEEP_IDLE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time before probing idle */
end_comment

begin_decl_stmt
name|int
name|tcp6_keepintvl
init|=
name|TCP6TV_KEEPINTVL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* interval betwn idle probes */
end_comment

begin_decl_stmt
name|int
name|tcp6_keepcnt
init|=
name|TCP6TV_KEEPCNT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max idle probes */
end_comment

begin_decl_stmt
name|int
name|tcp6_maxpersistidle
init|=
name|TCP6TV_KEEP_IDLE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max idle time in persist */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INET_SERVER
end_ifndef

begin_define
define|#
directive|define
name|TCP6_LISTEN_HASH_SIZE
value|17
end_define

begin_define
define|#
directive|define
name|TCP6_CONN_HASH_SIZE
value|97
end_define

begin_define
define|#
directive|define
name|TCP6_SYN_HASH_SIZE
value|293
end_define

begin_define
define|#
directive|define
name|TCP6_SYN_BUCKET_SIZE
value|35
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TCP6_LISTEN_HASH_SIZE
value|97
end_define

begin_define
define|#
directive|define
name|TCP6_CONN_HASH_SIZE
value|9973
end_define

begin_define
define|#
directive|define
name|TCP6_SYN_HASH_SIZE
value|997
end_define

begin_define
define|#
directive|define
name|TCP6_SYN_BUCKET_SIZE
value|35
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|tcp6_listen_hash_size
init|=
name|TCP6_LISTEN_HASH_SIZE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tcp6_conn_hash_size
init|=
name|TCP6_CONN_HASH_SIZE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|tcp6_hash_list
name|tcp6_listen_hash
index|[
name|TCP6_LISTEN_HASH_SIZE
index|]
decl_stmt|,
name|tcp6_conn_hash
index|[
name|TCP6_CONN_HASH_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tcp6_syn_cache_size
init|=
name|TCP6_SYN_HASH_SIZE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tcp6_syn_cache_limit
init|=
name|TCP6_SYN_HASH_SIZE
operator|*
name|TCP6_SYN_BUCKET_SIZE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tcp6_syn_bucket_limit
init|=
literal|3
operator|*
name|TCP6_SYN_BUCKET_SIZE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|syn_cache_head6
name|tcp6_syn_cache
index|[
name|TCP6_SYN_HASH_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|syn_cache_head6
modifier|*
name|tcp6_syn_cache_first
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tcp6_syn_cache_interval
init|=
literal|8
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* runs timer every 4 seconds */
end_comment

begin_decl_stmt
name|int
name|tcp6_syn_cache_timeo
init|=
name|TCP6TV_KEEP_INIT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Parameters for computing a desirable data segment size  * given an upper bound (either interface MTU, or peer's MSS option)_.  * As applications tend to use a buffer size that is a multiple  * of kilobytes, try for something that divides evenly. However,  * do not round down too much.  *  * Round segment size down to a multiple of TCP6_ROUNDSIZE if this  * does not result in lowering by more than (size/TCP6_ROUNDFRAC).  * For example, round 536 to 512.  Older versions of the system  * effectively used MCLBYTES (1K or 2K) as TCP6_ROUNDSIZE, with  * a value of 1 for TCP6_ROUNDFRAC (eliminating its effect).  * We round to a multiple of 256 for SLIP.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TCP6_ROUNDSIZE
end_ifndef

begin_define
define|#
directive|define
name|TCP6_ROUNDSIZE
value|256
end_define

begin_comment
comment|/* round to multiple of 256 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TCP6_ROUNDFRAC
end_ifndef

begin_define
define|#
directive|define
name|TCP6_ROUNDFRAC
value|10
end_define

begin_comment
comment|/* round down at most N/10, or 10% */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|tcp6_roundsize
init|=
name|TCP6_ROUNDSIZE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tcp6_roundfrac
init|=
name|TCP6_ROUNDFRAC
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*TCP6*/
end_comment

begin_comment
comment|/* UDP on IP6 parameters */
end_comment

begin_decl_stmt
name|int
name|udp6_sendspace
init|=
literal|9216
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* really max datagram size */
end_comment

begin_decl_stmt
name|int
name|udp6_recvspace
init|=
literal|40
operator|*
operator|(
literal|1024
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|sockaddr_in6
argument_list|)
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 40 1K datagrams */
end_comment

begin_comment
comment|/*  * sysctl related items.  */
end_comment

begin_expr_stmt
name|SYSCTL_NODE
argument_list|(
name|_net
argument_list|,
name|PF_INET6
argument_list|,
name|inet6
argument_list|,
name|CTLFLAG_RW
argument_list|,
literal|0
argument_list|,
literal|"Internet6 Family"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* net.inet6 */
end_comment

begin_expr_stmt
name|SYSCTL_NODE
argument_list|(
name|_net_inet6
argument_list|,
name|IPPROTO_IPV6
argument_list|,
name|ip6
argument_list|,
name|CTLFLAG_RW
argument_list|,
literal|0
argument_list|,
literal|"IP6"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_NODE
argument_list|(
name|_net_inet6
argument_list|,
name|IPPROTO_ICMPV6
argument_list|,
name|icmp6
argument_list|,
name|CTLFLAG_RW
argument_list|,
literal|0
argument_list|,
literal|"ICMP6"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_NODE
argument_list|(
name|_net_inet6
argument_list|,
name|IPPROTO_UDP
argument_list|,
name|udp6
argument_list|,
name|CTLFLAG_RW
argument_list|,
literal|0
argument_list|,
literal|"UDP6"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_NODE
argument_list|(
name|_net_inet6
argument_list|,
name|IPPROTO_TCP
argument_list|,
name|tcp6
argument_list|,
name|CTLFLAG_RW
argument_list|,
literal|0
argument_list|,
literal|"TCP6"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|IPSEC
end_ifdef

begin_expr_stmt
name|SYSCTL_NODE
argument_list|(
name|_net_inet6
argument_list|,
name|IPPROTO_ESP
argument_list|,
name|ipsec6
argument_list|,
name|CTLFLAG_RW
argument_list|,
literal|0
argument_list|,
literal|"IPSEC6"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IPSEC */
end_comment

begin_comment
comment|/* net.inet6.ip6 */
end_comment

begin_function
specifier|static
name|int
name|sysctl_ip6_forwarding
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
block|{
name|int
name|error
init|=
literal|0
decl_stmt|;
name|int
name|old_ip6_forwarding
decl_stmt|;
name|int
name|changed
decl_stmt|;
name|error
operator|=
name|SYSCTL_OUT
argument_list|(
name|req
argument_list|,
name|arg1
argument_list|,
sizeof|sizeof
argument_list|(
name|int
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|||
operator|!
name|req
operator|->
name|newptr
condition|)
return|return
operator|(
name|error
operator|)
return|;
name|old_ip6_forwarding
operator|=
name|ip6_forwarding
expr_stmt|;
name|error
operator|=
name|SYSCTL_IN
argument_list|(
name|req
argument_list|,
name|arg1
argument_list|,
sizeof|sizeof
argument_list|(
name|int
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|!=
literal|0
condition|)
return|return
operator|(
name|error
operator|)
return|;
name|changed
operator|=
operator|(
name|ip6_forwarding
condition|?
literal|1
else|:
literal|0
operator|)
operator|^
operator|(
name|old_ip6_forwarding
condition|?
literal|1
else|:
literal|0
operator|)
expr_stmt|;
if|if
condition|(
name|changed
operator|==
literal|0
condition|)
return|return
operator|(
name|error
operator|)
return|;
comment|/* 	 * XXX while host->router removes prefix got from RA, 	 * router->host case nukes all the prefixes managed by in6_prefix.c 	 * (both RR and static).  therefore, switching from host->router->host 	 * will remove statically configured addresses/prefixes. 	 * not sure if it is intended behavior or not. 	 */
if|if
condition|(
name|ip6_forwarding
operator|!=
literal|0
condition|)
block|{
comment|/* host becomes router */
name|int
name|s
init|=
name|splnet
argument_list|()
decl_stmt|;
name|struct
name|nd_prefix
modifier|*
name|pr
decl_stmt|,
modifier|*
name|next
decl_stmt|;
for|for
control|(
name|pr
operator|=
name|nd_prefix
operator|.
name|lh_first
init|;
name|pr
condition|;
name|pr
operator|=
name|next
control|)
block|{
name|next
operator|=
name|pr
operator|->
name|ndpr_next
expr_stmt|;
if|if
condition|(
operator|!
name|IN6_IS_ADDR_UNSPECIFIED
argument_list|(
operator|&
name|pr
operator|->
name|ndpr_addr
argument_list|)
condition|)
name|in6_ifdel
argument_list|(
name|pr
operator|->
name|ndpr_ifp
argument_list|,
operator|&
name|pr
operator|->
name|ndpr_addr
argument_list|)
expr_stmt|;
name|prelist_remove
argument_list|(
name|pr
argument_list|)
expr_stmt|;
block|}
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* router becomes host */
while|while
condition|(
operator|!
name|LIST_EMPTY
argument_list|(
operator|&
name|rr_prefix
argument_list|)
condition|)
name|delete_each_prefix
argument_list|(
name|LIST_FIRST
argument_list|(
operator|&
name|rr_prefix
argument_list|)
argument_list|,
name|PR_ORIG_KERNEL
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|sysctl_icmp6_ratelimit
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
block|{
name|int
name|rate_usec
decl_stmt|,
name|error
decl_stmt|,
name|s
decl_stmt|;
comment|/* 	 * The sysctl specifies the rate in usec-between-icmp, 	 * so we must convert from/to a timeval. 	 */
name|rate_usec
operator|=
operator|(
name|icmp6errratelim
operator|.
name|tv_sec
operator|*
literal|1000000
operator|)
operator|+
name|icmp6errratelim
operator|.
name|tv_usec
expr_stmt|;
name|error
operator|=
name|sysctl_handle_int
argument_list|(
name|oidp
argument_list|,
operator|&
name|rate_usec
argument_list|,
literal|0
argument_list|,
name|req
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
return|return
operator|(
name|error
operator|)
return|;
if|if
condition|(
name|rate_usec
operator|<
literal|0
condition|)
return|return
operator|(
name|EINVAL
operator|)
return|;
name|s
operator|=
name|splnet
argument_list|()
expr_stmt|;
name|icmp6errratelim
operator|.
name|tv_sec
operator|=
name|rate_usec
operator|/
literal|1000000
expr_stmt|;
name|icmp6errratelim
operator|.
name|tv_usec
operator|=
name|rate_usec
operator|%
literal|1000000
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|SYSCTL_OID
argument_list|(
name|_net_inet6_ip6
argument_list|,
name|IPV6CTL_FORWARDING
argument_list|,
name|forwarding
argument_list|,
name|CTLTYPE_INT
operator||
name|CTLFLAG_RW
argument_list|,
operator|&
name|ip6_forwarding
argument_list|,
literal|0
argument_list|,
name|sysctl_ip6_forwarding
argument_list|,
literal|"I"
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_net_inet6_ip6
argument_list|,
name|IPV6CTL_SENDREDIRECTS
argument_list|,
name|redirect
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|ip6_sendredirects
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_net_inet6_ip6
argument_list|,
name|IPV6CTL_DEFHLIM
argument_list|,
name|hlim
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|ip6_defhlim
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_net_inet6_ip6
argument_list|,
name|IPV6CTL_MAXFRAGPACKETS
argument_list|,
name|maxfragpackets
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|ip6_maxfragpackets
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_net_inet6_ip6
argument_list|,
name|IPV6CTL_ACCEPT_RTADV
argument_list|,
name|accept_rtadv
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|ip6_accept_rtadv
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_net_inet6_ip6
argument_list|,
name|IPV6CTL_KEEPFAITH
argument_list|,
name|keepfaith
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|ip6_keepfaith
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_net_inet6_ip6
argument_list|,
name|IPV6CTL_LOG_INTERVAL
argument_list|,
name|log_interval
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|ip6_log_interval
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_net_inet6_ip6
argument_list|,
name|IPV6CTL_HDRNESTLIMIT
argument_list|,
name|hdrnestlimit
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|ip6_hdrnestlimit
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_net_inet6_ip6
argument_list|,
name|IPV6CTL_DAD_COUNT
argument_list|,
name|dad_count
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|ip6_dad_count
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_net_inet6_ip6
argument_list|,
name|IPV6CTL_AUTO_FLOWLABEL
argument_list|,
name|auto_flowlabel
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|ip6_auto_flowlabel
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_net_inet6_ip6
argument_list|,
name|IPV6CTL_DEFMCASTHLIM
argument_list|,
name|defmcasthlim
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|ip6_defmcasthlim
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_net_inet6_ip6
argument_list|,
name|IPV6CTL_GIF_HLIM
argument_list|,
name|gifhlim
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|ip6_gif_hlim
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_STRING
argument_list|(
name|_net_inet6_ip6
argument_list|,
name|IPV6CTL_KAME_VERSION
argument_list|,
name|kame_version
argument_list|,
name|CTLFLAG_RD
argument_list|,
name|__KAME_VERSION
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_net_inet6_ip6
argument_list|,
name|IPV6CTL_USE_DEPRECATED
argument_list|,
name|use_deprecated
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|ip6_use_deprecated
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_net_inet6_ip6
argument_list|,
name|IPV6CTL_RR_PRUNE
argument_list|,
name|rr_prune
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|ip6_rr_prune
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_net_inet6_ip6
argument_list|,
name|IPV6CTL_MAPPED_ADDR
argument_list|,
name|mapped_addr
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|ip6_mapped_addr_on
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* net.inet6.icmp6 */
end_comment

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_net_inet6_icmp6
argument_list|,
name|ICMPV6CTL_REDIRACCEPT
argument_list|,
name|rediraccept
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|icmp6_rediraccept
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_net_inet6_icmp6
argument_list|,
name|ICMPV6CTL_REDIRTIMEOUT
argument_list|,
name|redirtimeout
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|icmp6_redirtimeout
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_STRUCT
argument_list|(
name|_net_inet6_icmp6
argument_list|,
name|ICMPV6CTL_STATS
argument_list|,
name|stats
argument_list|,
name|CTLFLAG_RD
argument_list|,
operator|&
name|icmp6stat
argument_list|,
name|icmp6stat
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_PROC
argument_list|(
name|_net_inet6_icmp6
argument_list|,
name|ICMPV6CTL_ERRRATELIMIT
argument_list|,
name|errratelimit
argument_list|,
name|CTLTYPE_INT
operator||
name|CTLFLAG_RW
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|int
argument_list|)
argument_list|,
name|sysctl_icmp6_ratelimit
argument_list|,
literal|"I"
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_net_inet6_icmp6
argument_list|,
name|ICMPV6CTL_ND6_PRUNE
argument_list|,
name|nd6_prune
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|nd6_prune
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_net_inet6_icmp6
argument_list|,
name|ICMPV6CTL_ND6_DELAY
argument_list|,
name|nd6_delay
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|nd6_delay
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_net_inet6_icmp6
argument_list|,
name|ICMPV6CTL_ND6_UMAXTRIES
argument_list|,
name|nd6_umaxtries
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|nd6_umaxtries
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_net_inet6_icmp6
argument_list|,
name|ICMPV6CTL_ND6_MMAXTRIES
argument_list|,
name|nd6_mmaxtries
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|nd6_mmaxtries
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_net_inet6_icmp6
argument_list|,
name|ICMPV6CTL_ND6_USELOOPBACK
argument_list|,
name|nd6_useloopback
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|nd6_useloopback
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_net_inet6_icmp6
argument_list|,
name|ICMPV6CTL_NODEINFO
argument_list|,
name|nodeinfo
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|icmp6_nodeinfo
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_net_inet6_icmp6
argument_list|,
name|ICMPV6CTL_ERRPPSLIMIT
argument_list|,
name|errppslimit
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|icmp6errppslim
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_net_inet6_icmp6
argument_list|,
name|ICMPV6CTL_ND6_MAXNUDHINT
argument_list|,
name|nd6_maxnudhint
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|nd6_maxnudhint
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

