begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: ip6.h,v 1.18 2001/03/29 05:34:30 itojun Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ip.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_IP6_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_IP6_H_
end_define

begin_comment
comment|/*  * Definition for internet protocol version 6.  * RFC 2460  */
end_comment

begin_struct
struct|struct
name|ip6_hdr
block|{
union|union
block|{
struct|struct
name|ip6_hdrctl
block|{
name|u_int32_t
name|ip6_un1_flow
decl_stmt|;
comment|/* 20 bits of flow-ID */
name|u_int16_t
name|ip6_un1_plen
decl_stmt|;
comment|/* payload length */
name|u_int8_t
name|ip6_un1_nxt
decl_stmt|;
comment|/* next header */
name|u_int8_t
name|ip6_un1_hlim
decl_stmt|;
comment|/* hop limit */
block|}
name|ip6_un1
struct|;
name|u_int8_t
name|ip6_un2_vfc
decl_stmt|;
comment|/* 4 bits version, top 4 bits class */
block|}
name|ip6_ctlun
union|;
name|struct
name|in6_addr
name|ip6_src
decl_stmt|;
comment|/* source address */
name|struct
name|in6_addr
name|ip6_dst
decl_stmt|;
comment|/* destination address */
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|ip6_vfc
value|ip6_ctlun.ip6_un2_vfc
end_define

begin_define
define|#
directive|define
name|ip6_flow
value|ip6_ctlun.ip6_un1.ip6_un1_flow
end_define

begin_define
define|#
directive|define
name|ip6_plen
value|ip6_ctlun.ip6_un1.ip6_un1_plen
end_define

begin_define
define|#
directive|define
name|ip6_nxt
value|ip6_ctlun.ip6_un1.ip6_un1_nxt
end_define

begin_define
define|#
directive|define
name|ip6_hlim
value|ip6_ctlun.ip6_un1.ip6_un1_hlim
end_define

begin_define
define|#
directive|define
name|ip6_hops
value|ip6_ctlun.ip6_un1.ip6_un1_hlim
end_define

begin_define
define|#
directive|define
name|IPV6_VERSION
value|0x60
end_define

begin_define
define|#
directive|define
name|IPV6_VERSION_MASK
value|0xf0
end_define

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|IPV6_FLOWINFO_MASK
value|0x0fffffff
end_define

begin_comment
comment|/* flow info (28 bits) */
end_comment

begin_define
define|#
directive|define
name|IPV6_FLOWLABEL_MASK
value|0x000fffff
end_define

begin_comment
comment|/* flow label (20 bits) */
end_comment

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|IPV6_FLOWINFO_MASK
value|0xffffff0f
end_define

begin_comment
comment|/* flow info (28 bits) */
end_comment

begin_define
define|#
directive|define
name|IPV6_FLOWLABEL_MASK
value|0xffff0f00
end_define

begin_comment
comment|/* flow label (20 bits) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LITTLE_ENDIAN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|1
end_if

begin_comment
comment|/* ECN bits proposed by Sally Floyd */
end_comment

begin_define
define|#
directive|define
name|IP6TOS_CE
value|0x01
end_define

begin_comment
comment|/* congestion experienced */
end_comment

begin_define
define|#
directive|define
name|IP6TOS_ECT
value|0x02
end_define

begin_comment
comment|/* ECN-capable transport */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Extension Headers  */
end_comment

begin_struct
struct|struct
name|ip6_ext
block|{
name|u_int8_t
name|ip6e_nxt
decl_stmt|;
name|u_int8_t
name|ip6e_len
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* Hop-by-Hop options header */
end_comment

begin_comment
comment|/* XXX should we pad it to force alignment on an 8-byte boundary? */
end_comment

begin_struct
struct|struct
name|ip6_hbh
block|{
name|u_int8_t
name|ip6h_nxt
decl_stmt|;
comment|/* next header */
name|u_int8_t
name|ip6h_len
decl_stmt|;
comment|/* length in units of 8 octets */
comment|/* followed by options */
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* Destination options header */
end_comment

begin_comment
comment|/* XXX should we pad it to force alignment on an 8-byte boundary? */
end_comment

begin_struct
struct|struct
name|ip6_dest
block|{
name|u_int8_t
name|ip6d_nxt
decl_stmt|;
comment|/* next header */
name|u_int8_t
name|ip6d_len
decl_stmt|;
comment|/* length in units of 8 octets */
comment|/* followed by options */
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* Option types and related macros */
end_comment

begin_define
define|#
directive|define
name|IP6OPT_PAD1
value|0x00
end_define

begin_comment
comment|/* 00 0 00000 */
end_comment

begin_define
define|#
directive|define
name|IP6OPT_PADN
value|0x01
end_define

begin_comment
comment|/* 00 0 00001 */
end_comment

begin_define
define|#
directive|define
name|IP6OPT_JUMBO
value|0xC2
end_define

begin_comment
comment|/* 11 0 00010 = 194 */
end_comment

begin_define
define|#
directive|define
name|IP6OPT_NSAP_ADDR
value|0xC3
end_define

begin_comment
comment|/* 11 0 00011 */
end_comment

begin_define
define|#
directive|define
name|IP6OPT_TUNNEL_LIMIT
value|0x04
end_define

begin_comment
comment|/* 00 0 00100 */
end_comment

begin_define
define|#
directive|define
name|IP6OPT_RTALERT
value|0x05
end_define

begin_comment
comment|/* 00 0 00101 (KAME definition) */
end_comment

begin_define
define|#
directive|define
name|IP6OPT_RTALERT_LEN
value|4
end_define

begin_define
define|#
directive|define
name|IP6OPT_RTALERT_MLD
value|0
end_define

begin_comment
comment|/* Datagram contains an MLD message */
end_comment

begin_define
define|#
directive|define
name|IP6OPT_RTALERT_RSVP
value|1
end_define

begin_comment
comment|/* Datagram contains an RSVP message */
end_comment

begin_define
define|#
directive|define
name|IP6OPT_RTALERT_ACTNET
value|2
end_define

begin_comment
comment|/* contains an Active Networks msg */
end_comment

begin_define
define|#
directive|define
name|IP6OPT_MINLEN
value|2
end_define

begin_define
define|#
directive|define
name|IP6OPT_BINDING_UPDATE
value|0xc6
end_define

begin_comment
comment|/* 11 0 00110 */
end_comment

begin_define
define|#
directive|define
name|IP6OPT_BINDING_ACK
value|0x07
end_define

begin_comment
comment|/* 00 0 00111 */
end_comment

begin_define
define|#
directive|define
name|IP6OPT_BINDING_REQ
value|0x08
end_define

begin_comment
comment|/* 00 0 01000 */
end_comment

begin_define
define|#
directive|define
name|IP6OPT_HOME_ADDRESS
value|0xc9
end_define

begin_comment
comment|/* 11 0 01001 */
end_comment

begin_define
define|#
directive|define
name|IP6OPT_EID
value|0x8a
end_define

begin_comment
comment|/* 10 0 01010 */
end_comment

begin_define
define|#
directive|define
name|IP6OPT_TYPE
parameter_list|(
name|o
parameter_list|)
value|((o)& 0xC0)
end_define

begin_define
define|#
directive|define
name|IP6OPT_TYPE_SKIP
value|0x00
end_define

begin_define
define|#
directive|define
name|IP6OPT_TYPE_DISCARD
value|0x40
end_define

begin_define
define|#
directive|define
name|IP6OPT_TYPE_FORCEICMP
value|0x80
end_define

begin_define
define|#
directive|define
name|IP6OPT_TYPE_ICMP
value|0xC0
end_define

begin_define
define|#
directive|define
name|IP6OPT_MUTABLE
value|0x20
end_define

begin_define
define|#
directive|define
name|IP6OPT_JUMBO_LEN
value|6
end_define

begin_comment
comment|/* Routing header */
end_comment

begin_struct
struct|struct
name|ip6_rthdr
block|{
name|u_int8_t
name|ip6r_nxt
decl_stmt|;
comment|/* next header */
name|u_int8_t
name|ip6r_len
decl_stmt|;
comment|/* length in units of 8 octets */
name|u_int8_t
name|ip6r_type
decl_stmt|;
comment|/* routing type */
name|u_int8_t
name|ip6r_segleft
decl_stmt|;
comment|/* segments left */
comment|/* followed by routing type specific data */
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* Type 0 Routing header */
end_comment

begin_struct
struct|struct
name|ip6_rthdr0
block|{
name|u_int8_t
name|ip6r0_nxt
decl_stmt|;
comment|/* next header */
name|u_int8_t
name|ip6r0_len
decl_stmt|;
comment|/* length in units of 8 octets */
name|u_int8_t
name|ip6r0_type
decl_stmt|;
comment|/* always zero */
name|u_int8_t
name|ip6r0_segleft
decl_stmt|;
comment|/* segments left */
name|u_int8_t
name|ip6r0_reserved
decl_stmt|;
comment|/* reserved field */
name|u_int8_t
name|ip6r0_slmap
index|[
literal|3
index|]
decl_stmt|;
comment|/* strict/loose bit map */
name|struct
name|in6_addr
name|ip6r0_addr
index|[
literal|1
index|]
decl_stmt|;
comment|/* up to 23 addresses */
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* Fragment header */
end_comment

begin_struct
struct|struct
name|ip6_frag
block|{
name|u_int8_t
name|ip6f_nxt
decl_stmt|;
comment|/* next header */
name|u_int8_t
name|ip6f_reserved
decl_stmt|;
comment|/* reserved field */
name|u_int16_t
name|ip6f_offlg
decl_stmt|;
comment|/* offset, reserved, and flag */
name|u_int32_t
name|ip6f_ident
decl_stmt|;
comment|/* identification */
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
end_struct

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|IP6F_OFF_MASK
value|0xfff8
end_define

begin_comment
comment|/* mask out offset from _offlg */
end_comment

begin_define
define|#
directive|define
name|IP6F_RESERVED_MASK
value|0x0006
end_define

begin_comment
comment|/* reserved bits in ip6f_offlg */
end_comment

begin_define
define|#
directive|define
name|IP6F_MORE_FRAG
value|0x0001
end_define

begin_comment
comment|/* more-fragments flag */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* BYTE_ORDER == LITTLE_ENDIAN */
end_comment

begin_define
define|#
directive|define
name|IP6F_OFF_MASK
value|0xf8ff
end_define

begin_comment
comment|/* mask out offset from _offlg */
end_comment

begin_define
define|#
directive|define
name|IP6F_RESERVED_MASK
value|0x0600
end_define

begin_comment
comment|/* reserved bits in ip6f_offlg */
end_comment

begin_define
define|#
directive|define
name|IP6F_MORE_FRAG
value|0x0100
end_define

begin_comment
comment|/* more-fragments flag */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BYTE_ORDER == LITTLE_ENDIAN */
end_comment

begin_comment
comment|/*  * Internet implementation parameters.  */
end_comment

begin_define
define|#
directive|define
name|IPV6_MAXHLIM
value|255
end_define

begin_comment
comment|/* maximun hoplimit */
end_comment

begin_define
define|#
directive|define
name|IPV6_DEFHLIM
value|64
end_define

begin_comment
comment|/* default hlim */
end_comment

begin_define
define|#
directive|define
name|IPV6_FRAGTTL
value|120
end_define

begin_comment
comment|/* ttl for fragment packets, in slowtimo tick */
end_comment

begin_define
define|#
directive|define
name|IPV6_HLIMDEC
value|1
end_define

begin_comment
comment|/* subtracted when forwaeding */
end_comment

begin_define
define|#
directive|define
name|IPV6_MMTU
value|1280
end_define

begin_comment
comment|/* minimal MTU and reassembly. 1024 + 256 */
end_comment

begin_define
define|#
directive|define
name|IPV6_MAXPACKET
value|65535
end_define

begin_comment
comment|/* ip6 max packet size without Jumbo payload*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * IP6_EXTHDR_CHECK ensures that region between the IP6 header and the  * target header (including IPv6 itself, extension headers and  * TCP/UDP/ICMP6 headers) are continuous. KAME requires drivers  * to store incoming data into one internal mbuf or one or more external  * mbufs(never into two or more internal mbufs). Thus, the third case is  * supposed to never be matched but is prepared just in case.  */
end_comment

begin_define
define|#
directive|define
name|IP6_EXTHDR_CHECK
parameter_list|(
name|m
parameter_list|,
name|off
parameter_list|,
name|hlen
parameter_list|,
name|ret
parameter_list|)
define|\
value|do {									\     if ((m)->m_next != NULL) {						\ 	if (((m)->m_flags& M_LOOP)&&					\ 	    ((m)->m_len< (off) + (hlen))&&				\ 	    (((m) = m_pullup((m), (off) + (hlen))) == NULL)) {		\ 		ip6stat.ip6s_exthdrtoolong++;				\ 		return ret;						\ 	} else if ((m)->m_flags& M_EXT) {				\ 		if ((m)->m_len< (off) + (hlen)) {			\ 			ip6stat.ip6s_exthdrtoolong++;			\ 			m_freem(m);					\ 			return ret;					\ 		}							\ 	} else {							\ 		if ((m)->m_len< (off) + (hlen)) {			\ 			ip6stat.ip6s_exthdrtoolong++;			\ 			m_freem(m);					\ 			return ret;					\ 		}							\ 	}								\     } else {								\ 	if ((m)->m_len< (off) + (hlen)) {				\ 		ip6stat.ip6s_tooshort++;				\ 		in6_ifstat_inc(m->m_pkthdr.rcvif, ifs6_in_truncated);	\ 		m_freem(m);						\ 		return ret;						\ 	}								\     }									\ } while (0)
end_define

begin_comment
comment|/*  * IP6_EXTHDR_GET ensures that intermediate protocol header (from "off" to  * "len") is located in single mbuf, on contiguous memory region.  * The pointer to the region will be returned to pointer variable "val",  * with type "typ".  * IP6_EXTHDR_GET0 does the same, except that it aligns the structure at the  * very top of mbuf.  GET0 is likely to make memory copy than GET.  *  * XXX we're now testing this, needs m_pulldown()  */
end_comment

begin_define
define|#
directive|define
name|IP6_EXTHDR_GET
parameter_list|(
name|val
parameter_list|,
name|typ
parameter_list|,
name|m
parameter_list|,
name|off
parameter_list|,
name|len
parameter_list|)
define|\
value|do {									\ 	struct mbuf *t;							\ 	int tmp;							\ 	if ((m)->m_len>= (off) + (len))				\ 		(val) = (typ)(mtod((m), caddr_t) + (off));		\ 	else {								\ 		t = m_pulldown((m), (off), (len),&tmp);		\ 		if (t) {						\ 			if (t->m_len< tmp + (len))			\ 				panic("m_pulldown malfunction");	\ 			(val) = (typ)(mtod(t, caddr_t) + tmp);		\ 		} else {						\ 			(val) = (typ)NULL;				\ 			(m) = NULL;					\ 		}							\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|IP6_EXTHDR_GET0
parameter_list|(
name|val
parameter_list|,
name|typ
parameter_list|,
name|m
parameter_list|,
name|off
parameter_list|,
name|len
parameter_list|)
define|\
value|do {									\ 	struct mbuf *t;							\ 	if ((off) == 0)							\ 		(val) = (typ)mtod(m, caddr_t);				\ 	else {								\ 		t = m_pulldown((m), (off), (len), NULL);		\ 		if (t) {						\ 			if (t->m_len< (len))				\ 				panic("m_pulldown malfunction");	\ 			(val) = (typ)mtod(t, caddr_t);			\ 		} else {						\ 			(val) = (typ)NULL;				\ 			(m) = NULL;					\ 		}							\ 	}								\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_KERNEL*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _NETINET_IP6_H_ */
end_comment

end_unit

