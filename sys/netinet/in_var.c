begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id$  */
end_comment

begin_comment
comment|/*  * This file attempts to centralize all the various variables that have  * a hand in controlling the operation of IP and its ULPs.  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"systm.h"
end_include

begin_include
include|#
directive|include
file|"mbuf.h"
end_include

begin_include
include|#
directive|include
file|"domain.h"
end_include

begin_include
include|#
directive|include
file|"protosw.h"
end_include

begin_include
include|#
directive|include
file|"socket.h"
end_include

begin_include
include|#
directive|include
file|"time.h"
end_include

begin_include
include|#
directive|include
file|"net/if.h"
end_include

begin_include
include|#
directive|include
file|"net/route.h"
end_include

begin_include
include|#
directive|include
file|"in.h"
end_include

begin_include
include|#
directive|include
file|"in_systm.h"
end_include

begin_include
include|#
directive|include
file|"ip.h"
end_include

begin_include
include|#
directive|include
file|"in_pcb.h"
end_include

begin_include
include|#
directive|include
file|"in_var.h"
end_include

begin_include
include|#
directive|include
file|"ip_var.h"
end_include

begin_include
include|#
directive|include
file|"ip_icmp.h"
end_include

begin_include
include|#
directive|include
file|"icmp_var.h"
end_include

begin_comment
comment|/*  * IPFORWARDING controls whether the IP layer will forward packets received  * by us but not addressed to one of our addresses.  *  * IPSENDREDIRECTS controls whether the IP layer will send ICMP Redirect  * messages.  *  * GATEWAY turns both of these on, and also allocates more memory for some  * networking functions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IPFORWARDING
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|GATEWAY
end_ifdef

begin_define
define|#
directive|define
name|IPFORWARDING
value|1
end_define

begin_comment
comment|/* forward IP packets not for us */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not GATEWAY */
end_comment

begin_define
define|#
directive|define
name|IPFORWARDING
value|0
end_define

begin_comment
comment|/* don't forward IP packets not for us */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not GATEWAY */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not IPFORWARDING */
end_comment

begin_comment
comment|/*  * NB: RFC 1122, ``Requirements for Internet Hosts: Communication Layers'',  * absolutely forbids hosts (which are not acting as gateways) from sending  * ICMP redirects.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IPSENDREDIRECTS
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|GATEWAY
end_ifdef

begin_define
define|#
directive|define
name|IPSENDREDIRECTS
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not GATEWAY */
end_comment

begin_define
define|#
directive|define
name|IPSENDREDIRECTS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not GATEWAY */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not IPSENDREDIRECTS */
end_comment

begin_decl_stmt
name|int
name|ipforwarding
init|=
name|IPFORWARDING
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ipsendredirects
init|=
name|IPSENDREDIRECTS
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DIAGNOSTIC
end_ifdef

begin_decl_stmt
name|int
name|ipprintfs
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * ip_protox[] maps from IP protocol number to an index in inetsw[].  */
end_comment

begin_decl_stmt
name|u_char
name|ip_protox
index|[
name|IPPROTO_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * ipqmaxlen is the maximum length of the IP input queue.  * ipintrq is the queue itself.  */
end_comment

begin_decl_stmt
name|struct
name|ifqueue
name|ipintrq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ipqmaxlen
init|=
name|IFQ_MAXLEN
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * the IP reassembly queue  */
end_comment

begin_decl_stmt
name|struct
name|ipq
name|ipq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * in_ifaddr points to a linked list of IP interface addresses, managed  * by the code in in.c.  */
end_comment

begin_decl_stmt
name|struct
name|in_ifaddr
modifier|*
name|in_ifaddr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* first inet address */
end_comment

begin_comment
comment|/*  * statistics for netstat and management  */
end_comment

begin_decl_stmt
name|struct
name|ipstat
name|ipstat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * ip_id is the next IP packet id number to be assigned (used in fragmentation  * and reassembly).  */
end_comment

begin_decl_stmt
name|u_short
name|ip_id
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * When acting as a gateway, the IP layer keeps track of how many packets  * are forwarded for each (in-ifp, out-ifp) pair.  This code needs to get  * updated or junked now that interfaces can come and go like the wind.  * (in ip_input.c)  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GATEWAY
end_ifdef

begin_decl_stmt
name|u_long
modifier|*
name|ip_ifmatrix
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * ipaddr is a sockaddr_in used by various bits of code when they  * need to convert a `struct in_addr' to a `struct sockaddr_in'.  *  * ipforward_rt is a route used when forwarding packets.  It functions  * as a route cache of order one, if you want to think of it that way.  */
end_comment

begin_decl_stmt
name|struct
name|sockaddr_in
name|ipaddr
init|=
block|{
sizeof|sizeof
argument_list|(
name|ipaddr
argument_list|)
block|,
name|AF_INET
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|route
name|ipforward_rt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * inetctlerrmap[] maps control input commands to errno values.  0 means  * don't signal error.  */
end_comment

begin_decl_stmt
name|u_char
name|inetctlerrmap
index|[
name|PRC_NCMDS
index|]
init|=
block|{
literal|0
block|,
comment|/* ifdown */
literal|0
block|,
comment|/* routedead */
literal|0
block|,
comment|/* #2 */
literal|0
block|,
comment|/* quench2 */
literal|0
block|,
comment|/* quench */
name|EMSGSIZE
block|,
comment|/* msgsize */
name|EHOSTDOWN
block|,
comment|/* hostdead */
name|EHOSTUNREACH
block|,
comment|/* hostunreach */
name|EHOSTUNREACH
block|,
comment|/* unreachnet */
name|EHOSTUNREACH
block|,
comment|/* unreachhost */
name|ECONNREFUSED
block|,
comment|/* unreachproto */
name|ECONNREFUSED
block|,
comment|/* unreachport */
name|EMSGSIZE
block|,
comment|/* old needfrag */
name|EHOSTUNREACH
block|,
comment|/* srcfail */
name|EHOSTUNREACH
block|,
comment|/* netunknown */
name|EHOSTUNREACH
block|,
comment|/* hostunknown */
name|EHOSTUNREACH
block|,
comment|/* isolated */
name|ECONNREFUSED
block|,
comment|/* net admin. prohibited */
name|ECONNREFUSED
block|,
comment|/* host admin. prohibited */
name|EHOSTUNREACH
block|,
comment|/* tos net unreachable */
name|EHOSTUNREACH
block|,
comment|/* tos host unreachable */
literal|0
block|,
comment|/* redirect net */
literal|0
block|,
comment|/* redirect host */
literal|0
block|,
comment|/* redirect tosnet */
literal|0
block|,
comment|/* redirect toshost */
literal|0
block|,
comment|/* time exceeded */
literal|0
block|,
comment|/* reassembly timeout */
name|ENOPROTOOPT
block|,
comment|/* parameter problem */
name|ENOPROTOOPT
block|,
comment|/* required option missing */
literal|0
block|,
comment|/* MTU changed */
comment|/* NB: this means that this error will only 	   get propagated by in_mtunotify(), which 	   doesn't bother to check. */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * SUBNETSARELOCAL determines where IP subnets are considered to be ``local''  * or not.  This option is obsolete.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SUBNETSARELOCAL
end_ifndef

begin_define
define|#
directive|define
name|SUBNETSARELOCAL
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|subnetsarelocal
init|=
name|SUBNETSARELOCAL
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|MTUDISC
end_ifdef

begin_comment
comment|/*  * MTUTIMER1 is the number of minutes to wait after having incremented  * the MTU estimate before trying again.  MTUTIMER2 is the number  * of minutes to wait after having decremented the MTU estimate  * before trying to increment it.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MTUTIMER1
end_ifndef

begin_define
define|#
directive|define
name|MTUTIMER1
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|in_mtutimer1
init|=
name|MTUTIMER1
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|MTUTIMER2
end_ifndef

begin_define
define|#
directive|define
name|MTUTIMER2
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|in_mtutimer2
init|=
name|MTUTIMER2
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MTUDISC */
end_comment

begin_comment
comment|/*  * and a zero in_addr to make some code happy...  */
end_comment

begin_decl_stmt
name|struct
name|in_addr
name|zeroin_addr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * ICMPPRINTFS enables some debugging printfs in ip_icmp.c.  *  * IPBROADCASTECHO controls whether ICMP Echo Reply packets are sent  * in response to ICMP Echo packets which were addressed to a multicast  * or broadcast address.  *  * IPMASKAGENT controls whether ICMP Mask Reply packets are sent.  * It should only be enabled on the machine which is the authoritative  * mask agent for a subnet.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ICMPPRINTFS
end_ifdef

begin_decl_stmt
name|int
name|icmpprintfs
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPBROADCASTECHO
end_ifndef

begin_define
define|#
directive|define
name|IPBROADCASTECHO
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|ipbroadcastecho
init|=
name|IPBROADCASTECHO
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|IPMASKAGENT
end_ifndef

begin_define
define|#
directive|define
name|IPMASKAGENT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|ipmaskagent
init|=
name|IPMASKAGENT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * ICMP statistics  */
end_comment

begin_decl_stmt
name|struct
name|icmpstat
name|icmpstat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Yet Another sockaddr_in filled in by various routines when convenient.  */
end_comment

begin_decl_stmt
name|struct
name|sockaddr_in
name|icmpmask
init|=
block|{
literal|8
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Print out TCP debugging messages on the console.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TCPDEBUG
end_ifdef

begin_decl_stmt
name|int
name|tcpconsdebug
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"tcp.h"
end_include

begin_include
include|#
directive|include
file|"tcp_fsm.h"
end_include

begin_include
include|#
directive|include
file|"tcp_seq.h"
end_include

begin_include
include|#
directive|include
file|"tcp_timer.h"
end_include

begin_include
include|#
directive|include
file|"tcp_var.h"
end_include

begin_include
include|#
directive|include
file|"tcpip.h"
end_include

begin_comment
comment|/*  * tcp_ttl is the default IP TTL for TCP segments.  * tcp_mssdflt is the default max segment size.  * tcp_rttdflt is the initial round trip time estimate when there is no RTT  * in the route.  */
end_comment

begin_decl_stmt
name|int
name|tcp_ttl
init|=
name|TCP_TTL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tcp_mssdflt
init|=
name|TCP_MSS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tcp_rttdflt
init|=
name|TCPTV_SRTTDFLT
operator|/
name|PR_SLOWHZ
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * When KPROF is defined (god only knows why), TCP keeps track of  * protocol requests in this matrix.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KPROF
end_ifdef

begin_decl_stmt
name|int
name|tcp_acounts
index|[
name|TCP_NSTATES
index|]
index|[
name|PRU_NREQ
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * tcp_keepidle is the a fraction of the length of non-response time in a   * in a keepalive situation after which TCP abandons the connection.  *  * tcp_keepintvl is the interval between keepalives.  *  * tcp_maxidle is the time after which a connection will be dropped in  * certain states.  It is computed as `TCPTV_KEEPCNT * tcp_keepintvl'.  */
end_comment

begin_decl_stmt
name|int
name|tcp_keepidle
init|=
name|TCPTV_KEEP_IDLE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tcp_keepintvl
init|=
name|TCPTV_KEEPINTVL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tcp_maxidle
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * tcp_sendspace and tcp_recvspace are the default send and receive window  * sizes, respectively.  These are obsolescent (this information should  * be set by the route).  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TCP_SMALLSPACE
end_ifdef

begin_decl_stmt
name|u_long
name|tcp_sendspace
init|=
literal|1024
operator|*
literal|4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_long
name|tcp_recvspace
init|=
literal|1024
operator|*
literal|4
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|u_long
name|tcp_sendspace
init|=
literal|1024
operator|*
literal|16
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_long
name|tcp_recvspace
init|=
literal|1024
operator|*
literal|16
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TCP_SMALLSPACE */
end_comment

begin_include
include|#
directive|include
file|"udp.h"
end_include

begin_include
include|#
directive|include
file|"udp_var.h"
end_include

begin_comment
comment|/*  * udpcksum tells whether to do UDP checksums.  It should always be  * turned on, except as required for compatibility with ancient  * 4.2-based systems like SunOS 3.5 and Ultrix 2.0.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COMPAT_42
end_ifndef

begin_decl_stmt
name|int
name|udpcksum
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|udpcksum
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * udp_ttl is the default IP TTL for UDP packets.  */
end_comment

begin_decl_stmt
name|int
name|udp_ttl
init|=
name|UDP_TTL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * UDP statistics for netstat.  */
end_comment

begin_decl_stmt
name|struct
name|udpstat
name|udpstat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * udp_sendspace is the maximum datagram size the UDP layer is willing to  * attempt to transmit.  *  * udp_recvspace is the amount of buffer space the UDP layer will  * reserve for holding received packets.  */
end_comment

begin_decl_stmt
name|u_long
name|udp_sendspace
init|=
literal|9216
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* really max datagram size */
end_comment

begin_decl_stmt
name|u_long
name|udp_recvspace
init|=
literal|40
operator|*
operator|(
literal|1024
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|sockaddr_in
argument_list|)
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 40 1K datagrams */
end_comment

end_unit

