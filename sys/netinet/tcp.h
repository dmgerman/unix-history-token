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

begin_include
include|#
directive|include
file|<sys/types.h>
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
name|u_char
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
name|u_char
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
define|#
directive|define
name|PRINT_TH_FLAGS
value|"\20\1FIN\2SYN\3RST\4PUSH\5ACK\6URG\7ECE\10CWR"
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
name|TCPOLEN_EOL
value|1
end_define

begin_define
define|#
directive|define
name|TCPOPT_PAD
value|0
end_define

begin_comment
comment|/* padding after EOL */
end_comment

begin_define
define|#
directive|define
name|TCPOLEN_PAD
value|1
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
name|TCPOLEN_NOP
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

begin_define
define|#
directive|define
name|TCPOLEN_SACKHDR
value|2
end_define

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
comment|/*  * The default maximum segment size (MSS) to be used for new TCP connections  * when path MTU discovery is not enabled.  *  * RFC879 derives the default MSS from the largest datagram size hosts are  * minimally required to handle directly or through IP reassembly minus the  * size of the IP and TCP header.  With IPv6 the minimum MTU is specified  * in RFC2460.  *  * For IPv4 the MSS is 576 - sizeof(struct tcpiphdr)  * For IPv6 the MSS is IPV6_MMTU - sizeof(struct ip6_hdr) - sizeof(struct tcphdr)  *  * We use explicit numerical definition here to avoid header pollution.  */
end_comment

begin_define
define|#
directive|define
name|TCP_MSS
value|536
end_define

begin_define
define|#
directive|define
name|TCP6_MSS
value|1220
end_define

begin_comment
comment|/*  * Limit the lowest MSS we accept for path MTU discovery and the TCP SYN MSS  * option.  Allowing low values of MSS can consume significant resources and  * be used to mount a resource exhaustion attack.  * Connections requesting lower MSS values will be rounded up to this value  * and the IP_DF flag will be cleared to allow fragmentation along the path.  *  * See tcp_subr.c tcp_minmss SYSCTL declaration for more comments.  Setting  * it to "0" disables the minmss check.  *  * The default value is fine for TCP across the Internet's smallest official  * link MTU (256 bytes for AX.25 packet radio).  However, a connection is very  * unlikely to come across such low MTU interfaces these days (anno domini 2003).  */
end_comment

begin_define
define|#
directive|define
name|TCP_MINMSS
value|216
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
comment|/*  * User-settable options (used with setsockopt).  These are discrete  * values and are not masked together.  Some values appear to be  * bitmasks for historical reasons.  */
end_comment

begin_define
define|#
directive|define
name|TCP_NODELAY
value|1
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
value|2
end_define

begin_comment
comment|/* set maximum segment size */
end_comment

begin_define
define|#
directive|define
name|TCP_NOPUSH
value|4
end_define

begin_comment
comment|/* don't push last block of write */
end_comment

begin_define
define|#
directive|define
name|TCP_NOOPT
value|8
end_define

begin_comment
comment|/* don't use TCP options */
end_comment

begin_define
define|#
directive|define
name|TCP_MD5SIG
value|16
end_define

begin_comment
comment|/* use MD5 digests (RFC2385) */
end_comment

begin_define
define|#
directive|define
name|TCP_INFO
value|32
end_define

begin_comment
comment|/* retrieve tcp_info structure */
end_comment

begin_define
define|#
directive|define
name|TCP_CONGESTION
value|64
end_define

begin_comment
comment|/* get/set congestion control algorithm */
end_comment

begin_define
define|#
directive|define
name|TCP_KEEPINIT
value|128
end_define

begin_comment
comment|/* N, time to establish connection */
end_comment

begin_define
define|#
directive|define
name|TCP_KEEPIDLE
value|256
end_define

begin_comment
comment|/* L,N,X start keeplives after this period */
end_comment

begin_define
define|#
directive|define
name|TCP_KEEPINTVL
value|512
end_define

begin_comment
comment|/* L,N interval between keepalives */
end_comment

begin_define
define|#
directive|define
name|TCP_KEEPCNT
value|1024
end_define

begin_comment
comment|/* L,N number of keepalives before close */
end_comment

begin_define
define|#
directive|define
name|TCP_PCAP_OUT
value|2048
end_define

begin_comment
comment|/* number of output packets to keep */
end_comment

begin_define
define|#
directive|define
name|TCP_PCAP_IN
value|4096
end_define

begin_comment
comment|/* number of input packets to keep */
end_comment

begin_define
define|#
directive|define
name|TCP_FUNCTION_BLK
value|8192
end_define

begin_comment
comment|/* Set the tcp function pointers to the specified stack */
end_comment

begin_comment
comment|/* Start of reserved space for third-party user-settable options. */
end_comment

begin_define
define|#
directive|define
name|TCP_VENDOR
value|SO_VENDOR
end_define

begin_define
define|#
directive|define
name|TCP_CA_NAME_MAX
value|16
end_define

begin_comment
comment|/* max congestion control name length */
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

begin_define
define|#
directive|define
name|TCPI_OPT_TOE
value|0x10
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
name|tcpi_rto
decl_stmt|;
comment|/* Retransmission timeout (usec). */
name|u_int32_t
name|__tcpi_ato
decl_stmt|;
name|u_int32_t
name|tcpi_snd_mss
decl_stmt|;
comment|/* Max segment size for send. */
name|u_int32_t
name|tcpi_rcv_mss
decl_stmt|;
comment|/* Max segment size for receive. */
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
name|tcpi_last_data_recv
decl_stmt|;
comment|/* Time since last recv data. */
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
name|tcpi_rtt
decl_stmt|;
comment|/* Smoothed RTT in usecs. */
name|u_int32_t
name|tcpi_rttvar
decl_stmt|;
comment|/* RTT variance in usecs. */
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
comment|/* No longer used. */
name|u_int32_t
name|tcpi_snd_nxt
decl_stmt|;
comment|/* Next egress seqno */
name|u_int32_t
name|tcpi_rcv_nxt
decl_stmt|;
comment|/* Next ingress seqno */
name|u_int32_t
name|tcpi_toe_tid
decl_stmt|;
comment|/* HWTID for TOE endpoints */
name|u_int32_t
name|tcpi_snd_rexmitpack
decl_stmt|;
comment|/* Retransmitted packets */
name|u_int32_t
name|tcpi_rcv_ooopack
decl_stmt|;
comment|/* Out-of-order packets */
name|u_int32_t
name|tcpi_snd_zerowin
decl_stmt|;
comment|/* Zero-sized windows sent */
comment|/* Padding to grow without breaking ABI. */
name|u_int32_t
name|__tcpi_pad
index|[
literal|26
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

begin_define
define|#
directive|define
name|TCP_FUNCTION_NAME_LEN_MAX
value|32
end_define

begin_struct
struct|struct
name|tcp_function_set
block|{
name|char
name|function_set_name
index|[
name|TCP_FUNCTION_NAME_LEN_MAX
index|]
decl_stmt|;
name|uint32_t
name|pcbcnt
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NETINET_TCP_H_ */
end_comment

end_unit

