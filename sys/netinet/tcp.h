begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)tcp.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_TCP_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_TCP_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_typedef
typedef|typedef
name|u_int32_t
name|tcp_seq
typedef|;
end_typedef

begin_define
define|#
directive|define
name|tcp6_seq
value|tcp_seq
end_define

begin_comment
comment|/* for KAME src sync over BSD*'s */
end_comment

begin_define
define|#
directive|define
name|tcp6hdr
value|tcphdr
end_define

begin_comment
comment|/* for KAME src sync over BSD*'s */
end_comment

begin_comment
comment|/*  * TCP header.  * Per RFC 793, September, 1981.  */
end_comment

begin_struct
struct|struct
name|tcphdr
block|{
name|u_short
name|th_sport
decl_stmt|;
comment|/* source port */
name|u_short
name|th_dport
decl_stmt|;
comment|/* destination port */
name|tcp_seq
name|th_seq
decl_stmt|;
comment|/* sequence number */
name|tcp_seq
name|th_ack
decl_stmt|;
comment|/* acknowledgement number */
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
name|u_int
name|th_x2
range|:
literal|4
decl_stmt|,
comment|/* (unused) */
name|th_off
range|:
literal|4
decl_stmt|;
comment|/* data offset */
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_int
name|th_off
range|:
literal|4
decl_stmt|,
comment|/* data offset */
name|th_x2
range|:
literal|4
decl_stmt|;
comment|/* (unused) */
endif|#
directive|endif
name|u_char
name|th_flags
decl_stmt|;
define|#
directive|define
name|TH_FIN
value|0x01
define|#
directive|define
name|TH_SYN
value|0x02
define|#
directive|define
name|TH_RST
value|0x04
define|#
directive|define
name|TH_PUSH
value|0x08
define|#
directive|define
name|TH_ACK
value|0x10
define|#
directive|define
name|TH_URG
value|0x20
define|#
directive|define
name|TH_ECE
value|0x40
define|#
directive|define
name|TH_CWR
value|0x80
define|#
directive|define
name|TH_FLAGS
value|(TH_FIN|TH_SYN|TH_RST|TH_PUSH|TH_ACK|TH_URG|TH_ECE|TH_CWR)
name|u_short
name|th_win
decl_stmt|;
comment|/* window */
name|u_short
name|th_sum
decl_stmt|;
comment|/* checksum */
name|u_short
name|th_urp
decl_stmt|;
comment|/* urgent pointer */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TCPOPT_EOL
value|0
end_define

begin_define
define|#
directive|define
name|TCPOPT_NOP
value|1
end_define

begin_define
define|#
directive|define
name|TCPOPT_MAXSEG
value|2
end_define

begin_define
define|#
directive|define
name|TCPOLEN_MAXSEG
value|4
end_define

begin_define
define|#
directive|define
name|TCPOPT_WINDOW
value|3
end_define

begin_define
define|#
directive|define
name|TCPOLEN_WINDOW
value|3
end_define

begin_define
define|#
directive|define
name|TCPOPT_SACK_PERMITTED
value|4
end_define

begin_comment
comment|/* Experimental */
end_comment

begin_define
define|#
directive|define
name|TCPOLEN_SACK_PERMITTED
value|2
end_define

begin_define
define|#
directive|define
name|TCPOPT_SACK
value|5
end_define

begin_comment
comment|/* Experimental */
end_comment

begin_define
define|#
directive|define
name|TCPOLEN_SACK
value|8
end_define

begin_comment
comment|/* 2*sizeof(tcp_seq) */
end_comment

begin_define
define|#
directive|define
name|TCPOPT_TIMESTAMP
value|8
end_define

begin_define
define|#
directive|define
name|TCPOLEN_TIMESTAMP
value|10
end_define

begin_define
define|#
directive|define
name|TCPOLEN_TSTAMP_APPA
value|(TCPOLEN_TIMESTAMP+2)
end_define

begin_comment
comment|/* appendix A */
end_comment

begin_define
define|#
directive|define
name|TCPOPT_TSTAMP_HDR
define|\
value|(TCPOPT_NOP<<24|TCPOPT_NOP<<16|TCPOPT_TIMESTAMP<<8|TCPOLEN_TIMESTAMP)
end_define

begin_define
define|#
directive|define
name|MAX_TCPOPTLEN
value|40
end_define

begin_comment
comment|/* Absolute maximum TCP options len */
end_comment

begin_define
define|#
directive|define
name|TCPOPT_SIGNATURE
value|19
end_define

begin_comment
comment|/* Keyed MD5: RFC 2385 */
end_comment

begin_define
define|#
directive|define
name|TCPOLEN_SIGNATURE
value|18
end_define

begin_comment
comment|/* Option definitions */
end_comment

begin_define
define|#
directive|define
name|TCPOPT_SACK_PERMIT_HDR
define|\
value|(TCPOPT_NOP<<24|TCPOPT_NOP<<16|TCPOPT_SACK_PERMITTED<<8|TCPOLEN_SACK_PERMITTED)
end_define

begin_define
define|#
directive|define
name|TCPOPT_SACK_HDR
value|(TCPOPT_NOP<<24|TCPOPT_NOP<<16|TCPOPT_SACK<<8)
end_define

begin_comment
comment|/* Miscellaneous constants */
end_comment

begin_define
define|#
directive|define
name|MAX_SACK_BLKS
value|6
end_define

begin_comment
comment|/* Max # SACK blocks stored at receiver side */
end_comment

begin_define
define|#
directive|define
name|TCP_MAX_SACK
value|4
end_define

begin_comment
comment|/* MAX # SACKs sent in any segment */
end_comment

begin_comment
comment|/*  * Default maximum segment size for TCP.  * With an IP MTU of 576, this is 536,  * but 512 is probably more convenient.  * This should be defined as MIN(512, IP_MSS - sizeof (struct tcpiphdr)).  */
end_comment

begin_define
define|#
directive|define
name|TCP_MSS
value|512
end_define

begin_comment
comment|/*  * TCP_MINMSS is defined to be 216 which is fine for the smallest  * link MTU (256 bytes, AX.25 packet radio) in the Internet.  * However it is very unlikely to come across such low MTU interfaces  * these days (anno dato 2003).  * See tcp_subr.c tcp_minmss SYSCTL declaration for more comments.  * Setting this to "0" disables the minmss check.  */
end_comment

begin_define
define|#
directive|define
name|TCP_MINMSS
value|216
end_define

begin_comment
comment|/*  * TCP_MINMSSOVERLOAD is defined to be 1000 which should cover any type  * of interactive TCP session.  * See tcp_subr.c tcp_minmssoverload SYSCTL declaration and tcp_input.c  * for more comments.  * Setting this to "0" disables the minmssoverload check.  */
end_comment

begin_define
define|#
directive|define
name|TCP_MINMSSOVERLOAD
value|0
end_define

begin_comment
comment|/* XXX: Disabled until refined */
end_comment

begin_comment
comment|/*  * Default maximum segment size for TCP6.  * With an IP6 MSS of 1280, this is 1220,  * but 1024 is probably more convenient. (xxx kazu in doubt)  * This should be defined as MIN(1024, IP6_MSS - sizeof (struct tcpip6hdr))  */
end_comment

begin_define
define|#
directive|define
name|TCP6_MSS
value|1024
end_define

begin_define
define|#
directive|define
name|TCP_MAXWIN
value|65535
end_define

begin_comment
comment|/* largest value for (unscaled) window */
end_comment

begin_define
define|#
directive|define
name|TTCP_CLIENT_SND_WND
value|4096
end_define

begin_comment
comment|/* dflt send window for T/TCP client */
end_comment

begin_define
define|#
directive|define
name|TCP_MAX_WINSHIFT
value|14
end_define

begin_comment
comment|/* maximum window shift */
end_comment

begin_define
define|#
directive|define
name|TCP_MAXBURST
value|4
end_define

begin_comment
comment|/* maximum segments in a burst */
end_comment

begin_define
define|#
directive|define
name|TCP_MAXHLEN
value|(0xf<<2)
end_define

begin_comment
comment|/* max length of header in bytes */
end_comment

begin_define
define|#
directive|define
name|TCP_MAXOLEN
value|(TCP_MAXHLEN - sizeof(struct tcphdr))
end_define

begin_comment
comment|/* max space left for options */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BSD_VISIBLE */
end_comment

begin_comment
comment|/*  * User-settable options (used with setsockopt).  */
end_comment

begin_define
define|#
directive|define
name|TCP_NODELAY
value|0x01
end_define

begin_comment
comment|/* don't delay send to coalesce packets */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|TCP_MAXSEG
value|0x02
end_define

begin_comment
comment|/* set maximum segment size */
end_comment

begin_define
define|#
directive|define
name|TCP_NOPUSH
value|0x04
end_define

begin_comment
comment|/* don't push last block of write */
end_comment

begin_define
define|#
directive|define
name|TCP_NOOPT
value|0x08
end_define

begin_comment
comment|/* don't use TCP options */
end_comment

begin_define
define|#
directive|define
name|TCP_MD5SIG
value|0x10
end_define

begin_comment
comment|/* use MD5 digests (RFC2385) */
end_comment

begin_define
define|#
directive|define
name|TCP_INFO
value|0x20
end_define

begin_comment
comment|/* retrieve tcp_info structure */
end_comment

begin_define
define|#
directive|define
name|TCPI_OPT_TIMESTAMPS
value|0x01
end_define

begin_define
define|#
directive|define
name|TCPI_OPT_SACK
value|0x02
end_define

begin_define
define|#
directive|define
name|TCPI_OPT_WSCALE
value|0x04
end_define

begin_define
define|#
directive|define
name|TCPI_OPT_ECN
value|0x08
end_define

begin_comment
comment|/*  * The TCP_INFO socket option comes from the Linux 2.6 TCP API, and permits  * the caller to query certain information about the state of a TCP  * connection.  We provide an overlapping set of fields with the Linux  * implementation, but since this is a fixed size structure, room has been  * left for growth.  In order to maximize potential future compatibility with  * the Linux API, the same variable names and order have been adopted, and  * padding left to make room for omitted fields in case they are added later.  *  * XXX: This is currently an unstable ABI/API, in that it is expected to  * change.  */
end_comment

begin_struct
struct|struct
name|tcp_info
block|{
name|u_int8_t
name|tcpi_state
decl_stmt|;
comment|/* TCP FSM state. */
name|u_int8_t
name|__tcpi_ca_state
decl_stmt|;
name|u_int8_t
name|__tcpi_retransmits
decl_stmt|;
name|u_int8_t
name|__tcpi_probes
decl_stmt|;
name|u_int8_t
name|__tcpi_backoff
decl_stmt|;
name|u_int8_t
name|tcpi_options
decl_stmt|;
comment|/* Options enabled on conn. */
name|u_int8_t
name|tcpi_snd_wscale
range|:
literal|4
decl_stmt|,
comment|/* RFC1323 send shift value. */
name|tcpi_rcv_wscale
range|:
literal|4
decl_stmt|;
comment|/* RFC1323 recv shift value. */
name|u_int32_t
name|__tcpi_rto
decl_stmt|;
name|u_int32_t
name|__tcpi_ato
decl_stmt|;
name|u_int32_t
name|__tcpi_snd_mss
decl_stmt|;
name|u_int32_t
name|__tcpi_rcv_mss
decl_stmt|;
name|u_int32_t
name|__tcpi_unacked
decl_stmt|;
name|u_int32_t
name|__tcpi_sacked
decl_stmt|;
name|u_int32_t
name|__tcpi_lost
decl_stmt|;
name|u_int32_t
name|__tcpi_retrans
decl_stmt|;
name|u_int32_t
name|__tcpi_fackets
decl_stmt|;
comment|/* Times; measurements in usecs. */
name|u_int32_t
name|__tcpi_last_data_sent
decl_stmt|;
name|u_int32_t
name|__tcpi_last_ack_sent
decl_stmt|;
comment|/* Also unimpl. on Linux? */
name|u_int32_t
name|__tcpi_last_data_recv
decl_stmt|;
name|u_int32_t
name|__tcpi_last_ack_recv
decl_stmt|;
comment|/* Metrics; variable units. */
name|u_int32_t
name|__tcpi_pmtu
decl_stmt|;
name|u_int32_t
name|__tcpi_rcv_ssthresh
decl_stmt|;
name|u_int32_t
name|__tcpi_rtt
decl_stmt|;
name|u_int32_t
name|__tcpi_rttvar
decl_stmt|;
name|u_int32_t
name|tcpi_snd_ssthresh
decl_stmt|;
comment|/* Slow start threshold. */
name|u_int32_t
name|tcpi_snd_cwnd
decl_stmt|;
comment|/* Send congestion window. */
name|u_int32_t
name|__tcpi_advmss
decl_stmt|;
name|u_int32_t
name|__tcpi_reordering
decl_stmt|;
name|u_int32_t
name|__tcpi_rcv_rtt
decl_stmt|;
name|u_int32_t
name|tcpi_rcv_space
decl_stmt|;
comment|/* Advertised recv window. */
comment|/* FreeBSD extensions to tcp_info. */
name|u_int32_t
name|tcpi_snd_wnd
decl_stmt|;
comment|/* Advertised send window. */
name|u_int32_t
name|tcpi_snd_bwnd
decl_stmt|;
comment|/* Bandwidth send window. */
comment|/* Padding to grow without breaking ABI. */
name|u_int32_t
name|__tcpi_pad
index|[
literal|32
index|]
decl_stmt|;
comment|/* Padding. */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NETINET_TCP_H_ */
end_comment

end_unit

