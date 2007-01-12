begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ip.h	8.2 (Berkeley) 6/1/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_IP_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_IP_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/*  * Definitions for internet protocol version 4.  * Per RFC 791, September 1981.  */
end_comment

begin_define
define|#
directive|define
name|IPVERSION
value|4
end_define

begin_comment
comment|/*  * Structure of an internet header, naked of options.  */
end_comment

begin_struct
struct|struct
name|ip
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
name|u_int
name|ip_hl
range|:
literal|4
decl_stmt|,
comment|/* header length */
name|ip_v
range|:
literal|4
decl_stmt|;
comment|/* version */
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_int
name|ip_v
range|:
literal|4
decl_stmt|,
comment|/* version */
name|ip_hl
range|:
literal|4
decl_stmt|;
comment|/* header length */
endif|#
directive|endif
name|u_char
name|ip_tos
decl_stmt|;
comment|/* type of service */
name|u_short
name|ip_len
decl_stmt|;
comment|/* total length */
name|u_short
name|ip_id
decl_stmt|;
comment|/* identification */
name|u_short
name|ip_off
decl_stmt|;
comment|/* fragment offset field */
define|#
directive|define
name|IP_RF
value|0x8000
comment|/* reserved fragment flag */
define|#
directive|define
name|IP_DF
value|0x4000
comment|/* dont fragment flag */
define|#
directive|define
name|IP_MF
value|0x2000
comment|/* more fragments flag */
define|#
directive|define
name|IP_OFFMASK
value|0x1fff
comment|/* mask for fragmenting bits */
name|u_char
name|ip_ttl
decl_stmt|;
comment|/* time to live */
name|u_char
name|ip_p
decl_stmt|;
comment|/* protocol */
name|u_short
name|ip_sum
decl_stmt|;
comment|/* checksum */
name|struct
name|in_addr
name|ip_src
decl_stmt|,
name|ip_dst
decl_stmt|;
comment|/* source and dest address */
block|}
name|__packed
name|__aligned
argument_list|(
literal|4
argument_list|)
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|CTASSERT
end_ifdef

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|ip
argument_list|)
operator|==
literal|20
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IP_MAXPACKET
value|65535
end_define

begin_comment
comment|/* maximum packet size */
end_comment

begin_comment
comment|/*  * Definitions for IP type of service (ip_tos)  */
end_comment

begin_define
define|#
directive|define
name|IPTOS_LOWDELAY
value|0x10
end_define

begin_define
define|#
directive|define
name|IPTOS_THROUGHPUT
value|0x08
end_define

begin_define
define|#
directive|define
name|IPTOS_RELIABILITY
value|0x04
end_define

begin_define
define|#
directive|define
name|IPTOS_MINCOST
value|0x02
end_define

begin_if
if|#
directive|if
literal|1
end_if

begin_comment
comment|/* ECN RFC3168 obsoletes RFC2481, and these will be deprecated soon. */
end_comment

begin_define
define|#
directive|define
name|IPTOS_CE
value|0x01
end_define

begin_define
define|#
directive|define
name|IPTOS_ECT
value|0x02
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Definitions for IP precedence (also in ip_tos) (hopefully unused)  */
end_comment

begin_define
define|#
directive|define
name|IPTOS_PREC_NETCONTROL
value|0xe0
end_define

begin_define
define|#
directive|define
name|IPTOS_PREC_INTERNETCONTROL
value|0xc0
end_define

begin_define
define|#
directive|define
name|IPTOS_PREC_CRITIC_ECP
value|0xa0
end_define

begin_define
define|#
directive|define
name|IPTOS_PREC_FLASHOVERRIDE
value|0x80
end_define

begin_define
define|#
directive|define
name|IPTOS_PREC_FLASH
value|0x60
end_define

begin_define
define|#
directive|define
name|IPTOS_PREC_IMMEDIATE
value|0x40
end_define

begin_define
define|#
directive|define
name|IPTOS_PREC_PRIORITY
value|0x20
end_define

begin_define
define|#
directive|define
name|IPTOS_PREC_ROUTINE
value|0x00
end_define

begin_comment
comment|/*  * ECN (Explicit Congestion Notification) codepoints in RFC3168  * mapped to the lower 2 bits of the TOS field.  */
end_comment

begin_define
define|#
directive|define
name|IPTOS_ECN_NOTECT
value|0x00
end_define

begin_comment
comment|/* not-ECT */
end_comment

begin_define
define|#
directive|define
name|IPTOS_ECN_ECT1
value|0x01
end_define

begin_comment
comment|/* ECN-capable transport (1) */
end_comment

begin_define
define|#
directive|define
name|IPTOS_ECN_ECT0
value|0x02
end_define

begin_comment
comment|/* ECN-capable transport (0) */
end_comment

begin_define
define|#
directive|define
name|IPTOS_ECN_CE
value|0x03
end_define

begin_comment
comment|/* congestion experienced */
end_comment

begin_define
define|#
directive|define
name|IPTOS_ECN_MASK
value|0x03
end_define

begin_comment
comment|/* ECN field mask */
end_comment

begin_comment
comment|/*  * Definitions for options.  */
end_comment

begin_define
define|#
directive|define
name|IPOPT_COPIED
parameter_list|(
name|o
parameter_list|)
value|((o)&0x80)
end_define

begin_define
define|#
directive|define
name|IPOPT_CLASS
parameter_list|(
name|o
parameter_list|)
value|((o)&0x60)
end_define

begin_define
define|#
directive|define
name|IPOPT_NUMBER
parameter_list|(
name|o
parameter_list|)
value|((o)&0x1f)
end_define

begin_define
define|#
directive|define
name|IPOPT_CONTROL
value|0x00
end_define

begin_define
define|#
directive|define
name|IPOPT_RESERVED1
value|0x20
end_define

begin_define
define|#
directive|define
name|IPOPT_DEBMEAS
value|0x40
end_define

begin_define
define|#
directive|define
name|IPOPT_RESERVED2
value|0x60
end_define

begin_define
define|#
directive|define
name|IPOPT_EOL
value|0
end_define

begin_comment
comment|/* end of option list */
end_comment

begin_define
define|#
directive|define
name|IPOPT_NOP
value|1
end_define

begin_comment
comment|/* no operation */
end_comment

begin_define
define|#
directive|define
name|IPOPT_RR
value|7
end_define

begin_comment
comment|/* record packet route */
end_comment

begin_define
define|#
directive|define
name|IPOPT_TS
value|68
end_define

begin_comment
comment|/* timestamp */
end_comment

begin_define
define|#
directive|define
name|IPOPT_SECURITY
value|130
end_define

begin_comment
comment|/* provide s,c,h,tcc */
end_comment

begin_define
define|#
directive|define
name|IPOPT_LSRR
value|131
end_define

begin_comment
comment|/* loose source route */
end_comment

begin_define
define|#
directive|define
name|IPOPT_ESO
value|133
end_define

begin_comment
comment|/* extended security */
end_comment

begin_define
define|#
directive|define
name|IPOPT_CIPSO
value|134
end_define

begin_comment
comment|/* commerical security */
end_comment

begin_define
define|#
directive|define
name|IPOPT_SATID
value|136
end_define

begin_comment
comment|/* satnet id */
end_comment

begin_define
define|#
directive|define
name|IPOPT_SSRR
value|137
end_define

begin_comment
comment|/* strict source route */
end_comment

begin_define
define|#
directive|define
name|IPOPT_RA
value|148
end_define

begin_comment
comment|/* router alert */
end_comment

begin_comment
comment|/*  * Offsets to fields in options other than EOL and NOP.  */
end_comment

begin_define
define|#
directive|define
name|IPOPT_OPTVAL
value|0
end_define

begin_comment
comment|/* option ID */
end_comment

begin_define
define|#
directive|define
name|IPOPT_OLEN
value|1
end_define

begin_comment
comment|/* option length */
end_comment

begin_define
define|#
directive|define
name|IPOPT_OFFSET
value|2
end_define

begin_comment
comment|/* offset within option */
end_comment

begin_define
define|#
directive|define
name|IPOPT_MINOFF
value|4
end_define

begin_comment
comment|/* min value of above */
end_comment

begin_comment
comment|/*  * Time stamp option structure.  */
end_comment

begin_struct
struct|struct
name|ip_timestamp
block|{
name|u_char
name|ipt_code
decl_stmt|;
comment|/* IPOPT_TS */
name|u_char
name|ipt_len
decl_stmt|;
comment|/* size of structure (variable) */
name|u_char
name|ipt_ptr
decl_stmt|;
comment|/* index of current entry */
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
name|u_int
name|ipt_flg
range|:
literal|4
decl_stmt|,
comment|/* flags, see below */
name|ipt_oflw
range|:
literal|4
decl_stmt|;
comment|/* overflow counter */
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_int
name|ipt_oflw
range|:
literal|4
decl_stmt|,
comment|/* overflow counter */
name|ipt_flg
range|:
literal|4
decl_stmt|;
comment|/* flags, see below */
endif|#
directive|endif
union|union
name|ipt_timestamp
block|{
name|n_long
name|ipt_time
index|[
literal|1
index|]
decl_stmt|;
struct|struct
name|ipt_ta
block|{
name|struct
name|in_addr
name|ipt_addr
decl_stmt|;
name|n_long
name|ipt_time
decl_stmt|;
block|}
name|ipt_ta
index|[
literal|1
index|]
struct|;
block|}
name|ipt_timestamp
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* flag bits for ipt_flg */
end_comment

begin_define
define|#
directive|define
name|IPOPT_TS_TSONLY
value|0
end_define

begin_comment
comment|/* timestamps only */
end_comment

begin_define
define|#
directive|define
name|IPOPT_TS_TSANDADDR
value|1
end_define

begin_comment
comment|/* timestamps and addresses */
end_comment

begin_define
define|#
directive|define
name|IPOPT_TS_PRESPEC
value|3
end_define

begin_comment
comment|/* specified modules only */
end_comment

begin_comment
comment|/* bits for security (not byte swapped) */
end_comment

begin_define
define|#
directive|define
name|IPOPT_SECUR_UNCLASS
value|0x0000
end_define

begin_define
define|#
directive|define
name|IPOPT_SECUR_CONFID
value|0xf135
end_define

begin_define
define|#
directive|define
name|IPOPT_SECUR_EFTO
value|0x789a
end_define

begin_define
define|#
directive|define
name|IPOPT_SECUR_MMMM
value|0xbc4d
end_define

begin_define
define|#
directive|define
name|IPOPT_SECUR_RESTR
value|0xaf13
end_define

begin_define
define|#
directive|define
name|IPOPT_SECUR_SECRET
value|0xd788
end_define

begin_define
define|#
directive|define
name|IPOPT_SECUR_TOPSECRET
value|0x6bc5
end_define

begin_comment
comment|/*  * Internet implementation parameters.  */
end_comment

begin_define
define|#
directive|define
name|MAXTTL
value|255
end_define

begin_comment
comment|/* maximum time to live (seconds) */
end_comment

begin_define
define|#
directive|define
name|IPDEFTTL
value|64
end_define

begin_comment
comment|/* default ttl, from RFC 1340 */
end_comment

begin_define
define|#
directive|define
name|IPFRAGTTL
value|60
end_define

begin_comment
comment|/* time to live for frags, slowhz */
end_comment

begin_define
define|#
directive|define
name|IPTTLDEC
value|1
end_define

begin_comment
comment|/* subtracted when forwarding */
end_comment

begin_define
define|#
directive|define
name|IP_MSS
value|576
end_define

begin_comment
comment|/* default maximum segment size */
end_comment

begin_comment
comment|/*  * This is the real IPv4 pseudo header, used for computing the TCP and UDP  * checksums. For the Internet checksum, struct ipovly can be used instead.  * For stronger checksums, the real thing must be used.  */
end_comment

begin_struct
struct|struct
name|ippseudo
block|{
name|struct
name|in_addr
name|ippseudo_src
decl_stmt|;
comment|/* source internet address */
name|struct
name|in_addr
name|ippseudo_dst
decl_stmt|;
comment|/* destination internet address */
name|u_char
name|ippseudo_pad
decl_stmt|;
comment|/* pad, must be zero */
name|u_char
name|ippseudo_p
decl_stmt|;
comment|/* protocol */
name|u_short
name|ippseudo_len
decl_stmt|;
comment|/* protocol length */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

