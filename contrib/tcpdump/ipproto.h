begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * @(#) $Header: /tcpdump/master/tcpdump/ipproto.h,v 1.4.2.1 2005/05/20 21:15:46 hannes Exp $ (LBL)  *  * From:  *	@(#)in.h	8.3 (Berkeley) 1/3/94  * $FreeBSD$  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|tok
name|ipproto_values
index|[]
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_IP
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_IP
value|0
end_define

begin_comment
comment|/* dummy for IP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_HOPOPTS
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_HOPOPTS
value|0
end_define

begin_comment
comment|/* IPv6 hop-by-hop options */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_ICMP
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_ICMP
value|1
end_define

begin_comment
comment|/* control message protocol */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_IGMP
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_IGMP
value|2
end_define

begin_comment
comment|/* group mgmt protocol */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_IPV4
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_IPV4
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_TCP
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_TCP
value|6
end_define

begin_comment
comment|/* tcp */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_EGP
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_EGP
value|8
end_define

begin_comment
comment|/* exterior gateway protocol */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_PIGP
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_PIGP
value|9
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_UDP
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_UDP
value|17
end_define

begin_comment
comment|/* user datagram protocol */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_IPV6
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_IPV6
value|41
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_ROUTING
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_ROUTING
value|43
end_define

begin_comment
comment|/* IPv6 routing header */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_FRAGMENT
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_FRAGMENT
value|44
end_define

begin_comment
comment|/* IPv6 fragmentation header */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_RSVP
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_RSVP
value|46
end_define

begin_comment
comment|/* resource reservation */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_GRE
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_GRE
value|47
end_define

begin_comment
comment|/* General Routing Encap. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_ESP
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_ESP
value|50
end_define

begin_comment
comment|/* SIPP Encap Sec. Payload */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_AH
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_AH
value|51
end_define

begin_comment
comment|/* SIPP Auth Header */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_MOBILE
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_MOBILE
value|55
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_ICMPV6
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_ICMPV6
value|58
end_define

begin_comment
comment|/* ICMPv6 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_NONE
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_NONE
value|59
end_define

begin_comment
comment|/* IPv6 no next header */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_DSTOPTS
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_DSTOPTS
value|60
end_define

begin_comment
comment|/* IPv6 destination options */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_MOBILITY_OLD
end_ifndef

begin_comment
comment|/*  * The current Protocol Numbers list says that the IP protocol number for  * mobility headers is 135; it cites draft-ietf-mobileip-ipv6-24, but  * that draft doesn't actually give a number.  *  * It appears that 62 used to be used, even though that's assigned to  * a protocol called CFTP; however, the only reference for CFTP is a  * Network Message from BBN back in 1982, so, for now, we support 62,  * aas well as 135, as a protocol number for mobility headers.  */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_MOBILITY_OLD
value|62
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_ND
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_ND
value|77
end_define

begin_comment
comment|/* Sun net disk proto (temp.) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_EIGRP
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_EIGRP
value|88
end_define

begin_comment
comment|/* Cisco/GXS IGRP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_OSPF
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_OSPF
value|89
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_PIM
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_PIM
value|103
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_IPCOMP
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_IPCOMP
value|108
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_VRRP
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_VRRP
value|112
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_PGM
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_PGM
value|113
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_SCTP
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_SCTP
value|132
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_MOBILITY
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_MOBILITY
value|135
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

