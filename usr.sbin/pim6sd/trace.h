begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1999 WIDE Project.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  *  Copyright (c) 1998 by the University of Southern California.  *  All rights reserved.  *  *  Permission to use, copy, modify, and distribute this software and  *  its documentation in source and binary forms for lawful  *  purposes and without fee is hereby granted, provided  *  that the above copyright notice appear in all copies and that both  *  the copyright notice and this permission notice appear in supporting  *  documentation, and that any documentation, advertising materials,  *  and other materials related to such distribution and use acknowledge  *  that the software was developed by the University of Southern  *  California and/or Information Sciences Institute.  *  The name of the University of Southern California may not  *  be used to endorse or promote products derived from this software  *  without specific prior written permission.  *  *  THE UNIVERSITY OF SOUTHERN CALIFORNIA DOES NOT MAKE ANY REPRESENTATIONS  *  ABOUT THE SUITABILITY OF THIS SOFTWARE FOR ANY PURPOSE.  THIS SOFTWARE IS  *  PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES,  *  INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  *  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, TITLE, AND   *  NON-INFRINGEMENT.  *  *  IN NO EVENT SHALL USC, OR ANY OTHER CONTRIBUTOR BE LIABLE FOR ANY  *  SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, WHETHER IN CONTRACT,  *  TORT, OR OTHER FORM OF ACTION, ARISING OUT OF OR IN CONNECTION WITH,  *  THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  *  Other copyrights might apply to parts of this software and are so  *  noted when applicable.  */
end_comment

begin_comment
comment|/*  *  Questions concerning this software should be directed to   *  Pavlin Ivanov Radoslavov (pavlin@catarina.usc.edu)  *  *  $Id: trace.h,v 1.2 1999/09/09 15:47:11 jinmei Exp $  */
end_comment

begin_comment
comment|/*  * Part of this program has been derived from mrouted.  * The mrouted program is covered by the license in the accompanying file  * named "LICENSE.mrouted".  *  * The mrouted program is COPYRIGHT 1989 by The Board of Trustees of  * Leland Stanford Junior University.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TRACE_H
end_ifndef

begin_define
define|#
directive|define
name|TRACE_H
end_define

begin_comment
comment|/*  * The packet format for a traceroute request.  */
end_comment

begin_struct
struct|struct
name|tr6_query
block|{
name|struct
name|in6_addr
name|tr_src
decl_stmt|;
comment|/* traceroute source */
name|struct
name|in6_addr
name|tr_dst
decl_stmt|;
comment|/* traceroute destination */
name|struct
name|in6_addr
name|tr_raddr
decl_stmt|;
comment|/* traceroute response address */
if|#
directive|if
name|defined
argument_list|(
name|BYTE_ORDER
argument_list|)
operator|&&
operator|(
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
operator|)
struct|struct
block|{
name|u_int32_t
name|qid
range|:
literal|24
decl_stmt|;
comment|/* traceroute query id */
name|u_int32_t
name|rhlim
range|:
literal|8
decl_stmt|;
comment|/* traceroute response ttl */
block|}
name|q
struct|;
else|#
directive|else
struct|struct
block|{
name|u_int32_t
name|rhlim
range|:
literal|8
decl_stmt|;
comment|/* traceroute response ttl */
name|u_int32_t
name|qid
range|:
literal|24
decl_stmt|;
comment|/* traceroute query id */
block|}
name|q
struct|;
endif|#
directive|endif
comment|/* BYTE_ORDER */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|tr_rhlim
value|q.rhlim
end_define

begin_define
define|#
directive|define
name|tr_qid
value|q.qid
end_define

begin_comment
comment|/*  * Traceroute response format.  A traceroute response has a tr_query at the  * beginning, followed by one tr_resp for each hop taken.  */
end_comment

begin_struct
struct|struct
name|tr6_resp
block|{
name|u_int32_t
name|tr_qarr
decl_stmt|;
comment|/* query arrival time */
if|#
directive|if
literal|0
block|struct in6_addr tr_inaddr;
comment|/* incoming interface address */
block|struct in6_addr tr_outaddr;
comment|/* outgoing interface address */
endif|#
directive|endif
name|u_int32_t
name|tr_inifid
decl_stmt|;
comment|/* incoming interface identifier */
name|u_int32_t
name|tr_outifid
decl_stmt|;
comment|/* outgoing interface identifier */
name|struct
name|in6_addr
name|tr_lcladdr
decl_stmt|;
comment|/* router's address(must have largest scope) */
name|struct
name|in6_addr
name|tr_rmtaddr
decl_stmt|;
comment|/* parent address in source tree */
name|u_int32_t
name|tr_vifin
decl_stmt|;
comment|/* input packet count on interface */
name|u_int32_t
name|tr_vifout
decl_stmt|;
comment|/* output packet count on interface */
name|u_int32_t
name|tr_pktcnt
decl_stmt|;
comment|/* total incoming packets for src-grp */
name|u_char
name|tr_rproto
decl_stmt|;
comment|/* routing protocol deployed on router */
if|#
directive|if
literal|0
block|u_char  tr_fhlim;
comment|/* hop limit required to forward on outvif */
endif|#
directive|endif
name|u_char
name|tr_flags
decl_stmt|;
comment|/* flags */
name|u_char
name|tr_plen
decl_stmt|;
comment|/* prefix length for src addr */
name|u_char
name|tr_rflags
decl_stmt|;
comment|/* forwarding error codes */
block|}
struct|;
end_struct

begin_comment
comment|/* defs within mtrace */
end_comment

begin_define
define|#
directive|define
name|QUERY
value|1
end_define

begin_define
define|#
directive|define
name|RESP
value|2
end_define

begin_define
define|#
directive|define
name|QLEN
value|sizeof(struct tr6_query)
end_define

begin_define
define|#
directive|define
name|RLEN
value|sizeof(struct tr6_resp)
end_define

begin_comment
comment|/* fields for tr_inifid and tr_outifid */
end_comment

begin_define
define|#
directive|define
name|TR_NO_VIF
value|0xffffffff
end_define

begin_comment
comment|/* interface can't be determined */
end_comment

begin_comment
comment|/* fields for tr_rflags (forwarding error codes) */
end_comment

begin_define
define|#
directive|define
name|TR_NO_ERR
value|0
end_define

begin_comment
comment|/* No error */
end_comment

begin_define
define|#
directive|define
name|TR_WRONG_IF
value|1
end_define

begin_comment
comment|/* traceroute arrived on non-oif */
end_comment

begin_define
define|#
directive|define
name|TR_PRUNED
value|2
end_define

begin_comment
comment|/* router has sent a prune upstream */
end_comment

begin_define
define|#
directive|define
name|TR_OPRUNED
value|3
end_define

begin_comment
comment|/* stop forw. after request from next hop rtr*/
end_comment

begin_define
define|#
directive|define
name|TR_SCOPED
value|4
end_define

begin_comment
comment|/* group adm. scoped at this hop */
end_comment

begin_define
define|#
directive|define
name|TR_NO_RTE
value|5
end_define

begin_comment
comment|/* no route for the source */
end_comment

begin_define
define|#
directive|define
name|TR_NO_LHR
value|6
end_define

begin_comment
comment|/* not the last-hop router */
end_comment

begin_define
define|#
directive|define
name|TR_NO_FWD
value|7
end_define

begin_comment
comment|/* not forwarding for this (S,G). Reason = ? */
end_comment

begin_define
define|#
directive|define
name|TR_RP
value|8
end_define

begin_comment
comment|/* I am the RP/Core */
end_comment

begin_define
define|#
directive|define
name|TR_IIF
value|9
end_define

begin_comment
comment|/* request arrived on the iif */
end_comment

begin_define
define|#
directive|define
name|TR_NO_MULTI
value|0x0a
end_define

begin_comment
comment|/* multicast disabled on that interface */
end_comment

begin_define
define|#
directive|define
name|TR_NO_SPACE
value|0x81
end_define

begin_comment
comment|/* no space to insert responce data block */
end_comment

begin_define
define|#
directive|define
name|TR_OLD_ROUTER
value|0x82
end_define

begin_comment
comment|/* previous hop does not support traceroute */
end_comment

begin_define
define|#
directive|define
name|TR_ADMIN_PROHIB
value|0x83
end_define

begin_comment
comment|/* traceroute adm. prohibited */
end_comment

begin_comment
comment|/* fields for tr_flags */
end_comment

begin_define
define|#
directive|define
name|TR_SUBNET_COUNT
value|0x80
end_define

begin_comment
comment|/* pkt count for (S,G) is for source network */
end_comment

begin_comment
comment|/* fields for r_plen */
end_comment

begin_define
define|#
directive|define
name|TR_GROUP_ONLY
value|0xff
end_define

begin_comment
comment|/* forwarding solely on group state */
end_comment

begin_comment
comment|/* fields for packets count */
end_comment

begin_define
define|#
directive|define
name|TR_CANT_COUNT
value|0xffffffff
end_define

begin_comment
comment|/* no count can be reported */
end_comment

begin_comment
comment|/* fields for tr_rproto (routing protocol) */
end_comment

begin_define
define|#
directive|define
name|PROTO_DVMRP
value|1
end_define

begin_define
define|#
directive|define
name|PROTO_MOSPF
value|2
end_define

begin_define
define|#
directive|define
name|PROTO_PIM
value|3
end_define

begin_define
define|#
directive|define
name|PROTO_CBT
value|4
end_define

begin_define
define|#
directive|define
name|PROTO_PIM_SPECIAL
value|5
end_define

begin_define
define|#
directive|define
name|PROTO_PIM_STATIC
value|6
end_define

begin_define
define|#
directive|define
name|PROTO_DVMRP_STATIC
value|7
end_define

begin_define
define|#
directive|define
name|MASK_TO_VAL
parameter_list|(
name|x
parameter_list|,
name|i
parameter_list|)
value|{ \ 			u_int32_t _x = ntohl(x); \ 			(i) = 1; \ 			while ((_x)<<= 1) \ 				(i)++; \ 			};
end_define

begin_define
define|#
directive|define
name|VAL_TO_MASK
parameter_list|(
name|x
parameter_list|,
name|i
parameter_list|)
value|{ \ 			x = htonl(~((1<< (32 - (i))) - 1)); \ 			};
end_define

begin_define
define|#
directive|define
name|MASKLEN_TO_MASK6
parameter_list|(
name|masklen
parameter_list|,
name|mask6
parameter_list|)
define|\
value|do {\ 		u_char maskarray[8] = \ 		{0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff}; \ 		int bytelen, bitlen, i; \ 		memset(&(mask6), 0, sizeof(mask6));\ 		bytelen = (masklen) / 8;\ 		bitlen = (masklen) % 8;\ 		for (i = 0; i< bytelen; i++) \ 			(mask6).s6_addr[i] = 0xff;\ 		if (bitlen) \ 			(mask6).s6_addr[bytelen] = maskarray[bitlen - 1]; \ 	}while(0);
end_define

begin_comment
comment|/* obnoxious gcc gives an extraneous warning about this constant... */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|JAN_1970
value|2208988800UL
end_define

begin_comment
comment|/* 1970 - 1900 in seconds */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|JAN_1970
value|2208988800L
end_define

begin_comment
comment|/* 1970 - 1900 in seconds */
end_comment

begin_define
define|#
directive|define
name|const
end_define

begin_comment
comment|/**/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NBR_VERS
parameter_list|(
name|n
parameter_list|)
value|(((n)->al_pv<< 8) + (n)->al_mv)
end_define

begin_decl_stmt
name|void
name|accept_mtrace
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
operator|,
expr|struct
name|in6_addr
operator|*
operator|,
expr|struct
name|in6_addr
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|u_int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TRACE_H */
end_comment

end_unit

