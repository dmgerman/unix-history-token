begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)iso_var.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETISO_ISO_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETISO_ISO_VAR_H_
end_define

begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_comment
comment|/* $FreeBSD$  * $Source: /pub/FreeBSD/FreeBSD-CVS/src/sys/netiso/Attic/iso_var.h,v $  */
end_comment

begin_comment
comment|/*  *	Interface address, iso version. One of these structures is  *	allocated for each interface with an osi address. The ifaddr  *	structure conatins the protocol-independent part  *	of the structure, and is assumed to be first.  */
end_comment

begin_struct
struct|struct
name|iso_ifaddr
block|{
name|struct
name|ifaddr
name|ia_ifa
decl_stmt|;
comment|/* protocol-independent info */
define|#
directive|define
name|ia_ifp
value|ia_ifa.ifa_ifp
define|#
directive|define
name|ia_flags
value|ia_ifa.ifa_flags
name|int
name|ia_snpaoffset
decl_stmt|;
name|struct
name|iso_ifaddr
modifier|*
name|ia_next
decl_stmt|;
comment|/* next in list of iso addresses */
name|struct
name|sockaddr_iso
name|ia_addr
decl_stmt|;
comment|/* reserve space for interface name */
name|struct
name|sockaddr_iso
name|ia_dstaddr
decl_stmt|;
comment|/* reserve space for broadcast addr */
define|#
directive|define
name|ia_broadaddr
value|ia_dstaddr
name|struct
name|sockaddr_iso
name|ia_sockmask
decl_stmt|;
comment|/* reserve space for general netmask */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iso_aliasreq
block|{
name|char
name|ifra_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* if name, e.g. "en0" */
name|struct
name|sockaddr_iso
name|ifra_addr
decl_stmt|;
name|struct
name|sockaddr_iso
name|ifra_dstaddr
decl_stmt|;
name|struct
name|sockaddr_iso
name|ifra_mask
decl_stmt|;
name|int
name|ifra_snpaoffset
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iso_ifreq
block|{
name|char
name|ifr_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* if name, e.g. "en0" */
name|struct
name|sockaddr_iso
name|ifr_Addr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *	Given a pointer to an iso_ifaddr (ifaddr),  *	return a pointer to the addr as a sockaddr_iso  */
end_comment

begin_comment
comment|/* #define	IA_SIS(ia) ((struct sockaddr_iso *)(ia.ia_ifa->ifa_addr))  * works if sockaddr_iso becomes variable sized.  */
end_comment

begin_define
define|#
directive|define
name|IA_SIS
parameter_list|(
name|ia
parameter_list|)
value|(&(((struct iso_ifaddr *)ia)->ia_addr))
end_define

begin_define
define|#
directive|define
name|SIOCDIFADDR_ISO
value|_IOW('i',25, struct iso_ifreq)
end_define

begin_comment
comment|/* delete IF addr */
end_comment

begin_define
define|#
directive|define
name|SIOCAIFADDR_ISO
value|_IOW('i',26, struct iso_aliasreq)
end_define

begin_comment
comment|/* add/chg IFalias */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFADDR_ISO
value|_IOWR('i',33, struct iso_ifreq)
end_define

begin_comment
comment|/* get ifnet address */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFDSTADDR_ISO
value|_IOWR('i',34, struct iso_ifreq)
end_define

begin_comment
comment|/* get dst address */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFNETMASK_ISO
value|_IOWR('i',37, struct iso_ifreq)
end_define

begin_comment
comment|/* get dst address */
end_comment

begin_comment
comment|/*  * This stuff should go in if.h or if_llc.h or someplace else,  * but for now . . .  */
end_comment

begin_struct
struct|struct
name|llc_etherhdr
block|{
name|char
name|dst
index|[
literal|6
index|]
decl_stmt|;
name|char
name|src
index|[
literal|6
index|]
decl_stmt|;
name|char
name|len
index|[
literal|2
index|]
decl_stmt|;
name|char
name|llc_dsap
decl_stmt|;
name|char
name|llc_ssap
decl_stmt|;
name|char
name|llc_ui_byte
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|snpa_hdr
block|{
name|struct
name|ifnet
modifier|*
name|snh_ifp
decl_stmt|;
name|char
name|snh_dhost
index|[
literal|6
index|]
decl_stmt|;
name|char
name|snh_shost
index|[
literal|6
index|]
decl_stmt|;
name|short
name|snh_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|iso_ifaddr
modifier|*
name|iso_ifaddr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* linked list of iso address ifaces */
end_comment

begin_function_decl
name|struct
name|iso_ifaddr
modifier|*
name|iso_localifa
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* linked list of iso address ifaces */
end_comment

begin_decl_stmt
name|void
name|clnlintr
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ifqueue
name|clnlintrq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* clnl packet input queue */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

