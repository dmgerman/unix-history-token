begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#) $Header: /tcpdump/master/tcpdump/tcp.h,v 1.7 2000/10/03 09:17:41 guy Exp $ (LBL) */
end_comment

begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)tcp.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_typedef
typedef|typedef
name|u_int32_t
name|tcp_seq
typedef|;
end_typedef

begin_comment
comment|/*  * TCP header.  * Per RFC 793, September, 1981.  */
end_comment

begin_struct
struct|struct
name|tcphdr
block|{
name|u_int16_t
name|th_sport
decl_stmt|;
comment|/* source port */
name|u_int16_t
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
name|u_int8_t
name|th_offx2
decl_stmt|;
comment|/* data offset, rsvd */
define|#
directive|define
name|TH_OFF
parameter_list|(
name|th
parameter_list|)
value|(((th)->th_offx2& 0xf0)>> 4)
name|u_int8_t
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
name|u_int16_t
name|th_win
decl_stmt|;
comment|/* window */
name|u_int16_t
name|th_sum
decl_stmt|;
comment|/* checksum */
name|u_int16_t
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

end_unit

