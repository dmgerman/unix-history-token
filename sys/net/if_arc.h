begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: if_arc.h,v 1.13 1999/11/19 20:41:19 thorpej Exp $	*/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: NetBSD: if_ether.h,v 1.10 1994/06/29 06:37:55 cgd Exp  *       @(#)if_ether.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_ARC_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_IF_ARC_H_
end_define

begin_comment
comment|/*  * Arcnet address - 1 octets  * don't know who uses this.  */
end_comment

begin_struct
struct|struct
name|arc_addr
block|{
name|u_int8_t
name|arc_addr_octet
index|[
literal|1
index|]
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
comment|/*  * Structure of a 2.5MB/s Arcnet header.  * as given to interface code.  */
end_comment

begin_struct
struct|struct
name|arc_header
block|{
name|u_int8_t
name|arc_shost
decl_stmt|;
name|u_int8_t
name|arc_dhost
decl_stmt|;
name|u_int8_t
name|arc_type
decl_stmt|;
comment|/* 	 * only present for newstyle encoding with LL fragmentation. 	 * Don't use sizeof(anything), use ARC_HDR{,NEW}LEN instead. 	 */
name|u_int8_t
name|arc_flag
decl_stmt|;
name|u_int16_t
name|arc_seqid
decl_stmt|;
comment|/* 	 * only present in exception packets (arc_flag == 0xff) 	 */
name|u_int8_t
name|arc_type2
decl_stmt|;
comment|/* same as arc_type */
name|u_int8_t
name|arc_flag2
decl_stmt|;
comment|/* real flag value */
name|u_int16_t
name|arc_seqid2
decl_stmt|;
comment|/* real seqid value */
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
name|ARC_ADDR_LEN
value|1
end_define

begin_define
define|#
directive|define
name|ARC_HDRLEN
value|3
end_define

begin_define
define|#
directive|define
name|ARC_HDRNEWLEN
value|6
end_define

begin_define
define|#
directive|define
name|ARC_HDRNEWLEN_EXC
value|10
end_define

begin_comment
comment|/* these lengths are data link layer length - 2*ARC_ADDR_LEN */
end_comment

begin_define
define|#
directive|define
name|ARC_MIN_LEN
value|1
end_define

begin_define
define|#
directive|define
name|ARC_MIN_FORBID_LEN
value|254
end_define

begin_define
define|#
directive|define
name|ARC_MAX_FORBID_LEN
value|256
end_define

begin_define
define|#
directive|define
name|ARC_MAX_LEN
value|508
end_define

begin_comment
comment|/* RFC 1051 */
end_comment

begin_define
define|#
directive|define
name|ARCTYPE_IP_OLD
value|240
end_define

begin_comment
comment|/* IP protocol */
end_comment

begin_define
define|#
directive|define
name|ARCTYPE_ARP_OLD
value|241
end_define

begin_comment
comment|/* address resolution protocol */
end_comment

begin_comment
comment|/* RFC 1201 */
end_comment

begin_define
define|#
directive|define
name|ARCTYPE_IP
value|212
end_define

begin_comment
comment|/* IP protocol */
end_comment

begin_define
define|#
directive|define
name|ARCTYPE_ARP
value|213
end_define

begin_comment
comment|/* address resolution protocol */
end_comment

begin_define
define|#
directive|define
name|ARCTYPE_REVARP
value|214
end_define

begin_comment
comment|/* reverse addr resolution protocol */
end_comment

begin_define
define|#
directive|define
name|ARCTYPE_ATALK
value|221
end_define

begin_comment
comment|/* Appletalk */
end_comment

begin_define
define|#
directive|define
name|ARCTYPE_BANIAN
value|247
end_define

begin_comment
comment|/* Banyan Vines */
end_comment

begin_define
define|#
directive|define
name|ARCTYPE_IPX
value|250
end_define

begin_comment
comment|/* Novell IPX */
end_comment

begin_define
define|#
directive|define
name|ARCTYPE_INET6
value|0xc4
end_define

begin_comment
comment|/* IPng */
end_comment

begin_define
define|#
directive|define
name|ARCTYPE_DIAGNOSE
value|0x80
end_define

begin_comment
comment|/* as per ANSI/ATA 878.1 */
end_comment

begin_define
define|#
directive|define
name|ARCMTU
value|507
end_define

begin_define
define|#
directive|define
name|ARCMIN
value|0
end_define

begin_define
define|#
directive|define
name|ARC_PHDS_MAXMTU
value|60480
end_define

begin_struct
struct|struct
name|arccom
block|{
name|struct
name|ifnet
name|ac_if
decl_stmt|;
comment|/* network-visible interface */
name|u_int16_t
name|ac_seqid
decl_stmt|;
comment|/* seq. id used by PHDS encap. */
name|u_int8_t
name|arc_shost
decl_stmt|;
name|u_int8_t
name|arc_dhost
decl_stmt|;
name|u_int8_t
name|arc_type
decl_stmt|;
name|u_int8_t
name|dummy0
decl_stmt|;
name|u_int16_t
name|dummy1
decl_stmt|;
name|int
name|sflag
decl_stmt|,
name|fsflag
decl_stmt|,
name|rsflag
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|curr_frag
decl_stmt|;
struct|struct
name|ac_frag
block|{
name|u_int8_t
name|af_maxflag
decl_stmt|;
comment|/* from first packet */
name|u_int8_t
name|af_lastseen
decl_stmt|;
comment|/* last split flag seen */
name|u_int16_t
name|af_seqid
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|af_packet
decl_stmt|;
block|}
name|ac_fragtab
index|[
literal|256
index|]
struct|;
comment|/* indexed by sender ll address */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|u_int8_t
name|arcbroadcastaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|arc_ipmtu
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX new ip only, no RFC 1051! */
end_comment

begin_function_decl
name|void
name|arc_ifattach
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arc_ifdetach
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arc_storelladdr
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|arc_sprintf
parameter_list|(
name|u_int8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|arc_isphds
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arc_input
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|arc_output
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|rtentry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|arc_ioctl
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arc_frag_init
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|arc_frag_next
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_IF_ARC_H_ */
end_comment

end_unit

