begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Mark Johnston<markj@FreeBSD.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"opt_kdtrace.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/sdt.h>
end_include

begin_expr_stmt
name|SDT_PROVIDER_DEFINE
argument_list|(
name|ip
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROVIDER_DEFINE
argument_list|(
name|tcp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROVIDER_DEFINE
argument_list|(
name|udp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DEFINE6_XLATE
argument_list|(
name|ip
argument_list|, , ,
name|receive
argument_list|,
literal|"void *"
argument_list|,
literal|"pktinfo_t *"
argument_list|,
literal|"void *"
argument_list|,
literal|"csinfo_t *"
argument_list|,
literal|"uint8_t *"
argument_list|,
literal|"ipinfo_t *"
argument_list|,
literal|"struct ifnet *"
argument_list|,
literal|"ifinfo_t *"
argument_list|,
literal|"struct ip *"
argument_list|,
literal|"ipv4info_t *"
argument_list|,
literal|"struct ip6_hdr *"
argument_list|,
literal|"ipv6info_t *"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DEFINE6_XLATE
argument_list|(
name|ip
argument_list|, , ,
name|send
argument_list|,
literal|"void *"
argument_list|,
literal|"pktinfo_t *"
argument_list|,
literal|"void *"
argument_list|,
literal|"csinfo_t *"
argument_list|,
literal|"uint8_t *"
argument_list|,
literal|"ipinfo_t *"
argument_list|,
literal|"struct ifnet *"
argument_list|,
literal|"ifinfo_t *"
argument_list|,
literal|"struct ip *"
argument_list|,
literal|"ipv4info_t *"
argument_list|,
literal|"struct ip6_hdr *"
argument_list|,
literal|"ipv6info_t *"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DEFINE5_XLATE
argument_list|(
name|tcp
argument_list|, , ,
name|accept__established
argument_list|,
literal|"void *"
argument_list|,
literal|"pktinfo_t *"
argument_list|,
literal|"struct tcpcb *"
argument_list|,
literal|"csinfo_t *"
argument_list|,
literal|"struct mbuf *"
argument_list|,
literal|"ipinfo_t *"
argument_list|,
literal|"struct tcpcb *"
argument_list|,
literal|"tcpsinfo_t *"
argument_list|,
literal|"struct tcphdr *"
argument_list|,
literal|"tcpinfoh_t *"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DEFINE5_XLATE
argument_list|(
name|tcp
argument_list|, , ,
name|accept__refused
argument_list|,
literal|"void *"
argument_list|,
literal|"pktinfo_t *"
argument_list|,
literal|"struct tcpcb *"
argument_list|,
literal|"csinfo_t *"
argument_list|,
literal|"struct mbuf *"
argument_list|,
literal|"ipinfo_t *"
argument_list|,
literal|"struct tcpcb *"
argument_list|,
literal|"tcpsinfo_t *"
argument_list|,
literal|"struct tcphdr *"
argument_list|,
literal|"tcpinfo_t *"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DEFINE5_XLATE
argument_list|(
name|tcp
argument_list|, , ,
name|connect__established
argument_list|,
literal|"void *"
argument_list|,
literal|"pktinfo_t *"
argument_list|,
literal|"struct tcpcb *"
argument_list|,
literal|"csinfo_t *"
argument_list|,
literal|"struct mbuf *"
argument_list|,
literal|"ipinfo_t *"
argument_list|,
literal|"struct tcpcb *"
argument_list|,
literal|"tcpsinfo_t *"
argument_list|,
literal|"struct tcphdr *"
argument_list|,
literal|"tcpinfoh_t *"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DEFINE5_XLATE
argument_list|(
name|tcp
argument_list|, , ,
name|connect__refused
argument_list|,
literal|"void *"
argument_list|,
literal|"pktinfo_t *"
argument_list|,
literal|"struct tcpcb *"
argument_list|,
literal|"csinfo_t *"
argument_list|,
literal|"struct mbuf *"
argument_list|,
literal|"ipinfo_t *"
argument_list|,
literal|"struct tcpcb *"
argument_list|,
literal|"tcpsinfo_t *"
argument_list|,
literal|"struct tcphdr *"
argument_list|,
literal|"tcpinfoh_t *"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DEFINE5_XLATE
argument_list|(
name|tcp
argument_list|, , ,
name|connect__request
argument_list|,
literal|"void *"
argument_list|,
literal|"pktinfo_t *"
argument_list|,
literal|"struct tcpcb *"
argument_list|,
literal|"csinfo_t *"
argument_list|,
literal|"uint8_t *"
argument_list|,
literal|"ipinfo_t *"
argument_list|,
literal|"struct tcpcb *"
argument_list|,
literal|"tcpsinfo_t *"
argument_list|,
literal|"struct tcphdr *"
argument_list|,
literal|"tcpinfo_t *"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DEFINE5_XLATE
argument_list|(
name|tcp
argument_list|, , ,
name|receive
argument_list|,
literal|"void *"
argument_list|,
literal|"pktinfo_t *"
argument_list|,
literal|"struct tcpcb *"
argument_list|,
literal|"csinfo_t *"
argument_list|,
literal|"struct mbuf *"
argument_list|,
literal|"ipinfo_t *"
argument_list|,
literal|"struct tcpcb *"
argument_list|,
literal|"tcpsinfo_t *"
argument_list|,
literal|"struct tcphdr *"
argument_list|,
literal|"tcpinfoh_t *"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DEFINE5_XLATE
argument_list|(
name|tcp
argument_list|, , ,
name|send
argument_list|,
literal|"void *"
argument_list|,
literal|"pktinfo_t *"
argument_list|,
literal|"struct tcpcb *"
argument_list|,
literal|"csinfo_t *"
argument_list|,
literal|"uint8_t *"
argument_list|,
literal|"ipinfo_t *"
argument_list|,
literal|"struct tcpcb *"
argument_list|,
literal|"tcpsinfo_t *"
argument_list|,
literal|"struct tcphdr *"
argument_list|,
literal|"tcpinfo_t *"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DEFINE6_XLATE
argument_list|(
name|tcp
argument_list|, , ,
name|state__change
argument_list|,
literal|"void *"
argument_list|,
literal|"void *"
argument_list|,
literal|"struct tcpcb *"
argument_list|,
literal|"csinfo_t *"
argument_list|,
literal|"void *"
argument_list|,
literal|"void *"
argument_list|,
literal|"struct tcpcb *"
argument_list|,
literal|"tcpsinfo_t *"
argument_list|,
literal|"void *"
argument_list|,
literal|"void *"
argument_list|,
literal|"int"
argument_list|,
literal|"tcplsinfo_t *"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DEFINE6_XLATE
argument_list|(
name|tcp
argument_list|, , ,
name|receive__autoresize
argument_list|,
literal|"void *"
argument_list|,
literal|"void *"
argument_list|,
literal|"struct tcpcb *"
argument_list|,
literal|"csinfo_t *"
argument_list|,
literal|"struct mbuf *"
argument_list|,
literal|"ipinfo_t *"
argument_list|,
literal|"struct tcpcb *"
argument_list|,
literal|"tcpsinfo_t *"
argument_list|,
literal|"struct tcphdr *"
argument_list|,
literal|"tcpinfoh_t *"
argument_list|,
literal|"int"
argument_list|,
literal|"int"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DEFINE5_XLATE
argument_list|(
name|udp
argument_list|, , ,
name|receive
argument_list|,
literal|"void *"
argument_list|,
literal|"pktinfo_t *"
argument_list|,
literal|"struct inpcb *"
argument_list|,
literal|"csinfo_t *"
argument_list|,
literal|"uint8_t *"
argument_list|,
literal|"ipinfo_t *"
argument_list|,
literal|"struct inpcb *"
argument_list|,
literal|"udpsinfo_t *"
argument_list|,
literal|"struct udphdr *"
argument_list|,
literal|"udpinfo_t *"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DEFINE5_XLATE
argument_list|(
name|udp
argument_list|, , ,
name|send
argument_list|,
literal|"void *"
argument_list|,
literal|"pktinfo_t *"
argument_list|,
literal|"struct inpcb *"
argument_list|,
literal|"csinfo_t *"
argument_list|,
literal|"uint8_t *"
argument_list|,
literal|"ipinfo_t *"
argument_list|,
literal|"struct inpcb *"
argument_list|,
literal|"udpsinfo_t *"
argument_list|,
literal|"struct udphdr *"
argument_list|,
literal|"udpinfo_t *"
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

