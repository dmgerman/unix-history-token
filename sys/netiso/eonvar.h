begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)eonvar.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETISO_EONVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETISO_EOBVAR_H_
end_define

begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_define
define|#
directive|define
name|EON_986_VERSION
value|0x3
end_define

begin_define
define|#
directive|define
name|EON_VERSION
value|0x1
end_define

begin_define
define|#
directive|define
name|EON_CACHESIZE
value|30
end_define

begin_define
define|#
directive|define
name|E_FREE
value|1
end_define

begin_define
define|#
directive|define
name|E_LINK
value|2
end_define

begin_define
define|#
directive|define
name|E_ES
value|3
end_define

begin_define
define|#
directive|define
name|E_IS
value|4
end_define

begin_comment
comment|/*  * this overlays a sockaddr_iso  */
end_comment

begin_struct
struct|struct
name|sockaddr_eon
block|{
name|u_char
name|seon_len
decl_stmt|;
comment|/* Length */
name|u_char
name|seon_family
decl_stmt|;
comment|/* AF_ISO */
name|u_char
name|seon_status
decl_stmt|;
comment|/* overlays session suffixlen */
define|#
directive|define
name|EON_ESLINK_UP
value|0x1
define|#
directive|define
name|EON_ESLINK_DOWN
value|0x2
define|#
directive|define
name|EON_ISLINK_UP
value|0x10
define|#
directive|define
name|EON_ISLINK_DOWN
value|0x20
comment|/* no change is neither up or down */
name|u_char
name|seon_pad1
decl_stmt|;
comment|/* 0, overlays tsfxlen */
name|u_char
name|seon_adrlen
decl_stmt|;
name|u_char
name|seon_afi
decl_stmt|;
comment|/* 47 */
name|u_char
name|seon_idi
index|[
literal|2
index|]
decl_stmt|;
comment|/* 0006 */
name|u_char
name|seon_vers
decl_stmt|;
comment|/* 03 */
name|u_char
name|seon_glbnum
index|[
literal|2
index|]
decl_stmt|;
comment|/* see RFC 1069 */
name|u_char
name|seon_RDN
index|[
literal|2
index|]
decl_stmt|;
comment|/* see RFC 1070 */
name|u_char
name|seon_pad2
index|[
literal|3
index|]
decl_stmt|;
comment|/* see RFC 1070 */
name|u_char
name|seon_LAREA
index|[
literal|2
index|]
decl_stmt|;
comment|/* see RFC 1070 */
name|u_char
name|seon_pad3
index|[
literal|2
index|]
decl_stmt|;
comment|/* see RFC 1070 */
comment|/* right now ip addr is  aligned  -- be careful -- 		 * future revisions may have it u_char[4] 		 */
name|u_int
name|seon_ipaddr
decl_stmt|;
comment|/* a.b.c.d */
name|u_char
name|seon_protoid
decl_stmt|;
comment|/* NSEL */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|EON_TEMPLATE
end_ifdef

begin_decl_stmt
name|struct
name|sockaddr_eon
name|eon_template
init|=
block|{
sizeof|sizeof
argument_list|(
name|eon_template
argument_list|)
block|,
name|AF_ISO
block|,
literal|0
block|,
literal|0
block|,
literal|0x14
block|,
literal|0x47
block|,
literal|0x0
block|,
literal|0x6
block|,
literal|0x3
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DOWNBITS
value|( EON_ESLINK_DOWN | EON_ISLINK_DOWN )
end_define

begin_define
define|#
directive|define
name|UPBITS
value|( EON_ESLINK_UP | EON_ISLINK_UP )
end_define

begin_define
define|#
directive|define
name|SIOCSEONCORE
value|_IOWR('i',10, struct iso_ifreq)
end_define

begin_comment
comment|/* EON core member */
end_comment

begin_define
define|#
directive|define
name|SIOCGEONCORE
value|_IOWR('i',11, struct iso_ifreq)
end_define

begin_comment
comment|/* EON core member */
end_comment

begin_struct
struct|struct
name|eon_hdr
block|{
name|u_char
name|eonh_vers
decl_stmt|;
comment|/* value 1 */
name|u_char
name|eonh_class
decl_stmt|;
comment|/* address multicast class, below */
define|#
directive|define
name|EON_NORMAL_ADDR
value|0x0
define|#
directive|define
name|EON_MULTICAST_ES
value|0x1
define|#
directive|define
name|EON_MULTICAST_IS
value|0x2
define|#
directive|define
name|EON_BROADCAST
value|0x3
name|u_short
name|eonh_csum
decl_stmt|;
comment|/* osi checksum (choke)*/
block|}
struct|;
end_struct

begin_struct
struct|struct
name|eon_iphdr
block|{
name|struct
name|ip
name|ei_ip
decl_stmt|;
name|struct
name|eon_hdr
name|ei_eh
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|EONIPLEN
value|(sizeof(struct eon_hdr) + sizeof(struct ip))
end_define

begin_comment
comment|/* stole these 2 fields of the flags for I-am-ES and I-am-IS */
end_comment

begin_define
define|#
directive|define
name|IFF_ES
value|0x400
end_define

begin_define
define|#
directive|define
name|IFF_IS
value|0x800
end_define

begin_struct
struct|struct
name|eon_stat
block|{
name|int
name|es_in_multi_es
decl_stmt|;
name|int
name|es_in_multi_is
decl_stmt|;
name|int
name|es_in_broad
decl_stmt|;
name|int
name|es_in_normal
decl_stmt|;
name|int
name|es_out_multi_es
decl_stmt|;
name|int
name|es_out_multi_is
decl_stmt|;
name|int
name|es_out_broad
decl_stmt|;
name|int
name|es_out_normal
decl_stmt|;
name|int
name|es_ipout
decl_stmt|;
name|int
name|es_icmp
index|[
name|PRC_NCMDS
index|]
decl_stmt|;
comment|/* errors */
name|int
name|es_badcsum
decl_stmt|;
name|int
name|es_badhdr
decl_stmt|;
block|}
name|eonstat
struct|;
end_struct

begin_undef
undef|#
directive|undef
name|IncStat
end_undef

begin_define
define|#
directive|define
name|IncStat
parameter_list|(
name|xxx
parameter_list|)
value|eonstat.xxx++
end_define

begin_typedef
typedef|typedef
struct|struct
name|qhdr
block|{
name|struct
name|qhdr
modifier|*
name|link
decl_stmt|,
modifier|*
name|rlink
decl_stmt|;
block|}
typedef|*
name|queue_t
typedef|;
end_typedef

begin_struct
struct|struct
name|eon_llinfo
block|{
name|struct
name|qhdr
name|el_qhdr
decl_stmt|;
comment|/* keep all in a list */
name|int
name|el_flags
decl_stmt|;
comment|/* cache valid ? */
name|int
name|el_snpaoffset
decl_stmt|;
comment|/* IP address contained in dst nsap */
name|struct
name|rtentry
modifier|*
name|el_rt
decl_stmt|;
comment|/* back pointer to parent route */
name|struct
name|eon_iphdr
name|el_ei
decl_stmt|;
comment|/* precomputed portion of hdr */
name|struct
name|route
name|el_iproute
decl_stmt|;
comment|/* if direct route cache IP info */
comment|/* if gateway, cache secondary route */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|el_iphdr
value|el_ei.ei_ip
end_define

begin_define
define|#
directive|define
name|el_eonhdr
value|el_ei.ei_eh
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

