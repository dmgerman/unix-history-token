begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)iso.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETISO_ISO_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETISO_ISO_H_
end_define

begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $Source: /pub/FreeBSD/FreeBSD-CVS/src/sys/netiso/Attic/iso.h,v $ */
end_comment

begin_comment
comment|/*  *	Return true if this is a multicast address  *	This assumes that the bit transmission is lsb first. This  *	assumption is valid for 802.3 but not 802.5. There is a  *	kludge to get around this for 802.5 -- see if_lan.c  *	where subnetwork header is setup.  */
end_comment

begin_define
define|#
directive|define
name|IS_MULTICAST
parameter_list|(
name|snpa
parameter_list|)
define|\
value|((snpa)[0]& 0x01)
end_define

begin_comment
comment|/*  * Protocols  */
end_comment

begin_define
define|#
directive|define
name|ISOPROTO_TCP
value|6
end_define

begin_comment
comment|/* IETF experiment */
end_comment

begin_define
define|#
directive|define
name|ISOPROTO_UDP
value|17
end_define

begin_comment
comment|/* IETF experiment */
end_comment

begin_define
define|#
directive|define
name|ISOPROTO_TP0
value|25
end_define

begin_comment
comment|/* connection oriented transport protocol */
end_comment

begin_define
define|#
directive|define
name|ISOPROTO_TP1
value|26
end_define

begin_comment
comment|/* not implemented */
end_comment

begin_define
define|#
directive|define
name|ISOPROTO_TP2
value|27
end_define

begin_comment
comment|/* not implemented */
end_comment

begin_define
define|#
directive|define
name|ISOPROTO_TP3
value|28
end_define

begin_comment
comment|/* not implemented */
end_comment

begin_define
define|#
directive|define
name|ISOPROTO_TP4
value|29
end_define

begin_comment
comment|/* connection oriented transport protocol */
end_comment

begin_define
define|#
directive|define
name|ISOPROTO_TP
value|ISOPROTO_TP4
end_define

begin_comment
comment|/* tp-4 with negotiation */
end_comment

begin_define
define|#
directive|define
name|ISOPROTO_CLTP
value|30
end_define

begin_comment
comment|/* connectionless transport (not yet impl.) */
end_comment

begin_define
define|#
directive|define
name|ISOPROTO_CLNP
value|31
end_define

begin_comment
comment|/* connectionless internetworking protocol */
end_comment

begin_define
define|#
directive|define
name|ISOPROTO_X25
value|32
end_define

begin_comment
comment|/* cons */
end_comment

begin_define
define|#
directive|define
name|ISOPROTO_INACT_NL
value|33
end_define

begin_comment
comment|/* inactive network layer! */
end_comment

begin_define
define|#
directive|define
name|ISOPROTO_ESIS
value|34
end_define

begin_comment
comment|/* ES-IS protocol */
end_comment

begin_define
define|#
directive|define
name|ISOPROTO_INTRAISIS
value|35
end_define

begin_comment
comment|/* IS-IS protocol */
end_comment

begin_define
define|#
directive|define
name|ISOPROTO_IDRP
value|36
end_define

begin_comment
comment|/* Interdomain Routing Protocol */
end_comment

begin_define
define|#
directive|define
name|ISOPROTO_RAW
value|255
end_define

begin_comment
comment|/* raw clnp */
end_comment

begin_define
define|#
directive|define
name|ISOPROTO_MAX
value|256
end_define

begin_define
define|#
directive|define
name|ISO_PORT_RESERVED
value|1024
end_define

begin_define
define|#
directive|define
name|ISO_PORT_USERRESERVED
value|5000
end_define

begin_comment
comment|/*  * Port/socket numbers: standard network functions  * NOT PRESENTLY USED  */
end_comment

begin_define
define|#
directive|define
name|ISO_PORT_MAINT
value|501
end_define

begin_define
define|#
directive|define
name|ISO_PORT_ECHO
value|507
end_define

begin_define
define|#
directive|define
name|ISO_PORT_DISCARD
value|509
end_define

begin_define
define|#
directive|define
name|ISO_PORT_SYSTAT
value|511
end_define

begin_define
define|#
directive|define
name|ISO_PORT_NETSTAT
value|515
end_define

begin_comment
comment|/*  * Port/socket numbers: non-standard application functions  */
end_comment

begin_define
define|#
directive|define
name|ISO_PORT_LOGIN
value|513
end_define

begin_comment
comment|/*  * Port/socket numbers: public use  */
end_comment

begin_define
define|#
directive|define
name|ISO_PORT_PUBLIC
value|1024
end_define

begin_comment
comment|/* high bit set --> public */
end_comment

begin_comment
comment|/*  *	Network layer protocol identifiers  */
end_comment

begin_define
define|#
directive|define
name|ISO8473_CLNP
value|0x81
end_define

begin_define
define|#
directive|define
name|ISO9542_ESIS
value|0x82
end_define

begin_define
define|#
directive|define
name|ISO9542X25_ESIS
value|0x8a
end_define

begin_define
define|#
directive|define
name|ISO10589_ISIS
value|0x83
end_define

begin_define
define|#
directive|define
name|ISO8878A_CONS
value|0x84
end_define

begin_define
define|#
directive|define
name|ISO10747_IDRP
value|0x85
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|IN_CLASSA_NET
end_ifndef

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IN_CLASSA_NET */
end_comment

begin_comment
comment|/* The following looks like a sockaddr  * to facilitate using tree lookup routines */
end_comment

begin_struct
struct|struct
name|iso_addr
block|{
name|u_char
name|isoa_len
decl_stmt|;
comment|/* length (in bytes) */
name|char
name|isoa_genaddr
index|[
literal|20
index|]
decl_stmt|;
comment|/* general opaque address */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sockaddr_iso
block|{
name|u_char
name|siso_len
decl_stmt|;
comment|/* length */
name|u_char
name|siso_family
decl_stmt|;
comment|/* family */
name|u_char
name|siso_plen
decl_stmt|;
comment|/* presentation selector length */
name|u_char
name|siso_slen
decl_stmt|;
comment|/* session selector length */
name|u_char
name|siso_tlen
decl_stmt|;
comment|/* transport selector length */
name|struct
name|iso_addr
name|siso_addr
decl_stmt|;
comment|/* network address */
name|u_char
name|siso_pad
index|[
literal|6
index|]
decl_stmt|;
comment|/* space for gosip v2 sels */
comment|/* makes struct 32 bytes long */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|siso_nlen
value|siso_addr.isoa_len
end_define

begin_define
define|#
directive|define
name|siso_data
value|siso_addr.isoa_genaddr
end_define

begin_define
define|#
directive|define
name|TSEL
parameter_list|(
name|s
parameter_list|)
value|((caddr_t)((s)->siso_data + (s)->siso_nlen))
end_define

begin_define
define|#
directive|define
name|SAME_ISOADDR
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|(bcmp((a)->siso_data, (b)->siso_data, (unsigned)(a)->siso_nlen)==0)
end_define

begin_comment
comment|/*  * The following are specific values for siso->siso_data[0],  * otherwise known as the AFI:  */
end_comment

begin_define
define|#
directive|define
name|AFI_37
value|0x37
end_define

begin_comment
comment|/* bcd of "37" */
end_comment

begin_define
define|#
directive|define
name|AFI_OSINET
value|0x47
end_define

begin_comment
comment|/* bcd of "47" */
end_comment

begin_define
define|#
directive|define
name|AFI_RFC986
value|0x47
end_define

begin_comment
comment|/* bcd of "47" */
end_comment

begin_define
define|#
directive|define
name|AFI_SNA
value|0x00
end_define

begin_comment
comment|/* SubNetwork Address; invalid really...*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
specifier|extern
name|int
name|iso_netmatch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|iso_hash
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|iso_addrmatch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|iso_ifaddr
modifier|*
name|iso_iaonnetof
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|domain
name|isodomain
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|protosw
name|isosw
index|[]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* user utilities definitions from the iso library */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|struct
name|iso_addr
modifier|*
name|iso_addr
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|iso_ntoa
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|iso_addr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* THESE DON'T EXIST YET */
end_comment

begin_decl_stmt
name|struct
name|hostent
modifier|*
name|iso_gethostbyname
argument_list|()
decl_stmt|,
modifier|*
name|iso_gethostbyaddr
argument_list|()
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_define
define|#
directive|define
name|_offsetof
parameter_list|(
name|t
parameter_list|,
name|m
parameter_list|)
value|((int)((caddr_t)&((t *)0)->m))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

